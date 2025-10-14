#ifndef _sun_rmi_transport_TransportConstants_h_
#define _sun_rmi_transport_TransportConstants_h_
//$ class sun.rmi.transport.TransportConstants
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace rmi {
		namespace transport {

class $export TransportConstants : public ::java::lang::Object {
	$class(TransportConstants, $NO_CLASS_INIT, ::java::lang::Object)
public:
	TransportConstants();
	void init$();
	static const int32_t Magic = 0x4A524D49;
	static const int16_t Version = 2;
	static const int8_t StreamProtocol = 75;
	static const int8_t SingleOpProtocol = 76;
	static const int8_t MultiplexProtocol = 77;
	static const int8_t ProtocolAck = 78;
	static const int8_t ProtocolNack = 79;
	static const int8_t Call = 80;
	static const int8_t Return = 81;
	static const int8_t Ping = 82;
	static const int8_t PingAck = 83;
	static const int8_t DGCAck = 84;
	static const int8_t NormalReturn = 1;
	static const int8_t ExceptionalReturn = 2;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_TransportConstants_h_