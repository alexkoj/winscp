// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TBXUtils.pas' rev: 37.00 (Windows)

#ifndef TBXUtilsHPP
#define TBXUtilsHPP

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
#include <Winapi.Messages.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ImgList.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tbxutils
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TShadow;
class DELPHICLASS THorzShadow;
class DELPHICLASS TVertShadow;
class DELPHICLASS TShadows;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM Tbxutils__1 : unsigned char { seTopLeft, seBottomRight };

typedef System::Set<Tbxutils__1, Tbxutils__1::seTopLeft, Tbxutils__1::seBottomRight> TShadowEdges;

enum DECLSPEC_DENUM TShadowStyle : unsigned char { ssFlat, ssLayered };

class PASCALIMPLEMENTATION TShadow : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
protected:
	System::Byte FOpacity;
	Vcl::Graphics::TBitmap* FBuffer;
	Winapi::Windows::TRect FClearRect;
	TShadowEdges FEdges;
	TShadowStyle FStyle;
	bool FSaveBits;
	void __fastcall GradR(const Winapi::Windows::TRect &R);
	void __fastcall GradB(const Winapi::Windows::TRect &R);
	void __fastcall GradBR(const Winapi::Windows::TRect &R);
	void __fastcall GradTR(const Winapi::Windows::TRect &R);
	void __fastcall GradBL(const Winapi::Windows::TRect &R);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall FillBuffer() = 0 ;
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall TShadow(const Winapi::Windows::TRect &Bounds, System::Byte Opacity, bool LoColor, TShadowEdges Edges);
	void __fastcall Clear(const Winapi::Windows::TRect &R);
	void __fastcall Render();
	HIDESBASE void __fastcall Show(HWND ParentHandle);
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TShadow() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TShadow(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION THorzShadow : public TShadow
{
	typedef TShadow inherited;
	
protected:
	virtual void __fastcall FillBuffer();
public:
	/* TShadow.Create */ inline __fastcall THorzShadow(const Winapi::Windows::TRect &Bounds, System::Byte Opacity, bool LoColor, TShadowEdges Edges) : TShadow(Bounds, Opacity, LoColor, Edges) { }
	
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~THorzShadow() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall THorzShadow(HWND ParentWindow) : TShadow(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TVertShadow : public TShadow
{
	typedef TShadow inherited;
	
protected:
	virtual void __fastcall FillBuffer();
public:
	/* TShadow.Create */ inline __fastcall TVertShadow(const Winapi::Windows::TRect &Bounds, System::Byte Opacity, bool LoColor, TShadowEdges Edges) : TShadow(Bounds, Opacity, LoColor, Edges) { }
	
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TVertShadow() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TVertShadow(HWND ParentWindow) : TShadow(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TShadows : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FSaveBits;
	void __fastcall SetSaveBits(bool Value);
	
protected:
	TShadow* V1;
	TShadow* H1;
	TShadow* V2;
	TShadow* H2;
	TShadow* V3;
	TShadow* H3;
	
public:
	__fastcall TShadows(const Winapi::Windows::TRect &R1, const Winapi::Windows::TRect &R2, int TheSize, System::Byte Opacity, bool LoColor);
	__fastcall virtual ~TShadows();
	void __fastcall Show(HWND ParentHandle);
	__property bool SaveBits = {read=FSaveBits, write=SetSaveBits, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* StockBitmap1;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* StockBitmap2;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* StockMonoBitmap;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* StockCompatibleBitmap;
extern DELPHI_PACKAGE Vcl::Graphics::TFont* SmCaptionFont;
static _DELPHI_CONST int ROP_DSPDxax = int(0xe20746);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall MixColors(System::Uitypes::TColor C1, System::Uitypes::TColor C2, int W1);
extern DELPHI_PACKAGE int __fastcall ColorIntensity(System::Uitypes::TColor C);
extern DELPHI_PACKAGE bool __fastcall IsDarkColor(System::Uitypes::TColor C, int Threshold = 0x64);
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall Blend(System::Uitypes::TColor C1, System::Uitypes::TColor C2, int W1);
extern DELPHI_PACKAGE void __fastcall SetContrast(System::Uitypes::TColor &Color, System::Uitypes::TColor BkgndColor, int Threshold);
extern DELPHI_PACKAGE int __fastcall TBXScaleByTextHeightRunTime(Vcl::Graphics::TCanvas* Canvas, int Dimension);
extern DELPHI_PACKAGE bool __fastcall FillRectEx(HDC DC, const Winapi::Windows::TRect &Rect, System::Uitypes::TColor Color);
extern DELPHI_PACKAGE bool __fastcall FrameRectEx(HDC DC, Winapi::Windows::TRect &Rect, System::Uitypes::TColor Color, bool Adjust);
extern DELPHI_PACKAGE void __fastcall DrawLineEx(HDC DC, int X1, int Y1, int X2, int Y2, System::Uitypes::TColor Color);
extern DELPHI_PACKAGE bool __fastcall PolyLineEx(HDC DC, const System::Types::TPoint *Points, const System::NativeInt Points_High, System::Uitypes::TColor Color)/* overload */;
extern DELPHI_PACKAGE void __fastcall PolygonEx(HDC DC, const System::Types::TPoint *Points, const System::NativeInt Points_High, System::Uitypes::TColor OutlineColor, System::Uitypes::TColor FillColor);
extern DELPHI_PACKAGE void __fastcall RoundRectEx(HDC DC, int Left, int Top, int Right, int Bottom, System::Uitypes::TColor EllipseWidth, System::Uitypes::TColor EllipseHeight, System::Uitypes::TColor OutlineColor, System::Uitypes::TColor FillColor);
extern DELPHI_PACKAGE void __fastcall EllipseEx(HDC DC, int Left, int Top, int Right, int Bottom, System::Uitypes::TColor OutlineColor, System::Uitypes::TColor FillColor);
extern DELPHI_PACKAGE void __fastcall DrawTBXIcon(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &R, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex);
extern DELPHI_PACKAGE void __fastcall DrawTBXIconShadow(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &R, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex, int Density);
extern DELPHI_PACKAGE void __fastcall DrawTBXIconFlatShadow(Vcl::Graphics::TCanvas* Canvas, const Winapi::Windows::TRect &R, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex, System::Uitypes::TColor ShadowColor);
extern DELPHI_PACKAGE void __fastcall DrawGlyph(HDC DC, int X, int Y, Vcl::Imglist::TCustomImageList* ImageList, int ImageIndex, System::Uitypes::TColor Color)/* overload */;
extern DELPHI_PACKAGE void __fastcall DrawGlyph(HDC DC, const Winapi::Windows::TRect &R, int Width, int Height, const void *Bits, System::Uitypes::TColor Color)/* overload */;
extern DELPHI_PACKAGE void __fastcall RecreateStock();
}	/* namespace Tbxutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TBXUTILS)
using namespace Tbxutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TBXUtilsHPP
