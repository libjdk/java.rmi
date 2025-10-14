#ifndef _sun_rmi_registry_RegistryImpl$3_h_
#define _sun_rmi_registry_RegistryImpl$3_h_
//$ class sun.rmi.registry.RegistryImpl$3
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$3 : public ::java::security::PrivilegedExceptionAction {
	$class(RegistryImpl$3, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RegistryImpl$3();
	void init$($String* val$clientHostName);
	virtual $Object* run() override;
	$String* val$clientHostName = nullptr;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl$3_h_