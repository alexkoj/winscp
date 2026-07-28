// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclDebug.pas' rev: 37.00 (Windows)

#ifndef JclDebugHPP
#define JclDebugHPP

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
#include <System.Contnrs.hpp>
#include <JclBase.hpp>
#include <JclFileUtils.hpp>
#include <JclPeImage.hpp>
#include <JclSynch.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jcldebug
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TJclModuleInfo;
class DELPHICLASS TJclModuleInfoList;
struct TJclMapAddress;
class DELPHICLASS TJclAbstractMapParser;
class DELPHICLASS TJclMapParser;
struct TJclMapStringCache;
struct TJclMapSegmentClass;
struct TJclMapSegment;
struct TJclMapProcName;
struct TJclMapLineNumber;
class DELPHICLASS TJclMapScanner;
struct TJclDbgHeader;
class DELPHICLASS TJclBinDebugGenerator;
struct TJclBinDbgNameCache;
class DELPHICLASS TJclBinDebugScanner;
struct TJclLocationInfo;
class DELPHICLASS TJclLocationInfoEx;
class DELPHICLASS TJclCustomLocationInfoList;
class DELPHICLASS TJclLocationInfoList;
class DELPHICLASS TJclDebugInfoSource;
class DELPHICLASS TJclDebugInfoList;
class DELPHICLASS TJclDebugInfoMap;
class DELPHICLASS TJclDebugInfoBinary;
class DELPHICLASS TJclDebugInfoExports;
class DELPHICLASS TJclDebugInfoSymbols;
class DELPHICLASS TJclStackBaseList;
struct TStackFrame;
struct TStackInfo;
class DELPHICLASS TJclStackInfoItem;
class DELPHICLASS TJclStackInfoList;
struct TJmpInstruction;
struct TExcDescEntry;
struct TExcDesc;
struct TExcFrame;
struct TJmpTable;
class DELPHICLASS TJclExceptFrame;
class DELPHICLASS TJclExceptFrameList;
class DELPHICLASS TJclDebugThread;
class DELPHICLASS TJclDebugThreadList;
class DELPHICLASS TJclDebugThreadInfo;
class DELPHICLASS TJclCustomThreadInfo;
class DELPHICLASS TJclThreadInfo;
class DELPHICLASS TJclThreadInfoList;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclModuleInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FSize;
	void *FEndAddr;
	void *FStartAddr;
	bool FSystemModule;
	
public:
	__property void * EndAddr = {read=FEndAddr};
	__property unsigned Size = {read=FSize, nodefault};
	__property void * StartAddr = {read=FStartAddr};
	__property bool SystemModule = {read=FSystemModule, nodefault};
public:
	/* TObject.Create */ inline __fastcall TJclModuleInfo() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJclModuleInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclModuleInfoList : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
private:
	bool FDynamicBuild;
	bool FSystemModulesOnly;
	int FRefCount;
	TJclModuleInfo* __fastcall GetItems(Jclbase::TJclListSize Index);
	TJclModuleInfo* __fastcall GetModuleFromAddress(void * Addr);
	
protected:
	void __fastcall BuildModulesList();
	TJclModuleInfo* __fastcall CreateItemForAddress(void * Addr, bool SystemModule);
	
public:
	__fastcall TJclModuleInfoList(bool ADynamicBuild, bool ASystemModulesOnly);
	bool __fastcall AddModule(unsigned Module, bool SystemModule);
	bool __fastcall IsSystemModuleAddress(void * Addr);
	bool __fastcall IsValidModuleAddress(void * Addr);
	__property bool DynamicBuild = {read=FDynamicBuild, nodefault};
	__property TJclModuleInfo* Items[Jclbase::TJclListSize Index] = {read=GetItems};
	__property TJclModuleInfo* ModuleFromAddress[void * Addr] = {read=GetModuleFromAddress};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TJclModuleInfoList() { }
	
};

#pragma pack(pop)

typedef TJclMapAddress *PJclMapAddress;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TJclMapAddress
{
public:
	System::Word Segment;
	Jclbase::TJclAddr Offset;
};
#pragma pack(pop)


typedef char * PJclMapString;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclAbstractMapParser : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FLinkerBug;
	PJclMapString FLinkerBugUnitName;
	Jclfileutils::TJclFileMappingStream* FStream;
	System::UnicodeString __fastcall GetLinkerBugUnitName();
	
protected:
	unsigned FModule;
	PJclMapString FLastUnitName;
	PJclMapString FLastUnitFileName;
	virtual void __fastcall ClassTableItem(const TJclMapAddress &Address, int Len, PJclMapString SectionName, PJclMapString GroupName) = 0 ;
	virtual void __fastcall SegmentItem(const TJclMapAddress &Address, int Len, PJclMapString GroupName, PJclMapString UnitName) = 0 ;
	virtual bool __fastcall CanHandlePublicsByName() = 0 ;
	virtual bool __fastcall CanHandlePublicsByValue() = 0 ;
	virtual void __fastcall PublicsByNameItem(const TJclMapAddress &Address, PJclMapString Name) = 0 ;
	virtual void __fastcall PublicsByValueItem(const TJclMapAddress &Address, PJclMapString Name) = 0 ;
	virtual void __fastcall LineNumberUnitItem(PJclMapString UnitName, PJclMapString UnitFileName) = 0 ;
	virtual void __fastcall LineNumbersItem(int LineNumber, const TJclMapAddress &Address) = 0 ;
	
public:
	__fastcall virtual TJclAbstractMapParser(const System::Sysutils::TFileName MapFileName, unsigned Module)/* overload */;
	__fastcall TJclAbstractMapParser(const System::Sysutils::TFileName MapFileName)/* overload */;
	__fastcall virtual ~TJclAbstractMapParser();
	void __fastcall Parse();
	__classmethod System::UnicodeString __fastcall MapStringToFileName(PJclMapString MapString);
	__classmethod System::UnicodeString __fastcall MapStringToModuleName(PJclMapString MapString);
	__classmethod System::UnicodeString __fastcall MapStringToStr(PJclMapString MapString, bool IgnoreSpaces = false);
	__property bool LinkerBug = {read=FLinkerBug, nodefault};
	__property System::UnicodeString LinkerBugUnitName = {read=GetLinkerBugUnitName};
	__property Jclfileutils::TJclFileMappingStream* Stream = {read=FStream};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TJclMapClassTableEvent)(System::TObject* Sender, const TJclMapAddress &Address, int Len, const System::UnicodeString SectionName, const System::UnicodeString GroupName);

typedef void __fastcall (__closure *TJclMapSegmentEvent)(System::TObject* Sender, const TJclMapAddress &Address, int Len, const System::UnicodeString GroupName, const System::UnicodeString UnitName);

typedef void __fastcall (__closure *TJclMapPublicsEvent)(System::TObject* Sender, const TJclMapAddress &Address, const System::UnicodeString Name);

typedef void __fastcall (__closure *TJclMapLineNumberUnitEvent)(System::TObject* Sender, const System::UnicodeString UnitName, const System::UnicodeString UnitFileName);

typedef void __fastcall (__closure *TJclMapLineNumbersEvent)(System::TObject* Sender, int LineNumber, const TJclMapAddress &Address);

class PASCALIMPLEMENTATION TJclMapParser : public TJclAbstractMapParser
{
	typedef TJclAbstractMapParser inherited;
	
private:
	TJclMapClassTableEvent FOnClassTable;
	TJclMapLineNumbersEvent FOnLineNumbers;
	TJclMapLineNumberUnitEvent FOnLineNumberUnit;
	TJclMapPublicsEvent FOnPublicsByValue;
	TJclMapPublicsEvent FOnPublicsByName;
	TJclMapSegmentEvent FOnSegmentItem;
	
protected:
	virtual void __fastcall ClassTableItem(const TJclMapAddress &Address, int Len, PJclMapString SectionName, PJclMapString GroupName);
	virtual void __fastcall SegmentItem(const TJclMapAddress &Address, int Len, PJclMapString GroupName, PJclMapString UnitName);
	virtual bool __fastcall CanHandlePublicsByName();
	virtual bool __fastcall CanHandlePublicsByValue();
	virtual void __fastcall PublicsByNameItem(const TJclMapAddress &Address, PJclMapString Name);
	virtual void __fastcall PublicsByValueItem(const TJclMapAddress &Address, PJclMapString Name);
	virtual void __fastcall LineNumberUnitItem(PJclMapString UnitName, PJclMapString UnitFileName);
	virtual void __fastcall LineNumbersItem(int LineNumber, const TJclMapAddress &Address);
	
public:
	__property TJclMapClassTableEvent OnClassTable = {read=FOnClassTable, write=FOnClassTable};
	__property TJclMapSegmentEvent OnSegment = {read=FOnSegmentItem, write=FOnSegmentItem};
	__property TJclMapPublicsEvent OnPublicsByName = {read=FOnPublicsByName, write=FOnPublicsByName};
	__property TJclMapPublicsEvent OnPublicsByValue = {read=FOnPublicsByValue, write=FOnPublicsByValue};
	__property TJclMapLineNumberUnitEvent OnLineNumberUnit = {read=FOnLineNumberUnit, write=FOnLineNumberUnit};
	__property TJclMapLineNumbersEvent OnLineNumbers = {read=FOnLineNumbers, write=FOnLineNumbers};
public:
	/* TJclAbstractMapParser.Create */ inline __fastcall virtual TJclMapParser(const System::Sysutils::TFileName MapFileName, unsigned Module)/* overload */ : TJclAbstractMapParser(MapFileName, Module) { }
	/* TJclAbstractMapParser.Create */ inline __fastcall TJclMapParser(const System::Sysutils::TFileName MapFileName)/* overload */ : TJclAbstractMapParser(MapFileName) { }
	/* TJclAbstractMapParser.Destroy */ inline __fastcall virtual ~TJclMapParser() { }
	
};


struct DECLSPEC_DRECORD TJclMapStringCache
{
public:
	System::UnicodeString CachedValue;
	PJclMapString RawValue;
	bool TLS;
};


typedef TJclMapSegmentClass *PJclMapSegmentClass;

struct DECLSPEC_DRECORD TJclMapSegmentClass
{
public:
	System::Word Segment;
	unsigned Start;
	unsigned Addr;
	unsigned VA;
	unsigned Len;
	TJclMapStringCache SectionName;
	TJclMapStringCache GroupName;
};


typedef TJclMapSegment *PJclMapSegment;

struct DECLSPEC_DRECORD TJclMapSegment
{
public:
	System::Word Segment;
	unsigned StartVA;
	unsigned EndVA;
	TJclMapStringCache UnitName;
};


typedef TJclMapProcName *PJclMapProcName;

struct DECLSPEC_DRECORD TJclMapProcName
{
public:
	System::Word Segment;
	unsigned VA;
	TJclMapStringCache ProcName;
};


typedef TJclMapLineNumber *PJclMapLineNumber;

struct DECLSPEC_DRECORD TJclMapLineNumber
{
public:
	System::Word Segment;
	unsigned VA;
	int LineNumber;
	PJclMapString UnitName;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclMapScanner : public TJclAbstractMapParser
{
	typedef TJclAbstractMapParser inherited;
	
	
private:
	typedef System::DynamicArray<TJclMapSegmentClass> _TJclMapScanner__1;
	
	typedef System::DynamicArray<TJclMapLineNumber> _TJclMapScanner__2;
	
	typedef System::DynamicArray<TJclMapProcName> _TJclMapScanner__3;
	
	typedef System::DynamicArray<TJclMapSegment> _TJclMapScanner__4;
	
	typedef System::DynamicArray<TJclMapProcName> _TJclMapScanner__5;
	
	
private:
	_TJclMapScanner__1 FSegmentClasses;
	_TJclMapScanner__2 FLineNumbers;
	_TJclMapScanner__3 FProcNames;
	_TJclMapScanner__4 FSegments;
	_TJclMapScanner__5 FSourceNames;
	int FLineNumbersCnt;
	int FLineNumberErrors;
	PJclMapString FNewUnitFileName;
	PJclMapString FCurrentUnitName;
	int FProcNamesCnt;
	int FSegmentCnt;
	int FLastAccessedSegementIndex;
	int __fastcall IndexOfSegment(unsigned Addr);
	
protected:
	unsigned __fastcall MAPAddrToVA(const unsigned Addr);
	virtual void __fastcall ClassTableItem(const TJclMapAddress &Address, int Len, PJclMapString SectionName, PJclMapString GroupName);
	virtual void __fastcall SegmentItem(const TJclMapAddress &Address, int Len, PJclMapString GroupName, PJclMapString UnitName);
	virtual bool __fastcall CanHandlePublicsByName();
	virtual bool __fastcall CanHandlePublicsByValue();
	virtual void __fastcall PublicsByNameItem(const TJclMapAddress &Address, PJclMapString Name);
	virtual void __fastcall PublicsByValueItem(const TJclMapAddress &Address, PJclMapString Name);
	virtual void __fastcall LineNumbersItem(int LineNumber, const TJclMapAddress &Address);
	virtual void __fastcall LineNumberUnitItem(PJclMapString UnitName, PJclMapString UnitFileName);
	void __fastcall Scan();
	TJclMapLineNumber __fastcall GetLineNumberByIndex(int Index);
	
public:
	__fastcall virtual TJclMapScanner(const System::Sysutils::TFileName MapFileName, unsigned Module)/* overload */;
	__classmethod System::UnicodeString __fastcall MapStringCacheToFileName(TJclMapStringCache &MapString);
	__classmethod System::UnicodeString __fastcall MapStringCacheToModuleName(TJclMapStringCache &MapString);
	__classmethod System::UnicodeString __fastcall MapStringCacheToStr(TJclMapStringCache &MapString, bool IgnoreSpaces = false);
	int __fastcall LineNumberFromAddr(unsigned Addr)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	System::UnicodeString __fastcall ModuleNameFromAddr(unsigned Addr);
	unsigned __fastcall ModuleStartFromAddr(unsigned Addr);
	System::UnicodeString __fastcall ProcNameFromAddr(unsigned Addr)/* overload */;
	System::UnicodeString __fastcall ProcNameFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	System::UnicodeString __fastcall SourceNameFromAddr(unsigned Addr);
	unsigned __fastcall VAFromUnitAndProcName(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
	__property int LineNumberErrors = {read=FLineNumberErrors, nodefault};
	__property int LineNumbersCnt = {read=FLineNumbersCnt, nodefault};
	__property TJclMapLineNumber LineNumberByIndex[int Index] = {read=GetLineNumberByIndex};
public:
	/* TJclAbstractMapParser.Create */ inline __fastcall TJclMapScanner(const System::Sysutils::TFileName MapFileName)/* overload */ : TJclAbstractMapParser(MapFileName) { }
	/* TJclAbstractMapParser.Destroy */ inline __fastcall virtual ~TJclMapScanner() { }
	
};

#pragma pack(pop)

typedef TJclDbgHeader *PJclDbgHeader;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TJclDbgHeader
{
public:
	unsigned Signature;
	System::Byte Version;
	int Units;
	int SourceNames;
	int Symbols;
	int LineNumbers;
	int Words;
	int ModuleName;
	int CheckSum;
	bool CheckSumValid;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclBinDebugGenerator : public TJclMapScanner
{
	typedef TJclMapScanner inherited;
	
private:
	System::Classes::TMemoryStream* FDataStream;
	System::Sysutils::TFileName FMapFileName;
	
protected:
	void __fastcall CreateData();
	
public:
	__fastcall virtual TJclBinDebugGenerator(const System::Sysutils::TFileName MapFileName, unsigned Module)/* overload */;
	__fastcall virtual ~TJclBinDebugGenerator();
	bool __fastcall CalculateCheckSum();
	__property System::Classes::TMemoryStream* DataStream = {read=FDataStream};
public:
	/* TJclAbstractMapParser.Create */ inline __fastcall TJclBinDebugGenerator(const System::Sysutils::TFileName MapFileName)/* overload */ : TJclMapScanner(MapFileName) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TJclBinDbgNameCache
{
public:
	unsigned Addr;
	int FirstWord;
	int SecondWord;
	System::UnicodeString Text;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclBinDebugScanner : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TJclMapLineNumber> _TJclBinDebugScanner__1;
	
	typedef System::DynamicArray<TJclBinDbgNameCache> _TJclBinDebugScanner__2;
	
	
private:
	bool FCacheData;
	bool FCacheProcNames;
	System::Classes::TCustomMemoryStream* FStream;
	bool FValidFormat;
	_TJclBinDebugScanner__1 FLineNumbers;
	_TJclBinDebugScanner__2 FProcNames;
	System::UnicodeString __fastcall GetModuleName();
	
protected:
	void __fastcall CacheLineNumbers();
	void __fastcall CacheProcNames();
	void __fastcall CheckFormat();
	System::UnicodeString __fastcall DataToStr(int A);
	void * __fastcall MakePtr(int A);
	static bool __fastcall ReadValue(void * &P, int &Value);
	
public:
	__fastcall TJclBinDebugScanner(System::Classes::TCustomMemoryStream* AStream, bool CacheData, bool CacheProcNames);
	bool __fastcall IsModuleNameValid(const System::Sysutils::TFileName Name);
	int __fastcall LineNumberFromAddr(unsigned Addr)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	System::UnicodeString __fastcall ProcNameFromAddr(unsigned Addr)/* overload */;
	System::UnicodeString __fastcall ProcNameFromAddr(unsigned Addr, /* out */ int &Offset)/* overload */;
	System::UnicodeString __fastcall ModuleNameFromAddr(unsigned Addr);
	unsigned __fastcall ModuleStartFromAddr(unsigned Addr);
	System::UnicodeString __fastcall SourceNameFromAddr(unsigned Addr);
	__property System::UnicodeString ModuleName = {read=GetModuleName};
	__property bool ValidFormat = {read=FValidFormat, nodefault};
	unsigned __fastcall VAFromUnitAndProcName(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclBinDebugScanner() { }
	
};

#pragma pack(pop)

typedef TJclLocationInfo *PJclLocationInfo;

struct DECLSPEC_DRECORD TJclLocationInfo
{
public:
	void *Address;
	System::UnicodeString UnitName;
	System::UnicodeString ProcedureName;
	int OffsetFromProcName;
	int LineNumber;
	int OffsetFromLineNumber;
	System::UnicodeString SourceName;
	TJclDebugInfoSource* DebugInfo;
	System::UnicodeString BinaryFileName;
};


enum DECLSPEC_DENUM Jcldebug__8 : unsigned char { lievLocationInfo, lievProcedureStartLocationInfo, lievUnitVersionInfo };

typedef System::Set<Jcldebug__8, Jcldebug__8::lievLocationInfo, Jcldebug__8::lievUnitVersionInfo> TJclLocationInfoExValues;

enum DECLSPEC_DENUM Jcldebug__9 : unsigned char { liloAutoGetAddressInfo, liloAutoGetLocationInfo, liloAutoGetUnitVersionInfo };

typedef System::Set<Jcldebug__9, Jcldebug__9::liloAutoGetAddressInfo, Jcldebug__9::liloAutoGetUnitVersionInfo> TJclLocationInfoListOptions;

class PASCALIMPLEMENTATION TJclLocationInfoEx : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	void *FAddress;
	System::UnicodeString FBinaryFileName;
	TJclDebugInfoSource* FDebugInfo;
	int FLineNumber;
	int FLineNumberOffsetFromProcedureStart;
	System::UnicodeString FModuleName;
	int FOffsetFromLineNumber;
	int FOffsetFromProcName;
	TJclCustomLocationInfoList* FParent;
	System::UnicodeString FProcedureName;
	System::UnicodeString FSourceName;
	System::UnicodeString FSourceUnitName;
	System::TDateTime FUnitVersionDateTime;
	System::UnicodeString FUnitVersionExtra;
	System::UnicodeString FUnitVersionLogPath;
	System::UnicodeString FUnitVersionRCSfile;
	System::UnicodeString FUnitVersionRevision;
	void *FVAddress;
	TJclLocationInfoExValues FValues;
	void __fastcall Fill(TJclLocationInfoListOptions AOptions);
	System::UnicodeString __fastcall GetAsString();
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
public:
	__fastcall TJclLocationInfoEx(TJclCustomLocationInfoList* AParent, void * Address);
	virtual void __fastcall Clear();
	__property void * Address = {read=FAddress, write=FAddress};
	__property System::UnicodeString AsString = {read=GetAsString};
	__property System::UnicodeString BinaryFileName = {read=FBinaryFileName, write=FBinaryFileName};
	__property TJclDebugInfoSource* DebugInfo = {read=FDebugInfo, write=FDebugInfo};
	__property int LineNumber = {read=FLineNumber, write=FLineNumber, nodefault};
	__property int LineNumberOffsetFromProcedureStart = {read=FLineNumberOffsetFromProcedureStart, write=FLineNumberOffsetFromProcedureStart, nodefault};
	__property System::UnicodeString ModuleName = {read=FModuleName, write=FModuleName};
	__property int OffsetFromLineNumber = {read=FOffsetFromLineNumber, write=FOffsetFromLineNumber, nodefault};
	__property int OffsetFromProcName = {read=FOffsetFromProcName, write=FOffsetFromProcName, nodefault};
	__property System::UnicodeString ProcedureName = {read=FProcedureName, write=FProcedureName};
	__property System::UnicodeString SourceName = {read=FSourceName, write=FSourceName};
	__property System::UnicodeString SourceUnitName = {read=FSourceUnitName, write=FSourceUnitName};
	__property System::TDateTime UnitVersionDateTime = {read=FUnitVersionDateTime, write=FUnitVersionDateTime};
	__property System::UnicodeString UnitVersionExtra = {read=FUnitVersionExtra, write=FUnitVersionExtra};
	__property System::UnicodeString UnitVersionLogPath = {read=FUnitVersionLogPath, write=FUnitVersionLogPath};
	__property System::UnicodeString UnitVersionRCSfile = {read=FUnitVersionRCSfile, write=FUnitVersionRCSfile};
	__property System::UnicodeString UnitVersionRevision = {read=FUnitVersionRevision, write=FUnitVersionRevision};
	__property void * VAddress = {read=FVAddress, write=FVAddress};
	__property TJclLocationInfoExValues Values = {read=FValues, write=FValues, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TJclLocationInfoEx() { }
	
};


typedef System::TMetaClass* TJclLocationInfoClass;

typedef System::TMetaClass* TJclCustomLocationInfoListClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclCustomLocationInfoList : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	TJclLocationInfoClass FItemClass;
	System::Contnrs::TObjectList* FItems;
	TJclLocationInfoListOptions FOptions;
	System::UnicodeString __fastcall GetAsString();
	int __fastcall GetCount();
	TJclLocationInfoEx* __fastcall InternalAdd(void * Addr);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
public:
	__fastcall virtual TJclCustomLocationInfoList();
	__fastcall virtual ~TJclCustomLocationInfoList();
	void __fastcall AddStackInfoList(System::TObject* AStackInfoList);
	void __fastcall Clear();
	__property System::UnicodeString AsString = {read=GetAsString};
	__property int Count = {read=GetCount, nodefault};
	__property TJclLocationInfoListOptions Options = {read=FOptions, write=FOptions, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclLocationInfoList : public TJclCustomLocationInfoList
{
	typedef TJclCustomLocationInfoList inherited;
	
public:
	TJclLocationInfoEx* operator[](int AIndex) { return this->Items[AIndex]; }
	
private:
	TJclLocationInfoEx* __fastcall GetItems(int AIndex);
	
public:
	__fastcall virtual TJclLocationInfoList();
	TJclLocationInfoEx* __fastcall Add(void * Addr);
	__property TJclLocationInfoEx* Items[int AIndex] = {read=GetItems/*, default*/};
public:
	/* TJclCustomLocationInfoList.Destroy */ inline __fastcall virtual ~TJclLocationInfoList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDebugInfoSource : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FModule;
	Jclbase::SizeInt FModuleCodeSize;
	System::Sysutils::TFileName __fastcall GetFileName();
	
protected:
	virtual unsigned __fastcall VAFromAddr(const void * Addr);
	virtual void * __fastcall AddrFromVA(const unsigned VA);
	
public:
	__fastcall virtual TJclDebugInfoSource(unsigned AModule);
	virtual bool __fastcall InitializeSource() = 0 ;
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info) = 0 ;
	virtual void * __fastcall GetAddress(const System::UnicodeString UnitName, const System::UnicodeString ProcName) = 0 ;
	__property unsigned Module = {read=FModule, nodefault};
	__property System::Sysutils::TFileName FileName = {read=GetFileName};
	__property Jclbase::SizeInt ModuleCodeSize = {read=FModuleCodeSize, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDebugInfoSource() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TJclDebugInfoSourceClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDebugInfoList : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
private:
	TJclDebugInfoSource* __fastcall GetItemFromModule(const unsigned Module);
	TJclDebugInfoSource* __fastcall GetItems(Jclbase::TJclListSize Index);
	
protected:
	TJclDebugInfoSource* __fastcall CreateDebugInfo(const unsigned Module);
	
public:
	__classmethod void __fastcall RegisterDebugInfoSource(const TJclDebugInfoSourceClass InfoSourceClass);
	__classmethod void __fastcall UnRegisterDebugInfoSource(const TJclDebugInfoSourceClass InfoSourceClass);
	__classmethod void __fastcall RegisterDebugInfoSourceFirst(const TJclDebugInfoSourceClass InfoSourceClass);
	__classmethod void __fastcall NeedInfoSourceClassList();
	bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
	__property TJclDebugInfoSource* ItemFromModule[const unsigned Module] = {read=GetItemFromModule};
	__property TJclDebugInfoSource* Items[Jclbase::TJclListSize Index] = {read=GetItems};
public:
	/* TObjectList.Create */ inline __fastcall TJclDebugInfoList()/* overload */ : System::Contnrs::TObjectList() { }
	/* TObjectList.Create */ inline __fastcall TJclDebugInfoList(bool AOwnsObjects)/* overload */ : System::Contnrs::TObjectList(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TJclDebugInfoList() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDebugInfoMap : public TJclDebugInfoSource
{
	typedef TJclDebugInfoSource inherited;
	
private:
	TJclMapScanner* FScanner;
	
public:
	__fastcall virtual ~TJclDebugInfoMap();
	virtual bool __fastcall InitializeSource();
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
	virtual void * __fastcall GetAddress(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
public:
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoMap(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDebugInfoBinary : public TJclDebugInfoSource
{
	typedef TJclDebugInfoSource inherited;
	
private:
	TJclBinDebugScanner* FScanner;
	System::Classes::TCustomMemoryStream* FStream;
	
public:
	__fastcall virtual ~TJclDebugInfoBinary();
	virtual bool __fastcall InitializeSource();
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
	virtual void * __fastcall GetAddress(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
public:
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoBinary(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDebugInfoExports : public TJclDebugInfoSource
{
	typedef TJclDebugInfoSource inherited;
	
private:
	Jclpeimage::TJclPeBorImage* FImage;
	bool __fastcall IsAddressInThisExportedFunction(System::Sysutils::PByteArray Addr, Jclbase::TJclAddr FunctionStartAddr);
	
public:
	__fastcall virtual ~TJclDebugInfoExports();
	virtual bool __fastcall InitializeSource();
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
	virtual void * __fastcall GetAddress(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
public:
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoExports(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclDebugInfoSymbols : public TJclDebugInfoSource
{
	typedef TJclDebugInfoSource inherited;
	
public:
	__classmethod bool __fastcall LoadDebugFunctions();
	__classmethod bool __fastcall UnloadDebugFunctions();
	__classmethod bool __fastcall InitializeDebugSymbols();
	__classmethod bool __fastcall CleanupDebugSymbols();
	virtual bool __fastcall InitializeSource();
	virtual bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info);
	virtual void * __fastcall GetAddress(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
public:
	/* TJclDebugInfoSource.Create */ inline __fastcall virtual TJclDebugInfoSymbols(unsigned AModule) : TJclDebugInfoSource(AModule) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDebugInfoSymbols() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TJclStackBaseList : public System::Contnrs::TObjectList
{
	typedef System::Contnrs::TObjectList inherited;
	
private:
	unsigned FThreadID;
	System::TDateTime FTimeStamp;
	
protected:
	System::Classes::TNotifyEvent FOnDestroy;
	
public:
	__fastcall TJclStackBaseList();
	__fastcall virtual ~TJclStackBaseList();
	__property unsigned ThreadID = {read=FThreadID, nodefault};
	__property System::TDateTime TimeStamp = {read=FTimeStamp};
};


typedef System::StaticArray<unsigned, 536870909> TDWORD_PTRArray;

typedef TDWORD_PTRArray *PDWORD_PTRArray;

typedef unsigned *PDWORD_PTR;

typedef TStackFrame *PStackFrame;

struct DECLSPEC_DRECORD TStackFrame
{
public:
	Jclbase::TJclAddr CallerFrame;
	Jclbase::TJclAddr CallerAddr;
};


typedef TStackInfo *PStackInfo;

struct DECLSPEC_DRECORD TStackInfo
{
public:
	Jclbase::TJclAddr CallerAddr;
	int Level;
	Jclbase::TJclAddr CallerFrame;
	unsigned DumpSize;
	unsigned ParamSize;
	PDWORD_PTRArray ParamPtr;
	
public:
	union
	{
		struct 
		{
			Jclbase::PJclByteArray DumpPtr;
		};
		struct 
		{
			PStackFrame StackFrame;
		};
		
	};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclStackInfoItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TStackInfo FStackInfo;
	void * __fastcall GetCallerAddr();
	Jclbase::TJclAddr __fastcall GetLogicalAddress();
	
public:
	__property void * CallerAddr = {read=GetCallerAddr};
	__property Jclbase::TJclAddr LogicalAddress = {read=GetLogicalAddress, nodefault};
	__property TStackInfo StackInfo = {read=FStackInfo};
public:
	/* TObject.Create */ inline __fastcall TJclStackInfoItem() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJclStackInfoItem() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TJclStackInfoList : public TJclStackBaseList
{
	typedef TJclStackBaseList inherited;
	
public:
	TJclStackInfoItem* operator[](Jclbase::TJclListSize Index) { return this->Items[Index]; }
	
private:
	int FIgnoreLevels;
	Jclbase::TJclAddr TopOfStack;
	Jclbase::TJclAddr BaseOfStack;
	Jclbase::PPointer FStackData;
	void *FFramePointer;
	TJclModuleInfoList* FModuleInfoList;
	bool FCorrectOnAccess;
	bool FSkipFirstItem;
	bool FDelayedTrace;
	bool FInStackTracing;
	bool FRaw;
	__int64 FStackOffset;
	TJclStackInfoItem* __fastcall GetItems(Jclbase::TJclListSize Index);
	bool __fastcall NextStackFrame(PStackFrame &StackFrame, TStackInfo &StackInfo);
	void __fastcall StoreToList(const TStackInfo &StackInfo);
	void __fastcall TraceStackFrames();
	void __fastcall TraceStackRaw();
	void __fastcall DelayStoreStack();
	bool __fastcall ValidCallSite(Jclbase::TJclAddr CodeAddr, /* out */ unsigned &CallInstructionSize);
	bool __fastcall ValidStackAddr(Jclbase::TJclAddr StackAddr);
	int __fastcall GetCount();
	void __fastcall CorrectOnAccess(bool ASkipFirstItem);
	
public:
	__fastcall TJclStackInfoList(bool ARaw, int AIgnoreLevels, void * AFirstCaller)/* overload */;
	__fastcall TJclStackInfoList(bool ARaw, int AIgnoreLevels, void * AFirstCaller, bool ADelayedTrace)/* overload */;
	__fastcall TJclStackInfoList(bool ARaw, int AIgnoreLevels, void * AFirstCaller, bool ADelayedTrace, void * ABaseOfStack)/* overload */;
	__fastcall TJclStackInfoList(bool ARaw, int AIgnoreLevels, void * AFirstCaller, bool ADelayedTrace, void * ABaseOfStack, void * ATopOfStack)/* overload */;
	__fastcall virtual ~TJclStackInfoList();
	void __fastcall ForceStackTracing();
	void __fastcall AddToStrings(System::Classes::TStrings* Strings, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
	__property bool DelayedTrace = {read=FDelayedTrace, nodefault};
	__property TJclStackInfoItem* Items[Jclbase::TJclListSize Index] = {read=GetItems/*, default*/};
	__property int IgnoreLevels = {read=FIgnoreLevels, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property bool Raw = {read=FRaw, nodefault};
};


typedef TJmpInstruction *PJmpInstruction;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TJmpInstruction
{
public:
	System::Byte OpCode;
	System::LongInt Distance;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TExcDescEntry
{
public:
	void *VTable;
	void *Handler;
};


typedef TExcDesc *PExcDesc;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TExcDesc
{
public:
	TJmpInstruction JMP;
	
public:
	union
	{
		struct 
		{
			int Cnt;
			System::StaticArray<TExcDescEntry, 1> ExcTab;
		};
		struct 
		{
			System::StaticArray<System::Byte, 1> Instructions;
		};
		
	};
};
#pragma pack(pop)


typedef TExcFrame *PExcFrame;

struct DECLSPEC_DRECORD TExcFrame
{
public:
	PExcFrame Next;
	PExcDesc Desc;
	void *FramePointer;
	
public:
	union
	{
		struct 
		{
			void *SelfOfMethod;
		};
		struct 
		{
			void *ConstructedObject;
		};
		
	};
};


typedef TJmpTable *PJmpTable;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TJmpTable
{
public:
	System::Word OPCode;
	void *Ptr;
};
#pragma pack(pop)


enum DECLSPEC_DENUM TExceptFrameKind : unsigned char { efkUnknown, efkFinally, efkAnyException, efkOnException, efkAutoException };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclExceptFrame : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TExcDescEntry> _TJclExceptFrame__1;
	
	
private:
	TExceptFrameKind FFrameKind;
	void *FFrameLocation;
	void *FCodeLocation;
	_TJclExceptFrame__1 FExcTab;
	
protected:
	void __fastcall AnalyseExceptFrame(PExcDesc AExcDesc);
	
public:
	__fastcall TJclExceptFrame(void * AFrameLocation, PExcDesc AExcDesc);
	bool __fastcall Handles(System::TObject* ExceptObj);
	bool __fastcall HandlerInfo(System::TObject* ExceptObj, /* out */ void * &HandlerAt);
	__property void * CodeLocation = {read=FCodeLocation};
	__property void * FrameLocation = {read=FFrameLocation};
	__property TExceptFrameKind FrameKind = {read=FFrameKind, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclExceptFrame() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TJclExceptFrameList : public TJclStackBaseList
{
	typedef TJclStackBaseList inherited;
	
private:
	int FIgnoreLevels;
	TJclExceptFrame* __fastcall GetItems(Jclbase::TJclListSize Index);
	
protected:
	TJclExceptFrame* __fastcall AddFrame(PExcFrame AFrame);
	
public:
	__fastcall TJclExceptFrameList(int AIgnoreLevels);
	void __fastcall TraceExceptionFrames();
	__property TJclExceptFrame* Items[Jclbase::TJclListSize Index] = {read=GetItems};
	__property int IgnoreLevels = {read=FIgnoreLevels, write=FIgnoreLevels, nodefault};
public:
	/* TJclStackBaseList.Destroy */ inline __fastcall virtual ~TJclExceptFrameList() { }
	
};


class PASCALIMPLEMENTATION TJclDebugThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	System::TObject* FSyncException;
	System::UnicodeString FThreadName;
	void __fastcall DoHandleException();
	System::UnicodeString __fastcall GetThreadInfo();
	
protected:
	void __fastcall DoNotify();
	DYNAMIC void __fastcall DoSyncHandleException();
	void __fastcall HandleException(System::TObject* Sender = (System::TObject*)(0x0));
	
public:
	__fastcall TJclDebugThread(bool ASuspended, const System::UnicodeString AThreadName);
	__fastcall virtual ~TJclDebugThread();
	__property System::TObject* SyncException = {read=FSyncException};
	__property System::UnicodeString ThreadInfo = {read=GetThreadInfo};
	__property System::UnicodeString ThreadName = {read=FThreadName};
};


typedef void __fastcall (__closure *TJclDebugThreadNotifyEvent)(TJclDebugThread* Thread);

typedef void __fastcall (__closure *TJclThreadIDNotifyEvent)(unsigned ThreadID);

class PASCALIMPLEMENTATION TJclDebugThreadList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Contnrs::TObjectList* FList;
	Jclsynch::TJclCriticalSection* FLock;
	Jclsynch::TJclCriticalSection* FReadLock;
	unsigned FRegSyncThreadID;
	bool FSaveCreationStack;
	unsigned FUnregSyncThreadID;
	TJclDebugThreadNotifyEvent FOnSyncException;
	TJclThreadIDNotifyEvent FOnThreadRegistered;
	TJclThreadIDNotifyEvent FOnThreadUnregistered;
	System::UnicodeString __fastcall GetThreadClassNames(unsigned ThreadID);
	System::UnicodeString __fastcall GetThreadInfos(unsigned ThreadID);
	System::UnicodeString __fastcall GetThreadNames(unsigned ThreadID);
	void __fastcall DoSyncThreadRegistered();
	void __fastcall DoSyncThreadUnregistered();
	System::TDateTime __fastcall GetThreadCreationTime(unsigned ThreadID);
	Winapi::Windows::THandle __fastcall GetThreadHandle(int Index);
	unsigned __fastcall GetThreadID(int Index);
	int __fastcall GetThreadIDCount();
	unsigned __fastcall GetThreadParentID(unsigned ThreadID);
	System::UnicodeString __fastcall GetThreadValues(unsigned ThreadID, int Index);
	int __fastcall IndexOfThreadID(unsigned ThreadID);
	
protected:
	void __fastcall DoSyncException(TJclDebugThread* Thread);
	void __fastcall DoThreadRegistered(System::Classes::TThread* Thread);
	void __fastcall DoThreadUnregistered(System::Classes::TThread* Thread);
	void __fastcall InternalRegisterThread(System::Classes::TThread* Thread, unsigned ThreadID, const System::UnicodeString ThreadName);
	void __fastcall InternalUnregisterThread(System::Classes::TThread* Thread, unsigned ThreadID);
	
public:
	__fastcall TJclDebugThreadList();
	__fastcall virtual ~TJclDebugThreadList();
	bool __fastcall AddStackListToLocationInfoList(unsigned ThreadID, TJclLocationInfoList* AList);
	void __fastcall RegisterThread(System::Classes::TThread* Thread, const System::UnicodeString ThreadName);
	void __fastcall RegisterThreadID(unsigned AThreadID, const System::UnicodeString ThreadName = System::UnicodeString());
	void __fastcall UnregisterThread(System::Classes::TThread* Thread);
	void __fastcall UnregisterThreadID(unsigned AThreadID);
	__property Jclsynch::TJclCriticalSection* Lock = {read=FLock};
	__property bool SaveCreationStack = {read=FSaveCreationStack, write=FSaveCreationStack, nodefault};
	__property System::UnicodeString ThreadClassNames[unsigned ThreadID] = {read=GetThreadClassNames};
	__property System::TDateTime ThreadCreationTime[unsigned ThreadID] = {read=GetThreadCreationTime};
	__property Winapi::Windows::THandle ThreadHandles[int Index] = {read=GetThreadHandle};
	__property unsigned ThreadIDs[int Index] = {read=GetThreadID};
	__property int ThreadIDCount = {read=GetThreadIDCount, nodefault};
	__property System::UnicodeString ThreadInfos[unsigned ThreadID] = {read=GetThreadInfos};
	__property System::UnicodeString ThreadNames[unsigned ThreadID] = {read=GetThreadNames};
	__property unsigned ThreadParentIDs[unsigned ThreadID] = {read=GetThreadParentID};
	__property TJclDebugThreadNotifyEvent OnSyncException = {read=FOnSyncException, write=FOnSyncException};
	__property TJclThreadIDNotifyEvent OnThreadRegistered = {read=FOnThreadRegistered, write=FOnThreadRegistered};
	__property TJclThreadIDNotifyEvent OnThreadUnregistered = {read=FOnThreadUnregistered, write=FOnThreadUnregistered};
};


class PASCALIMPLEMENTATION TJclDebugThreadInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::TDateTime FCreationTime;
	unsigned FParentThreadID;
	TJclStackInfoList* FStackList;
	System::UnicodeString FThreadClassName;
	unsigned FThreadID;
	Winapi::Windows::THandle FThreadHandle;
	System::UnicodeString FThreadName;
	
public:
	__fastcall TJclDebugThreadInfo(unsigned AParentThreadID, unsigned AThreadID, bool AStack);
	__fastcall virtual ~TJclDebugThreadInfo();
	__property System::TDateTime CreationTime = {read=FCreationTime};
	__property unsigned ParentThreadID = {read=FParentThreadID, nodefault};
	__property TJclStackInfoList* StackList = {read=FStackList};
	__property System::UnicodeString ThreadClassName = {read=FThreadClassName, write=FThreadClassName};
	__property unsigned ThreadID = {read=FThreadID, nodefault};
	__property Winapi::Windows::THandle ThreadHandle = {read=FThreadHandle, write=FThreadHandle, nodefault};
	__property System::UnicodeString ThreadName = {read=FThreadName, write=FThreadName};
};


enum DECLSPEC_DENUM Jcldebug__72 : unsigned char { tioIsMainThread, tioName, tioCreationTime, tioParentThreadID, tioStack, tioCreationStack };

typedef System::Set<Jcldebug__72, Jcldebug__72::tioIsMainThread, Jcldebug__72::tioCreationStack> TJclThreadInfoOptions;

class PASCALIMPLEMENTATION TJclCustomThreadInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
protected:
	System::TDateTime FCreationTime;
	TJclCustomLocationInfoList* FCreationStack;
	System::UnicodeString FName;
	unsigned FParentThreadID;
	TJclCustomLocationInfoList* FStack;
	unsigned FThreadID;
	TJclThreadInfoOptions FValues;
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	virtual TJclCustomLocationInfoListClass __fastcall GetStackClass();
	
public:
	__fastcall TJclCustomThreadInfo();
	__fastcall virtual ~TJclCustomThreadInfo();
	__property System::TDateTime CreationTime = {read=FCreationTime, write=FCreationTime};
	__property System::UnicodeString Name = {read=FName, write=FName};
	__property unsigned ParentThreadID = {read=FParentThreadID, write=FParentThreadID, nodefault};
	__property unsigned ThreadID = {read=FThreadID, write=FThreadID, nodefault};
	__property TJclThreadInfoOptions Values = {read=FValues, write=FValues, nodefault};
};


class PASCALIMPLEMENTATION TJclThreadInfo : public TJclCustomThreadInfo
{
	typedef TJclCustomThreadInfo inherited;
	
private:
	System::UnicodeString __fastcall GetAsString();
	void __fastcall InternalFill(Winapi::Windows::THandle AThreadHandle, unsigned AThreadID, TJclThreadInfoOptions AGatherOptions, bool AExceptThread);
	TJclLocationInfoList* __fastcall GetStack(const int AIndex);
	
protected:
	virtual TJclCustomLocationInfoListClass __fastcall GetStackClass();
	
public:
	void __fastcall Fill(Winapi::Windows::THandle AThreadHandle, unsigned AThreadID, TJclThreadInfoOptions AGatherOptions);
	void __fastcall FillFromExceptThread(TJclThreadInfoOptions AGatherOptions);
	__property System::UnicodeString AsString = {read=GetAsString};
	__property TJclLocationInfoList* CreationStack = {read=GetStack, index=1};
	__property TJclLocationInfoList* Stack = {read=GetStack, index=2};
public:
	/* TJclCustomThreadInfo.Create */ inline __fastcall TJclThreadInfo() : TJclCustomThreadInfo() { }
	/* TJclCustomThreadInfo.Destroy */ inline __fastcall virtual ~TJclThreadInfo() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclThreadInfoList : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TJclThreadInfo* operator[](int AIndex) { return this->Items[AIndex]; }
	
private:
	TJclThreadInfoOptions FGatherOptions;
	System::Contnrs::TObjectList* FItems;
	System::UnicodeString __fastcall GetAsString();
	int __fastcall GetCount();
	TJclThreadInfo* __fastcall GetItems(int AIndex);
	void __fastcall InternalGather(unsigned *AIncludeThreadIDs, const System::NativeInt AIncludeThreadIDs_High, unsigned *AExcludeThreadIDs, const System::NativeInt AExcludeThreadIDs_High);
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
public:
	__fastcall TJclThreadInfoList();
	__fastcall virtual ~TJclThreadInfoList();
	TJclThreadInfo* __fastcall Add();
	void __fastcall Clear();
	void __fastcall Gather(unsigned AExceptThreadID);
	void __fastcall GatherExclude(unsigned *AThreadIDs, const System::NativeInt AThreadIDs_High);
	void __fastcall GatherInclude(unsigned *AThreadIDs, const System::NativeInt AThreadIDs_High);
	__property System::UnicodeString AsString = {read=GetAsString};
	__property int Count = {read=GetCount, nodefault};
	__property TJclThreadInfoOptions GatherOptions = {read=FGatherOptions, write=FGatherOptions, nodefault};
	__property TJclThreadInfo* Items[int AIndex] = {read=GetItems/*, default*/};
};

#pragma pack(pop)

enum DECLSPEC_DENUM TJclStackTrackingOption : unsigned char { stStack, stExceptFrame, stRawMode, stAllModules, stStaticModuleList, stDelayedTrace, stTraceAllExceptions, stMainThreadOnly, stDisableIfDebuggerAttached, stImmediateExceptionStacktraceResolving, stCleanRawStack };

typedef System::Set<TJclStackTrackingOption, TJclStackTrackingOption::stStack, TJclStackTrackingOption::stCleanRawStack> TJclStackTrackingOptions;

enum DECLSPEC_DENUM TJclExceptionStacktraceOption : unsigned char { estoIncludeModuleName, estoIncludeAdressOffset, estoIncludeStartProcLineOffset, estoIncludeVAddress };

typedef System::Set<TJclExceptionStacktraceOption, TJclExceptionStacktraceOption::estoIncludeModuleName, TJclExceptionStacktraceOption::estoIncludeVAddress> TJclExceptionStacktraceOptions;

//-- var, const, procedure ---------------------------------------------------
#define EnvironmentVarNtSymbolPath L"_NT_SYMBOL_PATH"
#define EnvironmentVarAlternateNtSymbolPath L"_NT_ALTERNATE_SYMBOL_PATH"
static _DELPHI_CONST System::Word MaxStackTraceItems = System::Word(0x1000);
static _DELPHI_CONST int JclDbgDataSignature = int(0x4742444a);
#define JclDbgDataResName "JCLDEBUG"
static _DELPHI_CONST System::Int8 JclDbgHeaderVersion = System::Int8(0x1);
#define JclDbgFileExtension L".jdbg"
#define JclMapFileExtension L".map"
#define DrcFileExtension L".drc"
extern DELPHI_PACKAGE TJclStackTrackingOptions JclStackTrackingOptions;
extern DELPHI_PACKAGE TJclExceptionStacktraceOptions JclExceptionStacktraceOptions;
extern DELPHI_PACKAGE System::UnicodeString JclDebugInfoSymbolPaths;
extern DELPHI_PACKAGE void __fastcall AssertKindOf(const System::UnicodeString ClassName, System::TObject* const Obj)/* overload */;
extern DELPHI_PACKAGE void __fastcall AssertKindOf(const System::TClass ClassType, System::TObject* const Obj)/* overload */;
extern DELPHI_PACKAGE void __fastcall TraceMsg(const System::UnicodeString Msg);
extern DELPHI_PACKAGE void __fastcall TraceLoc(const System::UnicodeString Msg);
extern DELPHI_PACKAGE void __fastcall TraceLocFmt(const System::UnicodeString Fmt, const System::TVarRec *Args, const System::NativeInt Args_High);
extern DELPHI_PACKAGE bool __fastcall ConvertMapFileToJdbgFile(const System::Sysutils::TFileName MapFileName)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ConvertMapFileToJdbgFile(const System::Sysutils::TFileName MapFileName, /* out */ System::UnicodeString &LinkerBugUnit, /* out */ int &LineNumberErrors)/* overload */;
extern DELPHI_PACKAGE bool __fastcall ConvertMapFileToJdbgFile(const System::Sysutils::TFileName MapFileName, /* out */ System::UnicodeString &LinkerBugUnit, /* out */ int &LineNumberErrors, /* out */ int &MapFileSize, /* out */ int &JdbgFileSize)/* overload */;
extern DELPHI_PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const System::Sysutils::TFileName ExecutableFileName, const System::Sysutils::TFileName MapFileName, /* out */ System::UnicodeString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize)/* overload */;
extern DELPHI_PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const System::Sysutils::TFileName ExecutableFileName, const System::Sysutils::TFileName MapFileName, /* out */ System::UnicodeString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize, /* out */ int &LineNumberErrors)/* overload */;
extern DELPHI_PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const System::Sysutils::TFileName ExecutableFileName, TJclBinDebugGenerator* BinDebug, /* out */ System::UnicodeString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize)/* overload */;
extern DELPHI_PACKAGE bool __fastcall InsertDebugDataIntoExecutableFile(const System::Sysutils::TFileName ExecutableFileName, TJclBinDebugGenerator* BinDebug, /* out */ System::UnicodeString &LinkerBugUnit, /* out */ int &MapFileSize, /* out */ int &JclDebugDataSize, /* out */ int &LineNumberErrors)/* overload */;
extern DELPHI_PACKAGE void * __fastcall Caller(int Level = 0x0, bool FastStackWalk = false);
extern DELPHI_PACKAGE void __fastcall BeginGetLocationInfoCache();
extern DELPHI_PACKAGE void __fastcall EndGetLocationInfoCache();
extern DELPHI_PACKAGE TJclLocationInfo __fastcall GetLocationInfo(const void * Addr)/* overload */;
extern DELPHI_PACKAGE bool __fastcall GetLocationInfo(const void * Addr, /* out */ TJclLocationInfo &Info)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetLocationInfoStr(const void * Addr, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
extern DELPHI_PACKAGE bool __fastcall DebugInfoAvailable(const unsigned Module);
extern DELPHI_PACKAGE void __fastcall ClearLocationData();
extern DELPHI_PACKAGE System::UnicodeString __fastcall FileByLevel(const int Level = 0x0);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ModuleByLevel(const int Level = 0x0);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ProcByLevel(const int Level = 0x0, bool OnlyProcedureName = false);
extern DELPHI_PACKAGE int __fastcall LineByLevel(const int Level = 0x0);
extern DELPHI_PACKAGE bool __fastcall MapByLevel(const int Level, System::UnicodeString &File_, System::UnicodeString &Module_, System::UnicodeString &Proc_, int &Line_);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ExtractClassName(const System::UnicodeString ProcedureName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ExtractMethodName(const System::UnicodeString ProcedureName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall __MODULE__ _DEPRECATED_ATTRIBUTE0 (const int Level = 0x0);
extern DELPHI_PACKAGE System::UnicodeString __fastcall __PROC__ _DEPRECATED_ATTRIBUTE0 (const int Level = 0x0);
extern DELPHI_PACKAGE bool __fastcall __MAP__ _DEPRECATED_ATTRIBUTE0 (const int Level, System::UnicodeString &_File, System::UnicodeString &_Module, System::UnicodeString &_Proc, int &_Line);
extern DELPHI_PACKAGE System::UnicodeString __fastcall FileOfAddr(const void * Addr);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ModuleOfAddr(const void * Addr);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ProcOfAddr(const void * Addr);
extern DELPHI_PACKAGE int __fastcall LineOfAddr(const void * Addr);
extern DELPHI_PACKAGE bool __fastcall MapOfAddr(const void * Addr, System::UnicodeString &File_, System::UnicodeString &Module_, System::UnicodeString &Proc_, int &Line_);
extern DELPHI_PACKAGE System::UnicodeString __fastcall __FILE_OF_ADDR__ _DEPRECATED_ATTRIBUTE0 (const void * Addr);
extern DELPHI_PACKAGE System::UnicodeString __fastcall __MODULE_OF_ADDR__ _DEPRECATED_ATTRIBUTE0 (const void * Addr);
extern DELPHI_PACKAGE System::UnicodeString __fastcall __PROC_OF_ADDR__ _DEPRECATED_ATTRIBUTE0 (const void * Addr);
extern DELPHI_PACKAGE int __fastcall __LINE_OF_ADDR__ _DEPRECATED_ATTRIBUTE0 (const void * Addr);
extern DELPHI_PACKAGE bool __fastcall __MAP_OF_ADDR__ _DEPRECATED_ATTRIBUTE0 (const void * Addr, System::UnicodeString &_File, System::UnicodeString &_Module, System::UnicodeString &_Proc, int &_Line);
extern DELPHI_PACKAGE bool __fastcall JclValidateModuleAddress(void * Addr);
extern DELPHI_PACKAGE void __fastcall DoExceptionStackTrace(System::TObject* ExceptObj, void * ExceptAddr, bool OSException, void * BaseOfStack);
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclLastExceptStackList();
extern DELPHI_PACKAGE bool __fastcall JclLastExceptStackListToStrings(System::Classes::TStrings* Strings, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclGetExceptStackList(unsigned ThreadID);
extern DELPHI_PACKAGE bool __fastcall JclGetExceptStackListToStrings(unsigned ThreadID, System::Classes::TStrings* Strings, bool IncludeModuleName = false, bool IncludeAddressOffset = false, bool IncludeStartProcLineOffset = false, bool IncludeVAddress = false);
extern DELPHI_PACKAGE void __fastcall JclClearGlobalStackData();
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, int AIgnoreLevels, void * FirstCaller)/* overload */;
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, int AIgnoreLevels, void * FirstCaller, bool DelayedTrace)/* overload */;
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, int AIgnoreLevels, void * FirstCaller, bool DelayedTrace, void * BaseOfStack)/* overload */;
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclCreateStackList(bool Raw, int AIgnoreLevels, void * FirstCaller, bool DelayedTrace, void * BaseOfStack, void * TopOfStack)/* overload */;
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclCreateThreadStackTrace(bool Raw, const Winapi::Windows::THandle ThreadHandle);
extern DELPHI_PACKAGE TJclStackInfoList* __fastcall JclCreateThreadStackTraceFromID(bool Raw, unsigned ThreadID);
extern DELPHI_PACKAGE TJclExceptFrameList* __fastcall JclCreateExceptFrameList(int AIgnoreLevels);
extern DELPHI_PACKAGE TJclExceptFrameList* __fastcall JclLastExceptFrameList();
extern DELPHI_PACKAGE TJclExceptFrameList* __fastcall JclGetExceptFrameList(unsigned ThreadID);
extern DELPHI_PACKAGE void __fastcall DoExceptFrameTrace();
extern DELPHI_PACKAGE void __fastcall AddIgnoredException(const System::TClass ExceptionClass);
extern DELPHI_PACKAGE void __fastcall AddIgnoredExceptionByName(const System::UnicodeString AExceptionClassName);
extern DELPHI_PACKAGE void __fastcall RemoveIgnoredException(const System::TClass ExceptionClass);
extern DELPHI_PACKAGE void __fastcall RemoveIgnoredExceptionByName(const System::UnicodeString AExceptionClassName);
extern DELPHI_PACKAGE bool __fastcall IsIgnoredException(const System::TClass ExceptionClass);
extern DELPHI_PACKAGE void __fastcall AddModule(const System::UnicodeString ModuleName);
extern DELPHI_PACKAGE bool __fastcall JclStartExceptionTracking();
extern DELPHI_PACKAGE bool __fastcall JclStopExceptionTracking();
extern DELPHI_PACKAGE bool __fastcall JclExceptionTrackingActive();
extern DELPHI_PACKAGE bool __fastcall JclTrackExceptionsFromLibraries();
extern DELPHI_PACKAGE TJclDebugThreadList* __fastcall JclDebugThreadList();
extern DELPHI_PACKAGE bool __fastcall JclHookThreads();
extern DELPHI_PACKAGE bool __fastcall JclUnhookThreads();
extern DELPHI_PACKAGE bool __fastcall JclThreadsHooked();
extern DELPHI_PACKAGE bool __fastcall IsDebuggerAttached();
extern DELPHI_PACKAGE bool __fastcall IsHandleValid(Winapi::Windows::THandle Handle);
}	/* namespace Jcldebug */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLDEBUG)
using namespace Jcldebug;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclDebugHPP
