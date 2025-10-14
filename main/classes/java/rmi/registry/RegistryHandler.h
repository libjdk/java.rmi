#ifndef _java_rmi_registry_RegistryHandler_h_
#define _java_rmi_registry_RegistryHandler_h_
//$ interface java.rmi.registry.RegistryHandler
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
		namespace registry {

class $export RegistryHandler : public ::java::lang::Object {
	$interface(RegistryHandler, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::rmi::registry::Registry* registryImpl(int32_t port) {return nullptr;}
	virtual ::java::rmi::registry::Registry* registryStub($String* host, int32_t port) {return nullptr;}
};

		} // registry
	} // rmi
} // java

#endif // _java_rmi_registry_RegistryHandler_h_