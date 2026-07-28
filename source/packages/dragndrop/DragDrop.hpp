// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DragDrop.pas' rev: 37.00 (Windows)

#ifndef DragDropHPP
#define DragDropHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Vcl.Menus.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Graphics.hpp>
#include <Winapi.ActiveX.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------
#include <oleidl.h>

namespace Dragdrop
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TFormatEtcList;
class DELPHICLASS TDDInterfacedObject;
class DELPHICLASS TEnumFormatEtc;
class DELPHICLASS TDataObject;
class DELPHICLASS TDropSource;
class DELPHICLASS TDropTarget;
class DELPHICLASS TScrollDetectArea;
class DELPHICLASS TScrollDetectOptions;
class DELPHICLASS TDragDrop;
//-- type declarations -------------------------------------------------------
typedef _di_IEnumFORMATETC IEnumFormatEtc;

typedef _di_IDataObject IDataObject;

using Winapi::Activex::TFormatEtc;

using Winapi::Activex::TStgMedium;

enum DECLSPEC_DENUM TDropEffect : unsigned char { deCopy, deMove, deLink };

enum DECLSPEC_DENUM TDragResult : unsigned char { drInvalid, drCancelled, drCopy, drMove, drLink };

typedef System::Set<TDropEffect, TDropEffect::deCopy, TDropEffect::deLink> TDropEffectSet;

enum DECLSPEC_DENUM TDragDetectStatus : unsigned char { ddsNone, ddsLeft, ddsRight, ddsCancelled, ddsDrag };

enum DECLSPEC_DENUM TRenderDataOn : unsigned char { rdoEnter, rdoEnterAndDropSync, rdoEnterAndDropAsync, rdoDropSync, rdoDropAsync, rdoNever };

enum DECLSPEC_DENUM TSrcCompatibilityCheck : unsigned char { CheckLindex, CheckdwAspect };

typedef System::Set<TSrcCompatibilityCheck, TSrcCompatibilityCheck::CheckLindex, TSrcCompatibilityCheck::CheckdwAspect> TSrcCompatibilityCheckSet;

typedef System::Word TScrollInterval;

enum DECLSPEC_DENUM TScrollDirection : unsigned char { sdUp, sdDown, sdLeft, sdRight };

typedef void __fastcall (__closure *TOnDragEnter)(IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect, bool &Accept);

typedef void __fastcall (__closure *TOnDragLeave)(int Dummy);

typedef void __fastcall (__closure *TOnDragOver)(System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect, System::LongInt PreferredEffect);

typedef void __fastcall (__closure *TOnDrop)(IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect);

typedef void __fastcall (__closure *TOnQueryContinueDrag)(System::LongBool fEscapePressed, System::LongInt grfKeyState, HRESULT &Result);

typedef void __fastcall (__closure *TOnGiveFeedback)(System::LongInt dwEffect, HRESULT &Result);

typedef void __fastcall (__closure *TOnDragDetect)(System::LongInt grfKeyState, const Winapi::Windows::TPoint &DetectStart, const Winapi::Windows::TPoint &pt, TDragDetectStatus DragDetectStatus);

typedef void __fastcall (__closure *TOnProcessDropped)(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt dwEffect);

typedef void __fastcall (__closure *TOnBeforeScrolling)(System::TObject* Sender, const Winapi::Windows::TPoint &pt, TScrollInterval &Interval, TScrollDirection ScrollDirection, bool &ScrollPage);

typedef void __fastcall (__closure *TOnMenuPopup)(System::TObject* Sender, HMENU AMenu, IDataObject DataObj, int AMinCustCmd, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt);

typedef void __fastcall (__closure *TOnMenuExecCmd)(System::TObject* Sender, HMENU AMenu, IDataObject DataObj, int Command, System::LongInt &dwEffect, bool &Succeeded);

typedef void __fastcall (__closure *TOnMenuDestroy)(System::TObject* Sender, HMENU AMenu);

typedef System::DynamicArray<tagFORMATETC> TFormatEtcArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFormatEtcList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCount;
	TFormatEtcArray FList;
	TFormatEtc __fastcall Get(int Index);
	void __fastcall Put(int Index, const TFormatEtc &Item);
	
public:
	__fastcall TFormatEtcList();
	__fastcall virtual ~TFormatEtcList();
	int __fastcall Add(const TFormatEtc &Item);
	void __fastcall Clear();
	void __fastcall Delete(int Index);
	TFormatEtcList* __fastcall Clone();
	__property int Count = {read=FCount, nodefault};
	__property TFormatEtc Items[int Index] = {read=Get, write=Put};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDDInterfacedObject : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	HIDESBASE HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef();
	HIDESBASE int __stdcall _Release();
public:
	/* TObject.Create */ inline __fastcall TDDInterfacedObject() : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TDDInterfacedObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TEnumFormatEtc : public TDDInterfacedObject
{
	typedef TDDInterfacedObject inherited;
	
protected:
	TFormatEtcList* FFormatEtcList;
	int FIndex;
	
public:
	__fastcall TEnumFormatEtc(TFormatEtcList* FormatEtcList);
	__fastcall virtual ~TEnumFormatEtc();
	HRESULT __stdcall Next(System::LongInt celt, /* out */ void *elt, System::PLongInt pceltFetched);
	HRESULT __stdcall Skip(System::LongInt celt);
	HRESULT __stdcall Reset();
	HRESULT __stdcall Clone(/* out */ IEnumFormatEtc &Enum);
private:
	void *__IEnumFORMATETC;	// IEnumFORMATETC 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000103-0000-0000-C000-000000000046}
	operator _di_IEnumFORMATETC()
	{
		_di_IEnumFORMATETC intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IEnumFORMATETC*(void) { return (IEnumFORMATETC*)&__IEnumFORMATETC; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDataObject : public TDDInterfacedObject
{
	typedef TDDInterfacedObject inherited;
	
protected:
	TFormatEtcList* FFormatEtcList;
	bool FCheckLindex;
	bool FCheckdwAspect;
	
public:
	__fastcall TDataObject();
	__fastcall virtual ~TDataObject();
	HRESULT __stdcall GetData(const TFormatEtc &formatetcIn, /* out */ TStgMedium &medium);
	HRESULT __stdcall GetDataHere(const TFormatEtc &formatetc, /* out */ TStgMedium &medium);
	HRESULT __stdcall QueryGetData(const TFormatEtc &formatetc);
	HRESULT __stdcall GetCanonicalFormatEtc(const TFormatEtc &formatetc, /* out */ TFormatEtc &formatetcOut);
	HRESULT __stdcall SetData(const TFormatEtc &formatetc, TStgMedium &medium, System::LongBool fRelease);
	HRESULT __stdcall EnumFormatEtc(System::LongInt dwDirection, /* out */ IEnumFormatEtc &enumFormatEtc);
	HRESULT __stdcall DAdvise(const TFormatEtc &formatetc, System::LongInt advf, const _di_IAdviseSink advSink, /* out */ System::LongInt &dwConnection);
	HRESULT __stdcall DUnadvise(System::LongInt dwConnection);
	HRESULT __stdcall EnumDAdvise(/* out */ _di_IEnumSTATDATA &enumAdvise);
	virtual HRESULT __fastcall RenderData(const TFormatEtc &FormatEtc, TStgMedium &StgMedium) = 0 ;
	
protected:
	virtual bool __fastcall AllowData(const TFormatEtc &FormatEtc);
private:
	void *__IDataObject;	// IDataObject 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0000010E-0000-0000-C000-000000000046}
	operator _di_IDataObject()
	{
		_di_IDataObject intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDataObject*(void) { return (IDataObject*)&__IDataObject; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDropSource : public TDDInterfacedObject
{
	typedef TDDInterfacedObject inherited;
	
private:
	TDragDrop* FOwner;
	
public:
	__fastcall TDropSource(TDragDrop* AOwner);
	__fastcall virtual ~TDropSource();
	HRESULT __stdcall QueryContinueDrag(System::LongBool fEscapePressed, System::LongInt grfKeyState);
	HRESULT __stdcall GiveFeedback(System::LongInt dwEffect);
private:
	void *__IDropSource;	// IDropSource 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000121-0000-0000-C000-000000000046}
	operator _di_IDropSource()
	{
		_di_IDropSource intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDropSource*(void) { return (IDropSource*)&__IDropSource; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDropTarget : public TDDInterfacedObject
{
	typedef TDDInterfacedObject inherited;
	
private:
	bool FAccept;
	Vcl::Extctrls::TTimer* HorzStartTimer;
	Vcl::Extctrls::TTimer* HorzScrollTimer;
	Vcl::Extctrls::TTimer* VertStartTimer;
	Vcl::Extctrls::TTimer* VertScrollTimer;
	int FVScrollCode;
	int FHScrollCode;
	System::LongInt FPreferredEffect;
	void __fastcall InitScroll(bool VerticalScroll, int ScrollCode);
	void __fastcall TermScroll(bool VerticalScroll);
	void __fastcall DetermineScrollDir(bool VertScrolling, int &ScrollCode);
	void __fastcall OnStartTimer(System::TObject* Sender);
	void __fastcall OnScrollTimer(System::TObject* Sender);
	
protected:
	TDragDrop* FOwner;
	virtual void __fastcall SuggestDropEffect(System::LongInt grfKeyState, System::LongInt &dwEffect);
	virtual void __fastcall AcceptDataObject(IDataObject DataObj, bool &Accept);
	virtual void __fastcall RenderDropped(IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect);
	System::LongInt __fastcall GetPreferredDropEffect(const IDataObject DataObj);
	
public:
	__fastcall TDropTarget(TDragDrop* AOwner);
	__fastcall virtual ~TDropTarget();
	HRESULT __stdcall DragEnter(const IDataObject dataObj, System::LongInt grfKeyState, Winapi::Windows::TPoint pt, System::LongInt &dwEffect);
	HRESULT __stdcall DragOver(System::LongInt grfKeyState, Winapi::Windows::TPoint pt, System::LongInt &dwEffect);
	HRESULT __stdcall DragLeave();
	HRESULT __stdcall Drop(const IDataObject dataObj, System::LongInt grfKeyState, Winapi::Windows::TPoint pt, System::LongInt &dwEffect);
private:
	void *__IDropTarget;	// IDropTarget 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000122-0000-0000-C000-000000000046}
	operator _di_IDropTarget()
	{
		_di_IDropTarget intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDropTarget*(void) { return (IDropTarget*)&__IDropTarget; }
	#endif
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TScrollDetectArea : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FControl;
	System::Word FMargin;
	System::Word FRange;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall SetValue(int Index, System::Word Value);
	
protected:
	DYNAMIC void __fastcall Change();
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	__property System::Classes::TPersistent* Control = {read=FControl};
	
public:
	__fastcall TScrollDetectArea(System::Classes::TPersistent* Control);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property System::Word Margin = {read=FMargin, write=SetValue, index=0, default=0};
	__property System::Word Range = {read=FRange, write=SetValue, index=1, default=10};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TScrollDetectArea() { }
	
};


class PASCALIMPLEMENTATION TScrollDetectOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TDragDrop* FControl;
	TScrollInterval FScrollDelay;
	TScrollInterval FStartDelay;
	TScrollDetectArea* FLeft;
	TScrollDetectArea* FTop;
	TScrollDetectArea* FRight;
	TScrollDetectArea* FBottom;
	System::Classes::TNotifyEvent FOnChange;
	bool FHorzScrolling;
	bool FVertScrolling;
	bool FHorzPageScroll;
	bool FVertPageScroll;
	void __fastcall SetValue(int Index, TScrollInterval Value);
	
protected:
	DYNAMIC void __fastcall Change();
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	__property TDragDrop* Control = {read=FControl};
	
public:
	__fastcall TScrollDetectOptions(TDragDrop* Control);
	__fastcall virtual ~TScrollDetectOptions();
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property TScrollInterval ScrollDelay = {read=FScrollDelay, write=SetValue, index=0, default=100};
	__property TScrollInterval StartDelay = {read=FStartDelay, write=SetValue, index=1, default=750};
	__property TScrollDetectArea* AreaLeft = {read=FLeft, write=FLeft};
	__property TScrollDetectArea* AreaTop = {read=FTop, write=FTop};
	__property TScrollDetectArea* AreaRight = {read=FRight, write=FRight};
	__property TScrollDetectArea* AreaBottom = {read=FBottom, write=FBottom};
	__property bool HorzScrolling = {read=FHorzScrolling, write=FHorzScrolling, default=0};
	__property bool VertScrolling = {read=FVertScrolling, write=FVertScrolling, default=0};
	__property bool HorzPageScroll = {read=FHorzPageScroll, write=FHorzPageScroll, default=0};
	__property bool VertPageScroll = {read=FVertPageScroll, write=FVertPageScroll, default=0};
};


class PASCALIMPLEMENTATION TDragDrop : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FAutoDetectDnD;
	System::Byte FDragDetectDelta;
	bool FAcceptOwnDnD;
	bool FBTF;
	bool FContextMenu;
	Vcl::Controls::TWinControl* FDragDropControl;
	bool FRegistered;
	bool FOwnerIsSource;
	bool FShowPopUpMenu;
	TDropEffectSet FTargetEffectsSet;
	System::LongInt FTargetEffects;
	TOnQueryContinueDrag FOnQueryContinueDrag;
	TOnGiveFeedback FOnGiveFeedback;
	TOnDragEnter FOnDragEnter;
	TOnDragLeave FOnDragLeave;
	TOnDragOver FOnDragOver;
	TOnDrop FOnDrop;
	TDropEffectSet FSourceEffectsSet;
	System::LongInt FSourceEffects;
	TOnProcessDropped FOnProcessDropped;
	void *OldWndProc;
	void *WndProcPtr;
	TOnDragDetect FOnDragDetect;
	TDragDetectStatus FDragDetectStatus;
	Winapi::Windows::TPoint FDragDetectStart;
	TRenderDataOn FRenderDataOn;
	IDataObject FDataObj;
	System::LongInt FgrfKeyState;
	Winapi::Windows::TPoint Fpt;
	System::LongInt FdwEffect;
	HICON FCHCopy;
	HICON FCHMove;
	HICON FCHLink;
	HICON FCHScrollCopy;
	HICON FCHScrollMove;
	HICON FCHScrollLink;
	bool FMessageHooked;
	System::LongInt FAvailableDropEffects;
	int FTargetScrolling;
	TSrcCompatibilityCheckSet FSrcCompatibilityCheck;
	TScrollDetectOptions* FScrollDetectOptions;
	TOnBeforeScrolling FOnBeforeScrolling;
	System::Classes::TNotifyEvent FOnAfterScrolling;
	int FPressedButton;
	TDragDrop* FInternalSource;
	TOnMenuPopup FOnMenuPopup;
	TOnMenuExecCmd FOnMenuExecCmd;
	TOnMenuDestroy FOnMenuDestroy;
	TOnProcessDropped FOnMenuSucceeded;
	TOnProcessDropped FOnDropHandlerSucceeded;
	void __fastcall WndMethod(Winapi::Messages::TMessage &Msg);
	void __fastcall SetDragDropControl(Vcl::Controls::TWinControl* WinControl);
	void __fastcall SetSourceEffects(TDropEffectSet Values);
	void __fastcall SetTargetEffects(TDropEffectSet Values);
	
protected:
	TDropTarget* FDropTarget;
	virtual void __fastcall Loaded();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual TDataObject* __fastcall CreateDataObject() = 0 ;
	virtual void __fastcall DoMenuPopup(System::TObject* Sender, HMENU AMenu, IDataObject DataObj, int AMinCustCmd, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt);
	virtual bool __fastcall DoMenuExecCmd(System::TObject* Sender, HMENU AMenu, IDataObject DataObj, int Command, System::LongInt &dwEffect);
	virtual void __fastcall DoMenuDestroy(System::TObject* Sender, HMENU AMenu);
	virtual bool __fastcall DropHandler(const IDataObject dataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect);
	__property TOnProcessDropped OnDropHandlerSucceeded = {read=FOnDropHandlerSucceeded, write=FOnDropHandlerSucceeded};
	
public:
	__fastcall virtual TDragDrop(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDragDrop();
	bool __fastcall RegisterTarget();
	bool __fastcall UnRegisterTarget();
	void __fastcall HookMessageHandler();
	void __fastcall UnhookMessageHandler(bool ForceUnhook);
	TDragResult __fastcall ExecuteOperation(TDataObject* DataObject);
	TDragResult __fastcall Execute();
	virtual bool __fastcall CopyToClipboard();
	virtual bool __fastcall GetFromClipboard(System::LongInt &dwEffect);
	virtual void __fastcall StartDnDDetection(System::Uitypes::TMouseButton Button);
	__property bool OwnerIsSource = {read=FOwnerIsSource, nodefault};
	__property bool Registered = {read=FRegistered, default=0};
	__property HICON CHCopy = {read=FCHCopy, write=FCHCopy, default=0};
	__property HICON CHMove = {read=FCHMove, write=FCHMove, default=0};
	__property HICON CHLink = {read=FCHLink, write=FCHLink, default=0};
	__property HICON CHScrollCopy = {read=FCHScrollCopy, write=FCHScrollCopy, default=0};
	__property HICON CHScrollMove = {read=FCHScrollMove, write=FCHScrollMove, default=0};
	__property HICON CHScrollLink = {read=FCHScrollLink, write=FCHScrollLink, default=0};
	__property TDragDetectStatus DragDetectStatus = {read=FDragDetectStatus, nodefault};
	__property System::LongInt AvailableDropEffects = {read=FAvailableDropEffects, nodefault};
	__property TDragDrop* InternalSource = {read=FInternalSource};
	
__published:
	__property bool AcceptOwnDnD = {read=FAcceptOwnDnD, write=FAcceptOwnDnD, nodefault};
	__property bool AutoDetectDnD = {read=FAutoDetectDnD, write=FAutoDetectDnD, nodefault};
	__property bool BringToFront = {read=FBTF, write=FBTF, nodefault};
	__property System::Byte DragDetectDelta = {read=FDragDetectDelta, write=FDragDetectDelta, default=10};
	__property Vcl::Controls::TWinControl* DragDropControl = {read=FDragDropControl, write=SetDragDropControl};
	__property TRenderDataOn RenderDataOn = {read=FRenderDataOn, write=FRenderDataOn, default=3};
	__property TScrollDetectOptions* ScrollDetectOptions = {read=FScrollDetectOptions, write=FScrollDetectOptions};
	__property TSrcCompatibilityCheckSet SourceCompatibility = {read=FSrcCompatibilityCheck, write=FSrcCompatibilityCheck, nodefault};
	__property TDropEffectSet SourceEffects = {read=FSourceEffectsSet, write=SetSourceEffects, nodefault};
	__property bool TargetPopupMenu = {read=FShowPopUpMenu, write=FShowPopUpMenu, nodefault};
	__property TDropEffectSet TargetEffects = {read=FTargetEffectsSet, write=SetTargetEffects, nodefault};
	__property System::Classes::TNotifyEvent OnAfterScrolling = {read=FOnAfterScrolling, write=FOnAfterScrolling};
	__property TOnBeforeScrolling OnBeforeScrolling = {read=FOnBeforeScrolling, write=FOnBeforeScrolling};
	__property TOnDragDetect OnDragDetect = {read=FOnDragDetect, write=FOnDragDetect};
	__property TOnDragEnter OnDragEnter = {read=FOnDragEnter, write=FOnDragEnter};
	__property TOnDragLeave OnDragLeave = {read=FOnDragLeave, write=FOnDragLeave};
	__property TOnDragOver OnDragOver = {read=FOnDragOver, write=FOnDragOver};
	__property TOnDrop OnDrop = {read=FOnDrop, write=FOnDrop};
	__property TOnQueryContinueDrag OnQueryContinueDrag = {read=FOnQueryContinueDrag, write=FOnQueryContinueDrag};
	__property TOnGiveFeedback OnGiveFeedback = {read=FOnGiveFeedback, write=FOnGiveFeedback};
	__property TOnProcessDropped OnProcessDropped = {read=FOnProcessDropped, write=FOnProcessDropped};
	__property TOnMenuPopup OnMenuPopup = {read=FOnMenuPopup, write=FOnMenuPopup};
	__property TOnMenuExecCmd OnMenuExecCmd = {read=FOnMenuExecCmd, write=FOnMenuExecCmd};
	__property TOnMenuDestroy OnMenuDestroy = {read=FOnMenuDestroy, write=FOnMenuDestroy};
	__property TOnProcessDropped OnMenuSucceeded = {read=FOnMenuSucceeded, write=FOnMenuSucceeded};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 DefaultCursor = System::Int8(0x0);
extern DELPHI_PACKAGE System::ResourceString _MICopyStr;
#define Dragdrop_MICopyStr System::LoadResourceString(&Dragdrop::_MICopyStr)
extern DELPHI_PACKAGE System::ResourceString _MIMoveStr;
#define Dragdrop_MIMoveStr System::LoadResourceString(&Dragdrop::_MIMoveStr)
extern DELPHI_PACKAGE System::ResourceString _MILinkStr;
#define Dragdrop_MILinkStr System::LoadResourceString(&Dragdrop::_MILinkStr)
extern DELPHI_PACKAGE System::ResourceString _MIAbortStr;
#define Dragdrop_MIAbortStr System::LoadResourceString(&Dragdrop::_MIAbortStr)
extern DELPHI_PACKAGE void __fastcall Register();
}	/* namespace Dragdrop */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DRAGDROP)
using namespace Dragdrop;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DragDropHPP
