#ifndef _java_rmi_server_RemoteStub_h_
#define _java_rmi_server_RemoteStub_h_
//$ class java.rmi.server.RemoteStub
//$ extends java.rmi.server.RemoteObject

#include <java/rmi/server/RemoteObject.h>

namespace java {
	namespace rmi {
		namespace server {
			class RemoteRef;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import RemoteStub : public ::java::rmi::server::RemoteObject {
	$class(RemoteStub, $NO_CLASS_INIT, ::java::rmi::server::RemoteObject)
public:
	RemoteStub();
	void init$();
	void init$(::java::rmi::server::RemoteRef* ref);
	static void setRef(::java::rmi::server::RemoteStub* stub, ::java::rmi::server::RemoteRef* ref);
	static const int64_t serialVersionUID = (int64_t)0xE9FEDCC98BE1651A;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteStub_h_