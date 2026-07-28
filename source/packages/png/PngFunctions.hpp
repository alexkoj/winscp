// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PngFunctions.pas' rev: 37.00 (Windows)

#ifndef PngFunctionsHPP
#define PngFunctionsHPP

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
#include <Vcl.Graphics.hpp>
#include <Vcl.ImgList.hpp>
#include <System.Contnrs.hpp>
#include <Vcl.Imaging.pngimage.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pngfunctions
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TPngOption : unsigned char { pngBlendOnDisabled, pngGrayscaleOnDisabled };

typedef System::Set<TPngOption, TPngOption::pngBlendOnDisabled, TPngOption::pngGrayscaleOnDisabled> TPngOptions;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall MakeImageBlended(Vcl::Imaging::Pngimage::TPngImage* Image, System::Byte Amount = (System::Byte)(0x7f));
extern DELPHI_PACKAGE void __fastcall MakeImageGrayscale(Vcl::Imaging::Pngimage::TPngImage* Image, System::Byte Amount = (System::Byte)(0xff));
extern DELPHI_PACKAGE void __fastcall DrawPNG(Vcl::Imaging::Pngimage::TPngImage* Png, Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &ARect, const TPngOptions Options);
extern DELPHI_PACKAGE void __fastcall ConvertToPNG(Vcl::Graphics::TGraphic* Source, Vcl::Imaging::Pngimage::TPngImage* Dest);
extern DELPHI_PACKAGE void __fastcall CreatePNG(Vcl::Graphics::TBitmap* Color, Vcl::Graphics::TBitmap* Mask, Vcl::Imaging::Pngimage::TPngImage* Dest, bool InverseMask = false);
extern DELPHI_PACKAGE void __fastcall CreatePNGMasked(Vcl::Graphics::TBitmap* Bitmap, System::Uitypes::TColor Mask, Vcl::Imaging::Pngimage::TPngImage* Dest);
extern DELPHI_PACKAGE void __fastcall SlicePNG(Vcl::Imaging::Pngimage::TPngImage* JoinedPNG, int Columns, int Rows, /* out */ System::Contnrs::TObjectList* &SlicedPNGs);
extern DELPHI_PACKAGE void __fastcall MakeDisabledImage(Vcl::Imaging::Pngimage::TPngImage* Image, const TPngOptions Options);
}	/* namespace Pngfunctions */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PNGFUNCTIONS)
using namespace Pngfunctions;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PngFunctionsHPP
