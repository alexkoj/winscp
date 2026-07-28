// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TB2Acc.pas' rev: 37.00 (Windows)

#ifndef TB2AccHPP
#define TB2AccHPP

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
#include <TB2Item.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tb2acc
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE ITBAccessible;
typedef System::DelphiInterface<ITBAccessible> _di_ITBAccessible;
class DELPHICLASS TTBCustomAccObject;
class DELPHICLASS TTBViewAccObject;
class DELPHICLASS TTBItemViewerAccObject;
//-- type declarations -------------------------------------------------------
__interface  INTERFACE_UUID("{618736E0-3C3D-11CF-810C-00AA00389B71}") ITBAccessible  : public IDispatch 
{
	virtual HRESULT __stdcall get_accParent(/* out */ _di_IDispatch &ppdispParent) = 0 ;
	virtual HRESULT __stdcall get_accChildCount(/* out */ int &pcountChildren) = 0 ;
	virtual HRESULT __stdcall get_accChild(System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild) = 0 ;
	virtual HRESULT __stdcall get_accName(System::OleVariant varChild, /* out */ System::WideString &pszName) = 0 ;
	virtual HRESULT __stdcall get_accValue(System::OleVariant varChild, /* out */ System::WideString &pszValue) = 0 ;
	virtual HRESULT __stdcall get_accDescription(System::OleVariant varChild, /* out */ System::WideString &pszDescription) = 0 ;
	virtual HRESULT __stdcall get_accRole(System::OleVariant varChild, /* out */ System::OleVariant &pvarRole) = 0 ;
	virtual HRESULT __stdcall get_accState(System::OleVariant varChild, /* out */ System::OleVariant &pvarState) = 0 ;
	virtual HRESULT __stdcall get_accHelp(System::OleVariant varChild, /* out */ System::WideString &pszHelp) = 0 ;
	virtual HRESULT __stdcall get_accHelpTopic(/* out */ System::WideString &pszHelpFile, System::OleVariant varChild, /* out */ int &pidTopic) = 0 ;
	virtual HRESULT __stdcall get_accKeyboardShortcut(System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut) = 0 ;
	virtual HRESULT __stdcall get_accFocus(/* out */ System::OleVariant &pvarID) = 0 ;
	virtual HRESULT __stdcall get_accSelection(/* out */ System::OleVariant &pvarChildren) = 0 ;
	virtual HRESULT __stdcall get_accDefaultAction(System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction) = 0 ;
	virtual HRESULT __stdcall accSelect(int flagsSelect, System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall accNavigate(int navDir, System::OleVariant varStart, /* out */ System::OleVariant &pvarEnd) = 0 ;
	virtual HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarID) = 0 ;
	virtual HRESULT __stdcall accDoDefaultAction(System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall put_accName(System::OleVariant varChild, const System::WideString pszName) = 0 ;
	virtual HRESULT __stdcall put_accValue(System::OleVariant varChild, const System::WideString pszValue) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBCustomAccObject : public Tb2item::TTBBaseAccObject
{
	typedef Tb2item::TTBBaseAccObject inherited;
	
private:
	TTBCustomAccObject* FPrevious;
	TTBCustomAccObject* FNext;
	
public:
	__fastcall TTBCustomAccObject();
	__fastcall virtual ~TTBCustomAccObject();
private:
	void *__IDispatch;	// IDispatch 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020400-0000-0000-C000-000000000046}
	operator _di_IDispatch()
	{
		_di_IDispatch intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IDispatch; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBViewAccObject : public TTBCustomAccObject
{
	typedef TTBCustomAccObject inherited;
	
private:
	Tb2item::TTBView* FView;
	bool __fastcall Check(const System::OleVariant &varChild, HRESULT &ErrorCode);
	HRESULT __stdcall accDoDefaultAction(System::OleVariant varChild);
	HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarID);
	HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, System::OleVariant varChild);
	HRESULT __stdcall accNavigate(int navDir, System::OleVariant varStart, /* out */ System::OleVariant &pvarEnd);
	HRESULT __stdcall accSelect(int flagsSelect, System::OleVariant varChild);
	HRESULT __stdcall get_accChild(System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild);
	HRESULT __stdcall get_accChildCount(/* out */ int &pcountChildren);
	HRESULT __stdcall get_accDefaultAction(System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction);
	HRESULT __stdcall get_accDescription(System::OleVariant varChild, /* out */ System::WideString &pszDescription);
	HRESULT __stdcall get_accFocus(/* out */ System::OleVariant &pvarID);
	HRESULT __stdcall get_accHelp(System::OleVariant varChild, /* out */ System::WideString &pszHelp);
	HRESULT __stdcall get_accHelpTopic(/* out */ System::WideString &pszHelpFile, System::OleVariant varChild, /* out */ int &pidTopic);
	HRESULT __stdcall get_accKeyboardShortcut(System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut);
	HRESULT __stdcall get_accName(System::OleVariant varChild, /* out */ System::WideString &pszName);
	HRESULT __stdcall get_accParent(/* out */ _di_IDispatch &ppdispParent);
	HRESULT __stdcall get_accRole(System::OleVariant varChild, /* out */ System::OleVariant &pvarRole);
	HRESULT __stdcall get_accSelection(/* out */ System::OleVariant &pvarChildren);
	HRESULT __stdcall get_accState(System::OleVariant varChild, /* out */ System::OleVariant &pvarState);
	HRESULT __stdcall get_accValue(System::OleVariant varChild, /* out */ System::WideString &pszValue);
	HRESULT __stdcall put_accName(System::OleVariant varChild, const System::WideString pszName);
	HRESULT __stdcall put_accValue(System::OleVariant varChild, const System::WideString pszValue);
	
public:
	__fastcall TTBViewAccObject(Tb2item::TTBView* AView);
	__fastcall virtual ~TTBViewAccObject();
	virtual void __fastcall ClientIsDestroying();
private:
	void *__ITBAccessible;	// ITBAccessible 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {618736E0-3C3D-11CF-810C-00AA00389B71}
	operator _di_ITBAccessible()
	{
		_di_ITBAccessible intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ITBAccessible*(void) { return (ITBAccessible*)&__ITBAccessible; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020400-0000-0000-C000-000000000046}
	operator _di_IDispatch()
	{
		_di_IDispatch intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDispatch*(void) { return (IDispatch*)&__ITBAccessible; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__ITBAccessible; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTBItemViewerAccObject : public TTBCustomAccObject
{
	typedef TTBCustomAccObject inherited;
	
private:
	Tb2item::TTBItemViewer* FViewer;
	bool __fastcall Check(const System::OleVariant &varChild, HRESULT &ErrorCode);
	bool __fastcall IsActionable();
	bool __fastcall IsAvailable();
	bool __fastcall IsFocusable();
	HRESULT __stdcall accDoDefaultAction(System::OleVariant varChild);
	HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarID);
	HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, System::OleVariant varChild);
	HRESULT __stdcall accNavigate(int navDir, System::OleVariant varStart, /* out */ System::OleVariant &pvarEnd);
	HRESULT __stdcall accSelect(int flagsSelect, System::OleVariant varChild);
	HRESULT __stdcall get_accChild(System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild);
	HRESULT __stdcall get_accChildCount(/* out */ int &pcountChildren);
	HRESULT __stdcall get_accDefaultAction(System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction);
	HRESULT __stdcall get_accDescription(System::OleVariant varChild, /* out */ System::WideString &pszDescription);
	HRESULT __stdcall get_accFocus(/* out */ System::OleVariant &pvarID);
	HRESULT __stdcall get_accHelp(System::OleVariant varChild, /* out */ System::WideString &pszHelp);
	HRESULT __stdcall get_accHelpTopic(/* out */ System::WideString &pszHelpFile, System::OleVariant varChild, /* out */ int &pidTopic);
	HRESULT __stdcall get_accKeyboardShortcut(System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut);
	HRESULT __stdcall get_accName(System::OleVariant varChild, /* out */ System::WideString &pszName);
	HRESULT __stdcall get_accParent(/* out */ _di_IDispatch &ppdispParent);
	HRESULT __stdcall get_accRole(System::OleVariant varChild, /* out */ System::OleVariant &pvarRole);
	HRESULT __stdcall get_accSelection(/* out */ System::OleVariant &pvarChildren);
	HRESULT __stdcall get_accState(System::OleVariant varChild, /* out */ System::OleVariant &pvarState);
	HRESULT __stdcall get_accValue(System::OleVariant varChild, /* out */ System::WideString &pszValue);
	HRESULT __stdcall put_accName(System::OleVariant varChild, const System::WideString pszName);
	HRESULT __stdcall put_accValue(System::OleVariant varChild, const System::WideString pszValue);
	
public:
	__fastcall TTBItemViewerAccObject(Tb2item::TTBItemViewer* AViewer);
	__fastcall virtual ~TTBItemViewerAccObject();
	virtual void __fastcall ClientIsDestroying();
	void __fastcall HandleAccSelect(const bool AExecute);
private:
	void *__ITBAccessible;	// ITBAccessible 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {618736E0-3C3D-11CF-810C-00AA00389B71}
	operator _di_ITBAccessible()
	{
		_di_ITBAccessible intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ITBAccessible*(void) { return (ITBAccessible*)&__ITBAccessible; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020400-0000-0000-C000-000000000046}
	operator _di_IDispatch()
	{
		_di_IDispatch intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IDispatch*(void) { return (IDispatch*)&__ITBAccessible; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__ITBAccessible; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE int ViewAccObjectInstances;
extern DELPHI_PACKAGE int ItemViewerAccObjectInstances;
}	/* namespace Tb2acc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TB2ACC)
using namespace Tb2acc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TB2AccHPP
