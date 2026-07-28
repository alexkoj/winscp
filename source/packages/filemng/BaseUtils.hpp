// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BaseUtils.pas' rev: 37.00 (Windows)

#ifndef BaseUtilsHPP
#define BaseUtilsHPP

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

//-- user supplied -----------------------------------------------------------

namespace Baseutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TDateTimePrecision : unsigned char { tpNone, tpDay, tpMinute, tpSecond, tpMillisecond };

enum DECLSPEC_DENUM TFormatBytesStyle : unsigned char { fbNone, fbKilobytes, fbShort };

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::ResourceString _SNoValidPath;
#define Baseutils_SNoValidPath System::LoadResourceString(&Baseutils::_SNoValidPath)
extern DELPHI_PACKAGE System::ResourceString _SByte;
#define Baseutils_SByte System::LoadResourceString(&Baseutils::_SByte)
extern DELPHI_PACKAGE System::ResourceString _SKiloByte;
#define Baseutils_SKiloByte System::LoadResourceString(&Baseutils::_SKiloByte)
extern DELPHI_PACKAGE System::ResourceString _SMegaByte;
#define Baseutils_SMegaByte System::LoadResourceString(&Baseutils::_SMegaByte)
extern DELPHI_PACKAGE System::ResourceString _SGigaByte;
#define Baseutils_SGigaByte System::LoadResourceString(&Baseutils::_SGigaByte)
extern DELPHI_PACKAGE bool __fastcall StrContains(System::UnicodeString Str1, System::UnicodeString Str2);
extern DELPHI_PACKAGE bool __fastcall FileOrDirExists(System::UnicodeString FileName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ExtractFileNameOnly(System::UnicodeString Name);
extern DELPHI_PACKAGE System::UnicodeString __fastcall FormatBytes(__int64 Bytes, TFormatBytesStyle Style = (TFormatBytesStyle)(0x2), bool UseUnitsForBytes = true);
extern DELPHI_PACKAGE System::UnicodeString __fastcall FormatPanelBytes(__int64 Bytes, TFormatBytesStyle Style);
extern DELPHI_PACKAGE void __fastcall FreePIDL(Winapi::Shlobj::PItemIDList &PIDL);
extern DELPHI_PACKAGE void __fastcall ReduceDateTimePrecision(System::TDateTime &DateTime, TDateTimePrecision Precision);
extern DELPHI_PACKAGE bool __fastcall SpecialFolderLocation(int Folder, System::UnicodeString &Path, Winapi::Shlobj::PItemIDList &PIDL)/* overload */;
extern DELPHI_PACKAGE bool __fastcall SpecialFolderLocation(int Folder, System::UnicodeString &Path)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall FormatLastOSError(System::UnicodeString Message);
}	/* namespace Baseutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_BASEUTILS)
using namespace Baseutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BaseUtilsHPP
