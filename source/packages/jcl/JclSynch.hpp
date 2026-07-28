// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclSynch.pas' rev: 37.00 (Windows)

#ifndef JclSynchHPP
#define JclSynchHPP

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
#include <JclWin32.hpp>
#include <JclBase.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jclsynch
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TJclDispatcherObject;
class DELPHICLASS TJclCriticalSection;
class DELPHICLASS TJclCriticalSectionEx;
class DELPHICLASS TJclEvent;
class DELPHICLASS TJclWaitableTimer;
class DELPHICLASS TJclSemaphore;
class DELPHICLASS TJclMutex;
struct TOptexSharedInfo;
struct TMrewThreadInfo;
class DELPHICLASS TJclMultiReadExclusiveWrite;
struct TMetSectSharedInfo;
struct TMeteredSection;
class DELPHICLASS TJclMeteredSection;
struct TEventInfo;
struct TMutexInfo;
struct TSemaphoreCounts;
struct TTimerInfo;
class DELPHICLASS EJclWin32HandleObjectError;
class DELPHICLASS EJclDispatcherObjectError;
class DELPHICLASS EJclCriticalSectionError;
class DELPHICLASS EJclEventError;
class DELPHICLASS EJclWaitableTimerError;
class DELPHICLASS EJclSemaphoreError;
class DELPHICLASS EJclMutexError;
class DELPHICLASS EJclMeteredSectionError;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TJclWaitResult : unsigned char { wrAbandoned, wrError, wrIoCompletion, wrSignaled, wrTimeout };

typedef Winapi::Windows::THandle TJclWaitHandle;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDispatcherObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FExisted;
	TJclWaitHandle FHandle;
	System::UnicodeString FName;
	
public:
	__fastcall TJclDispatcherObject(TJclWaitHandle AHandle);
	__fastcall virtual ~TJclDispatcherObject();
	TJclWaitResult __fastcall SignalAndWait(TJclDispatcherObject* const Obj, unsigned TimeOut, bool Alertable);
	TJclWaitResult __fastcall WaitAlertable(const unsigned TimeOut);
	TJclWaitResult __fastcall WaitFor(const unsigned TimeOut);
	TJclWaitResult __fastcall WaitForever();
	__property bool Existed = {read=FExisted, nodefault};
	__property TJclWaitHandle Handle = {read=FHandle, nodefault};
	__property System::UnicodeString Name = {read=FName};
public:
	/* TObject.Create */ inline __fastcall TJclDispatcherObject() : System::TObject() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclCriticalSection : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Winapi::Windows::TRTLCriticalSection FCriticalSection;
	
public:
	__fastcall virtual TJclCriticalSection();
	__fastcall virtual ~TJclCriticalSection();
	__classmethod void __fastcall CreateAndEnter(TJclCriticalSection* &CS);
	void __fastcall Enter();
	void __fastcall Leave();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclCriticalSectionEx : public TJclCriticalSection
{
	typedef TJclCriticalSection inherited;
	
private:
	unsigned FSpinCount;
	
public:
	__fastcall virtual TJclCriticalSectionEx();
	__fastcall virtual TJclCriticalSectionEx(unsigned SpinCount, bool NoFailEnter);
	bool __fastcall TryEnter();
public:
	/* TJclCriticalSection.Destroy */ inline __fastcall virtual ~TJclCriticalSectionEx() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclEvent : public TJclDispatcherObject
{
	typedef TJclDispatcherObject inherited;
	
public:
	__fastcall TJclEvent(Winapi::Windows::PSecurityAttributes SecAttr, bool Manual, bool Signaled, const System::UnicodeString Name);
	__fastcall TJclEvent(unsigned Access, bool Inheritable, const System::UnicodeString Name);
	bool __fastcall Pulse();
	bool __fastcall ResetEvent();
	bool __fastcall SetEvent();
public:
	/* TJclDispatcherObject.Attach */ inline __fastcall TJclEvent(TJclWaitHandle AHandle) : TJclDispatcherObject(AHandle) { }
	/* TJclDispatcherObject.Destroy */ inline __fastcall virtual ~TJclEvent() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclWaitableTimer : public TJclDispatcherObject
{
	typedef TJclDispatcherObject inherited;
	
private:
	bool FResume;
	
public:
	__fastcall TJclWaitableTimer(Winapi::Windows::PSecurityAttributes SecAttr, bool Manual, const System::UnicodeString Name);
	__fastcall TJclWaitableTimer(unsigned Access, bool Inheritable, const System::UnicodeString Name);
	bool __fastcall Cancel();
	bool __fastcall SetTimer(const __int64 DueTime, System::LongInt Period, bool Resume);
	bool __fastcall SetTimerApc(const __int64 DueTime, System::LongInt Period, bool Resume, Winapi::Windows::TFNTimerAPCRoutine Apc, void * Arg);
public:
	/* TJclDispatcherObject.Attach */ inline __fastcall TJclWaitableTimer(TJclWaitHandle AHandle) : TJclDispatcherObject(AHandle) { }
	/* TJclDispatcherObject.Destroy */ inline __fastcall virtual ~TJclWaitableTimer() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclSemaphore : public TJclDispatcherObject
{
	typedef TJclDispatcherObject inherited;
	
public:
	__fastcall TJclSemaphore(Winapi::Windows::PSecurityAttributes SecAttr, System::LongInt Initial, System::LongInt Maximum, const System::UnicodeString Name);
	__fastcall TJclSemaphore(unsigned Access, bool Inheritable, const System::UnicodeString Name);
	bool __fastcall Release(System::LongInt ReleaseCount);
	bool __fastcall ReleasePrev(System::LongInt ReleaseCount, System::LongInt &PrevCount);
public:
	/* TJclDispatcherObject.Attach */ inline __fastcall TJclSemaphore(TJclWaitHandle AHandle) : TJclDispatcherObject(AHandle) { }
	/* TJclDispatcherObject.Destroy */ inline __fastcall virtual ~TJclSemaphore() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclMutex : public TJclDispatcherObject
{
	typedef TJclDispatcherObject inherited;
	
public:
	__fastcall TJclMutex(Winapi::Windows::PSecurityAttributes SecAttr, bool InitialOwner, const System::UnicodeString Name);
	__fastcall TJclMutex(unsigned Access, bool Inheritable, const System::UnicodeString Name);
	bool __fastcall Acquire(const unsigned TimeOut = (unsigned)(0xffffffff));
	bool __fastcall Release();
public:
	/* TJclDispatcherObject.Attach */ inline __fastcall TJclMutex(TJclWaitHandle AHandle) : TJclDispatcherObject(AHandle) { }
	/* TJclDispatcherObject.Destroy */ inline __fastcall virtual ~TJclMutex() { }
	
};

#pragma pack(pop)

typedef TOptexSharedInfo *POptexSharedInfo;

struct DECLSPEC_DRECORD TOptexSharedInfo
{
public:
	int SpinCount;
	int LockCount;
	System::LongWord ThreadId;
	int RecursionCount;
};


enum DECLSPEC_DENUM TMrewPreferred : unsigned char { mpReaders, mpWriters, mpEqual };

struct DECLSPEC_DRECORD TMrewThreadInfo
{
public:
	System::LongWord ThreadId;
	int RecursionCount;
	bool Reader;
};


typedef System::DynamicArray<TMrewThreadInfo> TMrewThreadInfoArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclMultiReadExclusiveWrite : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TJclCriticalSection* FLock;
	TMrewPreferred FPreferred;
	TJclSemaphore* FSemReaders;
	TJclSemaphore* FSemWriters;
	int FState;
	TMrewThreadInfoArray FThreads;
	int FWaitingReaders;
	int FWaitingWriters;
	void __fastcall AddToThreadList(System::LongWord ThreadId, bool Reader);
	void __fastcall RemoveFromThreadList(int Index);
	int __fastcall FindThread(System::LongWord ThreadId);
	void __fastcall ReleaseWaiters(bool WasReading);
	
protected:
	void __fastcall Release();
	
public:
	__fastcall TJclMultiReadExclusiveWrite(TMrewPreferred Preferred);
	__fastcall virtual ~TJclMultiReadExclusiveWrite();
	void __fastcall BeginRead();
	void __fastcall BeginWrite();
	void __fastcall EndRead();
	void __fastcall EndWrite();
};

#pragma pack(pop)

typedef TMetSectSharedInfo *PMetSectSharedInfo;

struct DECLSPEC_DRECORD TMetSectSharedInfo
{
public:
	System::LongBool Initialized;
	System::LongInt SpinLock;
	System::LongInt ThreadsWaiting;
	System::LongInt AvailableCount;
	System::LongInt MaximumCount;
};


typedef TMeteredSection *PMeteredSection;

struct DECLSPEC_DRECORD TMeteredSection
{
public:
	Winapi::Windows::THandle Event;
	Winapi::Windows::THandle FileMap;
	PMetSectSharedInfo SharedInfo;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclMeteredSection : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	PMeteredSection FMetSect;
	void __fastcall CloseMeteredSection();
	bool __fastcall InitMeteredSection(System::LongInt InitialCount, System::LongInt MaxCount, const System::UnicodeString Name, bool OpenOnly);
	bool __fastcall CreateMetSectEvent(const System::UnicodeString Name, bool OpenOnly);
	bool __fastcall CreateMetSectFileView(System::LongInt InitialCount, System::LongInt MaxCount, const System::UnicodeString Name, bool OpenOnly);
	
protected:
	void __fastcall AcquireLock();
	void __fastcall ReleaseLock();
	
public:
	__fastcall TJclMeteredSection(System::LongInt InitialCount, System::LongInt MaxCount, const System::UnicodeString Name);
	__fastcall TJclMeteredSection(const System::UnicodeString Name);
	__fastcall virtual ~TJclMeteredSection();
	TJclWaitResult __fastcall Enter(System::LongWord TimeOut);
	bool __fastcall Leave(System::LongInt ReleaseCount)/* overload */;
	bool __fastcall Leave(System::LongInt ReleaseCount, /* out */ System::LongInt &PrevCount)/* overload */;
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TEventInfo
{
public:
	System::LongInt EventType;
	System::LongBool Signaled;
};


struct DECLSPEC_DRECORD TMutexInfo
{
public:
	System::LongInt SignalState;
	System::ByteBool Owned;
	System::ByteBool Abandoned;
};


struct DECLSPEC_DRECORD TSemaphoreCounts
{
public:
	System::LongInt CurrentCount;
	System::LongInt MaximumCount;
};


struct DECLSPEC_DRECORD TTimerInfo
{
public:
	Jclbase::TLargeInteger Remaining;
	System::ByteBool Signaled;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclWin32HandleObjectError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclWin32HandleObjectError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclWin32HandleObjectError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclWin32HandleObjectError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclWin32HandleObjectError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclWin32HandleObjectError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclWin32HandleObjectError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclWin32HandleObjectError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclWin32HandleObjectError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclWin32HandleObjectError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclWin32HandleObjectError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclWin32HandleObjectError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclWin32HandleObjectError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclWin32HandleObjectError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclWin32HandleObjectError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclDispatcherObjectError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclDispatcherObjectError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclDispatcherObjectError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclDispatcherObjectError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclDispatcherObjectError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclDispatcherObjectError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclDispatcherObjectError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclDispatcherObjectError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclDispatcherObjectError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclDispatcherObjectError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclDispatcherObjectError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclDispatcherObjectError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclDispatcherObjectError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclDispatcherObjectError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclDispatcherObjectError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclCriticalSectionError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclCriticalSectionError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclCriticalSectionError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclCriticalSectionError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclCriticalSectionError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclCriticalSectionError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclCriticalSectionError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclCriticalSectionError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclCriticalSectionError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclCriticalSectionError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclCriticalSectionError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclCriticalSectionError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCriticalSectionError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclCriticalSectionError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclCriticalSectionError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclEventError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclEventError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclEventError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclEventError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclEventError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclEventError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclEventError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclEventError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclEventError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclEventError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclEventError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclEventError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclEventError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclEventError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclEventError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclWaitableTimerError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclWaitableTimerError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclWaitableTimerError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclWaitableTimerError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclWaitableTimerError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclWaitableTimerError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclWaitableTimerError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclWaitableTimerError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclWaitableTimerError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclWaitableTimerError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclWaitableTimerError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclWaitableTimerError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclWaitableTimerError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclWaitableTimerError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclWaitableTimerError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclSemaphoreError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclSemaphoreError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclSemaphoreError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclSemaphoreError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclSemaphoreError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclSemaphoreError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclSemaphoreError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclSemaphoreError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclSemaphoreError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclSemaphoreError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclSemaphoreError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclSemaphoreError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclSemaphoreError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclSemaphoreError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclSemaphoreError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclMutexError : public Jclwin32::EJclWin32Error
{
	typedef Jclwin32::EJclWin32Error inherited;
	
public:
	/* EJclWin32Error.Create */ inline __fastcall EJclMutexError(const System::UnicodeString Msg) : Jclwin32::EJclWin32Error(Msg) { }
	/* EJclWin32Error.CreateFmt */ inline __fastcall EJclMutexError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclwin32::EJclWin32Error(Msg, Args, Args_High) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclMutexError(int Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* EJclWin32Error.CreateRes */ inline __fastcall EJclMutexError(System::PResStringRec ResStringRec)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec) { }
	
public:
	/* Exception.CreateRes */ inline __fastcall EJclMutexError(System::NativeUInt Ident)/* overload */ : Jclwin32::EJclWin32Error(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclMutexError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclMutexError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclMutexError(const System::UnicodeString Msg, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclMutexError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclwin32::EJclWin32Error(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclMutexError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclMutexError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMutexError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMutexError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclwin32::EJclWin32Error(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclMutexError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclMeteredSectionError : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EJclMeteredSectionError(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EJclMeteredSectionError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EJclMeteredSectionError(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EJclMeteredSectionError(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclMeteredSectionError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclMeteredSectionError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclMeteredSectionError(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclMeteredSectionError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclMeteredSectionError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclMeteredSectionError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMeteredSectionError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclMeteredSectionError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclMeteredSectionError() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int __fastcall LockedAdd(int &Target, int Value)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedCompareExchange(int &Target, int Exch, int Comp)/* overload */;
extern DELPHI_PACKAGE void * __fastcall LockedCompareExchange(void * &Target, void * Exch, void * Comp)/* overload */;
extern DELPHI_PACKAGE System::TObject* __fastcall LockedCompareExchange(System::TObject* &Target, System::TObject* Exch, System::TObject* Comp)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedDec(int &Target)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedExchange(int &Target, int Value)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedExchangeAdd(int &Target, int Value)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedExchangeDec(int &Target)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedExchangeInc(int &Target)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedExchangeSub(int &Target, int Value)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedInc(int &Target)/* overload */;
extern DELPHI_PACKAGE int __fastcall LockedSub(int &Target, int Value)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall WaitForMultipleObjects(TJclDispatcherObject* const *Objects, const System::NativeInt Objects_High, bool WaitAll, unsigned TimeOut);
extern DELPHI_PACKAGE unsigned __fastcall WaitAlertableForMultipleObjects(TJclDispatcherObject* const *Objects, const System::NativeInt Objects_High, bool WaitAll, unsigned TimeOut);
extern DELPHI_PACKAGE bool __fastcall QueryCriticalSection(TJclCriticalSection* CS, Winapi::Windows::TRTLCriticalSection &Info);
extern DELPHI_PACKAGE bool __fastcall QueryEvent(Winapi::Windows::THandle Handle, TEventInfo &Info);
extern DELPHI_PACKAGE bool __fastcall QueryMutex(Winapi::Windows::THandle Handle, TMutexInfo &Info);
extern DELPHI_PACKAGE bool __fastcall QuerySemaphore(Winapi::Windows::THandle Handle, TSemaphoreCounts &Info);
extern DELPHI_PACKAGE bool __fastcall QueryTimer(Winapi::Windows::THandle Handle, TTimerInfo &Info);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ValidateMutexName(const System::UnicodeString aName);
}	/* namespace Jclsynch */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLSYNCH)
using namespace Jclsynch;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclSynchHPP
