// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TBXStatusBars.pas' rev: 37.00 (Windows)

#ifndef TBXStatusBarsHPP
#define TBXStatusBarsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <TBX.hpp>
#include <TBXThemes.hpp>
#include <TB2Item.hpp>
#include <Vcl.ImgList.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>
#include <Vcl.Menus.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tbxstatusbars
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TTBXStatusPanel;
class DELPHICLASS TTBXStatusPanels;
class DELPHICLASS TTBXCustomStatusBar;
class DELPHICLASS TTBXStatusBar;
//-- type declarations -------------------------------------------------------
typedef System::Int8 TPercent;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBXStatusPanel : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	Vcl::Controls::TCaption FCaption;
	Vcl::Controls::TControl* FControl;
	bool FEnabled;
	bool FFramed;
	Tbx::TFontSettings* FFontSettings;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	int FMaxSize;
	int FSize;
	TPercent FStretchPriority;
	int FTag;
	Tbx::TTextTruncation FTextTruncation;
	TPercent FViewPriority;
	void __fastcall FontSettingsChanged(System::TObject* Sender);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetCaption(const Vcl::Controls::TCaption Value);
	void __fastcall SetControl(Vcl::Controls::TControl* Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetFramed(bool Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetMaxSize(int Value);
	void __fastcall SetSize(int Value);
	void __fastcall SetStretchPriority(TPercent Value);
	void __fastcall SetTextTruncation(Tbx::TTextTruncation Value);
	void __fastcall SetViewPriority(TPercent Value);
	void __fastcall SetFontSettings(Tbx::TFontSettings* const Value);
	
protected:
	Winapi::Windows::TRect CachedBounds;
	int CachedSize;
	bool CachedVisible;
	bool CachedGripper;
	TTBXCustomStatusBar* __fastcall StatusBar();
	virtual System::UnicodeString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TTBXStatusPanel(System::Classes::TCollection* Collection);
	__fastcall virtual ~TTBXStatusPanel();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Winapi::Windows::TRect BoundsRect = {read=CachedBounds};
	__property bool Visible = {read=CachedVisible, nodefault};
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property Vcl::Controls::TCaption Caption = {read=FCaption, write=SetCaption};
	__property Vcl::Controls::TControl* Control = {read=FControl, write=SetControl};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property bool Framed = {read=FFramed, write=SetFramed, default=1};
	__property Tbx::TFontSettings* FontSettings = {read=FFontSettings, write=SetFontSettings};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property int MaxSize = {read=FMaxSize, write=SetMaxSize, default=0};
	__property TPercent ViewPriority = {read=FViewPriority, write=SetViewPriority, default=100};
	__property int Size = {read=FSize, write=SetSize, default=50};
	__property TPercent StretchPriority = {read=FStretchPriority, write=SetStretchPriority, default=0};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	__property Tbx::TTextTruncation TextTruncation = {read=FTextTruncation, write=SetTextTruncation, default=0};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBXStatusPanels : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TTBXStatusPanel* operator[](int Index) { return this->Items[Index]; }
	
private:
	TTBXCustomStatusBar* FStatusBar;
	HIDESBASE TTBXStatusPanel* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TTBXStatusPanel* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner();
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TTBXStatusPanels(TTBXCustomStatusBar* AStatusBar);
	HIDESBASE TTBXStatusPanel* __fastcall Add();
	TTBXStatusPanel* __fastcall FindPanel(Vcl::Controls::TControl* AControl);
	__property TTBXCustomStatusBar* StatusBar = {read=FStatusBar};
	__property TTBXStatusPanel* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TTBXStatusPanels() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TSBAdjustContentRect)(TTBXCustomStatusBar* Sender, TTBXStatusPanel* Panel, Winapi::Windows::TRect &ARect);

typedef void __fastcall (__closure *TSBAdjustFont)(TTBXCustomStatusBar* Sender, TTBXStatusPanel* Panel, Vcl::Graphics::TFont* AFont);

typedef void __fastcall (__closure *TSBPanelEvent)(TTBXCustomStatusBar* Sender, TTBXStatusPanel* Panel);

class PASCALIMPLEMENTATION TTBXCustomStatusBar : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TTBXStatusPanels* FPanels;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FSimplePanel;
	Vcl::Controls::TCaption FSimpleText;
	bool FSizeGrip;
	int FUpdateCount;
	bool FUseSystemFont;
	TSBAdjustContentRect FOnAdjustContentRect;
	TSBAdjustFont FOnAdjustFont;
	TSBPanelEvent FOnPanelClick;
	TSBPanelEvent FOnPanelDblClick;
	bool FFixAlign;
	MESSAGE void __fastcall CMControlChange(Vcl::Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetPanels(TTBXStatusPanels* Value);
	void __fastcall SetSimplePanel(bool Value);
	void __fastcall SetSimpleText(const Vcl::Controls::TCaption Value);
	void __fastcall SetSizeGrip(bool Value);
	void __fastcall SetUseSystemFont(bool Value);
	MESSAGE void __fastcall TBMThemeChange(void *Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	Tbxthemes::TTBXMargins CachedPanelMargins;
	virtual void __fastcall AdjustPanelContentRect(TTBXStatusPanel* APanel, Winapi::Windows::TRect &ARect);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, Winapi::Windows::TRect &Rect);
	void __fastcall BeginUpdate();
	DYNAMIC void __fastcall Change();
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool isDpiChange)/* overload */;
	DYNAMIC void __fastcall Click();
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	DYNAMIC void __fastcall DblClick();
	virtual void __fastcall DoAdjustFont(TTBXStatusPanel* APanel, Vcl::Graphics::TFont* AFont);
	virtual void __fastcall DoPanelClick(TTBXStatusPanel* APanel);
	virtual void __fastcall DoPanelDblClick(TTBXStatusPanel* APanel);
	void __fastcall EndUpdate();
	Winapi::Windows::TRect __fastcall GetGripperRect();
	virtual void __fastcall Loaded();
	bool __fastcall IsSizeGripVisible();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint();
	virtual void __fastcall PaintPanel(const Winapi::Windows::TRect &ARect, TTBXStatusPanel* APanel, bool IsLast);
	DYNAMIC void __fastcall Resize();
	virtual void __fastcall UpdateCache();
	virtual void __fastcall UpdatePanels();
	
public:
	__fastcall virtual TTBXCustomStatusBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBXCustomStatusBar();
	TTBXStatusPanel* __fastcall GetPanelAt(const Winapi::Windows::TPoint &Pt)/* overload */;
	TTBXStatusPanel* __fastcall GetPanelAt(int X, int Y)/* overload */;
	Winapi::Windows::TRect __fastcall GetPanelRect(TTBXStatusPanel* APanel);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	__property Align = {default=2};
	__property bool FixAlign = {read=FFixAlign, write=FFixAlign, default=0};
	__property DoubleBuffered = {default=1};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TTBXStatusPanels* Panels = {read=FPanels, write=SetPanels};
	__property bool SimplePanel = {read=FSimplePanel, write=SetSimplePanel, default=0};
	__property Vcl::Controls::TCaption SimpleText = {read=FSimpleText, write=SetSimpleText};
	__property bool SizeGrip = {read=FSizeGrip, write=SetSizeGrip, default=1};
	__property bool UseSystemFont = {read=FUseSystemFont, write=SetUseSystemFont, nodefault};
	__property TSBAdjustContentRect OnAdjustContentRect = {read=FOnAdjustContentRect, write=FOnAdjustContentRect};
	__property TSBAdjustFont OnAdjustFont = {read=FOnAdjustFont, write=FOnAdjustFont};
	__property TSBPanelEvent OnPanelClick = {read=FOnPanelClick, write=FOnPanelClick};
	__property TSBPanelEvent OnPanelDblClick = {read=FOnPanelDblClick, write=FOnPanelDblClick};
	
__published:
	__property Height = {default=22};
public:
	/* TWinControl.CreateParented */ inline __fastcall TTBXCustomStatusBar(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	DYNAMIC inline void __fastcall  ChangeScale(int M, int D){ Vcl::Controls::TControl::ChangeScale(M, D); }
	
};


class PASCALIMPLEMENTATION TTBXStatusBar : public TTBXCustomStatusBar
{
	typedef TTBXCustomStatusBar inherited;
	
__published:
	__property Action;
	__property Align = {default=2};
	__property Anchors = {default=3};
	__property Constraints;
	__property Ctl3D;
	__property DoubleBuffered = {default=1};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property FixAlign = {default=0};
	__property Font;
	__property Images;
	__property Panels;
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property SimplePanel = {default=0};
	__property SimpleText = {default=0};
	__property SizeGrip = {default=1};
	__property ShowHint;
	__property UseSystemFont;
	__property Visible = {default=1};
	__property OnAdjustContentRect;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnPanelClick;
	__property OnPanelDblClick;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TTBXCustomStatusBar.Create */ inline __fastcall virtual TTBXStatusBar(System::Classes::TComponent* AOwner) : TTBXCustomStatusBar(AOwner) { }
	/* TTBXCustomStatusBar.Destroy */ inline __fastcall virtual ~TTBXStatusBar() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TTBXStatusBar(HWND ParentWindow) : TTBXCustomStatusBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Tbxstatusbars */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TBXSTATUSBARS)
using namespace Tbxstatusbars;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TBXStatusBarsHPP
