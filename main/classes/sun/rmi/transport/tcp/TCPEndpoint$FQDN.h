#ifndef _sun_rmi_transport_tcp_TCPEndpoint$FQDN_h_
#define _sun_rmi_transport_tcp_TCPEndpoint$FQDN_h_
//$ class sun.rmi.transport.tcp.TCPEndpoint$FQDN
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace java {
	namespace net {
		class InetAddress;
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPEndpoint$FQDN : public ::java::lang::Runnable {
	$class(TCPEndpoint$FQDN, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	TCPEndpoint$FQDN();
	void init$($String* hostAddress);
	static $String* attemptFQDN(::java::net::InetAddress* localAddr);
	void getFQDN();
	$String* getHost();
	virtual void run() override;
	$String* reverseLookup = nullptr;
	$String* hostAddress = nullptr;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPEndpoint$FQDN_h_