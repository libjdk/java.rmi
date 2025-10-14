#ifndef _sun_rmi_transport_tcp_TCPDirectSocketFactory_h_
#define _sun_rmi_transport_tcp_TCPDirectSocketFactory_h_
//$ class sun.rmi.transport.tcp.TCPDirectSocketFactory
//$ extends java.rmi.server.RMISocketFactory

#include <java/rmi/server/RMISocketFactory.h>

namespace java {
	namespace net {
		class ServerSocket;
		class Socket;
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPDirectSocketFactory : public ::java::rmi::server::RMISocketFactory {
	$class(TCPDirectSocketFactory, $NO_CLASS_INIT, ::java::rmi::server::RMISocketFactory)
public:
	TCPDirectSocketFactory();
	void init$();
	virtual ::java::net::ServerSocket* createServerSocket(int32_t port) override;
	virtual ::java::net::Socket* createSocket($String* host, int32_t port) override;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPDirectSocketFactory_h_