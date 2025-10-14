#ifndef _sun_rmi_transport_DGCClient$EndpointEntry$1_h_
#define _sun_rmi_transport_DGCClient$EndpointEntry$1_h_
//$ class sun.rmi.transport.DGCClient$EndpointEntry$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace transport {
			class DGCClient$EndpointEntry;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry$1 : public ::java::security::PrivilegedAction {
	$class(DGCClient$EndpointEntry$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	DGCClient$EndpointEntry$1();
	void init$(::sun::rmi::transport::DGCClient$EndpointEntry* this$0);
	virtual $Object* run() override;
	::sun::rmi::transport::DGCClient$EndpointEntry* this$0 = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCClient$EndpointEntry$1_h_