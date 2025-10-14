#ifndef _sun_rmi_server_LoaderHandler_h_
#define _sun_rmi_server_LoaderHandler_h_
//$ class sun.rmi.server.LoaderHandler
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class ReferenceQueue;
		}
	}
}
namespace java {
	namespace net {
		class URL;
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
		class PermissionCollection;
	}
}
namespace java {
	namespace util {
		class HashMap;
		class Map;
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class LoaderHandler$Loader;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $import LoaderHandler : public ::java::lang::Object {
	$class(LoaderHandler, 0, ::java::lang::Object)
public:
	LoaderHandler();
	void init$();
	static void addPermissionsForURLs($Array<::java::net::URL>* urls, ::java::security::PermissionCollection* perms, bool forLoader);
	static $String* getClassAnnotation($Class* cl);
	static ::java::lang::ClassLoader* getClassLoader($String* codebase);
	static $Array<::java::net::URL>* getDefaultCodebaseURLs();
	static ::java::security::AccessControlContext* getLoaderAccessControlContext($Array<::java::net::URL>* urls);
	static ::java::lang::ClassLoader* getRMIContextClassLoader();
	static $Object* getSecurityContext(::java::lang::ClassLoader* loader);
	static $String* lambda$static$0();
	static $String* lambda$static$1();
	static $Class* loadClass($String* codebase, $String* name, ::java::lang::ClassLoader* defaultLoader);
	static $Class* loadClass($Array<::java::net::URL>* urls, $String* name);
	static $Class* loadClassForName($String* name, bool initialize, ::java::lang::ClassLoader* loader);
	static $Class* loadProxyClass($String* codebase, $StringArray* interfaces, ::java::lang::ClassLoader* defaultLoader);
	static $Class* loadProxyClass($StringArray* interfaceNames, ::java::lang::ClassLoader* defaultLoader, ::java::lang::ClassLoader* codebaseLoader, bool preferCodebase);
	static $Class* loadProxyClass(::java::lang::ClassLoader* loader, $ClassArray* interfaces);
	static ::java::lang::ClassLoader* loadProxyInterfaces($StringArray* interfaces, ::java::lang::ClassLoader* loader, $ClassArray* classObjs, $booleans* nonpublic);
	static ::sun::rmi::server::LoaderHandler$Loader* lookupLoader($Array<::java::net::URL>* urls, ::java::lang::ClassLoader* parent);
	static $Array<::java::net::URL>* pathToURLs($String* path);
	static void registerCodebaseLoader(::java::lang::ClassLoader* loader);
	static $String* urlsToPath($Array<::java::net::URL>* urls);
	static int32_t logLevel;
	static ::sun::rmi::runtime::Log* loaderLog;
	static $String* codebaseProperty;
	static $Array<::java::net::URL>* codebaseURLs;
	static ::java::util::Map* codebaseLoaders;
	static ::java::util::HashMap* loaderTable;
	static ::java::lang::ref::ReferenceQueue* refQueue;
	static ::java::util::Map* pathToURLsCache;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_LoaderHandler_h_