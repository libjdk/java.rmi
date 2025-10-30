#ifndef _java_rmi_ServerRuntimeException_h_
#define _java_rmi_ServerRuntimeException_h_
//$ class java.rmi.ServerRuntimeException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $export ServerRuntimeException : public ::java::rmi::RemoteException {
	$class(ServerRuntimeException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	ServerRuntimeException();
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x61E67E7811C08B53;
	ServerRuntimeException(const ServerRuntimeException& e);
	virtual void throw$() override;
	inline ServerRuntimeException* operator ->() {
		return (ServerRuntimeException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_ServerRuntimeException_h_