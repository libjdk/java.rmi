#ifndef _sun_rmi_transport_GC$1_h_
#define _sun_rmi_transport_GC$1_h_
//$ class sun.rmi.transport.GC$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace transport {

class GC$1 : public ::java::security::PrivilegedAction {
	$class(GC$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	GC$1();
	void init$();
	virtual $Object* run() override;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_GC$1_h_