// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DirViewInt.pas' rev: 37.00 (Windows)

#ifndef DirViewIntHPP
#define DirViewIntHPP

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
#include <Vcl.ComCtrls.hpp>
#include <CompThread.hpp>
#include <CustomDirView.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <FileOperator.hpp>
#include <DiscMon.hpp>
#include <System.Classes.hpp>
#include <DirViewColProperties.hpp>
#include <DragDrop.hpp>
#include <Winapi.Messages.hpp>
#include <ListViewColProperties.hpp>
#include <Winapi.CommCtrl.hpp>
#include <DragDropFilesEx.hpp>
#include <Vcl.FileCtrl.hpp>
#include <System.SysUtils.hpp>
#include <BaseUtils.hpp>
#include <Vcl.Controls.hpp>
#include <CustomDriveView.hpp>
#include <System.Generics.Collections.hpp>
#include <Winapi.ShellAPI.hpp>
#include <System.Types.hpp>
#include <IEListView.hpp>
#include <NortonLikeListView.hpp>
#include <PathLabel.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dirviewint
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EDragDrop;
struct TFileRec;
class DELPHICLASS TIconUpdateThread;
struct TIconUpdateSchedule;
class DELPHICLASS TDirViewInt;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EDragDrop : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EDragDrop(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EDragDrop(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EDragDrop(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EDragDrop(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EDragDrop(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EDragDrop(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EDragDrop(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EDragDrop(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDragDrop(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDragDrop(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDragDrop(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDragDrop(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EDragDrop() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TClipboardOperation : unsigned char { cboNone, cboCut, cboCopy };

typedef TFileRec *PFileRec;

struct DECLSPEC_DRECORD TFileRec
{
public:
	bool Empty;
	bool IconEmpty;
	bool IsDirectory;
	bool IsRecycleBin;
	bool IsParentDir;
	System::UnicodeString FileName;
	System::UnicodeString Displayname;
	System::UnicodeString FileExt;
	System::UnicodeString TypeName;
	int ImageIndex;
	Vcl::Graphics::TBitmap* Thumbnail;
	System::Types::TSize ThumbnailSize;
	__int64 Size;
	System::LongWord Attr;
	Winapi::Windows::TFileTime FileTime;
	Dragdropfilesex::PItemIDList PIDL;
	__int64 CalculatedSize;
};


typedef void __fastcall (__closure *TDirViewFileSizeChanged)(System::TObject* Sender, Vcl::Comctrls::TListItem* Item);

typedef void __fastcall (__closure *TDirViewFileIconForName)(System::TObject* Sender, System::UnicodeString &FileName);

class PASCALIMPLEMENTATION TIconUpdateThread : public Compthread::TCompThread
{
	typedef Compthread::TCompThread inherited;
	
private:
	TDirViewInt* FOwner;
	int FSyncIcon;
	Vcl::Graphics::TBitmap* FSyncThumbnail;
	int FCurrentIndex;
	System::UnicodeString FCurrentFilePath;
	TFileRec FCurrentItemData;
	
protected:
	__fastcall TIconUpdateThread(TDirViewInt* Owner);
	virtual void __fastcall Execute();
	
public:
	__fastcall virtual ~TIconUpdateThread();
};


struct DECLSPEC_DRECORD TIconUpdateSchedule
{
public:
	int Index;
};


class PASCALIMPLEMENTATION TDirViewInt : public Customdirview::TCustomDirView
{
	typedef Customdirview::TCustomDirView inherited;
	
private:
	bool FConfirmDelete;
	bool FConfirmOverwrite;
	Customdriveview::TCustomDriveView* FDriveView;
	Vcl::Extctrls::TTimer* FChangeTimer;
	unsigned FChangeInterval;
	bool FUseIconUpdateThread;
	int FDriveType;
	_di_IShellFolder FParentFolder;
	_di_IShellFolder FDesktopFolder;
	bool FDirOK;
	int FHiddenCount;
	int FFilteredCount;
	bool FNotRelative;
	Fileoperator::TFileOperator* FFileOperator;
	TIconUpdateThread* FIconUpdateThread;
	Discmon::TDiscMonitor* FDiscMonitor;
	System::UnicodeString FHomeDirectory;
	TDirViewFileIconForName FOnFileIconForName;
	_di_IShellFolder iRecycleFolder;
	Dragdropfilesex::PItemIDList PIDLRecycle;
	bool FTimeoutShellIconRetrieval;
	bool FAnyCut;
	Dirviewcolproperties::TDirViewColProperties* __fastcall GetDirColProperties();
	System::UnicodeString __fastcall GetHomeDirectory();
	void __fastcall SignalFileDelete(System::TObject* Sender, System::Classes::TStringList* Files);
	void __fastcall PerformDragDropFileOperation(System::UnicodeString TargetPath, int Effect);
	void __fastcall SetDirColProperties(Dirviewcolproperties::TDirViewColProperties* Value);
	
protected:
	System::UnicodeString FPath;
	virtual Listviewcolproperties::TCustomListViewColProperties* __fastcall NewColProperties();
	virtual bool __fastcall SortAscendingByDefault(int Index);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall Delete(Vcl::Comctrls::TListItem* Item);
	void __fastcall DDError(Customdirview::TDDError ErrorNo);
	_di_IShellFolder __fastcall GetShellFolder(System::UnicodeString Dir);
	virtual bool __fastcall GetDirOK();
	virtual void __fastcall GetDisplayInfo(Vcl::Comctrls::TListItem* ListItem, Winapi::Commctrl::TLVItem &DispInfo);
	virtual void __fastcall DDDragDetect(System::LongInt grfKeyState, const Winapi::Windows::TPoint &DetectStart, const Winapi::Windows::TPoint &Point, Dragdrop::TDragDetectStatus DragStatus);
	virtual void __fastcall DDMenuPopup(System::TObject* Sender, HMENU AMenu, Dragdrop::IDataObject DataObj, int AMinCustCmd, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt);
	virtual void __fastcall DDMenuDone(System::TObject* Sender, HMENU AMenu);
	virtual void __fastcall DDDropHandlerSucceeded(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt dwEffect);
	virtual void __fastcall DDChooseEffect(int grfKeyState, int &dwEffect, int PreferredEffect);
	virtual System::UnicodeString __fastcall GetPathName();
	virtual void __fastcall SetChangeInterval(unsigned Value);
	virtual void __fastcall LoadFromRecycleBin(System::UnicodeString Dir);
	virtual void __fastcall SetLoadEnabled(bool Value);
	virtual System::UnicodeString __fastcall GetPath();
	virtual void __fastcall SetPath(System::UnicodeString Value);
	virtual void __fastcall SetItemImageIndex(Vcl::Comctrls::TListItem* Item, int Index);
	void __fastcall ChangeDetected(System::TObject* Sender, const System::UnicodeString Directory, bool &SubdirsChanged);
	void __fastcall ChangeInvalid(System::TObject* Sender, const System::UnicodeString Directory, const System::UnicodeString ErrorStr);
	void __fastcall TimerOnTimer(System::TObject* Sender);
	void __fastcall ResetItemImage(int Index);
	virtual void __fastcall SetWatchForChanges(bool Value);
	void __fastcall AddParentDirItem();
	virtual void __fastcall AddToDragFileList(Dragdropfilesex::TFileList* FileList, Vcl::Comctrls::TListItem* Item);
	virtual bool __fastcall DragCompleteFileList();
	virtual void __fastcall ExecuteFile(Vcl::Comctrls::TListItem* Item);
	virtual bool __fastcall GetIsRoot();
	virtual void __fastcall InternalEdit(const Winapi::Commctrl::TLVItem &HItem);
	virtual System::Uitypes::TColor __fastcall ItemColor(Vcl::Comctrls::TListItem* Item);
	virtual Vcl::Graphics::TBitmap* __fastcall ItemThumbnail(Vcl::Comctrls::TListItem* Item, const System::Types::TSize &Size);
	System::UnicodeString __fastcall ItemFileExt(Vcl::Comctrls::TListItem* Item);
	System::UnicodeString __fastcall ItemFileNameOnly(Vcl::Comctrls::TListItem* Item);
	virtual int __fastcall ItemImageIndex(Vcl::Comctrls::TListItem* Item, bool Cache);
	virtual bool __fastcall ItemIsFile(Vcl::Comctrls::TListItem* Item);
	virtual bool __fastcall ItemIsRecycleBin(Vcl::Comctrls::TListItem* Item);
	virtual bool __fastcall ItemMatchesFilter(Vcl::Comctrls::TListItem* Item, const Customdirview::TFileFilter &Filter);
	bool __fastcall FileMatches(System::UnicodeString FileName, const System::Sysutils::TSearchRec &SearchRec);
	virtual System::Word __fastcall ItemOverlayIndexes(Vcl::Comctrls::TListItem* Item);
	virtual void __fastcall LoadFiles();
	virtual void __fastcall PerformItemDragDropOperation(Vcl::Comctrls::TListItem* Item, int Effect, bool Paste);
	virtual void __fastcall SortItems();
	bool __fastcall ThumbnailNeeded(PFileRec ItemData);
	void __fastcall DoFetchIconUpdate();
	void __fastcall DoUpdateIcon();
	void __fastcall StartFileDeleteThread();
	virtual void __fastcall IconUpdateEnqueue(Vcl::Comctrls::TListItem* ListItem) = 0 ;
	virtual int __fastcall IconUpdatePeek() = 0 ;
	virtual void __fastcall IconUpdateDequeue(int Index) = 0 ;
	HIDESBASE MESSAGE void __fastcall WMDestroy(Winapi::Messages::TWMDestroy &Msg);
	virtual void __fastcall Load(bool DoFocusSomething);
	void __fastcall DoFetchIcon(System::UnicodeString FilePath, bool IsSpecialExt, bool CanTimeout, PFileRec FileRec, int &ImageIndex, System::UnicodeString &TypeName);
	unsigned __fastcall GetFileInfo(bool CanUsePIDL, Dragdropfilesex::PItemIDList PIDL, System::UnicodeString Path, bool CanTimeout, unsigned dwFileAttributes, Winapi::Shellapi::TSHFileInfoW &psfi, unsigned uFlags);
	bool __fastcall DoCopyToClipboard(bool Focused, bool Cut, TClipboardOperation Operation);
	void __fastcall ClearCutState();
	virtual void __fastcall IconUpdateClear() = 0 ;
	virtual bool __fastcall IconUpdateDeprioritize(PFileRec ItemData, int Index) = 0 ;
	virtual bool __fastcall TryGetLastPath(System::UnicodeString Drive, System::UnicodeString &Path) = 0 ;
	virtual int __fastcall HiddenCount();
	virtual int __fastcall FilteredCount();
	
public:
	__property int DriveType = {read=FDriveType, nodefault};
	__property Customdriveview::TCustomDriveView* DriveView = {read=FDriveView, write=FDriveView};
	__property Columns = {stored=false};
	__property _di_IShellFolder ParentFolder = {read=FParentFolder};
	DYNAMIC void __fastcall EmptyClipboard();
	bool __fastcall CopyToClipBoard(bool Focused);
	bool __fastcall CutToClipBoard(bool Focused);
	virtual bool __fastcall PasteFromClipBoard(System::UnicodeString TargetPath = System::UnicodeString());
	virtual void __fastcall DisplayPropertiesMenu();
	virtual void __fastcall DisplayContextMenu(const Winapi::Windows::TPoint &Where);
	virtual void __fastcall ExecuteParentDirectory();
	virtual void __fastcall ExecuteRootDirectory();
	virtual bool __fastcall ItemIsDirectory(Vcl::Comctrls::TListItem* Item);
	virtual System::UnicodeString __fastcall ItemFullFileName(Vcl::Comctrls::TListItem* Item);
	virtual bool __fastcall ItemIsParentDirectory(Vcl::Comctrls::TListItem* Item);
	virtual System::UnicodeString __fastcall ItemFileName(Vcl::Comctrls::TListItem* Item);
	virtual __int64 __fastcall ItemFileSize(Vcl::Comctrls::TListItem* Item);
	virtual System::TDateTime __fastcall ItemFileTime(Vcl::Comctrls::TListItem* Item, Baseutils::TDateTimePrecision &Precision);
	virtual void __fastcall SetItemCalculatedSize(Vcl::Comctrls::TListItem* Item, __int64 ASize);
	void __fastcall OpenFallbackPath(System::UnicodeString Value);
	void __fastcall StartWatchThread();
	void __fastcall StopWatchThread();
	bool __fastcall WatchThreadActive();
	void __fastcall StartIconUpdateThread();
	void __fastcall StopIconUpdateThread();
	void __fastcall TerminateThreads();
	virtual void __fastcall CreateDir(System::UnicodeString DirName);
	void __fastcall ValidateFile(Vcl::Comctrls::TListItem* Item)/* overload */;
	void __fastcall ValidateFile(System::Sysutils::TFileName FileName)/* overload */;
	DYNAMIC void __fastcall ValidateSelectedFiles();
	HIDESBASE Vcl::Comctrls::TListItem* __fastcall AddItem(const System::Sysutils::TSearchRec &SRec);
	void __fastcall GetDisplayData(Vcl::Comctrls::TListItem* Item, bool FetchIcon);
	PFileRec __fastcall GetFileRec(int Index);
	virtual void __fastcall Reload(bool CacheIcons);
	void __fastcall Reload2();
	virtual System::UnicodeString __fastcall GetAttrString(int Attr);
	__fastcall virtual TDirViewInt(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDirViewInt();
	virtual void __fastcall ExecuteHomeDirectory();
	virtual void __fastcall ReloadDirectory();
	void __fastcall ExecuteDrive(System::UnicodeString Drive);
	__property System::UnicodeString HomeDirectory = {read=GetHomeDirectory, write=FHomeDirectory};
	__property bool TimeoutShellIconRetrieval = {read=FTimeoutShellIconRetrieval, write=FTimeoutShellIconRetrieval, nodefault};
	__property bool AnyCut = {read=FAnyCut, nodefault};
	
__published:
	__property Dirviewcolproperties::TDirViewColProperties* DirColProperties = {read=GetDirColProperties, write=SetDirColProperties};
	__property PathLabel;
	__property OnUpdateStatusBar;
	__property DimmHiddenFiles = {default=1};
	__property ShowHiddenFiles = {default=1};
	__property TargetPopupMenu = {default=1};
	__property AddParentDir = {default=0};
	__property OnSelectItem;
	__property OnStartLoading;
	__property OnLoaded;
	__property OnDDDragEnter;
	__property OnDDDragLeave;
	__property OnDDDragOver;
	__property OnDDDrop;
	__property OnDDQueryContinueDrag;
	__property OnDDGiveFeedback;
	__property OnDDDragDetect;
	__property OnDDCreateDragFileList;
	__property OnDDEnd;
	__property OnDDCreateDataObject;
	__property OnDDTargetHasDropHandler;
	__property DDLinkOnExeDrag = {default=1};
	__property OnDDProcessDropped;
	__property OnDDError;
	__property OnDDExecuted;
	__property OnDDFileOperation;
	__property OnDDFileOperationExecuted;
	__property OnExecFile;
	__property OnMatchMask;
	__property OnGetOverlay;
	__property OnGetItemColor;
	__property bool ConfirmDelete = {read=FConfirmDelete, write=FConfirmDelete, default=1};
	__property bool ConfirmOverwrite = {read=FConfirmOverwrite, write=FConfirmOverwrite, default=1};
	__property unsigned ChangeInterval = {read=FChangeInterval, write=SetChangeInterval, default=1000};
	__property bool UseIconUpdateThread = {read=FUseIconUpdateThread, write=FUseIconUpdateThread, default=0};
	__property WatchForChanges = {default=0};
	__property TDirViewFileIconForName OnFileIconForName = {read=FOnFileIconForName, write=FOnFileIconForName};
	__property UseSystemContextMenu = {default=1};
	__property OnContextPopup;
	__property OnHistoryChange;
	__property OnHistoryGo;
	__property OnPathChange;
	__property OnBusy;
	__property OnChangeFocus;
	__property ColumnClick = {default=1};
	__property MultiSelect = {default=1};
	__property ReadOnly = {default=0};
	__property DirViewStyle;
	__property Items;
public:
	/* TWinControl.CreateParented */ inline __fastcall TDirViewInt(HWND ParentWindow) : Customdirview::TCustomDirView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 msThreadChangeDelay = System::Int8(0xa);
static _DELPHI_CONST System::Int8 MaxWaitTimeOut = System::Int8(0xa);
static _DELPHI_CONST System::Word FileAttr = System::Word(0x1f7);
#define SpecialExtensions L"EXE,LNK,ICO,ANI,CUR,PIF,JOB,CPL"
#define ExeExtension L"EXE"
extern DELPHI_PACKAGE bool __fastcall MatchesFileExt(System::UnicodeString Ext, const System::UnicodeString FileExtList);
extern DELPHI_PACKAGE bool __fastcall DropLink(Dragdropfilesex::PFDDListItem Item, System::UnicodeString TargetPath);
extern DELPHI_PACKAGE bool __fastcall DropFiles(Customdirview::TCustomizableDragDropFilesEx* DragDropFilesEx, int Effect, Fileoperator::TFileOperator* FileOperator, System::UnicodeString TargetPath, bool IsRecycleBin, bool ConfirmDelete, bool ConfirmOverwrite, System::TObject* Sender, Customdirview::TDDFileOperationEvent OnDDFileOperation, /* out */ System::UnicodeString &SourcePath, /* out */ bool &SourceIsDirectory);
extern DELPHI_PACKAGE void __fastcall CheckCanOpenDirectory(System::UnicodeString Path);
}	/* namespace Dirviewint */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DIRVIEWINT)
using namespace Dirviewint;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DirViewIntHPP
