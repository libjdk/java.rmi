#ifndef _sun_rmi_transport_tcp_TCPTransport$ConnectionHandler_h_
#define _sun_rmi_transport_tcp_TCPTransport$ConnectionHandler_h_
//$ class sun.rmi.transport.tcp.TCPTransport$ConnectionHandler
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

#pragma push_macro("POST")
#undef POST

namespace java {
	namespace lang {
		class SecurityManager;
		class Void;
	}
}
namespace java {
	namespace net {
		class Socket;
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class Map;
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

class TCPTransport$ConnectionHandler : public ::java::lang::Runnable {
	$class(TCPTransport$ConnectionHandler, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	TCPTransport$ConnectionHandler();
	void init$(::sun::rmi::transport::tcp::TCPTransport* this$0, ::java::net::Socket* socket, $String* remoteHost);
	virtual void checkAcceptPermission(::java::lang::SecurityManager* sm, ::java::security::AccessControlContext* acc);
	virtual $String* getClientHost();
	::java::lang::Void* lambda$run$0();
	virtual void run() override;
	void run0();
	::sun::rmi::transport::tcp::TCPTransport* this$0 = nullptr;
	static const int32_t POST = 0x504F5354;
	::java::security::AccessControlContext* okContext = nullptr;
	::java::util::Map* authCache = nullptr;
	::java::lang::SecurityManager* cacheSecurityManager = nullptr;
	::java::net::Socket* socket = nullptr;
	$String* remoteHost = nullptr;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#pragma pop_macro("POST")

#endif // _sun_rmi_transport_tcp_TCPTransport$ConnectionHandler_h_