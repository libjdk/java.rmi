#ifndef _java_rmi_registry_Registry_h_
#define _java_rmi_registry_Registry_h_
//$ interface java.rmi.registry.Registry
//$ extends java.rmi.Remote

#include <java/lang/Array.h>
#include <java/rmi/Remote.h>

#pragma push_macro("REGISTRY_PORT")
#undef REGISTRY_PORT

namespace java {
	namespace rmi {
		namespace registry {

class $export Registry : public ::java::rmi::Remote {
	$interface(Registry, $NO_CLASS_INIT, ::java::rmi::Remote)
public:
	virtual void bind($String* name, ::java::rmi::Remote* obj) {}
	virtual $StringArray* list() {return nullptr;}
	virtual ::java::rmi::Remote* lookup($String* name) {return nullptr;}
	virtual void rebind($String* name, ::java::rmi::Remote* obj) {}
	virtual void unbind($String* name) {}
	static const int32_t REGISTRY_PORT = 1099;
};

		} // registry
	} // rmi
} // java

#pragma pop_macro("REGISTRY_PORT")

#endif // _java_rmi_registry_Registry_h_