// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TBXExtItems.pas' rev: 37.00 (Windows)

#ifndef TBXExtItemsHPP
#define TBXExtItemsHPP

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
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <TBX.hpp>
#include <TBXThemes.hpp>
#include <TB2Item.hpp>
#include <TB2Toolbar.hpp>
#include <TB2ExtItems.hpp>
#include <TBXLists.hpp>
#include <System.UITypes.hpp>
#include <Vcl.ImgList.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tbxextitems
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TTBXEditItem;
class DELPHICLASS TTBXEditItemViewer;
class DELPHICLASS TTBXCustomDropDownItem;
class DELPHICLASS TTBXDropDownItem;
class DELPHICLASS TTBXDropDownItemViewer;
class DELPHICLASS TTBXComboBoxItem;
class DELPHICLASS TTBXComboBoxItemViewer;
class DELPHICLASS TTBXLabelItem;
class DELPHICLASS TTBXLabelItemViewer;
class DELPHICLASS TTBXColorItem;
class DELPHICLASS TTBXColorItemViewer;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TTBXEditChange)(System::TObject* Sender, const System::UnicodeString Text);

class PASCALIMPLEMENTATION TTBXEditItem : public Tb2extitems::TTBEditItem
{
	typedef Tb2extitems::TTBEditItem inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	int FAutoCompleteCounter;
	Tbx::TFontSettings* FEditorFontSettings;
	Tbx::TFontSettings* FFontSettings;
	bool FIsChanging;
	System::UnicodeString FLastEditChange;
	System::WideChar FPasswordChar;
	bool FReadOnly;
	bool FShowImage;
	TTBXEditChange FOnChange;
	void __fastcall FontSettingsChanged(System::TObject* Sender);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetPasswordChar(System::WideChar Value);
	void __fastcall SetShowImage(const bool Value);
	void __fastcall SetFontSettings(Tbx::TFontSettings* Value);
	
protected:
	virtual bool __fastcall DoAcceptText(System::UnicodeString &NewText);
	virtual bool __fastcall DoAutoComplete(System::UnicodeString &AText);
	virtual void __fastcall DoBeginEdit(Tb2extitems::TTBEditItemViewer* Viewer);
	virtual void __fastcall DoChange(const System::UnicodeString AText);
	virtual void __fastcall DoTextChanged(int Reason);
	virtual int __fastcall GetImageIndex();
	virtual Tb2item::TTBItemViewerClass __fastcall GetItemViewerClass(Tb2item::TTBView* AView);
	virtual void __fastcall GetPopupPosition(Tb2item::TTBView* ParentView, Tb2item::TTBPopupWindow* PopupWindow, Tb2item::TTBPopupPositionRec &PopupPositionRec);
	virtual Tb2item::TTBPopupWindowClass __fastcall GetPopupWindowClass();
	virtual void __fastcall HandleEditChange(Vcl::Stdctrls::TEdit* Edit);
	
public:
	bool __fastcall StartEditing(Tb2item::TTBView* AView);
	__fastcall virtual TTBXEditItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBXEditItem();
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property Tbx::TFontSettings* EditorFontSettings = {read=FEditorFontSettings, write=FEditorFontSettings};
	__property ExtendedAccept = {default=0};
	__property Tbx::TFontSettings* FontSettings = {read=FFontSettings, write=SetFontSettings};
	__property ImageIndex = {default=-1};
	__property Images;
	__property System::WideChar PasswordChar = {read=FPasswordChar, write=SetPasswordChar, default=0};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property bool ShowImage = {read=FShowImage, write=SetShowImage, default=0};
	__property TTBXEditChange OnChange = {read=FOnChange, write=FOnChange};
	__property OnSelect;
};


class PASCALIMPLEMENTATION TTBXEditItemViewer : public Tb2extitems::TTBEditItemViewer
{
	typedef Tb2extitems::TTBEditItemViewer inherited;
	
private:
	void __fastcall EditChangeHandler(System::TObject* Sender);
	System::Types::TSize __fastcall MeasureEditCaption();
	int __fastcall MeasureTextHeight();
	void __fastcall HandleEditChange(Vcl::Stdctrls::TEdit* Edit);
	
protected:
	System::Classes::TWndMethod OldWndProc;
	virtual void __fastcall CalcSize(Vcl::Graphics::TCanvas* const Canvas, int &AWidth, int &AHeight);
	virtual bool __fastcall DoExecute();
	virtual bool __fastcall HandleEditMessage(Winapi::Messages::TMessage &Message);
	virtual int __fastcall GetAccRole();
	virtual void __fastcall GetItemInfo(Vcl::Graphics::TCanvas* const Canvas, /* out */ Tbxthemes::TTBXItemInfo &ItemInfo, bool IsHoverItem, bool IsPushed, bool UseMenuColor);
	virtual Tb2extitems::TEditClass __fastcall GetEditControlClass();
	virtual void __fastcall GetEditInfo(/* out */ Tbxthemes::TTBXEditInfo &EditInfo, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual int __fastcall GetIndentBefore();
	virtual int __fastcall GetIndentAfter();
	virtual void __fastcall GetEditRect(Winapi::Windows::TRect &R);
	virtual bool __fastcall IsToolbarSize();
	void __fastcall NewEditWndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* const Canvas, const Winapi::Windows::TRect &ClientAreaRect, bool IsHoverItem, bool IsPushed, bool UseDisabledShadow);
	virtual bool __fastcall ShowImage();
	virtual bool __fastcall StripTextHotkey();
	
public:
	virtual bool __fastcall IsToolbarStyle();
public:
	/* TTBItemViewer.Create */ inline __fastcall virtual TTBXEditItemViewer(Tb2item::TTBView* AView, Tb2item::TTBCustomItem* AItem, int AGroupLevel) : Tb2extitems::TTBEditItemViewer(AView, AItem, AGroupLevel) { }
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBXEditItemViewer() { }
	
};


class PASCALIMPLEMENTATION TTBXCustomDropDownItem : public TTBXEditItem
{
	typedef TTBXEditItem inherited;
	
private:
	bool FAlwaysSelectFirst;
	bool FDropDownList;
	System::Classes::TNotifyEvent FOnCancel;
	
protected:
	virtual Tb2item::TTBPopupWindow* __fastcall CreatePopup(Tb2item::TTBView* const ParentView, Tb2item::TTBItemViewer* const ParentViewer, const bool PositionAsSubmenu, const bool SelectFirstItem, const bool Customizing, const Winapi::Windows::TPoint &APopupPoint, const Tb2item::TTBPopupAlignment Alignment);
	virtual Tb2item::TTBItemViewerClass __fastcall GetItemViewerClass(Tb2item::TTBView* AView);
	virtual Tb2item::TTBPopupWindowClass __fastcall GetPopupWindowClass();
	void __fastcall DoCancel();
	
public:
	__fastcall virtual TTBXCustomDropDownItem(System::Classes::TComponent* AOwner);
	__property bool AlwaysSelectFirst = {read=FAlwaysSelectFirst, write=FAlwaysSelectFirst, default=1};
	__property bool DropDownList = {read=FDropDownList, write=FDropDownList, default=0};
	__property System::Classes::TNotifyEvent OnCancel = {read=FOnCancel, write=FOnCancel};
public:
	/* TTBXEditItem.Destroy */ inline __fastcall virtual ~TTBXCustomDropDownItem() { }
	
};


class PASCALIMPLEMENTATION TTBXDropDownItem : public TTBXCustomDropDownItem
{
	typedef TTBXCustomDropDownItem inherited;
	
__published:
	__property AlwaysSelectFirst = {default=1};
	__property DropDownList = {default=0};
	__property LinkSubitems;
	__property SubMenuImages;
public:
	/* TTBXCustomDropDownItem.Create */ inline __fastcall virtual TTBXDropDownItem(System::Classes::TComponent* AOwner) : TTBXCustomDropDownItem(AOwner) { }
	
public:
	/* TTBXEditItem.Destroy */ inline __fastcall virtual ~TTBXDropDownItem() { }
	
};


class PASCALIMPLEMENTATION TTBXDropDownItemViewer : public TTBXEditItemViewer
{
	typedef TTBXEditItemViewer inherited;
	
protected:
	virtual void __fastcall GetCursor(const Winapi::Windows::TPoint &Pt, HICON &ACursor);
	virtual void __fastcall GetEditInfo(/* out */ Tbxthemes::TTBXEditInfo &EditInfo, const Tbxthemes::TTBXItemInfo &ItemInfo);
	virtual int __fastcall GetIndentAfter();
	virtual bool __fastcall HandleEditMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsPtInButtonPart(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TTBItemViewer.Create */ inline __fastcall virtual TTBXDropDownItemViewer(Tb2item::TTBView* AView, Tb2item::TTBCustomItem* AItem, int AGroupLevel) : TTBXEditItemViewer(AView, AItem, AGroupLevel) { }
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBXDropDownItemViewer() { }
	
};


typedef void __fastcall (__closure *TTBXCAdjustImageIndex)(TTBXComboBoxItem* Sender, const System::UnicodeString AText, int AIndex, int &ImageIndex);

class PASCALIMPLEMENTATION TTBXComboBoxItem : public TTBXCustomDropDownItem
{
	typedef TTBXCustomDropDownItem inherited;
	
private:
	bool FAutoComplete;
	Tbxlists::TTBXStringList* FList;
	System::Classes::TNotifyEvent FOnItemClick;
	TTBXCAdjustImageIndex FOnAdjustImageIndex;
	void __fastcall AdjustImageIndexHandler(Tbxlists::TTBXCustomList* Sender, int AItemIndex, int &ImageIndex);
	int __fastcall GetItemIndex();
	int __fastcall GetMaxVisibleItems();
	int __fastcall GetMaxWidth();
	int __fastcall GetMinWidth();
	System::Classes::TStrings* __fastcall GetStrings();
	bool __fastcall GetShowListImages();
	Tbxlists::TTBXLPaintEvent __fastcall GetOnClearItem();
	Tbxlists::TTBXLPaintEvent __fastcall GetOnDrawItem();
	Tbxlists::TTBXLMeasureHeight __fastcall GetOnMeasureHeight();
	Tbxlists::TTBXLMeasureWidth __fastcall GetOnMeasureWidth();
	void __fastcall ListChangeHandler(System::TObject* Sender);
	void __fastcall ListClickHandler(System::TObject* Sender);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetMaxVisibleItems(int Value);
	void __fastcall SetMaxWidth(int Value);
	void __fastcall SetMinWidth(int Value);
	void __fastcall SetOnClearItem(Tbxlists::TTBXLPaintEvent Value);
	void __fastcall SetOnDrawItem(Tbxlists::TTBXLPaintEvent Value);
	void __fastcall SetOnMeasureHeight(Tbxlists::TTBXLMeasureHeight Value);
	void __fastcall SetOnMeasureWidth(Tbxlists::TTBXLMeasureWidth Value);
	void __fastcall SetStrings(System::Classes::TStrings* Value);
	void __fastcall SetShowListImages(bool Value);
	
protected:
	int CachedImageIndex;
	bool CacheValid;
	bool IsChanging;
	virtual void __fastcall AdjustImageIndex(const System::UnicodeString AText, int AIndex, int &ImageIndex);
	virtual bool __fastcall DoAutoComplete(System::UnicodeString &AText);
	virtual void __fastcall DoListChange();
	virtual void __fastcall DoListClick();
	virtual void __fastcall DoPopup(Tb2item::TTBCustomItem* Sender, bool FromLink);
	virtual int __fastcall GetImageIndex();
	virtual Tb2item::TTBItemViewerClass __fastcall GetItemViewerClass(Tb2item::TTBView* AView);
	virtual Tbxlists::TTBXStringListClass __fastcall GetStringListClass();
	virtual void __fastcall HandleEditChange(Vcl::Stdctrls::TEdit* Edit);
	
public:
	__fastcall virtual TTBXComboBoxItem(System::Classes::TComponent* AOwner);
	virtual void __fastcall Loaded();
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, default=-1};
	virtual void __fastcall ChangeScale(int M, int D);
	
__published:
	__property bool AutoComplete = {read=FAutoComplete, write=FAutoComplete, default=1};
	__property DropDownList = {default=0};
	__property int MaxListWidth = {read=GetMaxWidth, write=SetMaxWidth, default=0};
	__property int MaxVisibleItems = {read=GetMaxVisibleItems, write=SetMaxVisibleItems, default=8};
	__property int MinListWidth = {read=GetMinWidth, write=SetMinWidth, default=64};
	__property bool ShowListImages = {read=GetShowListImages, write=SetShowListImages, default=0};
	__property System::Classes::TStrings* Strings = {read=GetStrings, write=SetStrings};
	__property SubMenuImages;
	__property OnChange;
	__property TTBXCAdjustImageIndex OnAdjustImageIndex = {read=FOnAdjustImageIndex, write=FOnAdjustImageIndex};
	__property Tbxlists::TTBXLPaintEvent OnClearItem = {read=GetOnClearItem, write=SetOnClearItem};
	__property Tbxlists::TTBXLPaintEvent OnDrawItem = {read=GetOnDrawItem, write=SetOnDrawItem};
	__property System::Classes::TNotifyEvent OnItemClick = {read=FOnItemClick, write=FOnItemClick};
	__property Tbxlists::TTBXLMeasureHeight OnMeasureHeight = {read=GetOnMeasureHeight, write=SetOnMeasureHeight};
	__property Tbxlists::TTBXLMeasureWidth OnMeasureWidth = {read=GetOnMeasureWidth, write=SetOnMeasureWidth};
	__property OnPopup;
	__property OnCancel;
public:
	/* TTBXEditItem.Destroy */ inline __fastcall virtual ~TTBXComboBoxItem() { }
	
};


class PASCALIMPLEMENTATION TTBXComboBoxItemViewer : public TTBXDropDownItemViewer
{
	typedef TTBXDropDownItemViewer inherited;
	
protected:
	virtual bool __fastcall HandleEditMessage(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall StripTextHotkey();
public:
	/* TTBItemViewer.Create */ inline __fastcall virtual TTBXComboBoxItemViewer(Tb2item::TTBView* AView, Tb2item::TTBCustomItem* AItem, int AGroupLevel) : TTBXDropDownItemViewer(AView, AItem, AGroupLevel) { }
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBXComboBoxItemViewer() { }
	
};


enum DECLSPEC_DENUM TTBXLabelOrientation : unsigned char { tbxoAuto, tbxoHorizontal, tbxoVertical };

typedef int TNonNegativeInt;

class PASCALIMPLEMENTATION TTBXLabelItem : public Tb2item::TTBCustomItem
{
	typedef Tb2item::TTBCustomItem inherited;
	
private:
	Vcl::Controls::TCaption FCaption;
	Tbx::TFontSettings* FFontSettings;
	int FMargin;
	bool FShowAccelChar;
	TTBXLabelOrientation FOrientation;
	int FFixedSize;
	bool FSectionHeader;
	Tbx::TAdjustFontEvent FOnAdjustFont;
	void __fastcall FontSettingsChanged(System::TObject* Sender);
	void __fastcall SetMargin(int Value);
	void __fastcall SetOrientation(TTBXLabelOrientation Value);
	HIDESBASE void __fastcall SetCaption(const Vcl::Controls::TCaption Value);
	void __fastcall SetFontSettings(Tbx::TFontSettings* Value);
	void __fastcall SetShowAccelChar(bool Value);
	void __fastcall SetFixedSize(int Value);
	void __fastcall SetSectionHeader(bool Value);
	
protected:
	virtual Tb2item::TTBItemViewerClass __fastcall GetItemViewerClass(Tb2item::TTBView* AView);
	
public:
	__fastcall virtual TTBXLabelItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBXLabelItem();
	void __fastcall UpdateCaption(const Vcl::Controls::TCaption Value);
	
__published:
	__property Vcl::Controls::TCaption Caption = {read=FCaption, write=SetCaption};
	__property Enabled = {default=1};
	__property Tbx::TFontSettings* FontSettings = {read=FFontSettings, write=SetFontSettings};
	__property int Margin = {read=FMargin, write=SetMargin, default=0};
	__property TTBXLabelOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	__property int FixedSize = {read=FFixedSize, write=SetFixedSize, default=0};
	__property bool SectionHeader = {read=FSectionHeader, write=SetSectionHeader, default=0};
	__property Visible = {default=1};
	__property Tbx::TAdjustFontEvent OnAdjustFont = {read=FOnAdjustFont, write=FOnAdjustFont};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBXLabelItemViewer : public Tb2item::TTBItemViewer
{
	typedef Tb2item::TTBItemViewer inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetCaptionText();
	virtual bool __fastcall GetIsHoriz();
	virtual void __fastcall DoAdjustFont(Vcl::Graphics::TFont* AFont, int StateFlags);
	virtual void __fastcall CalcSize(Vcl::Graphics::TCanvas* const Canvas, int &AWidth, int &AHeight);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* const Canvas, const Winapi::Windows::TRect &ClientAreaRect, bool IsHoverItem, bool IsPushed, bool UseDisabledShadow);
	virtual bool __fastcall IsToolbarSize();
	
public:
	virtual bool __fastcall IsToolbarStyle();
public:
	/* TTBItemViewer.Create */ inline __fastcall virtual TTBXLabelItemViewer(Tb2item::TTBView* AView, Tb2item::TTBCustomItem* AItem, int AGroupLevel) : Tb2item::TTBItemViewer(AView, AItem, AGroupLevel) { }
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBXLabelItemViewer() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TTBXColorItem : public Tbx::TTBXCustomItem
{
	typedef Tbx::TTBXCustomItem inherited;
	
private:
	System::Uitypes::TColor FColor;
	void __fastcall SetColor(System::Uitypes::TColor Value);
	
protected:
	virtual Tb2item::TTBItemViewerClass __fastcall GetItemViewerClass(Tb2item::TTBView* AView);
	
public:
	__fastcall virtual TTBXColorItem(System::Classes::TComponent* AOwner);
	
__published:
	__property Action;
	__property AutoCheck = {default=0};
	__property Caption = {default=0};
	__property Checked = {default=0};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property DisplayMode = {default=0};
	__property Enabled = {default=1};
	__property FontSettings;
	__property GroupIndex = {default=0};
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property Hint = {default=0};
	__property InheritOptions = {default=1};
	__property MaskOptions = {default=0};
	__property MinHeight = {default=0};
	__property MinWidth = {default=0};
	__property Options = {default=0};
	__property RadioItem = {default=0};
	__property ShortCut = {default=0};
	__property Visible = {default=1};
	__property OnAdjustFont;
	__property OnClick;
public:
	/* TTBXCustomItem.Destroy */ inline __fastcall virtual ~TTBXColorItem() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBXColorItemViewer : public Tbx::TTBXItemViewer
{
	typedef Tbx::TTBXItemViewer inherited;
	
protected:
	virtual void __fastcall DoPaintCaption(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ClientAreaRect, Winapi::Windows::TRect &CaptionRect, bool IsTextRotated, bool &PaintDefault);
	virtual bool __fastcall GetImageShown();
	DYNAMIC System::Types::TSize __fastcall GetImageSize();
	virtual void __fastcall DrawItemImage(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const Tbxthemes::TTBXItemInfo &ItemInfo);
	
public:
	__fastcall virtual TTBXColorItemViewer(Tb2item::TTBView* AView, Tb2item::TTBCustomItem* AItem, int AGroupLevel);
public:
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBXColorItemViewer() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 tcrNumericProperty = System::Int8(0x3);
static _DELPHI_CONST System::Int8 tcrSpinButton = System::Int8(0x4);
static _DELPHI_CONST System::Int8 tcrList = System::Int8(0x5);
}	/* namespace Tbxextitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TBXEXTITEMS)
using namespace Tbxextitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TBXExtItemsHPP
