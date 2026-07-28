// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PIDL.pas' rev: 37.00 (Windows)

#ifndef PIDLHPP
#define PIDLHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.ShlObj.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.ActiveX.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pidl
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE unsigned CF_FILENAMEMAP;
extern DELPHI_PACKAGE unsigned CF_FILENAMEMAPW;
extern DELPHI_PACKAGE unsigned CF_SHELLIDLIST;
extern DELPHI_PACKAGE unsigned CF_PREFERREDDROPEFFECT;
extern DELPHI_PACKAGE int __fastcall PIDL_GetSize(Winapi::Shlobj::PItemIDList PIDL);
extern DELPHI_PACKAGE Winapi::Shlobj::PItemIDList __fastcall PIDL_Create(unsigned Size);
extern DELPHI_PACKAGE Winapi::Shlobj::PItemIDList __fastcall PIDL_Concatenate(Winapi::Shlobj::PItemIDList PIDL1, Winapi::Shlobj::PItemIDList PIDL2);
extern DELPHI_PACKAGE Winapi::Shlobj::PItemIDList __fastcall PIDL_Copy(Winapi::Shlobj::PItemIDList PIDLSource);
extern DELPHI_PACKAGE bool __fastcall PIDL_GetDisplayName(_di_IShellFolder piFolder, Winapi::Shlobj::PItemIDList PIDL, unsigned dwFlags, System::WideChar * pszName, unsigned cchMax);
extern DELPHI_PACKAGE void __fastcall PIDL_GetRelative(Winapi::Shlobj::PItemIDList &PIDLFQ, Winapi::Shlobj::PItemIDList &PPIDLRoot, Winapi::Shlobj::PItemIDList &PPIDLItem);
extern DELPHI_PACKAGE Winapi::Shlobj::PItemIDList __fastcall PIDL_GetFromPath(System::WideChar * pszFile);
extern DELPHI_PACKAGE bool __fastcall PIDL_GetFileFolder(Winapi::Shlobj::PItemIDList PIDL, _di_IShellFolder &piFolder);
extern DELPHI_PACKAGE Winapi::Shlobj::PItemIDList __fastcall PIDL_GetFromParentFolder(_di_IShellFolder pParentFolder, System::WideChar * pszFile);
extern DELPHI_PACKAGE void __fastcall PIDL_Free(Winapi::Shlobj::PItemIDList PIDL);
extern DELPHI_PACKAGE bool __fastcall PIDL_Equal(Winapi::Shlobj::PItemIDList PIDL1, Winapi::Shlobj::PItemIDList PIDL2);
}	/* namespace Pidl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PIDL)
using namespace Pidl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PIDLHPP
