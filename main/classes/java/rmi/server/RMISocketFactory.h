#ifndef _java_rmi_server_RMISocketFactory_h_
#define _java_rmi_server_RMISocketFactory_h_
//$ class java.rmi.server.RMISocketFactory
//$ extends java.rmi.server.RMIClientSocketFactory
//$ implements java.rmi.server.RMIServerSocketFactory

#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>

namespace java {
	namespace rmi {
		namespace server {
			class RMIFailureHandler;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export RMISocketFactory : public ::java::rmi::server::RMIClientSocketFactory, public ::java::rmi::server::RMIServerSocketFactory {
	$class(RMISocketFactory, 0, ::java::rmi::server::RMIClientSocketFactory, ::java::rmi::server::RMIServerSocketFactory)
public:
	RMISocketFactory();
	virtual $Object* clone() override;
	virtual ::java::net::ServerSocket* createServerSocket(int32_t port) override {return nullptr;}
	virtual ::java::net::Socket* createSocket($String* host, int32_t port) override {return nullptr;}
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	static ::java::rmi::server::RMISocketFactory* getDefaultSocketFactory();
	static ::java::rmi::server::RMIFailureHandler* getFailureHandler();
	static ::java::rmi::server::RMISocketFactory* getSocketFactory();
	static void setFailureHandler(::java::rmi::server::RMIFailureHandler* fh);
	static void setSocketFactory(::java::rmi::server::RMISocketFactory* fac);
	virtual $String* toString() override;
	static ::java::rmi::server::RMISocketFactory* factory;
	static ::java::rmi::server::RMISocketFactory* defaultSocketFactory;
	static ::java::rmi::server::RMIFailureHandler* handler;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMISocketFactory_h_