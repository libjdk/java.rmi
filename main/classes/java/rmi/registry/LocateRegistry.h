#ifndef _java_rmi_registry_LocateRegistry_h_
#define _java_rmi_registry_LocateRegistry_h_
//$ class java.rmi.registry.LocateRegistry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace rmi {
		namespace registry {
			class Registry;
		}
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
		}
	}
}

namespace java {
	namespace rmi {
		namespace registry {

class $export LocateRegistry : public ::java::lang::Object {
	$class(LocateRegistry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LocateRegistry();
	void init$();
	static ::java::rmi::registry::Registry* createRegistry(int32_t port);
	static ::java::rmi::registry::Registry* createRegistry(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	static ::java::rmi::registry::Registry* getRegistry();
	static ::java::rmi::registry::Registry* getRegistry(int32_t port);
	static ::java::rmi::registry::Registry* getRegistry($String* host);
	static ::java::rmi::registry::Registry* getRegistry($String* host, int32_t port);
	static ::java::rmi::registry::Registry* getRegistry($String* host, int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf);
};

		} // registry
	} // rmi
} // java

#endif // _java_rmi_registry_LocateRegistry_h_