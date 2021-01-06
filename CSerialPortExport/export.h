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

LIB_API cserialport_instance_t* cserialport_new(const char*);

LIB_API void cserialport_open(cserialport_instance_t*);

LIB_API void cserialport_close(cserialport_instance_t*);

LIB_API void cserialport_write(cserialport_instance_t*, const void*, int);

LIB_API int cserialport_read(cserialport_instance_t*, char*, int);

LIB_API bool cserialport_isopen(cserialport_instance_t*);

LIB_API void cserialport_setsync(cserialport_instance_t*);

#endif