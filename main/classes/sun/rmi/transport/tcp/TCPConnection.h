#ifndef _sun_rmi_transport_tcp_TCPConnection_h_
#define _sun_rmi_transport_tcp_TCPConnection_h_
//$ class sun.rmi.transport.tcp.TCPConnection
//$ extends sun.rmi.transport.Connection

#include <sun/rmi/transport/Connection.h>

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace java {
	namespace net {
		class Socket;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Channel;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {
				class TCPChannel;
			}
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPConnection : public ::sun::rmi::transport::Connection {
	$class(TCPConnection, $NO_CLASS_INIT, ::sun::rmi::transport::Connection)
public:
	TCPConnection();
	void init$(::sun::rmi::transport::tcp::TCPChannel* ch, ::java::net::Socket* s, ::java::io::InputStream* in, ::java::io::OutputStream* out);
	void init$(::sun::rmi::transport::tcp::TCPChannel* ch, ::java::io::InputStream* in, ::java::io::OutputStream* out);
	void init$(::sun::rmi::transport::tcp::TCPChannel* ch, ::java::net::Socket* s);
	virtual void close() override;
	virtual bool expired(int64_t time);
	virtual ::sun::rmi::transport::Channel* getChannel() override;
	virtual ::java::io::InputStream* getInputStream() override;
	virtual ::java::io::OutputStream* getOutputStream() override;
	virtual bool isDead();
	virtual bool isReusable() override;
	virtual void releaseInputStream() override;
	virtual void releaseOutputStream() override;
	virtual void setExpiration(int64_t time);
	virtual void setLastUseTime(int64_t time);
	::java::net::Socket* socket = nullptr;
	::sun::rmi::transport::Channel* channel = nullptr;
	::java::io::InputStream* in = nullptr;
	::java::io::OutputStream* out = nullptr;
	int64_t expiration = 0;
	int64_t lastuse = 0;
	int64_t roundtrip = 0;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPConnection_h_