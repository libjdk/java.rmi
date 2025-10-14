#ifndef _sun_rmi_registry_RegistryImpl$1_h_
#define _sun_rmi_registry_RegistryImpl$1_h_
//$ class sun.rmi.registry.RegistryImpl$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace io {
		class ObjectInputFilter;
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
namespace sun {
	namespace rmi {
		namespace registry {
			class RegistryImpl;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$1 : public ::java::security::PrivilegedExceptionAction {
	$class(RegistryImpl$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RegistryImpl$1();
	void init$(::sun::rmi::registry::RegistryImpl* this$0, int32_t val$port, ::java::rmi::server::RMIClientSocketFactory* val$csf, ::java::rmi::server::RMIServerSocketFactory* val$ssf, ::java::io::ObjectInputFilter* val$serialFilter);
	virtual $Object* run() override;
	::sun::rmi::registry::RegistryImpl* this$0 = nullptr;
	::java::io::ObjectInputFilter* val$serialFilter = nullptr;
	::java::rmi::server::RMIServerSocketFactory* val$ssf = nullptr;
	::java::rmi::server::RMIClientSocketFactory* val$csf = nullptr;
	int32_t val$port = 0;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl$1_h_