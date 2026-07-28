// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NortonLikeListView.pas' rev: 37.00 (Windows)

#ifndef NortonLikeListViewHPP
#define NortonLikeListViewHPP

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
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <ListViewColProperties.hpp>
#include <Winapi.CommCtrl.hpp>
#include <Vcl.Menus.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Nortonlikelistview
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomNortonLikeListView;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TSelectMode : unsigned char { smAll, smNone, smInvert };

enum DECLSPEC_DENUM TNortonLikeMode : unsigned char { nlOn, nlOff, nlKeyboard };

enum DECLSPEC_DENUM TSelectMethod : unsigned char { smNoneYet, smMouse, smKeyboard };

class PASCALIMPLEMENTATION TCustomNortonLikeListView : public Vcl::Comctrls::TCustomListView
{
	typedef Vcl::Comctrls::TCustomListView inherited;
	
private:
	Listviewcolproperties::TCustomListViewColProperties* FColProperties;
	bool FDontSelectItem;
	bool FDontUnSelectItem;
	int FSelCount;
	TNortonLikeMode FNortonLike;
	Vcl::Comctrls::TListItem* FLastDeletedItem;
	bool FFocusingItem;
	bool FManageSelection;
	int FFirstSelected;
	int FLastSelected;
	System::TDateTime FFocused;
	Winapi::Windows::THandle FIgnoreSetFocusFrom;
	bool FSelectingImplicitly;
	bool FAnyAndAllSelectedImplicitly;
	System::Classes::TShiftState FLButtonDownShiftState;
	Winapi::Windows::TPoint FLButtonDownPos;
	TSelectMethod FLastSelectMethod;
	bool FDarkMode;
	bool FAllowingDarkMode;
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMLButtonDown &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonDown(Winapi::Messages::TWMRButtonDown &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMLButtonUp &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TWMKeyDown &Message);
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Winapi::Messages::TWMSysCommand &Message);
	HIDESBASE MESSAGE void __fastcall WMChar(Winapi::Messages::TWMChar &Message);
	HIDESBASE MESSAGE void __fastcall WMNotify(Winapi::Messages::TWMNotify &Msg);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	MESSAGE void __fastcall LVMEditLabel(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall CMWantSpecialKey(Vcl::Controls::TCMWantSpecialKey &Message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNCDestroy &Message);
	int __fastcall GetMarkedCount();
	Vcl::Comctrls::TListItem* __fastcall GetMarkedFile();
	void __fastcall ItemSelected(Vcl::Comctrls::TListItem* Item, int Index);
	void __fastcall ItemUnselected(Vcl::Comctrls::TListItem* Item, int Index);
	HIDESBASE void __fastcall SelectAll(TSelectMode Mode, Vcl::Comctrls::TListItem* Exclude)/* overload */;
	MESSAGE void __fastcall WMThemeChanged(Winapi::Messages::TMessage &Msg);
	void __fastcall SetDarkMode(bool Value);
	
protected:
	bool FClearingItems;
	bool FInsertingNewUnselectedItem;
	int FUpdatingSelection;
	System::Word FNextCharToIgnore;
	HWND FHeaderHandle;
	virtual void __fastcall CreateWnd();
	virtual void __fastcall DestroyWnd();
	virtual void __fastcall BeginSelectionUpdate();
	virtual void __fastcall EndSelectionUpdate();
	virtual bool __fastcall CanChangeSelection(Vcl::Comctrls::TListItem* Item, bool Select);
	virtual void __fastcall ClearItems();
	void __fastcall ItemsReordered();
	DYNAMIC void __fastcall Delete(Vcl::Comctrls::TListItem* Item);
	DYNAMIC bool __fastcall ExCanChange(Vcl::Comctrls::TListItem* Item, int Change, System::Word NewState, System::Word OldState);
	DYNAMIC void __fastcall InsertItem(Vcl::Comctrls::TListItem* Item);
	virtual Listviewcolproperties::TCustomListViewColProperties* __fastcall NewColProperties() = 0 ;
	virtual void __fastcall FocusSomething(bool ForceMakeVisible);
	virtual bool __fastcall EnableDragOnClick();
	Vcl::Comctrls::TListItem* __fastcall GetItemFromHItem(const Winapi::Commctrl::TLVItem &Item);
	virtual bool __fastcall GetValid();
	virtual int __fastcall GetSelCount();
	void __fastcall DDBeforeDrag();
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TListItem* Item);
	DYNAMIC Vcl::Menus::TPopupMenu* __fastcall GetPopupMenu();
	DYNAMIC void __fastcall ChangeScale(int M, int D, bool isDpiChange)/* overload */;
	void __fastcall SetItemSelectedByIndex(int Index, bool Select);
	bool __fastcall GetItemSelectedByIndex(int Index);
	void __fastcall MakeTopItem(Vcl::Comctrls::TListItem* Item);
	void __fastcall UpdateDarkMode();
	
public:
	__fastcall virtual TCustomNortonLikeListView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomNortonLikeListView();
	Vcl::Comctrls::TListItem* __fastcall ClosestUnselected(Vcl::Comctrls::TListItem* Item);
	HIDESBASE void __fastcall SelectAll(TSelectMode Mode)/* overload */;
	void __fastcall SelectCurrentItem(bool FocusNext);
	HIDESBASE Vcl::Comctrls::TListItem* __fastcall GetNextItem(Vcl::Comctrls::TListItem* StartItem, Vcl::Comctrls::TSearchDirection Direction, Vcl::Comctrls::TItemStates States);
	void __fastcall MakeProgressVisible(Vcl::Comctrls::TListItem* Item);
	void __fastcall FocusItem(Vcl::Comctrls::TListItem* Item);
	bool __fastcall IsItemVisible(Vcl::Comctrls::TListItem* Item);
	__property Listviewcolproperties::TCustomListViewColProperties* ColProperties = {read=FColProperties, write=FColProperties, stored=false};
	__property MultiSelect = {default=1};
	__property TNortonLikeMode NortonLike = {read=FNortonLike, write=FNortonLike, default=0};
	__property int MarkedCount = {read=GetMarkedCount, nodefault};
	__property Vcl::Comctrls::TListItem* MarkedFile = {read=GetMarkedFile};
	__property bool Valid = {read=GetValid, nodefault};
	__property TSelectMethod LastSelectMethod = {read=FLastSelectMethod, nodefault};
	__property bool DarkMode = {read=FDarkMode, write=SetDarkMode, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomNortonLikeListView(HWND ParentWindow) : Vcl::Comctrls::TCustomListView(ParentWindow) { }
	
	/* Hoisted overloads: */
	
protected:
	DYNAMIC inline void __fastcall  ChangeScale(int M, int D){ Vcl::Controls::TControl::ChangeScale(M, D); }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Nortonlikelistview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_NORTONLIKELISTVIEW)
using namespace Nortonlikelistview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NortonLikeListViewHPP
