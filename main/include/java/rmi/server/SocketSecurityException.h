#ifndef _java_rmi_server_SocketSecurityException_h_
#define _java_rmi_server_SocketSecurityException_h_
//$ class java.rmi.server.SocketSecurityException
//$ extends java.rmi.server.ExportException

#include <java/rmi/server/ExportException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import SocketSecurityException : public ::java::rmi::server::ExportException {
	$class(SocketSecurityException, $NO_CLASS_INIT, ::java::rmi::server::ExportException)
public:
	SocketSecurityException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x9638F4FD9233F7A5;
	SocketSecurityException(const SocketSecurityException& e);
	virtual void throw$() override;
	inline SocketSecurityException* operator ->() {
		return (SocketSecurityException*)throwing$;
	}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_SocketSecurityException_h_