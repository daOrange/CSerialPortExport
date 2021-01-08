#include <iostream>
#include "export.h"
#include "CSerialPort/SerialPort.h"
#include "CSerialPort/SerialPortInfo.h"

#ifdef _WIN32
#include <windows.h>
#define imsleep(microsecond) Sleep(microsecond) // ms
#else
#include <unistd.h>
#define imsleep(microsecond) usleep(1000 * microsecond) // ms
#endif

#include <vector>


using namespace itas109;
using namespace std;

int countRead = 0;

//For Linux
//g++ CSerialPortDemoNoGui.cpp SerialPort.cpp SerialPortBase.cpp SerialPortUnixBase.cpp -lpthread -o CSerialPortDemoNoGui
//g++ CSerialPortDemoNoGui.cpp SerialPortInfo.cpp SerialPortInfoBase.cpp SerialPortInfoUnixBase.cpp SerialPort.cpp SerialPortBase.cpp SerialPortUnixBase.cpp -lpthread -o CSerialPortDemoNoGui

class mySlot : public has_slots<>
{
public:
	mySlot(CSerialPort* sp)
	{
		recLen = -1;
		p_sp = sp;
	};

	void OnSendMessage()
	{
		//read
		recLen = p_sp->readAllData(str);

		if (recLen > 0)
		{
			countRead++;

			str[recLen] = '\0';
			//std::cout << "receive data : " << str << ", receive size : " << recLen << ", receive count : " << countRead << std::endl;

			//if (countRead > 7)
			//{
			//	std::cout << "close serial port when receive count > 7" << std::endl;
			//	p_sp->close();
			//}
			//else
			//{
			//	// return receive data
			//	p_sp->writeData(str, recLen);
			//}
		}
	};

private:
	mySlot() {};

private:
	CSerialPort* p_sp;

	char str[1024];
	int recLen;
};

//int main()
//{
//	int index = -1;
//	std::string portName;
//	vector<SerialPortInfo> m_availablePortsList;
//	CSerialPort sp;
//
//	std::cout << "Version : " << sp.getVersion() << std::endl << std::endl;
//
//	mySlot receive(&sp);
//
//	m_availablePortsList = CSerialPortInfo::availablePortInfos();
//
//	std::cout << "availableFriendlyPorts : " << std::endl;
//
//	for (int i = 0; i < m_availablePortsList.size(); i++)
//	{
//		std::cout << i << " - " << m_availablePortsList[i].portName << " " << m_availablePortsList[i].description << std::endl;
//	}
//
//	if (m_availablePortsList.size() == 0)
//	{
//		std::cout << "No valid port" << std::endl;
//	}
//	else
//	{
//		std::cout << std::endl;
//
//		do
//		{
//			std::cout << "Please input index of the port(0 - " << (m_availablePortsList.size() - 1) << " ) : " << std::endl;
//
//			std::cin >> index;
//
//			if (index >= 0 && index < m_availablePortsList.size())
//			{
//				break;
//			}
//		} while (true);
//
//		portName = m_availablePortsList[index].portName;
//		std::cout << "select port name : " << portName << std::endl;
//
//		sp.init(portName);//windows:COM1 Linux:/dev/ttyS0
//
//		sp.open();
//
//		if (sp.isOpened())
//		{
//			std::cout << "open " << portName << " success" << std::endl;
//		}
//		else
//		{
//			std::cout << "open " << portName << " failed" << std::endl;
//		}
//
//		//connect for read
//		sp.readReady.connect(&receive, &mySlot::OnSendMessage);
//
//		//write
//		sp.writeData("itas109", 7);
//
//		for (;;)
//		{
//			imsleep(1);
//		}
//	}
//
//	return 0;
//}

int main()
{
	int index = -1;
	std::string portName;
	vector<SerialPortInfo> m_availablePortsList;
	cserialport_instance_t* sp;

	m_availablePortsList = CSerialPortInfo::availablePortInfos();

	std::cout << "availableFriendlyPorts : " << std::endl;

	for (int i = 0; i < m_availablePortsList.size(); i++)
	{
		std::cout << i << " - " << m_availablePortsList[i].portName << " " << m_availablePortsList[i].description << std::endl;
	}

	if (m_availablePortsList.size() == 0)
	{
		std::cout << "No valid port" << std::endl;
	}
	else
	{
		std::cout << std::endl;

		do
		{
			std::cout << "Please input index of the port(0 - " << (m_availablePortsList.size() - 1) << " ) : " << std::endl;

			std::cin >> index;

			if (index >= 0 && index < m_availablePortsList.size())
			{
				break;
			}
		} while (true);

		portName = m_availablePortsList[index].portName;
		std::cout << "select port name : " << portName << std::endl;

		sp = cserialport_new();//windows:COM1 Linux:/dev/ttyS0
		cserialport_init(sp, portName.data(), 9600, ParityNone, DataBits::DataBits8, StopBits::StopOne, 512);
		bool a = cserialport_get_isopen(sp);
		cserialport_set_sync(sp);
		cserialport_open(sp);

		if (cserialport_get_isopen(sp))
		{
			std::cout << "open " << portName << " success" << std::endl;
		}
		else
		{
			std::cout << "open " << portName << " failed" << std::endl;
		}

		//connect for read
		//sp.readReady.connect(&receive, &mySlot::OnSendMessage);

		//write
		byte data[] = { 0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01,0x55,0xff,0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01, 0xaa, 0x01 };

		cserialport_write(sp, data, 299);
		cserialport_close(sp);
		int aaaa = 0;
		//char buffer[1024];
		//while (true) {
		//	int  readcount = cserialport_read(sp, buffer, 1024);
		//	std::cout << "read " << buffer << std::endl;
		//}

		//for (;;)
		//{
		//	imsleep(1);
		//}
	}

	return 0;
}