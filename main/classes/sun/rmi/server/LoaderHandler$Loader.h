#ifndef _sun_rmi_server_LoaderHandler$Loader_h_
#define _sun_rmi_server_LoaderHandler$Loader_h_
//$ class sun.rmi.server.LoaderHandler$Loader
//$ extends java.net.URLClassLoader

#include <java/lang/Array.h>
#include <java/net/URLClassLoader.h>

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
	namespace security {
		class CodeSource;
		class PermissionCollection;
		class Permissions;
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class LoaderHandler$Loader : public ::java::net::URLClassLoader {
	$class(LoaderHandler$Loader, $NO_CLASS_INIT, ::java::net::URLClassLoader)
public:
	LoaderHandler$Loader();
	using ::java::net::URLClassLoader::findClass;
	using ::java::net::URLClassLoader::definePackage;
	using ::java::net::URLClassLoader::findResource;
	using ::java::net::URLClassLoader::defineClass;
	void init$($Array<::java::net::URL>* urls, ::java::lang::ClassLoader* parent);
	void checkPermissions();
	virtual $String* getClassAnnotation();
	virtual ::java::security::PermissionCollection* getPermissions(::java::security::CodeSource* codesource) override;
	using ::java::net::URLClassLoader::loadClass;
	virtual $Class* loadClass($String* name, bool resolve) override;
	virtual $String* toString() override;
	::java::lang::ClassLoader* parent = nullptr;
	$String* annotation = nullptr;
	::java::security::Permissions* permissions = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_LoaderHandler$Loader_h_