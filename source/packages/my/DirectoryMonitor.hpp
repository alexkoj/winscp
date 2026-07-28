// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DirectoryMonitor.pas' rev: 37.00 (Windows)

#ifndef DirectoryMonitorHPP
#define DirectoryMonitorHPP

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
#include <CompThread.hpp>

//-- user supplied -----------------------------------------------------------

namespace Directorymonitor
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EDirectoryMonitorError;
class DELPHICLASS TDirectoryMonitor;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EDirectoryMonitorError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EDirectoryMonitorError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EDirectoryMonitorError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EDirectoryMonitorError(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EDirectoryMonitorError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EDirectoryMonitorError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EDirectoryMonitorError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EDirectoryMonitorError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EDirectoryMonitorError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDirectoryMonitorError(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDirectoryMonitorError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDirectoryMonitorError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDirectoryMonitorError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EDirectoryMonitorError() { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TFileChangedEvent)(System::TObject* Sender, const System::UnicodeString FileName);

typedef void __fastcall (__closure *TFileRenamedEvent)(System::TObject* Sender, const System::UnicodeString FromFileName, const System::UnicodeString ToFileName);

class PASCALIMPLEMENTATION TDirectoryMonitor : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Winapi::Windows::THandle FDirectoryHandle;
	System::StaticArray<System::Byte, 4097> FNotificationBuffer;
	Compthread::TCompThread* FWatchThread;
	unsigned FWatchFilters;
	Winapi::Windows::TOverlapped FOverlapped;
	Winapi::Windows::POverlapped FPOverlapped;
	unsigned FBytesWritten;
	Winapi::Windows::THandle FCompletionPort;
	System::UnicodeString FPath;
	bool FActive;
	TFileChangedEvent FOnCreated;
	TFileChangedEvent FOnDeleted;
	TFileChangedEvent FOnModified;
	TFileRenamedEvent FOnRenamed;
	bool FWatchSubTree;
	void __fastcall SetActive(bool AActive);
	void __fastcall SetPath(System::UnicodeString aPath);
	
protected:
	void __fastcall Start();
	void __fastcall Stop();
	void __fastcall DoCreated(System::TObject* Sender, System::UnicodeString FileName);
	void __fastcall DoDeleted(System::TObject* Sender, System::UnicodeString FileName);
	void __fastcall DoModified(System::TObject* Sender, System::UnicodeString FileName);
	void __fastcall DoRenamed(System::TObject* Sender, System::UnicodeString FromFileName, System::UnicodeString ToFileName);
	
public:
	__fastcall virtual TDirectoryMonitor(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDirectoryMonitor();
	
__published:
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property System::UnicodeString Path = {read=FPath, write=SetPath};
	__property TFileChangedEvent OnCreated = {read=FOnCreated, write=FOnCreated};
	__property TFileChangedEvent OnDeleted = {read=FOnDeleted, write=FOnDeleted};
	__property TFileChangedEvent OnModified = {read=FOnModified, write=FOnModified};
	__property TFileRenamedEvent OnRenamed = {read=FOnRenamed, write=FOnRenamed};
	__property bool WatchSubtree = {read=FWatchSubTree, write=FWatchSubTree, nodefault};
	__property unsigned WatchFilters = {read=FWatchFilters, write=FWatchFilters, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Directorymonitor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DIRECTORYMONITOR)
using namespace Directorymonitor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DirectoryMonitorHPP
