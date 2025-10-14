#ifndef _java_rmi_server_Skeleton_h_
#define _java_rmi_server_Skeleton_h_
//$ interface java.rmi.server.Skeleton
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class Operation;
			class RemoteCall;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export Skeleton : public ::java::lang::Object {
	$interface(Skeleton, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void dispatch(::java::rmi::Remote* obj, ::java::rmi::server::RemoteCall* theCall, int32_t opnum, int64_t hash) {}
	virtual $Array<::java::rmi::server::Operation>* getOperations() {return nullptr;}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_Skeleton_h_