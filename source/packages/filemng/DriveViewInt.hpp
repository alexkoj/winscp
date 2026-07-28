// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DriveViewInt.pas' rev: 37.00 (Windows)

#ifndef DriveViewIntHPP
#define DriveViewIntHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ComObj.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Winapi.ActiveX.hpp>
#include <Winapi.ShlObj.hpp>
#include <DirViewInt.hpp>
#include <ShellDialogs.hpp>
#include <DragDrop.hpp>
#include <DragDropFilesEx.hpp>
#include <FileChanges.hpp>
#include <FileOperator.hpp>
#include <DiscMon.hpp>
#include <IEDriveInfoInt.hpp>
#include <IEListView.hpp>
#include <BaseUtils.hpp>
#include <CustomDirView.hpp>
#include <CustomDriveView.hpp>
#include <System.Generics.Collections.hpp>
#include <CompThread.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ImgList.hpp>

//-- user supplied -----------------------------------------------------------

namespace Driveviewint
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EInvalidDirName;
class DELPHICLASS ENodeNotAssigned;
class DELPHICLASS TDriveStatus;
struct TScanDirInfo;
class DELPHICLASS TSubDirReaderSchedule;
class DELPHICLASS TNodeData;
class DELPHICLASS TDriveTreeNode;
class DELPHICLASS TSubDirReaderThread;
class DELPHICLASS TDriveViewInt;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EInvalidDirName : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidDirName(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidDirName(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidDirName(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidDirName(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidDirName(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidDirName(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidDirName(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidDirName(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidDirName(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidDirName(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidDirName(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidDirName(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidDirName() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ENodeNotAssigned : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ENodeNotAssigned(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ENodeNotAssigned(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ENodeNotAssigned(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ENodeNotAssigned(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ENodeNotAssigned(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ENodeNotAssigned(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ENodeNotAssigned(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ENodeNotAssigned(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ENodeNotAssigned(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ENodeNotAssigned(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ENodeNotAssigned(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ENodeNotAssigned(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ENodeNotAssigned() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TDriveStatus : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	bool Scanned;
	bool Verified;
	Vcl::Comctrls::TTreeNode* RootNode;
	int RootNodeIndex;
	Discmon::TDiscMonitor* DiscMonitor;
	Vcl::Extctrls::TTimer* ChangeTimer;
	System::UnicodeString DefaultDir;
public:
	/* TObject.Create */ inline __fastcall TDriveStatus() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TDriveStatus() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TScanDirInfo
{
public:
	bool SearchNewDirs;
	Vcl::Comctrls::TTreeNode* StartNode;
	int DriveType;
};


typedef TScanDirInfo *PScanDirInfo;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSubDirReaderSchedule : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Vcl::Comctrls::TTreeNode* Node;
	System::UnicodeString Path;
	bool Deleted;
	bool Processed;
public:
	/* TObject.Create */ inline __fastcall TSubDirReaderSchedule() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSubDirReaderSchedule() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TNodeData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FDirName;
	int FAttr;
	bool FScanned;
	void *FData;
	bool FIsRecycleBin;
	bool FIconEmpty;
	TSubDirReaderSchedule* FSchedule;
	
public:
	System::Sysutils::TSearchRec DelayedSrec;
	System::Classes::TStringList* DelayedExclude;
	__fastcall TNodeData();
	__fastcall virtual ~TNodeData();
	__property System::UnicodeString DirName = {read=FDirName, write=FDirName};
	__property int Attr = {read=FAttr, write=FAttr, nodefault};
	__property bool Scanned = {read=FScanned, write=FScanned, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property bool IsRecycleBin = {read=FIsRecycleBin, nodefault};
	__property bool IconEmpty = {read=FIconEmpty, write=FIconEmpty, nodefault};
	__property TSubDirReaderSchedule* Schedule = {read=FSchedule, write=FSchedule};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TDriveTreeNode : public Vcl::Comctrls::TTreeNode
{
	typedef Vcl::Comctrls::TTreeNode inherited;
	
__published:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TTreeNode.Create */ inline __fastcall virtual TDriveTreeNode(Vcl::Comctrls::TTreeNodes* AOwner) : Vcl::Comctrls::TTreeNode(AOwner) { }
	/* TTreeNode.Destroy */ inline __fastcall virtual ~TDriveTreeNode() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TSubDirReaderThread : public Compthread::TCompThread
{
	typedef Compthread::TCompThread inherited;
	
public:
	__fastcall virtual ~TSubDirReaderThread();
	virtual void __fastcall Terminate();
	
protected:
	__fastcall TSubDirReaderThread(TDriveViewInt* DriveView);
	void __fastcall Add(Vcl::Comctrls::TTreeNode* Node, System::UnicodeString Path);
	void __fastcall Delete(Vcl::Comctrls::TTreeNode* Node);
	int __fastcall Detach();
	void __fastcall Reattach(int Count);
	virtual void __fastcall Execute();
	
private:
	TDriveViewInt* FDriveView;
	Winapi::Windows::THandle FEvent;
	System::Generics::Collections::TStack__1<TSubDirReaderSchedule*>* FQueue;
	System::Generics::Collections::TQueue__1<TSubDirReaderSchedule*>* FResults;
	Winapi::Windows::TRTLCriticalSection FSection;
	Vcl::Extctrls::TTimer* FTimer;
	HWND FWindowHandle;
	void __fastcall TriggerEvent();
	void __fastcall ScheduleProcess();
	void __fastcall Process();
	bool __fastcall ProcessResult();
	void __fastcall Timer(System::TObject* Sender);
	void __fastcall WndProc(Winapi::Messages::TMessage &Msg);
	int __fastcall DetachList(System::Generics::Collections::TEnumerable__1<TSubDirReaderSchedule*>* List);
	void __fastcall DestroyScheduleList(System::Generics::Collections::TEnumerable__1<TSubDirReaderSchedule*>* List);
};


typedef System::DynamicArray<Vcl::Comctrls::TTreeNode*> TTreeNodeArray;

class PASCALIMPLEMENTATION TDriveViewInt : public Customdriveview::TCustomDriveView
{
	typedef Customdriveview::TCustomDriveView inherited;
	
private:
	bool FConfirmDelete;
	bool FConfirmOverwrite;
	bool FWatchDirectory;
	System::UnicodeString FDirectory;
	bool FChangeFlag;
	System::UnicodeString FLastDir;
	bool FValidateFlag;
	bool FSysColorChangePending;
	bool FCreating;
	bool FForceRename;
	Vcl::Comctrls::TTreeNode* FRenameNode;
	System::UnicodeString FLastRenameName;
	Vcl::Comctrls::TTreeNode* FPrevSelected;
	int FPrevSelectedIndex;
	int FChangeTimerSuspended;
	TSubDirReaderThread* FSubDirReaderThread;
	System::Classes::TStringList* FDelayedNodes;
	Vcl::Extctrls::TTimer* FDelayedNodeTimer;
	int FRecreateScheduledCount;
	System::Classes::TNotifyEvent FOnDisplayContextMenu;
	System::Classes::TNotifyEvent FOnNeedHiddenDirectories;
	Dirviewint::TDirViewInt* FDirView;
	Fileoperator::TFileOperator* FFileOperator;
	unsigned FChangeInterval;
	System::UnicodeString FLastPathCut;
	void __fastcall SignalDirDelete(System::TObject* Sender, System::Classes::TStringList* Files);
	bool __fastcall GetSubDir(System::Sysutils::TSearchRec &SRec);
	bool __fastcall FindFirstSubDir(System::UnicodeString Path, System::Sysutils::TSearchRec &SRec);
	bool __fastcall FindNextSubDir(System::Sysutils::TSearchRec &SRec);
	void __fastcall ReadSubDirs(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall CancelDelayedNode(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall DelayedNodeTimer(System::TObject* Sender);
	bool __fastcall ReadSubDirsBatch(Vcl::Comctrls::TTreeNode* Node, System::Sysutils::TSearchRec &SRec, int CheckInterval, int Limit);
	void __fastcall UpdateDelayedNodeTimer();
	Vcl::Comctrls::TTreeNode* __fastcall DoSearchSubDirs(Vcl::Comctrls::TTreeNode* ParentNode, System::UnicodeString Path, int Level, bool ExistingOnly, TTreeNodeArray &SelectionHierarchy, int &SelectionHierarchyHeight);
	Vcl::Comctrls::TTreeNode* __fastcall SearchSubDirs(Vcl::Comctrls::TTreeNode* ParentNode, System::UnicodeString Path, int Level, bool ExistingOnly, TTreeNodeArray &SelectionHierarchy, int &SelectionHierarchyHeight);
	bool __fastcall CallBackValidateDir(Vcl::Comctrls::TTreeNode* &Node, void * Data);
	void __fastcall DeleteNode(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall ChangeDetected(System::TObject* Sender, const System::UnicodeString Directory, bool &SubdirsChanged);
	void __fastcall ChangeInvalid(System::TObject* Sender, const System::UnicodeString Directory, const System::UnicodeString ErrorStr);
	void __fastcall ChangeTimerOnTimer(System::TObject* Sender);
	
protected:
	HIDESBASE void __fastcall SetSelected(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall SetWatchDirectory(bool Value);
	void __fastcall SetDirView(Dirviewint::TDirViewInt* Value);
	virtual void __fastcall SetDirectory(System::UnicodeString Value);
	bool __fastcall DoScanDir(Vcl::Comctrls::TTreeNode* FromNode);
	void __fastcall AddChildNode(Vcl::Comctrls::TTreeNode* ParentNode, System::UnicodeString ParentPath, const System::Sysutils::TSearchRec &SRec);
	void __fastcall CreateWatchThread(System::UnicodeString Drive);
	bool __fastcall NodeWatched(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall TerminateWatchThread(System::UnicodeString Drive);
	bool __fastcall WatchThreadActive()/* overload */;
	bool __fastcall WatchThreadActive(System::UnicodeString Drive)/* overload */;
	void __fastcall SubscribeDriveNotifications(System::UnicodeString Drive);
	void __fastcall DriveRemoved(System::UnicodeString Drive);
	void __fastcall DriveRemoving(System::UnicodeString Drive);
	void __fastcall RefreshRootNodes(bool Floppy = false);
	void __fastcall DriveNotification(Iedriveinfoint::TDriveNotification Notification, System::UnicodeString Drive);
	int __fastcall DirAttrMask();
	TDriveStatus* __fastcall CreateDriveStatus();
	virtual bool __fastcall GetNextDriveStatus(int &Iterator, System::PUnicodeString Drive, TDriveStatus* &Status) = 0 ;
	virtual void __fastcall ValidateDirectoryEx(Vcl::Comctrls::TTreeNode* Node, Customdriveview::TRecursiveScan Recurse, bool NewDirs);
	virtual void __fastcall RebuildTree();
	virtual void __fastcall CreateWnd();
	virtual void __fastcall DestroyWnd();
	DYNAMIC void __fastcall Edit(const Winapi::Commctrl::TTVItem &Item);
	MESSAGE void __fastcall WMUserRename(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	virtual Customdirview::TCustomDirView* __fastcall GetCustomDirView();
	virtual void __fastcall SetCustomDirView(Customdirview::TCustomDirView* Value);
	virtual System::UnicodeString __fastcall NodePath(Vcl::Comctrls::TTreeNode* Node);
	virtual bool __fastcall NodeIsRecycleBin(Vcl::Comctrls::TTreeNode* Node);
	virtual bool __fastcall NodePathExists(Vcl::Comctrls::TTreeNode* Node);
	virtual System::Uitypes::TColor __fastcall NodeColor(Vcl::Comctrls::TTreeNode* Node);
	virtual Vcl::Comctrls::TTreeNode* __fastcall FindPathNode(System::UnicodeString Path);
	Vcl::Comctrls::TTreeNode* __fastcall DoFindNodeToPath(System::UnicodeString Path, bool ExistingOnly);
	virtual Vcl::Comctrls::TTreeNode* __fastcall CreateNode();
	virtual Dragdrop::TDropEffectSet __fastcall DDSourceEffects();
	virtual void __fastcall DDChooseEffect(int KeyState, int &Effect, int PreferredEffect);
	virtual bool __fastcall DragCompleteFileList();
	virtual Dragdrop::TDragResult __fastcall DDExecute();
	bool __fastcall CanPasteFromClipBoard();
	void __fastcall PasteFromClipBoard(Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall PerformDragDropFileOperation(Vcl::Comctrls::TTreeNode* Node, int Effect);
	void __fastcall ClearCutState();
	
public:
	__property Images;
	__property StateImages;
	__property Items = {stored=false};
	__property Selected = {write=SetSelected, stored=false};
	__property System::UnicodeString LastPathCut = {read=FLastPathCut};
	DYNAMIC void __fastcall EmptyClipboard();
	virtual TDriveStatus* __fastcall GetDriveStatus(System::UnicodeString Drive) = 0 ;
	int __fastcall GetDriveTypetoNode(Vcl::Comctrls::TTreeNode* Node);
	System::UnicodeString __fastcall GetDriveToNode(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall ScanDrive(System::UnicodeString Drive);
	System::Classes::TStrings* __fastcall GetDrives();
	virtual void __fastcall SetImageIndex(Vcl::Comctrls::TTreeNode* Node);
	Vcl::Comctrls::TTreeNode* __fastcall FindNodeToPath(System::UnicodeString Path);
	Vcl::Comctrls::TTreeNode* __fastcall TryFindNodeToPath(System::UnicodeString Path);
	Vcl::Comctrls::TTreeNode* __fastcall RootNode(Vcl::Comctrls::TTreeNode* Node);
	System::UnicodeString __fastcall GetDirName(Vcl::Comctrls::TTreeNode* Node);
	System::UnicodeString __fastcall GetDisplayName(Vcl::Comctrls::TTreeNode* Node);
	virtual System::UnicodeString __fastcall NodePathName(Vcl::Comctrls::TTreeNode* Node);
	__fastcall virtual TDriveViewInt(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDriveViewInt();
	virtual void __fastcall DisplayContextMenu(Vcl::Comctrls::TTreeNode* Node, const Winapi::Windows::TPoint &Point);
	virtual void __fastcall DisplayPropertiesMenu(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall StartWatchThread();
	void __fastcall StopWatchThread();
	void __fastcall SuspendChangeTimer();
	void __fastcall ResumeChangeTimer();
	void __fastcall StartAllWatchThreads();
	void __fastcall StopAllWatchThreads();
	void __fastcall ValidateCurrentDirectoryIfNotMonitoring();
	virtual void __fastcall GetImageIndex(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanChange(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanExpand(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall Delete(Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall Loaded();
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall Change(Vcl::Comctrls::TTreeNode* Node);
	
__published:
	__property Directory = {default=0};
	__property bool ConfirmDelete = {read=FConfirmDelete, write=FConfirmDelete, default=1};
	__property bool ConfirmOverwrite = {read=FConfirmOverwrite, write=FConfirmOverwrite, default=1};
	__property bool WatchDirectory = {read=FWatchDirectory, write=SetWatchDirectory, default=0};
	__property Dirviewint::TDirViewInt* DirView = {read=FDirView, write=SetDirView};
	__property System::Classes::TNotifyEvent OnDisplayContextMenu = {read=FOnDisplayContextMenu, write=FOnDisplayContextMenu};
	__property OnBusy;
	__property DDLinkOnExeDrag = {default=1};
	__property TargetPopUpMenu = {default=1};
	__property OnDDDragEnter;
	__property OnDDDragLeave;
	__property OnDDDragOver;
	__property OnDDDrop;
	__property OnDDQueryContinueDrag;
	__property OnDDGiveFeedback;
	__property OnDDDragDetect;
	__property OnDDProcessDropped;
	__property OnDDError;
	__property OnDDExecuted;
	__property OnDDFileOperation;
	__property OnDDFileOperationExecuted;
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoExpand = {default=0};
	__property BiDiMode;
	__property BorderStyle = {default=1};
	__property BorderWidth = {default=0};
	__property ChangeDelay = {default=0};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property Constraints;
	__property DoubleBuffered;
	__property DragKind = {default=0};
	__property DragCursor = {default=-12};
	__property DragMode = {default=1};
	__property OnDragDrop;
	__property OnDragOver;
	__property Enabled = {default=1};
	__property Font;
	__property HideSelection = {default=1};
	__property HotTrack = {default=0};
	__property Indent;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentDoubleBuffered = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property RightClickSelect = {default=0};
	__property RowSelect = {default=0};
	__property ShowButtons = {default=1};
	__property ShowHint;
	__property ShowLines = {default=1};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property ToolTips = {default=1};
	__property Visible = {default=1};
	__property OnChange;
	__property OnChanging;
	__property OnClick;
	__property OnCollapsing;
	__property OnCollapsed;
	__property OnCompare;
	__property OnDblClick;
	__property OnDeletion;
	__property OnEdited;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnExpanding;
	__property OnExpanded;
	__property OnGetImageIndex;
	__property OnGetSelectedIndex;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
	__property System::Classes::TNotifyEvent OnNeedHiddenDirectories = {read=FOnNeedHiddenDirectories, write=FOnNeedHiddenDirectories};
public:
	/* TWinControl.CreateParented */ inline __fastcall TDriveViewInt(HWND ParentWindow) : Customdriveview::TCustomDriveView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int DriveViewLoadingTooLongLimit;
}	/* namespace Driveviewint */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DRIVEVIEWINT)
using namespace Driveviewint;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DriveViewIntHPP
