#ifndef EXPORT_H
#define EXPORT_H 1

# define LIB_API extern "C" __declspec(dllexport)

#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"

using namespace itas109;
using namespace std;

typedef struct cserialport_instance_t {
	CSerialPort* sp;
} cserialport_instance_t;

LIB_API cserialport_instance_t* cserialport_new();

LIB_API void cserialport_init(cserialport_instance_t* instance, const char* portname, int baudRate, Parity parity, DataBits dataBits, StopBits stopbits, int64 readBufferSize);

LIB_API void cserialport_open(cserialport_instance_t* instance);

LIB_API void cserialport_close(cserialport_instance_t* instance);

LIB_API void cserialport_write(cserialport_instance_t* instance, const void* data, int length);

LIB_API int cserialport_read(cserialport_instance_t* instance, char* data, int length);

LIB_API bool cserialport_get_isopen(cserialport_instance_t* instance);

LIB_API void cserialport_set_portname(cserialport_instance_t* instance, const char* portname);

LIB_API const char* cserialport_get_portname(cserialport_instance_t* instance);

LIB_API void cserialport_set_baudrate(cserialport_instance_t* instance, int baudRate);

LIB_API int cserialport_get_baudrate(cserialport_instance_t* instance);

LIB_API void cserialport_set_parity(cserialport_instance_t* instance, itas109::Parity parity);

LIB_API itas109::Parity cserialport_get_parity(cserialport_instance_t* instance);

LIB_API void cserialport_set_databits(cserialport_instance_t* instance, itas109::DataBits dataBits);

LIB_API itas109::DataBits cserialport_get_databits(cserialport_instance_t* instance);

LIB_API void cserialport_set_stopbits(cserialport_instance_t* instance, itas109::StopBits stopbits);

LIB_API itas109::StopBits cserialport_get_stopbits(cserialport_instance_t* instance);

LIB_API void cserialport_set_readbuffersize(cserialport_instance_t* instance, int64 size);

LIB_API int64 cserialport_get_readbuffersize(cserialport_instance_t* instance);

LIB_API void cserialport_set_sync(cserialport_instance_t* instance);

LIB_API int cserialport_get_bytestoread(cserialport_instance_t* instance);

LIB_API void cserialport_set_dtr(cserialport_instance_t* instance, bool isenable);

LIB_API bool cserialport_get_dtr(cserialport_instance_t* instance);

LIB_API void cserialport_set_rts(cserialport_instance_t* instance, bool isenable);

LIB_API bool cserialport_get_rts(cserialport_instance_t* instance);

LIB_API bool cserialport_get_cts(cserialport_instance_t* instance);

LIB_API bool cserialport_get_dsr(cserialport_instance_t* instance);
#endif