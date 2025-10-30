#ifndef _java_rmi_server_ExportException_h_
#define _java_rmi_server_ExportException_h_
//$ class java.rmi.server.ExportException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import ExportException : public ::java::rmi::RemoteException {
	$class(ExportException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	ExportException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x80F12E97ACC3B976;
	ExportException(const ExportException& e);
	virtual void throw$() override;
	inline ExportException* operator ->() {
		return (ExportException*)throwing$;
	}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_ExportException_h_