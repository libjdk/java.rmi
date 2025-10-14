#ifndef _sun_rmi_server_DeserializationChecker_h_
#define _sun_rmi_server_DeserializationChecker_h_
//$ interface sun.rmi.server.DeserializationChecker
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace io {
		class ObjectStreamClass;
	}
}
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

class $import DeserializationChecker : public ::java::lang::Object {
	$interface(DeserializationChecker, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void check(::java::lang::reflect::Method* method, ::java::io::ObjectStreamClass* descriptor, int32_t paramIndex, int32_t callID) {}
	virtual void checkProxyClass(::java::lang::reflect::Method* method, $StringArray* ifaces, int32_t paramIndex, int32_t callID) {}
	virtual void end(int32_t callID);
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_DeserializationChecker_h_