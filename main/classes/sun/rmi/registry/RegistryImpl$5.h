#ifndef _sun_rmi_registry_RegistryImpl$5_h_
#define _sun_rmi_registry_RegistryImpl$5_h_
//$ class sun.rmi.registry.RegistryImpl$5
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$5 : public ::java::security::PrivilegedExceptionAction {
	$class(RegistryImpl$5, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RegistryImpl$5();
	void init$(int32_t val$regPort);
	virtual $Object* run() override;
	int32_t val$regPort = 0;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl$5_h_