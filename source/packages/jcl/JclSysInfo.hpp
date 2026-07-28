// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclSysInfo.pas' rev: 37.00 (Windows)

#ifndef JclSysInfoHPP
#define JclSysInfoHPP

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
#include <Winapi.ActiveX.hpp>
#include <Winapi.ShlObj.hpp>
#include <System.Classes.hpp>
#include <JclBase.hpp>
#include <JclResources.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jclsysinfo
{
//-- forward type declarations -----------------------------------------------
struct TIntelSpecific;
struct TCyrixSpecific;
struct TAMDSpecific;
struct TVIASpecific;
struct TTransmetaSpecific;
struct TCacheInfo;
struct TFreqInfo;
struct TCpuInfo;
struct TFreeSystemResources;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TEnvironmentOption : unsigned char { eoLocalMachine, eoCurrentUser, eoAdditional };

typedef System::Set<TEnvironmentOption, TEnvironmentOption::eoLocalMachine, TEnvironmentOption::eoAdditional> TEnvironmentOptions;

enum DECLSPEC_DENUM TAPMLineStatus : unsigned char { alsOffline, alsOnline, alsUnknown };

enum DECLSPEC_DENUM TAPMBatteryFlag : unsigned char { abfHigh, abfLow, abfCritical, abfCharging, abfNoBattery, abfUnknown };

typedef System::Set<TAPMBatteryFlag, TAPMBatteryFlag::abfHigh, TAPMBatteryFlag::abfUnknown> TAPMBatteryFlags;

enum DECLSPEC_DENUM TFileSystemFlag : unsigned char { fsCaseSensitive, fsCasePreservedNames, fsSupportsUnicodeOnDisk, fsPersistentACLs, fsSupportsFileCompression, fsSupportsVolumeQuotas, fsSupportsSparseFiles, fsSupportsReparsePoints, fsSupportsRemoteStorage, fsVolumeIsCompressed, fsSupportsObjectIds, fsSupportsEncryption, fsSupportsNamedStreams, fsVolumeIsReadOnly };

typedef System::Set<TFileSystemFlag, TFileSystemFlag::fsCaseSensitive, TFileSystemFlag::fsVolumeIsReadOnly> TFileSystemFlags;

enum DECLSPEC_DENUM TJclTerminateAppResult : unsigned char { taError, taClean, taKill };

enum DECLSPEC_DENUM TWindowsVersion : unsigned char { wvUnknown, wvWin95, wvWin95OSR2, wvWin98, wvWin98SE, wvWinME, wvWinNT31, wvWinNT35, wvWinNT351, wvWinNT4, wvWin2000, wvWinXP, wvWin2003, wvWinXP64, wvWin2003R2, wvWinVista, wvWinServer2008, wvWin7, wvWinServer2008R2, wvWin8, wvWin8RT, wvWinServer2012, wvWin81, wvWin81RT, wvWinServer2012R2, wvWin10, wvWinServer2016, wvWinServer2019, wvWinServer, wvWin11, wvWinServer2022, wvWinServer2025 };

enum DECLSPEC_DENUM TWindowsEdition : unsigned char { weUnknown, weWinXPHome, weWinXPPro, weWinXPHomeN, weWinXPProN, weWinXPHomeK, weWinXPProK, weWinXPHomeKN, weWinXPProKN, weWinXPStarter, weWinXPMediaCenter, weWinXPTablet, weWinVistaStarter, weWinVistaHomeBasic, weWinVistaHomeBasicN, weWinVistaHomePremium, weWinVistaBusiness, weWinVistaBusinessN, weWinVistaEnterprise, weWinVistaUltimate, weWin7Starter, weWin7HomeBasic, weWin7HomePremium, weWin7Professional, weWin7Enterprise, weWin7Ultimate, weWin8, weWin8Pro, weWin8Enterprise, weWin8RT, weWin81, weWin81Pro, weWin81Enterprise, weWin81RT, weWin10, weWin10Home, weWin10Pro, weWin10Enterprise, weWin10Education };

enum DECLSPEC_DENUM TNtProductType : unsigned char { ptUnknown, ptWorkStation, ptServer, ptAdvancedServer, ptPersonal, ptProfessional, ptDatacenterServer, ptEnterprise, ptWebEdition };

enum DECLSPEC_DENUM TProcessorArchitecture : unsigned char { paUnknown, pax8632, pax8664, paIA64, paARM, paARM64 };

enum DECLSPEC_DENUM TTLBInformation : unsigned char { tiEntries, tiAssociativity };

enum DECLSPEC_DENUM TCacheInformation : unsigned char { ciLineSize, ciLinesPerTag, ciAssociativity, ciSize };

struct DECLSPEC_DRECORD TIntelSpecific
{
public:
	unsigned L2Cache;
	System::StaticArray<System::Byte, 16> CacheDescriptors;
	System::Byte BrandID;
	System::Byte FlushLineSize;
	System::Byte APICID;
	unsigned ExFeatures;
	unsigned Ex64Features;
	unsigned Ex64Features2;
	unsigned PowerManagementFeatures;
	System::Byte PhysicalAddressBits;
	System::Byte VirtualAddressBits;
};


struct DECLSPEC_DRECORD TCyrixSpecific
{
public:
	System::StaticArray<System::Byte, 4> L1CacheInfo;
	System::StaticArray<System::Byte, 4> TLBInfo;
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TAMDSpecific
{
public:
	unsigned ExFeatures;
	unsigned ExFeatures2;
	unsigned Features2;
	System::Byte BrandID;
	System::Byte FlushLineSize;
	System::Byte APICID;
	System::Word ExBrandID;
	System::StaticArray<System::Byte, 2> L1MByteInstructionTLB;
	System::StaticArray<System::Byte, 2> L1MByteDataTLB;
	System::StaticArray<System::Byte, 2> L1KByteInstructionTLB;
	System::StaticArray<System::Byte, 2> L1KByteDataTLB;
	System::StaticArray<System::Byte, 4> L1DataCache;
	System::StaticArray<System::Byte, 4> L1InstructionCache;
	System::StaticArray<System::Byte, 2> L2MByteInstructionTLB;
	System::StaticArray<System::Byte, 2> L2MByteDataTLB;
	System::StaticArray<System::Byte, 2> L2KByteDataTLB;
	System::StaticArray<System::Byte, 2> L2KByteInstructionTLB;
	unsigned L2Cache;
	unsigned L3Cache;
	unsigned AdvancedPowerManagement;
	System::Byte PhysicalAddressSize;
	System::Byte VirtualAddressSize;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TVIASpecific
{
public:
	unsigned ExFeatures;
	System::StaticArray<System::Byte, 2> DataTLB;
	System::StaticArray<System::Byte, 2> InstructionTLB;
	System::StaticArray<System::Byte, 4> L1DataCache;
	System::StaticArray<System::Byte, 4> L1InstructionCache;
	unsigned L2DataCache;
};


struct DECLSPEC_DRECORD TTransmetaSpecific
{
public:
	unsigned ExFeatures;
	System::StaticArray<System::Byte, 2> DataTLB;
	System::StaticArray<System::Byte, 2> CodeTLB;
	System::StaticArray<System::Byte, 4> L1DataCache;
	System::StaticArray<System::Byte, 4> L1CodeCache;
	unsigned L2Cache;
	unsigned RevisionABCD;
	unsigned RevisionXXXX;
	unsigned Frequency;
	unsigned CodeMorphingABCD;
	unsigned CodeMorphingXXXX;
	unsigned TransmetaFeatures;
	System::StaticArray<System::WideChar, 65> TransmetaInformations;
	unsigned CurrentVoltage;
	unsigned CurrentFrequency;
	unsigned CurrentPerformance;
};


enum DECLSPEC_DENUM TCacheFamily : unsigned char { cfInstructionTLB, cfDataTLB, cfL1InstructionCache, cfL1DataCache, cfL2Cache, cfL2TLB, cfL3Cache, cfTrace, cfOther };

struct DECLSPEC_DRECORD TCacheInfo
{
public:
	System::Byte D;
	TCacheFamily Family;
	unsigned Size;
	System::Byte WaysOfAssoc;
	System::Byte LineSize;
	System::Byte LinePerSector;
	unsigned Entries;
	System::PResStringRec I;
};


struct DECLSPEC_DRECORD TFreqInfo
{
public:
	__int64 RawFreq;
	__int64 NormFreq;
	__int64 InCycles;
	__int64 ExTicks;
};


enum DECLSPEC_DENUM TSSESupport : unsigned char { sse, sse2, sse3, ssse3, sse41, sse42, sse4A, sse5, avx };

typedef System::Set<TSSESupport, TSSESupport::sse, TSSESupport::avx> TSSESupports;

struct DECLSPEC_DRECORD TCpuInfo
{
public:
	bool HasInstruction;
	bool AES;
	bool MMX;
	bool ExMMX;
	bool _3DNow;
	bool Ex3DNow;
	TSSESupports SSE;
	bool IsFDIVOK;
	bool Is64Bits;
	bool DEPCapable;
	bool HasCacheInfo;
	bool HasExtendedInfo;
	System::Byte PType;
	System::Byte Family;
	System::Byte ExtendedFamily;
	System::Byte Model;
	System::Byte ExtendedModel;
	System::Byte Stepping;
	unsigned Features;
	TFreqInfo FrequencyInfo;
	System::StaticArray<char, 12> VendorIDString;
	System::StaticArray<char, 10> Manufacturer;
	System::StaticArray<char, 48> CpuName;
	unsigned L1DataCacheSize;
	System::Byte L1DataCacheLineSize;
	System::Byte L1DataCacheAssociativity;
	unsigned L1InstructionCacheSize;
	System::Byte L1InstructionCacheLineSize;
	System::Byte L1InstructionCacheAssociativity;
	unsigned L2CacheSize;
	System::Byte L2CacheLineSize;
	System::Byte L2CacheAssociativity;
	unsigned L3CacheSize;
	System::Byte L3CacheLineSize;
	System::Byte L3CacheAssociativity;
	System::Byte L3LinesPerSector;
	System::Byte LogicalCore;
	System::Byte PhysicalCore;
	bool HyperThreadingTechnology;
	bool HardwareHyperThreadingTechnology;
	
public:
	System::Byte CpuType;
	union
	{
		struct 
		{
			TVIASpecific ViaSpecific;
		};
		struct 
		{
			TTransmetaSpecific TransmetaSpecific;
		};
		struct 
		{
			TAMDSpecific AMDSpecific;
		};
		struct 
		{
			TCyrixSpecific CyrixSpecific;
		};
		struct 
		{
			TIntelSpecific IntelSpecific;
		};
		
	};
};


enum DECLSPEC_DENUM TOSEnabledFeature : unsigned char { oefFPU, oefSSE, oefAVX };

typedef System::Set<TOSEnabledFeature, TOSEnabledFeature::oefFPU, TOSEnabledFeature::oefAVX> TOSEnabledFeatures;

enum DECLSPEC_DENUM TFreeSysResKind : unsigned char { rtSystem, rtGdi, rtUser };

struct DECLSPEC_DRECORD TFreeSystemResources
{
public:
	int SystemRes;
	int GdiRes;
	int UserRes;
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE bool IsWinNT;
static _DELPHI_CONST System::Word Windows11InitialBuildNumber = System::Word(0x55f0);
static _DELPHI_CONST System::Word Windows2025ServerInitialBuildNumber = System::Word(0x65f4);
static _DELPHI_CONST System::Int8 CPU_TYPE_INTEL = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CPU_TYPE_CYRIX = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CPU_TYPE_AMD = System::Int8(0x3);
static _DELPHI_CONST System::Int8 CPU_TYPE_TRANSMETA = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CPU_TYPE_VIA = System::Int8(0x5);
extern DELPHI_PACKAGE System::StaticArray<char, 12> VendorIDIntel;
extern DELPHI_PACKAGE System::StaticArray<char, 12> VendorIDCyrix;
extern DELPHI_PACKAGE System::StaticArray<char, 12> VendorIDAMD;
extern DELPHI_PACKAGE System::StaticArray<char, 12> VendorIDTransmeta;
extern DELPHI_PACKAGE System::StaticArray<char, 12> VendorIDVIA;
static _DELPHI_CONST System::Int8 BIT_0 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 BIT_1 = System::Int8(0x2);
static _DELPHI_CONST System::Int8 BIT_2 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 BIT_3 = System::Int8(0x8);
static _DELPHI_CONST System::Int8 BIT_4 = System::Int8(0x10);
static _DELPHI_CONST System::Int8 BIT_5 = System::Int8(0x20);
static _DELPHI_CONST System::Int8 BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word BIT_8 = System::Word(0x100);
static _DELPHI_CONST System::Word BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int BIT_16 = int(0x10000);
static _DELPHI_CONST int BIT_17 = int(0x20000);
static _DELPHI_CONST int BIT_18 = int(0x40000);
static _DELPHI_CONST int BIT_19 = int(0x80000);
static _DELPHI_CONST int BIT_20 = int(0x100000);
static _DELPHI_CONST int BIT_21 = int(0x200000);
static _DELPHI_CONST int BIT_22 = int(0x400000);
static _DELPHI_CONST int BIT_23 = int(0x800000);
static _DELPHI_CONST int BIT_24 = int(0x1000000);
static _DELPHI_CONST int BIT_25 = int(0x2000000);
static _DELPHI_CONST int BIT_26 = int(0x4000000);
static _DELPHI_CONST int BIT_27 = int(0x8000000);
static _DELPHI_CONST int BIT_28 = int(0x10000000);
static _DELPHI_CONST int BIT_29 = int(0x20000000);
static _DELPHI_CONST int BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 FPU_FLAG = System::Int8(0x1);
static _DELPHI_CONST System::Int8 VME_FLAG = System::Int8(0x2);
static _DELPHI_CONST System::Int8 DE_FLAG = System::Int8(0x4);
static _DELPHI_CONST System::Int8 PSE_FLAG = System::Int8(0x8);
static _DELPHI_CONST System::Int8 TSC_FLAG = System::Int8(0x10);
static _DELPHI_CONST System::Int8 MSR_FLAG = System::Int8(0x20);
static _DELPHI_CONST System::Int8 PAE_FLAG = System::Int8(0x40);
static _DELPHI_CONST System::Byte MCE_FLAG = System::Byte(0x80);
static _DELPHI_CONST System::Word CX8_FLAG = System::Word(0x100);
static _DELPHI_CONST System::Word APIC_FLAG = System::Word(0x200);
static _DELPHI_CONST System::Word BIT_10_FLAG = System::Word(0x400);
static _DELPHI_CONST System::Word SEP_FLAG = System::Word(0x800);
static _DELPHI_CONST System::Word MTRR_FLAG = System::Word(0x1000);
static _DELPHI_CONST System::Word PGE_FLAG = System::Word(0x2000);
static _DELPHI_CONST System::Word MCA_FLAG = System::Word(0x4000);
static _DELPHI_CONST System::Word CMOV_FLAG = System::Word(0x8000);
static _DELPHI_CONST int PAT_FLAG = int(0x10000);
static _DELPHI_CONST int PSE36_FLAG = int(0x20000);
static _DELPHI_CONST int PSN_FLAG = int(0x40000);
static _DELPHI_CONST int CLFLSH_FLAG = int(0x80000);
static _DELPHI_CONST int BIT_20_FLAG = int(0x100000);
static _DELPHI_CONST int DS_FLAG = int(0x200000);
static _DELPHI_CONST int ACPI_FLAG = int(0x400000);
static _DELPHI_CONST int MMX_FLAG = int(0x800000);
static _DELPHI_CONST int FXSR_FLAG = int(0x1000000);
static _DELPHI_CONST int SSE_FLAG = int(0x2000000);
static _DELPHI_CONST int SSE2_FLAG = int(0x4000000);
static _DELPHI_CONST int SS_FLAG = int(0x8000000);
static _DELPHI_CONST int HTT_FLAG = int(0x10000000);
static _DELPHI_CONST int TM_FLAG = int(0x20000000);
static _DELPHI_CONST int BIT_30_FLAG = int(0x40000000);
static _DELPHI_CONST unsigned PBE_FLAG = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 INTEL_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 INTEL_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 INTEL_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 INTEL_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 INTEL_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 INTEL_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 INTEL_PAE = System::Int8(0x40);
static _DELPHI_CONST System::Byte INTEL_MCE = System::Byte(0x80);
static _DELPHI_CONST System::Word INTEL_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word INTEL_APIC = System::Word(0x200);
static _DELPHI_CONST System::Word INTEL_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word INTEL_SEP = System::Word(0x800);
static _DELPHI_CONST System::Word INTEL_MTRR = System::Word(0x1000);
static _DELPHI_CONST System::Word INTEL_PGE = System::Word(0x2000);
static _DELPHI_CONST System::Word INTEL_MCA = System::Word(0x4000);
static _DELPHI_CONST System::Word INTEL_CMOV = System::Word(0x8000);
static _DELPHI_CONST int INTEL_PAT = int(0x10000);
static _DELPHI_CONST int INTEL_PSE36 = int(0x20000);
static _DELPHI_CONST int INTEL_PSN = int(0x40000);
static _DELPHI_CONST int INTEL_CLFLSH = int(0x80000);
static _DELPHI_CONST int INTEL_BIT_20 = int(0x100000);
static _DELPHI_CONST int INTEL_DS = int(0x200000);
static _DELPHI_CONST int INTEL_ACPI = int(0x400000);
static _DELPHI_CONST int INTEL_MMX = int(0x800000);
static _DELPHI_CONST int INTEL_FXSR = int(0x1000000);
static _DELPHI_CONST int INTEL_SSE = int(0x2000000);
static _DELPHI_CONST int INTEL_SSE2 = int(0x4000000);
static _DELPHI_CONST int INTEL_SS = int(0x8000000);
static _DELPHI_CONST int INTEL_HTT = int(0x10000000);
static _DELPHI_CONST int INTEL_TM = int(0x20000000);
static _DELPHI_CONST int INTEL_IA64 = int(0x40000000);
static _DELPHI_CONST unsigned INTEL_PBE = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 EINTEL_SSE3 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EINTEL_PCLMULQDQ = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EINTEL_DTES64 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EINTEL_MONITOR = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EINTEL_DSCPL = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EINTEL_VMX = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EINTEL_SMX = System::Int8(0x40);
static _DELPHI_CONST System::Byte EINTEL_EST = System::Byte(0x80);
static _DELPHI_CONST System::Word EINTEL_TM2 = System::Word(0x100);
static _DELPHI_CONST System::Word EINTEL_SSSE3 = System::Word(0x200);
static _DELPHI_CONST System::Word EINTEL_CNXTID = System::Word(0x400);
static _DELPHI_CONST System::Word EINTEL_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word EINTEL_FMA = System::Word(0x1000);
static _DELPHI_CONST System::Word EINTEL_CX16 = System::Word(0x2000);
static _DELPHI_CONST System::Word EINTEL_XTPR = System::Word(0x4000);
static _DELPHI_CONST System::Word EINTEL_PDCM = System::Word(0x8000);
static _DELPHI_CONST int EINTEL_BIT_16 = int(0x10000);
static _DELPHI_CONST int EINTEL_PCID = int(0x20000);
static _DELPHI_CONST int EINTEL_DCA = int(0x40000);
static _DELPHI_CONST int EINTEL_SSE4_1 = int(0x80000);
static _DELPHI_CONST int EINTEL_SSE4_2 = int(0x100000);
static _DELPHI_CONST int EINTEL_X2APIC = int(0x200000);
static _DELPHI_CONST int EINTEL_MOVBE = int(0x400000);
static _DELPHI_CONST int EINTEL_POPCNT = int(0x800000);
static _DELPHI_CONST int EINTEL_TSC_DL = int(0x1000000);
static _DELPHI_CONST int EINTEL_AES = int(0x2000000);
static _DELPHI_CONST int EINTEL_XSAVE = int(0x4000000);
static _DELPHI_CONST int EINTEL_OSXSAVE = int(0x8000000);
static _DELPHI_CONST int EINTEL_AVX = int(0x10000000);
static _DELPHI_CONST int EINTEL_BIT_29 = int(0x20000000);
static _DELPHI_CONST int EINTEL_RDRAND = int(0x40000000);
static _DELPHI_CONST unsigned EINTEL_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_0 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_1 = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_2 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_3 = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_4 = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_5 = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EINTEL64_BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte EINTEL64_BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word EINTEL64_BIT_8 = System::Word(0x100);
static _DELPHI_CONST System::Word EINTEL64_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word EINTEL64_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word EINTEL64_SYS = System::Word(0x800);
static _DELPHI_CONST System::Word EINTEL64_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word EINTEL64_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word EINTEL64_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word EINTEL64_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int EINTEL64_BIT_16 = int(0x10000);
static _DELPHI_CONST int EINTEL64_BIT_17 = int(0x20000);
static _DELPHI_CONST int EINTEL64_BIT_18 = int(0x40000);
static _DELPHI_CONST int EINTEL64_BIT_19 = int(0x80000);
static _DELPHI_CONST int EINTEL64_XD = int(0x100000);
static _DELPHI_CONST int EINTEL64_BIT_21 = int(0x200000);
static _DELPHI_CONST int EINTEL64_BIT_22 = int(0x400000);
static _DELPHI_CONST int EINTEL64_BIT_23 = int(0x800000);
static _DELPHI_CONST int EINTEL64_BIT_24 = int(0x1000000);
static _DELPHI_CONST int EINTEL64_BIT_25 = int(0x2000000);
static _DELPHI_CONST int EINTEL64_1GBYTE = int(0x4000000);
static _DELPHI_CONST int EINTEL64_RDTSCP = int(0x8000000);
static _DELPHI_CONST int EINTEL64_BIT_28 = int(0x10000000);
static _DELPHI_CONST int EINTEL64_EM64T = int(0x20000000);
static _DELPHI_CONST int EINTEL64_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned EINTEL64_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 EINTEL64_2_LAHF = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EINTEL64_2_BIT_1 = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EINTEL64_2_BIT_2 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EINTEL64_2_BIT_3 = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EINTEL64_2_BIT_4 = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EINTEL64_2_BIT_5 = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EINTEL64_2_BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte EINTEL64_2_BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_8 = System::Word(0x100);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word EINTEL64_2_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int EINTEL64_2_BIT_16 = int(0x10000);
static _DELPHI_CONST int EINTEL64_2_BIT_17 = int(0x20000);
static _DELPHI_CONST int EINTEL64_2_BIT_18 = int(0x40000);
static _DELPHI_CONST int EINTEL64_2_BIT_19 = int(0x80000);
static _DELPHI_CONST int EINTEL64_2_BIT_20 = int(0x100000);
static _DELPHI_CONST int EINTEL64_2_BIT_21 = int(0x200000);
static _DELPHI_CONST int EINTEL64_2_BIT_22 = int(0x400000);
static _DELPHI_CONST int EINTEL64_2_BIT_23 = int(0x800000);
static _DELPHI_CONST int EINTEL64_2_BIT_24 = int(0x1000000);
static _DELPHI_CONST int EINTEL64_2_BIT_25 = int(0x2000000);
static _DELPHI_CONST int EINTEL64_2_BIT_26 = int(0x4000000);
static _DELPHI_CONST int EINTEL64_2_BIT_27 = int(0x8000000);
static _DELPHI_CONST int EINTEL64_2_BIT_28 = int(0x10000000);
static _DELPHI_CONST int EINTEL64_2_BIT_29 = int(0x20000000);
static _DELPHI_CONST int EINTEL64_2_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned EINTEL64_2_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 PINTEL_TEMPSENSOR = System::Int8(0x1);
static _DELPHI_CONST System::Int8 PINTEL_TURBOBOOST = System::Int8(0x2);
static _DELPHI_CONST System::Int8 PINTEL_ARAT = System::Int8(0x4);
static _DELPHI_CONST System::Int8 PINTEL_BIT_3 = System::Int8(0x8);
static _DELPHI_CONST System::Int8 PINTEL_PLN = System::Int8(0x10);
static _DELPHI_CONST System::Int8 PINTEL_ECMD = System::Int8(0x20);
static _DELPHI_CONST System::Int8 PINTEL_PTM = System::Int8(0x40);
static _DELPHI_CONST System::Byte PINTEL_BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word PINTEL_BIT_8 = System::Word(0x100);
static _DELPHI_CONST System::Word PINTEL_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word PINTEL_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word PINTEL_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word PINTEL_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word PINTEL_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word PINTEL_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word PINTEL_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int PINTEL_BIT_16 = int(0x10000);
static _DELPHI_CONST int PINTEL_BIT_17 = int(0x20000);
static _DELPHI_CONST int PINTEL_BIT_18 = int(0x40000);
static _DELPHI_CONST int PINTEL_BIT_19 = int(0x80000);
static _DELPHI_CONST int PINTEL_BIT_20 = int(0x100000);
static _DELPHI_CONST int PINTEL_BIT_21 = int(0x200000);
static _DELPHI_CONST int PINTEL_BIT_22 = int(0x400000);
static _DELPHI_CONST int PINTEL_BIT_23 = int(0x800000);
static _DELPHI_CONST int PINTEL_BIT_24 = int(0x1000000);
static _DELPHI_CONST int PINTEL_BIT_25 = int(0x2000000);
static _DELPHI_CONST int PINTEL_BIT_26 = int(0x4000000);
static _DELPHI_CONST int PINTEL_BIT_27 = int(0x8000000);
static _DELPHI_CONST int PINTEL_BIT_28 = int(0x10000000);
static _DELPHI_CONST int PINTEL_BIT_29 = int(0x20000000);
static _DELPHI_CONST int PINTEL_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned PINTEL_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 AMD_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AMD_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AMD_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AMD_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AMD_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 AMD_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 AMD_PAE = System::Int8(0x40);
static _DELPHI_CONST System::Byte AMD_MCE = System::Byte(0x80);
static _DELPHI_CONST System::Word AMD_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word AMD_APIC = System::Word(0x200);
static _DELPHI_CONST System::Word AMD_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word AMD_SEP_BIT = System::Word(0x800);
static _DELPHI_CONST System::Word AMD_MTRR = System::Word(0x1000);
static _DELPHI_CONST System::Word AMD_PGE = System::Word(0x2000);
static _DELPHI_CONST System::Word AMD_MCA = System::Word(0x4000);
static _DELPHI_CONST System::Word AMD_CMOV = System::Word(0x8000);
static _DELPHI_CONST int AMD_PAT = int(0x10000);
static _DELPHI_CONST int AMD_PSE36 = int(0x20000);
static _DELPHI_CONST int AMD_BIT_18 = int(0x40000);
static _DELPHI_CONST int AMD_CLFLSH = int(0x80000);
static _DELPHI_CONST int AMD_BIT_20 = int(0x100000);
static _DELPHI_CONST int AMD_BIT_21 = int(0x200000);
static _DELPHI_CONST int AMD_BIT_22 = int(0x400000);
static _DELPHI_CONST int AMD_MMX = int(0x800000);
static _DELPHI_CONST int AMD_FXSR = int(0x1000000);
static _DELPHI_CONST int AMD_SSE = int(0x2000000);
static _DELPHI_CONST int AMD_SSE2 = int(0x4000000);
static _DELPHI_CONST int AMD_BIT_27 = int(0x8000000);
static _DELPHI_CONST int AMD_HTT = int(0x10000000);
static _DELPHI_CONST int AMD_BIT_29 = int(0x20000000);
static _DELPHI_CONST int AMD_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned AMD_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 AMD2_SSE3 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AMD2_PCLMULQDQ = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AMD2_BIT_2 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AMD2_MONITOR = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AMD2_BIT_4 = System::Int8(0x10);
static _DELPHI_CONST System::Int8 AMD2_BIT_5 = System::Int8(0x20);
static _DELPHI_CONST System::Int8 AMD2_BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte AMD2_BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word AMD2_BIT_8 = System::Word(0x100);
static _DELPHI_CONST System::Word AMD2_SSSE3 = System::Word(0x200);
static _DELPHI_CONST System::Word AMD2_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word AMD2_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word AMD2_FMA = System::Word(0x1000);
static _DELPHI_CONST System::Word AMD2_CMPXCHG16B = System::Word(0x2000);
static _DELPHI_CONST System::Word AMD2_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word AMD2_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int AMD2_BIT_16 = int(0x10000);
static _DELPHI_CONST int AMD2_BIT_17 = int(0x20000);
static _DELPHI_CONST int AMD2_BIT_18 = int(0x40000);
static _DELPHI_CONST int AMD2_SSE41 = int(0x80000);
static _DELPHI_CONST int AMD2_SSE42 = int(0x100000);
static _DELPHI_CONST int AMD2_BIT_21 = int(0x200000);
static _DELPHI_CONST int AMD2_BIT_22 = int(0x400000);
static _DELPHI_CONST int AMD2_POPCNT = int(0x800000);
static _DELPHI_CONST int AMD2_BIT_24 = int(0x1000000);
static _DELPHI_CONST int AMD2_AES = int(0x2000000);
static _DELPHI_CONST int AMD2_XSAVE = int(0x4000000);
static _DELPHI_CONST int AMD2_OSXSAVE = int(0x8000000);
static _DELPHI_CONST int AMD2_AVX = int(0x10000000);
static _DELPHI_CONST int AMD2_F16C = int(0x20000000);
static _DELPHI_CONST int AMD2_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned AMD2_RAZ = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 EAMD_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EAMD_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EAMD_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EAMD_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EAMD_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EAMD_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EAMD_PAE = System::Int8(0x40);
static _DELPHI_CONST System::Byte EAMD_MCE = System::Byte(0x80);
static _DELPHI_CONST System::Word EAMD_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word EAMD_APIC = System::Word(0x200);
static _DELPHI_CONST System::Word EAMD_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word EAMD_SEP = System::Word(0x800);
static _DELPHI_CONST System::Word EAMD_MTRR = System::Word(0x1000);
static _DELPHI_CONST System::Word EAMD_PGE = System::Word(0x2000);
static _DELPHI_CONST System::Word EAMD_MCA = System::Word(0x4000);
static _DELPHI_CONST System::Word EAMD_CMOV = System::Word(0x8000);
static _DELPHI_CONST int EAMD_PAT = int(0x10000);
static _DELPHI_CONST int EAMD_PSE2 = int(0x20000);
static _DELPHI_CONST int EAMD_BIT_18 = int(0x40000);
static _DELPHI_CONST int EAMD_BIT_19 = int(0x80000);
static _DELPHI_CONST int EAMD_NX = int(0x100000);
static _DELPHI_CONST int EAMD_BIT_21 = int(0x200000);
static _DELPHI_CONST int EAMD_EXMMX = int(0x400000);
static _DELPHI_CONST int EAMD_MMX = int(0x800000);
static _DELPHI_CONST int EAMD_FX = int(0x1000000);
static _DELPHI_CONST int EAMD_FFX = int(0x2000000);
static _DELPHI_CONST int EAMD_1GBPAGE = int(0x4000000);
static _DELPHI_CONST int EAMD_RDTSCP = int(0x8000000);
static _DELPHI_CONST int EAMD_BIT_28 = int(0x10000000);
static _DELPHI_CONST int EAMD_LONG = int(0x20000000);
static _DELPHI_CONST int EAMD_EX3DNOW = int(0x40000000);
static _DELPHI_CONST unsigned EAMD_3DNOW = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 EAMD2_LAHF = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EAMD2_CMPLEGACY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EAMD2_SVM = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EAMD2_EXTAPICSPACE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EAMD2_ALTMOVCR8 = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EAMD2_ABM = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EAMD2_SSE4A = System::Int8(0x40);
static _DELPHI_CONST System::Byte EAMD2_MISALIGNSSE = System::Byte(0x80);
static _DELPHI_CONST System::Word EAMD2_3DNOWPREFETCH = System::Word(0x100);
static _DELPHI_CONST System::Word EAMD2_OSVW = System::Word(0x200);
static _DELPHI_CONST System::Word EAMD2_IBS = System::Word(0x400);
static _DELPHI_CONST System::Word EAMD2_XOP = System::Word(0x800);
static _DELPHI_CONST System::Word EAMD2_SKINIT = System::Word(0x1000);
static _DELPHI_CONST System::Word EAMD2_WDT = System::Word(0x2000);
static _DELPHI_CONST System::Word EAMD2_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word EAMD2_LWP = System::Word(0x8000);
static _DELPHI_CONST int EAMD2_FMA4 = int(0x10000);
static _DELPHI_CONST int EAMD2_BIT_17 = int(0x20000);
static _DELPHI_CONST int EAMD2_BIT_18 = int(0x40000);
static _DELPHI_CONST int EAMD2_NODEID = int(0x80000);
static _DELPHI_CONST int EAMD2_BIT_20 = int(0x100000);
static _DELPHI_CONST int EAMD2_TBM = int(0x200000);
static _DELPHI_CONST int EAMD2_TOPOLOGYEXT = int(0x400000);
static _DELPHI_CONST int EAMD2_BIT_23 = int(0x800000);
static _DELPHI_CONST int EAMD2_BIT_24 = int(0x1000000);
static _DELPHI_CONST int EAMD2_BIT_25 = int(0x2000000);
static _DELPHI_CONST int EAMD2_BIT_26 = int(0x4000000);
static _DELPHI_CONST int EAMD2_BIT_27 = int(0x8000000);
static _DELPHI_CONST int EAMD2_BIT_28 = int(0x10000000);
static _DELPHI_CONST int EAMD2_BIT_29 = int(0x20000000);
static _DELPHI_CONST int EAMD2_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned EAMD2_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 PAMD_TEMPSENSOR = System::Int8(0x1);
static _DELPHI_CONST System::Int8 PAMD_FREQUENCYID = System::Int8(0x2);
static _DELPHI_CONST System::Int8 PAMD_VOLTAGEID = System::Int8(0x4);
static _DELPHI_CONST System::Int8 PAMD_THERMALTRIP = System::Int8(0x8);
static _DELPHI_CONST System::Int8 PAMD_THERMALMONITOR = System::Int8(0x10);
static _DELPHI_CONST System::Int8 PAMD_BIT_5 = System::Int8(0x20);
static _DELPHI_CONST System::Int8 PAMD_100MHZSTEP = System::Int8(0x40);
static _DELPHI_CONST System::Byte PAMD_HWPSTATE = System::Byte(0x80);
static _DELPHI_CONST System::Word PAMD_TSC_INVARIANT = System::Word(0x100);
static _DELPHI_CONST System::Word PAMD_CPB = System::Word(0x200);
static _DELPHI_CONST System::Word PAMD_EFFFREQRO = System::Word(0x400);
static _DELPHI_CONST System::Word PAMD_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word PAMD_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word PAMD_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word PAMD_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word PAMD_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int PAMD_BIT_16 = int(0x10000);
static _DELPHI_CONST int PAMD_BIT_17 = int(0x20000);
static _DELPHI_CONST int PAMD_BIT_18 = int(0x40000);
static _DELPHI_CONST int PAMD_BIT_19 = int(0x80000);
static _DELPHI_CONST int PAMD_BIT_20 = int(0x100000);
static _DELPHI_CONST int PAMD_BIT_21 = int(0x200000);
static _DELPHI_CONST int PAMD_BIT_22 = int(0x400000);
static _DELPHI_CONST int PAMD_BIT_23 = int(0x800000);
static _DELPHI_CONST int PAMD_BIT_24 = int(0x1000000);
static _DELPHI_CONST int PAMD_BIT_25 = int(0x2000000);
static _DELPHI_CONST int PAMD_BIT_26 = int(0x4000000);
static _DELPHI_CONST int PAMD_BIT_27 = int(0x8000000);
static _DELPHI_CONST int PAMD_BIT_28 = int(0x10000000);
static _DELPHI_CONST int PAMD_BIT_29 = int(0x20000000);
static _DELPHI_CONST int PAMD_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned PAMD_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 AMD_ASSOC_RESERVED = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AMD_ASSOC_DIRECT = System::Int8(0x1);
static _DELPHI_CONST System::Byte AMD_ASSOC_FULLY = System::Byte(0xff);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_DISABLED = System::Int8(0x0);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_DIRECT = System::Int8(0x1);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_2WAY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_4WAY = System::Int8(0x4);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_8WAY = System::Int8(0x6);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_16WAY = System::Int8(0x8);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_32WAY = System::Int8(0xa);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_48WAY = System::Int8(0xb);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_64WAY = System::Int8(0xc);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_96WAY = System::Int8(0xd);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_128WAY = System::Int8(0xe);
static _DELPHI_CONST System::Int8 AMD_L2_ASSOC_FULLY = System::Int8(0xf);
static _DELPHI_CONST System::Int8 VIA_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 VIA_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 VIA_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 VIA_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 VIA_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 VIA_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 VIA_PAE = System::Int8(0x40);
static _DELPHI_CONST System::Byte VIA_MCE = System::Byte(0x80);
static _DELPHI_CONST System::Word VIA_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word VIA_APIC = System::Word(0x200);
static _DELPHI_CONST System::Word VIA_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word VIA_SEP = System::Word(0x800);
static _DELPHI_CONST System::Word VIA_MTRR = System::Word(0x1000);
static _DELPHI_CONST System::Word VIA_PTE = System::Word(0x2000);
static _DELPHI_CONST System::Word VIA_MCA = System::Word(0x4000);
static _DELPHI_CONST System::Word VIA_CMOVE = System::Word(0x8000);
static _DELPHI_CONST int VIA_PAT = int(0x10000);
static _DELPHI_CONST int VIA_PSE2 = int(0x20000);
static _DELPHI_CONST int VIA_SNUM = int(0x40000);
static _DELPHI_CONST int VIA_BIT_19 = int(0x80000);
static _DELPHI_CONST int VIA_BIT_20 = int(0x100000);
static _DELPHI_CONST int VIA_BIT_21 = int(0x200000);
static _DELPHI_CONST int VIA_BIT_22 = int(0x400000);
static _DELPHI_CONST int VIA_MMX = int(0x800000);
static _DELPHI_CONST int VIA_FX = int(0x1000000);
static _DELPHI_CONST int VIA_SSE = int(0x2000000);
static _DELPHI_CONST int VIA_BIT_26 = int(0x4000000);
static _DELPHI_CONST int VIA_BIT_27 = int(0x8000000);
static _DELPHI_CONST int VIA_BIT_28 = int(0x10000000);
static _DELPHI_CONST int VIA_BIT_29 = int(0x20000000);
static _DELPHI_CONST int VIA_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned VIA_3DNOW = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 EVIA_AIS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EVIA_AISE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EVIA_NO_RNG = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EVIA_RNGE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EVIA_MSR = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EVIA_FEMMS = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EVIA_NO_ACE = System::Int8(0x40);
static _DELPHI_CONST System::Byte EVIA_ACEE = System::Byte(0x80);
static _DELPHI_CONST System::Word EVIA_BIT_8 = System::Word(0x100);
static _DELPHI_CONST System::Word EVIA_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word EVIA_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word EVIA_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word EVIA_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word EVIA_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word EVIA_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word EVIA_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int EVIA_BIT_16 = int(0x10000);
static _DELPHI_CONST int EVIA_BIT_17 = int(0x20000);
static _DELPHI_CONST int EVIA_BIT_18 = int(0x40000);
static _DELPHI_CONST int EVIA_BIT_19 = int(0x80000);
static _DELPHI_CONST int EVIA_BIT_20 = int(0x100000);
static _DELPHI_CONST int EVIA_BIT_21 = int(0x200000);
static _DELPHI_CONST int EVIA_BIT_22 = int(0x400000);
static _DELPHI_CONST int EVIA_BIT_23 = int(0x800000);
static _DELPHI_CONST int EVIA_BIT_24 = int(0x1000000);
static _DELPHI_CONST int EVIA_BIT_25 = int(0x2000000);
static _DELPHI_CONST int EVIA_BIT_26 = int(0x4000000);
static _DELPHI_CONST int EVIA_BIT_27 = int(0x8000000);
static _DELPHI_CONST int EVIA_BIT_28 = int(0x10000000);
static _DELPHI_CONST int EVIA_BIT_29 = int(0x20000000);
static _DELPHI_CONST int EVIA_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned EVIA_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 CYRIX_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CYRIX_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CYRIX_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CYRIX_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CYRIX_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 CYRIX_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 CYRIX_PAE = System::Int8(0x40);
static _DELPHI_CONST System::Byte CYRIX_MCE = System::Byte(0x80);
static _DELPHI_CONST System::Word CYRIX_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word CYRIX_APIC = System::Word(0x200);
static _DELPHI_CONST System::Word CYRIX_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word CYRIX_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word CYRIX_MTRR = System::Word(0x1000);
static _DELPHI_CONST System::Word CYRIX_PGE = System::Word(0x2000);
static _DELPHI_CONST System::Word CYRIX_MCA = System::Word(0x4000);
static _DELPHI_CONST System::Word CYRIX_CMOV = System::Word(0x8000);
static _DELPHI_CONST int CYRIX_BIT_16 = int(0x10000);
static _DELPHI_CONST int CYRIX_BIT_17 = int(0x20000);
static _DELPHI_CONST int CYRIX_BIT_18 = int(0x40000);
static _DELPHI_CONST int CYRIX_BIT_19 = int(0x80000);
static _DELPHI_CONST int CYRIX_BIT_20 = int(0x100000);
static _DELPHI_CONST int CYRIX_BIT_21 = int(0x200000);
static _DELPHI_CONST int CYRIX_BIT_22 = int(0x400000);
static _DELPHI_CONST int CYRIX_MMX = int(0x800000);
static _DELPHI_CONST int CYRIX_BIT_24 = int(0x1000000);
static _DELPHI_CONST int CYRIX_BIT_25 = int(0x2000000);
static _DELPHI_CONST int CYRIX_BIT_26 = int(0x4000000);
static _DELPHI_CONST int CYRIX_BIT_27 = int(0x8000000);
static _DELPHI_CONST int CYRIX_BIT_28 = int(0x10000000);
static _DELPHI_CONST int CYRIX_BIT_29 = int(0x20000000);
static _DELPHI_CONST int CYRIX_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned CYRIX_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 ECYRIX_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 ECYRIX_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 ECYRIX_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 ECYRIX_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 ECYRIX_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 ECYRIX_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 ECYRIX_PAE = System::Int8(0x40);
static _DELPHI_CONST System::Byte ECYRIX_MCE = System::Byte(0x80);
static _DELPHI_CONST System::Word ECYRIX_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word ECYRIX_APIC = System::Word(0x200);
static _DELPHI_CONST System::Word ECYRIX_SEP = System::Word(0x400);
static _DELPHI_CONST System::Word ECYRIX_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word ECYRIX_MTRR = System::Word(0x1000);
static _DELPHI_CONST System::Word ECYRIX_PGE = System::Word(0x2000);
static _DELPHI_CONST System::Word ECYRIX_MCA = System::Word(0x4000);
static _DELPHI_CONST System::Word ECYRIX_ICMOV = System::Word(0x8000);
static _DELPHI_CONST int ECYRIX_FCMOV = int(0x10000);
static _DELPHI_CONST int ECYRIX_BIT_17 = int(0x20000);
static _DELPHI_CONST int ECYRIX_BIT_18 = int(0x40000);
static _DELPHI_CONST int ECYRIX_BIT_19 = int(0x80000);
static _DELPHI_CONST int ECYRIX_BIT_20 = int(0x100000);
static _DELPHI_CONST int ECYRIX_BIT_21 = int(0x200000);
static _DELPHI_CONST int ECYRIX_BIT_22 = int(0x400000);
static _DELPHI_CONST int ECYRIX_MMX = int(0x800000);
static _DELPHI_CONST int ECYRIX_EMMX = int(0x1000000);
static _DELPHI_CONST int ECYRIX_BIT_25 = int(0x2000000);
static _DELPHI_CONST int ECYRIX_BIT_26 = int(0x4000000);
static _DELPHI_CONST int ECYRIX_BIT_27 = int(0x8000000);
static _DELPHI_CONST int ECYRIX_BIT_28 = int(0x10000000);
static _DELPHI_CONST int ECYRIX_BIT_29 = int(0x20000000);
static _DELPHI_CONST int ECYRIX_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned ECYRIX_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 TRANSMETA_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 TRANSMETA_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 TRANSMETA_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 TRANSMETA_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 TRANSMETA_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 TRANSMETA_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 TRANSMETA_BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte TRANSMETA_BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word TRANSMETA_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word TRANSMETA_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word TRANSMETA_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word TRANSMETA_SEP = System::Word(0x800);
static _DELPHI_CONST System::Word TRANSMETA_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word TRANSMETA_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word TRANSMETA_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word TRANSMETA_CMOV = System::Word(0x8000);
static _DELPHI_CONST int TRANSMETA_BIT_16 = int(0x10000);
static _DELPHI_CONST int TRANSMETA_BIT_17 = int(0x20000);
static _DELPHI_CONST int TRANSMETA_PSN = int(0x40000);
static _DELPHI_CONST int TRANSMETA_BIT_19 = int(0x80000);
static _DELPHI_CONST int TRANSMETA_BIT_20 = int(0x100000);
static _DELPHI_CONST int TRANSMETA_BIT_21 = int(0x200000);
static _DELPHI_CONST int TRANSMETA_BIT_22 = int(0x400000);
static _DELPHI_CONST int TRANSMETA_MMX = int(0x800000);
static _DELPHI_CONST int TRANSMETA_BIT_24 = int(0x1000000);
static _DELPHI_CONST int TRANSMETA_BIT_25 = int(0x2000000);
static _DELPHI_CONST int TRANSMETA_BIT_26 = int(0x4000000);
static _DELPHI_CONST int TRANSMETA_BIT_27 = int(0x8000000);
static _DELPHI_CONST int TRANSMETA_BIT_28 = int(0x10000000);
static _DELPHI_CONST int TRANSMETA_BIT_29 = int(0x20000000);
static _DELPHI_CONST int TRANSMETA_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned TRANSMETA_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 ETRANSMETA_FPU = System::Int8(0x1);
static _DELPHI_CONST System::Int8 ETRANSMETA_VME = System::Int8(0x2);
static _DELPHI_CONST System::Int8 ETRANSMETA_DE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 ETRANSMETA_PSE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 ETRANSMETA_TSC = System::Int8(0x10);
static _DELPHI_CONST System::Int8 ETRANSMETA_MSR = System::Int8(0x20);
static _DELPHI_CONST System::Int8 ETRANSMETA_BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte ETRANSMETA_BIT_7 = System::Byte(0x80);
static _DELPHI_CONST System::Word ETRANSMETA_CX8 = System::Word(0x100);
static _DELPHI_CONST System::Word ETRANSMETA_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word ETRANSMETA_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word ETRANSMETA_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word ETRANSMETA_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word ETRANSMETA_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word ETRANSMETA_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word ETRANSMETA_CMOV = System::Word(0x8000);
static _DELPHI_CONST int ETRANSMETA_FCMOV = int(0x10000);
static _DELPHI_CONST int ETRANSMETA_BIT_17 = int(0x20000);
static _DELPHI_CONST int ETRANSMETA_BIT_18 = int(0x40000);
static _DELPHI_CONST int ETRANSMETA_BIT_19 = int(0x80000);
static _DELPHI_CONST int ETRANSMETA_BIT_20 = int(0x100000);
static _DELPHI_CONST int ETRANSMETA_BIT_21 = int(0x200000);
static _DELPHI_CONST int ETRANSMETA_BIT_22 = int(0x400000);
static _DELPHI_CONST int ETRANSMETA_MMX = int(0x800000);
static _DELPHI_CONST int ETRANSMETA_BIT_24 = int(0x1000000);
static _DELPHI_CONST int ETRANSMETA_BIT_25 = int(0x2000000);
static _DELPHI_CONST int ETRANSMETA_BIT_26 = int(0x4000000);
static _DELPHI_CONST int ETRANSMETA_BIT_27 = int(0x8000000);
static _DELPHI_CONST int ETRANSMETA_BIT_28 = int(0x10000000);
static _DELPHI_CONST int ETRANSMETA_BIT_29 = int(0x20000000);
static _DELPHI_CONST int ETRANSMETA_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned ETRANSMETA_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 STRANSMETA_RECOVERY = System::Int8(0x1);
static _DELPHI_CONST System::Int8 STRANSMETA_LONGRUN = System::Int8(0x2);
static _DELPHI_CONST System::Int8 STRANSMETA_BIT_2 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 STRANSMETA_LRTI = System::Int8(0x8);
static _DELPHI_CONST System::Int8 STRANSMETA_BIT_4 = System::Int8(0x10);
static _DELPHI_CONST System::Int8 STRANSMETA_BIT_5 = System::Int8(0x20);
static _DELPHI_CONST System::Int8 STRANSMETA_BIT_6 = System::Int8(0x40);
static _DELPHI_CONST System::Byte STRANSMETA_PTTI1 = System::Byte(0x80);
static _DELPHI_CONST System::Word STRANSMETA_PTTI2 = System::Word(0x100);
static _DELPHI_CONST System::Word STRANSMETA_BIT_9 = System::Word(0x200);
static _DELPHI_CONST System::Word STRANSMETA_BIT_10 = System::Word(0x400);
static _DELPHI_CONST System::Word STRANSMETA_BIT_11 = System::Word(0x800);
static _DELPHI_CONST System::Word STRANSMETA_BIT_12 = System::Word(0x1000);
static _DELPHI_CONST System::Word STRANSMETA_BIT_13 = System::Word(0x2000);
static _DELPHI_CONST System::Word STRANSMETA_BIT_14 = System::Word(0x4000);
static _DELPHI_CONST System::Word STRANSMETA_BIT_15 = System::Word(0x8000);
static _DELPHI_CONST int STRANSMETA_BIT_16 = int(0x10000);
static _DELPHI_CONST int STRANSMETA_BIT_17 = int(0x20000);
static _DELPHI_CONST int STRANSMETA_BIT_18 = int(0x40000);
static _DELPHI_CONST int STRANSMETA_BIT_19 = int(0x80000);
static _DELPHI_CONST int STRANSMETA_BIT_20 = int(0x100000);
static _DELPHI_CONST int STRANSMETA_BIT_21 = int(0x200000);
static _DELPHI_CONST int STRANSMETA_BIT_22 = int(0x400000);
static _DELPHI_CONST int STRANSMETA_BIT_23 = int(0x800000);
static _DELPHI_CONST int STRANSMETA_BIT_24 = int(0x1000000);
static _DELPHI_CONST int STRANSMETA_BIT_25 = int(0x2000000);
static _DELPHI_CONST int STRANSMETA_BIT_26 = int(0x4000000);
static _DELPHI_CONST int STRANSMETA_BIT_27 = int(0x8000000);
static _DELPHI_CONST int STRANSMETA_BIT_28 = int(0x10000000);
static _DELPHI_CONST int STRANSMETA_BIT_29 = int(0x20000000);
static _DELPHI_CONST int STRANSMETA_BIT_30 = int(0x40000000);
static _DELPHI_CONST unsigned STRANSMETA_BIT_31 = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 MXCSR_IE = System::Int8(0x1);
static _DELPHI_CONST System::Int8 MXCSR_DE = System::Int8(0x2);
static _DELPHI_CONST System::Int8 MXCSR_ZE = System::Int8(0x4);
static _DELPHI_CONST System::Int8 MXCSR_OE = System::Int8(0x8);
static _DELPHI_CONST System::Int8 MXCSR_UE = System::Int8(0x10);
static _DELPHI_CONST System::Int8 MXCSR_PE = System::Int8(0x20);
static _DELPHI_CONST System::Int8 MXCSR_DAZ = System::Int8(0x40);
static _DELPHI_CONST System::Byte MXCSR_IM = System::Byte(0x80);
static _DELPHI_CONST System::Word MXCSR_DM = System::Word(0x100);
static _DELPHI_CONST System::Word MXCSR_ZM = System::Word(0x200);
static _DELPHI_CONST System::Word MXCSR_OM = System::Word(0x400);
static _DELPHI_CONST System::Word MXCSR_UM = System::Word(0x800);
static _DELPHI_CONST System::Word MXCSR_PM = System::Word(0x1000);
static _DELPHI_CONST System::Word MXCSR_RC1 = System::Word(0x2000);
static _DELPHI_CONST System::Word MXCSR_RC2 = System::Word(0x4000);
static _DELPHI_CONST System::Word MXCSR_RC = System::Word(0x6000);
static _DELPHI_CONST System::Word MXCSR_FZ = System::Word(0x8000);
extern DELPHI_PACKAGE System::StaticArray<TCacheInfo, 103> IntelCacheDescription;
extern DELPHI_PACKAGE unsigned ProcessorCount;
extern DELPHI_PACKAGE unsigned AllocGranularity;
extern DELPHI_PACKAGE unsigned PageSize;
extern DELPHI_PACKAGE bool __fastcall DelEnvironmentVar(const System::UnicodeString Name);
extern DELPHI_PACKAGE bool __fastcall ExpandEnvironmentVar(System::UnicodeString &Value);
extern DELPHI_PACKAGE bool __fastcall ExpandEnvironmentVarCustom(System::UnicodeString &Value, System::Classes::TStrings* Vars);
extern DELPHI_PACKAGE bool __fastcall GetEnvironmentVar(const System::UnicodeString Name, /* out */ System::UnicodeString &Value)/* overload */;
extern DELPHI_PACKAGE bool __fastcall GetEnvironmentVar(const System::UnicodeString Name, /* out */ System::UnicodeString &Value, bool Expand)/* overload */;
extern DELPHI_PACKAGE bool __fastcall SetEnvironmentVar(const System::UnicodeString Name, const System::UnicodeString Value);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetCurrentFolder();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetWindowsFolder();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetWindowsSystemFolder();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetWindowsTempFolder();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetDesktopFolder();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetProgramsFolder();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetIPAddress(const System::UnicodeString HostName);
extern DELPHI_PACKAGE void __fastcall GetIpAddresses(System::Classes::TStrings* Results)/* overload */;
extern DELPHI_PACKAGE void __fastcall GetIpAddresses(System::Classes::TStrings* Results, const System::AnsiString HostName)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetLocalComputerName();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetLocalUserName();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetUserDomainName(const System::UnicodeString CurUser);
extern DELPHI_PACKAGE System::WideString __fastcall GetWorkGroupName();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetDomainName();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetBIOSName();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetBIOSCopyright();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetBIOSExtendedInfo();
extern DELPHI_PACKAGE bool __fastcall LoadedModulesList(System::Classes::TStrings* const List, unsigned ProcessID, bool HandlesOnly = false);
extern DELPHI_PACKAGE bool __fastcall GetTasksList(System::Classes::TStrings* const List);
extern DELPHI_PACKAGE unsigned __fastcall ModuleFromAddr(const void * Addr);
extern DELPHI_PACKAGE bool __fastcall IsSystemModule(const unsigned Module);
extern DELPHI_PACKAGE void __fastcall BeginModuleFromAddrCache();
extern DELPHI_PACKAGE void __fastcall EndModuleFromAddrCache();
extern DELPHI_PACKAGE unsigned __fastcall CachedModuleFromAddr(const void * Addr);
extern DELPHI_PACKAGE bool __fastcall IsMainAppWindow(Winapi::Windows::THandle Wnd);
extern DELPHI_PACKAGE bool __fastcall IsWindowResponding(Winapi::Windows::THandle Wnd, int Timeout);
extern DELPHI_PACKAGE HICON __fastcall GetWindowIcon(Winapi::Windows::THandle Wnd, bool LargeIcon);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetWindowCaption(Winapi::Windows::THandle Wnd);
extern DELPHI_PACKAGE TJclTerminateAppResult __fastcall TerminateApp(unsigned ProcessID, int Timeout);
extern DELPHI_PACKAGE TJclTerminateAppResult __fastcall TerminateTask(Winapi::Windows::THandle Wnd, int Timeout);
extern DELPHI_PACKAGE Winapi::Windows::THandle __fastcall GetMainAppWndFromPid(unsigned PID);
extern DELPHI_PACKAGE HWND __fastcall GetWndFromPid(unsigned PID, const System::UnicodeString WindowClassName);
extern DELPHI_PACKAGE int __fastcall GetWindowsMajorVersionNumber();
extern DELPHI_PACKAGE int __fastcall GetWindowsMinorVersionNumber();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetWindowsVersionNumber();
extern DELPHI_PACKAGE int __fastcall GetWindowsServicePackVersion();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetWindowsServicePackVersionString();
extern DELPHI_PACKAGE bool __fastcall GetNativeSystemInfo(Winapi::Windows::TSystemInfo &SystemInfo);
extern DELPHI_PACKAGE TProcessorArchitecture __fastcall GetProcessorArchitecture();
extern DELPHI_PACKAGE bool __fastcall IsWindows64();
extern DELPHI_PACKAGE bool __fastcall JclCheckWinVersion(int Major, int Minor);
extern DELPHI_PACKAGE __int64 __fastcall ReadTimeStampCounter();
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetIntelCacheDescription(const System::Byte D);
extern DELPHI_PACKAGE int __fastcall RoundFrequency(const int Frequency);
extern DELPHI_PACKAGE bool __fastcall GetCPUSpeed(TFreqInfo &CpuSpeed);
extern DELPHI_PACKAGE TOSEnabledFeatures __fastcall GetOSEnabledFeatures();
extern DELPHI_PACKAGE bool __fastcall TestFDIVInstruction();
extern DELPHI_PACKAGE void __fastcall RoundToAllocGranularity64(__int64 &Value, bool Up);
extern DELPHI_PACKAGE void __fastcall RoundToAllocGranularityPtr(void * &Value, bool Up);
extern DELPHI_PACKAGE TAPMLineStatus __fastcall GetAPMLineStatus();
extern DELPHI_PACKAGE TAPMBatteryFlag __fastcall GetAPMBatteryFlag();
extern DELPHI_PACKAGE TAPMBatteryFlags __fastcall GetAPMBatteryFlags();
extern DELPHI_PACKAGE int __fastcall GetAPMBatteryLifePercent();
extern DELPHI_PACKAGE unsigned __fastcall GetAPMBatteryLifeTime();
extern DELPHI_PACKAGE unsigned __fastcall GetAPMBatteryFullLifeTime();
extern DELPHI_PACKAGE Jclbase::TJclAddr __fastcall GetMaxAppAddress();
extern DELPHI_PACKAGE Jclbase::TJclAddr __fastcall GetMinAppAddress();
extern DELPHI_PACKAGE System::Byte __fastcall GetMemoryLoad();
extern DELPHI_PACKAGE __int64 __fastcall GetSwapFileSize();
extern DELPHI_PACKAGE System::Byte __fastcall GetSwapFileUsage();
extern DELPHI_PACKAGE __int64 __fastcall GetTotalPhysicalMemory();
extern DELPHI_PACKAGE __int64 __fastcall GetFreePhysicalMemory();
extern DELPHI_PACKAGE __int64 __fastcall GetTotalPageFileMemory();
extern DELPHI_PACKAGE __int64 __fastcall GetFreePageFileMemory();
extern DELPHI_PACKAGE __int64 __fastcall GetTotalVirtualMemory();
extern DELPHI_PACKAGE __int64 __fastcall GetFreeVirtualMemory();
extern DELPHI_PACKAGE bool __fastcall GetKeyState(const unsigned VirtualKey);
extern DELPHI_PACKAGE bool __fastcall GetNumLockKeyState();
extern DELPHI_PACKAGE bool __fastcall GetScrollLockKeyState();
extern DELPHI_PACKAGE bool __fastcall GetCapsLockKeyState();
extern DELPHI_PACKAGE bool __fastcall IsSystemResourcesMeterPresent();
extern DELPHI_PACKAGE int __fastcall GetFreeSystemResources(const TFreeSysResKind ResourceType)/* overload */;
extern DELPHI_PACKAGE TFreeSystemResources __fastcall GetFreeSystemResources()/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall GetBPP();
extern DELPHI_PACKAGE bool __fastcall ProgIDExists(const System::UnicodeString ProgID);
extern DELPHI_PACKAGE bool __fastcall IsWordInstalled();
extern DELPHI_PACKAGE bool __fastcall IsExcelInstalled();
extern DELPHI_PACKAGE bool __fastcall IsAccessInstalled();
extern DELPHI_PACKAGE bool __fastcall IsPowerPointInstalled();
extern DELPHI_PACKAGE bool __fastcall IsFrontPageInstalled();
extern DELPHI_PACKAGE bool __fastcall IsOutlookInstalled();
extern DELPHI_PACKAGE bool __fastcall IsInternetExplorerInstalled();
extern DELPHI_PACKAGE bool __fastcall IsMSProjectInstalled();
extern DELPHI_PACKAGE bool __fastcall IsOpenOfficeInstalled();
extern DELPHI_PACKAGE bool __fastcall IsLibreOfficeInstalled();
}	/* namespace Jclsysinfo */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLSYSINFO)
using namespace Jclsysinfo;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclSysInfoHPP
