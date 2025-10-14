#ifndef _java_rmi_server_RMIServerSocketFactory_h_
#define _java_rmi_server_RMIServerSocketFactory_h_
//$ interface java.rmi.server.RMIServerSocketFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class ServerSocket;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export RMIServerSocketFactory : public ::java::lang::Object {
	$interface(RMIServerSocketFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::net::ServerSocket* createServerSocket(int32_t port) {return nullptr;}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIServerSocketFactory_h_