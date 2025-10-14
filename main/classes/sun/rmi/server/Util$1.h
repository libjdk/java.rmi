#ifndef _sun_rmi_server_Util$1_h_
#define _sun_rmi_server_Util$1_h_
//$ class sun.rmi.server.Util$1
//$ extends java.security.PrivilegedAction

#include <java/lang/Array.h>
#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class InvocationHandler;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class Util$1 : public ::java::security::PrivilegedAction {
	$class(Util$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Util$1();
	void init$(::java::lang::ClassLoader* val$loader, $ClassArray* val$interfaces, ::java::lang::reflect::InvocationHandler* val$handler);
	virtual $Object* run() override;
	::java::lang::reflect::InvocationHandler* val$handler = nullptr;
	$ClassArray* val$interfaces = nullptr;
	::java::lang::ClassLoader* val$loader = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_Util$1_h_