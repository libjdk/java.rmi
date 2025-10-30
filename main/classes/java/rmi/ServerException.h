#ifndef _java_rmi_ServerException_h_
#define _java_rmi_ServerException_h_
//$ class java.rmi.ServerException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $export ServerException : public ::java::rmi::RemoteException {
	$class(ServerException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	ServerException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0xBDB8C9FDC1279006;
	ServerException(const ServerException& e);
	virtual void throw$() override;
	inline ServerException* operator ->() {
		return (ServerException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_ServerException_h_