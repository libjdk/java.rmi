#ifndef _sun_rmi_transport_tcp_TCPEndpoint_h_
#define _sun_rmi_transport_tcp_TCPEndpoint_h_
//$ class sun.rmi.transport.tcp.TCPEndpoint
//$ extends sun.rmi.transport.Endpoint

#include <sun/rmi/transport/Endpoint.h>

#pragma push_macro("FORMAT_HOST_PORT")
#undef FORMAT_HOST_PORT
#pragma push_macro("FORMAT_HOST_PORT_FACTORY")
#undef FORMAT_HOST_PORT_FACTORY

namespace java {
	namespace io {
		class DataInput;
		class DataOutput;
		class ObjectInput;
		class ObjectOutput;
	}
}
namespace java {
	namespace lang {
		class Boolean;
		class Integer;
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
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
			class RMISocketFactory;
		}
	}
}
namespace java {
	namespace util {
		class Collection;
		class Map;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Channel;
			class Target;
			class Transport;
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

class TCPEndpoint : public ::sun::rmi::transport::Endpoint {
	$class(TCPEndpoint, 0, ::sun::rmi::transport::Endpoint)
public:
	TCPEndpoint();
	void init$($String* host, int32_t port);
	void init$($String* host, int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	static ::java::util::Collection* allKnownTransports();
	static ::java::rmi::server::RMISocketFactory* chooseFactory();
	virtual bool equals(Object$* obj) override;
	virtual void exportObject(::sun::rmi::transport::Target* target) override;
	static bool getBoolean($String* name);
	virtual ::sun::rmi::transport::Channel* getChannel() override;
	virtual ::java::rmi::server::RMIClientSocketFactory* getClientSocketFactory();
	virtual $String* getHost();
	static $String* getHostnameProperty();
	virtual ::sun::rmi::transport::Transport* getInboundTransport() override;
	static int32_t getInt($String* name, int32_t def);
	virtual int32_t getListenPort();
	static ::sun::rmi::transport::tcp::TCPEndpoint* getLocalEndpoint(int32_t port);
	static ::sun::rmi::transport::tcp::TCPEndpoint* getLocalEndpoint(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	virtual ::sun::rmi::transport::Transport* getOutboundTransport() override;
	virtual int32_t getPort();
	virtual ::java::rmi::server::RMIServerSocketFactory* getServerSocketFactory();
	virtual int32_t hashCode() override;
	static ::java::lang::Boolean* lambda$getBoolean$1($String* name);
	static $String* lambda$getHostnameProperty$2();
	static ::java::lang::Integer* lambda$getInt$0($String* name, int32_t def);
	virtual ::java::net::ServerSocket* newServerSocket();
	virtual ::java::net::Socket* newSocket();
	static ::sun::rmi::transport::tcp::TCPEndpoint* read(::java::io::ObjectInput* in);
	static ::sun::rmi::transport::tcp::TCPEndpoint* readHostPortFormat(::java::io::DataInput* in);
	static $String* resampleLocalHost();
	static void setDefaultPort(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	static void setLocalHost($String* host);
	static void shedConnectionCaches();
	virtual $String* toString() override;
	virtual void write(::java::io::ObjectOutput* out);
	virtual void writeHostPortFormat(::java::io::DataOutput* out);
	$String* host = nullptr;
	int32_t port = 0;
	::java::rmi::server::RMIClientSocketFactory* csf = nullptr;
	::java::rmi::server::RMIServerSocketFactory* ssf = nullptr;
	int32_t listenPort = 0;
	::sun::rmi::transport::tcp::TCPTransport* transport = nullptr;
	static $String* localHost;
	static bool localHostKnown;
	static ::java::util::Map* localEndpoints;
	static const int32_t FORMAT_HOST_PORT = 0;
	static const int32_t FORMAT_HOST_PORT_FACTORY = 1;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#pragma pop_macro("FORMAT_HOST_PORT")
#pragma pop_macro("FORMAT_HOST_PORT_FACTORY")

#endif // _sun_rmi_transport_tcp_TCPEndpoint_h_