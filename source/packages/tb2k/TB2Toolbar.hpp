// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TB2Toolbar.pas' rev: 37.00 (Windows)

#ifndef TB2ToolbarHPP
#define TB2ToolbarHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ActnList.hpp>
#include <TB2Item.hpp>
#include <TB2Dock.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tb2toolbar
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TTBToolbarView;
class DELPHICLASS TTBCustomToolbar;
class DELPHICLASS TTBToolbar;
class DELPHICLASS TTBChevronItem;
class DELPHICLASS TTBChevronItemViewer;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TTBChevronItemClass;

typedef System::TMetaClass* TTBToolbarViewClass;

class PASCALIMPLEMENTATION TTBToolbarView : public Tb2item::TTBView
{
	typedef Tb2item::TTBView inherited;
	
private:
	TTBCustomToolbar* FToolbar;
	
protected:
	virtual void __fastcall AutoSize(int AWidth, int AHeight);
	virtual void __fastcall DoUpdatePositions(Winapi::Windows::TPoint &ASize);
	virtual Tb2item::TTBCustomItem* __fastcall GetChevronItem();
	virtual Tb2item::TTBCustomItem* __fastcall GetMDIButtonsItem();
	virtual Tb2item::TTBCustomItem* __fastcall GetMDISystemMenuItem();
	
public:
	__fastcall virtual TTBToolbarView(System::Classes::TComponent* AOwner);
	virtual Vcl::Graphics::TFont* __fastcall GetFont();
	virtual void __fastcall InvalidatePositions();
	virtual void __fastcall EnterToolbarLoop(Tb2item::TTBEnterToolbarLoopOptions Options);
public:
	/* TTBView.CreateView */ inline __fastcall virtual TTBToolbarView(System::Classes::TComponent* AOwner, Tb2item::TTBView* AParentView, Tb2item::TTBCustomItem* AParentItem, Vcl::Controls::TWinControl* AWindow, bool AIsToolbar, bool ACustomizing, bool AUsePriorityList) : Tb2item::TTBView(AOwner, AParentView, AParentItem, AWindow, AIsToolbar, ACustomizing, AUsePriorityList) { }
	/* TTBView.Destroy */ inline __fastcall virtual ~TTBToolbarView() { }
	
};


enum DECLSPEC_DENUM TTBChevronPriorityForNewItems : unsigned char { tbcpHighest, tbcpLowest };

typedef void __fastcall (__closure *TToolbarGetBaseSizeEvent)(TTBCustomToolbar* Toolbar, Winapi::Windows::TPoint &ASize);

class PASCALIMPLEMENTATION TTBCustomToolbar : public Tb2dock::TTBCustomDockableWindow
{
	typedef Tb2dock::TTBCustomDockableWindow inherited;
	
private:
	Winapi::Windows::TPoint FBaseSize;
	TTBChevronItem* FChevronItem;
	bool FChevronMoveItems;
	bool FChevronMenu;
	TTBChevronPriorityForNewItems FChevronPriorityForNewItems;
	int FDisableAlignArrange;
	int FFloatingWidth;
	bool FIgnoreMouseLeave;
	Tb2item::TTBRootItem* FItem;
	int FLastWrappedLines;
	bool FMenuBar;
	Vcl::Forms::TShortCutEvent FOnShortCut;
	bool FProcessShortCuts;
	bool FMainWindowHookInstalled;
	Tb2dock::TTBShrinkMode FShrinkMode;
	void *FSizeData;
	bool FSystemFont;
	bool FUpdateActions;
	TToolbarGetBaseSizeEvent FOnGetBaseSize;
	System::Classes::TNotifyEvent FOnEndModal;
	void __fastcall CancelHover();
	int __fastcall CalcChevronOffset(Tb2dock::TTBDock* const ADock, const Tb2item::TTBViewOrientation AOrientation);
	int __fastcall CalcWrapOffset(Tb2dock::TTBDock* const ADock);
	Tb2item::TTBControlItem* __fastcall CreateWrapper(int Index, Vcl::Controls::TControl* Ctl);
	Tb2item::TTBControlItem* __fastcall FindWrapper(Vcl::Controls::TControl* Ctl);
	System::UnicodeString __fastcall GetChevronHint();
	Vcl::Imglist::TCustomImageList* __fastcall GetImages();
	Tb2item::TTBCustomItem* __fastcall GetItems();
	Tb2item::TTBCustomItem* __fastcall GetLinkSubitems();
	Tb2item::TTBItemOptions __fastcall GetOptions();
	void __fastcall InstallMainWindowHook();
	bool __fastcall IsChevronHintStored();
	__classmethod bool __fastcall MainWindowHook(Winapi::Messages::TMessage &Message);
	void __fastcall SetChevronHint(const System::UnicodeString Value);
	void __fastcall SetChevronMoveItems(bool Value);
	void __fastcall SetChevronPriorityForNewItems(TTBChevronPriorityForNewItems Value);
	void __fastcall SetFloatingWidth(int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLinkSubitems(Tb2item::TTBCustomItem* Value);
	void __fastcall SetMainWindowHook();
	void __fastcall SetMenuBar(bool Value);
	void __fastcall SetOptions(Tb2item::TTBItemOptions Value);
	void __fastcall SetProcessShortCuts(bool Value);
	void __fastcall SetShrinkMode(Tb2dock::TTBShrinkMode Value);
	void __fastcall SetSystemFont(bool Value);
	void __fastcall UninstallMainWindowHook();
	void __fastcall UpdateViewProperties();
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMControlChange(Vcl::Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Vcl::Controls::TCMControlListChange &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Vcl::Controls::TCMDialogChar &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Vcl::Controls::TCMDialogKey &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowHintChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMWinIniChange(Winapi::Messages::TWMSettingChange &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMCancelMode &Message);
	HIDESBASE MESSAGE void __fastcall WMGetObject(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCMouseMove(Winapi::Messages::TWMNCMouseMove &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Winapi::Messages::TWMSysCommand &Message);
	
protected:
	Tb2item::TTBCustomItem* FMDIButtonsItem;
	Tb2item::TTBCustomItem* FMDISystemMenuItem;
	TTBToolbarView* FView;
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, Winapi::Windows::TRect &Rect);
	DYNAMIC void __fastcall BuildPotentialSizesList(System::Classes::TList* SizesList);
	virtual void __fastcall ControlExistsAtPos(const Winapi::Windows::TPoint &P, bool &ControlExists);
	virtual Winapi::Windows::TPoint __fastcall DoArrange(bool CanMoveControls, Tb2dock::TTBDockType PreviousDockType, bool NewFloating, Tb2dock::TTBDock* NewDock);
	DYNAMIC void __fastcall DoContextPopup(const Winapi::Windows::TPoint &MousePos, bool &Handled);
	virtual void __fastcall GetBaseSize(Winapi::Windows::TPoint &ASize);
	void __fastcall GetMinBarSize(Winapi::Windows::TPoint &MinimumSize);
	virtual void __fastcall GetMinShrinkSize(int &AMinimumSize);
	virtual Tb2dock::TTBShrinkMode __fastcall GetShrinkMode();
	DYNAMIC TTBChevronItemClass __fastcall GetChevronItemClass();
	DYNAMIC Tb2item::TTBRootItemClass __fastcall GetItemClass();
	DYNAMIC TTBToolbarViewClass __fastcall GetViewClass();
	virtual void __fastcall Loaded();
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint();
	DYNAMIC void __fastcall ResizeBegin(Tb2dock::TTBSizeHandle ASizeHandle);
	DYNAMIC void __fastcall ResizeTrack(Winapi::Windows::TRect &Rect, const Winapi::Windows::TRect &OrigRect);
	DYNAMIC void __fastcall ResizeTrackAccept();
	DYNAMIC void __fastcall ResizeEnd();
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool isDpiChange)/* overload */;
	__property bool SystemFont = {read=FSystemFont, write=SetSystemFont, default=1};
	__property Vcl::Forms::TShortCutEvent OnShortCut = {read=FOnShortCut, write=FOnShortCut};
	
public:
	__fastcall virtual TTBCustomToolbar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBCustomToolbar();
	HIDESBASE void __fastcall BeginUpdate();
	HIDESBASE void __fastcall EndUpdate();
	void __fastcall CreateWrappersForAllControls();
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall InitiateAction();
	bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	bool __fastcall KeyboardOpen(System::WideChar Key, bool RequirePrimaryAccel);
	DYNAMIC void __fastcall ReadPositionData(System::UnicodeString &S);
	DYNAMIC System::UnicodeString __fastcall WritePositionData();
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall Idle();
	__property System::UnicodeString ChevronHint = {read=GetChevronHint, write=SetChevronHint, stored=IsChevronHintStored};
	__property bool ChevronMoveItems = {read=FChevronMoveItems, write=SetChevronMoveItems, default=1};
	__property bool ChevronMenu = {read=FChevronMenu, write=FChevronMenu, default=0};
	__property TTBChevronPriorityForNewItems ChevronPriorityForNewItems = {read=FChevronPriorityForNewItems, write=SetChevronPriorityForNewItems, default=0};
	__property int FloatingWidth = {read=FFloatingWidth, write=SetFloatingWidth, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property Tb2item::TTBRootItem* Items = {read=FItem};
	__property Tb2item::TTBCustomItem* LinkSubitems = {read=GetLinkSubitems, write=SetLinkSubitems};
	__property Tb2item::TTBItemOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property bool MenuBar = {read=FMenuBar, write=SetMenuBar, default=0};
	__property bool ProcessShortCuts = {read=FProcessShortCuts, write=SetProcessShortCuts, default=0};
	__property Tb2dock::TTBShrinkMode ShrinkMode = {read=FShrinkMode, write=SetShrinkMode, default=2};
	__property bool UpdateActions = {read=FUpdateActions, write=FUpdateActions, default=1};
	__property TTBToolbarView* View = {read=FView};
	__property TToolbarGetBaseSizeEvent OnGetBaseSize = {read=FOnGetBaseSize, write=FOnGetBaseSize};
	__property System::Classes::TNotifyEvent OnEndModal = {read=FOnEndModal, write=FOnEndModal};
	
__published:
	__property Hint = {stored=false, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TTBCustomToolbar(HWND ParentWindow) : Tb2dock::TTBCustomDockableWindow(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	DYNAMIC inline void __fastcall  ChangeScale(int M, int D){ Vcl::Controls::TControl::ChangeScale(M, D); }
	
private:
	void *__ITBItems;	// Tb2item::ITBItems 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A5C0D7CC-3EC4-4090-A0F8-3D03271877EA}
	operator Tb2item::_di_ITBItems()
	{
		Tb2item::_di_ITBItems intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Tb2item::ITBItems*(void) { return (Tb2item::ITBItems*)&__ITBItems; }
	#endif
	
};


class PASCALIMPLEMENTATION TTBToolbar : public TTBCustomToolbar
{
	typedef TTBCustomToolbar inherited;
	
__published:
	__property ActivateParent = {default=1};
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoResize = {default=1};
	__property BorderStyle = {default=1};
	__property Caption = {default=0};
	__property ChevronHint = {default=0};
	__property ChevronMoveItems = {default=1};
	__property ChevronMenu = {default=0};
	__property ChevronPriorityForNewItems = {default=0};
	__property CloseButton = {default=1};
	__property CloseButtonWhenDocked = {default=0};
	__property Color = {default=-16777201};
	__property CurrentDock;
	__property DefaultDock;
	__property DockableTo = {default=15};
	__property DockMode = {default=0};
	__property DockPos = {default=-1};
	__property DockRow = {default=0};
	__property DragHandleStyle = {default=2};
	__property FloatingMode = {default=0};
	__property FloatingWidth = {default=0};
	__property Font;
	__property FullSize = {default=0};
	__property HideWhenInactive = {default=1};
	__property Images;
	__property Items;
	__property LastDock;
	__property LinkSubitems;
	__property MenuBar = {default=0};
	__property Options = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ProcessShortCuts = {default=0};
	__property Resizable = {default=1};
	__property ShowCaption = {default=1};
	__property ShowHint;
	__property ShrinkMode = {default=2};
	__property SmoothDrag = {default=1};
	__property Stretch = {default=0};
	__property SystemFont = {default=1};
	__property TabOrder = {default=-1};
	__property UpdateActions = {default=1};
	__property UseLastDock = {default=1};
	__property Visible = {default=1};
	__property OnClose;
	__property OnCloseQuery;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMove;
	__property OnRecreated;
	__property OnRecreating;
	__property OnDockChanged;
	__property OnDockChanging;
	__property OnDockChangingHidden;
	__property OnResize;
	__property OnShortCut;
	__property OnVisibleChanged;
	__property OnGetBaseSize;
	__property OnEndModal;
public:
	/* TTBCustomToolbar.Create */ inline __fastcall virtual TTBToolbar(System::Classes::TComponent* AOwner) : TTBCustomToolbar(AOwner) { }
	/* TTBCustomToolbar.Destroy */ inline __fastcall virtual ~TTBToolbar() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TTBToolbar(HWND ParentWindow) : TTBCustomToolbar(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TTBChevronItem : public Tb2item::TTBCustomItem
{
	typedef Tb2item::TTBCustomItem inherited;
	
private:
	TTBCustomToolbar* FToolbar;
	System::UnicodeString __fastcall GetDefaultHint();
	
public:
	__fastcall virtual TTBChevronItem(System::Classes::TComponent* AOwner);
	virtual Tb2item::TTBView* __fastcall GetChevronParentView();
	virtual Tb2item::TTBItemViewerClass __fastcall GetItemViewerClass(Tb2item::TTBView* AView);
public:
	/* TTBCustomItem.Destroy */ inline __fastcall virtual ~TTBChevronItem() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBChevronItemViewer : public Tb2item::TTBItemViewer
{
	typedef Tb2item::TTBItemViewer inherited;
	
protected:
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* const Canvas, const Winapi::Windows::TRect &ClientAreaRect, bool IsSelected, bool IsPushed, bool UseDisabledShadow);
	DYNAMIC bool __fastcall CaptionShown();
public:
	/* TTBItemViewer.Create */ inline __fastcall virtual TTBChevronItemViewer(Tb2item::TTBView* AView, Tb2item::TTBCustomItem* AItem, int AGroupLevel) : Tb2item::TTBItemViewer(AView, AItem, AGroupLevel) { }
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBChevronItemViewer() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 tbChevronSize = System::Int8(0xc);
}	/* namespace Tb2toolbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TB2TOOLBAR)
using namespace Tb2toolbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TB2ToolbarHPP
