// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CustomDirView.pas' rev: 37.00 (Windows)

#ifndef CustomDirViewHPP
#define CustomDirViewHPP

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
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Winapi.ShellAPI.hpp>
#include <System.Win.ComObj.hpp>
#include <Winapi.ShlObj.hpp>
#include <Vcl.Dialogs.hpp>
#include <Winapi.ActiveX.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.FileCtrl.hpp>
#include <PIDL.hpp>
#include <BaseUtils.hpp>
#include <DragDrop.hpp>
#include <DragDropFilesEx.hpp>
#include <IEDriveInfoInt.hpp>
#include <IEListView.hpp>
#include <PathLabel.hpp>
#include <System.SysUtils.hpp>
#include <PasTools.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>
#include <NortonLikeListView.hpp>

//-- user supplied -----------------------------------------------------------

namespace Customdirview
{
//-- forward type declarations -----------------------------------------------
struct TStatusFileInfo;
__interface DELPHIINTERFACE TBusyOperation;
typedef System::DelphiInterface<TBusyOperation> _di_TBusyOperation;
struct TFileFilter;
struct TWMXMouse;
class DELPHICLASS TCustomizableDragDropFilesEx;
class DELPHICLASS TCustomDirView;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TStatusFileInfo
{
public:
	int FilesCount;
	int SelectedCount;
	__int64 FilesSize;
	__int64 SelectedSize;
	int HiddenCount;
	int FilteredCount;
};


enum DECLSPEC_DENUM TDDError : unsigned char { DDCreateShortCutError, DDPathNotFoundError };

typedef void __fastcall (__closure *TDDOnDragEnter)(System::TObject* Sender, Dragdrop::IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect, bool &Accept);

typedef void __fastcall (__closure *TDDOnDragLeave)(System::TObject* Sender);

typedef void __fastcall (__closure *TDDOnDragOver)(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect);

typedef void __fastcall (__closure *TDDOnDrop)(System::TObject* Sender, Dragdrop::IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect);

typedef void __fastcall (__closure *TDDOnQueryContinueDrag)(System::TObject* Sender, System::LongBool FEscapePressed, System::LongInt grfKeyState, HRESULT &Result);

typedef void __fastcall (__closure *TDDOnGiveFeedback)(System::TObject* Sender, System::LongInt dwEffect, HRESULT &Result);

typedef void __fastcall (__closure *TDDOnChooseEffect)(System::TObject* Sender, System::LongInt grfKeyState, System::LongInt &dwEffect);

typedef void __fastcall (__closure *TDDOnDragDetect)(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &DetectStart, const Winapi::Windows::TPoint &Point, Dragdrop::TDragDetectStatus DragStatus);

typedef void __fastcall (__closure *TDDOnCreateDragFileList)(System::TObject* Sender, Dragdropfilesex::TFileList* FileList, bool &Created);

typedef void __fastcall (__closure *TDDOnCreateDataObject)(System::TObject* Sender, Dragdrop::TDataObject* &DataObject);

typedef void __fastcall (__closure *TDDOnTargetHasDropHandler)(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, int &Effect, bool &DropHandler);

typedef void __fastcall (__closure *TOnProcessDropped)(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect);

typedef void __fastcall (__closure *TDDErrorEvent)(System::TObject* Sender, TDDError ErrorNo);

typedef void __fastcall (__closure *TDDExecutedEvent)(System::TObject* Sender, System::LongInt dwEffect);

typedef void __fastcall (__closure *TDDFileOperationEvent)(System::TObject* Sender, System::LongInt dwEffect, System::UnicodeString SourcePath, System::UnicodeString TargetPath, bool Paste, bool &DoOperation);

typedef void __fastcall (__closure *TDDFileOperationExecutedEvent)(System::TObject* Sender, System::LongInt dwEffect, System::UnicodeString SourcePath, System::UnicodeString TargetPath);

typedef void __fastcall (__closure *TDirViewExecFileEvent)(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool &AllowExec);

typedef void __fastcall (__closure *TMatchMaskEvent)(System::TObject* Sender, System::UnicodeString FileName, bool Directory, __int64 Size, System::TDateTime Modification, System::UnicodeString Masks, bool &Matches, bool AllowImplicitMatches);

typedef void __fastcall (__closure *TDirViewGetOverlayEvent)(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, System::Word &Indexes);

typedef void __fastcall (__closure *TDirViewGetItemColorEvent)(System::TObject* Sender, System::UnicodeString FileName, bool Directory, __int64 Size, System::TDateTime Modification, System::Uitypes::TColor &Color);

typedef void __fastcall (__closure *TDirViewUpdateStatusBarEvent)(System::TObject* Sender, const TStatusFileInfo &FileInfo);

typedef void __fastcall (__closure *TDirViewBusy)(System::TObject* Sender, int Busy, bool &State);

typedef void __fastcall (__closure *TDirViewChangeFocusEvent)(System::TObject* Sender, Vcl::Comctrls::TListItem* Item);

__interface TBusyOperation  : public System::IInterface 
{
	virtual void __fastcall Invoke() = 0 ;
};

enum DECLSPEC_DENUM TSelAttr : unsigned char { selDontCare, selYes, selNo };

struct DECLSPEC_DRECORD TFileFilter
{
public:
	System::UnicodeString Masks;
	bool Directories;
};


typedef void __fastcall (__closure *TDirViewNotifyEvent)(TCustomDirView* Sender);

typedef void __fastcall (__closure *TDVGetFilterEvent)(TCustomDirView* Sender, bool Select, TFileFilter &Filter);

typedef void __fastcall (__closure *TDVHistoryGoEvent)(TCustomDirView* Sender, int Index, bool &Cancel);

enum DECLSPEC_DENUM TCompareCriteria : unsigned char { ccTime, ccSize };

typedef System::Set<TCompareCriteria, TCompareCriteria::ccTime, TCompareCriteria::ccSize> TCompareCriterias;

enum DECLSPEC_DENUM TDirViewStyle : unsigned char { dvsIcon, dvsSmallIcon, dvsList, dvsReport, dvsThumbnail };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TWMXMouse
{
public:
	unsigned Msg;
	System::Word Keys;
	System::Word Button;
	System::Types::TSmallPoint Pos;
	System::LongInt Result;
};
#pragma pack(pop)


class PASCALIMPLEMENTATION TCustomizableDragDropFilesEx : public Dragdropfilesex::TDragDropFilesEx
{
	typedef Dragdropfilesex::TDragDropFilesEx inherited;
	
public:
	HIDESBASE Dragdrop::TDragResult __fastcall Execute(Dragdrop::TDataObject* DataObject);
public:
	/* TDragDropFilesEx.Create */ inline __fastcall virtual TCustomizableDragDropFilesEx(System::Classes::TComponent* AOwner) : Dragdropfilesex::TDragDropFilesEx(AOwner) { }
	/* TDragDropFilesEx.Destroy */ inline __fastcall virtual ~TCustomizableDragDropFilesEx() { }
	
};


typedef int __stdcall (*TListViewCompare)(int lParam1, int lParam2, int lParamSort);

class PASCALIMPLEMENTATION TCustomDirView : public Ielistview::TCustomIEListView
{
	typedef Ielistview::TCustomIEListView inherited;
	
private:
	bool FAddParentDir;
	bool FDimmHiddenFiles;
	Baseutils::TFormatBytesStyle FFormatSizeBytes;
	TCustomizableDragDropFilesEx* FDragDropFilesEx;
	bool FUseSystemContextMenu;
	System::Classes::TNotifyEvent FOnStartLoading;
	System::Classes::TNotifyEvent FOnLoaded;
	bool FExeDrag;
	bool FDDLinkOnExeDrag;
	TDDOnDragEnter FOnDDDragEnter;
	TDDOnDragLeave FOnDDDragLeave;
	TDDOnDragOver FOnDDDragOver;
	TDDOnDrop FOnDDDrop;
	TDDOnQueryContinueDrag FOnDDQueryContinueDrag;
	TDDOnGiveFeedback FOnDDGiveFeedback;
	TDDOnChooseEffect FOnDDChooseEffect;
	TDDOnDragDetect FOnDDDragDetect;
	TDDOnCreateDragFileList FOnDDCreateDragFileList;
	TOnProcessDropped FOnDDProcessDropped;
	TDDErrorEvent FOnDDError;
	TDDExecutedEvent FOnDDExecuted;
	TDDFileOperationEvent FOnDDFileOperation;
	TDDFileOperationExecutedEvent FOnDDFileOperationExecuted;
	System::Classes::TNotifyEvent FOnDDEnd;
	TDDOnCreateDataObject FOnDDCreateDataObject;
	TDDOnTargetHasDropHandler FOnDDTargetHasDropHandler;
	TDirViewExecFileEvent FOnExecFile;
	bool FForceRename;
	Dragdrop::TDragResult FLastDDResult;
	System::UnicodeString FLastRenameName;
	bool FContextMenu;
	bool FDragEnabled;
	Winapi::Windows::TPoint FStartPos;
	bool FDDOwnerIsSource;
	bool FAbortLoading;
	int FBackCount;
	bool FDontRecordPath;
	bool FDragOnDriveIsMove;
	bool FNotifyEnabled;
	Winapi::Windows::TFileTime FDragStartTime;
	System::Classes::TStrings* FHistoryPaths;
	Vcl::Controls::TImageList* FOverlaySmallImages;
	Vcl::Controls::TImageList* FOverlayLargeImages;
	Vcl::Controls::TImageList* FThumbnailShellImages;
	Vcl::Controls::TImageList* FThumbnailImages;
	int FMaxHistoryCount;
	Pathlabel::TCustomPathLabel* FPathLabel;
	TDirViewUpdateStatusBarEvent FOnUpdateStatusBar;
	TDirViewNotifyEvent FOnHistoryChange;
	TDVHistoryGoEvent FOnHistoryGo;
	TDirViewNotifyEvent FOnPathChange;
	bool FShowHiddenFiles;
	bool FSavedSelection;
	System::UnicodeString FSavedSelectionFile;
	System::UnicodeString FSavedSelectionLastFile;
	System::Classes::TStringList* FSavedNames;
	int FPendingFocusSomething;
	TMatchMaskEvent FOnMatchMask;
	TDirViewGetOverlayEvent FOnGetOverlay;
	TDirViewGetItemColorEvent FOnGetItemColor;
	System::UnicodeString FMask;
	bool FNaturalOrderNumericalSorting;
	bool FAlwaysSortDirectoriesByName;
	Pastools::TListViewScrollOnDragOver* FScrollOnDragOver;
	TStatusFileInfo FStatusFileInfo;
	TDirViewBusy FOnBusy;
	TDirViewChangeFocusEvent FOnChangeFocus;
	System::StaticArray<Vcl::Graphics::TBitmap*, 2> FFallbackThumbnail;
	System::Types::TSize FFallbackThumbnailSize;
	int FRecreatingWnd;
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMLButtonDblClk &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMLButtonUp &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMLButtonDown &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonDown(Winapi::Messages::TWMRButtonDown &Message);
	MESSAGE void __fastcall WMXButtonUp(TWMXMouse &Message);
	MESSAGE void __fastcall WMAppCommand(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall LVMSetExtendedListViewStyle(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMRecreateWnd(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMDPIChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKeyDown &Message);
	MESSAGE void __fastcall WMUserInvalidateItem(Winapi::Messages::TMessage &Message);
	void __fastcall DumbCustomDrawItem(Vcl::Comctrls::TCustomListView* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	void __fastcall DumbCustomDrawSubItem(Vcl::Comctrls::TCustomListView* Sender, Vcl::Comctrls::TListItem* Item, int SubItem, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	__int64 __fastcall GetFilesMarkedSize();
	int __fastcall GetForwardCount();
	System::UnicodeString __fastcall GetHistoryPath(int Index);
	bool __fastcall GetSelectedNamesSaved();
	TDirViewStyle __fastcall GetDirViewStyle();
	void __fastcall SetDirViewStyle(TDirViewStyle Value);
	void __fastcall ViewStyleChanged();
	bool __fastcall GetTargetPopupMenu();
	void __fastcall SetMaxHistoryCount(int Value);
	void __fastcall SetPathLabel(Pathlabel::TCustomPathLabel* Value);
	void __fastcall SetTargetPopupMenu(bool Value);
	MESSAGE void __fastcall WMUserRename(Winapi::Messages::TMessage &Message);
	void __fastcall ClearItemsStats();
	
protected:
	bool FCaseSensitive;
	bool FDirty;
	__int64 FFilesSize;
	__int64 FFilesSelSize;
	int FFilesSelected;
	bool FHasParentDir;
	bool FIsRecycleBin;
	System::UnicodeString FLastPath;
	System::UnicodeString FHistoryPath;
	bool FLoadEnabled;
	bool FLoading;
	System::UnicodeString FSelectFile;
	bool FPreserveShownItemOffset;
	bool FWatchForChanges;
	System::UnicodeString FInvalidNameChars;
	System::UnicodeString FDragDrive;
	System::TObject* FAnnouncedState;
	bool FThumbnail;
	System::UnicodeString FEffectiveMask;
	virtual void __fastcall AddToDragFileList(Dragdropfilesex::TFileList* FileList, Vcl::Comctrls::TListItem* Item);
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TListItem* Item);
	virtual bool __fastcall CanChangeSelection(Vcl::Comctrls::TListItem* Item, bool Select);
	void __fastcall CancelEdit();
	virtual void __fastcall ClearItems();
	virtual bool __fastcall GetDirOK() = 0 ;
	virtual void __fastcall DDDragDetect(System::LongInt grfKeyState, const Winapi::Windows::TPoint &DetectStart, const Winapi::Windows::TPoint &Point, Dragdrop::TDragDetectStatus DragStatus);
	void __fastcall DDDragEnter(Dragdrop::IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect, bool &Accept);
	void __fastcall DDDragLeave(int Dummy);
	void __fastcall DDDragOver(System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect, System::LongInt PreferredEffect);
	virtual void __fastcall DDChooseEffect(int grfKeyState, int &dwEffect, int PreferredEffect);
	void __fastcall DDDrop(Dragdrop::IDataObject DataObj, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt &dwEffect);
	virtual void __fastcall DDDropHandlerSucceeded(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt dwEffect);
	virtual void __fastcall DDGiveFeedback(System::LongInt dwEffect, HRESULT &Result);
	virtual void __fastcall DDMenuPopup(System::TObject* Sender, HMENU AMenu, Dragdrop::IDataObject DataObj, int AMinCustCmd, System::LongInt grfKeyState, const Winapi::Windows::TPoint &pt);
	virtual void __fastcall DDMenuDone(System::TObject* Sender, HMENU AMenu);
	void __fastcall DDProcessDropped(System::TObject* Sender, System::LongInt grfKeyState, const Winapi::Windows::TPoint &Point, System::LongInt dwEffect);
	virtual void __fastcall DDQueryContinueDrag(System::LongBool FEscapePressed, System::LongInt grfKeyState, HRESULT &Result);
	virtual void __fastcall DDSpecifyDropTarget(System::TObject* Sender, bool DragDropHandler, const Winapi::Windows::TPoint &Point, Dragdropfilesex::PItemIDList &pidlFQ, System::UnicodeString &Filename);
	virtual void __fastcall GetDisplayInfo(Vcl::Comctrls::TListItem* ListItem, Winapi::Commctrl::TLVItem &DispInfo);
	virtual Dragdrop::TDropEffectSet __fastcall GetDragSourceEffects();
	virtual System::UnicodeString __fastcall GetPathName() = 0 ;
	virtual int __fastcall GetFilesCount();
	DYNAMIC void __fastcall ColClick(Vcl::Comctrls::TListColumn* Column);
	virtual void __fastcall CreateWnd();
	virtual void __fastcall DestroyWnd();
	bool __fastcall OperateOnFocusedFile(bool Focused, bool OnlyFocused = false);
	System::Classes::TStrings* __fastcall CustomCreateFileList(bool Focused, bool OnlyFocused, bool FullPath, System::Classes::TStrings* FileList = (System::Classes::TStrings*)(0x0), bool ItemObject = false);
	virtual bool __fastcall CustomDrawItem(Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TCustomDrawState State, Vcl::Comctrls::TCustomDrawStage Stage);
	virtual bool __fastcall CustomDrawSubItem(Vcl::Comctrls::TListItem* Item, int SubItem, Vcl::Comctrls::TCustomDrawState State, Vcl::Comctrls::TCustomDrawStage Stage);
	void __fastcall CustomSortItems(TListViewCompare SortProc);
	DYNAMIC void __fastcall Delete(Vcl::Comctrls::TListItem* Item);
	DYNAMIC void __fastcall DoHistoryChange();
	virtual bool __fastcall DragCompleteFileList();
	DYNAMIC void __fastcall Edit(const Winapi::Commctrl::TLVItem &HItem);
	virtual void __fastcall EndSelectionUpdate();
	virtual bool __fastcall DoExecFile(Vcl::Comctrls::TListItem* Item, bool ForceEnter);
	virtual void __fastcall Execute(Vcl::Comctrls::TListItem* Item, bool ForceEnter);
	virtual void __fastcall ExecuteFile(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual void __fastcall FocusSomething(bool ForceMakeVisible);
	virtual bool __fastcall GetIsRoot() = 0 ;
	virtual bool __fastcall ItemCanDrag(Vcl::Comctrls::TListItem* Item);
	System::Uitypes::TColor __fastcall DoItemColor(Vcl::Comctrls::TListItem* Item);
	virtual System::Uitypes::TColor __fastcall ItemColor(Vcl::Comctrls::TListItem* Item);
	virtual int __fastcall ItemImageIndex(Vcl::Comctrls::TListItem* Item, bool Cache) = 0 ;
	virtual Vcl::Graphics::TBitmap* __fastcall ItemThumbnail(Vcl::Comctrls::TListItem* Item, const System::Types::TSize &Size);
	void __fastcall FreeThumbnails();
	Vcl::Graphics::TBitmap* __fastcall FallbackThumbnail(bool Dir, const System::Types::TSize &Size);
	void __fastcall DrawThumbnail(Vcl::Comctrls::TListItem* Item, HDC DC);
	virtual bool __fastcall ItemIsRecycleBin(Vcl::Comctrls::TListItem* Item);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LoadFiles() = 0 ;
	virtual void __fastcall PerformItemDragDropOperation(Vcl::Comctrls::TListItem* Item, int Effect, bool Paste) = 0 ;
	void __fastcall ProcessChangedFiles(TCustomDirView* DirView, System::Classes::TStrings* FileList, bool FullPath, bool ExistingOnly, TCompareCriterias Criterias);
	void __fastcall ReloadForce(bool CacheIcons);
	void __fastcall RetryRename(System::UnicodeString NewName);
	virtual void __fastcall SetAddParentDir(bool Value);
	virtual void __fastcall SetDimmHiddenFiles(bool Value);
	virtual void __fastcall SetItemImageIndex(Vcl::Comctrls::TListItem* Item, int Index) = 0 ;
	virtual void __fastcall SetLoadEnabled(bool Enabled);
	virtual void __fastcall SetMultiSelect(bool Value);
	virtual System::UnicodeString __fastcall GetPath() = 0 ;
	virtual bool __fastcall GetValid();
	virtual void __fastcall InternalEdit(const Winapi::Commctrl::TLVItem &HItem) = 0 ;
	virtual bool __fastcall ItemIsFile(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual bool __fastcall ItemMatchesFilter(Vcl::Comctrls::TListItem* Item, const TFileFilter &Filter) = 0 ;
	virtual System::Word __fastcall ItemOverlayIndexes(Vcl::Comctrls::TListItem* Item);
	void __fastcall LimitHistorySize();
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PathChanged();
	void __fastcall PathChanging(bool Relative);
	virtual void __fastcall SetPath(System::UnicodeString Value) = 0 ;
	virtual void __fastcall SetShowHiddenFiles(bool Value);
	void __fastcall SetFormatSizeBytes(Baseutils::TFormatBytesStyle Value);
	virtual void __fastcall SetViewStyle(Vcl::Comctrls::TViewStyle Value);
	virtual void __fastcall SetWatchForChanges(bool Value);
	virtual bool __fastcall TargetHasDropHandler(Vcl::Comctrls::TListItem* Item, int Effect);
	DYNAMIC void __fastcall UpdatePathLabel();
	DYNAMIC void __fastcall UpdatePathLabelCaption();
	bool __fastcall FileNameMatchesMasks(System::UnicodeString FileName, bool Directory, __int64 Size, System::TDateTime Modification, System::UnicodeString Masks, bool AllowImplicitMatches);
	virtual bool __fastcall EnableDragOnClick();
	virtual void __fastcall SetMask(System::UnicodeString Value);
	void __fastcall SetNaturalOrderNumericalSorting(bool Value);
	void __fastcall SetAlwaysSortDirectoriesByName(bool Value);
	void __fastcall DoHistoryGo(int Index);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	void __fastcall EnsureSelectionRedrawn();
	virtual int __fastcall HiddenCount() = 0 ;
	virtual int __fastcall FilteredCount() = 0 ;
	bool __fastcall DoBusy(int Busy);
	bool __fastcall StartBusy();
	void __fastcall EndBusy();
	bool __fastcall IsBusy();
	void __fastcall BusyOperation(_di_TBusyOperation Operation);
	void __fastcall DoDisplayPropertiesMenu();
	void __fastcall DoExecute(Vcl::Comctrls::TListItem* Item, bool ForceEnter);
	void __fastcall DoExecuteParentDirectory();
	virtual void __fastcall Load(bool DoFocusSomething);
	Vcl::Controls::TImageList* __fastcall NeedImageList(Pastools::TImageListSize Size, bool Recreate, Vcl::Controls::TImageList* &OverlayImages);
	void __fastcall NeedImageLists(bool Recreate);
	void __fastcall FreeImageLists();
	void __fastcall DoUpdateStatusBar(bool Force = false);
	void __fastcall DoCustomDrawItem(Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TCustomDrawStage Stage);
	void __fastcall ItemCalculatedSizeUpdated(Vcl::Comctrls::TListItem* Item, __int64 OldSize, __int64 NewSize);
	void __fastcall SaveItemsState(System::UnicodeString &FocusedItem, bool &FocusedShown, int &ShownItemOffset);
	void __fastcall RestoreItemsState(Vcl::Comctrls::TListItem* ItemToFocus, bool FocusedShown, int ShownItemOffset)/* overload */;
	void __fastcall RestoreItemsState(System::TObject* AState)/* overload */;
	Vcl::Comctrls::TListItem* __fastcall FindFileItemIfNotEmpty(System::UnicodeString FileName);
	
public:
	__fastcall virtual TCustomDirView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDirView();
	virtual void __fastcall Reload(bool CacheIcons);
	System::Classes::TStrings* __fastcall CreateFocusedFileList(bool FullPath, System::Classes::TStrings* FileList = (System::Classes::TStrings*)(0x0));
	System::Classes::TStrings* __fastcall CreateFileList(bool Focused, bool FullPath, System::Classes::TStrings* FileList = (System::Classes::TStrings*)(0x0), bool ItemObject = false);
	bool __fastcall AnyFileSelected(bool OnlyFocused, bool FilesOnly, bool FocusedFileOnlyWhenFocused);
	void __fastcall SelectFiles(const TFileFilter &Filter, bool Select);
	virtual void __fastcall ExecuteHomeDirectory() = 0 ;
	virtual void __fastcall ExecuteParentDirectory() = 0 ;
	virtual void __fastcall ExecuteRootDirectory() = 0 ;
	void __fastcall ExecuteCurrentFile();
	virtual void __fastcall CreateDir(System::UnicodeString DirName) = 0 ;
	Vcl::Comctrls::TListItem* __fastcall FindFileItem(System::UnicodeString FileName);
	void __fastcall HistoryGo(int Index);
	virtual bool __fastcall ItemIsDirectory(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual bool __fastcall ItemIsParentDirectory(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual System::UnicodeString __fastcall ItemFullFileName(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual System::UnicodeString __fastcall ItemFileName(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual __int64 __fastcall ItemFileSize(Vcl::Comctrls::TListItem* Item) = 0 ;
	virtual System::TDateTime __fastcall ItemFileTime(Vcl::Comctrls::TListItem* Item, Baseutils::TDateTimePrecision &Precision) = 0 ;
	virtual System::TObject* __fastcall ItemData(Vcl::Comctrls::TListItem* Item);
	virtual void __fastcall SetItemCalculatedSize(Vcl::Comctrls::TListItem* Item, __int64 Size) = 0 ;
	virtual void __fastcall ReloadDirectory() = 0 ;
	virtual void __fastcall DisplayPropertiesMenu() = 0 ;
	System::Classes::TStrings* __fastcall CreateChangedFileList(TCustomDirView* DirView, bool FullPath, bool ExistingOnly, TCompareCriterias Criterias);
	virtual void __fastcall CompareFiles(TCustomDirView* DirView, bool ExistingOnly, TCompareCriterias Criterias);
	System::UnicodeString __fastcall GetColumnText(Vcl::Comctrls::TListItem* ListItem, int Index);
	void __fastcall SaveSelection();
	void __fastcall RestoreSelection();
	void __fastcall DiscardSavedSelection();
	void __fastcall SaveSelectedNames();
	void __fastcall RestoreSelectedNames();
	void __fastcall ContinueSession(bool Continue);
	DYNAMIC bool __fastcall CanPasteFromClipBoard();
	virtual bool __fastcall PasteFromClipBoard(System::UnicodeString TargetPath = System::UnicodeString()) = 0 ;
	virtual System::TObject* __fastcall SaveState();
	virtual void __fastcall RestoreState(System::TObject* AState);
	virtual void __fastcall AnnounceState(System::TObject* AState);
	void __fastcall FocusByName(System::UnicodeString FileName);
	virtual void __fastcall DisplayContextMenu(const Winapi::Windows::TPoint &Where) = 0 ;
	void __fastcall DisplayContextMenuInSitu();
	void __fastcall UpdateStatusBar();
	void __fastcall InvalidateItem(Vcl::Comctrls::TListItem* Item);
	__property bool AddParentDir = {read=FAddParentDir, write=SetAddParentDir, default=0};
	__property bool DimmHiddenFiles = {read=FDimmHiddenFiles, write=SetDimmHiddenFiles, default=1};
	__property TCustomizableDragDropFilesEx* DragDropFilesEx = {read=FDragDropFilesEx};
	__property Baseutils::TFormatBytesStyle FormatSizeBytes = {read=FFormatSizeBytes, write=SetFormatSizeBytes, default=0};
	__property FullDrag = {default=1};
	__property bool TargetPopupMenu = {read=GetTargetPopupMenu, write=SetTargetPopupMenu, default=1};
	__property bool DDOwnerIsSource = {read=FDDOwnerIsSource, nodefault};
	__property __int64 FilesSize = {read=FFilesSize};
	__property __int64 FilesSelSize = {read=FFilesSelSize};
	__property int FilesCount = {read=GetFilesCount, nodefault};
	__property __int64 FilesMarkedSize = {read=GetFilesMarkedSize};
	__property bool HasParentDir = {read=FHasParentDir, nodefault};
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
	__property System::UnicodeString PathName = {read=GetPathName};
	__property bool UseSystemContextMenu = {read=FUseSystemContextMenu, write=FUseSystemContextMenu, default=1};
	__property bool Loading = {read=FLoading, nodefault};
	__property bool AbortLoading = {read=FAbortLoading, write=FAbortLoading, stored=false, nodefault};
	__property int BackCount = {read=FBackCount, nodefault};
	__property bool LoadEnabled = {read=FLoadEnabled, write=SetLoadEnabled, default=1};
	__property bool Dirty = {read=FDirty, nodefault};
	__property bool DirOK = {read=GetDirOK, nodefault};
	__property System::UnicodeString LastPath = {read=FLastPath};
	__property bool IsRecycleBin = {read=FIsRecycleBin, nodefault};
	__property bool DDLinkOnExeDrag = {read=FDDLinkOnExeDrag, write=FDDLinkOnExeDrag, default=0};
	__property bool DragOnDriveIsMove = {read=FDragOnDriveIsMove, write=FDragOnDriveIsMove, nodefault};
	__property Dragdrop::TDropEffectSet DragSourceEffects = {read=GetDragSourceEffects, nodefault};
	__property bool ExeDrag = {read=FExeDrag, nodefault};
	__property int ForwardCount = {read=GetForwardCount, nodefault};
	__property System::UnicodeString HistoryPath[int Index] = {read=GetHistoryPath};
	__property bool IsRoot = {read=GetIsRoot, nodefault};
	__property Dragdrop::TDragResult LastDDResult = {read=FLastDDResult, nodefault};
	__property SmallImages;
	__property LargeImages;
	__property int MaxHistoryCount = {read=FMaxHistoryCount, write=SetMaxHistoryCount, default=200};
	__property bool SelectedNamesSaved = {read=GetSelectedNamesSaved, nodefault};
	__property System::UnicodeString Mask = {read=FMask, write=SetMask};
	__property bool NaturalOrderNumericalSorting = {read=FNaturalOrderNumericalSorting, write=SetNaturalOrderNumericalSorting, nodefault};
	__property bool AlwaysSortDirectoriesByName = {read=FAlwaysSortDirectoriesByName, write=SetAlwaysSortDirectoriesByName, nodefault};
	__property TDirViewStyle DirViewStyle = {read=GetDirViewStyle, write=SetDirViewStyle, nodefault};
	__property OnContextPopup;
	__property System::Classes::TNotifyEvent OnStartLoading = {read=FOnStartLoading, write=FOnStartLoading};
	__property System::Classes::TNotifyEvent OnLoaded = {read=FOnLoaded, write=FOnLoaded};
	__property TDDOnDragEnter OnDDDragEnter = {read=FOnDDDragEnter, write=FOnDDDragEnter};
	__property TDDOnDragLeave OnDDDragLeave = {read=FOnDDDragLeave, write=FOnDDDragLeave};
	__property TDDOnDragOver OnDDDragOver = {read=FOnDDDragOver, write=FOnDDDragOver};
	__property TDDOnDrop OnDDDrop = {read=FOnDDDrop, write=FOnDDDrop};
	__property TDDOnQueryContinueDrag OnDDQueryContinueDrag = {read=FOnDDQueryContinueDrag, write=FOnDDQueryContinueDrag};
	__property TDDOnGiveFeedback OnDDGiveFeedback = {read=FOnDDGiveFeedback, write=FOnDDGiveFeedback};
	__property TDDOnChooseEffect OnDDChooseEffect = {read=FOnDDChooseEffect, write=FOnDDChooseEffect};
	__property TDDOnDragDetect OnDDDragDetect = {read=FOnDDDragDetect, write=FOnDDDragDetect};
	__property TDDOnCreateDragFileList OnDDCreateDragFileList = {read=FOnDDCreateDragFileList, write=FOnDDCreateDragFileList};
	__property System::Classes::TNotifyEvent OnDDEnd = {read=FOnDDEnd, write=FOnDDEnd};
	__property TDDOnCreateDataObject OnDDCreateDataObject = {read=FOnDDCreateDataObject, write=FOnDDCreateDataObject};
	__property TDDOnTargetHasDropHandler OnDDTargetHasDropHandler = {read=FOnDDTargetHasDropHandler, write=FOnDDTargetHasDropHandler};
	__property TOnProcessDropped OnDDProcessDropped = {read=FOnDDProcessDropped, write=FOnDDProcessDropped};
	__property TDDErrorEvent OnDDError = {read=FOnDDError, write=FOnDDError};
	__property TDDExecutedEvent OnDDExecuted = {read=FOnDDExecuted, write=FOnDDExecuted};
	__property TDDFileOperationEvent OnDDFileOperation = {read=FOnDDFileOperation, write=FOnDDFileOperation};
	__property TDDFileOperationExecutedEvent OnDDFileOperationExecuted = {read=FOnDDFileOperationExecuted, write=FOnDDFileOperationExecuted};
	__property TDirViewExecFileEvent OnExecFile = {read=FOnExecFile, write=FOnExecFile};
	__property TDirViewNotifyEvent OnHistoryChange = {read=FOnHistoryChange, write=FOnHistoryChange};
	__property TDVHistoryGoEvent OnHistoryGo = {read=FOnHistoryGo, write=FOnHistoryGo};
	__property TDirViewNotifyEvent OnPathChange = {read=FOnPathChange, write=FOnPathChange};
	__property TMatchMaskEvent OnMatchMask = {read=FOnMatchMask, write=FOnMatchMask};
	__property TDirViewGetOverlayEvent OnGetOverlay = {read=FOnGetOverlay, write=FOnGetOverlay};
	__property TDirViewGetItemColorEvent OnGetItemColor = {read=FOnGetItemColor, write=FOnGetItemColor};
	__property Pathlabel::TCustomPathLabel* PathLabel = {read=FPathLabel, write=SetPathLabel};
	__property bool ShowHiddenFiles = {read=FShowHiddenFiles, write=SetShowHiddenFiles, default=1};
	__property TDirViewUpdateStatusBarEvent OnUpdateStatusBar = {read=FOnUpdateStatusBar, write=FOnUpdateStatusBar};
	__property TDirViewBusy OnBusy = {read=FOnBusy, write=FOnBusy};
	__property TDirViewChangeFocusEvent OnChangeFocus = {read=FOnChangeFocus, write=FOnChangeFocus};
	__property bool WatchForChanges = {read=FWatchForChanges, write=SetWatchForChanges, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomDirView(HWND ParentWindow) : Ielistview::TCustomIEListView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Uitypes::TColor clDefaultItemColor;
static _DELPHI_CONST System::Word WM_USER_RENAME = System::Word(0x439);
static _DELPHI_CONST System::Word WM_USER_INVALIDATEITEM = System::Word(0x2410);
static _DELPHI_CONST System::Int8 oiNoOverlay = System::Int8(0x0);
static _DELPHI_CONST System::Int8 oiDirUp = System::Int8(0x1);
static _DELPHI_CONST System::Int8 oiLink = System::Int8(0x2);
static _DELPHI_CONST System::Int8 oiBrokenLink = System::Int8(0x4);
static _DELPHI_CONST System::Int8 oiPartial = System::Int8(0x8);
static _DELPHI_CONST System::Int8 oiEncrypted = System::Int8(0x10);
static _DELPHI_CONST System::Byte DefaultHistoryCount = System::Byte(0xc8);
static _DELPHI_CONST int DDDragStartDelay = int(0x7a120);
static _DELPHI_CONST System::Int8 DirAttrMask = System::Int8(0x16);
static _DELPHI_CONST System::Int8 _XBUTTON1 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 _XBUTTON2 = System::Int8(0x2);
extern DELPHI_PACKAGE System::ResourceString _SErrorRenameFile;
#define Customdirview_SErrorRenameFile System::LoadResourceString(&Customdirview::_SErrorRenameFile)
extern DELPHI_PACKAGE System::ResourceString _SErrorRenameFileExists;
#define Customdirview_SErrorRenameFileExists System::LoadResourceString(&Customdirview::_SErrorRenameFileExists)
extern DELPHI_PACKAGE System::ResourceString _SErrorInvalidName;
#define Customdirview_SErrorInvalidName System::LoadResourceString(&Customdirview::_SErrorInvalidName)
extern DELPHI_PACKAGE System::ResourceString _STextFileExt;
#define Customdirview_STextFileExt System::LoadResourceString(&Customdirview::_STextFileExt)
extern DELPHI_PACKAGE System::ResourceString _SParentDir;
#define Customdirview_SParentDir System::LoadResourceString(&Customdirview::_SParentDir)
extern DELPHI_PACKAGE System::ResourceString _SDragDropError;
#define Customdirview_SDragDropError System::LoadResourceString(&Customdirview::_SDragDropError)
extern DELPHI_PACKAGE System::ResourceString _SDriveNotReady;
#define Customdirview_SDriveNotReady System::LoadResourceString(&Customdirview::_SDriveNotReady)
extern DELPHI_PACKAGE System::ResourceString _SDirNotExists;
#define Customdirview_SDirNotExists System::LoadResourceString(&Customdirview::_SDirNotExists)
extern DELPHI_PACKAGE int StdDirIcon;
extern DELPHI_PACKAGE int StdDirSelIcon;
extern DELPHI_PACKAGE System::TObject* DropSourceControl;
extern DELPHI_PACKAGE int UnknownFileIcon;
extern DELPHI_PACKAGE System::UnicodeString StdDirTypeName;
extern DELPHI_PACKAGE int DefaultExeIcon;
extern DELPHI_PACKAGE System::UnicodeString UserDocumentDirectory;
#define coInvalidDosChars L"\\/:*?\"<>|"
static _DELPHI_CONST System::WideChar Space = (System::WideChar)(0x20);
extern DELPHI_PACKAGE void __fastcall InitFileControls();
extern DELPHI_PACKAGE bool __fastcall IsExecutable(System::UnicodeString FileName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetNextMask(System::UnicodeString &Mask);
extern DELPHI_PACKAGE void __fastcall DefaultFileFilter(TFileFilter &Filter);
extern DELPHI_PACKAGE int __fastcall CompareLogicalTextPas(const System::UnicodeString S1, const System::UnicodeString S2, bool NaturalOrderNumericalSorting);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ResolveFileShortCut(System::UnicodeString SourceFile, bool ShowDialog = false);
extern DELPHI_PACKAGE bool __fastcall CreateFileShortCut(System::UnicodeString SourceFile, System::UnicodeString Target, System::UnicodeString DisplayName, bool UpdateIfExists = false);
extern DELPHI_PACKAGE Vcl::Controls::TImageList* __fastcall OverlayImageList(int Size);
}	/* namespace Customdirview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CUSTOMDIRVIEW)
using namespace Customdirview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CustomDirViewHPP
