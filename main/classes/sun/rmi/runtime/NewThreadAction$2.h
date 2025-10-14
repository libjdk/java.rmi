#ifndef _sun_rmi_runtime_NewThreadAction$2_h_
#define _sun_rmi_runtime_NewThreadAction$2_h_
//$ class sun.rmi.runtime.NewThreadAction$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace runtime {

class NewThreadAction$2 : public ::java::security::PrivilegedAction {
	$class(NewThreadAction$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	NewThreadAction$2();
	void init$();
	virtual $Object* run() override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_NewThreadAction$2_h_