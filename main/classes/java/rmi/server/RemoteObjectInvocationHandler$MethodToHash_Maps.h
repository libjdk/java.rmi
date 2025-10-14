#ifndef _java_rmi_server_RemoteObjectInvocationHandler$MethodToHash_Maps_h_
#define _java_rmi_server_RemoteObjectInvocationHandler$MethodToHash_Maps_h_
//$ class java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps
//$ extends sun.rmi.server.WeakClassHashMap

#include <sun/rmi/server/WeakClassHashMap.h>

namespace java {
	namespace rmi {
		namespace server {

class RemoteObjectInvocationHandler$MethodToHash_Maps : public ::sun::rmi::server::WeakClassHashMap {
	$class(RemoteObjectInvocationHandler$MethodToHash_Maps, $NO_CLASS_INIT, ::sun::rmi::server::WeakClassHashMap)
public:
	RemoteObjectInvocationHandler$MethodToHash_Maps();
	void init$();
	virtual $Object* computeValue($Class* remoteClass) override;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteObjectInvocationHandler$MethodToHash_Maps_h_