// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclTD32.pas' rev: 37.00 (Windows)

#ifndef JclTD32HPP
#define JclTD32HPP

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
#include <JclPeImage.hpp>
#include <JclFileUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jcltd32
{
//-- forward type declarations -----------------------------------------------
struct TJclTD32FileSignature;
struct TDirectoryEntry;
struct TDirectoryHeader;
struct TSegmentInfo;
struct TModuleInfo;
struct TLineMappingEntry;
struct TOffsetPair;
struct TSourceFileEntry;
struct TSourceModuleInfo;
struct TGlobalTypeInfo;
struct TSymbolProcInfo;
struct TSymbolObjNameInfo;
struct TSymbolDataInfo;
struct TSymbolWithInfo;
struct TSymbolLabelInfo;
struct TSymbolConstantInfo;
struct TSymbolUdtInfo;
struct TSymbolVftPathInfo;
struct TSymbolInfo;
struct TSymbolInfos;
class DELPHICLASS TJclTD32ModuleInfo;
class DELPHICLASS TJclTD32LineInfo;
class DELPHICLASS TJclTD32SourceModuleInfo;
class DELPHICLASS TJclTD32SymbolInfo;
class DELPHICLASS TJclTD32ProcSymbolInfo;
class DELPHICLASS TJclTD32LocalProcSymbolInfo;
class DELPHICLASS TJclTD32GlobalProcSymbolInfo;
class DELPHICLASS TJclTD32ObjNameSymbolInfo;
class DELPHICLASS TJclTD32DataSymbolInfo;
class DELPHICLASS TJclTD32LDataSymbolInfo;
class DELPHICLASS TJclTD32GDataSymbolInfo;
class DELPHICLASS TJclTD32PublicSymbolInfo;
class DELPHICLASS TJclTD32WithSymbolInfo;
class DELPHICLASS TJclTD32LabelSymbolInfo;
class DELPHICLASS TJclTD32ConstantSymbolInfo;
class DELPHICLASS TJclTD32UdtSymbolInfo;
class DELPHICLASS TJclTD32VftPathSymbolInfo;
class DELPHICLASS TJclTD32InfoParser;
class DELPHICLASS TJclTD32InfoScanner;
class DELPHICLASS TJclPeBorTD32Image;
//-- type declarations -------------------------------------------------------
typedef TJclTD32FileSignature *PJclTD32FileSignature;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TJclTD32FileSignature
{
public:
	unsigned Signature;
	unsigned Offset;
};
#pragma pack(pop)


typedef TDirectoryEntry *PDirectoryEntry;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TDirectoryEntry
{
public:
	System::Word SubsectionType;
	System::Word ModuleIndex;
	unsigned Offset;
	unsigned Size;
};
#pragma pack(pop)


typedef TDirectoryHeader *PDirectoryHeader;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TDirectoryHeader
{
public:
	System::Word Size;
	System::Word DirEntrySize;
	unsigned DirEntryCount;
	unsigned lfoNextDir;
	unsigned Flags;
	System::StaticArray<TDirectoryEntry, 1> DirEntries;
};
#pragma pack(pop)


typedef TSegmentInfo *PSegmentInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSegmentInfo
{
public:
	System::Word Segment;
	System::Word Flags;
	unsigned Offset;
	unsigned Size;
};
#pragma pack(pop)


typedef System::StaticArray<TSegmentInfo, 32768> TSegmentInfoArray;

typedef TSegmentInfoArray *PSegmentInfoArray;

typedef TModuleInfo *PModuleInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TModuleInfo
{
public:
	System::Word OverlayNumber;
	System::Word LibraryIndex;
	System::Word SegmentCount;
	System::Word DebuggingStyle;
	unsigned NameIndex;
	unsigned TimeStamp;
	System::StaticArray<unsigned, 3> Reserved;
	System::StaticArray<TSegmentInfo, 1> Segments;
};
#pragma pack(pop)


typedef TLineMappingEntry *PLineMappingEntry;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TLineMappingEntry
{
public:
	System::Word SegmentIndex;
	System::Word PairCount;
	System::StaticArray<unsigned, 1> Offsets;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TOffsetPair
{
public:
	unsigned StartOffset;
	unsigned EndOffset;
};
#pragma pack(pop)


typedef System::StaticArray<TOffsetPair, 32768> TOffsetPairArray;

typedef TOffsetPairArray *POffsetPairArray;

typedef TSourceFileEntry *PSourceFileEntry;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSourceFileEntry
{
public:
	System::Word SegmentCount;
	unsigned NameIndex;
	System::StaticArray<unsigned, 1> BaseSrcLines;
};
#pragma pack(pop)


typedef TSourceModuleInfo *PSourceModuleInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSourceModuleInfo
{
public:
	System::Word FileCount;
	System::Word SegmentCount;
	System::StaticArray<unsigned, 1> BaseSrcFiles;
};
#pragma pack(pop)


typedef TGlobalTypeInfo *PGlobalTypeInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGlobalTypeInfo
{
public:
	unsigned Count;
	System::StaticArray<unsigned, 1> Offsets;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolProcInfo
{
public:
	unsigned pParent;
	unsigned pEnd;
	unsigned pNext;
	unsigned Size;
	unsigned DebugStart;
	unsigned DebugEnd;
	unsigned Offset;
	System::Word Segment;
	unsigned ProcType;
	System::Byte NearFar;
	System::Byte Reserved;
	unsigned NameIndex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolObjNameInfo
{
public:
	unsigned Signature;
	unsigned NameIndex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolDataInfo
{
public:
	unsigned Offset;
	System::Word Segment;
	System::Word Reserved;
	unsigned TypeIndex;
	unsigned NameIndex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolWithInfo
{
public:
	unsigned pParent;
	unsigned pEnd;
	unsigned Size;
	unsigned Offset;
	System::Word Segment;
	System::Word Reserved;
	unsigned NameIndex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolLabelInfo
{
public:
	unsigned Offset;
	System::Word Segment;
	System::Byte NearFar;
	System::Byte Reserved;
	unsigned NameIndex;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolConstantInfo
{
public:
	unsigned TypeIndex;
	unsigned NameIndex;
	unsigned Reserved;
	unsigned Value;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolUdtInfo
{
public:
	unsigned TypeIndex;
	System::Word Properties;
	unsigned NameIndex;
	unsigned Reserved;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolVftPathInfo
{
public:
	unsigned Offset;
	System::Word Segment;
	System::Word Reserved;
	unsigned RootIndex;
	unsigned PathIndex;
};
#pragma pack(pop)


typedef TSymbolInfo *PSymbolInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolInfo
{
public:
	System::Word Size;
	System::Word SymbolType;
	
public:
	union
	{
		struct 
		{
			TSymbolVftPathInfo VftPath;
		};
		struct 
		{
			TSymbolUdtInfo Udt;
		};
		struct 
		{
			TSymbolConstantInfo Constant;
		};
		struct 
		{
			TSymbolLabelInfo Label32;
		};
		struct 
		{
			TSymbolWithInfo With32;
		};
		struct 
		{
			TSymbolDataInfo Data;
		};
		struct 
		{
			TSymbolObjNameInfo ObjName;
		};
		struct 
		{
			TSymbolProcInfo Proc;
		};
		
	};
};
#pragma pack(pop)


typedef TSymbolInfos *PSymbolInfos;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSymbolInfos
{
public:
	unsigned Signature;
	System::StaticArray<TSymbolInfo, 1> Symbols;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32ModuleInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSegmentInfo operator[](const int Idx) { return this->Segment[Idx]; }
	
private:
	unsigned FNameIndex;
	PSegmentInfoArray FSegments;
	int FSegmentCount;
	TSegmentInfo __fastcall GetSegment(const int Idx);
	
public:
	__fastcall TJclTD32ModuleInfo(PModuleInfo pModInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property int SegmentCount = {read=FSegmentCount, nodefault};
	__property TSegmentInfo Segment[const int Idx] = {read=GetSegment/*, default*/};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ModuleInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32LineInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FLineNo;
	unsigned FOffset;
	
public:
	__fastcall TJclTD32LineInfo(unsigned ALineNo, unsigned AOffset);
	__property unsigned LineNo = {read=FLineNo, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LineInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32SourceModuleInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TJclTD32LineInfo* operator[](const int Idx) { return this->Line[Idx]; }
	
private:
	System::Contnrs::TObjectList* FLines;
	POffsetPairArray FSegments;
	int FSegmentCount;
	unsigned FNameIndex;
	TJclTD32LineInfo* __fastcall GetLine(const int Idx);
	int __fastcall GetLineCount();
	TOffsetPair __fastcall GetSegment(const int Idx);
	
public:
	__fastcall TJclTD32SourceModuleInfo(PSourceFileEntry pSrcFile, Jclbase::TJclAddr Base);
	__fastcall virtual ~TJclTD32SourceModuleInfo();
	bool __fastcall FindLine(const unsigned AAddr, /* out */ TJclTD32LineInfo* &ALine);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property int LineCount = {read=GetLineCount, nodefault};
	__property TJclTD32LineInfo* Line[const int Idx] = {read=GetLine/*, default*/};
	__property int SegmentCount = {read=FSegmentCount, nodefault};
	__property TOffsetPair Segment[const int Idx] = {read=GetSegment};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32SymbolInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Word FSymbolType;
	
public:
	__fastcall virtual TJclTD32SymbolInfo(PSymbolInfo pSymInfo);
	__property System::Word SymbolType = {read=FSymbolType, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32SymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32ProcSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FNameIndex;
	unsigned FOffset;
	unsigned FSize;
	
public:
	__fastcall virtual TJclTD32ProcSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned Size = {read=FSize, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ProcSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32LocalProcSymbolInfo : public TJclTD32ProcSymbolInfo
{
	typedef TJclTD32ProcSymbolInfo inherited;
	
public:
	/* TJclTD32ProcSymbolInfo.Create */ inline __fastcall virtual TJclTD32LocalProcSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32ProcSymbolInfo(pSymInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LocalProcSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32GlobalProcSymbolInfo : public TJclTD32ProcSymbolInfo
{
	typedef TJclTD32ProcSymbolInfo inherited;
	
public:
	/* TJclTD32ProcSymbolInfo.Create */ inline __fastcall virtual TJclTD32GlobalProcSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32ProcSymbolInfo(pSymInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32GlobalProcSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32ObjNameSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FSignature;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32ObjNameSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Signature = {read=FSignature, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ObjNameSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32DataSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FOffset;
	unsigned FTypeIndex;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32DataSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned TypeIndex = {read=FTypeIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32DataSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32LDataSymbolInfo : public TJclTD32DataSymbolInfo
{
	typedef TJclTD32DataSymbolInfo inherited;
	
public:
	/* TJclTD32DataSymbolInfo.Create */ inline __fastcall virtual TJclTD32LDataSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32DataSymbolInfo(pSymInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LDataSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32GDataSymbolInfo : public TJclTD32DataSymbolInfo
{
	typedef TJclTD32DataSymbolInfo inherited;
	
public:
	/* TJclTD32DataSymbolInfo.Create */ inline __fastcall virtual TJclTD32GDataSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32DataSymbolInfo(pSymInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32GDataSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32PublicSymbolInfo : public TJclTD32DataSymbolInfo
{
	typedef TJclTD32DataSymbolInfo inherited;
	
public:
	/* TJclTD32DataSymbolInfo.Create */ inline __fastcall virtual TJclTD32PublicSymbolInfo(PSymbolInfo pSymInfo) : TJclTD32DataSymbolInfo(pSymInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32PublicSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32WithSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FOffset;
	unsigned FSize;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32WithSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
	__property unsigned Size = {read=FSize, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32WithSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32LabelSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FOffset;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32LabelSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32LabelSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32ConstantSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FValue;
	unsigned FTypeIndex;
	unsigned FNameIndex;
	
public:
	__fastcall virtual TJclTD32ConstantSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned TypeIndex = {read=FTypeIndex, nodefault};
	__property unsigned Value = {read=FValue, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32ConstantSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32UdtSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FTypeIndex;
	unsigned FNameIndex;
	System::Word FProperties;
	
public:
	__fastcall virtual TJclTD32UdtSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned NameIndex = {read=FNameIndex, nodefault};
	__property unsigned TypeIndex = {read=FTypeIndex, nodefault};
	__property System::Word Properties = {read=FProperties, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32UdtSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32VftPathSymbolInfo : public TJclTD32SymbolInfo
{
	typedef TJclTD32SymbolInfo inherited;
	
private:
	unsigned FRootIndex;
	unsigned FPathIndex;
	unsigned FOffset;
	
public:
	__fastcall virtual TJclTD32VftPathSymbolInfo(PSymbolInfo pSymInfo);
	__property unsigned RootIndex = {read=FRootIndex, nodefault};
	__property unsigned PathIndex = {read=FPathIndex, nodefault};
	__property unsigned Offset = {read=FOffset, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclTD32VftPathSymbolInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32InfoParser : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	void *FBase;
	System::Classes::TCustomMemoryStream* FData;
	System::Classes::TList* FNames;
	System::Contnrs::TObjectList* FModules;
	System::Contnrs::TObjectList* FSourceModules;
	System::Contnrs::TObjectList* FSymbols;
	System::Classes::TList* FProcSymbols;
	bool FValidData;
	System::Classes::TStrings* FUnmangledNames;
	System::UnicodeString __fastcall GetName(const int Idx);
	int __fastcall GetNameCount();
	TJclTD32SymbolInfo* __fastcall GetSymbol(const int Idx);
	int __fastcall GetSymbolCount();
	TJclTD32ProcSymbolInfo* __fastcall GetProcSymbol(const int Idx);
	int __fastcall GetProcSymbolCount();
	TJclTD32ModuleInfo* __fastcall GetModule(const int Idx);
	int __fastcall GetModuleCount();
	TJclTD32SourceModuleInfo* __fastcall GetSourceModule(const int Idx);
	int __fastcall GetSourceModuleCount();
	System::UnicodeString __fastcall FormatProcName(const System::UnicodeString ProcName);
	
protected:
	void __fastcall Analyse();
	virtual void __fastcall AnalyseNames(const void * pSubsection, const unsigned Size);
	virtual void __fastcall AnalyseGlobalTypes(const void * pTypes, const unsigned Size);
	virtual void __fastcall AnalyseAlignSymbols(PSymbolInfos pSymbols, const unsigned Size);
	virtual void __fastcall AnalyseModules(PModuleInfo pModInfo, const unsigned Size);
	virtual void __fastcall AnalyseSourceModules(PSourceModuleInfo pSrcModInfo, const unsigned Size);
	virtual void __fastcall AnalyseUnknownSubSection(const void * pSubsection, const unsigned Size);
	void * __fastcall LfaToVa(unsigned Lfa);
	
public:
	__fastcall TJclTD32InfoParser(System::Classes::TCustomMemoryStream* const ATD32Data);
	__fastcall virtual ~TJclTD32InfoParser();
	bool __fastcall FindModule(const unsigned AAddr, /* out */ TJclTD32ModuleInfo* &AMod);
	bool __fastcall FindSourceModule(const unsigned AAddr, /* out */ TJclTD32SourceModuleInfo* &ASrcMod);
	bool __fastcall FindProc(const unsigned AAddr, /* out */ TJclTD32ProcSymbolInfo* &AProc);
	void __fastcall GenerateUnmangledNames();
	__classmethod bool __fastcall IsTD32Sign(const TJclTD32FileSignature &Sign);
	__classmethod bool __fastcall IsTD32DebugInfoValid(const void * DebugData, const System::LongWord DebugDataSize);
	__property System::Classes::TCustomMemoryStream* Data = {read=FData};
	__property System::UnicodeString Names[const int Idx] = {read=GetName};
	__property int NameCount = {read=GetNameCount, nodefault};
	__property TJclTD32SymbolInfo* Symbols[const int Idx] = {read=GetSymbol};
	__property int SymbolCount = {read=GetSymbolCount, nodefault};
	__property TJclTD32ProcSymbolInfo* ProcSymbols[const int Idx] = {read=GetProcSymbol};
	__property int ProcSymbolCount = {read=GetProcSymbolCount, nodefault};
	__property TJclTD32ModuleInfo* Modules[const int Idx] = {read=GetModule};
	__property int ModuleCount = {read=GetModuleCount, nodefault};
	__property TJclTD32SourceModuleInfo* SourceModules[const int Idx] = {read=GetSourceModule};
	__property int SourceModuleCount = {read=GetSourceModuleCount, nodefault};
	__property bool ValidData = {read=FValidData, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclTD32InfoScanner : public TJclTD32InfoParser
{
	typedef TJclTD32InfoParser inherited;
	
public:
	int __fastcall LineNumberFromAddr(unsigned AAddr, /* out */ int &Offset)/* overload */;
	int __fastcall LineNumberFromAddr(unsigned AAddr)/* overload */;
	System::UnicodeString __fastcall ProcNameFromAddr(unsigned AAddr)/* overload */;
	System::UnicodeString __fastcall ProcNameFromAddr(unsigned AAddr, /* out */ int &Offset)/* overload */;
	System::UnicodeString __fastcall ModuleNameFromAddr(unsigned AAddr);
	System::UnicodeString __fastcall SourceNameFromAddr(unsigned AAddr);
	unsigned __fastcall VAFromUnitAndProcName(const System::UnicodeString UnitName, const System::UnicodeString ProcName);
public:
	/* TJclTD32InfoParser.Create */ inline __fastcall TJclTD32InfoScanner(System::Classes::TCustomMemoryStream* const ATD32Data) : TJclTD32InfoParser(ATD32Data) { }
	/* TJclTD32InfoParser.Destroy */ inline __fastcall virtual ~TJclTD32InfoScanner() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclPeBorTD32Image : public Jclpeimage::TJclPeBorImage
{
	typedef Jclpeimage::TJclPeBorImage inherited;
	
private:
	bool FIsTD32DebugPresent;
	System::Classes::TCustomMemoryStream* FTD32DebugData;
	TJclTD32InfoScanner* FTD32Scanner;
	
protected:
	DYNAMIC void __fastcall AfterOpen();
	DYNAMIC void __fastcall Clear();
	void __fastcall ClearDebugData();
	void __fastcall CheckDebugData();
	bool __fastcall IsDebugInfoInImage(System::Classes::TCustomMemoryStream* &DataStream);
	bool __fastcall IsDebugInfoInTds(System::Classes::TCustomMemoryStream* &DataStream);
	
public:
	__property bool IsTD32DebugPresent = {read=FIsTD32DebugPresent, nodefault};
	__property System::Classes::TCustomMemoryStream* TD32DebugData = {read=FTD32DebugData};
	__property TJclTD32InfoScanner* TD32Scanner = {read=FTD32Scanner};
public:
	/* TJclPeBorImage.Create */ inline __fastcall virtual TJclPeBorTD32Image(bool ANoExceptions) : Jclpeimage::TJclPeBorImage(ANoExceptions) { }
	/* TJclPeBorImage.Destroy */ inline __fastcall virtual ~TJclPeBorTD32Image() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Jcltd32 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLTD32)
using namespace Jcltd32;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclTD32HPP
