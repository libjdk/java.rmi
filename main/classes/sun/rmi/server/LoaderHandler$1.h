#ifndef _sun_rmi_server_LoaderHandler$1_h_
#define _sun_rmi_server_LoaderHandler$1_h_
//$ class sun.rmi.server.LoaderHandler$1
//$ extends java.security.PrivilegedAction

#include <java/lang/Array.h>
#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace java {
	namespace net {
		class URL;
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class LoaderHandler$1 : public ::java::security::PrivilegedAction {
	$class(LoaderHandler$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LoaderHandler$1();
	void init$($Array<::java::net::URL>* val$urls, ::java::lang::ClassLoader* val$parent);
	virtual $Object* run() override;
	::java::lang::ClassLoader* val$parent = nullptr;
	$Array<::java::net::URL>* val$urls = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_LoaderHandler$1_h_