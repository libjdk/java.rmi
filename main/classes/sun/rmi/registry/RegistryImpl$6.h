#ifndef _sun_rmi_registry_RegistryImpl$6_h_
#define _sun_rmi_registry_RegistryImpl$6_h_
//$ class sun.rmi.registry.RegistryImpl$6
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$6 : public ::java::security::PrivilegedAction {
	$class(RegistryImpl$6, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RegistryImpl$6();
	void init$();
	virtual $Object* run() override;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl$6_h_