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

LIB_API void cserialport_init(cserialport_instance_t* instance, const char* portname, int baudRate);

LIB_API void cserialport_open(cserialport_instance_t* instance);

LIB_API void cserialport_close(cserialport_instance_t* instance);

LIB_API void cserialport_write(cserialport_instance_t* instance, const void* data, int length);

LIB_API int cserialport_read(cserialport_instance_t* instance, char* data, int length);

LIB_API bool cserialport_isopen(cserialport_instance_t* instance);

LIB_API void cserialport_setsync(cserialport_instance_t* instance);

LIB_API int cserialport_getbytestoread(cserialport_instance_t* instance);

LIB_API void cserialport_setdtr(cserialport_instance_t* instance, bool isenable);

LIB_API bool cserialport_getdtr(cserialport_instance_t* instance);

LIB_API void cserialport_setrts(cserialport_instance_t* instance, bool isenable);

LIB_API bool cserialport_getrts(cserialport_instance_t* instance);

LIB_API bool cserialport_getcts(cserialport_instance_t* instance);

LIB_API bool cserialport_getdsr(cserialport_instance_t* instance);
#endif