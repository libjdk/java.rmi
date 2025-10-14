#ifndef _java_rmi_server_Unreferenced_h_
#define _java_rmi_server_Unreferenced_h_
//$ interface java.rmi.server.Unreferenced
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace rmi {
		namespace server {

class $export Unreferenced : public ::java::lang::Object {
	$interface(Unreferenced, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void unreferenced() {}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_Unreferenced_h_