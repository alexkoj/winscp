// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PngButtonFunctions.pas' rev: 37.00 (Windows)

#ifndef PngButtonFunctionsHPP
#define PngButtonFunctionsHPP

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
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pngbuttonfunctions
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall CalcButtonLayout(Vcl::Graphics::TCanvas* Canvas, Vcl::Imaging::Pngimage::TPngImage* PngImage, const Winapi::Windows::TRect &Client, bool Pressed, bool Down, const System::UnicodeString Caption, Vcl::Buttons::TButtonLayout Layout, int Margin, int Spacing, Winapi::Windows::TPoint &GlyphPos, Winapi::Windows::TPoint &TextPos, System::LongInt BiDiFlags);
}	/* namespace Pngbuttonfunctions */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PNGBUTTONFUNCTIONS)
using namespace Pngbuttonfunctions;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PngButtonFunctionsHPP
