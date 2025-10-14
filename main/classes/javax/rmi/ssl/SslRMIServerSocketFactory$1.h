#ifndef _javax_rmi_ssl_SslRMIServerSocketFactory$1_h_
#define _javax_rmi_ssl_SslRMIServerSocketFactory$1_h_
//$ class javax.rmi.ssl.SslRMIServerSocketFactory$1
//$ extends java.net.ServerSocket

#include <java/net/ServerSocket.h>

namespace java {
	namespace net {
		class Socket;
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLSocketFactory;
		}
	}
}
namespace javax {
	namespace rmi {
		namespace ssl {
			class SslRMIServerSocketFactory;
		}
	}
}

namespace javax {
	namespace rmi {
		namespace ssl {

class SslRMIServerSocketFactory$1 : public ::java::net::ServerSocket {
	$class(SslRMIServerSocketFactory$1, $NO_CLASS_INIT, ::java::net::ServerSocket)
public:
	SslRMIServerSocketFactory$1();
	void init$(::javax::rmi::ssl::SslRMIServerSocketFactory* this$0, int32_t arg0, ::javax::net::ssl::SSLSocketFactory* val$sslSocketFactory);
	virtual ::java::net::Socket* accept() override;
	::javax::rmi::ssl::SslRMIServerSocketFactory* this$0 = nullptr;
	::javax::net::ssl::SSLSocketFactory* val$sslSocketFactory = nullptr;
};

		} // ssl
	} // rmi
} // javax

#endif // _javax_rmi_ssl_SslRMIServerSocketFactory$1_h_