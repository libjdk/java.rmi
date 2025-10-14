#ifndef _sun_rmi_server_LoaderHandler$2_h_
#define _sun_rmi_server_LoaderHandler$2_h_
//$ class sun.rmi.server.LoaderHandler$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace sun {
	namespace rmi {
		namespace server {

class LoaderHandler$2 : public ::java::security::PrivilegedAction {
	$class(LoaderHandler$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LoaderHandler$2();
	void init$();
	virtual $Object* run() override;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_LoaderHandler$2_h_