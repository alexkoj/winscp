// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ListViewColProperties.pas' rev: 37.00 (Windows)

#ifndef ListViewColPropertiesHPP
#define ListViewColPropertiesHPP

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
#include <System.Contnrs.hpp>

//-- user supplied -----------------------------------------------------------

namespace Listviewcolproperties
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomListViewColProperty;
class DELPHICLASS TCustomListViewColProperties;
class DELPHICLASS TListViewColProperties;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TCustomListViewColProperty : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Classes::TAlignment Alignment;
	System::UnicodeString Caption;
	int Width;
	int MaxWidth;
	int MinWidth;
	bool Visible;
	int Order;
	__fastcall TCustomListViewColProperty(int AOrder);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomListViewColProperty() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TCustomListViewColProperties : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FChanged;
	System::Classes::TNotifyEvent FOnChange;
	int FUpdating;
	System::Contnrs::TObjectList* FProperties;
	bool FCreated;
	Vcl::Comctrls::TListColumns* __fastcall GetColumns();
	int __fastcall GetCount();
	System::UnicodeString __fastcall GetOrderStr();
	void __fastcall CheckBounds(int Index);
	void __fastcall SetWidthsStr(System::UnicodeString Value, int PixelsPerInch);
	System::UnicodeString __fastcall GetWidthsStr();
	void __fastcall SetOrderStr(System::UnicodeString Value);
	
protected:
	Vcl::Comctrls::TCustomListView* FListView;
	bool FListViewManaged;
	bool FConstraintsInitialized;
	System::Classes::TAlignment __fastcall GetAlignments(int Index);
	virtual System::UnicodeString __fastcall GetParamsStr();
	bool __fastcall GetVisible(int Index);
	int __fastcall GetWidths(int Index);
	void __fastcall SetAlignments(int Index, System::Classes::TAlignment Value);
	void __fastcall SetVisibleInternal(int Index, bool Value, bool SaveWidth);
	void __fastcall SetVisible(int Index, bool Value);
	void __fastcall SetWidths(int Index, int Value);
	System::UnicodeString __fastcall GetCaptions(int Index);
	virtual void __fastcall Changed();
	virtual void __fastcall SetCaptions(int Index, System::UnicodeString Value);
	virtual void __fastcall SetParamsStr(System::UnicodeString Value);
	void __fastcall UpdateListView();
	void __fastcall UpdateFromListView();
	void __fastcall UpdateOrderFromListView();
	void __fastcall UpdateListViewOrder();
	TCustomListViewColProperty* __fastcall GetProperties(int Index);
	int __fastcall GetIndexByOrder(int Order);
	bool __fastcall ColumnsExists();
	void __fastcall SetRuntimeVisible(int Index, bool Value, bool SaveWidth);
	Vcl::Comctrls::TListColumn* __fastcall GetColumn(int Index);
	void __fastcall CreateProperties(int ACount);
	int __fastcall DefaultConstraint(int Value, bool Visible, int Def);
	__property Vcl::Comctrls::TListColumns* Columns = {read=GetColumns, stored=false};
	
public:
	__fastcall TCustomListViewColProperties(Vcl::Comctrls::TCustomListView* ListView, int ColCount);
	__fastcall virtual ~TCustomListViewColProperties();
	void __fastcall EndUpdate();
	void __fastcall BeginUpdate();
	void __fastcall ListViewWndCreated();
	void __fastcall ListViewWndDestroying();
	void __fastcall ListViewWndDestroyed();
	void __fastcall ChangeScale(int M, int D);
	__property int Count = {read=GetCount, stored=false, nodefault};
	__property System::Classes::TAlignment Alignments[int Index] = {read=GetAlignments, write=SetAlignments};
	__property System::UnicodeString Captions[int Index] = {read=GetCaptions, write=SetCaptions};
	__property int Widths[int Index] = {read=GetWidths, write=SetWidths};
	__property bool Visible[int Index] = {read=GetVisible, write=SetVisible};
	void __fastcall RecreateColumns();
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property System::UnicodeString ParamsStr = {read=GetParamsStr, write=SetParamsStr, stored=false};
};


class PASCALIMPLEMENTATION TListViewColProperties : public TCustomListViewColProperties
{
	typedef TCustomListViewColProperties inherited;
	
public:
	/* TCustomListViewColProperties.Create */ inline __fastcall TListViewColProperties(Vcl::Comctrls::TCustomListView* ListView, int ColCount) : TCustomListViewColProperties(ListView, ColCount) { }
	/* TCustomListViewColProperties.Destroy */ inline __fastcall virtual ~TListViewColProperties() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Listviewcolproperties */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_LISTVIEWCOLPROPERTIES)
using namespace Listviewcolproperties;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ListViewColPropertiesHPP
