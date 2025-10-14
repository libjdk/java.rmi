#ifndef _sun_rmi_transport_tcp_ConnectionAcceptor_h_
#define _sun_rmi_transport_tcp_ConnectionAcceptor_h_
//$ class sun.rmi.transport.tcp.ConnectionAcceptor
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace java {
	namespace util {
		class List;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Connection;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {
				class TCPTransport;
			}
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class ConnectionAcceptor : public ::java::lang::Runnable {
	$class(ConnectionAcceptor, 0, ::java::lang::Runnable)
public:
	ConnectionAcceptor();
	void init$(::sun::rmi::transport::tcp::TCPTransport* transport);
	virtual void accept(::sun::rmi::transport::Connection* conn);
	virtual void run() override;
	virtual void startNewAcceptor();
	::sun::rmi::transport::tcp::TCPTransport* transport = nullptr;
	::java::util::List* queue = nullptr;
	static int32_t threadNum;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_ConnectionAcceptor_h_