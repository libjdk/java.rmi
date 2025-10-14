#ifndef _java_rmi_Naming$ParsedNamingURL_h_
#define _java_rmi_Naming$ParsedNamingURL_h_
//$ class java.rmi.Naming$ParsedNamingURL
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace rmi {

class Naming$ParsedNamingURL : public ::java::lang::Object {
	$class(Naming$ParsedNamingURL, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Naming$ParsedNamingURL();
	void init$($String* host, int32_t port, $String* name);
	$String* host = nullptr;
	int32_t port = 0;
	$String* name = nullptr;
};

	} // rmi
} // java

#endif // _java_rmi_Naming$ParsedNamingURL_h_