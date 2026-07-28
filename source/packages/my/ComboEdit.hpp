// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ComboEdit.pas' rev: 37.00 (Windows)

#ifndef ComboEditHPP
#define ComboEditHPP

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
#include <System.Classes.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.FileCtrl.hpp>
#include <System.SysUtils.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Comboedit
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomComboEdit;
class DELPHICLASS TComboEdit;
class DELPHICLASS TFileDirEdit;
class DELPHICLASS TFilenameEdit;
class DELPHICLASS TDirectoryEdit;
class DELPHICLASS EComboEditError;
//-- type declarations -------------------------------------------------------
typedef System::UnicodeString TFileExt;

class PASCALIMPLEMENTATION TCustomComboEdit : public Vcl::Stdctrls::TCustomEdit
{
	typedef Vcl::Stdctrls::TCustomEdit inherited;
	
private:
	Vcl::Stdctrls::TButton* FButton;
	Vcl::Controls::TWinControl* FBtnControl;
	System::Classes::TNotifyEvent FOnButtonClick;
	System::Classes::TShortCut FClickKey;
	void __fastcall SetEditRect();
	void __fastcall UpdateBtnBounds();
	void __fastcall EditButtonClick(System::TObject* Sender);
	int __fastcall GetMinHeight();
	int __fastcall GetTextHeight();
	int __fastcall GetButtonWidth();
	void __fastcall SetButtonWidth(int Value);
	bool __fastcall BtnWidthStored();
	System::UnicodeString __fastcall GetButtonCaption();
	bool __fastcall ButtonCaptionStored();
	void __fastcall SetButtonCaption(System::UnicodeString Value);
	System::UnicodeString __fastcall GetButtonHint();
	void __fastcall SetButtonHint(const System::UnicodeString Value);
	bool __fastcall GetButtonTabStop();
	void __fastcall SetButtonTabStop(bool Value);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CNCtlColor(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd();
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall ButtonClick();
	__property Vcl::Stdctrls::TButton* Button = {read=FButton};
	__property System::Classes::TShortCut ClickKey = {read=FClickKey, write=FClickKey, default=32808};
	__property int ButtonWidth = {read=GetButtonWidth, write=SetButtonWidth, stored=BtnWidthStored, nodefault};
	__property System::UnicodeString ButtonCaption = {read=GetButtonCaption, write=SetButtonCaption, stored=ButtonCaptionStored};
	__property System::UnicodeString ButtonHint = {read=GetButtonHint, write=SetButtonHint};
	__property bool ButtonTabStop = {read=GetButtonTabStop, write=SetButtonTabStop, default=1};
	__property System::Classes::TNotifyEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	
public:
	__fastcall virtual TCustomComboEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomComboEdit();
	void __fastcall DoClick();
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomComboEdit(HWND ParentWindow) : Vcl::Stdctrls::TCustomEdit(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TComboEdit : public TCustomComboEdit
{
	typedef TCustomComboEdit inherited;
	
__published:
	__property AutoSelect = {default=1};
	__property ButtonHint = {default=0};
	__property ButtonTabStop = {default=1};
	__property ButtonCaption = {default=0};
	__property BorderStyle = {default=1};
	__property CharCase = {default=0};
	__property ClickKey = {default=32808};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ButtonWidth;
	__property HideSelection = {default=1};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Constraints;
	__property DragKind = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property OnButtonClick;
	__property OnChange;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property OnContextPopup;
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TCustomComboEdit.Create */ inline __fastcall virtual TComboEdit(System::Classes::TComponent* AOwner) : TCustomComboEdit(AOwner) { }
	/* TCustomComboEdit.Destroy */ inline __fastcall virtual ~TComboEdit() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TComboEdit(HWND ParentWindow) : TCustomComboEdit(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TExecOpenDialogEvent)(System::TObject* Sender, System::UnicodeString &Name, bool &Action);

class PASCALIMPLEMENTATION TFileDirEdit : public TCustomComboEdit
{
	typedef TCustomComboEdit inherited;
	
private:
	bool FAcceptFiles;
	TExecOpenDialogEvent FOnBeforeDialog;
	TExecOpenDialogEvent FOnAfterDialog;
	void __fastcall SetDragAccept(bool Value);
	void __fastcall SetAcceptFiles(bool Value);
	MESSAGE void __fastcall WMDropFiles(Winapi::Messages::TWMDropFiles &Msg);
	
protected:
	virtual void __fastcall CreateHandle();
	virtual void __fastcall DestroyWindowHandle();
	DYNAMIC void __fastcall DoAfterDialog(System::UnicodeString &FileName, bool &Action);
	DYNAMIC void __fastcall DoBeforeDialog(System::UnicodeString &FileName, bool &Action);
	virtual void __fastcall ReceptFileDir(const System::UnicodeString AFileName) = 0 ;
	virtual void __fastcall ClearFileList();
	__property MaxLength = {default=0};
	
__published:
	__property bool AcceptFiles = {read=FAcceptFiles, write=SetAcceptFiles, default=0};
	__property TExecOpenDialogEvent OnBeforeDialog = {read=FOnBeforeDialog, write=FOnBeforeDialog};
	__property TExecOpenDialogEvent OnAfterDialog = {read=FOnAfterDialog, write=FOnAfterDialog};
	__property OnButtonClick;
public:
	/* TCustomComboEdit.Create */ inline __fastcall virtual TFileDirEdit(System::Classes::TComponent* AOwner) : TCustomComboEdit(AOwner) { }
	/* TCustomComboEdit.Destroy */ inline __fastcall virtual ~TFileDirEdit() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TFileDirEdit(HWND ParentWindow) : TCustomComboEdit(ParentWindow) { }
	
};


enum DECLSPEC_DENUM TFileDialogKind : unsigned char { dkOpen, dkSave, dkOpenPicture, dkSavePicture };

class PASCALIMPLEMENTATION TFilenameEdit : public TFileDirEdit
{
	typedef TFileDirEdit inherited;
	
private:
	Vcl::Dialogs::TOpenDialog* FDialog;
	TFileDialogKind FDialogKind;
	void __fastcall CreateEditDialog();
	System::UnicodeString __fastcall GetFileName();
	TFileExt __fastcall GetDefaultExt();
	Vcl::Dialogs::TFileEditStyle __fastcall GetFileEditStyle();
	System::UnicodeString __fastcall GetFilter();
	int __fastcall GetFilterIndex();
	System::UnicodeString __fastcall GetInitialDir();
	System::Classes::TStrings* __fastcall GetHistoryList();
	System::Uitypes::TOpenOptions __fastcall GetOptions();
	System::UnicodeString __fastcall GetDialogTitle();
	System::Classes::TStrings* __fastcall GetDialogFiles();
	void __fastcall SetDialogKind(TFileDialogKind Value);
	void __fastcall SetFileName(const System::UnicodeString Value);
	void __fastcall SetDefaultExt(TFileExt Value);
	void __fastcall SetFileEditStyle(Vcl::Dialogs::TFileEditStyle Value);
	void __fastcall SetFilter(const System::UnicodeString Value);
	void __fastcall SetFilterIndex(int Value);
	void __fastcall SetInitialDir(const System::UnicodeString Value);
	void __fastcall SetHistoryList(System::Classes::TStrings* Value);
	void __fastcall SetOptions(System::Uitypes::TOpenOptions Value);
	void __fastcall SetDialogTitle(const System::UnicodeString Value);
	bool __fastcall IsCustomTitle();
	bool __fastcall IsCustomFilter();
	
protected:
	DYNAMIC void __fastcall ButtonClick();
	virtual void __fastcall ReceptFileDir(const System::UnicodeString AFileName);
	virtual void __fastcall ClearFileList();
	
public:
	__fastcall virtual TFilenameEdit(System::Classes::TComponent* AOwner);
	__property Vcl::Dialogs::TOpenDialog* Dialog = {read=FDialog};
	__property System::Classes::TStrings* DialogFiles = {read=GetDialogFiles};
	
__published:
	__property TFileDialogKind DialogKind = {read=FDialogKind, write=SetDialogKind, default=0};
	__property TFileExt DefaultExt = {read=GetDefaultExt, write=SetDefaultExt};
	__property Vcl::Dialogs::TFileEditStyle FileEditStyle = {read=GetFileEditStyle, write=SetFileEditStyle, default=0};
	__property System::UnicodeString FileName = {read=GetFileName, write=SetFileName, stored=false};
	__property System::UnicodeString Filter = {read=GetFilter, write=SetFilter, stored=IsCustomFilter};
	__property int FilterIndex = {read=GetFilterIndex, write=SetFilterIndex, default=1};
	__property System::UnicodeString InitialDir = {read=GetInitialDir, write=SetInitialDir};
	__property System::Classes::TStrings* HistoryList = {read=GetHistoryList, write=SetHistoryList};
	__property System::Uitypes::TOpenOptions DialogOptions = {read=GetOptions, write=SetOptions, default=4};
	__property System::UnicodeString DialogTitle = {read=GetDialogTitle, write=SetDialogTitle, stored=IsCustomTitle};
	__property AutoSelect = {default=1};
	__property ButtonHint = {default=0};
	__property BorderStyle = {default=1};
	__property CharCase = {default=0};
	__property ClickKey = {default=32808};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ButtonWidth;
	__property HideSelection = {default=1};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Constraints;
	__property DragKind = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property OnContextPopup;
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TCustomComboEdit.Destroy */ inline __fastcall virtual ~TFilenameEdit() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TFilenameEdit(HWND ParentWindow) : TFileDirEdit(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TDirectoryEdit : public TFileDirEdit
{
	typedef TFileDirEdit inherited;
	
private:
	System::UnicodeString FInitialDir;
	System::UnicodeString FDialogText;
	
protected:
	DYNAMIC void __fastcall ButtonClick();
	virtual void __fastcall ReceptFileDir(const System::UnicodeString AFileName);
	
public:
	__fastcall virtual TDirectoryEdit(System::Classes::TComponent* AOwner);
	
__published:
	__property System::UnicodeString DialogText = {read=FDialogText, write=FDialogText};
	__property System::UnicodeString InitialDir = {read=FInitialDir, write=FInitialDir};
	__property AutoSelect = {default=1};
	__property ButtonHint = {default=0};
	__property BorderStyle = {default=1};
	__property CharCase = {default=0};
	__property ClickKey = {default=32808};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ButtonWidth;
	__property HideSelection = {default=1};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Constraints;
	__property DragKind = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property Visible = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property OnContextPopup;
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TCustomComboEdit.Destroy */ inline __fastcall virtual ~TDirectoryEdit() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TDirectoryEdit(HWND ParentWindow) : TFileDirEdit(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION EComboEditError : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EComboEditError(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EComboEditError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EComboEditError(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EComboEditError(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EComboEditError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EComboEditError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EComboEditError(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EComboEditError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EComboEditError(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EComboEditError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EComboEditError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EComboEditError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EComboEditError() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word scAltDown = System::Word(0x8028);
static _DELPHI_CONST System::Word scCtrlEnter = System::Word(0x400d);
static _DELPHI_CONST System::Int8 DefEditBtnWidth = System::Int8(0x19);
#define DefButtonCaption L"..."
extern DELPHI_PACKAGE System::ResourceString _SBrowse;
#define Comboedit_SBrowse System::LoadResourceString(&Comboedit::_SBrowse)
extern DELPHI_PACKAGE System::ResourceString _SDefaultFilter;
#define Comboedit_SDefaultFilter System::LoadResourceString(&Comboedit::_SDefaultFilter)
extern DELPHI_PACKAGE System::ResourceString _SInvalidFileName;
#define Comboedit_SInvalidFileName System::LoadResourceString(&Comboedit::_SInvalidFileName)
static _DELPHI_CONST System::Int8 MaxFileLength = System::Int8(0x3);
extern DELPHI_PACKAGE void __fastcall Register();
extern DELPHI_PACKAGE bool __fastcall SelectDirectory(System::UnicodeString &Directory, System::UnicodeString Prompt);
}	/* namespace Comboedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_COMBOEDIT)
using namespace Comboedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ComboEditHPP
