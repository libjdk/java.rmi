#ifndef _sun_rmi_transport_tcp_TCPChannel_h_
#define _sun_rmi_transport_tcp_TCPChannel_h_
//$ class sun.rmi.transport.tcp.TCPChannel
//$ extends sun.rmi.transport.Channel

#include <sun/rmi/transport/Channel.h>

namespace java {
	namespace io {
		class DataOutputStream;
	}
}
namespace java {
	namespace lang {
		class Integer;
		class Long;
		class SecurityManager;
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class List;
		class WeakHashMap;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Future;
			class ScheduledExecutorService;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Connection;
			class Endpoint;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {
				class ConnectionAcceptor;
				class TCPEndpoint;
				class TCPTransport;
			}
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPChannel : public ::sun::rmi::transport::Channel {
	$class(TCPChannel, 0, ::sun::rmi::transport::Channel)
public:
	TCPChannel();
	void init$(::sun::rmi::transport::tcp::TCPTransport* tr, ::sun::rmi::transport::tcp::TCPEndpoint* ep);
	void checkConnectPermission();
	::sun::rmi::transport::Connection* createConnection();
	virtual void free(::sun::rmi::transport::Connection* conn, bool reuse) override;
	void freeCachedConnections();
	virtual ::sun::rmi::transport::Endpoint* getEndpoint() override;
	static ::java::lang::Long* lambda$static$0();
	static ::java::lang::Integer* lambda$static$1();
	static ::java::lang::Integer* lambda$static$2();
	virtual ::sun::rmi::transport::Connection* newConnection() override;
	virtual void shedCache();
	void writeTransportHeader(::java::io::DataOutputStream* out);
	::sun::rmi::transport::tcp::TCPEndpoint* ep = nullptr;
	::sun::rmi::transport::tcp::TCPTransport* tr = nullptr;
	::java::util::List* freeList = nullptr;
	::java::util::concurrent::Future* reaper = nullptr;
	::sun::rmi::transport::tcp::ConnectionAcceptor* acceptor = nullptr;
	::java::security::AccessControlContext* okContext = nullptr;
	::java::util::WeakHashMap* authcache = nullptr;
	::java::lang::SecurityManager* cacheSecurityManager = nullptr;
	static int64_t idleTimeout;
	static int32_t handshakeTimeout;
	static int32_t responseTimeout;
	static ::java::util::concurrent::ScheduledExecutorService* scheduler;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPChannel_h_