#ifndef _java_rmi_server_LoaderHandler_h_
#define _java_rmi_server_LoaderHandler_h_
//$ interface java.rmi.server.LoaderHandler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace java {
	namespace net {
		class URL;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import LoaderHandler : public ::java::lang::Object {
	$interface(LoaderHandler, 0, ::java::lang::Object)
public:
	virtual $Object* getSecurityContext(::java::lang::ClassLoader* loader) {return nullptr;}
	virtual $Class* loadClass($String* name) {return nullptr;}
	virtual $Class* loadClass(::java::net::URL* codebase, $String* name) {return nullptr;}
	static $String* packagePrefix;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_LoaderHandler_h_