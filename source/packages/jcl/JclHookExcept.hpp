// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclHookExcept.pas' rev: 37.00 (Windows)

#ifndef JclHookExceptHPP
#define JclHookExceptHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jclhookexcept
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef System::Sysutils::Exception* __fastcall (*TJclExceptFilterProc)(System::Sysutils::PExceptionRecord ExceptRecord);

typedef void __fastcall (*TJclExceptNotifyProc)(System::TObject* ExceptObj, void * ExceptAddr, bool OSException);

typedef void __fastcall (*TJclExceptNotifyProcEx)(System::TObject* ExceptObj, void * ExceptAddr, bool OSException, void * StackPointer);

typedef void __fastcall (__closure *TJclExceptNotifyMethod)(System::TObject* ExceptObj, void * ExceptAddr, bool OSException);

enum DECLSPEC_DENUM TJclExceptNotifyPriority : unsigned char { npNormal, npFirstChain };

typedef System::DynamicArray<unsigned> TJclModuleArray;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool __fastcall JclBelongsHookedCode(void * Address);
extern DELPHI_PACKAGE bool __fastcall JclAddExceptFilter(const TJclExceptFilterProc FilterProc, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0));
extern DELPHI_PACKAGE bool __fastcall JclAddExceptNotifier(const TJclExceptNotifyProc NotifyProc, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall JclAddExceptNotifier(const TJclExceptNotifyProcEx NotifyProc, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall JclAddExceptNotifier(const TJclExceptNotifyMethod NotifyMethod, TJclExceptNotifyPriority Priority = (TJclExceptNotifyPriority)(0x0))/* overload */;
extern DELPHI_PACKAGE bool __fastcall JclRemoveExceptFilter(const TJclExceptFilterProc FilterProc);
extern DELPHI_PACKAGE bool __fastcall JclRemoveExceptNotifier(const TJclExceptNotifyProc NotifyProc)/* overload */;
extern DELPHI_PACKAGE bool __fastcall JclRemoveExceptNotifier(const TJclExceptNotifyProcEx NotifyProc)/* overload */;
extern DELPHI_PACKAGE bool __fastcall JclRemoveExceptNotifier(const TJclExceptNotifyMethod NotifyMethod)/* overload */;
extern DELPHI_PACKAGE void __fastcall JclReplaceExceptObj(System::Sysutils::Exception* NewExceptObj);
extern DELPHI_PACKAGE bool __fastcall JclHookExceptions();
extern DELPHI_PACKAGE bool __fastcall JclUnhookExceptions();
extern DELPHI_PACKAGE bool __fastcall JclExceptionsHooked();
extern DELPHI_PACKAGE bool __fastcall JclHookExceptionsInModule(unsigned Module);
extern DELPHI_PACKAGE bool __fastcall JclUnhookExceptionsInModule(unsigned Module);
extern DELPHI_PACKAGE bool __fastcall JclInitializeLibrariesHookExcept();
extern DELPHI_PACKAGE bool __fastcall JclHookedExceptModulesList(/* out */ TJclModuleArray &ModulesList);
}	/* namespace Jclhookexcept */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLHOOKEXCEPT)
using namespace Jclhookexcept;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclHookExceptHPP
