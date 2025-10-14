#ifndef _sun_rmi_server_UnicastServerRef$HashToMethod_Maps_h_
#define _sun_rmi_server_UnicastServerRef$HashToMethod_Maps_h_
//$ class sun.rmi.server.UnicastServerRef$HashToMethod_Maps
//$ extends sun.rmi.server.WeakClassHashMap

#include <sun/rmi/server/WeakClassHashMap.h>

namespace sun {
	namespace rmi {
		namespace server {

class UnicastServerRef$HashToMethod_Maps : public ::sun::rmi::server::WeakClassHashMap {
	$class(UnicastServerRef$HashToMethod_Maps, $NO_CLASS_INIT, ::sun::rmi::server::WeakClassHashMap)
public:
	UnicastServerRef$HashToMethod_Maps();
	void init$();
	virtual $Object* computeValue($Class* remoteClass) override;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_UnicastServerRef$HashToMethod_Maps_h_