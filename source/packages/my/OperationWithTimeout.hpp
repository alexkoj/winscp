// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OperationWithTimeout.pas' rev: 37.00 (Windows)

#ifndef OperationWithTimeoutHPP
#define OperationWithTimeoutHPP

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
#include <Winapi.ShlObj.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Winapi.ActiveX.hpp>

//-- user supplied -----------------------------------------------------------

namespace Operationwithtimeout
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool TimeoutShellOperations;
extern DELPHI_PACKAGE unsigned __fastcall SHGetFileInfoWithTimeout(System::WideChar * pszPath, unsigned dwFileAttributes, Winapi::Shellapi::TSHFileInfoW &psfi, unsigned cbFileInfo, unsigned uFlags, int Timeout);
extern DELPHI_PACKAGE HRESULT __fastcall ShellFolderParseDisplayNameWithTimeout(_di_IShellFolder ShellFolder, HWND hwndOwner, void * pbcReserved, Winapi::Activex::POleStr lpszDisplayName, /* out */ unsigned &pchEaten, /* out */ Winapi::Shlobj::PItemIDList &ppidl, unsigned &dwAttributes, int Timeout);
extern DELPHI_PACKAGE HRESULT __fastcall DestinationListBeginList(_di_ICustomDestinationList DestinationList, unsigned &pcMaxSlots, const Winapi::Activex::TIID &riid, /* out */ void * &ppv, int Timeout);
}	/* namespace Operationwithtimeout */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_OPERATIONWITHTIMEOUT)
using namespace Operationwithtimeout;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OperationWithTimeoutHPP
