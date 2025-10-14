#ifndef _sun_rmi_server_UnicastServerRef$HashToMethod_Maps$1_h_
#define _sun_rmi_server_UnicastServerRef$HashToMethod_Maps$1_h_
//$ class sun.rmi.server.UnicastServerRef$HashToMethod_Maps$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class UnicastServerRef$HashToMethod_Maps;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class UnicastServerRef$HashToMethod_Maps$1 : public ::java::security::PrivilegedAction {
	$class(UnicastServerRef$HashToMethod_Maps$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	UnicastServerRef$HashToMethod_Maps$1();
	void init$(::sun::rmi::server::UnicastServerRef$HashToMethod_Maps* this$0, ::java::lang::reflect::Method* val$m);
	virtual $Object* run() override;
	::sun::rmi::server::UnicastServerRef$HashToMethod_Maps* this$0 = nullptr;
	::java::lang::reflect::Method* val$m = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_UnicastServerRef$HashToMethod_Maps$1_h_