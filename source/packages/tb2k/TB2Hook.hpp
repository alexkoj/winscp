// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TB2Hook.pas' rev: 37.00 (Windows)

#ifndef TB2HookHPP
#define TB2HookHPP

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

//-- user supplied -----------------------------------------------------------

namespace Tb2hook
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM THookProcCode : unsigned char { hpSendActivate, hpSendActivateApp, hpSendWindowPosChanged, hpPreDestroy, hpGetMessage };

typedef System::Set<THookProcCode, THookProcCode::hpSendActivate, THookProcCode::hpGetMessage> THookProcCodes;

typedef void __fastcall (*THookProc)(THookProcCode Code, HWND Wnd, unsigned WParam, int LParam);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall InstallHookProc(System::TObject* AUser, THookProc AProc, THookProcCodes ACodes);
extern DELPHI_PACKAGE void __fastcall UninstallHookProc(System::TObject* AUser, THookProc AProc);
}	/* namespace Tb2hook */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TB2HOOK)
using namespace Tb2hook;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TB2HookHPP
