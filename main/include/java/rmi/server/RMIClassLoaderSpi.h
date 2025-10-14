#ifndef _java_rmi_server_RMIClassLoaderSpi_h_
#define _java_rmi_server_RMIClassLoaderSpi_h_
//$ class java.rmi.server.RMIClassLoaderSpi
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import RMIClassLoaderSpi : public ::java::lang::Object {
	$class(RMIClassLoaderSpi, $NO_CLASS_INIT, ::java::lang::Object)
public:
	RMIClassLoaderSpi();
	void init$();
	virtual $String* getClassAnnotation($Class* cl) {return nullptr;}
	virtual ::java::lang::ClassLoader* getClassLoader($String* codebase) {return nullptr;}
	virtual $Class* loadClass($String* codebase, $String* name, ::java::lang::ClassLoader* defaultLoader) {return nullptr;}
	virtual $Class* loadProxyClass($String* codebase, $StringArray* interfaces, ::java::lang::ClassLoader* defaultLoader) {return nullptr;}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIClassLoaderSpi_h_