#include "export.h"

cserialport_instance_t* cserialport_new(const char* portname) {
	cserialport_instance_t* instance = new cserialport_instance_t();
	instance->sp = new CSerialPort();
	instance->sp->init(portname);
	return instance;
}

void cserialport_open(cserialport_instance_t* instance) {
	instance->sp->open();
}

void cserialport_close(cserialport_instance_t* instance) {
	instance->sp->close();
}

void cserialport_write(cserialport_instance_t* instance, const void* data, int maxSize) {
	instance->sp->writeData((const char*)data, maxSize);
}

void cserialport_read(cserialport_instance_t* instance, char* data, int maxSize) {
	instance->sp->readData(data, maxSize);
}

bool cserialport_isopen(cserialport_instance_t* instance) {
	return	instance->sp->isOpened();
}