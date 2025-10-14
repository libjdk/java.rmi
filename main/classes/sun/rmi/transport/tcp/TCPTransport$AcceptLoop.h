#ifndef _sun_rmi_transport_tcp_TCPTransport$AcceptLoop_h_
#define _sun_rmi_transport_tcp_TCPTransport$AcceptLoop_h_
//$ class sun.rmi.transport.tcp.TCPTransport$AcceptLoop
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		class ServerSocket;
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

class TCPTransport$AcceptLoop : public ::java::lang::Runnable {
	$class(TCPTransport$AcceptLoop, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	TCPTransport$AcceptLoop();
	void init$(::sun::rmi::transport::tcp::TCPTransport* this$0, ::java::net::ServerSocket* serverSocket);
	bool continueAfterAcceptFailure($Throwable* t);
	void executeAcceptLoop();
	virtual void run() override;
	void throttleLoopOnException();
	::sun::rmi::transport::tcp::TCPTransport* this$0 = nullptr;
	::java::net::ServerSocket* serverSocket = nullptr;
	int64_t lastExceptionTime = 0;
	int32_t recentExceptionCount = 0;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPTransport$AcceptLoop_h_