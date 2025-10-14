#ifndef _java_rmi_ServerError_h_
#define _java_rmi_ServerError_h_
//$ class java.rmi.ServerError
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Error;
	}
}

namespace java {
	namespace rmi {

class $export ServerError : public ::java::rmi::RemoteException {
	$class(ServerError, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	ServerError();
	void init$($String* s, ::java::lang::Error* err);
	static const int64_t serialVersionUID = (int64_t)0x755734D02036BFE2;
	ServerError(const ServerError& e);
	ServerError wrapper$();
	virtual void throwWrapper$() override;
};

	} // rmi
} // java

#endif // _java_rmi_ServerError_h_