#ifndef _java_rmi_server_RMIClientSocketFactory_h_
#define _java_rmi_server_RMIClientSocketFactory_h_
//$ interface java.rmi.server.RMIClientSocketFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class Socket;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export RMIClientSocketFactory : public ::java::lang::Object {
	$interface(RMIClientSocketFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::net::Socket* createSocket($String* host, int32_t port) {return nullptr;}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIClientSocketFactory_h_