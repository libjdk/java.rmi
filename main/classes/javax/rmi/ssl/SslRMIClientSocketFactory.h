#ifndef _javax_rmi_ssl_SslRMIClientSocketFactory_h_
#define _javax_rmi_ssl_SslRMIClientSocketFactory_h_
//$ class javax.rmi.ssl.SslRMIClientSocketFactory
//$ extends java.rmi.server.RMIClientSocketFactory
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <java/rmi/server/RMIClientSocketFactory.h>

namespace java {
	namespace net {
		class Socket;
	}
}
namespace javax {
	namespace net {
		class SocketFactory;
	}
}

namespace javax {
	namespace rmi {
		namespace ssl {

class $export SslRMIClientSocketFactory : public ::java::rmi::server::RMIClientSocketFactory, public ::java::io::Serializable {
	$class(SslRMIClientSocketFactory, 0, ::java::rmi::server::RMIClientSocketFactory, ::java::io::Serializable)
public:
	SslRMIClientSocketFactory();
	virtual $Object* clone() override;
	virtual void finalize() override;
	void init$();
	virtual ::java::net::Socket* createSocket($String* host, int32_t port) override;
	virtual bool equals(Object$* obj) override;
	static ::javax::net::SocketFactory* getDefaultClientSocketFactory();
	virtual int32_t hashCode() override;
	virtual $String* toString() override;
	static ::javax::net::SocketFactory* defaultSocketFactory;
	static const int64_t serialVersionUID = (int64_t)0x8CAAB4BB8185250F;
};

		} // ssl
	} // rmi
} // javax

#endif // _javax_rmi_ssl_SslRMIClientSocketFactory_h_