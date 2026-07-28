// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TB2Item.pas' rev: 37.00 (Windows)

#ifndef TB2ItemHPP
#define TB2ItemHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <TB2Anim.hpp>
#include <System.UITypes.hpp>
#include <System.ImageList.hpp>
#include <System.Types.hpp>
#include <System.Actions.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tb2item
{
//-- forward type declarations -----------------------------------------------
struct TTBDoneActionData;
struct TTBItemData;
class DELPHICLASS ETBItemError;
class DELPHICLASS TTBImageChangeLink;
struct TTBPopupPositionRec;
class DELPHICLASS TTBCustomItem;
class DELPHICLASS TTBCustomItemActionLink;
class DELPHICLASS TTBBaseAccObject;
class DELPHICLASS TTBItemViewer;
class DELPHICLASS TTBView;
class DELPHICLASS TTBRootItem;
class DELPHICLASS TTBItem;
class DELPHICLASS TTBGroupItem;
class DELPHICLASS TTBSubmenuItem;
class DELPHICLASS TTBSeparatorItem;
class DELPHICLASS TTBSeparatorItemViewer;
class DELPHICLASS TTBControlItem;
class DELPHICLASS TTBPopupView;
__interface DELPHIINTERFACE ITBPopupWindow;
typedef System::DelphiInterface<ITBPopupWindow> _di_ITBPopupWindow;
class DELPHICLASS TTBPopupWindow;
__interface DELPHIINTERFACE ITBItems;
typedef System::DelphiInterface<ITBItems> _di_ITBItems;
class DELPHICLASS TTBItemContainer;
class DELPHICLASS TTBPopupMenu;
class DELPHICLASS TTBCustomImageList;
class DELPHICLASS TTBImageList;
class DELPHICLASS TTBModalHandler;
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TTBCustomItemClass;

typedef System::TMetaClass* TTBCustomItemActionLinkClass;

typedef System::TMetaClass* TTBItemViewerClass;

typedef System::TMetaClass* TTBPopupWindowClass;

enum DECLSPEC_DENUM TTBDoneAction : unsigned char { tbdaNone, tbdaCancel, tbdaClickItem, tbdaOpenSystemMenu, tbdaHelpContext, tbdaHelpKeyword };

typedef TTBDoneActionData *PTBDoneActionData;

struct DECLSPEC_DRECORD TTBDoneActionData
{
public:
	TTBDoneAction DoneAction;
	
public:
	union
	{
		struct 
		{
			System::SmallStringBase<100> HelpKeyword;
		};
		struct 
		{
			int ContextID;
		};
		struct 
		{
			HWND Wnd;
			unsigned Key;
		};
		struct 
		{
			TTBCustomItem* ClickItem;
			bool Sound;
		};
		
	};
};


typedef void __fastcall (__closure *TTBInsertItemProc)(System::Classes::TComponent* AParent, TTBCustomItem* AItem);

enum DECLSPEC_DENUM TTBItemChangedAction : unsigned char { tbicInserted, tbicDeleting, tbicSubitemsChanged, tbicSubitemsBeginUpdate, tbicSubitemsEndUpdate, tbicInvalidate, tbicInvalidateAndResize, tbicRecreateItemViewers, tbicNameChanged, tbicSubMenuImagesChanged };

typedef void __fastcall (__closure *TTBItemChangedProc)(TTBCustomItem* Sender, bool Relayed, TTBItemChangedAction Action, int Index, TTBCustomItem* Item);

struct DECLSPEC_DRECORD TTBItemData
{
public:
	TTBCustomItem* Item;
};


typedef System::StaticArray<TTBItemData, 536870911> TTBItemDataArray;

typedef TTBItemDataArray *PTBItemDataArray;

enum DECLSPEC_DENUM TTBItemDisplayMode : unsigned char { nbdmDefault, nbdmTextOnly, nbdmTextOnlyInMenus, nbdmImageAndText };

enum DECLSPEC_DENUM TTBItemOption : unsigned char { tboDefault, tboDropdownArrow, tboImageAboveCaption, tboLongHintInMenuOnly, tboNoAutoHint, tboNoRotation, tboSameWidth, tboShowHint, tboToolbarStyle, tboToolbarSize };

typedef System::Set<TTBItemOption, TTBItemOption::tboDefault, TTBItemOption::tboToolbarSize> TTBItemOptions;

enum DECLSPEC_DENUM Tb2item__1 : unsigned char { tbisSubmenu, tbisSelectable, tbisSeparator, tbisEmbeddedGroup, tbisClicksTransparent, tbisCombo, tbisNoAutoOpen, tbisSubitemsEditable, tbisNoLineBreak, tbisRightAlign, tbisDontSelectFirst, tbisRedrawOnSelChange, tbisRedrawOnMouseOverChange, tbisStretch };

typedef System::Set<Tb2item__1, Tb2item__1::tbisSubmenu, Tb2item__1::tbisStretch> TTBItemStyle;

enum DECLSPEC_DENUM TTBPopupAlignment : unsigned char { tbpaLeft, tbpaRight, tbpaCenter };

typedef void __fastcall (__closure *TTBPopupEvent)(TTBCustomItem* Sender, bool FromLink);

typedef void __fastcall (__closure *TTBSelectEvent)(TTBCustomItem* Sender, TTBItemViewer* Viewer, bool Selecting);

#pragma pack(push,4)
class PASCALIMPLEMENTATION ETBItemError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ETBItemError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ETBItemError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ETBItemError(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ETBItemError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ETBItemError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ETBItemError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ETBItemError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ETBItemError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ETBItemError(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ETBItemError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ETBItemError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ETBItemError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ETBItemError() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TTBImageChangeLink : public Vcl::Imglist::TChangeLink
{
	typedef Vcl::Imglist::TChangeLink inherited;
	
private:
	int FLastWidth;
	int FLastHeight;
public:
	/* TChangeLink.Create */ inline __fastcall virtual TTBImageChangeLink() : Vcl::Imglist::TChangeLink() { }
	
public:
	/* TImageLink.Destroy */ inline __fastcall virtual ~TTBImageChangeLink() { }
	
};


struct DECLSPEC_DRECORD TTBPopupPositionRec
{
public:
	bool PositionAsSubmenu;
	TTBPopupAlignment Alignment;
	bool Opposite;
	Winapi::Windows::TRect MonitorRect;
	Winapi::Windows::TRect ParentItemRect;
	int NCSizeX;
	int NCSizeY;
	int X;
	int Y;
	int W;
	int H;
	Tb2anim::TTBAnimationDirection AnimDir;
	bool PlaySound;
};


class PASCALIMPLEMENTATION TTBCustomItem : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
public:
	TTBCustomItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	TTBCustomItemActionLink* FActionLink;
	bool FAutoCheck;
	System::UnicodeString FCaption;
	bool FChecked;
	TTBItemDisplayMode FDisplayMode;
	bool FEnabled;
	TTBItemOptions FEffectiveOptions;
	int FGroupIndex;
	System::Classes::THelpContext FHelpContext;
	System::UnicodeString FHelpKeyword;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	TTBImageChangeLink* FImagesChangeLink;
	PTBItemDataArray FItems;
	int FItemCount;
	TTBItemStyle FItemStyle;
	System::Classes::TList* FLinkParents;
	TTBItemOptions FMaskOptions;
	TTBItemOptions FOptions;
	bool FInheritOptions;
	System::Classes::TList* FNotifyList;
	System::Classes::TNotifyEvent FOnClick;
	TTBPopupEvent FOnPopup;
	TTBSelectEvent FOnSelect;
	TTBCustomItem* FParent;
	System::Classes::TComponent* FParentComponent;
	bool FRadioItem;
	System::Classes::TShortCut FShortCut;
	Vcl::Imglist::TCustomImageList* FSubMenuImages;
	TTBImageChangeLink* FSubMenuImagesChangeLink;
	TTBCustomItem* FLinkSubitems;
	bool FVisible;
	void __fastcall DoActionChange(System::TObject* Sender);
	bool __fastcall ChangeImages(Vcl::Imglist::TCustomImageList* &AImages, Vcl::Imglist::TCustomImageList* const Value, TTBImageChangeLink* &AChangeLink);
	__classmethod void __fastcall ClickWndProc(Winapi::Messages::TMessage &Message);
	TTBCustomItem* __fastcall FindItemWithShortCut(System::Classes::TShortCut AShortCut, TTBCustomItem* &ATopmostParent);
	TTBItemOptions __fastcall FixOptions(const TTBItemOptions AOptions);
	System::Classes::TBasicAction* __fastcall GetAction();
	TTBCustomItem* __fastcall GetItem(int Index);
	void __fastcall ImageListChangeHandler(System::TObject* Sender);
	void __fastcall InternalNotify(TTBCustomItem* Ancestor, int NestingLevel, TTBItemChangedAction Action, int Index, TTBCustomItem* Item);
	bool __fastcall IsAutoCheckStored();
	bool __fastcall IsCaptionStored();
	bool __fastcall IsCheckedStored();
	bool __fastcall IsEnabledStored();
	bool __fastcall IsHelpContextStored();
	bool __fastcall IsHintStored();
	bool __fastcall IsImageIndexStored();
	bool __fastcall IsOnClickStored();
	bool __fastcall IsShortCutStored();
	bool __fastcall IsVisibleStored();
	void __fastcall Notify(TTBItemChangedAction Action, int Index, TTBCustomItem* Item);
	void __fastcall RefreshOptions();
	void __fastcall SetAction(System::Classes::TBasicAction* Value);
	void __fastcall SetCaption(System::UnicodeString Value);
	void __fastcall SetChecked(bool Value);
	void __fastcall SetDisplayMode(TTBItemDisplayMode Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetGroupIndex(int Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetInheritOptions(bool Value);
	void __fastcall SetLinkSubitems(TTBCustomItem* Value);
	void __fastcall SetMaskOptions(TTBItemOptions Value);
	void __fastcall SetOptions(TTBItemOptions Value);
	void __fastcall SetRadioItem(bool Value);
	void __fastcall SetSubMenuImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SubMenuImagesChanged();
	void __fastcall TurnSiblingsOff();
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall Change(bool NeedResize);
	virtual TTBPopupWindow* __fastcall CreatePopup(TTBView* const ParentView, TTBItemViewer* const ParentViewer, const bool PositionAsSubmenu, const bool SelectFirstItem, const bool Customizing, const Winapi::Windows::TPoint &APopupPoint, const TTBPopupAlignment Alignment);
	virtual void __fastcall DoPopup(TTBCustomItem* Sender, bool FromLink);
	virtual void __fastcall EnabledChanged();
	DYNAMIC TTBCustomItemActionLinkClass __fastcall GetActionLinkClass();
	virtual TTBView* __fastcall GetChevronParentView();
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual TTBItemViewerClass __fastcall GetItemViewerClass(TTBView* AView);
	virtual void __fastcall GetPopupPosition(TTBView* ParentView, TTBPopupWindow* PopupWindow, TTBPopupPositionRec &PopupPositionRec);
	virtual TTBPopupWindowClass __fastcall GetPopupWindowClass();
	void __fastcall IndexError();
	virtual void __fastcall Loaded();
	virtual bool __fastcall NeedToRecreateViewer(TTBItemViewer* AViewer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	TTBCustomItem* __fastcall OpenPopup(const bool SelectFirstItem, const bool TrackRightButton, const Winapi::Windows::TPoint &PopupPoint, const TTBPopupAlignment Alignment, const bool ReturnClickedItemOnly, bool PositionAsSubmenu);
	void __fastcall RecreateItemViewers();
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	__property TTBCustomItemActionLink* ActionLink = {read=FActionLink, write=FActionLink};
	__property TTBItemStyle ItemStyle = {read=FItemStyle, write=FItemStyle, nodefault};
	
public:
	__fastcall virtual TTBCustomItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBCustomItem();
	DYNAMIC bool __fastcall HasParent();
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent();
	System::Classes::TComponent* __fastcall GetTopComponent();
	void __fastcall Add(TTBCustomItem* AItem);
	void __fastcall Clear();
	virtual void __fastcall Click();
	bool __fastcall ContainsItem(TTBCustomItem* AItem);
	void __fastcall Delete(int Index);
	System::UnicodeString __fastcall GetShortCutText();
	int __fastcall IndexOf(TTBCustomItem* AItem);
	virtual void __fastcall InitiateAction();
	HIDESBASE void __fastcall Insert(int NewIndex, TTBCustomItem* AItem);
	bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	void __fastcall Move(int CurIndex, int NewIndex);
	TTBCustomItem* __fastcall Popup(int X, int Y, bool TrackRightButton, TTBPopupAlignment Alignment = (TTBPopupAlignment)(0x0), bool ReturnClickedItemOnly = false, bool PositionAsSubmenu = false);
	void __fastcall PostClick();
	void __fastcall RegisterNotification(TTBItemChangedProc ANotify);
	HIDESBASE void __fastcall Remove(TTBCustomItem* Item);
	void __fastcall UnregisterNotification(TTBItemChangedProc ANotify);
	void __fastcall ViewBeginUpdate();
	void __fastcall ViewEndUpdate();
	virtual void __fastcall ChangeScale(int M, int D);
	__property System::Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property bool AutoCheck = {read=FAutoCheck, write=FAutoCheck, stored=IsAutoCheckStored, default=0};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property int Count = {read=FItemCount, nodefault};
	__property bool Checked = {read=FChecked, write=SetChecked, stored=IsCheckedStored, default=0};
	__property TTBItemDisplayMode DisplayMode = {read=FDisplayMode, write=SetDisplayMode, default=0};
	__property TTBItemOptions EffectiveOptions = {read=FEffectiveOptions, nodefault};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property System::Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, stored=IsHelpContextStored, default=0};
	__property System::UnicodeString HelpKeyword = {read=FHelpKeyword, write=FHelpKeyword, stored=IsHelpContextStored};
	__property System::UnicodeString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool InheritOptions = {read=FInheritOptions, write=SetInheritOptions, default=1};
	__property TTBCustomItem* Items[int Index] = {read=GetItem/*, default*/};
	__property TTBCustomItem* LinkSubitems = {read=FLinkSubitems, write=SetLinkSubitems};
	__property TTBItemOptions MaskOptions = {read=FMaskOptions, write=SetMaskOptions, default=0};
	__property TTBItemOptions Options = {read=FOptions, write=SetOptions, default=0};
	__property TTBCustomItem* Parent = {read=FParent};
	__property System::Classes::TComponent* ParentComponent = {read=FParentComponent, write=FParentComponent};
	__property bool RadioItem = {read=FRadioItem, write=SetRadioItem, default=0};
	__property System::Classes::TShortCut ShortCut = {read=FShortCut, write=FShortCut, stored=IsShortCutStored, default=0};
	__property Vcl::Imglist::TCustomImageList* SubMenuImages = {read=FSubMenuImages, write=SetSubMenuImages};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
	__property TTBPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
	__property TTBSelectEvent OnSelect = {read=FOnSelect, write=FOnSelect};
};


class PASCALIMPLEMENTATION TTBCustomItemActionLink : public Vcl::Actnlist::TActionLink
{
	typedef Vcl::Actnlist::TActionLink inherited;
	
protected:
	TTBCustomItem* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsAutoCheckLinked();
	virtual bool __fastcall IsCaptionLinked();
	virtual bool __fastcall IsCheckedLinked();
	virtual bool __fastcall IsEnabledLinked();
	virtual bool __fastcall IsHelpContextLinked();
	virtual bool __fastcall IsHelpLinked();
	virtual bool __fastcall IsHintLinked();
	virtual bool __fastcall IsImageIndexLinked();
	virtual bool __fastcall IsShortCutLinked();
	virtual bool __fastcall IsVisibleLinked();
	virtual bool __fastcall IsOnExecuteLinked();
	virtual void __fastcall SetAutoCheck(bool Value);
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHelpContext(System::Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const System::UnicodeString Value);
	virtual void __fastcall SetHint(const System::UnicodeString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetShortCut(System::Classes::TShortCut Value);
	virtual void __fastcall SetVisible(bool Value);
	virtual void __fastcall SetOnExecute(System::Classes::TNotifyEvent Value);
public:
	/* TBasicActionLink.Create */ inline __fastcall virtual TTBCustomItemActionLink(System::TObject* AClient) : Vcl::Actnlist::TActionLink(AClient) { }
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TTBCustomItemActionLink() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBBaseAccObject : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	virtual void __fastcall ClientIsDestroying() = 0 ;
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, System::Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
public:
	/* TObject.Create */ inline __fastcall TTBBaseAccObject() : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TTBBaseAccObject() { }
	
private:
	void *__IDispatch;	// IDispatch 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020400-0000-0000-C000-000000000046}
	operator _di_IDispatch()
	{
		_di_IDispatch intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBItemViewer : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	enum DECLSPEC_DENUM _TTBItemViewer__1 : unsigned char { tbisInvalidated, tbisLineSep };
	
	
private:
	Winapi::Windows::TRect FBoundsRect;
	bool FClipped;
	int FGroupLevel;
	TTBCustomItem* FItem;
	bool FOffEdge;
	bool FShow;
	TTBView* FView;
	void __fastcall AccSelect(const bool AExecute);
	int __fastcall GetIndex();
	
protected:
	TTBBaseAccObject* FAccObjectInstance;
	virtual void __fastcall CalcSize(Vcl::Graphics::TCanvas* const Canvas, int &AWidth, int &AHeight);
	DYNAMIC bool __fastcall CaptionShown();
	virtual bool __fastcall DoExecute();
	virtual void __fastcall DrawItemCaption(Vcl::Graphics::TCanvas* const Canvas, const Winapi::Windows::TRect &ARect, const System::UnicodeString ACaption, bool ADrawDisabledShadow, unsigned AFormat);
	virtual void __fastcall Entering(TTBItemViewer* OldSelected);
	virtual int __fastcall GetAccRole();
	virtual bool __fastcall GetAccValue(System::WideString &Value);
	virtual System::UnicodeString __fastcall GetCaptionText();
	virtual void __fastcall GetCursor(const Winapi::Windows::TPoint &Pt, HICON &ACursor);
	Vcl::Imglist::TCustomImageList* __fastcall GetImageList();
	bool __fastcall ImageShown();
	bool __fastcall IsRotated();
	virtual bool __fastcall IsToolbarSize();
	virtual bool __fastcall IsPtInButtonPart(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Leaving();
	virtual void __fastcall LosingCapture();
	virtual void __fastcall MouseDown(System::Classes::TShiftState Shift, int X, int Y, bool &MouseDownOnMenu);
	virtual void __fastcall MouseMove(int X, int Y);
	virtual void __fastcall MouseUp(int X, int Y, bool MouseWasDownOnMenu);
	virtual void __fastcall MouseWheel(int WheelDelta, int X, int Y);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* const Canvas, const Winapi::Windows::TRect &ClientAreaRect, bool IsSelected, bool IsPushed, bool UseDisabledShadow);
	void __fastcall PostAccSelect(const bool AExecute);
	virtual bool __fastcall UsesSameWidth();
	
public:
	System::Set<_TTBItemViewer__1, _TTBItemViewer__1::tbisInvalidated, _TTBItemViewer__1::tbisLineSep> State;
	__property Winapi::Windows::TRect BoundsRect = {read=FBoundsRect};
	__property bool Clipped = {read=FClipped, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property TTBCustomItem* Item = {read=FItem};
	__property bool OffEdge = {read=FOffEdge, nodefault};
	__property bool Show = {read=FShow, nodefault};
	__property TTBView* View = {read=FView};
	__fastcall virtual TTBItemViewer(TTBView* AView, TTBCustomItem* AItem, int AGroupLevel);
	__fastcall virtual ~TTBItemViewer();
	void __fastcall Execute(bool AGivePriority);
	_di_IDispatch __fastcall GetAccObject();
	System::UnicodeString __fastcall GetHintText();
	bool __fastcall IsAccessible();
	virtual bool __fastcall IsToolbarStyle();
	Winapi::Windows::TPoint __fastcall ScreenToClient(const Winapi::Windows::TPoint &P);
};

#pragma pack(pop)

typedef System::StaticArray<TTBItemViewer*, 536870911> TTBItemViewerArray;

typedef TTBItemViewerArray *PTBItemViewerArray;

enum DECLSPEC_DENUM TTBViewOrientation : unsigned char { tbvoHorizontal, tbvoVertical, tbvoFloating };

enum DECLSPEC_DENUM Tb2item__8 : unsigned char { tbetMouseDown, tbetExecuteSelected, tbetFromMSAA };

typedef System::Set<Tb2item__8, Tb2item__8::tbetMouseDown, Tb2item__8::tbetFromMSAA> TTBEnterToolbarLoopOptions;

enum DECLSPEC_DENUM Tb2item__9 : unsigned char { vsModal, vsMouseInWindow, vsDrawInOrder, vsOppositePopup, vsIgnoreFirstMouseUp, vsShowAccels, vsDropDownMenus, vsNoAnimation };

typedef System::Set<Tb2item__9, Tb2item__9::vsModal, Tb2item__9::vsNoAnimation> TTBViewState;

enum DECLSPEC_DENUM Tb2item__01 : unsigned char { vsMenuBar, vsUseHiddenAccels, vsAlwaysShowHints };

typedef System::Set<Tb2item__01, Tb2item__01::vsMenuBar, Tb2item__01::vsAlwaysShowHints> TTBViewStyle;

enum DECLSPEC_DENUM TTBViewTimerID : unsigned char { tiOpen, tiClose, tiScrollUp, tiScrollDown };

typedef System::TMetaClass* TTBViewClass;

class PASCALIMPLEMENTATION TTBView : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Set<TTBViewTimerID, TTBViewTimerID::tiOpen, TTBViewTimerID::tiScrollDown> FActiveTimers;
	System::Uitypes::TColor FBackgroundColor;
	Winapi::Windows::TPoint FBaseSize;
	bool FCapture;
	HWND FCaptureWnd;
	int FChevronOffset;
	TTBView* FChevronParentView;
	int FChevronSize;
	TTBCustomItem* FCurParentItem;
	bool FCustomizing;
	TTBDoneActionData FDoneActionData;
	int FInternalViewersAtEnd;
	int FInternalViewersAtFront;
	bool FIsPopup;
	bool FIsToolbar;
	int FMaxHeight;
	Winapi::Windows::TRect FMonitorRect;
	bool FMouseOverSelected;
	bool FNewViewersGetHighestPriority;
	TTBItemViewer* FOpenViewer;
	TTBView* FOpenViewerView;
	TTBPopupWindow* FOpenViewerWindow;
	TTBView* FParentView;
	TTBCustomItem* FParentItem;
	System::Classes::TList* FPriorityList;
	TTBViewOrientation FOrientation;
	int FScrollOffset;
	TTBItemViewer* FSelected;
	bool FSelectedViaMouse;
	bool FShowDownArrow;
	bool FShowUpArrow;
	TTBViewState FState;
	TTBViewStyle FStyle;
	int FUpdating;
	bool FUsePriorityList;
	bool FValidated;
	int FViewerCount;
	PTBItemViewerArray FViewers;
	Vcl::Controls::TWinControl* FWindow;
	int FWrapOffset;
	void __fastcall DeletingViewer(TTBItemViewer* Viewer);
	void __fastcall DrawItem(TTBItemViewer* Viewer, Vcl::Graphics::TCanvas* DrawTo, bool Offscreen);
	void __fastcall FreeViewers();
	void __fastcall ImagesChanged();
	int __fastcall InsertItemViewers(const int NewIndex, TTBCustomItem* const AItem, const int AGroupLevel, const bool AddToPriorityList, const bool TopOfPriorityList);
	void __fastcall ItemNotification(TTBCustomItem* Ancestor, bool Relayed, TTBItemChangedAction Action, int Index, TTBCustomItem* Item);
	void __fastcall LinkNotification(TTBCustomItem* Ancestor, bool Relayed, TTBItemChangedAction Action, int Index, TTBCustomItem* Item);
	void __fastcall RecreateItemViewer(const int I);
	void __fastcall Scroll(bool ADown);
	void __fastcall SetCustomizing(bool Value);
	void __fastcall SetSelected(TTBItemViewer* Value);
	void __fastcall SetUsePriorityList(bool Value);
	void __fastcall StartTimer(const TTBViewTimerID ATimer, const int Interval);
	void __fastcall StopAllTimers();
	void __fastcall StopTimer(const TTBViewTimerID ATimer);
	void __fastcall UpdateCurParentItem();
	
protected:
	TTBBaseAccObject* FAccObjectInstance;
	virtual void __fastcall AutoSize(int AWidth, int AHeight);
	bool __fastcall CalculatePositions(const bool CanMoveControls, const TTBViewOrientation AOrientation, int AWrapOffset, int AChevronOffset, int AChevronSize, Winapi::Windows::TPoint &ABaseSize, Winapi::Windows::TPoint &TotalSize, int &AWrappedLines);
	virtual void __fastcall DoUpdatePositions(Winapi::Windows::TPoint &ASize);
	virtual TTBCustomItem* __fastcall GetChevronItem();
	virtual void __fastcall GetMargins(TTBViewOrientation AOrientation, Winapi::Windows::TRect &Margins);
	virtual TTBCustomItem* __fastcall GetMDIButtonsItem();
	virtual TTBCustomItem* __fastcall GetMDISystemMenuItem();
	TTBView* __fastcall GetParentToolbarView();
	TTBView* __fastcall GetRootView();
	bool __fastcall HandleWMGetObject(Winapi::Messages::TMessage &Message);
	void __fastcall InitiateActions();
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SetAccelsVisibility(bool AShowAccels);
	void __fastcall SetState(TTBViewState AState);
	__property TTBDoneActionData DoneActionData = {read=FDoneActionData, write=FDoneActionData};
	__property bool ShowDownArrow = {read=FShowDownArrow, nodefault};
	__property bool ShowUpArrow = {read=FShowUpArrow, nodefault};
	
public:
	__fastcall virtual TTBView(System::Classes::TComponent* AOwner, TTBView* AParentView, TTBCustomItem* AParentItem, Vcl::Controls::TWinControl* AWindow, bool AIsToolbar, bool ACustomizing, bool AUsePriorityList);
	__fastcall virtual ~TTBView();
	void __fastcall BeginUpdate();
	void __fastcall CancelCapture();
	void __fastcall CancelChildPopups();
	void __fastcall CancelMode();
	void __fastcall CloseChildPopups();
	bool __fastcall ContainsView(TTBView* AView);
	void __fastcall DrawSubitems(Vcl::Graphics::TCanvas* ACanvas);
	void __fastcall EndModal();
	void __fastcall EndModalWithClick(TTBItemViewer* AViewer);
	void __fastcall EndModalWithHelp(int AContextID)/* overload */;
	void __fastcall EndModalWithHelp(System::UnicodeString HelpKeyword)/* overload */;
	void __fastcall EndModalWithSystemMenu(HWND AWnd, unsigned AKey);
	void __fastcall EndUpdate();
	virtual void __fastcall EnterToolbarLoop(TTBEnterToolbarLoopOptions Options);
	void __fastcall ExecuteSelected(bool AGivePriority);
	TTBItemViewer* __fastcall Find(TTBCustomItem* Item);
	TTBItemViewer* __fastcall FirstSelectable();
	_di_IDispatch __fastcall GetAccObject();
	HWND __fastcall GetCaptureWnd();
	virtual Vcl::Graphics::TFont* __fastcall GetFont();
	void __fastcall GetOffEdgeControlList(System::Classes::TList* const List);
	void __fastcall GivePriority(TTBItemViewer* AViewer);
	TTBItemViewer* __fastcall HighestPriorityViewer();
	void __fastcall Invalidate(TTBItemViewer* AViewer);
	virtual void __fastcall InvalidatePositions();
	int __fastcall IndexOf(TTBItemViewer* AViewer);
	bool __fastcall IsModalEnding();
	TTBItemViewer* __fastcall NextSelectable(TTBItemViewer* CurViewer, bool GoForward);
	TTBItemViewer* __fastcall NextSelectableWithAccel(TTBItemViewer* CurViewer, System::WideChar Key, bool RequirePrimaryAccel, bool &IsOnlyItemWithAccel);
	void __fastcall NotifyFocusEvent();
	bool __fastcall OpenChildPopup(const bool SelectFirstItem);
	void __fastcall RecreateAllViewers();
	void __fastcall ScrollSelectedIntoView();
	void __fastcall Select(TTBItemViewer* Value, bool ViaMouse);
	void __fastcall SetCapture();
	void __fastcall TryValidatePositions();
	void __fastcall UpdateSelection(const Winapi::Windows::PPoint P, const bool AllowNewSelection);
	Winapi::Windows::TPoint __fastcall UpdatePositions();
	void __fastcall ValidatePositions();
	TTBItemViewer* __fastcall ViewerFromPoint(const Winapi::Windows::TPoint &P);
	virtual Vcl::Forms::TMonitor* __fastcall GetMonitor();
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=FBackgroundColor, nodefault};
	__property Winapi::Windows::TPoint BaseSize = {read=FBaseSize};
	__property bool Capture = {read=FCapture, nodefault};
	__property int ChevronOffset = {read=FChevronOffset, write=FChevronOffset, nodefault};
	__property int ChevronSize = {read=FChevronSize, write=FChevronSize, nodefault};
	__property bool Customizing = {read=FCustomizing, write=SetCustomizing, nodefault};
	__property bool IsPopup = {read=FIsPopup, nodefault};
	__property bool IsToolbar = {read=FIsToolbar, nodefault};
	__property bool MouseOverSelected = {read=FMouseOverSelected, nodefault};
	__property bool NewViewersGetHighestPriority = {read=FNewViewersGetHighestPriority, write=FNewViewersGetHighestPriority, nodefault};
	__property TTBView* ParentView = {read=FParentView};
	__property TTBCustomItem* ParentItem = {read=FParentItem};
	__property TTBItemViewer* OpenViewer = {read=FOpenViewer};
	__property TTBView* OpenViewerView = {read=FOpenViewerView};
	__property TTBViewOrientation Orientation = {read=FOrientation, write=FOrientation, nodefault};
	__property TTBItemViewer* Selected = {read=FSelected, write=SetSelected};
	__property bool SelectedViaMouse = {read=FSelectedViaMouse, nodefault};
	__property TTBViewState State = {read=FState, nodefault};
	__property TTBViewStyle Style = {read=FStyle, write=FStyle, nodefault};
	__property bool UsePriorityList = {read=FUsePriorityList, write=SetUsePriorityList, nodefault};
	__property PTBItemViewerArray Viewers = {read=FViewers};
	__property int ViewerCount = {read=FViewerCount, nodefault};
	__property Vcl::Controls::TWinControl* Window = {read=FWindow};
	__property int WrapOffset = {read=FWrapOffset, write=FWrapOffset, nodefault};
public:
	/* TComponent.Create */ inline __fastcall virtual TTBView(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	
};


typedef System::TMetaClass* TTBRootItemClass;

class PASCALIMPLEMENTATION TTBRootItem : public TTBCustomItem
{
	typedef TTBCustomItem inherited;
	
public:
	/* TTBCustomItem.Create */ inline __fastcall virtual TTBRootItem(System::Classes::TComponent* AOwner) : TTBCustomItem(AOwner) { }
	/* TTBCustomItem.Destroy */ inline __fastcall virtual ~TTBRootItem() { }
	
};


class PASCALIMPLEMENTATION TTBItem : public TTBCustomItem
{
	typedef TTBCustomItem inherited;
	
__published:
	__property Action;
	__property AutoCheck = {default=0};
	__property Caption = {default=0};
	__property Checked = {default=0};
	__property DisplayMode = {default=0};
	__property Enabled = {default=1};
	__property GroupIndex = {default=0};
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property Hint = {default=0};
	__property ImageIndex = {default=-1};
	__property Images;
	__property InheritOptions = {default=1};
	__property MaskOptions = {default=0};
	__property Options = {default=0};
	__property RadioItem = {default=0};
	__property ShortCut = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnSelect;
public:
	/* TTBCustomItem.Create */ inline __fastcall virtual TTBItem(System::Classes::TComponent* AOwner) : TTBCustomItem(AOwner) { }
	/* TTBCustomItem.Destroy */ inline __fastcall virtual ~TTBItem() { }
	
};


class PASCALIMPLEMENTATION TTBGroupItem : public TTBCustomItem
{
	typedef TTBCustomItem inherited;
	
public:
	__fastcall virtual TTBGroupItem(System::Classes::TComponent* AOwner);
	
__published:
	__property InheritOptions = {default=1};
	__property LinkSubitems;
	__property MaskOptions = {default=0};
	__property Options = {default=0};
public:
	/* TTBCustomItem.Destroy */ inline __fastcall virtual ~TTBGroupItem() { }
	
};


class PASCALIMPLEMENTATION TTBSubmenuItem : public TTBCustomItem
{
	typedef TTBCustomItem inherited;
	
private:
	bool __fastcall GetDropdownCombo();
	void __fastcall SetDropdownCombo(bool Value);
	
public:
	__fastcall virtual TTBSubmenuItem(System::Classes::TComponent* AOwner);
	
__published:
	__property Action;
	__property AutoCheck = {default=0};
	__property Caption = {default=0};
	__property Checked = {default=0};
	__property DisplayMode = {default=0};
	__property bool DropdownCombo = {read=GetDropdownCombo, write=SetDropdownCombo, default=0};
	__property Enabled = {default=1};
	__property GroupIndex = {default=0};
	__property HelpContext = {default=0};
	__property HelpKeyword = {default=0};
	__property Hint = {default=0};
	__property ImageIndex = {default=-1};
	__property Images;
	__property InheritOptions = {default=1};
	__property LinkSubitems;
	__property MaskOptions = {default=0};
	__property Options = {default=0};
	__property RadioItem = {default=0};
	__property ShortCut = {default=0};
	__property SubMenuImages;
	__property Visible = {default=1};
	__property OnClick;
	__property OnPopup;
	__property OnSelect;
public:
	/* TTBCustomItem.Destroy */ inline __fastcall virtual ~TTBSubmenuItem() { }
	
};


class PASCALIMPLEMENTATION TTBSeparatorItem : public TTBCustomItem
{
	typedef TTBCustomItem inherited;
	
private:
	bool FBlank;
	void __fastcall SetBlank(bool Value);
	
protected:
	virtual TTBItemViewerClass __fastcall GetItemViewerClass(TTBView* AView);
	
public:
	__fastcall virtual TTBSeparatorItem(System::Classes::TComponent* AOwner);
	
__published:
	__property bool Blank = {read=FBlank, write=SetBlank, default=0};
	__property Hint = {default=0};
	__property Visible = {default=1};
public:
	/* TTBCustomItem.Destroy */ inline __fastcall virtual ~TTBSeparatorItem() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBSeparatorItemViewer : public TTBItemViewer
{
	typedef TTBItemViewer inherited;
	
protected:
	virtual void __fastcall CalcSize(Vcl::Graphics::TCanvas* const Canvas, int &AWidth, int &AHeight);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* const Canvas, const Winapi::Windows::TRect &ClientAreaRect, bool IsSelected, bool IsPushed, bool UseDisabledShadow);
	virtual bool __fastcall UsesSameWidth();
public:
	/* TTBItemViewer.Create */ inline __fastcall virtual TTBSeparatorItemViewer(TTBView* AView, TTBCustomItem* AItem, int AGroupLevel) : TTBItemViewer(AView, AItem, AGroupLevel) { }
	/* TTBItemViewer.Destroy */ inline __fastcall virtual ~TTBSeparatorItemViewer() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TTBControlItem : public TTBCustomItem
{
	typedef TTBCustomItem inherited;
	
private:
	Vcl::Controls::TControl* FControl;
	bool FDontFreeControl;
	void __fastcall SetControl(Vcl::Controls::TControl* Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TTBControlItem(System::Classes::TComponent* AOwner);
	__fastcall TTBControlItem(System::Classes::TComponent* AOwner, Vcl::Controls::TControl* AControl);
	__fastcall virtual ~TTBControlItem();
	__property bool DontFreeControl = {read=FDontFreeControl, write=FDontFreeControl, nodefault};
	
__published:
	__property Vcl::Controls::TControl* Control = {read=FControl, write=SetControl};
};


class PASCALIMPLEMENTATION TTBPopupView : public TTBView
{
	typedef TTBView inherited;
	
protected:
	virtual void __fastcall AutoSize(int AWidth, int AHeight);
	
public:
	virtual Vcl::Forms::TMonitor* __fastcall GetMonitor();
	virtual Vcl::Graphics::TFont* __fastcall GetFont();
public:
	/* TTBView.CreateView */ inline __fastcall virtual TTBPopupView(System::Classes::TComponent* AOwner, TTBView* AParentView, TTBCustomItem* AParentItem, Vcl::Controls::TWinControl* AWindow, bool AIsToolbar, bool ACustomizing, bool AUsePriorityList) : TTBView(AOwner, AParentView, AParentItem, AWindow, AIsToolbar, ACustomizing, AUsePriorityList) { }
	/* TTBView.Destroy */ inline __fastcall virtual ~TTBPopupView() { }
	
public:
	/* TComponent.Create */ inline __fastcall virtual TTBPopupView(System::Classes::TComponent* AOwner) : TTBView(AOwner) { }
	
};


__interface  INTERFACE_UUID("{E45CBE74-1ECF-44CB-B064-6D45B1924708}") ITBPopupWindow  : public System::IInterface 
{
	
};

class PASCALIMPLEMENTATION TTBPopupWindow : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FAccelsVisibilitySet;
	Tb2anim::TTBAnimationDirection FAnimationDirection;
	TTBView* FView;
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	MESSAGE void __fastcall CMHintShowPause(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMClose(Winapi::Messages::TWMClose &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMGetObject(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	MESSAGE void __fastcall WMPrint(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPrintClient(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMTB2kStepAnimation(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMTB2kAnimationEnded(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	virtual void __fastcall DestroyWindowHandle();
	DYNAMIC Winapi::Windows::TPoint __fastcall GetNCSize();
	DYNAMIC TTBViewClass __fastcall GetViewClass();
	virtual void __fastcall Paint();
	virtual void __fastcall PaintScrollArrows();
	__property Tb2anim::TTBAnimationDirection AnimationDirection = {read=FAnimationDirection, nodefault};
	DYNAMIC void __fastcall Cancel();
	
public:
	__fastcall virtual TTBPopupWindow(System::Classes::TComponent* AOwner, TTBView* const AParentView, TTBCustomItem* const AItem, const bool ACustomizing, const Winapi::Windows::TPoint &PopupPoint);
	__fastcall virtual ~TTBPopupWindow();
	virtual void __fastcall BeforeDestruction();
	__property TTBView* View = {read=FView};
public:
	/* TCustomControl.Create */ inline __fastcall virtual TTBPopupWindow(System::Classes::TComponent* AOwner) : Vcl::Controls::TCustomControl(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TTBPopupWindow(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
private:
	void *__ITBPopupWindow;	// ITBPopupWindow 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E45CBE74-1ECF-44CB-B064-6D45B1924708}
	operator _di_ITBPopupWindow()
	{
		_di_ITBPopupWindow intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ITBPopupWindow*(void) { return (ITBPopupWindow*)&__ITBPopupWindow; }
	#endif
	
};


__interface  INTERFACE_UUID("{A5C0D7CC-3EC4-4090-A0F8-3D03271877EA}") ITBItems  : public System::IInterface 
{
	virtual TTBCustomItem* __fastcall GetItems() = 0 ;
};

class PASCALIMPLEMENTATION TTBItemContainer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TTBRootItem* FItem;
	Vcl::Imglist::TCustomImageList* __fastcall GetImages();
	TTBCustomItem* __fastcall GetItems();
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	
protected:
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	
public:
	__fastcall virtual TTBItemContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBItemContainer();
	__property TTBRootItem* Items = {read=FItem};
	
__published:
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
private:
	void *__ITBItems;	// ITBItems 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A5C0D7CC-3EC4-4090-A0F8-3D03271877EA}
	operator _di_ITBItems()
	{
		_di_ITBItems intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ITBItems*(void) { return (ITBItems*)&__ITBItems; }
	#endif
	
};


class PASCALIMPLEMENTATION TTBPopupMenu : public Vcl::Menus::TPopupMenu
{
	typedef Vcl::Menus::TPopupMenu inherited;
	
private:
	TTBRootItem* FItem;
	Vcl::Imglist::TCustomImageList* __fastcall GetImages();
	TTBCustomItem* __fastcall GetItems();
	TTBCustomItem* __fastcall GetLinkSubitems();
	TTBItemOptions __fastcall GetOptions();
	void __fastcall RootItemClick(System::TObject* Sender);
	HIDESBASE void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetLinkSubitems(TTBCustomItem* Value);
	void __fastcall SetOptions(TTBItemOptions Value);
	
protected:
	DYNAMIC TTBRootItemClass __fastcall GetRootItemClass();
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	
public:
	__fastcall virtual TTBPopupMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBPopupMenu();
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	virtual void __fastcall Popup(int X, int Y);
	TTBCustomItem* __fastcall PopupEx(int X, int Y, bool ReturnClickedItemOnly = false);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	
__published:
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property TTBRootItem* Items = {read=FItem};
	__property TTBCustomItem* LinkSubitems = {read=GetLinkSubitems, write=SetLinkSubitems};
	__property TTBItemOptions Options = {read=GetOptions, write=SetOptions, default=0};
private:
	void *__ITBItems;	// ITBItems 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A5C0D7CC-3EC4-4090-A0F8-3D03271877EA}
	operator _di_ITBItems()
	{
		_di_ITBItems intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ITBItems*(void) { return (ITBItems*)&__ITBItems; }
	#endif
	
};


class PASCALIMPLEMENTATION TTBCustomImageList : public Vcl::Controls::TImageList
{
	typedef Vcl::Controls::TImageList inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FCheckedImages;
	Vcl::Imglist::TChangeLink* FCheckedImagesChangeLink;
	Vcl::Imglist::TCustomImageList* FDisabledImages;
	Vcl::Imglist::TChangeLink* FDisabledImagesChangeLink;
	Vcl::Imglist::TCustomImageList* FHotImages;
	Vcl::Imglist::TChangeLink* FHotImagesChangeLink;
	Vcl::Graphics::TBitmap* FImagesBitmap;
	System::Uitypes::TColor FImagesBitmapMaskColor;
	void __fastcall ChangeImages(Vcl::Imglist::TCustomImageList* &AImageList, Vcl::Imglist::TCustomImageList* Value, Vcl::Imglist::TChangeLink* AChangeLink);
	void __fastcall ImageListChanged(System::TObject* Sender);
	void __fastcall ImagesBitmapChanged(System::TObject* Sender);
	void __fastcall SetCheckedImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetDisabledImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetHotImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetImagesBitmap(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetImagesBitmapMaskColor(System::Uitypes::TColor Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property Vcl::Imglist::TCustomImageList* CheckedImages = {read=FCheckedImages, write=SetCheckedImages};
	__property Vcl::Imglist::TCustomImageList* DisabledImages = {read=FDisabledImages, write=SetDisabledImages};
	__property Vcl::Imglist::TCustomImageList* HotImages = {read=FHotImages, write=SetHotImages};
	__property Vcl::Graphics::TBitmap* ImagesBitmap = {read=FImagesBitmap, write=SetImagesBitmap};
	__property System::Uitypes::TColor ImagesBitmapMaskColor = {read=FImagesBitmapMaskColor, write=SetImagesBitmapMaskColor, default=16711935};
	
public:
	__fastcall virtual TTBCustomImageList(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TTBCustomImageList();
	virtual void __fastcall DrawState(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int Index, bool Enabled, bool Selected, bool Checked);
public:
	/* TCustomImageList.CreateSize */ inline __fastcall TTBCustomImageList(int AWidth, int AHeight) : Vcl::Controls::TImageList(AWidth, AHeight) { }
	
};


class PASCALIMPLEMENTATION TTBImageList : public TTBCustomImageList
{
	typedef TTBCustomImageList inherited;
	
__published:
	__property CheckedImages;
	__property DisabledImages;
	__property HotImages;
	__property ImagesBitmap;
	__property ImagesBitmapMaskColor = {default=16711935};
public:
	/* TTBCustomImageList.Create */ inline __fastcall virtual TTBImageList(System::Classes::TComponent* AOwner) : TTBCustomImageList(AOwner) { }
	/* TTBCustomImageList.Destroy */ inline __fastcall virtual ~TTBImageList() { }
	
public:
	/* TCustomImageList.CreateSize */ inline __fastcall TTBImageList(int AWidth, int AHeight) : TTBCustomImageList(AWidth, AHeight) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBModalHandler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCreatedWnd;
	bool FInited;
	HWND FWnd;
	TTBPopupWindow* FRootPopup;
	void __fastcall WndProc(Winapi::Messages::TMessage &Msg);
	
public:
	__fastcall TTBModalHandler(HWND AExistingWnd);
	__fastcall virtual ~TTBModalHandler();
	void __fastcall Loop(TTBView* const RootView, const bool AMouseDown, const bool AExecuteSelected, const bool AFromMSAA, const bool TrackRightButton);
	__property TTBPopupWindow* RootPopup = {read=FRootPopup, write=FRootPopup};
	__property HWND Wnd = {read=FWnd, nodefault};
	__classmethod void __fastcall DoLockForegroundWindow(unsigned LockCode);
	__classmethod void __fastcall LockForegroundWindow();
	__classmethod void __fastcall UnlockForegroundWindow();
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word WM_TB2K_POPUPSHOWING = System::Word(0x62a);
static _DELPHI_CONST System::Int8 TPS_ANIMSTART = System::Int8(0x1);
static _DELPHI_CONST System::Int8 TPS_ANIMFINISHED = System::Int8(0x2);
static _DELPHI_CONST System::Int8 TPS_NOANIM = System::Int8(0x3);
static _DELPHI_CONST int tbMenuBkColor = int(-16777212);
static _DELPHI_CONST int tbMenuTextColor = int(-16777209);
static _DELPHI_CONST System::Int8 tbMenuVerticalMargin = System::Int8(0x4);
static _DELPHI_CONST System::Int8 tbMenuImageTextSpace = System::Int8(0x1);
static _DELPHI_CONST System::Int8 tbMenuLeftTextMargin = System::Int8(0x2);
static _DELPHI_CONST System::Int8 tbMenuRightTextMargin = System::Int8(0x3);
static _DELPHI_CONST System::Int8 tbMenuSeparatorOffset = System::Int8(0xc);
static _DELPHI_CONST System::Int8 tbMenuScrollArrowHeight = System::Int8(0x13);
static _DELPHI_CONST System::Int8 tbDropdownArrowWidth = System::Int8(0x8);
static _DELPHI_CONST System::Int8 tbDropdownArrowMargin = System::Int8(0x3);
static _DELPHI_CONST System::Int8 tbDropdownComboArrowWidth = System::Int8(0xb);
static _DELPHI_CONST System::Int8 tbDropdownComboMargin = System::Int8(0x2);
static _DELPHI_CONST System::Int8 tbLineSpacing = System::Int8(0x6);
static _DELPHI_CONST System::Int8 tbLineSepOffset = System::Int8(0x1);
static _DELPHI_CONST System::Int8 tbDockedLineSepOffset = System::Int8(0x4);
static _DELPHI_CONST System::Word WM_TB2K_CLICKITEM = System::Word(0x500);
extern DELPHI_PACKAGE TTBCustomItem* __fastcall ProcessDoneAction(const TTBDoneActionData &DoneActionData, const bool ReturnClickedItemOnly);
extern DELPHI_PACKAGE Vcl::Graphics::TFont* __fastcall GetToolbarFont(int PixelsPerInch)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TFont* __fastcall GetToolbarFont(Vcl::Controls::TControl* Control)/* overload */;
extern DELPHI_PACKAGE void __fastcall TBInitToolbarSystemFont();
}	/* namespace Tb2item */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TB2ITEM)
using namespace Tb2item;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TB2ItemHPP
