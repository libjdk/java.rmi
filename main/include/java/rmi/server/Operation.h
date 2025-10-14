#ifndef _java_rmi_server_Operation_h_
#define _java_rmi_server_Operation_h_
//$ class java.rmi.server.Operation
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace rmi {
		namespace server {

class $import Operation : public ::java::lang::Object {
	$class(Operation, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Operation();
	void init$($String* op);
	virtual $String* getOperation();
	virtual $String* toString() override;
	$String* operation = nullptr;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_Operation_h_