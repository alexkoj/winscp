// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IEDriveInfoInt.pas' rev: 37.00 (Windows)

#ifndef IEDriveInfoIntHPP
#define IEDriveInfoIntHPP

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
#include <System.Win.Registry.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Winapi.ShlObj.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Vcl.Forms.hpp>
#include <BaseUtils.hpp>
#include <System.Generics.Collections.hpp>
#include <Vcl.Graphics.hpp>
#include <Winapi.Messages.hpp>
#include <System.Generics.Defaults.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Iedriveinfoint
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TDriveInfoRec;
struct TSpecialFolderRec;
class DELPHICLASS TDriveInfoInt;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TDriveInfoRec : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Winapi::Shlobj::PItemIDList PIDL;
	bool Init;
	bool Valid;
	bool ValidButHiddenByDrivePolicy;
	bool DriveReady;
	int DriveType;
	System::UnicodeString DisplayName;
	System::UnicodeString PrettyName;
	unsigned DriveSerial;
	__int64 Size;
	int ImageIndex;
	Winapi::Windows::THandle DriveHandle;
	void *NotificationHandle;
	bool SubscribeDriveNotifications;
public:
	/* TObject.Create */ inline __fastcall TDriveInfoRec() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TDriveInfoRec() { }
	
};


typedef System::WideChar TRealDrive;

typedef System::Int8 TSpecialFolder;

typedef TSpecialFolderRec *PSpecialFolderRec;

struct DECLSPEC_DRECORD TSpecialFolderRec
{
public:
	bool Valid;
	System::UnicodeString Location;
	System::UnicodeString DisplayName;
	int ImageIndex;
	Winapi::Shlobj::PItemIDList PIDL;
};


enum DECLSPEC_DENUM TDriveNotification : unsigned char { dnRefresh, dnRemoving };

typedef void __fastcall (__closure *TDriveNotificationEvent)(TDriveNotification Notification, System::UnicodeString Drive);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDriveInfoInt : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::StaticArray<TSpecialFolderRec, 28> _TDriveInfoInt__1;
	
	
private:
	unsigned FNoDrives;
	unsigned FNoViewOnDrive;
	_di_IShellFolder FDesktop;
	_TDriveInfoInt__1 FFolders;
	int FHonorDrivePolicy;
	bool FUseABDrives;
	bool FLoaded;
	System::Generics::Collections::TList__1<TDriveNotificationEvent>* FHandlers;
	unsigned FChangeNotify;
	PSpecialFolderRec __fastcall GetFolder(TSpecialFolder Folder);
	void __fastcall SetHonorDrivePolicy(int Value);
	System::WideChar __fastcall GetFirstFixedDrive();
	void __fastcall Load();
	int __fastcall GetDriveBitMask(System::UnicodeString Drive);
	bool __fastcall DoAnyValidPath(int DriveType, bool CanBeHidden, System::UnicodeString &Path);
	unsigned __fastcall ReadDriveMask(System::Win::Registry::TRegistry* Reg, System::UnicodeString ValueName);
	void __fastcall ScheduleDriveRefresh();
	void __fastcall CancelDriveRefresh();
	void __fastcall InternalWndProc(Winapi::Messages::TMessage &Msg);
	void __fastcall InvokeHandlers(TDriveNotification DriveNotification, System::UnicodeString Drive);
	void __fastcall ProcessThreadResults();
	void __fastcall ReadAsynchronous();
	
protected:
	__fastcall TDriveInfoInt();
	void __fastcall DriveRemoving(System::UnicodeString Drive)/* overload */;
	void __fastcall ResetDrive(System::UnicodeString Drive);
	void __fastcall DoReadDriveStatus(System::UnicodeString Drive, int Flags);
	void __fastcall ReadDriveBasicStatus(System::UnicodeString Drive);
	void __fastcall UpdateDriveNotifications(System::UnicodeString Drive);
	virtual TDriveInfoRec* __fastcall AddDrive(System::UnicodeString Drive) = 0 ;
	virtual TDriveInfoRec* __fastcall GetInternal(System::UnicodeString Drive) = 0 ;
	virtual void __fastcall DriveRemoving(Winapi::Windows::THandle DeviceHandle) = 0 /* overload */;
	virtual void __fastcall UpdateDrivesNotifications() = 0 ;
	
public:
	virtual TDriveInfoRec* __fastcall Get(System::UnicodeString Drive) = 0 ;
	__property PSpecialFolderRec SpecialFolder[TSpecialFolder Folder] = {read=GetFolder};
	void __fastcall NeedData();
	System::UnicodeString __fastcall AnyValidPath();
	System::UnicodeString __fastcall GetDriveKey(System::UnicodeString Path);
	System::UnicodeString __fastcall GetDriveRoot(System::UnicodeString Drive);
	bool __fastcall IsRealDrive(System::UnicodeString Drive);
	bool __fastcall IsFixedDrive(System::UnicodeString Drive);
	int __fastcall GetImageIndex(System::UnicodeString Drive);
	System::UnicodeString __fastcall GetSimpleName(System::UnicodeString Drive);
	System::UnicodeString __fastcall GetDisplayName(System::UnicodeString Drive);
	System::UnicodeString __fastcall GetPrettyName(System::UnicodeString Drive);
	void __fastcall ReadDriveStatus(System::UnicodeString Drive, int Flags);
	void __fastcall OverrideDrivePolicy(System::UnicodeString Drive);
	__property int HonorDrivePolicy = {read=FHonorDrivePolicy, write=SetHonorDrivePolicy, nodefault};
	__property System::WideChar FirstFixedDrive = {read=GetFirstFixedDrive, nodefault};
	__property bool UseABDrives = {read=FUseABDrives, write=FUseABDrives, nodefault};
	__fastcall virtual ~TDriveInfoInt();
	void __fastcall AddHandler(TDriveNotificationEvent Handler);
	void __fastcall RemoveHandler(TDriveNotificationEvent Handler);
	void __fastcall DriveRefresh();
	void __fastcall SubscribeDriveNotifications(System::UnicodeString Drive);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 dsValid = System::Int8(0x0);
static _DELPHI_CONST System::Int8 dsImageIndex = System::Int8(0x1);
static _DELPHI_CONST System::Int8 dsSize = System::Int8(0x2);
static _DELPHI_CONST System::Int8 dsDisplayName = System::Int8(0x4);
static _DELPHI_CONST System::Int8 dsSynchronous = System::Int8(0x5);
static _DELPHI_CONST System::Int8 dsAll = System::Int8(0x7);
static _DELPHI_CONST System::WideChar FirstDrive = (System::WideChar)(0x41);
static _DELPHI_CONST System::WideChar SystemDrive = (System::WideChar)(0x43);
static _DELPHI_CONST System::WideChar LastDrive = (System::WideChar)(0x5a);
static _DELPHI_CONST System::Int8 FirstSpecialFolder = System::Int8(0x0);
static _DELPHI_CONST System::Int8 LastSpecialFolder = System::Int8(0x1b);
static _DELPHI_CONST System::Word WM_USER_SHCHANGENOTIFY = System::Word(0x240d);
static _DELPHI_CONST System::Word WM_DRIVEINFO_PROCESS = System::Word(0x2412);
extern DELPHI_PACKAGE TDriveInfoInt* DriveInfo;
extern DELPHI_PACKAGE System::ResourceString _ErrorInvalidDrive;
#define Iedriveinfoint_ErrorInvalidDrive System::LoadResourceString(&Iedriveinfoint::_ErrorInvalidDrive)
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetShellFileName(Winapi::Shlobj::PItemIDList PIDL)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetNetWorkName(System::UnicodeString Drive);
extern DELPHI_PACKAGE bool __fastcall GetNetWorkConnected(System::UnicodeString Drive);
extern DELPHI_PACKAGE bool __fastcall IsRootPath(System::UnicodeString Path);
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall GetThumbnail(System::UnicodeString Path, const System::Types::TSize &Size);
extern DELPHI_PACKAGE void __fastcall DriveInfoInit(TDriveInfoInt* ADriveInfo);
}	/* namespace Iedriveinfoint */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_IEDRIVEINFOINT)
using namespace Iedriveinfoint;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IEDriveInfoIntHPP
