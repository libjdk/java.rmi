#ifndef _sun_rmi_server_MarshalOutputStream$1_h_
#define _sun_rmi_server_MarshalOutputStream$1_h_
//$ class sun.rmi.server.MarshalOutputStream$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace server {
			class MarshalOutputStream;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class MarshalOutputStream$1 : public ::java::security::PrivilegedAction {
	$class(MarshalOutputStream$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	MarshalOutputStream$1();
	void init$(::sun::rmi::server::MarshalOutputStream* this$0);
	virtual $Object* run() override;
	::sun::rmi::server::MarshalOutputStream* this$0 = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_MarshalOutputStream$1_h_