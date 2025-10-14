#ifndef _java_rmi_server_RMIFailureHandler_h_
#define _java_rmi_server_RMIFailureHandler_h_
//$ interface java.rmi.server.RMIFailureHandler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import RMIFailureHandler : public ::java::lang::Object {
	$interface(RMIFailureHandler, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual bool failure(::java::lang::Exception* ex) {return false;}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RMIFailureHandler_h_