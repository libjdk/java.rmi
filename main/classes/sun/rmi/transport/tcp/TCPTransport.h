#ifndef _sun_rmi_transport_tcp_TCPTransport_h_
#define _sun_rmi_transport_tcp_TCPTransport_h_
//$ class sun.rmi.transport.tcp.TCPTransport
//$ extends sun.rmi.transport.Transport

#include <sun/rmi/transport/Transport.h>

#pragma push_macro("NOPERMS_ACC")
#undef NOPERMS_ACC

namespace java {
	namespace lang {
		class Integer;
		class Long;
		class ThreadLocal;
	}
}
namespace java {
	namespace net {
		class ServerSocket;
		class Socket;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RMISocketFactory;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class LinkedList;
		class Map;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ExecutorService;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicInteger;
			}
		}
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Channel;
			class Connection;
			class Endpoint;
			class Target;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {
				class TCPEndpoint;
			}
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPTransport : public ::sun::rmi::transport::Transport {
	$class(TCPTransport, 0, ::sun::rmi::transport::Transport)
public:
	TCPTransport();
	void init$(::java::util::LinkedList* epList);
	virtual void checkAcceptPermission(::java::security::AccessControlContext* acc) override;
	static void closeSocket(::java::net::Socket* sock);
	void decrementExportCount();
	virtual void exportObject(::sun::rmi::transport::Target* target) override;
	virtual void free(::sun::rmi::transport::Endpoint* ep) override;
	virtual ::sun::rmi::transport::Channel* getChannel(::sun::rmi::transport::Endpoint* ep) override;
	static $String* getClientHost();
	::sun::rmi::transport::tcp::TCPEndpoint* getEndpoint();
	virtual void handleMessages(::sun::rmi::transport::Connection* conn, bool persistent);
	static $String* lambda$static$0();
	static ::java::lang::Integer* lambda$static$1();
	static ::java::lang::Long* lambda$static$2();
	static ::java::lang::Integer* lambda$static$3();
	void listen();
	virtual void shedConnectionCaches();
	virtual void targetUnexported() override;
	static bool $assertionsDisabled;
	static ::sun::rmi::runtime::Log* tcpLog;
	static int32_t maxConnectionThreads;
	static int64_t threadKeepAliveTime;
	static ::java::util::concurrent::ExecutorService* connectionThreadPool;
	static ::java::util::concurrent::atomic::AtomicInteger* connectionCount;
	static ::java::lang::ThreadLocal* threadConnectionHandler;
	static ::java::security::AccessControlContext* NOPERMS_ACC;
	::java::util::LinkedList* epList = nullptr;
	int32_t exportCount = 0;
	::java::net::ServerSocket* server = nullptr;
	::java::util::Map* channelTable = nullptr;
	static ::java::rmi::server::RMISocketFactory* defaultSocketFactory;
	static int32_t connectionReadTimeout;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#pragma pop_macro("NOPERMS_ACC")

#endif // _sun_rmi_transport_tcp_TCPTransport_h_