#ifndef _sun_rmi_server_Dispatcher_h_
#define _sun_rmi_server_Dispatcher_h_
//$ interface sun.rmi.server.Dispatcher
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteCall;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $import Dispatcher : public ::java::lang::Object {
	$interface(Dispatcher, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void dispatch(::java::rmi::Remote* obj, ::java::rmi::server::RemoteCall* call) {}
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_Dispatcher_h_