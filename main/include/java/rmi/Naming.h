#ifndef _java_rmi_Naming_h_
#define _java_rmi_Naming_h_
//$ class java.rmi.Naming
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace rmi {
		class Naming$ParsedNamingURL;
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace registry {
			class Registry;
		}
	}
}

namespace java {
	namespace rmi {

class $import Naming : public ::java::lang::Object {
	$class(Naming, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Naming();
	void init$();
	static void bind($String* name, ::java::rmi::Remote* obj);
	static ::java::rmi::registry::Registry* getRegistry(::java::rmi::Naming$ParsedNamingURL* parsed);
	static ::java::rmi::Naming$ParsedNamingURL* intParseURL($String* str);
	static $StringArray* list($String* name);
	static ::java::rmi::Remote* lookup($String* name);
	static ::java::rmi::Naming$ParsedNamingURL* parseURL($String* str);
	static void rebind($String* name, ::java::rmi::Remote* obj);
	static void unbind($String* name);
};

	} // rmi
} // java

#endif // _java_rmi_Naming_h_