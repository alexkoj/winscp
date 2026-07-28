// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PasTools.pas' rev: 37.00 (Windows)

#ifndef PasToolsHPP
#define PasToolsHPP

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
#include <System.Types.hpp>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Graphics.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Pastools
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomControlScrollOnDragOver;
class DELPHICLASS TTreeViewScrollOnDragOver;
class DELPHICLASS TListViewScrollOnDragOver;
class DELPHICLASS TListBoxScrollOnDragOver;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TImageListSize : unsigned char { ilsSmall, ilsLarge };

typedef System::UnicodeString __fastcall (*TApiPathEvent)(System::UnicodeString Path);

typedef void __fastcall (*TAppLogEvent)(System::UnicodeString S);

typedef void __fastcall (__closure *TControlScrollBeforeUpdate)(System::TObject* ObjectToValidate);

class PASCALIMPLEMENTATION TCustomControlScrollOnDragOver : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TControlScrollBeforeUpdate FOnBeforeUpdate;
	Vcl::Extctrls::TTimer* FDragOverTimer;
	Vcl::Controls::TControl* FControl;
	_FILETIME FDragOverTime;
	_FILETIME FLastVScrollTime;
	int FVScrollCount;
	void __fastcall DragOverTimer(System::TObject* Sender);
	void __fastcall BeforeUpdate(System::TObject* ObjectToValidate);
	void __fastcall AfterUpdate();
	
public:
	__fastcall TCustomControlScrollOnDragOver(Vcl::Controls::TControl* Control, bool ScheduleDragOver);
	__fastcall virtual ~TCustomControlScrollOnDragOver();
	virtual void __fastcall StartDrag();
	virtual void __fastcall EndDrag();
	virtual void __fastcall DragOver(const System::Types::TPoint &Point) = 0 ;
	__property TControlScrollBeforeUpdate OnBeforeUpdate = {read=FOnBeforeUpdate, write=FOnBeforeUpdate};
};


class PASCALIMPLEMENTATION TTreeViewScrollOnDragOver : public TCustomControlScrollOnDragOver
{
	typedef TCustomControlScrollOnDragOver inherited;
	
private:
	Vcl::Comctrls::TTreeNode* FLastDragNode;
	_FILETIME FLastHScrollTime;
	
public:
	virtual void __fastcall StartDrag();
	virtual void __fastcall DragOver(const System::Types::TPoint &Point);
public:
	/* TCustomControlScrollOnDragOver.Create */ inline __fastcall TTreeViewScrollOnDragOver(Vcl::Controls::TControl* Control, bool ScheduleDragOver) : TCustomControlScrollOnDragOver(Control, ScheduleDragOver) { }
	/* TCustomControlScrollOnDragOver.Destroy */ inline __fastcall virtual ~TTreeViewScrollOnDragOver() { }
	
};


class PASCALIMPLEMENTATION TListViewScrollOnDragOver : public TCustomControlScrollOnDragOver
{
	typedef TCustomControlScrollOnDragOver inherited;
	
public:
	virtual void __fastcall DragOver(const System::Types::TPoint &Point);
public:
	/* TCustomControlScrollOnDragOver.Create */ inline __fastcall TListViewScrollOnDragOver(Vcl::Controls::TControl* Control, bool ScheduleDragOver) : TCustomControlScrollOnDragOver(Control, ScheduleDragOver) { }
	/* TCustomControlScrollOnDragOver.Destroy */ inline __fastcall virtual ~TListViewScrollOnDragOver() { }
	
};


class PASCALIMPLEMENTATION TListBoxScrollOnDragOver : public TCustomControlScrollOnDragOver
{
	typedef TCustomControlScrollOnDragOver inherited;
	
public:
	virtual void __fastcall DragOver(const System::Types::TPoint &Point);
public:
	/* TCustomControlScrollOnDragOver.Create */ inline __fastcall TListBoxScrollOnDragOver(Vcl::Controls::TControl* Control, bool ScheduleDragOver) : TCustomControlScrollOnDragOver(Control, ScheduleDragOver) { }
	/* TCustomControlScrollOnDragOver.Destroy */ inline __fastcall virtual ~TListBoxScrollOnDragOver() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word CM_DPICHANGED = System::Word(0x240a);
static _DELPHI_CONST System::Int8 FIND_FIRST_EX_LARGE_FETCH_PAS = System::Int8(0x2);
extern DELPHI_PACKAGE TApiPathEvent OnApiPath;
extern DELPHI_PACKAGE TAppLogEvent OnAppLog;
extern DELPHI_PACKAGE System::Classes::TComponent* __fastcall Construct(System::Classes::TComponentClass ComponentClass, System::Classes::TComponent* Owner);
extern DELPHI_PACKAGE void __fastcall FilterToFileTypes(System::UnicodeString Filter, Vcl::Dialogs::TFileTypeItems* FileTypes);
extern DELPHI_PACKAGE bool __fastcall HasSystemParametersInfoForPixelsPerInch();
extern DELPHI_PACKAGE System::LongBool __fastcall SystemParametersInfoForPixelsPerInch(unsigned uiAction, unsigned uiParam, void * pvParam, unsigned fWinIni, unsigned dpi);
extern DELPHI_PACKAGE int __fastcall GetMonitorPixelsPerInch(Vcl::Forms::TMonitor* Monitor);
extern DELPHI_PACKAGE Vcl::Forms::TMonitor* __fastcall GetMonitorFromControl(Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE int __fastcall GetControlPixelsPerInch(Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE int __fastcall GetComponentPixelsPerInch(System::Classes::TComponent* Component);
extern DELPHI_PACKAGE int __fastcall LoadDimension(int Dimension, int PixelsPerInch, Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE int __fastcall StrToDimensionDef(System::UnicodeString Str, int PixelsPerInch, Vcl::Controls::TControl* Control, int Default);
extern DELPHI_PACKAGE int __fastcall SaveDimension(int Dimension);
extern DELPHI_PACKAGE int __fastcall DimensionToDefaultPixelsPerInch(int Dimension);
extern DELPHI_PACKAGE int __fastcall ScaleByPixelsPerInch(int Dimension, Vcl::Forms::TMonitor* Monitor)/* overload */;
extern DELPHI_PACKAGE int __fastcall ScaleByPixelsPerInch(int Dimension, Vcl::Controls::TControl* Control)/* overload */;
extern DELPHI_PACKAGE int __fastcall ScaleByPixelsPerInchFromSystem(int Dimension, Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE int __fastcall ScaleByCurrentPPI(int Dimension, Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE int __fastcall LoadPixelsPerInch(System::UnicodeString S, Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE System::UnicodeString __fastcall SavePixelsPerInch(Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE System::UnicodeString __fastcall SaveDefaultPixelsPerInch();
extern DELPHI_PACKAGE int __fastcall CalculateTextHeight(Vcl::Graphics::TCanvas* Canvas);
extern DELPHI_PACKAGE int __fastcall ScaleByTextHeight(Vcl::Controls::TControl* Control, int Dimension);
extern DELPHI_PACKAGE int __fastcall ScaleByTextHeightRunTime(Vcl::Controls::TControl* Control, int Dimension);
extern DELPHI_PACKAGE int __fastcall ScaleByControlTextHeightRunTime(Vcl::Graphics::TCanvas* Canvas, int Dimension);
extern DELPHI_PACKAGE int __fastcall GetSystemMetricsForControl(Vcl::Controls::TControl* Control, int nIndex);
extern DELPHI_PACKAGE void __fastcall NeedShellImageLists();
extern DELPHI_PACKAGE Vcl::Controls::TImageList* __fastcall ShellImageListForSize(int Width);
extern DELPHI_PACKAGE Vcl::Controls::TImageList* __fastcall ShellImageListForControl(Vcl::Controls::TControl* Control, TImageListSize Size);
extern DELPHI_PACKAGE bool __fastcall ControlHasRecreationPersistenceData(Vcl::Controls::TControl* Control);
extern DELPHI_PACKAGE bool __fastcall IsAppIconic();
extern DELPHI_PACKAGE void __fastcall SetAppIconic(bool Value);
extern DELPHI_PACKAGE void __fastcall SetAppMainForm(Vcl::Forms::TForm* Value);
extern DELPHI_PACKAGE void __fastcall SetAppTerminated(bool Value);
extern DELPHI_PACKAGE void __fastcall ForceColorChange(Vcl::Controls::TWinControl* Control);
extern DELPHI_PACKAGE bool __fastcall IsUncPath(System::UnicodeString Path);
extern DELPHI_PACKAGE bool __fastcall FileExistsFix(System::UnicodeString Path);
extern DELPHI_PACKAGE bool __fastcall DirectoryExistsFix(System::UnicodeString Path, bool FollowLink = true);
extern DELPHI_PACKAGE int __fastcall FindFirstEx(const System::UnicodeString Path, int Attr, System::Sysutils::TSearchRec &F, unsigned AdditionalFlags = (unsigned)(0x0), _FINDEX_SEARCH_OPS SearchOp = (_FINDEX_SEARCH_OPS)(0x0));
extern DELPHI_PACKAGE bool __fastcall SupportsDarkMode();
extern DELPHI_PACKAGE void __fastcall AllowDarkModeForWindow(Vcl::Controls::TWinControl* Control, bool Allow)/* overload */;
extern DELPHI_PACKAGE void __fastcall AllowDarkModeForWindow(Winapi::Windows::THandle Handle, bool Allow)/* overload */;
extern DELPHI_PACKAGE void __fastcall SetDarkModeTheme(Vcl::Controls::TWinControl* Control, System::UnicodeString SubAppName);
extern DELPHI_PACKAGE void __fastcall RefreshColorMode();
extern DELPHI_PACKAGE void __fastcall ResetSysDarkTheme();
extern DELPHI_PACKAGE bool __fastcall GetSysDarkTheme();
}	/* namespace Pastools */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_PASTOOLS)
using namespace Pastools;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PasToolsHPP
