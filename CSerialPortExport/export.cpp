#include "export.h"

cserialport_instance_t* cserialport_new() {
	cserialport_instance_t* instance = new cserialport_instance_t();
	instance->sp = new CSerialPort();
	return instance;
}

void cserialport_init(cserialport_instance_t* instance, const char* portname, int baudRate, Parity parity, DataBits dataBits, StopBits stopbits, int64 readBufferSize) {
	instance->sp->init(portname, baudRate, parity, dataBits, stopbits, itas109::FlowNone, readBufferSize);
	instance->sp->setMinByteReadNotify(1);
	//instance->sp->setOperateMode(SynchronousOperate);
}

void cserialport_open(cserialport_instance_t* instance) {
	instance->sp->open();
}

void cserialport_close(cserialport_instance_t* instance) {
	instance->sp->close();
}

void cserialport_write(cserialport_instance_t* instance, const void* data, int length) {
	int a = instance->sp->writeData((const char*)data, length);
}

int cserialport_read(cserialport_instance_t* instance, char* data, int length) {
	return instance->sp->readData((char*)data, length);
}

bool cserialport_get_isopen(cserialport_instance_t* instance) {
	return	instance->sp->isOpened();
}

void cserialport_set_portname(cserialport_instance_t* instance, const char* portname) {
	instance->sp->setPortName(portname);
}

const char* cserialport_get_portname(cserialport_instance_t* instance) {
	return instance->sp->getPortName().data();
}

void cserialport_set_baudrate(cserialport_instance_t* instance, int baudRate) {
	instance->sp->setBaudRate(baudRate);
}

int cserialport_get_baudrate(cserialport_instance_t* instance) {
	return instance->sp->getBaudRate();
}

void cserialport_set_parity(cserialport_instance_t* instance, itas109::Parity parity) {
	instance->sp->setParity(parity);
}

itas109::Parity cserialport_get_parity(cserialport_instance_t* instance) {
	return instance->sp->getParity();
}

void cserialport_set_databits(cserialport_instance_t* instance, itas109::DataBits dataBits) {
	instance->sp->setDataBits(dataBits);
}

itas109::DataBits cserialport_get_databits(cserialport_instance_t* instance) {
	return instance->sp->getDataBits();
}

void cserialport_set_stopbits(cserialport_instance_t* instance, itas109::StopBits stopbits) {
	instance->sp->setStopBits(stopbits);
}

itas109::StopBits cserialport_get_stopbits(cserialport_instance_t* instance) {
	return instance->sp->getStopBits();
}

void cserialport_set_readbuffersize(cserialport_instance_t* instance, int64 size) {
	instance->sp->setReadBufferSize(size);
}

int64 cserialport_get_readbuffersize(cserialport_instance_t* instance) {
	return instance->sp->getReadBufferSize();
}

void cserialport_set_sync(cserialport_instance_t* instance) {
	instance->sp->setOperateMode(itas109::SynchronousOperate);
}

int cserialport_get_bytestoread(cserialport_instance_t* instance) {
	return instance->sp->getBytesToRead();
}

void cserialport_set_dtr(cserialport_instance_t* instance, bool isenable) {
	instance->sp->setDtr(isenable);
}

bool cserialport_get_dtr(cserialport_instance_t* instance) {
	return instance->sp->getDtr();
}

void cserialport_set_rts(cserialport_instance_t* instance, bool isenable) {
	instance->sp->setRts(isenable);
}

bool cserialport_get_rts(cserialport_instance_t* instance) {
	return instance->sp->getRts();
}

bool cserialport_get_cts(cserialport_instance_t* instance) {
	return instance->sp->getCts();
}

bool cserialport_get_dsr(cserialport_instance_t* instance) {
	return instance->sp->getDsr();
}