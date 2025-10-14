#ifndef _java_rmi_server_RMIClassLoader$1_h_
#define _java_rmi_server_RMIClassLoader$1_h_
//$ class java.rmi.server.RMIClassLoader$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace rmi {
		namespace server {

class RMIClassLoader$1 : public ::java::security::PrivilegedAction {
	$class(RMIClassLoader$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RMIClassLoader$1();
	void init$();
	virtual $Object* run() override;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIClassLoader$1_h_