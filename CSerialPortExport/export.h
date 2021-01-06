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

LIB_API cserialport_instance_t* cserialport_new(const char* portname);

LIB_API void cserialport_open(cserialport_instance_t* instance);

LIB_API void cserialport_close(cserialport_instance_t* instance);

LIB_API void cserialport_write(cserialport_instance_t* instance,const void* data, int maxSize);

LIB_API void cserialport_read(cserialport_instance_t* instance, char* data, int maxSize);

LIB_API bool cserialport_isopen(cserialport_instance_t* instance);
#endif
