#ifndef _sun_rmi_runtime_RuntimeUtil$GetInstanceAction_h_
#define _sun_rmi_runtime_RuntimeUtil$GetInstanceAction_h_
//$ class sun.rmi.runtime.RuntimeUtil$GetInstanceAction
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace runtime {

class RuntimeUtil$GetInstanceAction : public ::java::security::PrivilegedAction {
	$class(RuntimeUtil$GetInstanceAction, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RuntimeUtil$GetInstanceAction();
	void init$();
	virtual $Object* run() override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_RuntimeUtil$GetInstanceAction_h_