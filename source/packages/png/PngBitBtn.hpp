// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PngBitBtn.pas' rev: 37.00 (Windows)

#ifndef PngBitBtnHPP
#define PngBitBtnHPP

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
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <PngFunctions.hpp>
#include <Vcl.StdCtrls.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pngbitbtn
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TPngBitBtn;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TPngBitBtn : public Vcl::Buttons::TBitBtn
{
	typedef Vcl::Buttons::TBitBtn inherited;
	
private:
	Vcl::Imaging::Pngimage::TPngImage* FPngImage;
	Pngfunctions::TPngOptions FPngOptions;
	Vcl::Graphics::TCanvas* FCanvas;
	Vcl::Buttons::TBitBtnKind FLastKind;
	bool FImageFromAction;
	bool FMouseInControl;
	bool IsFocused;
	bool __fastcall PngImageStored();
	void __fastcall SetPngImage(Vcl::Imaging::Pngimage::TPngImage* const Value);
	void __fastcall SetPngOptions(const Pngfunctions::TPngOptions Value);
	HIDESBASE MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall SetButtonStyle(bool ADefault);
	
public:
	__fastcall virtual TPngBitBtn(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TPngBitBtn();
	
__published:
	__property Vcl::Imaging::Pngimage::TPngImage* PngImage = {read=FPngImage, write=SetPngImage, stored=PngImageStored};
	__property Pngfunctions::TPngOptions PngOptions = {read=FPngOptions, write=SetPngOptions, default=1};
	__property Glyph = {stored=false};
	__property NumGlyphs = {stored=false, default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TPngBitBtn(HWND ParentWindow) : Vcl::Buttons::TBitBtn(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Pngbitbtn */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PNGBITBTN)
using namespace Pngbitbtn;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PngBitBtnHPP
