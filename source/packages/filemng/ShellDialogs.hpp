// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ShellDialogs.pas' rev: 37.00 (Windows)

#ifndef ShellDialogsHPP
#define ShellDialogsHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Menus.hpp>
#include <PIDL.hpp>

//-- user supplied -----------------------------------------------------------

namespace Shelldialogs
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<Winapi::Shlobj::PItemIDList, 1> TPIDLArray;

typedef TPIDLArray *PPIDLArray;

//-- var, const, procedure ---------------------------------------------------
#define shcProperties L"properties"
#define shcCut L"cut"
#define shcCopy L"copy"
#define shcPaste L"paste"
#define shcDelete L"delete"
#define shcLink L"link"
#define shcrename L"rename"
#define shcDefault L""
extern DELPHI_PACKAGE Vcl::Menus::TPopupMenu* CustomContextMenu;
extern DELPHI_PACKAGE void __fastcall ShellDisplayContextMenu(Winapi::Windows::THandle Handle, const Winapi::Windows::TPoint &P, _di_IShellFolder ShellFolder, int PIDLCount, Winapi::Shlobj::PItemIDList &PIDL, bool AllowRename, System::UnicodeString &Verb, bool PerformPaste = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall ShellDisplayContextMenu(Winapi::Windows::THandle Handle, const Winapi::Windows::TPoint &P, System::UnicodeString FileName, bool AllowRename, System::UnicodeString &Verb, bool PerformPaste = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall ShellDisplayContextMenu(Winapi::Windows::THandle Handle, const Winapi::Windows::TPoint &P, System::UnicodeString Path, System::Classes::TStringList* Files, System::UnicodeString &Verb, bool PerformPaste = true)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ShellExecuteContextCommand(Winapi::Windows::THandle Handle, System::UnicodeString Command, _di_IShellFolder ShellFolder, int PIDLCount, Winapi::Shlobj::PItemIDList &PIDL)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ShellExecuteContextCommand(Winapi::Windows::THandle Handle, System::UnicodeString Command, System::UnicodeString FileName)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ShellExecuteContextCommand(Winapi::Windows::THandle Handle, System::UnicodeString Command, System::UnicodeString Path, System::Classes::TStringList* Files)/* overload */;
}	/* namespace Shelldialogs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SHELLDIALOGS)
using namespace Shelldialogs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ShellDialogsHPP
