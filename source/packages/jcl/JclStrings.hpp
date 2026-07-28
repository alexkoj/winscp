// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclStrings.pas' rev: 37.00 (Windows)

#ifndef JclStringsHPP
#define JclStringsHPP

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
#include <System.SysUtils.hpp>
#include <JclAnsiStrings.hpp>
#include <JclBase.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jclstrings
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EJclStringError;
class DELPHICLASS FormatException;
class DELPHICLASS ArgumentException;
class DELPHICLASS ArgumentNullException;
class DELPHICLASS ArgumentOutOfRangeException;
__interface DELPHIINTERFACE IToString;
typedef System::DelphiInterface<IToString> _di_IToString;
class DELPHICLASS TJclStringBuilder;
class DELPHICLASS TJclTabSet;
class DELPHICLASS NullReferenceException;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclStringError : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EJclStringError(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EJclStringError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EJclStringError(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EJclStringError(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclStringError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclStringError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclStringError(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclStringError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclStringError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclStringError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStringError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStringError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclStringError() { }
	
};

#pragma pack(pop)

typedef bool __fastcall (*TCharValidator)(const System::WideChar C);

typedef System::WideChar * *PCharVector;

#pragma pack(push,4)
class PASCALIMPLEMENTATION FormatException : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall FormatException(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall FormatException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall FormatException(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall FormatException(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall FormatException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall FormatException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall FormatException(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall FormatException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall FormatException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall FormatException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall FormatException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall FormatException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~FormatException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ArgumentException : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall ArgumentException(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ArgumentException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ArgumentException(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ArgumentException(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ArgumentException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ArgumentException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ArgumentException(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ArgumentException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ArgumentException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ArgumentException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ArgumentException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ArgumentNullException : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall ArgumentNullException(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ArgumentNullException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ArgumentNullException(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ArgumentNullException(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ArgumentNullException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ArgumentNullException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ArgumentNullException(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ArgumentNullException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ArgumentNullException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ArgumentNullException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentNullException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentNullException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ArgumentNullException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ArgumentOutOfRangeException : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall ArgumentOutOfRangeException(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ArgumentOutOfRangeException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ArgumentOutOfRangeException(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ArgumentOutOfRangeException(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ArgumentOutOfRangeException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ArgumentOutOfRangeException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ArgumentOutOfRangeException(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ArgumentOutOfRangeException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ArgumentOutOfRangeException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ArgumentOutOfRangeException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentOutOfRangeException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ArgumentOutOfRangeException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ArgumentOutOfRangeException() { }
	
};

#pragma pack(pop)

__interface  INTERFACE_UUID("{C4ABABB4-1029-46E7-B5FA-99800F130C05}") IToString  : public System::IInterface 
{
	virtual System::UnicodeString __fastcall ToString() = 0 ;
};

typedef System::DynamicArray<System::WideChar> TCharDynArray;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclStringBuilder : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	System::WideChar operator[](Jclbase::SizeInt Index) { return this->__Chars__[Index]; }
	
private:
	TCharDynArray FChars;
	Jclbase::SizeInt FLength;
	Jclbase::SizeInt FMaxCapacity;
	Jclbase::SizeInt __fastcall GetCapacity();
	void __fastcall SetCapacity(const Jclbase::SizeInt Value);
	System::WideChar __fastcall GetChars(Jclbase::SizeInt Index);
	void __fastcall SetChars(Jclbase::SizeInt Index, const System::WideChar Value);
	void __fastcall Set_Length(const Jclbase::SizeInt Value);
	
protected:
	TJclStringBuilder* __fastcall AppendPChar(System::WideChar * Value, Jclbase::SizeInt Count, Jclbase::SizeInt RepeatCount = 0x1);
	TJclStringBuilder* __fastcall InsertPChar(Jclbase::SizeInt Index, System::WideChar * Value, Jclbase::SizeInt Count, Jclbase::SizeInt RepeatCount = 0x1);
	
public:
	__fastcall TJclStringBuilder(const System::UnicodeString Value, Jclbase::SizeInt Capacity)/* overload */;
	__fastcall TJclStringBuilder(Jclbase::SizeInt Capacity, Jclbase::SizeInt MaxCapacity)/* overload */;
	__fastcall TJclStringBuilder(const System::UnicodeString Value, Jclbase::SizeInt StartIndex, Jclbase::SizeInt Length, Jclbase::SizeInt Capacity)/* overload */;
	TJclStringBuilder* __fastcall Append(const System::UnicodeString Value)/* overload */;
	TJclStringBuilder* __fastcall Append(const System::UnicodeString Value, Jclbase::SizeInt StartIndex, Jclbase::SizeInt Length)/* overload */;
	TJclStringBuilder* __fastcall Append(bool Value)/* overload */;
	TJclStringBuilder* __fastcall Append(System::WideChar Value, Jclbase::SizeInt RepeatCount = 0x1)/* overload */;
	TJclStringBuilder* __fastcall Append(const System::WideChar *Value, const System::NativeInt Value_High)/* overload */;
	TJclStringBuilder* __fastcall Append(const System::WideChar *Value, const System::NativeInt Value_High, Jclbase::SizeInt StartIndex, Jclbase::SizeInt Length)/* overload */;
	TJclStringBuilder* __fastcall Append(unsigned Value)/* overload */;
	TJclStringBuilder* __fastcall Append(int Value)/* overload */;
	TJclStringBuilder* __fastcall Append(double Value)/* overload */;
	TJclStringBuilder* __fastcall Append(__int64 Value)/* overload */;
	TJclStringBuilder* __fastcall Append(System::TObject* Obj)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const System::UnicodeString Fmt, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const System::UnicodeString Fmt, const System::Variant &Arg0)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const System::UnicodeString Fmt, const System::Variant &Arg0, const System::Variant &Arg1)/* overload */;
	TJclStringBuilder* __fastcall AppendFormat(const System::UnicodeString Fmt, const System::Variant &Arg0, const System::Variant &Arg1, const System::Variant &Arg2)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, const System::UnicodeString Value, Jclbase::SizeInt Count = 0x1)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, bool Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, const System::WideChar *Value, const System::NativeInt Value_High)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, const System::WideChar *Value, const System::NativeInt Value_High, Jclbase::SizeInt StartIndex, Jclbase::SizeInt Length)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, unsigned Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, int Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, double Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, __int64 Value)/* overload */;
	TJclStringBuilder* __fastcall Insert(Jclbase::SizeInt Index, System::TObject* Obj)/* overload */;
	TJclStringBuilder* __fastcall Replace(System::WideChar OldChar, System::WideChar NewChar, Jclbase::SizeInt StartIndex = 0x0, Jclbase::SizeInt Count = 0xffffffff)/* overload */;
	TJclStringBuilder* __fastcall Replace(System::UnicodeString OldValue, System::UnicodeString NewValue, Jclbase::SizeInt StartIndex = 0x0, Jclbase::SizeInt Count = 0xffffffff)/* overload */;
	TJclStringBuilder* __fastcall Remove(Jclbase::SizeInt StartIndex, Jclbase::SizeInt Length);
	Jclbase::SizeInt __fastcall EnsureCapacity(Jclbase::SizeInt Capacity);
	void __fastcall Clear();
	virtual System::UnicodeString __fastcall ToString();
	__property System::WideChar __Chars__[Jclbase::SizeInt Index] = {read=GetChars, write=SetChars/*, default*/};
	__property TCharDynArray Chars = {read=FChars};
	__property Jclbase::SizeInt Length = {read=FLength, write=Set_Length, nodefault};
	__property Jclbase::SizeInt Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property Jclbase::SizeInt MaxCapacity = {read=FMaxCapacity, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclStringBuilder() { }
	
private:
	void *__IToString;	// IToString 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C4ABABB4-1029-46E7-B5FA-99800F130C05}
	operator _di_IToString()
	{
		_di_IToString intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IToString*(void) { return (IToString*)&__IToString; }
	#endif
	
};

#pragma pack(pop)

using System::Sysutils::TStringBuilder;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTabSet : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
public:
	Jclbase::SizeInt operator[](Jclbase::SizeInt Index) { return this->TabStops[Index]; }
	
private:
	System::TObject* FData;
	Jclbase::SizeInt __fastcall GetCount();
	Jclbase::SizeInt __fastcall GetStops(Jclbase::SizeInt Index);
	Jclbase::SizeInt __fastcall GetTabWidth();
	bool __fastcall GetZeroBased();
	void __fastcall SetStops(Jclbase::SizeInt Index, Jclbase::SizeInt Value);
	void __fastcall SetTabWidth(Jclbase::SizeInt Value);
	void __fastcall SetZeroBased(bool Value);
	
protected:
	Jclbase::SizeInt __fastcall FindStop(Jclbase::SizeInt Column);
	Jclbase::TDynSizeIntArray __fastcall InternalTabStops();
	Jclbase::SizeInt __fastcall InternalTabWidth();
	void __fastcall RemoveAt(Jclbase::SizeInt Index);
	
public:
	__fastcall TJclTabSet()/* overload */;
	__fastcall TJclTabSet(System::TObject* Data)/* overload */;
	__fastcall TJclTabSet(Jclbase::SizeInt TabWidth)/* overload */;
	__fastcall TJclTabSet(const int *Tabstops, const System::NativeInt Tabstops_High, bool ZeroBased)/* overload */;
	__fastcall TJclTabSet(const int *Tabstops, const System::NativeInt Tabstops_High, bool ZeroBased, Jclbase::SizeInt TabWidth)/* overload */;
	__fastcall virtual ~TJclTabSet();
	TJclTabSet* __fastcall Clone();
	TJclTabSet* __fastcall NewReference();
	Jclbase::SizeInt __fastcall Add(Jclbase::SizeInt Column);
	Jclbase::SizeInt __fastcall Delete(Jclbase::SizeInt Column);
	System::UnicodeString __fastcall Expand(const System::UnicodeString S)/* overload */;
	System::UnicodeString __fastcall Expand(const System::UnicodeString S, Jclbase::SizeInt Column)/* overload */;
	void __fastcall OptimalFillInfo(Jclbase::SizeInt StartColumn, Jclbase::SizeInt TargetColumn, /* out */ Jclbase::SizeInt &TabsNeeded, /* out */ Jclbase::SizeInt &SpacesNeeded);
	System::UnicodeString __fastcall Optimize(const System::UnicodeString S)/* overload */;
	System::UnicodeString __fastcall Optimize(const System::UnicodeString S, Jclbase::SizeInt Column)/* overload */;
	Jclbase::SizeInt __fastcall StartColumn();
	Jclbase::SizeInt __fastcall TabFrom(Jclbase::SizeInt Column);
	Jclbase::SizeInt __fastcall UpdatePosition(const System::UnicodeString S)/* overload */;
	Jclbase::SizeInt __fastcall UpdatePosition(const System::UnicodeString S, Jclbase::SizeInt Column)/* overload */;
	Jclbase::SizeInt __fastcall UpdatePosition(const System::UnicodeString S, Jclbase::SizeInt &Column, Jclbase::SizeInt &Line)/* overload */;
	virtual System::UnicodeString __fastcall ToString()/* overload */;
	HIDESBASE System::UnicodeString __fastcall ToString(Jclbase::SizeInt FormattingOptions)/* overload */;
	static TJclTabSet* __fastcall FromString(const System::UnicodeString S);
	__property Jclbase::SizeInt ActualTabWidth = {read=InternalTabWidth, nodefault};
	__property Jclbase::SizeInt Count = {read=GetCount, nodefault};
	__property Jclbase::SizeInt TabStops[Jclbase::SizeInt Index] = {read=GetStops, write=SetStops/*, default*/};
	__property Jclbase::SizeInt TabWidth = {read=GetTabWidth, write=SetTabWidth, nodefault};
	__property bool ZeroBased = {read=GetZeroBased, write=SetZeroBased, nodefault};
private:
	void *__IToString;	// IToString 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C4ABABB4-1029-46E7-B5FA-99800F130C05}
	operator _di_IToString()
	{
		_di_IToString intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IToString*(void) { return (IToString*)&__IToString; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION NullReferenceException : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	__fastcall NullReferenceException()/* overload */;
public:
	/* Exception.CreateFmt */ inline __fastcall NullReferenceException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall NullReferenceException(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall NullReferenceException(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall NullReferenceException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall NullReferenceException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall NullReferenceException(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall NullReferenceException(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall NullReferenceException(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall NullReferenceException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall NullReferenceException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall NullReferenceException(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~NullReferenceException() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::WideChar NativeNull = (System::WideChar)(0x0);
static _DELPHI_CONST System::WideChar NativeSoh = (System::WideChar)(0x1);
static _DELPHI_CONST System::WideChar NativeStx = (System::WideChar)(0x2);
static _DELPHI_CONST System::WideChar NativeEtx = (System::WideChar)(0x3);
static _DELPHI_CONST System::WideChar NativeEot = (System::WideChar)(0x4);
static _DELPHI_CONST System::WideChar NativeEnq = (System::WideChar)(0x5);
static _DELPHI_CONST System::WideChar NativeAck = (System::WideChar)(0x6);
static _DELPHI_CONST System::WideChar NativeBell = (System::WideChar)(0x7);
static _DELPHI_CONST System::WideChar NativeBackspace = (System::WideChar)(0x8);
static _DELPHI_CONST System::WideChar NativeTab = (System::WideChar)(0x9);
static _DELPHI_CONST System::WideChar NativeLineFeed = (System::WideChar)(0xa);
static _DELPHI_CONST System::WideChar NativeVerticalTab = (System::WideChar)(0xb);
static _DELPHI_CONST System::WideChar NativeFormFeed = (System::WideChar)(0xc);
static _DELPHI_CONST System::WideChar NativeCarriageReturn = (System::WideChar)(0xd);
#define NativeCrLf L"\r\n"
static _DELPHI_CONST System::WideChar NativeSo = (System::WideChar)(0xe);
static _DELPHI_CONST System::WideChar NativeSi = (System::WideChar)(0xf);
static _DELPHI_CONST System::WideChar NativeDle = (System::WideChar)(0x10);
static _DELPHI_CONST System::WideChar NativeDc1 = (System::WideChar)(0x11);
static _DELPHI_CONST System::WideChar NativeDc2 = (System::WideChar)(0x12);
static _DELPHI_CONST System::WideChar NativeDc3 = (System::WideChar)(0x13);
static _DELPHI_CONST System::WideChar NativeDc4 = (System::WideChar)(0x14);
static _DELPHI_CONST System::WideChar NativeNak = (System::WideChar)(0x15);
static _DELPHI_CONST System::WideChar NativeSyn = (System::WideChar)(0x16);
static _DELPHI_CONST System::WideChar NativeEtb = (System::WideChar)(0x17);
static _DELPHI_CONST System::WideChar NativeCan = (System::WideChar)(0x18);
static _DELPHI_CONST System::WideChar NativeEm = (System::WideChar)(0x19);
static _DELPHI_CONST System::WideChar NativeEndOfFile = (System::WideChar)(0x1a);
static _DELPHI_CONST System::WideChar NativeEscape = (System::WideChar)(0x1b);
static _DELPHI_CONST System::WideChar NativeFs = (System::WideChar)(0x1c);
static _DELPHI_CONST System::WideChar NativeGs = (System::WideChar)(0x1d);
static _DELPHI_CONST System::WideChar NativeRs = (System::WideChar)(0x1e);
static _DELPHI_CONST System::WideChar NativeUs = (System::WideChar)(0x1f);
static _DELPHI_CONST System::WideChar NativeSpace = (System::WideChar)(0x20);
static _DELPHI_CONST System::WideChar NativeComma = (System::WideChar)(0x2c);
static _DELPHI_CONST System::WideChar NativeBackslash = (System::WideChar)(0x5c);
static _DELPHI_CONST System::WideChar NativeForwardSlash = (System::WideChar)(0x2f);
static _DELPHI_CONST System::WideChar NativeDoubleQuote = (System::WideChar)(0x22);
static _DELPHI_CONST System::WideChar NativeSingleQuote = (System::WideChar)(0x27);
#define NativeLineBreak L"\r\n"
static _DELPHI_CONST System::Int8 TabSetFormatting_SurroundStopsWithBrackets = System::Int8(0x1);
static _DELPHI_CONST System::Int8 TabSetFormatting_EmptyBracketsIfNoStops = System::Int8(0x2);
static _DELPHI_CONST System::Int8 TabSetFormatting_NoTabStops = System::Int8(0x4);
static _DELPHI_CONST System::Int8 TabSetFormatting_NoTabWidth = System::Int8(0x8);
static _DELPHI_CONST System::Int8 TabSetFormatting_AutoTabWidth = System::Int8(0x10);
static _DELPHI_CONST System::Int8 TabSetFormatting_Default = System::Int8(0x0);
static _DELPHI_CONST System::Int8 TabSetFormatting_AlwaysUseBrackets = System::Int8(0x3);
static _DELPHI_CONST System::Int8 TabSetFormatting_Full = System::Int8(0x13);
static _DELPHI_CONST System::Int8 TabSetFormatting_StopsOnly = System::Int8(0x8);
static _DELPHI_CONST System::Int8 TabSetFormatting_TabWidthOnly = System::Int8(0x4);
static _DELPHI_CONST System::Int8 TabSetFormatting_StopsWithoutBracketsAndTabWidth = System::Int8(0x0);
static _DELPHI_CONST int MaxStrCharCount = int(0x10000);
static _DELPHI_CONST System::Int8 StrLoOffset = System::Int8(0x0);
static _DELPHI_CONST int StrUpOffset = int(0x10000);
static _DELPHI_CONST int StrReOffset = int(0x20000);
static _DELPHI_CONST int StrCaseMapSize = int(0x30000);
extern DELPHI_PACKAGE System::StaticArray<System::WideChar, 196608> StrCaseMap;
extern DELPHI_PACKAGE bool StrCaseMapReady;
extern DELPHI_PACKAGE System::StaticArray<System::Word, 65536> StrCharTypes;
extern DELPHI_PACKAGE bool __fastcall ArrayContainsChar(const System::WideChar *Chars, const System::NativeInt Chars_High, const System::WideChar C)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ArrayContainsChar(const System::WideChar *Chars, const System::NativeInt Chars_High, const System::WideChar C, /* out */ Jclbase::SizeInt &Index)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIsAlpha(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall StrIsAlphaNum(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall StrContainsChars(const System::UnicodeString S, const TCharValidator Chars, bool CheckAll)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrContainsChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High, bool CheckAll)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIsAlphaNumUnderscore(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall StrIsDigit(const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall StrIsSubset(const System::UnicodeString S, const TCharValidator ValidChars)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIsSubset(const System::UnicodeString S, const System::WideChar *ValidChars, const System::NativeInt ValidChars_High)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrSame(const System::UnicodeString S1, const System::UnicodeString S2, bool CaseSensitive = false);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrCenter(const System::UnicodeString S, Jclbase::SizeInt L, System::WideChar C = (System::WideChar)(0x20));
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrCharPosLower(const System::UnicodeString S, Jclbase::SizeInt CharPos);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrCharPosUpper(const System::UnicodeString S, Jclbase::SizeInt CharPos);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrDoubleQuote(const System::UnicodeString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrEnsureNoPrefix(const System::UnicodeString Prefix, const System::UnicodeString Text);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrEnsureNoSuffix(const System::UnicodeString Suffix, const System::UnicodeString Text);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrEnsurePrefix(const System::UnicodeString Prefix, const System::UnicodeString Text);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrEnsureSuffix(const System::UnicodeString Suffix, const System::UnicodeString Text);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrEscapedToString(const System::UnicodeString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrLower(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall StrLowerInPlace(System::UnicodeString &S);
extern DELPHI_PACKAGE void __fastcall StrLowerBuff(System::WideChar * S);
extern DELPHI_PACKAGE void __fastcall StrMove(System::UnicodeString &Dest, const System::UnicodeString Source, const Jclbase::SizeInt ToIndex, const Jclbase::SizeInt FromIndex, const Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrPadLeft(const System::UnicodeString S, Jclbase::SizeInt Len, System::WideChar C = (System::WideChar)(0x20));
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrPadRight(const System::UnicodeString S, Jclbase::SizeInt Len, System::WideChar C = (System::WideChar)(0x20));
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrProper(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall StrProperBuff(System::WideChar * S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrQuote(const System::UnicodeString S, System::WideChar C);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRemoveChars(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRemoveChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRemoveLeadingChars(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRemoveLeadingChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRemoveEndChars(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRemoveEndChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrKeepChars(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrKeepChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRepeat(const System::UnicodeString S, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRepeatLength(const System::UnicodeString S, Jclbase::SizeInt L);
extern DELPHI_PACKAGE void __fastcall StrReplace(System::UnicodeString &S, const System::UnicodeString Search, const System::UnicodeString Replace, System::Sysutils::TReplaceFlags Flags = System::Sysutils::TReplaceFlags() );
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrReplaceChar(const System::UnicodeString S, const System::WideChar Source, const System::WideChar Replace);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrReplaceChars(const System::UnicodeString S, const TCharValidator Chars, System::WideChar Replace)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrReplaceChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High, System::WideChar Replace)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrReplaceButChars(const System::UnicodeString S, const TCharValidator Chars, System::WideChar Replace)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrReplaceButChars(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High, System::WideChar Replace)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrReverse(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall StrReverseInPlace(System::UnicodeString &S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrSingleQuote(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall StrSkipChars(System::WideChar * &S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrSkipChars(System::WideChar * &S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrSkipChars(const System::UnicodeString S, Jclbase::SizeInt &Index, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrSkipChars(const System::UnicodeString S, Jclbase::SizeInt &Index, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrSmartCase(const System::UnicodeString S, const TCharValidator Delimiters)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrSmartCase(const System::UnicodeString S, const System::WideChar *Delimiters, const System::NativeInt Delimiters_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrStringToEscaped(const System::UnicodeString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrToHex(const System::UnicodeString Source);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimCharLeft(const System::UnicodeString S, System::WideChar C);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimCharsLeft(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimCharsLeft(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimCharRight(const System::UnicodeString S, System::WideChar C);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimCharsRight(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimCharsRight(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrTrimQuotes(const System::UnicodeString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrUpper(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall StrUpperInPlace(System::UnicodeString &S);
extern DELPHI_PACKAGE void __fastcall StrUpperBuff(System::WideChar * S);
extern DELPHI_PACKAGE void __fastcall StrAddRef(System::UnicodeString &S);
extern DELPHI_PACKAGE void __fastcall StrDecRef(System::UnicodeString &S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrLength(const System::UnicodeString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrRefCount(const System::UnicodeString S);
extern DELPHI_PACKAGE void __fastcall StrResetLength(System::WideString &S)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrResetLength(System::AnsiString &S)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrResetLength(TJclStringBuilder* S)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrResetLength(System::UnicodeString &S)/* overload */;
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCharCount(const System::UnicodeString S, System::WideChar C)/* overload */;
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCharsCount(const System::UnicodeString S, const TCharValidator Chars)/* overload */;
extern DELPHI_PACKAGE int __fastcall StrCharsCount(const System::UnicodeString S, const System::WideChar *Chars, const System::NativeInt Chars_High)/* overload */;
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrStrCount(const System::UnicodeString S, const System::UnicodeString SubS);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCompareRangeEx(const System::UnicodeString S1, const System::UnicodeString S2, Jclbase::SizeInt Index, Jclbase::SizeInt Count, bool CaseSensitive);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCompare(const System::UnicodeString S1, const System::UnicodeString S2, bool CaseSensitive = false);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCompareRange(const System::UnicodeString S1, const System::UnicodeString S2, Jclbase::SizeInt Index, Jclbase::SizeInt Count, bool CaseSensitive = true);
extern DELPHI_PACKAGE void __fastcall StrFillChar(void *S, Jclbase::SizeInt Count, System::WideChar C);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRepeatChar(System::WideChar C, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrFind(const System::UnicodeString Substr, const System::UnicodeString S, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE bool __fastcall StrHasPrefix(const System::UnicodeString S, const System::UnicodeString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE bool __fastcall StrHasSuffix(const System::UnicodeString S, const System::UnicodeString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrIndex(const System::UnicodeString S, const System::UnicodeString *List, const System::NativeInt List_High, bool CaseSensitive = false);
extern DELPHI_PACKAGE bool __fastcall StrIHasPrefix(const System::UnicodeString S, const System::UnicodeString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE bool __fastcall StrIHasSuffix(const System::UnicodeString S, const System::UnicodeString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrILastPos(const System::UnicodeString SubStr, const System::UnicodeString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrIPos(const System::UnicodeString SubStr, const System::UnicodeString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrIPrefixIndex(const System::UnicodeString S, const System::UnicodeString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE bool __fastcall StrIsOneOf(const System::UnicodeString S, const System::UnicodeString *List, const System::NativeInt List_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrISuffixIndex(const System::UnicodeString S, const System::UnicodeString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrLastPos(const System::UnicodeString SubStr, const System::UnicodeString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrMatch(const System::UnicodeString Substr, const System::UnicodeString S, Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE bool __fastcall StrMatches(const System::UnicodeString Substr, const System::UnicodeString S, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrNPos(const System::UnicodeString S, const System::UnicodeString SubStr, Jclbase::SizeInt N);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrNIPos(const System::UnicodeString S, const System::UnicodeString SubStr, Jclbase::SizeInt N);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrPrefixIndex(const System::UnicodeString S, const System::UnicodeString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrSearch(const System::UnicodeString Substr, const System::UnicodeString S, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrSuffixIndex(const System::UnicodeString S, const System::UnicodeString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrAfter(const System::UnicodeString SubStr, const System::UnicodeString S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrBefore(const System::UnicodeString SubStr, const System::UnicodeString S);
extern DELPHI_PACKAGE bool __fastcall StrSplit(const System::UnicodeString SubStr, const System::UnicodeString S, System::UnicodeString &Left, System::UnicodeString &Right);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrBetween(const System::UnicodeString S, const System::WideChar Start, const System::WideChar Stop);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrChopRight(const System::UnicodeString S, Jclbase::SizeInt N);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrLeft(const System::UnicodeString S, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrMid(const System::UnicodeString S, Jclbase::SizeInt Start, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRestOf(const System::UnicodeString S, Jclbase::SizeInt N);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrRight(const System::UnicodeString S, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE bool __fastcall CharEqualNoCase(const System::WideChar C1, const System::WideChar C2);
extern DELPHI_PACKAGE bool __fastcall CharIsAlpha(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsAlphaNum(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsBlank(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsControl(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsDelete(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsDigit(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsFracDigit(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsHexDigit(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsLower(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsPrintable(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsPunctuation(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsReturn(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsSpace(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsUpper(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsValidIdentifierLetter(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsWhiteSpace(const System::WideChar C);
extern DELPHI_PACKAGE bool __fastcall CharIsWildcard(const System::WideChar C);
extern DELPHI_PACKAGE System::Word __fastcall CharType(const System::WideChar C);
extern DELPHI_PACKAGE PCharVector __fastcall StringsToPCharVector(PCharVector &Dest, System::Classes::TStrings* const Source);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall PCharVectorCount(PCharVector Source);
extern DELPHI_PACKAGE void __fastcall PCharVectorToStrings(System::Classes::TStrings* const Dest, PCharVector Source);
extern DELPHI_PACKAGE void __fastcall FreePCharVector(PCharVector &Dest);
extern DELPHI_PACKAGE System::Byte __fastcall CharHex(const System::WideChar C);
extern DELPHI_PACKAGE System::WideChar __fastcall CharLower(const System::WideChar C);
extern DELPHI_PACKAGE System::WideChar __fastcall CharToggleCase(const System::WideChar C);
extern DELPHI_PACKAGE System::WideChar __fastcall CharUpper(const System::WideChar C);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharLastPos(const System::UnicodeString S, const System::WideChar C, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharPos(const System::UnicodeString S, const System::WideChar C, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharIPos(const System::UnicodeString S, System::WideChar C, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharReplace(System::UnicodeString &S, const System::WideChar Search, const System::WideChar Replace);
extern DELPHI_PACKAGE void __fastcall StrToStrings(System::UnicodeString S, System::UnicodeString Sep, System::Classes::TStrings* const List, const bool AllowEmptyString = true);
extern DELPHI_PACKAGE void __fastcall StrIToStrings(System::UnicodeString S, System::UnicodeString Sep, System::Classes::TStrings* const List, const bool AllowEmptyString = true);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StringsToStr(System::Classes::TStrings* const List, const System::UnicodeString Sep, const bool AllowEmptyString = true)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StringsToStr(System::Classes::TStrings* const List, const System::UnicodeString Sep, const Jclbase::SizeInt NumberOfItems, const bool AllowEmptyString = true)/* overload */;
extern DELPHI_PACKAGE void __fastcall TrimStrings(System::Classes::TStrings* const List, bool DeleteIfEmpty = true);
extern DELPHI_PACKAGE void __fastcall TrimStringsRight(System::Classes::TStrings* const List, bool DeleteIfEmpty = true);
extern DELPHI_PACKAGE void __fastcall TrimStringsLeft(System::Classes::TStrings* const List, bool DeleteIfEmpty = true);
extern DELPHI_PACKAGE bool __fastcall AddStringToStrings(const System::UnicodeString S, System::Classes::TStrings* Strings, const bool Unique);
extern DELPHI_PACKAGE System::RawByteString __fastcall FileToString(const System::UnicodeString FileName);
extern DELPHI_PACKAGE void __fastcall StringToFile(const System::UnicodeString FileName, const System::RawByteString Contents, bool Append = false);
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrToken(System::UnicodeString &S, System::WideChar Separator);
extern DELPHI_PACKAGE void __fastcall StrTokens(const System::UnicodeString S, System::Classes::TStrings* const List);
extern DELPHI_PACKAGE bool __fastcall StrWord(const System::UnicodeString S, Jclbase::SizeInt &Index, /* out */ System::UnicodeString &Word)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrWord(System::WideChar * &S, /* out */ System::UnicodeString &Word)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIdent(const System::UnicodeString S, Jclbase::SizeInt &Index, /* out */ System::UnicodeString &Ident)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIdent(System::WideChar * &S, /* out */ System::UnicodeString &Ident)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrTokenToStrings(System::UnicodeString S, System::WideChar Separator, System::Classes::TStrings* const List);
extern DELPHI_PACKAGE void __fastcall StrNormIndex(const Jclbase::SizeInt StrLen, Jclbase::SizeInt &Index, Jclbase::SizeInt &Count)/* overload */;
extern DELPHI_PACKAGE Jclbase::TDynStringArray __fastcall ArrayOf(System::Classes::TStrings* List)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall DotNetFormat(const System::UnicodeString Fmt, const System::Variant &Arg0)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall DotNetFormat(const System::UnicodeString Fmt, const System::Variant &Arg0, const System::Variant &Arg1)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall DotNetFormat(const System::UnicodeString Fmt, const System::Variant &Arg0, const System::Variant &Arg1, const System::Variant &Arg2)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall DotNetFormat(const System::UnicodeString Fmt, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrExpandTabs(System::UnicodeString S)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrExpandTabs(System::UnicodeString S, Jclbase::SizeInt TabWidth)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrExpandTabs(System::UnicodeString S, TJclTabSet* TabSet)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrOptimizeTabs(System::UnicodeString S)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrOptimizeTabs(System::UnicodeString S, Jclbase::SizeInt TabWidth)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrOptimizeTabs(System::UnicodeString S, TJclTabSet* TabSet)/* overload */;
}	/* namespace Jclstrings */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLSTRINGS)
using namespace Jclstrings;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclStringsHPP
