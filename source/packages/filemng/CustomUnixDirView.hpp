// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CustomUnixDirView.pas' rev: 37.00 (Windows)

#ifndef CustomUnixDirViewHPP
#define CustomUnixDirViewHPP

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
#include <NortonLikeListView.hpp>
#include <IEListView.hpp>
#include <CustomDirView.hpp>
#include <ListViewColProperties.hpp>
#include <UnixDirViewColProperties.hpp>

//-- user supplied -----------------------------------------------------------

namespace Customunixdirview
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TCustomUnixDirView;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TCustomUnixDirView : public Customdirview::TCustomDirView
{
	typedef Customdirview::TCustomDirView inherited;
	
private:
	void __fastcall SetUnixColProperties(Unixdirviewcolproperties::TUnixDirViewColProperties* Value);
	Unixdirviewcolproperties::TUnixDirViewColProperties* __fastcall GetUnixColProperties();
	
protected:
	virtual Listviewcolproperties::TCustomListViewColProperties* __fastcall NewColProperties();
	virtual bool __fastcall SortAscendingByDefault(int Index);
	
public:
	__property Items;
	
__published:
	__property Unixdirviewcolproperties::TUnixDirViewColProperties* UnixColProperties = {read=GetUnixColProperties, write=SetUnixColProperties};
public:
	/* TCustomDirView.Create */ inline __fastcall virtual TCustomUnixDirView(System::Classes::TComponent* AOwner) : Customdirview::TCustomDirView(AOwner) { }
	/* TCustomDirView.Destroy */ inline __fastcall virtual ~TCustomUnixDirView() { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomUnixDirView(HWND ParentWindow) : Customdirview::TCustomDirView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::ResourceString _SUnixDefaultRootName;
#define Customunixdirview_SUnixDefaultRootName System::LoadResourceString(&Customunixdirview::_SUnixDefaultRootName)
}	/* namespace Customunixdirview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CUSTOMUNIXDIRVIEW)
using namespace Customunixdirview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CustomUnixDirViewHPP
