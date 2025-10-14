#ifndef _sun_rmi_transport_GC$Daemon$1_h_
#define _sun_rmi_transport_GC$Daemon$1_h_
//$ class sun.rmi.transport.GC$Daemon$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace transport {

class GC$Daemon$1 : public ::java::security::PrivilegedAction {
	$class(GC$Daemon$1, 0, ::java::security::PrivilegedAction)
public:
	GC$Daemon$1();
	void init$();
	virtual $Object* run() override;
	static bool $assertionsDisabled;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_GC$Daemon$1_h_