#include "export.h"

cserialport_instance_t* cserialport_new() {
	cserialport_instance_t* instance = new cserialport_instance_t();
	instance->sp = new CSerialPort();
	return instance;
}

void cserialport_init(cserialport_instance_t* instance, const char* portname, int baudRate) {
	instance->sp->init(portname, baudRate);
	instance->sp->setMinByteReadNotify(1);
}

void cserialport_open(cserialport_instance_t* instance) {
	instance->sp->open();
}

void cserialport_close(cserialport_instance_t* instance) {
	instance->sp->close();
}

void cserialport_write(cserialport_instance_t* instance, const void* data, int length) {
	instance->sp->writeData((const char*)data, length);
}

int cserialport_read(cserialport_instance_t* instance, char* data, int length) {
	return instance->sp->readData((char*)data, length);
}

bool cserialport_isopen(cserialport_instance_t* instance) {
	return	instance->sp->isOpened();
}

void cserialport_setsync(cserialport_instance_t* instance) {
	instance->sp->setOperateMode(itas109::SynchronousOperate);
}

int cserialport_getbytestoread(cserialport_instance_t* instance) {
	return instance->sp->getBytesToRead();
}

void cserialport_setdtr(cserialport_instance_t* instance, bool isenable) {
	instance->sp->setDtr(isenable);
}

bool cserialport_getdtr(cserialport_instance_t* instance) {
	return instance->sp->getDtr();
}

void cserialport_setrts(cserialport_instance_t* instance, bool isenable) {
	instance->sp->setRts(isenable);
}

bool cserialport_getrts(cserialport_instance_t* instance) {
	return instance->sp->getRts();
}

bool cserialport_getcts(cserialport_instance_t* instance) {
	return instance->sp->getCts();
}

bool cserialport_getdsr(cserialport_instance_t* instance) {
	return instance->sp->getDsr();
}