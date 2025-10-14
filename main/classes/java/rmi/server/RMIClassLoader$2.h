#ifndef _java_rmi_server_RMIClassLoader$2_h_
#define _java_rmi_server_RMIClassLoader$2_h_
//$ class java.rmi.server.RMIClassLoader$2
//$ extends java.rmi.server.RMIClassLoaderSpi

#include <java/lang/Array.h>
#include <java/rmi/server/RMIClassLoaderSpi.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class RMIClassLoader$2 : public ::java::rmi::server::RMIClassLoaderSpi {
	$class(RMIClassLoader$2, $NO_CLASS_INIT, ::java::rmi::server::RMIClassLoaderSpi)
public:
	RMIClassLoader$2();
	void init$();
	virtual $String* getClassAnnotation($Class* cl) override;
	virtual ::java::lang::ClassLoader* getClassLoader($String* codebase) override;
	virtual $Class* loadClass($String* codebase, $String* name, ::java::lang::ClassLoader* defaultLoader) override;
	virtual $Class* loadProxyClass($String* codebase, $StringArray* interfaces, ::java::lang::ClassLoader* defaultLoader) override;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIClassLoader$2_h_