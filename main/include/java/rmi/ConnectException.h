#ifndef _java_rmi_ConnectException_h_
#define _java_rmi_ConnectException_h_
//$ class java.rmi.ConnectException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $import ConnectException : public ::java::rmi::RemoteException {
	$class(ConnectException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	ConnectException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x437ECD31CAD3515A;
	ConnectException(const ConnectException& e);
	virtual void throw$() override;
	inline ConnectException* operator ->() {
		return (ConnectException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_ConnectException_h_