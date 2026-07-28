// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TBXOfficeXPTheme.pas' rev: 37.00 (Windows)

#ifndef TBXOfficeXPThemeHPP
#define TBXOfficeXPThemeHPP

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
#include <Vcl.Graphics.hpp>
#include <TBXThemes.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Controls.hpp>
#include <TB2Item.hpp>
#include <Vcl.Forms.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tbxofficexptheme
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TTBXOfficeXPTheme;
class DELPHICLASS TTBXDarkOfficeXPTheme;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TItemPart : unsigned char { ipBody, ipText, ipFrame };

enum DECLSPEC_DENUM TBtnItemState : unsigned char { bisNormal, bisDisabled, bisSelected, bisPressed, bisHot, bisDisabledHot, bisSelectedHot, bisPopupParent };

enum DECLSPEC_DENUM TMenuItemState : unsigned char { misNormal, misDisabled, misHot, misDisabledHot };

enum DECLSPEC_DENUM TWinFramePart : unsigned char { wfpBorder, wfpCaption, wfpCaptionText };

enum DECLSPEC_DENUM TWinFrameState : unsigned char { wfsActive, wfsInactive };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBXOfficeXPTheme : public Tbxthemes::TTBXTheme
{
	typedef Tbxthemes::TTBXTheme inherited;
	
private:
	MESSAGE void __fastcall TBXSysCommand(Winapi::Messages::TMessage &Message);
	
protected:
	System::Uitypes::TColor MenubarColor;
	System::Uitypes::TColor ToolbarColor;
	System::Uitypes::TColor PopupColor;
	System::Uitypes::TColor DockPanelColor;
	System::Uitypes::TColor PopupFrameColor;
	System::StaticArray<System::StaticArray<System::Uitypes::TColor, 3>, 2> WinFrameColors;
	System::StaticArray<System::StaticArray<System::Uitypes::TColor, 3>, 2> PnlFrameColors;
	System::StaticArray<System::StaticArray<System::Uitypes::TColor, 3>, 4> MenuItemColors;
	System::StaticArray<System::StaticArray<System::Uitypes::TColor, 3>, 8> BtnItemColors;
	System::Uitypes::TColor DragHandleColor;
	System::Uitypes::TColor PopupSeparatorColor;
	System::Uitypes::TColor ToolbarSeparatorColor;
	System::Uitypes::TColor IconShadowColor;
	System::Uitypes::TColor StatusPanelFrameColor;
	bool FDark;
	virtual void __fastcall SetupColorCache();
	System::Uitypes::TColor __fastcall GetPartColor(const Tbxthemes::TTBXItemInfo &ItemInfo, TItemPart ItemPart);
	System::Uitypes::TColor __fastcall GetBtnColor(const Tbxthemes::TTBXItemInfo &ItemInfo, TItemPart ItemPart);
	System::Uitypes::TColor __fastcall GetStandardColor(System::Uitypes::TColor Color);
	void __fastcall Init();
	__fastcall TTBXOfficeXPTheme(const System::UnicodeString AName, bool Dark)/* overload */;
	
public:
	__fastcall virtual TTBXOfficeXPTheme(const System::UnicodeString AName)/* overload */;
	__fastcall virtual ~TTBXOfficeXPTheme();
	virtual bool __fastcall GetBooleanMetrics(int Index);
	virtual int __fastcall GetIntegerMetrics(Vcl::Forms::TMonitor* Monitor, int Index)/* overload */;
	virtual void __fastcall GetMargins(int MarginID, /* out */ Tbxthemes::TTBXMargins &Margins);
	virtual Winapi::Windows::TPoint __fastcall GetImageOffset(Vcl::Graphics::TCanvas* Canvas, const Tbxthemes::TTBXItemInfo &ItemInfo, Vcl::Imglist::TCustomImageList* ImageList);
	virtual System::Uitypes::TColor __fastcall GetItemColor(const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual System::Uitypes::TColor __fastcall GetItemTextColor(const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual System::Uitypes::TColor __fastcall GetItemImageBackground(const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual int __fastcall GetPopupShadowType();
	virtual void __fastcall GetViewBorder(Vcl::Controls::TControl* Control, int ViewType, /* out */ Winapi::Windows::TPoint &Border);
	virtual System::Uitypes::TColor __fastcall GetViewColor(int AViewType);
	virtual void __fastcall GetViewMargins(int ViewType, /* out */ Tbxthemes::TTBXMargins &Margins);
	virtual unsigned __fastcall GetSysColor(int nIndex);
	virtual void __fastcall PaintBackgnd(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ADockRect, const Winapi::Windows::TRect &ARect, const Winapi::Windows::TRect &AClipRect, System::Uitypes::TColor AColor, bool Transparent, int AViewType);
	virtual void __fastcall PaintButton(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintCaption(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo, const System::UnicodeString ACaption, unsigned AFormat, bool Rotated);
	virtual void __fastcall PaintCheckMark(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintChevron(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintDock(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ClientRect, const Winapi::Windows::TRect &DockRect, int DockPosition);
	virtual void __fastcall PaintDropDownArrow(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintEditButton(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, Tbxthemes::TTBXItemInfo &ItemInfo, const Tbxthemes::TTBXEditBtnInfo &ButtonInfo);
	virtual void __fastcall PaintEditFrame(Vcl::Forms::TMonitor* Monitor, Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, Tbxthemes::TTBXItemInfo &ItemInfo, const Tbxthemes::TTBXEditInfo &EditInfo);
	virtual void __fastcall PaintFloatingBorder(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXWindowInfo &WindowInfo);
	virtual void __fastcall PaintFrame(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintImage(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex);
	virtual void __fastcall PaintMenuItem(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintMenuItemFrame(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual void __fastcall PaintPopupNCArea(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &R, const Tbxthemes::TTBXPopupInfo &PopupInfo);
	virtual void __fastcall PaintSeparator(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo, bool Horizontal, bool LineSeparator);
	virtual void __fastcall PaintToolbarNCArea(Vcl::Forms::TMonitor* Monitor, Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &R, const Tbxthemes::TTBXToolbarInfo &ToolbarInfo);
	virtual void __fastcall PaintStatusBar(Vcl::Controls::TWinControl* Control, Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &R, int Part);
	/* Hoisted overloads: */
	
public:
	inline int __fastcall  GetIntegerMetrics(Tb2item::TTBItemViewer* Viewer, int Index){ return Tbxthemes::TTBXTheme::GetIntegerMetrics(Viewer, Index); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBXDarkOfficeXPTheme : public TTBXOfficeXPTheme
{
	typedef TTBXOfficeXPTheme inherited;
	
public:
	__fastcall virtual TTBXDarkOfficeXPTheme(const System::UnicodeString AName)/* overload */;
protected:
	/* TTBXOfficeXPTheme.CreateEx */ inline __fastcall TTBXDarkOfficeXPTheme(const System::UnicodeString AName, bool Dark)/* overload */ : TTBXOfficeXPTheme(AName, Dark) { }
	
public:
	/* TTBXOfficeXPTheme.Destroy */ inline __fastcall virtual ~TTBXDarkOfficeXPTheme() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Tbxofficexptheme */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TBXOFFICEXPTHEME)
using namespace Tbxofficexptheme;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TBXOfficeXPThemeHPP
