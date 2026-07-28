// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DragDropFilesEx.pas' rev: 37.00 (Windows)

#ifndef DragDropFilesExHPP
#define DragDropFilesExHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <DragDrop.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Winapi.ActiveX.hpp>
#include <PIDL.hpp>
#include <Winapi.ShlObj.hpp>
#include <System.Win.ComObj.hpp>
#include <System.Win.Registry.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dragdropfilesex
{
//-- forward type declarations -----------------------------------------------
struct TDropFiles;
struct TFDDListItem;
struct TCMListItem;
class DELPHICLASS TFileList;
class DELPHICLASS TDataObjectFilesEx;
class DELPHICLASS TDropTargetFilesEx;
class DELPHICLASS TShellExtension;
class DELPHICLASS TDragDropFilesEx;
//-- type declarations -------------------------------------------------------
typedef TDropFiles *PDropFiles;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TDropFiles
{
public:
	unsigned pFiles;
	Winapi::Windows::TPoint pt;
	System::LongBool fNC;
	System::LongBool fWide;
};
#pragma pack(pop)


using Winapi::Shlobj::PItemIDList;

enum DECLSPEC_DENUM TFileExMustDnD : unsigned char { nvFilename, nvPIDL };

typedef System::Set<TFileExMustDnD, TFileExMustDnD::nvFilename, TFileExMustDnD::nvPIDL> TFileExMustDnDSet;

typedef void __fastcall (__closure *TOnSpecifyDropTarget)(System::TObject* Sender, bool DragDropHandler, const Winapi::Windows::TPoint &pt, PItemIDList &pidlFQ, System::UnicodeString &Filename);

typedef TFDDListItem *PFDDListItem;

struct DECLSPEC_DRECORD TFDDListItem
{
public:
	PItemIDList pidlFQ;
	System::UnicodeString Name;
	System::UnicodeString MappedName;
};


typedef TCMListItem *PCMListItem;

struct DECLSPEC_DRECORD TCMListItem
{
public:
	int FirstCmd;
	int LastCmd;
	_di_IContextMenu CM;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TFileList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	HIDESBASE PFDDListItem __fastcall Get(int Index);
	HIDESBASE void __fastcall Put(int Index, PFDDListItem Item);
	
public:
	__fastcall TFileList();
	__fastcall virtual ~TFileList();
	virtual void __fastcall Clear();
	HIDESBASE void __fastcall Delete(int Index);
	HIDESBASE int __fastcall Remove(PFDDListItem Item);
	HIDESBASE PFDDListItem __fastcall First();
	HIDESBASE PFDDListItem __fastcall Last();
	int __fastcall AddItem(PItemIDList ApidlFQ, System::UnicodeString AName);
	int __fastcall AddItemEx(PItemIDList ApidlFQ, System::UnicodeString AName, System::UnicodeString AMappedName);
	bool __fastcall RenderPIDLs();
	bool __fastcall RenderNames();
	__property PFDDListItem Items[int Index] = {read=Get, write=Put};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TDataObjectFilesEx : public Dragdrop::TDataObject
{
	typedef Dragdrop::TDataObject inherited;
	
private:
	System::Classes::TMemoryStream* pidlStream;
	System::Classes::TMemoryStream* HDropStream;
	System::Classes::TStringList* FilenameMapList;
	bool FilenamesAreMapped;
	System::Classes::TNotifyEvent FOnRelease;
	bool FPreferCopy;
	
public:
	__fastcall TDataObjectFilesEx(TFileList* AFileList, bool RenderPIDL, bool RenderFilename, bool PreferCopy);
	__fastcall virtual ~TDataObjectFilesEx();
	virtual HRESULT __fastcall RenderData(const Winapi::Activex::TFormatEtc &FormatEtc, Winapi::Activex::TStgMedium &StgMedium);
	bool __fastcall IsValid(bool FormatPidl, bool FormatHDrop);
	__property System::Classes::TNotifyEvent OnRelease = {read=FOnRelease, write=FOnRelease};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TDropTargetFilesEx : public Dragdrop::TDropTarget
{
	typedef Dragdrop::TDropTarget inherited;
	
protected:
	virtual void __fastcall AcceptDataObject(_di_IDataObject DataObj, bool &Accept);
	
public:
	__fastcall TDropTargetFilesEx(Dragdrop::TDragDrop* AOwner);
	__fastcall virtual ~TDropTargetFilesEx();
	virtual void __fastcall RenderDropped(_di_IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TShellExtension : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FDropHandler;
	bool FDragDropHandler;
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
__published:
	__property bool DropHandler = {read=FDropHandler, write=FDropHandler, default=0};
	__property bool DragDropHandler = {read=FDragDropHandler, write=FDragDropHandler, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TShellExtension() { }
	
public:
	/* TObject.Create */ inline __fastcall TShellExtension() : System::Classes::TPersistent() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TDragDropFilesEx : public Dragdrop::TDragDrop
{
	typedef Dragdrop::TDragDrop inherited;
	
private:
	TFileList* FFileList;
	TFileExMustDnDSet FNeedValid;
	bool FCompleteFileList;
	bool FFileNamesAreMapped;
	TOnSpecifyDropTarget FOnSpecifyDropTarget;
	TShellExtension* FShellExtension;
	System::Classes::TList* FCMList;
	System::Classes::TNotifyEvent FOnDataObjectRelease;
	bool FPreferCopy;
	
protected:
	virtual Dragdrop::TDataObject* __fastcall CreateDataObject();
	void __fastcall DataObjectRelease(System::TObject* Sender);
	virtual void __fastcall DoMenuPopup(System::TObject* Sender, HMENU AMenu, _di_IDataObject DataObj, int AMinCustCmd, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt);
	virtual bool __fastcall DoMenuExecCmd(System::TObject* Sender, HMENU AMenu, _di_IDataObject DataObj, int Command, System::LongInt &dwEffect);
	virtual void __fastcall DoMenuDestroy(System::TObject* Sender, HMENU AMenu);
	virtual bool __fastcall DropHandler(const _di_IDataObject dataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt, System::LongInt &dwEffect);
	
public:
	__fastcall virtual TDragDropFilesEx(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDragDropFilesEx();
	bool __fastcall TargetHasDropHandler(PItemIDList pidlFQ, System::UnicodeString Filename, System::LongInt &dwEffect);
	__property TFileList* FileList = {read=FFileList, write=FFileList};
	__property bool FileNamesAreMapped = {read=FFileNamesAreMapped, nodefault};
	__property bool PreferCopy = {read=FPreferCopy, write=FPreferCopy, nodefault};
	
__published:
	__property TFileExMustDnDSet NeedValid = {read=FNeedValid, write=FNeedValid, nodefault};
	__property bool CompleteFileList = {read=FCompleteFileList, write=FCompleteFileList, default=1};
	__property TShellExtension* ShellExtensions = {read=FShellExtension, write=FShellExtension};
	__property TOnSpecifyDropTarget OnSpecifyDropTarget = {read=FOnSpecifyDropTarget, write=FOnSpecifyDropTarget};
	__property OnDropHandlerSucceeded;
	__property System::Classes::TNotifyEvent OnDataObjectRelease = {read=FOnDataObjectRelease, write=FOnDataObjectRelease};
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall Register();
}	/* namespace Dragdropfilesex */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DRAGDROPFILESEX)
using namespace Dragdropfilesex;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DragDropFilesExHPP
