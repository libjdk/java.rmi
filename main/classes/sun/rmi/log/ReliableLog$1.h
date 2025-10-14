#ifndef _sun_rmi_log_ReliableLog$1_h_
#define _sun_rmi_log_ReliableLog$1_h_
//$ class sun.rmi.log.ReliableLog$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace log {

class ReliableLog$1 : public ::java::security::PrivilegedAction {
	$class(ReliableLog$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	ReliableLog$1();
	void init$();
	virtual $Object* run() override;
};

		} // log
	} // rmi
} // sun

#endif // _sun_rmi_log_ReliableLog$1_h_