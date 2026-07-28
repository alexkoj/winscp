// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CustomDriveView.pas' rev: 37.00 (Windows)

#ifndef CustomDriveViewHPP
#define CustomDriveViewHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Winapi.ShlObj.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Graphics.hpp>
#include <DragDrop.hpp>
#include <CustomDirView.hpp>
#include <IEDriveInfoInt.hpp>
#include <DragDropFilesEx.hpp>
#include <PasTools.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Customdriveview
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomDriveView;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TRecursiveScan : unsigned char { rsNoRecursive, rsRecursiveExisting };

enum DECLSPEC_DENUM TScanStartNode : unsigned char { coNoScanStartNode, coScanStartNode };

typedef bool __fastcall (__closure *TCallBackFunc)(Vcl::Comctrls::TTreeNode* &Node, void * Data);

class PASCALIMPLEMENTATION TCustomDriveView : public Vcl::Comctrls::TCustomTreeView
{
	typedef Vcl::Comctrls::TCustomTreeView inherited;
	
protected:
	Vcl::Forms::TCustomForm* FParentForm;
	System::Classes::TStringList* FDragFileList;
	Customdirview::TCustomizableDragDropFilesEx* FDragDropFilesEx;
	System::UnicodeString FDragDrive;
	bool FExeDrag;
	bool FDDLinkOnExeDrag;
	Vcl::Comctrls::TTreeNode* FDragNode;
	_FILETIME FDragStartTime;
	Winapi::Windows::TPoint FStartPos;
	bool FContextMenu;
	bool FCanChange;
	bool FUseSystemContextMenu;
	bool FDimmHiddenDirs;
	bool FShowHiddenDirs;
	bool FNaturalOrderNumericalSorting;
	bool FDarkMode;
	Vcl::Controls::TImageList* FImageList;
	Pastools::TTreeViewScrollOnDragOver* FScrollOnDragOver;
	bool FRecreatingHandle;
	Customdirview::TDDOnDragEnter FOnDDDragEnter;
	Customdirview::TDDOnDragLeave FOnDDDragLeave;
	Customdirview::TDDOnDragOver FOnDDDragOver;
	Customdirview::TDDOnDrop FOnDDDrop;
	Customdirview::TDDOnQueryContinueDrag FOnDDQueryContinueDrag;
	Customdirview::TDDOnChooseEffect FOnDDChooseEffect;
	Customdirview::TDDOnGiveFeedback FOnDDGiveFeedback;
	Customdirview::TDDOnDragDetect FOnDDDragDetect;
	Customdirview::TOnProcessDropped FOnDDProcessDropped;
	Customdirview::TDDErrorEvent FOnDDError;
	Customdirview::TDDExecutedEvent FOnDDExecuted;
	Customdirview::TDDFileOperationEvent FOnDDFileOperation;
	Customdirview::TDDFileOperationExecutedEvent FOnDDFileOperationExecuted;
	Customdirview::TDDOnCreateDragFileList FOnDDCreateDragFileList;
	System::Classes::TNotifyEvent FOnDDEnd;
	Customdirview::TDDOnCreateDataObject FOnDDCreateDataObject;
	Dragdrop::TDragResult FLastDDResult;
	Customdirview::TDirViewBusy FOnBusy;
	bool __fastcall GetTargetPopupMenu();
	void __fastcall SetTargetPopUpMenu(bool Value);
	void __fastcall SetDimmHiddenDirs(bool Value);
	void __fastcall SetShowHiddenDirs(bool Value);
	void __fastcall SetNaturalOrderNumericalSorting(bool Value);
	void __fastcall SetDarkMode(bool Value);
	virtual System::UnicodeString __fastcall GetDirectory();
	virtual void __fastcall SetDirectory(System::UnicodeString Value);
	virtual Customdirview::TCustomDirView* __fastcall GetCustomDirView() = 0 ;
	virtual void __fastcall SetCustomDirView(Customdirview::TCustomDirView* Value) = 0 ;
	virtual void __fastcall CreateWnd();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	Vcl::Comctrls::TTreeNode* __fastcall GetNodeFromHItem(const Winapi::Commctrl::TTVItem &Item);
	virtual bool __fastcall IsCustomDrawn(Vcl::Comctrls::TCustomDrawTarget Target, Vcl::Comctrls::TCustomDrawStage Stage);
	virtual bool __fastcall CustomDrawItem(Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, Vcl::Comctrls::TCustomDrawStage Stage, bool &PaintImages);
	void __fastcall NeedImageLists();
	void __fastcall DoCompare(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node1, Vcl::Comctrls::TTreeNode* Node2, int Data, int &Compare);
	int __fastcall DoCompareText(System::UnicodeString Text1, System::UnicodeString Text2);
	void __fastcall UpdateItemHeight();
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Msg);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall CMRecreateWnd(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMLButtonDown &Msg);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMLButtonDown &Msg);
	HIDESBASE MESSAGE void __fastcall WMRButtonDown(Winapi::Messages::TWMRButtonDown &Msg);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMLButtonDblClk &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Msg);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TWMKeyDown &Message);
	MESSAGE void __fastcall CMDPIChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool isDpiChange)/* overload */;
	DYNAMIC void __fastcall Delete(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall InternalOnDrawItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	void __fastcall DDDragEnter(Dragdrop::IDataObject DataObj, System::LongInt KeyState, const Winapi::Windows::TPoint &Point, System::LongInt &Effect, bool &Accept);
	void __fastcall DDDragLeave(int Dummy);
	void __fastcall DDDragOver(System::LongInt KeyState, const Winapi::Windows::TPoint &Point, System::LongInt &Effect, System::LongInt PreferredEffect);
	void __fastcall DDDrop(Dragdrop::IDataObject DataObj, System::LongInt KeyState, const Winapi::Windows::TPoint &Point, System::LongInt &Effect);
	void __fastcall DDQueryContinueDrag(System::LongBool EscapePressed, System::LongInt KeyState, HRESULT &Result);
	void __fastcall DDDropHandlerSucceeded(System::TObject* Sender, System::LongInt KeyState, const Winapi::Windows::TPoint &Point, System::LongInt Effect);
	void __fastcall DDGiveFeedback(System::LongInt Effect, HRESULT &Result);
	void __fastcall DDProcessDropped(System::TObject* Sender, System::LongInt KeyState, const Winapi::Windows::TPoint &Point, System::LongInt Effect);
	virtual void __fastcall DDError(Customdirview::TDDError Error);
	void __fastcall DDSpecifyDropTarget(System::TObject* Sender, bool DragDropHandler, const Winapi::Windows::TPoint &Point, Dragdropfilesex::PItemIDList &PIDL, System::UnicodeString &Filename);
	virtual void __fastcall DDDragDetect(System::LongInt KeyState, const Winapi::Windows::TPoint &DetectStart, const Winapi::Windows::TPoint &Point, Dragdrop::TDragDetectStatus DragStatus);
	virtual void __fastcall PerformDragDropFileOperation(Vcl::Comctrls::TTreeNode* Node, int Effect) = 0 ;
	virtual void __fastcall DDChooseEffect(int KeyState, int &Effect, int PreferredEffect);
	virtual bool __fastcall DragCompleteFileList() = 0 ;
	virtual Dragdrop::TDragResult __fastcall DDExecute();
	virtual Dragdrop::TDropEffectSet __fastcall DDSourceEffects() = 0 ;
	virtual System::UnicodeString __fastcall NodePath(Vcl::Comctrls::TTreeNode* Node) = 0 ;
	virtual bool __fastcall NodeIsRecycleBin(Vcl::Comctrls::TTreeNode* Node);
	virtual bool __fastcall NodePathExists(Vcl::Comctrls::TTreeNode* Node);
	virtual System::Uitypes::TColor __fastcall NodeColor(Vcl::Comctrls::TTreeNode* Node) = 0 ;
	virtual bool __fastcall NodeCanDrag(Vcl::Comctrls::TTreeNode* Node);
	virtual System::Word __fastcall NodeOverlayIndexes(Vcl::Comctrls::TTreeNode* Node);
	virtual Vcl::Comctrls::TTreeNode* __fastcall FindPathNode(System::UnicodeString Path) = 0 ;
	virtual void __fastcall ClearDragFileList(Dragdropfilesex::TFileList* FileList);
	virtual void __fastcall AddToDragFileList(Dragdropfilesex::TFileList* FileList, Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall ValidateDirectoryEx(Vcl::Comctrls::TTreeNode* Node, TRecursiveScan Recurse, bool NewDirs) = 0 ;
	virtual void __fastcall RebuildTree() = 0 ;
	virtual void __fastcall DisplayContextMenu(Vcl::Comctrls::TTreeNode* Node, const Winapi::Windows::TPoint &ScreenPos) = 0 ;
	virtual void __fastcall DisplayPropertiesMenu(Vcl::Comctrls::TTreeNode* Node) = 0 ;
	void __fastcall ScrollOnDragOverBeforeUpdate(System::TObject* ObjectToValidate);
	bool __fastcall DoBusy(int Busy);
	bool __fastcall StartBusy();
	void __fastcall EndBusy();
	bool __fastcall IsBusy();
	__property Vcl::Controls::TImageList* ImageList = {read=FImageList};
	
public:
	__fastcall virtual TCustomDriveView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDriveView();
	void __fastcall ValidateDirectory(Vcl::Comctrls::TTreeNode* Node);
	bool __fastcall SortChildren(Vcl::Comctrls::TTreeNode* ParentNode, bool Recurse);
	bool __fastcall IterateSubTree(Vcl::Comctrls::TTreeNode* &StartNode, TCallBackFunc CallBackFunc, TRecursiveScan Recurse, TScanStartNode ScanStartNode, void * Data);
	virtual System::UnicodeString __fastcall NodePathName(Vcl::Comctrls::TTreeNode* Node) = 0 ;
	__property Customdirview::TCustomizableDragDropFilesEx* DragDropFilesEx = {read=FDragDropFilesEx};
	__property bool UseSystemContextMenu = {read=FUseSystemContextMenu, write=FUseSystemContextMenu, default=1};
	__property bool DimmHiddenDirs = {read=FDimmHiddenDirs, write=SetDimmHiddenDirs, default=0};
	__property bool ShowHiddenDirs = {read=FShowHiddenDirs, write=SetShowHiddenDirs, default=0};
	__property bool NaturalOrderNumericalSorting = {read=FNaturalOrderNumericalSorting, write=SetNaturalOrderNumericalSorting, nodefault};
	__property bool DarkMode = {read=FDarkMode, write=SetDarkMode, nodefault};
	__property bool DDLinkOnExeDrag = {read=FDDLinkOnExeDrag, write=FDDLinkOnExeDrag, default=1};
	__property Customdirview::TDDOnDragEnter OnDDDragEnter = {read=FOnDDDragEnter, write=FOnDDDragEnter};
	__property Customdirview::TDDOnDragLeave OnDDDragLeave = {read=FOnDDDragLeave, write=FOnDDDragLeave};
	__property Customdirview::TDDOnDragOver OnDDDragOver = {read=FOnDDDragOver, write=FOnDDDragOver};
	__property Customdirview::TDDOnDrop OnDDDrop = {read=FOnDDDrop, write=FOnDDDrop};
	__property Customdirview::TDDOnQueryContinueDrag OnDDQueryContinueDrag = {read=FOnDDQueryContinueDrag, write=FOnDDQueryContinueDrag};
	__property Customdirview::TDDOnChooseEffect OnDDChooseEffect = {read=FOnDDChooseEffect, write=FOnDDChooseEffect};
	__property Customdirview::TDDOnGiveFeedback OnDDGiveFeedback = {read=FOnDDGiveFeedback, write=FOnDDGiveFeedback};
	__property Customdirview::TDDOnDragDetect OnDDDragDetect = {read=FOnDDDragDetect, write=FOnDDDragDetect};
	__property Customdirview::TOnProcessDropped OnDDProcessDropped = {read=FOnDDProcessDropped, write=FOnDDProcessDropped};
	__property Customdirview::TDDErrorEvent OnDDError = {read=FOnDDError, write=FOnDDError};
	__property Customdirview::TDDExecutedEvent OnDDExecuted = {read=FOnDDExecuted, write=FOnDDExecuted};
	__property Customdirview::TDDFileOperationEvent OnDDFileOperation = {read=FOnDDFileOperation, write=FOnDDFileOperation};
	__property Customdirview::TDDFileOperationExecutedEvent OnDDFileOperationExecuted = {read=FOnDDFileOperationExecuted, write=FOnDDFileOperationExecuted};
	__property Customdirview::TDDOnCreateDragFileList OnDDCreateDragFileList = {read=FOnDDCreateDragFileList, write=FOnDDCreateDragFileList};
	__property System::Classes::TNotifyEvent OnDDEnd = {read=FOnDDEnd, write=FOnDDEnd};
	__property Customdirview::TDDOnCreateDataObject OnDDCreateDataObject = {read=FOnDDCreateDataObject, write=FOnDDCreateDataObject};
	__property Customdirview::TDirViewBusy OnBusy = {read=FOnBusy, write=FOnBusy};
	__property bool TargetPopUpMenu = {read=GetTargetPopupMenu, write=SetTargetPopUpMenu, default=1};
	__property System::UnicodeString Directory = {read=GetDirectory, write=SetDirectory};
	__property Vcl::Comctrls::TTreeNode* DragNode = {read=FDragNode};
	__property Dragdrop::TDragResult LastDDResult = {read=FLastDDResult, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomDriveView(HWND ParentWindow) : Vcl::Comctrls::TCustomTreeView(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	DYNAMIC inline void __fastcall  ChangeScale(int M, int D){ Vcl::Controls::TControl::ChangeScale(M, D); }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Customdriveview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CUSTOMDRIVEVIEW)
using namespace Customdriveview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CustomDriveViewHPP
