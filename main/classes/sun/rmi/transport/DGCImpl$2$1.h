#ifndef _sun_rmi_transport_DGCImpl$2$1_h_
#define _sun_rmi_transport_DGCImpl$2$1_h_
//$ class sun.rmi.transport.DGCImpl$2$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class ObjID;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class UnicastServerRef;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class DGCImpl$2;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl$2$1 : public ::java::security::PrivilegedAction {
	$class(DGCImpl$2$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	DGCImpl$2$1();
	void init$(::sun::rmi::transport::DGCImpl$2* this$0, ::sun::rmi::server::UnicastServerRef* val$disp, ::java::rmi::Remote* val$stub, ::java::rmi::server::ObjID* val$dgcID);
	virtual $Object* run() override;
	::sun::rmi::transport::DGCImpl$2* this$0 = nullptr;
	::java::rmi::server::ObjID* val$dgcID = nullptr;
	::java::rmi::Remote* val$stub = nullptr;
	::sun::rmi::server::UnicastServerRef* val$disp = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCImpl$2$1_h_