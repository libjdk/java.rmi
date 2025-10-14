#ifndef _java_rmi_server_ServerRef_h_
#define _java_rmi_server_ServerRef_h_
//$ interface java.rmi.server.ServerRef
//$ extends java.rmi.server.RemoteRef

#include <java/rmi/server/RemoteRef.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteStub;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import ServerRef : public ::java::rmi::server::RemoteRef {
	$interface(ServerRef, $NO_CLASS_INIT, ::java::rmi::server::RemoteRef)
public:
	virtual ::java::rmi::server::RemoteStub* exportObject(::java::rmi::Remote* obj, Object$* data) {return nullptr;}
	virtual $String* getClientHost() {return nullptr;}
	static const int64_t serialVersionUID = (int64_t)0xC0BF9D9F86B510DA;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_ServerRef_h_