// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FileChanges.pas' rev: 37.00 (Windows)

#ifndef FileChangesHPP
#define FileChangesHPP

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
#include <CompThread.hpp>

//-- user supplied -----------------------------------------------------------

namespace Filechanges
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TFileDeleteThread;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TFileDeleteEvent)(System::TObject* Sender, System::Classes::TStringList* Files);

class PASCALIMPLEMENTATION TFileDeleteThread : public Compthread::TCompThread
{
	typedef Compthread::TCompThread inherited;
	
private:
	TFileDeleteEvent fOnSignalDelete;
	System::Classes::TStringList* fFiles;
	System::Classes::TStringList* fDelFiles;
	_FILETIME fEndTime;
	
protected:
	virtual void __fastcall Execute();
	virtual void __fastcall DoTerminate();
	void __fastcall DoOnSignalDelete();
	
public:
	__fastcall TFileDeleteThread(System::Classes::TStringList* Files, unsigned TimeOut, TFileDeleteEvent SignalProc);
	__property Terminated;
	
__published:
	__property TFileDeleteEvent OnSignalDelete = {read=fOnSignalDelete, write=fOnSignalDelete};
public:
	/* TCompThread.Destroy */ inline __fastcall virtual ~TFileDeleteThread() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Filechanges */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FILECHANGES)
using namespace Filechanges;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FileChangesHPP
