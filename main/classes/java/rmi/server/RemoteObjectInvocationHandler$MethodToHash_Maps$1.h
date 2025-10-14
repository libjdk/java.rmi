#ifndef _java_rmi_server_RemoteObjectInvocationHandler$MethodToHash_Maps$1_h_
#define _java_rmi_server_RemoteObjectInvocationHandler$MethodToHash_Maps$1_h_
//$ class java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps$1
//$ extends java.util.WeakHashMap

#include <java/util/WeakHashMap.h>

namespace java {
	namespace rmi {
		namespace server {
			class RemoteObjectInvocationHandler$MethodToHash_Maps;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class RemoteObjectInvocationHandler$MethodToHash_Maps$1 : public ::java::util::WeakHashMap {
	$class(RemoteObjectInvocationHandler$MethodToHash_Maps$1, $NO_CLASS_INIT, ::java::util::WeakHashMap)
public:
	RemoteObjectInvocationHandler$MethodToHash_Maps$1();
	void init$(::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps* this$0);
	virtual $Object* get(Object$* key) override;
	using ::java::util::WeakHashMap::remove;
	::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps* this$0 = nullptr;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteObjectInvocationHandler$MethodToHash_Maps$1_h_