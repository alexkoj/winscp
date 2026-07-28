// CodeGear C++Builder
// Copyright (c) 1995, 2026 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'JclStreams.pas' rev: 37.00 (Windows)

#ifndef JclStreamsHPP
#define JclStreamsHPP

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
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Contnrs.hpp>
#include <JclBase.hpp>

//-- user supplied -----------------------------------------------------------

namespace Jclstreams
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EJclStreamError;
class DELPHICLASS TJclStream;
class DELPHICLASS TJclHandleStream;
class DELPHICLASS TJclFileStream;
class DELPHICLASS TJclEmptyStream;
class DELPHICLASS TJclMultiplexStream;
class DELPHICLASS TJclStreamDecorator;
class DELPHICLASS TJclBufferedStream;
class DELPHICLASS TJclEventStream;
class DELPHICLASS TJclEasyStream;
class DELPHICLASS TJclScopedStream;
class DELPHICLASS TJclDelegatedStream;
class DELPHICLASS TJclSectoredStream;
class DELPHICLASS TJclSplitStream;
class DELPHICLASS TJclDynamicSplitStream;
class DELPHICLASS TJclSplitVolume;
class DELPHICLASS TJclStaticSplitStream;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION EJclStreamError : public Jclbase::EJclError
{
	typedef Jclbase::EJclError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EJclStreamError(const System::UnicodeString Msg) : Jclbase::EJclError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EJclStreamError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : Jclbase::EJclError(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EJclStreamError(System::NativeUInt Ident)/* overload */ : Jclbase::EJclError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EJclStreamError(System::PResStringRec ResStringRec)/* overload */ : Jclbase::EJclError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclStreamError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EJclStreamError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EJclStreamError(const System::UnicodeString Msg, int AHelpContext) : Jclbase::EJclError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EJclStreamError(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : Jclbase::EJclError(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclStreamError(System::NativeUInt Ident, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EJclStreamError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStreamError(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EJclStreamError(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : Jclbase::EJclError(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EJclStreamError() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclStream : public System::Classes::TStream
{
	typedef System::Classes::TStream inherited;
	
protected:
	virtual void __fastcall SetSize(System::LongInt NewSize)/* overload */;
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	virtual System::LongInt __fastcall Seek(System::LongInt Offset, System::Word Origin)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Source, System::LongInt BufferSize = 0x1000);
	virtual void __fastcall LoadFromFile(const System::Sysutils::TFileName FileName, System::LongInt BufferSize = 0x1000);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Dest, System::LongInt BufferSize = 0x1000);
	virtual void __fastcall SaveToFile(const System::Sysutils::TFileName FileName, System::LongInt BufferSize = 0x1000);
public:
	/* TObject.Create */ inline __fastcall TJclStream() : System::Classes::TStream() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJclStream() { }
	
	/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclHandleStream : public TJclStream
{
	typedef TJclStream inherited;
	
private:
	Winapi::Windows::THandle FHandle;
	
protected:
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclHandleStream(Winapi::Windows::THandle AHandle);
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	__property Winapi::Windows::THandle Handle = {read=FHandle, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclHandleStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclFileStream : public TJclHandleStream
{
	typedef TJclHandleStream inherited;
	
public:
	__fastcall TJclFileStream(const System::Sysutils::TFileName FileName, System::Word Mode, unsigned Rights);
	__fastcall virtual ~TJclFileStream();
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclEmptyStream : public TJclStream
{
	typedef TJclStream inherited;
	
protected:
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
public:
	/* TObject.Create */ inline __fastcall TJclEmptyStream() : TJclStream() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJclEmptyStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TJclMultiplexStream : public TJclStream
{
	typedef TJclStream inherited;
	
private:
	System::Classes::TList* FStreams;
	int FReadStreamIndex;
	System::Classes::TStream* __fastcall GetStream(int Index);
	int __fastcall GetCount();
	void __fastcall SetStream(int Index, System::Classes::TStream* const Value);
	System::Classes::TStream* __fastcall GetReadStream();
	void __fastcall SetReadStream(System::Classes::TStream* const Value);
	void __fastcall SetReadStreamIndex(const int Value);
	
protected:
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclMultiplexStream();
	__fastcall virtual ~TJclMultiplexStream();
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	int __fastcall Add(System::Classes::TStream* NewStream);
	void __fastcall Clear();
	int __fastcall Remove(System::Classes::TStream* AStream);
	void __fastcall Delete(const int Index);
	__property System::Classes::TStream* Streams[int Index] = {read=GetStream, write=SetStream};
	__property int ReadStreamIndex = {read=FReadStreamIndex, write=SetReadStreamIndex, nodefault};
	__property System::Classes::TStream* ReadStream = {read=GetReadStream, write=SetReadStream};
	__property int Count = {read=GetCount, nodefault};
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TJclStreamDecorator : public TJclStream
{
	typedef TJclStream inherited;
	
private:
	System::Classes::TNotifyEvent FAfterStreamChange;
	System::Classes::TNotifyEvent FBeforeStreamChange;
	bool FOwnsStream;
	System::Classes::TStream* FStream;
	void __fastcall SetStream(System::Classes::TStream* Value);
	
protected:
	virtual void __fastcall DoAfterStreamChange();
	virtual void __fastcall DoBeforeStreamChange();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclStreamDecorator(System::Classes::TStream* AStream, bool AOwnsStream);
	__fastcall virtual ~TJclStreamDecorator();
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	__property System::Classes::TNotifyEvent AfterStreamChange = {read=FAfterStreamChange, write=FAfterStreamChange};
	__property System::Classes::TNotifyEvent BeforeStreamChange = {read=FBeforeStreamChange, write=FBeforeStreamChange};
	__property bool OwnsStream = {read=FOwnsStream, write=FOwnsStream, nodefault};
	__property System::Classes::TStream* Stream = {read=FStream, write=SetStream};
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};


class PASCALIMPLEMENTATION TJclBufferedStream : public TJclStreamDecorator
{
	typedef TJclStreamDecorator inherited;
	
	
private:
	typedef System::DynamicArray<System::Byte> _TJclBufferedStream__1;
	
	
protected:
	_TJclBufferedStream__1 FBuffer;
	System::LongInt FBufferCurrentSize;
	System::LongInt FBufferMaxModifiedPos;
	System::LongInt FBufferSize;
	__int64 FBufferStart;
	__int64 FPosition;
	bool __fastcall BufferHit();
	virtual __int64 __fastcall GetCalcedSize();
	virtual bool __fastcall LoadBuffer();
	System::LongInt __fastcall ReadFromBuffer(void *Buffer, System::LongInt Count, System::LongInt Start);
	System::LongInt __fastcall WriteToBuffer(const void *Buffer, System::LongInt Count, System::LongInt Start);
	virtual void __fastcall DoAfterStreamChange();
	virtual void __fastcall DoBeforeStreamChange();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclBufferedStream(System::Classes::TStream* AStream, bool AOwnsStream);
	__fastcall virtual ~TJclBufferedStream();
	virtual void __fastcall Flush();
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	__property System::LongInt BufferSize = {read=FBufferSize, write=FBufferSize, nodefault};
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};


typedef void __fastcall (__closure *TStreamNotifyEvent)(System::TObject* Sender, __int64 Position, __int64 Size);

class PASCALIMPLEMENTATION TJclEventStream : public TJclStreamDecorator
{
	typedef TJclStreamDecorator inherited;
	
private:
	TStreamNotifyEvent FNotification;
	void __fastcall DoNotification();
	
protected:
	virtual void __fastcall DoBeforeStreamChange();
	virtual void __fastcall DoAfterStreamChange();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclEventStream(System::Classes::TStream* AStream, TStreamNotifyEvent ANotification, bool AOwnsStream);
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	__property TStreamNotifyEvent OnNotification = {read=FNotification, write=FNotification};
public:
	/* TJclStreamDecorator.Destroy */ inline __fastcall virtual ~TJclEventStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};


class PASCALIMPLEMENTATION TJclEasyStream : public TJclStreamDecorator
{
	typedef TJclStreamDecorator inherited;
	
public:
	bool __fastcall IsEqual(System::Classes::TStream* Stream);
	bool __fastcall ReadBoolean();
	System::WideChar __fastcall ReadChar();
	char __fastcall ReadAnsiChar();
	System::WideChar __fastcall ReadWideChar();
	System::Byte __fastcall ReadByte();
	System::Currency __fastcall ReadCurrency();
	System::TDateTime __fastcall ReadDateTime();
	System::Extended __fastcall ReadExtended();
	double __fastcall ReadDouble();
	__int64 __fastcall ReadInt64();
	int __fastcall ReadInteger();
	System::UnicodeString __fastcall ReadCString();
	System::AnsiString __fastcall ReadCAnsiString();
	System::WideString __fastcall ReadCWideString();
	System::UnicodeString __fastcall ReadShortString();
	float __fastcall ReadSingle();
	System::UnicodeString __fastcall ReadSizedString();
	System::AnsiString __fastcall ReadSizedAnsiString();
	System::WideString __fastcall ReadSizedWideString();
	void __fastcall WriteBoolean(bool Value);
	void __fastcall WriteChar(System::WideChar Value);
	void __fastcall WriteAnsiChar(char Value);
	void __fastcall WriteWideChar(System::WideChar Value);
	void __fastcall WriteByte(System::Byte Value);
	void __fastcall WriteCurrency(const System::Currency Value);
	void __fastcall WriteDateTime(const System::TDateTime Value);
	void __fastcall WriteExtended(const System::Extended Value);
	void __fastcall WriteDouble(const double Value);
	void __fastcall WriteInt64(__int64 Value)/* overload */;
	void __fastcall WriteInteger(int Value)/* overload */;
	void __fastcall WriteCString(const System::UnicodeString Value);
	void __fastcall WriteCAnsiString(const System::AnsiString Value);
	void __fastcall WriteCWideString(const System::WideString Value);
	void __fastcall WriteShortString(const System::ShortString &Value);
	void __fastcall WriteSingle(const float Value);
	void __fastcall WriteSizedString(const System::UnicodeString Value);
	void __fastcall WriteSizedAnsiString(const System::AnsiString Value);
	void __fastcall WriteSizedWideString(const System::WideString Value);
public:
	/* TJclStreamDecorator.Create */ inline __fastcall TJclEasyStream(System::Classes::TStream* AStream, bool AOwnsStream) : TJclStreamDecorator(AStream, AOwnsStream) { }
	/* TJclStreamDecorator.Destroy */ inline __fastcall virtual ~TJclEasyStream() { }
	
};


class PASCALIMPLEMENTATION TJclScopedStream : public TJclStream
{
	typedef TJclStream inherited;
	
private:
	System::Classes::TStream* FParentStream;
	__int64 FStartPos;
	__int64 FCurrentPos;
	__int64 FMaxSize;
	
protected:
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclScopedStream(System::Classes::TStream* AParentStream, const __int64 AMaxSize)/* overload */;
	__fastcall TJclScopedStream(System::Classes::TStream* AParentStream, const __int64 AStartPos, const __int64 AMaxSize)/* overload */;
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	__property System::Classes::TStream* ParentStream = {read=FParentStream};
	__property __int64 StartPos = {read=FStartPos};
	__property __int64 MaxSize = {read=FMaxSize, write=FMaxSize};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclScopedStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};


typedef __int64 __fastcall (__closure *TJclStreamSeekEvent)(System::TObject* Sender, const __int64 Offset, System::Classes::TSeekOrigin Origin);

typedef System::LongInt __fastcall (__closure *TJclStreamReadEvent)(System::TObject* Sender, void *Buffer, System::LongInt Count);

typedef System::LongInt __fastcall (__closure *TJclStreamWriteEvent)(System::TObject* Sender, const void *Buffer, System::LongInt Count);

typedef void __fastcall (__closure *TJclStreamSizeEvent)(System::TObject* Sender, const __int64 NewSize);

class PASCALIMPLEMENTATION TJclDelegatedStream : public TJclStream
{
	typedef TJclStream inherited;
	
private:
	TJclStreamSeekEvent FOnSeek;
	TJclStreamReadEvent FOnRead;
	TJclStreamWriteEvent FOnWrite;
	TJclStreamSizeEvent FOnSize;
	
protected:
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	__property TJclStreamSeekEvent OnSeek = {read=FOnSeek, write=FOnSeek};
	__property TJclStreamReadEvent OnRead = {read=FOnRead, write=FOnRead};
	__property TJclStreamWriteEvent OnWrite = {read=FOnWrite, write=FOnWrite};
	__property TJclStreamSizeEvent OnSize = {read=FOnSize, write=FOnSize};
public:
	/* TObject.Create */ inline __fastcall TJclDelegatedStream() : TJclStream() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDelegatedStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};


class PASCALIMPLEMENTATION TJclSectoredStream : public TJclBufferedStream
{
	typedef TJclBufferedStream inherited;
	
protected:
	System::LongInt FSectorOverHead;
	__int64 __fastcall FlatToSectored(const __int64 Position);
	__int64 __fastcall SectoredToFlat(const __int64 Position);
	virtual __int64 __fastcall GetCalcedSize();
	virtual bool __fastcall LoadBuffer();
	virtual void __fastcall DoAfterStreamChange();
	virtual void __fastcall AfterBlockRead();
	virtual void __fastcall BeforeBlockWrite();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall TJclSectoredStream(System::Classes::TStream* AStorageStream, bool AOwnsStream, System::LongInt ASectorOverHead);
	virtual void __fastcall Flush();
public:
	/* TJclBufferedStream.Destroy */ inline __fastcall virtual ~TJclSectoredStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
};


class PASCALIMPLEMENTATION TJclSplitStream : public TJclStream
{
	typedef TJclStream inherited;
	
private:
	System::Classes::TStream* FVolume;
	int FVolumeIndex;
	__int64 FVolumeMaxSize;
	__int64 FPosition;
	__int64 FVolumePosition;
	bool FForcePosition;
	
protected:
	virtual System::Classes::TStream* __fastcall GetVolume(int Index) = 0 ;
	virtual __int64 __fastcall GetVolumeMaxSize(int Index) = 0 ;
	virtual __int64 __fastcall GetSize();
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	bool __fastcall InternalLoadVolume(int Index);
	
public:
	__fastcall TJclSplitStream(bool AForcePosition);
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
	virtual System::LongInt __fastcall Read(void *Buffer, System::LongInt Count)/* overload */;
	virtual System::LongInt __fastcall Write(const void *Buffer, System::LongInt Count)/* overload */;
	__property bool ForcePosition = {read=FForcePosition, write=FForcePosition, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSplitStream() { }
	
	/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(System::LongInt NewSize){ TJclStream::SetSize(NewSize); }
	
public:
	inline System::LongInt __fastcall  Seek(System::LongInt Offset, System::Word Origin){ return TJclStream::Seek(Offset, Origin); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Read(System::Sysutils::TBytes &Buffer, System::LongInt Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Offset, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline System::LongInt __fastcall  Write(const System::Sysutils::TBytes Buffer, System::LongInt Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};


typedef System::Classes::TStream* __fastcall (__closure *TJclVolumeEvent)(int Index);

typedef __int64 __fastcall (__closure *TJclVolumeMaxSizeEvent)(int Index);

class PASCALIMPLEMENTATION TJclDynamicSplitStream : public TJclSplitStream
{
	typedef TJclSplitStream inherited;
	
private:
	TJclVolumeEvent FOnVolume;
	TJclVolumeMaxSizeEvent FOnVolumeMaxSize;
	
protected:
	virtual System::Classes::TStream* __fastcall GetVolume(int Index);
	virtual __int64 __fastcall GetVolumeMaxSize(int Index);
	
public:
	__property TJclVolumeEvent OnVolume = {read=FOnVolume, write=FOnVolume};
	__property TJclVolumeMaxSizeEvent OnVolumeMaxSize = {read=FOnVolumeMaxSize, write=FOnVolumeMaxSize};
public:
	/* TJclSplitStream.Create */ inline __fastcall TJclDynamicSplitStream(bool AForcePosition) : TJclSplitStream(AForcePosition) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TJclDynamicSplitStream() { }
	
};


class PASCALIMPLEMENTATION TJclSplitVolume : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__int64 MaxSize;
	System::Classes::TStream* Stream;
	bool OwnStream;
public:
	/* TObject.Create */ inline __fastcall TJclSplitVolume() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TJclSplitVolume() { }
	
};


class PASCALIMPLEMENTATION TJclStaticSplitStream : public TJclSplitStream
{
	typedef TJclSplitStream inherited;
	
private:
	System::Contnrs::TObjectList* FVolumes;
	int __fastcall GetVolumeCount();
	
protected:
	virtual System::Classes::TStream* __fastcall GetVolume(int Index);
	virtual __int64 __fastcall GetVolumeMaxSize(int Index);
	
public:
	__fastcall TJclStaticSplitStream(bool AForcePosition);
	__fastcall virtual ~TJclStaticSplitStream();
	int __fastcall AddVolume(System::Classes::TStream* AStream, __int64 AMaxSize = 0LL, bool AOwnStream = false);
	__property int VolumeCount = {read=GetVolumeCount, nodefault};
	__property System::Classes::TStream* Volumes[int Index] = {read=GetVolume};
	__property __int64 VolumeMaxSizes[int Index] = {read=GetVolumeMaxSize};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Word StreamDefaultBufferSize = System::Word(0x1000);
extern DELPHI_PACKAGE __int64 __fastcall StreamCopy(System::Classes::TStream* Source, System::Classes::TStream* Dest, System::LongInt BufferSize = 0x1000);
extern DELPHI_PACKAGE bool __fastcall CompareStreams(System::Classes::TStream* A, System::Classes::TStream* B, System::LongInt BufferSize = 0x1000);
extern DELPHI_PACKAGE bool __fastcall CompareFiles(const System::Sysutils::TFileName FileA, const System::Sysutils::TFileName FileB, System::LongInt BufferSize = 0x1000);
}	/* namespace Jclstreams */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_JCLSTREAMS)
using namespace Jclstreams;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// JclStreamsHPP
