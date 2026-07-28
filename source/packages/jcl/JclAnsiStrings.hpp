// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclAnsiStrings.pas' rev: 37.00 (Windows)

#ifndef JclAnsiStringsHPP
#define JclAnsiStringsHPP

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
#include <System.AnsiStrings.hpp>
#include <JclBase.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jclansistrings
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TJclAnsiStrings;
struct TJclAnsiStringObjectHolder;
class DELPHICLASS TJclAnsiStringList;
class DELPHICLASS EJclAnsiStringError;
class DELPHICLASS EJclAnsiStringListError;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclAnsiStrings : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	System::AnsiString operator[](int Index) { return this->Strings[Index]; }
	
private:
	char FDelimiter;
	char FNameValueSeparator;
	bool FStrictDelimiter;
	char FQuoteChar;
	int FUpdateCount;
	System::AnsiString __fastcall GetText();
	void __fastcall SetText(const System::AnsiString Value);
	System::AnsiString __fastcall GetCommaText();
	void __fastcall SetCommaText(const System::AnsiString Value);
	System::AnsiString __fastcall GetDelimitedText()/* overload */;
	System::AnsiString __fastcall GetDelimitedText(const System::AnsiString ADelimiter, char AQuoteChar)/* overload */;
	void __fastcall SetDelimitedText(const System::AnsiString Value)/* overload */;
	void __fastcall SetDelimitedText(const System::AnsiString Value, const System::AnsiString ADelimiter, char AQuoteChar)/* overload */;
	System::AnsiString __fastcall ExtractName(const System::AnsiString S);
	System::AnsiString __fastcall GetName(int Index);
	System::AnsiString __fastcall GetValue(const System::AnsiString Name);
	void __fastcall SetValue(const System::AnsiString Name, const System::AnsiString Value);
	System::AnsiString __fastcall GetValueFromIndex(int Index);
	void __fastcall SetValueFromIndex(int Index, const System::AnsiString Value);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	void __fastcall Error(const System::UnicodeString Msg, int Data)/* overload */;
	void __fastcall Error(System::PResStringRec Msg, int Data)/* overload */;
	virtual System::AnsiString __fastcall GetString(int Index) = 0 ;
	virtual void __fastcall SetString(int Index, const System::AnsiString Value) = 0 ;
	virtual System::TObject* __fastcall GetObject(int Index) = 0 ;
	virtual void __fastcall SetObject(int Index, System::TObject* AObject) = 0 ;
	virtual int __fastcall GetCapacity();
	virtual void __fastcall SetCapacity(const int Value);
	virtual int __fastcall GetCount() = 0 ;
	virtual int __fastcall CompareStrings(const System::AnsiString S1, const System::AnsiString S2);
	virtual void __fastcall SetUpdateState(bool Updating);
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	
public:
	__fastcall TJclAnsiStrings();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual int __fastcall Add(const System::AnsiString S);
	virtual int __fastcall AddObject(const System::AnsiString S, System::TObject* AObject) = 0 ;
	virtual void __fastcall AddStrings(TJclAnsiStrings* Strings);
	virtual void __fastcall Insert(int Index, const System::AnsiString S);
	virtual void __fastcall InsertObject(int Index, const System::AnsiString S, System::TObject* AObject) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	virtual void __fastcall Clear() = 0 ;
	virtual void __fastcall LoadFromFile(const System::Sysutils::TFileName FileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall SaveToFile(const System::Sysutils::TFileName FileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	void __fastcall BeginUpdate();
	void __fastcall EndUpdate();
	virtual int __fastcall IndexOf(const System::AnsiString S);
	virtual int __fastcall IndexOfName(const System::AnsiString Name);
	virtual int __fastcall IndexOfObject(System::TObject* AObject);
	virtual void __fastcall Exchange(int Index1, int Index2);
	__property char Delimiter = {read=FDelimiter, write=FDelimiter, nodefault};
	__property System::AnsiString DelimitedText = {read=GetDelimitedText, write=SetDelimitedText};
	__property System::AnsiString CommaText = {read=GetCommaText, write=SetCommaText};
	__property bool StrictDelimiter = {read=FStrictDelimiter, write=FStrictDelimiter, nodefault};
	__property char QuoteChar = {read=FQuoteChar, write=FQuoteChar, nodefault};
	__property System::AnsiString Strings[int Index] = {read=GetString, write=SetString/*, default*/};
	__property System::TObject* Objects[int Index] = {read=GetObject, write=SetObject};
	__property System::AnsiString Text = {read=GetText, write=SetText};
	__property int Count = {read=GetCount, nodefault};
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property System::AnsiString Names[int Index] = {read=GetName};
	__property System::AnsiString Values[const System::AnsiString Name] = {read=GetValue, write=SetValue};
	__property System::AnsiString ValueFromIndex[int Index] = {read=GetValueFromIndex, write=SetValueFromIndex};
	__property char NameValueSeparator = {read=FNameValueSeparator, write=FNameValueSeparator, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclAnsiStrings() { }
	
};

#pragma pack(pop)

typedef int __fastcall (*TJclAnsiStringListSortCompare)(TJclAnsiStringList* List, int Index1, int Index2);

struct DECLSPEC_DRECORD TJclAnsiStringObjectHolder
{
public:
	System::AnsiString Str;
	System::TObject* Obj;
};


class PASCALIMPLEMENTATION TJclAnsiStringList : public TJclAnsiStrings
{
	typedef TJclAnsiStrings inherited;
	
	
private:
	typedef System::DynamicArray<TJclAnsiStringObjectHolder> _TJclAnsiStringList__1;
	
	
private:
	_TJclAnsiStringList__1 FStrings;
	int FCount;
	System::Classes::TDuplicates FDuplicates;
	bool FSorted;
	bool FCaseSensitive;
	System::Classes::TNotifyEvent FOnChange;
	System::Classes::TNotifyEvent FOnChanging;
	void __fastcall Grow();
	void __fastcall QuickSort(int L, int R, TJclAnsiStringListSortCompare SCompare);
	void __fastcall SetSorted(bool Value);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	virtual System::AnsiString __fastcall GetString(int Index);
	virtual void __fastcall SetString(int Index, const System::AnsiString Value);
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual void __fastcall SetObject(int Index, System::TObject* AObject);
	virtual int __fastcall GetCapacity();
	virtual void __fastcall SetCapacity(const int Value);
	virtual int __fastcall GetCount();
	virtual int __fastcall CompareStrings(const System::AnsiString S1, const System::AnsiString S2);
	virtual void __fastcall SetUpdateState(bool Updating);
	virtual void __fastcall Changed();
	virtual void __fastcall Changing();
	
public:
	__fastcall TJclAnsiStringList();
	__fastcall virtual ~TJclAnsiStringList();
	virtual int __fastcall AddObject(const System::AnsiString S, System::TObject* AObject);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall InsertObject(int Index, const System::AnsiString S, System::TObject* AObject);
	virtual void __fastcall Delete(int Index);
	virtual bool __fastcall Find(const System::AnsiString S, int &Index);
	virtual void __fastcall CustomSort(TJclAnsiStringListSortCompare Compare);
	virtual void __fastcall Sort();
	virtual void __fastcall Clear();
	__property bool CaseSensitive = {read=FCaseSensitive, write=FCaseSensitive, nodefault};
	__property System::Classes::TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property System::Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
};


typedef TJclAnsiStrings TAnsiStrings;

typedef TJclAnsiStringList TAnsiStringList;

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclAnsiStringError : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EJclAnsiStringError(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EJclAnsiStringError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EJclAnsiStringError(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EJclAnsiStringError(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclAnsiStringError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclAnsiStringError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclAnsiStringError(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclAnsiStringError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclAnsiStringError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclAnsiStringError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAnsiStringError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAnsiStringError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclAnsiStringError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclAnsiStringListError : public EJclAnsiStringError
{
	typedef EJclAnsiStringError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EJclAnsiStringListError(const System::UnicodeString Msg) : EJclAnsiStringError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EJclAnsiStringListError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : EJclAnsiStringError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EJclAnsiStringListError(System::NativeUInt Ident)/* overload */ : EJclAnsiStringError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EJclAnsiStringListError(System::PResStringRec ResStringRec)/* overload */ : EJclAnsiStringError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclAnsiStringListError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EJclAnsiStringError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclAnsiStringListError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : EJclAnsiStringError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclAnsiStringListError(const System::UnicodeString Msg, int AHelpContext) : EJclAnsiStringError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclAnsiStringListError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : EJclAnsiStringError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclAnsiStringListError(System::NativeUInt Ident, int AHelpContext)/* overload */ : EJclAnsiStringError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclAnsiStringListError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EJclAnsiStringError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAnsiStringListError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EJclAnsiStringError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclAnsiStringListError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : EJclAnsiStringError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclAnsiStringListError() { }
	
};

#pragma pack(pop)

typedef char * *PAnsiCharVector;

typedef char * PAnsiMultiSz;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST char AnsiNull = '\0';
static _DELPHI_CONST char AnsiSoh = '\x01';
static _DELPHI_CONST char AnsiStx = '\x02';
static _DELPHI_CONST char AnsiEtx = '\x03';
static _DELPHI_CONST char AnsiEot = '\x04';
static _DELPHI_CONST char AnsiEnq = '\x05';
static _DELPHI_CONST char AnsiAck = '\x06';
static _DELPHI_CONST char AnsiBell = '\x07';
static _DELPHI_CONST char AnsiBackspace = '\x08';
static _DELPHI_CONST char AnsiTab = '\x09';
static _DELPHI_CONST char AnsiLineFeed = '\x0a';
static _DELPHI_CONST char AnsiVerticalTab = '\x0b';
static _DELPHI_CONST char AnsiFormFeed = '\x0c';
static _DELPHI_CONST char AnsiCarriageReturn = '\x0d';
#define AnsiCrLf "\r\n"
static _DELPHI_CONST char AnsiSo = '\x0e';
static _DELPHI_CONST char AnsiSi = '\x0f';
static _DELPHI_CONST char AnsiDle = '\x10';
static _DELPHI_CONST char AnsiDc1 = '\x11';
static _DELPHI_CONST char AnsiDc2 = '\x12';
static _DELPHI_CONST char AnsiDc3 = '\x13';
static _DELPHI_CONST char AnsiDc4 = '\x14';
static _DELPHI_CONST char AnsiNak = '\x15';
static _DELPHI_CONST char AnsiSyn = '\x16';
static _DELPHI_CONST char AnsiEtb = '\x17';
static _DELPHI_CONST char AnsiCan = '\x18';
static _DELPHI_CONST char AnsiEm = '\x19';
static _DELPHI_CONST char AnsiEndOfFile = '\x1a';
static _DELPHI_CONST char AnsiEscape = '\x1b';
static _DELPHI_CONST char AnsiFs = '\x1c';
static _DELPHI_CONST char AnsiGs = '\x1d';
static _DELPHI_CONST char AnsiRs = '\x1e';
static _DELPHI_CONST char AnsiUs = '\x1f';
static _DELPHI_CONST char AnsiSpace = '\x20';
static _DELPHI_CONST char AnsiComma = '\x2c';
static _DELPHI_CONST char AnsiBackslash = '\x5c';
static _DELPHI_CONST char AnsiForwardSlash = '\x2f';
static _DELPHI_CONST char AnsiDoubleQuote = '\x22';
static _DELPHI_CONST char AnsiSingleQuote = '\x27';
#define AnsiLineBreak "\r\n"
static _DELPHI_CONST char AnsiSignMinus = '\x2d';
static _DELPHI_CONST char AnsiSignPlus = '\x2b';
#define AnsiWhiteSpace (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x9' << '\xa' << '\xb' << '\xc' << '\xd' << '\x20' )
#define AnsiSigns (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x2b' << '\x2d' )
#define AnsiUppercaseLetters (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x5a' )
#define AnsiLowercaseLetters (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' )
#define AnsiLetters (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x5a' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' )
#define AnsiDecDigits (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' )
#define AnsiOctDigits (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' )
#define AnsiHexDigits (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' )
#define AnsiValidIdentifierLetters (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x30' << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' << '\x37' << '\x38' << '\x39' << '\x41' << '\x42' << '\x43' << '\x44' << '\x45' << '\x46' << '\x47' << '\x48' << '\x49' << '\x4a' << '\x4b' << '\x4c' << '\x4d' << '\x4e' << '\x4f' << '\x50' << '\x51' << '\x52' << '\x53' << '\x54' << '\x55' << '\x56' << '\x57' << '\x58' << '\x59' << '\x5a' << '\x5f' << '\x61' << '\x62' << '\x63' << '\x64' << '\x65' << '\x66' << '\x67' << '\x68' << '\x69' << '\x6a' << '\x6b' << '\x6c' << '\x6d' << '\x6e' << '\x6f' << '\x70' << '\x71' << '\x72' << '\x73' << '\x74' << '\x75' << '\x76' << '\x77' << '\x78' << '\x79' << '\x7a' )
static _DELPHI_CONST System::Word AnsiCharCount = System::Word(0x100);
static _DELPHI_CONST System::Int8 AnsiLoOffset = System::Int8(0x0);
static _DELPHI_CONST System::Word AnsiUpOffset = System::Word(0x100);
static _DELPHI_CONST System::Word AnsiReOffset = System::Word(0x200);
static _DELPHI_CONST System::Word AnsiCaseMapSize = System::Word(0x300);
extern DELPHI_PACKAGE System::StaticArray<char, 768> AnsiCaseMap;
extern DELPHI_PACKAGE bool AnsiCaseMapReady;
extern DELPHI_PACKAGE System::StaticArray<System::Word, 256> AnsiCharTypes;
extern DELPHI_PACKAGE bool __fastcall StrIsAlpha(const System::AnsiString S);
extern DELPHI_PACKAGE bool __fastcall StrIsAlphaNum(const System::AnsiString S);
extern DELPHI_PACKAGE bool __fastcall StrConsistsOfNumberChars(const System::AnsiString S);
extern DELPHI_PACKAGE bool __fastcall StrContainsChars(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars, bool CheckAll);
extern DELPHI_PACKAGE bool __fastcall StrIsAlphaNumUnderscore(const System::AnsiString S);
extern DELPHI_PACKAGE bool __fastcall StrIsDigit(const System::AnsiString S);
extern DELPHI_PACKAGE bool __fastcall StrIsSubset(const System::AnsiString S, const System::Sysutils::TSysCharSet &ValidChars);
extern DELPHI_PACKAGE bool __fastcall StrSame(const System::AnsiString S1, const System::AnsiString S2);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrCenter(const System::AnsiString S, Jclbase::SizeInt L, char C = '\x20');
extern DELPHI_PACKAGE System::AnsiString __fastcall StrCharPosLower(const System::AnsiString S, Jclbase::SizeInt CharPos);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrCharPosUpper(const System::AnsiString S, Jclbase::SizeInt CharPos);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrDoubleQuote(const System::AnsiString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrEnsureNoPrefix(const System::AnsiString Prefix, const System::AnsiString Text);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrEnsureNoSuffix(const System::AnsiString Suffix, const System::AnsiString Text);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrEnsurePrefix(const System::AnsiString Prefix, const System::AnsiString Text);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrEnsureSuffix(const System::AnsiString Suffix, const System::AnsiString Text);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrEscapedToString(const System::AnsiString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrLower(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrLowerInPlace(System::AnsiString &S);
extern DELPHI_PACKAGE void __fastcall StrLowerBuff(char * S);
extern DELPHI_PACKAGE void __fastcall StrMove(System::AnsiString &Dest, const System::AnsiString Source, const Jclbase::SizeInt ToIndex, const Jclbase::SizeInt FromIndex, const Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrPadLeft(const System::AnsiString S, Jclbase::SizeInt Len, char C = '\x20');
extern DELPHI_PACKAGE System::AnsiString __fastcall StrPadRight(const System::AnsiString S, Jclbase::SizeInt Len, char C = '\x20');
extern DELPHI_PACKAGE System::AnsiString __fastcall StrProper(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrProperBuff(char * S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrQuote(const System::AnsiString S, char C);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrRemoveChars(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrKeepChars(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrRepeat(const System::AnsiString S, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrRepeatLength(const System::AnsiString S, const Jclbase::SizeInt L);
extern DELPHI_PACKAGE void __fastcall StrReplace(System::AnsiString &S, const System::AnsiString Search, const System::AnsiString Replace, System::Sysutils::TReplaceFlags Flags = System::Sysutils::TReplaceFlags() );
extern DELPHI_PACKAGE System::AnsiString __fastcall StrReplaceChar(const System::AnsiString S, const char Source, const char Replace);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrReplaceChars(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars, char Replace);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrReplaceButChars(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars, char Replace);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrReverse(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrReverseInPlace(System::AnsiString &S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrSingleQuote(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrSkipChars(char * &S, const System::Sysutils::TSysCharSet &Chars)/* overload */;
extern DELPHI_PACKAGE void __fastcall StrSkipChars(const System::AnsiString S, Jclbase::SizeInt &Index, const System::Sysutils::TSysCharSet &Chars)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall StrSmartCase(const System::AnsiString S, const System::Sysutils::TSysCharSet &Delimiters);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrStringToEscaped(const System::AnsiString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrStripNonNumberChars(const System::AnsiString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrToHex(const System::AnsiString Source);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrTrimCharLeft(const System::AnsiString S, char C);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrTrimCharsLeft(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrTrimCharsRight(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrTrimCharRight(const System::AnsiString S, char C);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrTrimQuotes(const System::AnsiString S)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall StrTrimQuotes(const System::AnsiString S, char QuoteChar)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall StrUpper(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrUpperInPlace(System::AnsiString &S);
extern DELPHI_PACKAGE void __fastcall StrUpperBuff(char * S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrOemToAnsi(const System::AnsiString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrAnsiToOem(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrAddRef(System::AnsiString &S);
extern DELPHI_PACKAGE void __fastcall StrDecRef(System::AnsiString &S);
extern DELPHI_PACKAGE System::LongInt __fastcall StrLength(const System::AnsiString S);
extern DELPHI_PACKAGE System::LongInt __fastcall StrRefCount(const System::AnsiString S);
extern DELPHI_PACKAGE void __fastcall StrResetLength(System::AnsiString &S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCharCount(const System::AnsiString S, char C);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCharsCount(const System::AnsiString S, const System::Sysutils::TSysCharSet &Chars);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrStrCount(const System::AnsiString S, const System::AnsiString SubS);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCompareRangeEx(const System::AnsiString S1, const System::AnsiString S2, Jclbase::SizeInt Index, Jclbase::SizeInt Count, bool CaseSensitive = false);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCompare(const System::AnsiString S1, const System::AnsiString S2, bool CaseSensitive = false);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrCompareRange(const System::AnsiString S1, const System::AnsiString S2, Jclbase::SizeInt Index, Jclbase::SizeInt Count, bool CaseSensitive = true);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrRepeatChar(char C, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrFind(const System::AnsiString Substr, const System::AnsiString S, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE bool __fastcall StrHasPrefix(const System::AnsiString S, const System::AnsiString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE bool __fastcall StrHasSuffix(const System::AnsiString S, const System::AnsiString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE bool __fastcall StrIHasPrefix(const System::AnsiString S, const System::AnsiString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE bool __fastcall StrIHasSuffix(const System::AnsiString S, const System::AnsiString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrIndex(const System::AnsiString S, const System::AnsiString *List, const System::NativeInt List_High, bool CaseSensitive = false);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrILastPos(const System::AnsiString SubStr, const System::AnsiString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrIPos(const System::AnsiString SubStr, const System::AnsiString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrIPrefixIndex(const System::AnsiString S, const System::AnsiString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE bool __fastcall StrIsOneOf(const System::AnsiString S, const System::AnsiString *List, const System::NativeInt List_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrISuffixIndex(const System::AnsiString S, const System::AnsiString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrLastPos(const System::AnsiString SubStr, const System::AnsiString S);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrMatch(const System::AnsiString Substr, const System::AnsiString S, Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE bool __fastcall StrMatches(const System::AnsiString Substr, const System::AnsiString S, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrNPos(const System::AnsiString S, const System::AnsiString SubStr, Jclbase::SizeInt N);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrNIPos(const System::AnsiString S, const System::AnsiString SubStr, Jclbase::SizeInt N);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrPrefixIndex(const System::AnsiString S, const System::AnsiString *Prefixes, const System::NativeInt Prefixes_High);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrSearch(const System::AnsiString Substr, const System::AnsiString S, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall StrSuffixIndex(const System::AnsiString S, const System::AnsiString *Suffixes, const System::NativeInt Suffixes_High);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrAfter(const System::AnsiString SubStr, const System::AnsiString S);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrBefore(const System::AnsiString SubStr, const System::AnsiString S);
extern DELPHI_PACKAGE bool __fastcall StrSplit(const System::AnsiString SubStr, const System::AnsiString S, System::AnsiString &Left, System::AnsiString &Right);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrBetween(const System::AnsiString S, const char Start, const char Stop);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrChopRight(const System::AnsiString S, Jclbase::SizeInt N);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrLeft(const System::AnsiString S, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrMid(const System::AnsiString S, Jclbase::SizeInt Start, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrRestOf(const System::AnsiString S, Jclbase::SizeInt N);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrRight(const System::AnsiString S, Jclbase::SizeInt Count);
extern DELPHI_PACKAGE bool __fastcall CharEqualNoCase(const char C1, const char C2);
extern DELPHI_PACKAGE bool __fastcall CharIsAlpha(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsAlphaNum(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsBlank(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsControl(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsDelete(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsDigit(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsFracDigit(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsHexDigit(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsLower(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsNumberChar(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsNumber(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsPrintable(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsPunctuation(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsReturn(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsSpace(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsUpper(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsValidIdentifierLetter(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsWhiteSpace(const char C);
extern DELPHI_PACKAGE bool __fastcall CharIsWildcard(const char C);
extern DELPHI_PACKAGE System::Word __fastcall CharType(const char C);
extern DELPHI_PACKAGE PAnsiCharVector __fastcall StringsToPCharVector(PAnsiCharVector &Dest, TJclAnsiStrings* const Source);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall PCharVectorCount(PAnsiCharVector Source);
extern DELPHI_PACKAGE void __fastcall PCharVectorToStrings(TJclAnsiStrings* const Dest, PAnsiCharVector Source);
extern DELPHI_PACKAGE void __fastcall FreePCharVector(PAnsiCharVector &Dest);
extern DELPHI_PACKAGE System::Byte __fastcall CharHex(const char C);
extern DELPHI_PACKAGE char __fastcall CharLower(const char C);
extern DELPHI_PACKAGE char __fastcall CharToggleCase(const char C);
extern DELPHI_PACKAGE char __fastcall CharUpper(const char C);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharLastPos(const System::AnsiString S, const char C, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharPos(const System::AnsiString S, const char C, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharIPos(const System::AnsiString S, char C, const Jclbase::SizeInt Index = 0x1);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall CharReplace(System::AnsiString &S, const char Search, const char Replace);
extern DELPHI_PACKAGE PAnsiMultiSz __fastcall StringsToMultiSz(PAnsiMultiSz &Dest, TJclAnsiStrings* const Source);
extern DELPHI_PACKAGE void __fastcall MultiSzToStrings(TJclAnsiStrings* const Dest, const PAnsiMultiSz Source);
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall MultiSzLength(const PAnsiMultiSz Source);
extern DELPHI_PACKAGE void __fastcall AllocateMultiSz(PAnsiMultiSz &Dest, Jclbase::SizeInt Len);
extern DELPHI_PACKAGE void __fastcall FreeMultiSz(PAnsiMultiSz &Dest);
extern DELPHI_PACKAGE PAnsiMultiSz __fastcall MultiSzDup(const PAnsiMultiSz Source);
extern DELPHI_PACKAGE void __fastcall StrToStrings(System::AnsiString S, System::AnsiString Sep, TJclAnsiStrings* const List, const bool AllowEmptyString = true);
extern DELPHI_PACKAGE void __fastcall StrIToStrings(System::AnsiString S, System::AnsiString Sep, TJclAnsiStrings* const List, const bool AllowEmptyString = true);
extern DELPHI_PACKAGE System::AnsiString __fastcall StringsToStr(TJclAnsiStrings* const List, const System::AnsiString Sep, const bool AllowEmptyString = true);
extern DELPHI_PACKAGE void __fastcall TrimStrings(TJclAnsiStrings* const List, bool DeleteIfEmpty = true);
extern DELPHI_PACKAGE void __fastcall TrimStringsRight(TJclAnsiStrings* const List, bool DeleteIfEmpty = true);
extern DELPHI_PACKAGE void __fastcall TrimStringsLeft(TJclAnsiStrings* const List, bool DeleteIfEmpty = true);
extern DELPHI_PACKAGE bool __fastcall AddStringToStrings(const System::AnsiString S, TJclAnsiStrings* Strings, const bool Unique);
extern DELPHI_PACKAGE System::AnsiString __fastcall FileToString(const System::Sysutils::TFileName FileName);
extern DELPHI_PACKAGE void __fastcall StringToFile(const System::Sysutils::TFileName FileName, const System::AnsiString Contents, bool Append = false);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrToken(System::AnsiString &S, char Separator);
extern DELPHI_PACKAGE void __fastcall StrTokens(const System::AnsiString S, TJclAnsiStrings* const List);
extern DELPHI_PACKAGE void __fastcall StrTokenToStrings(System::AnsiString S, char Separator, TJclAnsiStrings* const List);
extern DELPHI_PACKAGE bool __fastcall StrWord(const System::AnsiString S, Jclbase::SizeInt &Index, /* out */ System::AnsiString &Word)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrWord(char * &S, /* out */ System::AnsiString &Word)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIdent(const System::AnsiString S, Jclbase::SizeInt &Index, /* out */ System::AnsiString &Ident)/* overload */;
extern DELPHI_PACKAGE bool __fastcall StrIdent(char * &S, /* out */ System::AnsiString &Ident)/* overload */;
extern DELPHI_PACKAGE Jclbase::Float __fastcall StrToFloatSafe(const System::AnsiString S);
extern DELPHI_PACKAGE int __fastcall StrToIntSafe(const System::AnsiString S);
extern DELPHI_PACKAGE Jclbase::TDynStringArray __fastcall ArrayOf(TJclAnsiStrings* List)/* overload */;
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall AnsiCompareNaturalStr(const System::AnsiString S1, const System::AnsiString S2)/* overload */;
extern DELPHI_PACKAGE Jclbase::SizeInt __fastcall AnsiCompareNaturalText(const System::AnsiString S1, const System::AnsiString S2)/* overload */;
extern DELPHI_PACKAGE char * __fastcall StrNewA(const char * Str);
extern DELPHI_PACKAGE void __fastcall StrDisposeA(char * Str);
extern DELPHI_PACKAGE int __fastcall StrLenA(char * S);
extern DELPHI_PACKAGE char * __fastcall StrEndA(const char * Str);
extern DELPHI_PACKAGE char * __fastcall StrPosA(const char * Str1, const char * Str2);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrPasA(const char * Str);
extern DELPHI_PACKAGE char * __fastcall StrCopyA(char * Dest, const char * Source);
extern DELPHI_PACKAGE char * __fastcall StrLCopyA(char * Dest, const char * Source, unsigned MaxLen);
extern DELPHI_PACKAGE char * __fastcall StrPCopyA(char * Dest, const System::AnsiString Source);
extern DELPHI_PACKAGE char * __fastcall StrPLCopyA(char * Dest, const System::AnsiString Source, unsigned MaxLen);
extern DELPHI_PACKAGE char * __fastcall StrECopyA(char * Dest, const char * Source);
extern DELPHI_PACKAGE char * __fastcall StrCatA(char * Dest, const char * Source);
extern DELPHI_PACKAGE char * __fastcall StrLCatA(char * Dest, const char * Source, unsigned MaxLen);
extern DELPHI_PACKAGE int __fastcall StrCompA(const char * Str1, const char * Str2);
extern DELPHI_PACKAGE int __fastcall StrLCompA(const char * Str1, const char * Str2, unsigned MaxLen);
extern DELPHI_PACKAGE int __fastcall StrICompA(const char * Str1, const char * Str2);
extern DELPHI_PACKAGE int __fastcall StrLICompA(const char * Str1, const char * Str2, unsigned MaxLen);
extern DELPHI_PACKAGE char * __fastcall StrFmtA(char * Buffer, char * Format, const System::TVarRec *Args, const System::NativeInt Args_High);
extern DELPHI_PACKAGE char * __fastcall AnsiStrPosA(const char * Str1, const char * Str2);
extern DELPHI_PACKAGE int __fastcall AnsiStrLICompA(char * S1, char * S2, unsigned MaxLen);
extern DELPHI_PACKAGE int __fastcall AnsiStrLCompA(char * S1, char * S2, unsigned MaxLen);
}	/* namespace Jclansistrings */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLANSISTRINGS)
using namespace Jclansistrings;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclAnsiStringsHPP
