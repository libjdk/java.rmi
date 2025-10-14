#ifndef _java_rmi_server_RemoteServer_h_
#define _java_rmi_server_RemoteServer_h_
//$ class java.rmi.server.RemoteServer
//$ extends java.rmi.server.RemoteObject

#include <java/rmi/server/RemoteObject.h>

namespace java {
	namespace io {
		class OutputStream;
		class PrintStream;
	}
}
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

class $import RemoteServer : public ::java::rmi::server::RemoteObject {
	$class(RemoteServer, 0, ::java::rmi::server::RemoteObject)
public:
	RemoteServer();
	void init$();
	void init$(::java::rmi::server::RemoteRef* ref);
	static $String* getClientHost();
	static ::java::io::PrintStream* getLog();
	static void setLog(::java::io::OutputStream* out);
	static const int64_t serialVersionUID = (int64_t)0xC719071268F339FB;
	static bool logNull;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteServer_h_