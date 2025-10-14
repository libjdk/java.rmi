#ifndef _sun_rmi_runtime_NewThreadAction$1_h_
#define _sun_rmi_runtime_NewThreadAction$1_h_
//$ class sun.rmi.runtime.NewThreadAction$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace runtime {

class NewThreadAction$1 : public ::java::security::PrivilegedAction {
	$class(NewThreadAction$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	NewThreadAction$1();
	void init$();
	virtual $Object* run() override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_NewThreadAction$1_h_