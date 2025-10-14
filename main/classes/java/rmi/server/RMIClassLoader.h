#ifndef _java_rmi_server_RMIClassLoader_h_
#define _java_rmi_server_RMIClassLoader_h_
//$ class java.rmi.server.RMIClassLoader
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
			class RMIClassLoaderSpi;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export RMIClassLoader : public ::java::lang::Object {
	$class(RMIClassLoader, 0, ::java::lang::Object)
public:
	RMIClassLoader();
	void init$();
	static $String* getClassAnnotation($Class* cl);
	static ::java::lang::ClassLoader* getClassLoader($String* codebase);
	static ::java::rmi::server::RMIClassLoaderSpi* getDefaultProviderInstance();
	static $Object* getSecurityContext(::java::lang::ClassLoader* loader);
	static ::java::rmi::server::RMIClassLoaderSpi* initializeProvider();
	static $Class* loadClass($String* name);
	static $Class* loadClass(::java::net::URL* codebase, $String* name);
	static $Class* loadClass($String* codebase, $String* name);
	static $Class* loadClass($String* codebase, $String* name, ::java::lang::ClassLoader* defaultLoader);
	static $Class* loadProxyClass($String* codebase, $StringArray* interfaces, ::java::lang::ClassLoader* defaultLoader);
	static ::java::rmi::server::RMIClassLoaderSpi* newDefaultProviderInstance();
	static ::java::rmi::server::RMIClassLoaderSpi* defaultProvider;
	static ::java::rmi::server::RMIClassLoaderSpi* provider;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIClassLoader_h_