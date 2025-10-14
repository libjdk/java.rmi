#ifndef _sun_rmi_registry_RegistryImpl$2_h_
#define _sun_rmi_registry_RegistryImpl$2_h_
//$ class sun.rmi.registry.RegistryImpl$2
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

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

class RegistryImpl$2 : public ::java::security::PrivilegedExceptionAction {
	$class(RegistryImpl$2, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RegistryImpl$2();
	void init$(::sun::rmi::registry::RegistryImpl* this$0, int32_t val$port);
	virtual $Object* run() override;
	::sun::rmi::registry::RegistryImpl* this$0 = nullptr;
	int32_t val$port = 0;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl$2_h_