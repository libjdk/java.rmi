#ifndef _sun_rmi_registry_RegistryImpl$4_h_
#define _sun_rmi_registry_RegistryImpl$4_h_
//$ class sun.rmi.registry.RegistryImpl$4
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace net {
		class InetAddress;
	}
}

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$4 : public ::java::security::PrivilegedExceptionAction {
	$class(RegistryImpl$4, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	RegistryImpl$4();
	void init$(::java::net::InetAddress* val$finalClientHost);
	virtual $Object* run() override;
	::java::net::InetAddress* val$finalClientHost = nullptr;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl$4_h_