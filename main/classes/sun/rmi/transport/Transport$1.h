#ifndef _sun_rmi_transport_Transport$1_h_
#define _sun_rmi_transport_Transport$1_h_
//$ class sun.rmi.transport.Transport$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteCall;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class Dispatcher;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Transport;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class Transport$1 : public ::java::security::PrivilegedExceptionAction {
	$class(Transport$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	Transport$1();
	void init$(::sun::rmi::transport::Transport* this$0, ::java::security::AccessControlContext* val$acc, ::sun::rmi::server::Dispatcher* val$disp, ::java::rmi::Remote* val$impl, ::java::rmi::server::RemoteCall* val$call);
	virtual $Object* run() override;
	::sun::rmi::transport::Transport* this$0 = nullptr;
	::java::rmi::server::RemoteCall* val$call = nullptr;
	::java::rmi::Remote* val$impl = nullptr;
	::sun::rmi::server::Dispatcher* val$disp = nullptr;
	::java::security::AccessControlContext* val$acc = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_Transport$1_h_