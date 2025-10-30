#ifndef _java_rmi_server_ServerNotActiveException_h_
#define _java_rmi_server_ServerNotActiveException_h_
//$ class java.rmi.server.ServerNotActiveException
//$ extends java.lang.Exception

#include <java/lang/Exception.h>

namespace java {
	namespace rmi {
		namespace server {

class $export ServerNotActiveException : public ::java::lang::Exception {
	$class(ServerNotActiveException, $NO_CLASS_INIT, ::java::lang::Exception)
public:
	ServerNotActiveException();
	void init$();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0x410EE93F71039B37;
	ServerNotActiveException(const ServerNotActiveException& e);
	virtual void throw$() override;
	inline ServerNotActiveException* operator ->() {
		return (ServerNotActiveException*)throwing$;
	}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_ServerNotActiveException_h_