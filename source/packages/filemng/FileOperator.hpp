// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FileOperator.pas' rev: 37.00 (Windows)

#ifndef FileOperatorHPP
#define FileOperatorHPP

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
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <Winapi.ShellAPI.hpp>
#include <BaseUtils.hpp>
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Fileoperator
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TFileOperator;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TFileOperation : unsigned char { foCopy, foDelete, foMove, foRename };

enum DECLSPEC_DENUM TFileOperationFlag : unsigned char { foAllowUndo, foConfirmMouse, foFilesOnly, foMultiDestFiles, foNoConfirmation, foNoConfirmMkDir, foRenameOnCollision, foSilent, foSimpleProgress };

typedef System::Set<TFileOperationFlag, TFileOperationFlag::foAllowUndo, TFileOperationFlag::foSimpleProgress> TFileOperationFlags;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TFileOperator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Winapi::Shellapi::TSHFileOpStruct FData;
	System::Classes::TStringList* FFrom;
	System::Classes::TStringList* FTo;
	Vcl::Controls::TWinControl* fOwner;
	void __fastcall SetOperation(TFileOperation Value);
	TFileOperation __fastcall GetOperation();
	bool __fastcall GetWantMappingHandle();
	void __fastcall SetWantMappingHandle(bool Value);
	void __fastcall SetFlags(TFileOperationFlags Value);
	TFileOperationFlags __fastcall GetFlags();
	bool __fastcall GetOperFlag(unsigned F);
	void __fastcall SetOperFlag(unsigned F, bool V);
	
public:
	__property System::Classes::TStringList* OperandFrom = {read=FFrom, write=FFrom};
	__property System::Classes::TStringList* OperandTo = {read=FTo, write=FTo};
	__fastcall TFileOperator(Vcl::Controls::TWinControl* Owner);
	__fastcall virtual ~TFileOperator();
	bool __fastcall Execute();
	
__published:
	__property TFileOperation Operation = {read=GetOperation, write=SetOperation, stored=false, nodefault};
	__property TFileOperationFlags Flags = {read=GetFlags, write=SetFlags, stored=false, nodefault};
	__property bool WantMappingHandle = {read=GetWantMappingHandle, write=SetWantMappingHandle, stored=false, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define FileOperatorDefaultFlags (System::Set<TFileOperationFlag, TFileOperationFlag::foAllowUndo, TFileOperationFlag::foSimpleProgress>() << TFileOperationFlag::foAllowUndo << TFileOperationFlag::foNoConfirmMkDir )
}	/* namespace Fileoperator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FILEOPERATOR)
using namespace Fileoperator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FileOperatorHPP
