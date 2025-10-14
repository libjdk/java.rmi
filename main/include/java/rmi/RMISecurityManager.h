#ifndef _java_rmi_RMISecurityManager_h_
#define _java_rmi_RMISecurityManager_h_
//$ class java.rmi.RMISecurityManager
//$ extends java.lang.SecurityManager

#include <java/lang/SecurityManager.h>

namespace java {
	namespace rmi {

class $import RMISecurityManager : public ::java::lang::SecurityManager {
	$class(RMISecurityManager, $NO_CLASS_INIT, ::java::lang::SecurityManager)
public:
	RMISecurityManager();
	void init$();
};

	} // rmi
} // java

#endif // _java_rmi_RMISecurityManager_h_