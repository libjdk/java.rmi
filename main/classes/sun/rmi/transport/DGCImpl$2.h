#ifndef _sun_rmi_transport_DGCImpl$2_h_
#define _sun_rmi_transport_DGCImpl$2_h_
//$ class sun.rmi.transport.DGCImpl$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl$2 : public ::java::security::PrivilegedAction {
	$class(DGCImpl$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	DGCImpl$2();
	void init$();
	virtual $Object* run() override;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCImpl$2_h_