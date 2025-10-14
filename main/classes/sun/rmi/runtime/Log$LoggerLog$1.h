#ifndef _sun_rmi_runtime_Log$LoggerLog$1_h_
#define _sun_rmi_runtime_Log$LoggerLog$1_h_
//$ class sun.rmi.runtime.Log$LoggerLog$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$LoggerLog$1 : public ::java::security::PrivilegedAction {
	$class(Log$LoggerLog$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Log$LoggerLog$1();
	void init$();
	virtual $Object* run() override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LoggerLog$1_h_