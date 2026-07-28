//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <Common.h>
#include <vsstyle.h>
#include <memory>
#include <PasTools.hpp>
#include <TBXOfficeXPTheme.hpp>
#include <StrUtils.hpp>
#include <CustomWinConfiguration.h>
#include "ThemePageControl.h"
#include <algorithm>
#include <Vcl.Themes.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// Based on
// https://web.archive.org/web/20250809094534/https://www.codeproject.com/Articles/6355/XP-Themes-Tab-Control-in-any-orientation
//---------------------------------------------------------------------------
#define IDS_UTIL_TAB            L"TAB"
//---------------------------------------------------------------------------
// UseThemes() alone checks only the native/classic UxTheme state, which predates
// VCL Styles and can be false (e.g. missing manifest on some build configs, or a
// system with visual styles off) even while a VCL Style is fully active and doing
// its own owner-draw painting. Either being true means we are "themed" enough for
// TThemePageControl's custom paint (including the tab close ("x") button) to make
// sense; without this OR, the close button (and the caption padding reserving
// space for it) could silently disappear completely, not just look small/faint.
static bool IsPageControlThemed()
{
  return
    UseThemes() ||
    ((Vcl::Themes::TStyleManager::ActiveStyle != NULL) &&
     !SameText(Vcl::Themes::TStyleManager::ActiveStyle->Name, L"Windows"));
}
// Note on why the tab close ("x") button is painted from WndProc (see DrawTabButtons)
// and not from PaintWindow: Vcl.ComCtrls registers TTabControlStyleHook for
// TCustomTabControl, and with a VCL Style active that hook sets OverridePaint and paints
// the whole control straight from WM_PAINT - so PaintWindow below is never called at
// all. The tabs still look properly themed (the hook draws them), which masks the real
// symptom: the close button is not painted, while its hit area and click handling
// (WM_LBUTTONDOWN, routed through Dispatch, untouched by the hook) keep working.
//
// Opting the control out of the style hook (registering a pass-through TStyleHook for
// this class, csOverrideStylePaint, trimming StyleElements) was tried and did NOT bring
// the button back, so it was removed again rather than left in as dead risk.
//---------------------------------------------------------------------------
__fastcall TThemeTabSheet::TThemeTabSheet(TComponent * Owner) :
  TTabSheet(Owner)
{
  FShadowed = false;
  FButton = ttbNone;
  FCaptionTruncation = tttNone;
}
//----------------------------------------------------------------------------------------------------------
TThemePageControl * TThemeTabSheet::GetParentPageControl()
{
  return DebugNotNull(dynamic_cast<TThemePageControl *>(Parent));
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemeTabSheet::Invalidate()
{
  TThemePageControl * ThemePageControl = GetParentPageControl();
  if (DebugAlwaysTrue(ThemePageControl != NULL))
  {
    ThemePageControl->InvalidateTab(TabIndex);
  }
  else
  {
    Parent->Invalidate();
  }
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemeTabSheet::SetShadowed(bool Value)
{
  if (Shadowed != Value)
  {
    FShadowed = Value;
    Invalidate();
  }
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemeTabSheet::SetButton(TThemeTabSheetButtons Value)
{
  if (Button != Value)
  {
    FButton = Value;
    Invalidate();
  }
}
//----------------------------------------------------------------------------------------------------------
void TThemeTabSheet::SetBaseCaption(const UnicodeString & value)
{
  if (FBaseCaption != value)
  {
    FBaseCaption = value;
    UpdateCaption();
  }
}
//----------------------------------------------------------------------------------------------------------
UnicodeString TThemeTabSheet::TruncatedCaption()
{
  UnicodeString Result = FBaseCaption;
  TThemePageControl * ParentPageControl = GetParentPageControl();
  if (ParentPageControl->FSessionTabShrink > 0)
  {
    if (FCaptionTruncation == tttNone)
    {
      // noop
    }
    else if (FCaptionTruncation == tttEllipsis)
    {
      if (ParentPageControl->FSessionTabShrink == 1)
      {
        Result = Result.SubString(1, 1);
      }
      else if (ParentPageControl->FSessionTabShrink < Result.Length())
      {
        Result = Result.SubString(1, ParentPageControl->FSessionTabShrink - 1) + Ellipsis;
      }
    }
    else if (DebugAlwaysTrue(FCaptionTruncation == tttNoText))
    {
      Result = EmptyStr;
    }
  }
  return Result;
}
//----------------------------------------------------------------------------------------------------------
void TThemeTabSheet::UpdateCaption()
{
  UnicodeString ACaption = TruncatedCaption();

  TThemePageControl * ParentPageControl = GetParentPageControl();

  if (IsPageControlThemed() && (Button != ttbNone))
  {
    ParentPageControl->Canvas->Font = ParentPageControl->Font;
    int OrigWidth = ParentPageControl->Canvas->TextWidth(ACaption);
    int TabButtonWidth = ParentPageControl->TabButtonSize();
    int Padding = ScaleByTextHeight(this, 2);
    while (ParentPageControl->Canvas->TextWidth(ACaption) < OrigWidth + Padding + TabButtonWidth)
    {
      ACaption += L" ";
    }
  }
  Caption = ACaption;
  ParentPageControl->TabChanged(TabIndex);
}
//----------------------------------------------------------------------------------------------------------
UnicodeString TThemeTabSheet::GetBaseCaption()
{
  DebugAssert(StartsStr(FBaseCaption, Caption));
  DebugAssert(RightStr(Caption, Caption.Length() - FBaseCaption.Length()).Trim().Length() == 0);
  return FBaseCaption;
}
//----------------------------------------------------------------------------------------------------------
void TThemeTabSheet::SetCaptionTruncation(TThemeTabCaptionTruncation Value)
{
  if (FCaptionTruncation != Value)
  {
    FCaptionTruncation = Value;
    UpdateCaption();
  }
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
__fastcall TThemePageControl::TThemePageControl(TComponent * Owner) :
  TPageControl(Owner)
{
  FOldTabIndex = -1;
  FHotTabButton = -1;
  FClickedButton = -1;
  FSessionTabShrink = 0;
  FOnTabButtonClick = NULL;
  FOnTabHint = NULL;
  FTabTheme = NULL;
  FActiveTabTheme = NULL;
  FTextHeight = -1;

}
//----------------------------------------------------------------------------------------------------------
int __fastcall TThemePageControl::GetTabsHeight()
{
  // The Calculated height includes tab/contents separator line on Windows 7/8,
  // but not on Windows XP

  TRect Rect = GetClientRect();
  ::SendMessage(Handle, TCM_ADJUSTRECT, FALSE, reinterpret_cast<LPARAM>(&Rect));
  int Result = Rect.Top - 1;

  // Two different ways to calculate the same, not sure which one is more reliable,
  // so we want to know in case they differ.
  if (DebugAlwaysTrue(PageCount >= 0))
  {
    TRect Rect2 = TabRect(0);
    int Result2 = Rect2.Bottom + 1;
    // On Windows 10 with 200% scaling, the first is 40, the second is 42.
    // With 250% scaling it's 50 vs 53.
    // Using the larger.
    if (Result2 > Result)
    {
      DebugAssert(IsWin10());
      Result = Result2;
    }
  }

  return Result;
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::PaintWindow(HDC DC)
{
  // Themes not enabled, give up. This used to check only UseThemes() (native/
  // classic UxTheme), which can be false even while a VCL Style is fully active.
  // When that happened, ALL of this control's custom painting - including the
  // tab close ("x") button - was skipped entirely in favour of the stock
  // TPageControl::PaintWindow, which VCL Styles then re-skins transparently via
  // its own generic TPageControl style hook (which is why the tabs still looked
  // themed/colored - just not via this class's code at all, so none of the fixes
  // made to DrawTabItem/GetTabButton/UpdateCaption here had any effect).
  if (!IsPageControlThemed())
  {
    TPageControl::PaintWindow(DC);
    return;
  }

  HTHEME Theme = OpenThemeData(NULL, IDS_UTIL_TAB);

  // TODO use GetClipBox

  TRect PageRect = GetClientRect();

  // 1st paint the tab body
  TRect ClientRect = PageRect;
  ::SendMessage(Handle, TCM_ADJUSTRECT, FALSE, reinterpret_cast<LPARAM>(&PageRect));

  ClientRect.Top = PageRect.Top - 2;
  DrawThemeBackground(Theme, DC, TABP_PANE, 0, &ClientRect, NULL);

  // 2nd paint the inactive tabs

  int SelectedIndex = TabIndex; // optimization

  std::unique_ptr<TCanvas> ACanvas(new TCanvas());
  ACanvas->Handle = DC;
  ACanvas->Font = Font;
  FTextHeight = CalculateTextHeight(ACanvas.get());

  for (int Tab = 0; Tab < PageCount; Tab++)
  {
    if (Tab != SelectedIndex)
    {
      DrawThemesXpTab(DC, Theme, Tab);
    }
  }

  if (SelectedIndex >= 0)
  {
    DrawThemesXpTab(DC, Theme, SelectedIndex);
  }

  CloseThemeData(Theme);
}
//----------------------------------------------------------------------------------------------------------
TThemeTabSheetButtons __fastcall TThemePageControl::GetTabButton(int Index)
{
  TThemeTabSheet * ThemeTabSheet = dynamic_cast<TThemeTabSheet *>(Pages[Index]);
  return (IsPageControlThemed() && (ThemeTabSheet != NULL)) ? ThemeTabSheet->Button : ttbNone;
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::DrawThemesXpTab(HDC DC, HTHEME Theme, int Tab)
{
  TThemeTabSheet * ThemeTabSheet = dynamic_cast<TThemeTabSheet *>(Pages[Tab]);
  bool Shadowed = (ThemeTabSheet != NULL) ? ThemeTabSheet->Shadowed : false;
  TRect Rect = TabRect(Tab);
  ItemTabRect(Tab, Rect);
  int State;
  TTBXTheme * ATabTheme;
  if (Tab != TabIndex)
  {
    TPoint Point = ScreenToClient(Mouse->CursorPos);
    int HotIndex = IndexOfTabAt(Point.X, Point.Y);
    State = (Tab == HotIndex ? TIS_HOT : (Shadowed ? TIS_DISABLED : TIS_NORMAL));
    ATabTheme = TabTheme;
  }
  else
  {
    State = TIS_SELECTED;
    ATabTheme = (ActiveTabTheme != NULL) ? ActiveTabTheme : TabTheme;
  }
  DrawThemesXpTabItem(DC, Theme, Tab, Rect, State, Shadowed, ATabTheme);
}
//----------------------------------------------------------------------------------------------------------
static TTBXItemInfo GetItemInfo(int State)
{
  TTBXItemInfo ItemInfo;
  memset(&ItemInfo, 0, sizeof(ItemInfo));
  ItemInfo.Enabled = true;
  ItemInfo.ViewType =
    VT_TOOLBAR | TVT_EMBEDDED |
    FLAGMASK(State == TIS_SELECTED, ISF_SELECTED);
  return ItemInfo;
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::DrawThemesXpTabItem(
  HDC DC, HTHEME Theme, int Item, const TRect & Rect, int State, bool Shadowed, TTBXTheme * ATabTheme)
{
  TRect PaintRect = Rect;
  if ((State == TIS_SELECTED) || (ATabTheme != NULL))
  {
    PaintRect.Bottom++;
  }

  if (ATabTheme != NULL)
  {
    std::unique_ptr<TCanvas> CanvasMem(new TCanvas());
    CanvasMem->Handle = DC;
    ATabTheme->PaintFrame(CanvasMem.get(), PaintRect, GetItemInfo(State));
  }
  else
  {
    int PartID = (Item == 0) ? TABP_TABITEMLEFTEDGE : TABP_TABITEM;
    DrawThemeBackground(Theme, DC, PartID, State, &PaintRect, NULL);
  }

  if (Item >= 0)
  {
    DrawTabItem(DC, Item, Rect, State, Shadowed, ATabTheme);
  }
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::ItemTabRect(int Item, TRect & Rect)
{
  if (Item == TabIndex)
  {
    // Countered in TabButtonRect
    Rect.Inflate(2, 2);
    Rect.Bottom--;
  }
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::ItemContentsRect(int Item, TRect & Rect)
{
  Rect.Left += 6;
  Rect.Right -= 3;

  if (Item == TabIndex)
  {
    // to counter the ItemTabRect
    Rect.Left += 2;
    Rect.Right -= 2;
    Rect.Bottom++;
    Rect.Bottom -= 2;
  }
}
//----------------------------------------------------------------------------------------------------------
bool __fastcall TThemePageControl::HasItemImage(int Item)
{
  return (Images != NULL) && (Pages[Item]->ImageIndex >= 0);
}
//----------------------------------------------------------------------------------------------------------
void TThemePageControl::DrawDropDown(HDC DC, int Radius, int X, int Y, COLORREF Color, int Grow)
{
  // Optimized for even-sized Rect (100% scaling), may need adjustments for even-sized to correctly center
  TPoint Points[] = {
    Point(X - Radius - 1 - Grow, Y), Point(X + Radius + Grow, Y),
    Point(X, Y + Radius + Grow), Point(X - 1, Y + Radius + Grow)
  };
  HBRUSH Brush = CreateSolidBrush(Color);
  HPEN Pen = CreatePen(PS_SOLID, 1, Color);
  HGDIOBJ OldBrush = SelectObject(DC, Brush);
  HGDIOBJ OldPen = SelectObject(DC, Pen);
  Polygon(DC, Points, std::size(Points));
  SelectObject(DC, OldPen);
  SelectObject(DC, OldBrush);
  DeleteObject(Brush);
  DeleteObject(Pen);
}
//----------------------------------------------------------------------------------------------------------
static int Luminance(COLORREF Color)
{
  return
    ((299 * static_cast<int>(GetRValue(Color))) +
     (587 * static_cast<int>(GetGValue(Color))) +
     (114 * static_cast<int>(GetBValue(Color)))) / 1000;
}
//----------------------------------------------------------------------------------------------------------
static int VCenter(const TRect & Rect, int Height)
{
  int A = (Rect.Top + Rect.Bottom - Height);
  return (A / 2) + (A % 2);
}
//----------------------------------------------------------------------------------------------------------
// Draw tab item context: possible icon and text
void __fastcall TThemePageControl::DrawTabItem(HDC DC, int Item, TRect Rect, int State, bool Shadowed, TTBXTheme * ATabTheme)
{
  TRect OrigRect = Rect;
  ItemContentsRect(Item, Rect);

  UnicodeString Text = Pages[Item]->Caption;

  std::unique_ptr<TCanvas> Canvas(new TCanvas());
  Canvas->Handle = DC;

  if (HasItemImage(Item))
  {
    int Left;
    if (!Text.IsEmpty())
    {
      Left = Rect.Left;
      Rect.Left += Images->Width + 3;
    }
    else
    {
      Left = OrigRect.Left + (OrigRect.Right - Images->Width - OrigRect.Left) / 2;
    }
    int Top = VCenter(Rect, Images->Height);
    Images->Draw(Canvas.get(), Left, Top, Pages[Item]->ImageIndex, !Shadowed);
  }

  int OldMode = SetBkMode(DC, TRANSPARENT);
  HGDIOBJ OldFont = SelectObject(DC, Font->Handle);

  if (!Text.IsEmpty())
  {
    if (ATabTheme != NULL)
    {
      SetTextColor(DC, static_cast<COLORREF>(ATabTheme->GetItemTextColor(GetItemInfo(State))));
    }
    wchar_t * Buf = new wchar_t[static_cast<size_t>(Text.Length() + 1 + 4)];
    wcscpy(Buf, Text.c_str());
    TRect TextRect(0, 0, Rect.Width(), 20);
    // Truncates too long texts with ellipsis
    ::DrawText(DC, Buf, -1, &TextRect, DT_CALCRECT | DT_SINGLELINE | DT_MODIFYSTRING | DT_END_ELLIPSIS);
    DebugAssert(FTextHeight == TextRect.Height());

    Rect.Top = VCenter(Rect, FTextHeight);
    DrawText(DC, Buf, -1, &Rect, DT_NOPREFIX | DT_CENTER);
    delete[] Buf;
  }

  SelectObject(DC, OldFont);
  SetBkMode(DC, OldMode);
  // The tab button is deliberately NOT painted from here: DrawTabButtons (called from
  // WndProc) is the single place that does it, because this method does not run at all
  // when a VCL Style hook owns WM_PAINT. Painting it in both places made the button
  // sample its own glyph as "background color" and invert itself into invisibility.
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::DrawTabButton(HDC DC, TCanvas * Canvas, int Item, int State)
{
  TThemeTabSheetButtons Button = GetTabButton(Item);
  if (Button != ttbNone)
  {
    TRect ButtonRect = TabButtonRect(Item);

    TTBXItemInfo ButtonItemInfo = GetItemInfo(State);

    // CurrentTheme is TBX's own global for the theme in use, so it is always the live
    // one. Deliberately NOT TabTheme/ActiveTabTheme: those are cached pointers owned by
    // whoever set them, and this code runs on every WM_PAINT - including the paints that
    // happen between TBXSetTheme() freeing the old theme object and UpdateControls()
    // assigning the new one. Dereferencing the stale pointer there took the whole app
    // down on every Dark/Light switch.
    if (IsHotButton(Item) && (CurrentTheme != NULL))
    {
      ButtonItemInfo.HoverKind = hkMouseHover;

      CurrentTheme->PaintFrame(Canvas, ButtonRect, ButtonItemInfo);
    }

    // How far the glyph is kept away from the button edges. Also decides where the
    // background is sampled below, so it is needed for both button kinds.
    int Inset = std::max((ButtonRect.Width() * 3) / 10, 3);

    // Sampled to the LEFT of the glyph, never at the centre of the button: this runs as
    // an overlay over an already painted window, so the centre may still hold the cross
    // drawn by the previous paint. Reading that back as "the background" would flip the
    // glyph to the background color - the button then alternates between visible and
    // invisible from one repaint to the next.
    COLORREF BackColor =
      GetPixel(DC, ButtonRect.Left + (Inset / 2), ButtonRect.Top + (ButtonRect.Height() / 2));

    // Derived from the background actually on screen rather than from a theme color:
    // this overlay has no reliable way of knowing which engine painted the tab, and a
    // theme text color that happens to sit close to the tab background renders the
    // button invisible. GetPixel returns CLR_INVALID outside the clipping region, in
    // which case the control's own font color is the best available guess.
    COLORREF ShapeColor;
    if (BackColor == CLR_INVALID)
    {
      ShapeColor = static_cast<COLORREF>(ColorToRGB(Font->Color));
    }
    else
    {
      ShapeColor = (Luminance(BackColor) < 128) ? RGB(0xF0, 0xF0, 0xF0) : RGB(0x30, 0x30, 0x30);
    }
    #define BlendValue(FN) (((4 * static_cast<int>(FN(BackColor))) + static_cast<int>(FN(ShapeColor))) / 5)
    COLORREF BlendColor =
      (BackColor == CLR_INVALID) ? ShapeColor : RGB(BlendValue(GetRValue), BlendValue(GetGValue), BlendValue(GetBValue));
    #undef BlendValue

    if (Button == ttbClose)
    {
      // Drawn as plain GDI lines, not as a font glyph: this runs over whatever painted
      // the tab (see DrawTabButtons), so it must not depend on the font selected into
      // the DC, on that font actually having the glyph, or on the background mode.
      COLORREF CrossColor = ShapeColor;
      int Thickness = std::max(ScaleByTextHeight(this, 1), 1);
      TRect CrossRect(ButtonRect);
      CrossRect.Inflate(-Inset, -Inset);

      HPEN Pen = CreatePen(PS_SOLID, Thickness, CrossColor);
      HGDIOBJ OldPen = SelectObject(DC, Pen);
      MoveToEx(DC, CrossRect.Left, CrossRect.Top, NULL);
      LineTo(DC, CrossRect.Right, CrossRect.Bottom);
      MoveToEx(DC, CrossRect.Right - 1, CrossRect.Top, NULL);
      LineTo(DC, CrossRect.Left - 1, CrossRect.Bottom);
      SelectObject(DC, OldPen);
      DeleteObject(Pen);
    }
    else if (DebugAlwaysTrue(Button == ttbDropDown))
    {
      // See TTBXOfficeXPTheme.PaintDropDownArrow
      int Radius = ScaleByTextHeight(this, 2);
      int X = ((ButtonRect.Left + ButtonRect.Right)) / 2;
      int Y = ((ButtonRect.Top + ButtonRect.Bottom) / 2) - (Radius * 2 / 3);
      DrawDropDown(DC, Radius, X, Y, BlendColor, 1);
      DrawDropDown(DC, Radius, X, Y, ShapeColor, 0);
    }
  }
}
//----------------------------------------------------------------------------------------------------------
// Draws the tab buttons over whatever painted the control - our own PaintWindow, the
// stock TPageControl painting, or the VCL Style's TTabControlStyleHook. Which of those
// three runs depends on VCL internals we do not control (the style hook sets
// OverridePaint and swallows WM_PAINT before PaintWindow is ever reached), and that is
// precisely why the close button used to be invisible while its click handling - which
// goes through Dispatch/WM_LBUTTONDOWN, untouched by any hook - kept working.
// Painting it from WndProc, after the message has been fully handled, is independent of
// all of that. The caption already reserves the space for it (see UpdateCaption).
void __fastcall TThemePageControl::DrawTabButtons(HDC DC)
{
  std::unique_ptr<TCanvas> Canvas(new TCanvas());
  Canvas->Handle = DC;
  Canvas->Font = Font;

  int OldMode = SetBkMode(DC, TRANSPARENT);

  TPoint Point = ScreenToClient(Mouse->CursorPos);
  int HotIndex = IndexOfTabAt(Point.X, Point.Y);

  for (int Item = 0; Item < PageCount; Item++)
  {
    int State;
    if (Item != TabIndex)
    {
      State = (Item == HotIndex) ? TIS_HOT : TIS_NORMAL;
    }
    else
    {
      State = TIS_SELECTED;
    }

    DrawTabButton(DC, Canvas.get(), Item, State);
  }

  SetBkMode(DC, OldMode);
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::WndProc(TMessage & Message)
{
  TPageControl::WndProc(Message);

  if ((Message.Msg == WM_PAINT) &&
      HandleAllocated() &&
      !ComponentState.Contains(csDestroying) &&
      !ControlState.Contains(csDestroyingHandle) &&
      (PageCount > 0))
  {
    // GetDC() would be GetDCEx(..., DCX_USESTYLE), and TWinControl creates its window
    // with WS_CLIPCHILDREN, so the returned DC would have the child tab sheet clipped
    // out - GetPixel then fails (CLR_INVALID) and drawing can be silently discarded.
    // Asking for the plain cached DC keeps the whole client area writable.
    HDC DC = GetDCEx(Handle, NULL, DCX_CACHE);
    if (DC != NULL)
    {
      try
      {
        DrawTabButtons(DC);
      }
      __finally
      {
        ReleaseDC(Handle, DC);
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------
int __fastcall TThemePageControl::TabButtonSize()
{
  // Was 8/13: made the tab close ("x") button too small/hard to notice.
  return MulDiv(GetTabsHeight(), 10, 13);
}
//----------------------------------------------------------------------------------------------------------
TRect __fastcall TThemePageControl::TabButtonRect(int Index)
{
  TRect Rect = TabRect(Index);
  ItemTabRect(Index, Rect);
  ItemContentsRect(Index, Rect);

  int ATabButtonSize = TabButtonSize();

  Rect.Top = VCenter(Rect, ATabButtonSize);
  Rect.Left = Rect.Right - ATabButtonSize - ScaleByTextHeight(this, 1);
  Rect.Right = Rect.Left + ATabButtonSize;
  Rect.Bottom = Rect.Top + ATabButtonSize;
  return Rect;
}
//----------------------------------------------------------------------------------------------------------
bool TThemePageControl::IsHotButton(int Index)
{
  // This was an attempt to allow tracking close buttons, even while drop down button menu is popped,
  // but MouseMove does not trigger then.
  return (Index == FClickedButton) || (Index == FHotTabButton);
}
//----------------------------------------------------------------------------------------------------------
void TThemePageControl::TabChanged(int Index)
{
  // When the "clicked" tab changes, it's probably not anymore the tab that was actually clicked.
  // For example, when the last tab is closed, it's replaced with either local-local tab (without the X button),
  // or removed altogether. The Login dialog pops up and when new session is opened, its tab's X button is rendered clicked,
  // until connection openning finishes (and WMLButtonDown finishes).
  if (Index == FClickedButton)
  {
    UpdateHotButton(FClickedButton, -1);
  }
}
//----------------------------------------------------------------------------------------------------------
void TThemePageControl::UpdateHotButton(int & Ref, int Index)
{
  if (Ref != Index)
  {
    bool WasHot = (Index >= 0) && IsHotButton(Index);
    int Prev = Ref;
    Ref = Index;
    if ((Prev >= 0) && !IsHotButton(Prev))
    {
      InvalidateTab(Prev);
    }
    if ((Index >= 0) && !WasHot)
    {
      InvalidateTab(Index);
    }
  }
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::MouseMove(TShiftState Shift, int X, int Y)
{
  TPageControl::MouseMove(Shift, X, Y);
  UpdateHotButton(FHotTabButton, IndexOfTabButtonAt(X, Y));
}
//----------------------------------------------------------------------------------------------------------
int __fastcall TThemePageControl::IndexOfTabButtonAt(int X, int Y)
{
  int Result = IndexOfTabAt(X, Y);
  if ((Result < 0) ||
      !GetTabButton(Result) ||
      !TabButtonRect(Result).Contains(TPoint(X, Y)))
  {
    Result = -1;
  }
  return Result;
}
//----------------------------------------------------------------------------------------------------------
bool __fastcall TThemePageControl::CanChange()
{
  FOldTabIndex = ActivePageIndex;

  return TPageControl::CanChange();
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::InvalidateTab(int Index)
{
  if (HandleAllocated())
  {
    TRect Rect = TabRect(Index);
    if (Index == TabIndex)
    {
      Rect.Inflate(2, 2);
    }
    // Original code was invalidating range against parent window
    // (recalculating coordinates first)
    InvalidateRect(Handle, &Rect, true);
  }
}
//----------------------------------------------------------------------------------------------------------
void __fastcall TThemePageControl::Change()
{
  // note that TabIndex yields correct value already here,
  // while ActivePageIndex is not updated yet
  if ((FOldTabIndex >= 0) && (FOldTabIndex != TabIndex) && IsPageControlThemed())
  {
    InvalidateTab(FOldTabIndex);
  }

  TPageControl::Change();
}
//---------------------------------------------------------------------------
void __fastcall TThemePageControl::WMLButtonDown(TWMLButtonDown & Message)
{
  int Index = IndexOfTabButtonAt(Message.XPos, Message.YPos);
  if (Index >= 0)
  {
    Message.Result = 1;
    if (FOnTabButtonClick != NULL)
    {
      UpdateHotButton(FClickedButton, Index);
      try
      {
        FOnTabButtonClick(this, Index);
      }
      __finally
      {
        UpdateHotButton(FClickedButton, -1);
      }
    }
  }
  else
  {
    TPageControl::Dispatch(&Message);
  }
}
//---------------------------------------------------------------------------
void TThemePageControl::CMHintShow(TCMHintShow & HintShow)
{
  TPageControl::Dispatch(&HintShow);
  if (OnTabHint != NULL)
  {
    int Tab = IndexOfTabAt(HintShow.HintInfo->CursorPos.x, HintShow.HintInfo->CursorPos.y);
    OnTabHint(this, Tab, HintShow.HintInfo->HintStr);
    HintShow.HintInfo->CursorRect = TabRect(Tab);
  }
}
//---------------------------------------------------------------------------
void __fastcall TThemePageControl::Dispatch(void * Message)
{
  TMessage * M = reinterpret_cast<TMessage*>(Message);
  if (M->Msg == CM_MOUSELEAVE)
  {
    UpdateHotButton(FHotTabButton, -1);
    TPageControl::Dispatch(Message);
  }
  else if (M->Msg == WM_LBUTTONDOWN)
  {
    WMLButtonDown(*reinterpret_cast<TWMLButtonDown *>(M));
  }
  else if (M->Msg == WM_WANTS_SCREEN_TIPS)
  {
    M->Result = 1;
  }
  else if (M->Msg == CM_HINTSHOW)
  {
    CMHintShow(*reinterpret_cast<TCMHintShow *>(M));
  }
  else
  {
    TPageControl::Dispatch(Message);
  }
}
//----------------------------------------------------------------------------------------------------------
TThemeTabSheet * TThemePageControl::GetPage(int Index)
{
  return DebugNotNull(dynamic_cast<TThemeTabSheet *>(TPageControl::Pages[Index]));
}
//----------------------------------------------------------------------------------------------------------
TThemeTabSheet * TThemePageControl::GetActivePage()
{
  TTabSheet * TabSheet = TPageControl::ActivePage;
  TThemeTabSheet * Result = NULL;
  if (TabSheet != NULL)
  {
    Result = DebugNotNull(dynamic_cast<TThemeTabSheet *>(TabSheet));
  }
  return Result;
}
//----------------------------------------------------------------------------------------------------------
int TThemePageControl::TotalTabsWidth()
{
  TRect FirstTabRect = TabRect(0);
  TRect LastTabRect = TabRect(PageCount - 1);
  return -FirstTabRect.Left + LastTabRect.Right;
}
//----------------------------------------------------------------------------------------------------------
void TThemePageControl::UpdateTabsCaptionTruncation()
{
  DisableAlign();
  Tabs->BeginUpdate();
  try
  {
    FSessionTabShrink = 0;
    for (int Index = 0; Index < PageCount; Index++)
    {
      Pages[Index]->UpdateCaption();
    }

    int TabsWidth = TotalTabsWidth();
    int MaxWidth = ClientWidth - ScaleByTextHeight(this, 8); // arbitrary margin to avoid left/right buttons flicker
    Canvas->Font = Font;
    if (TabsWidth > MaxWidth)
    {
      int NeedWidth = (TabsWidth - MaxWidth);
      int MaxLen = 0;
      int CaptionsWidth = 0;
      for (int Index = 0; Index < PageCount; Index++)
      {
        UnicodeString TabCaption = Pages[Index]->BaseCaption;
        MaxLen = std::max(MaxLen, TabCaption.Length());
        CaptionsWidth += Canvas->TextWidth(TabCaption);
      }

      bool Repeat;
      do
      {
        int NewShrink;
        if (FSessionTabShrink == 0)
        {
          NewShrink = MaxLen; // remove only new tab caption
        }
        else
        {
          NewShrink = FSessionTabShrink - 1;
        }

        if (NewShrink < 1)
        {
          Repeat = false;
        }
        else
        {
          FSessionTabShrink = NewShrink;
          int NewCaptionsWidth = 0;
          for (int Index = 0; Index < PageCount; Index++)
          {
            UnicodeString TabCaption = Pages[Index]->TruncatedCaption();
            NewCaptionsWidth += Canvas->TextWidth(TabCaption);
          }
          int GainedWidth = (CaptionsWidth - NewCaptionsWidth);
          Repeat = (GainedWidth < NeedWidth);
        }
      }
      while (Repeat);

      for (int Index = 0; Index < PageCount; Index++)
      {
        Pages[Index]->UpdateCaption();
      }
    }
  }
  __finally
  {
    Tabs->BeginUpdate();
    EnableAlign();
  }
}
//----------------------------------------------------------------------------------------------------------
void TThemePageControl::SetActiveTabTheme(TTBXTheme * value)
{
  if (FActiveTabTheme != value)
  {
    FActiveTabTheme = value;
    if (ActivePage != NULL)
    {
      ActivePage->Invalidate();
    }
  }
}
//----------------------------------------------------------------------------------------------------------
void TThemePageControl::SetTabTheme(TTBXTheme * value)
{
  if (FTabTheme != value)
  {
    FTabTheme = value;
    Invalidate();
  }
}
//----------------------------------------------------------------------------------------------------------
#ifdef _DEBUG
void __fastcall TThemePageControl::RequestAlign()
{
  TPageControl::RequestAlign();
}
#endif
//----------------------------------------------------------------------------------------------------------
