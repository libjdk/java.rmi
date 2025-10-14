#ifndef _javax_rmi_ssl_SslRMIServerSocketFactory_h_
#define _javax_rmi_ssl_SslRMIServerSocketFactory_h_
//$ class javax.rmi.ssl.SslRMIServerSocketFactory
//$ extends java.rmi.server.RMIServerSocketFactory

#include <java/lang/Array.h>
#include <java/rmi/server/RMIServerSocketFactory.h>

namespace java {
	namespace net {
		class ServerSocket;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLContext;
			class SSLSocketFactory;
		}
	}
}

namespace javax {
	namespace rmi {
		namespace ssl {

class $export SslRMIServerSocketFactory : public ::java::rmi::server::RMIServerSocketFactory {
	$class(SslRMIServerSocketFactory, 0, ::java::rmi::server::RMIServerSocketFactory)
public:
	SslRMIServerSocketFactory();
	void init$();
	void init$($StringArray* enabledCipherSuites, $StringArray* enabledProtocols, bool needClientAuth);
	void init$(::javax::net::ssl::SSLContext* context, $StringArray* enabledCipherSuites, $StringArray* enabledProtocols, bool needClientAuth);
	bool checkParameters(::javax::rmi::ssl::SslRMIServerSocketFactory* that);
	virtual ::java::net::ServerSocket* createServerSocket(int32_t port) override;
	virtual bool equals(Object$* obj) override;
	static ::javax::net::ssl::SSLSocketFactory* getDefaultSSLSocketFactory();
	$StringArray* getEnabledCipherSuites();
	$StringArray* getEnabledProtocols();
	bool getNeedClientAuth();
	virtual int32_t hashCode() override;
	static ::javax::net::ssl::SSLSocketFactory* defaultSSLSocketFactory;
	$StringArray* enabledCipherSuites = nullptr;
	$StringArray* enabledProtocols = nullptr;
	bool needClientAuth = false;
	::java::util::List* enabledCipherSuitesList = nullptr;
	::java::util::List* enabledProtocolsList = nullptr;
	::javax::net::ssl::SSLContext* context = nullptr;
};

		} // ssl
	} // rmi
} // javax

#endif // _javax_rmi_ssl_SslRMIServerSocketFactory_h_