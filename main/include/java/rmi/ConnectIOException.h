#ifndef _java_rmi_ConnectIOException_h_
#define _java_rmi_ConnectIOException_h_
//$ class java.rmi.ConnectIOException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $import ConnectIOException : public ::java::rmi::RemoteException {
	$class(ConnectIOException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	ConnectIOException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x8FC25414C01EC3B8;
	ConnectIOException(const ConnectIOException& e);
	virtual void throw$() override;
	inline ConnectIOException* operator ->() {
		return (ConnectIOException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_ConnectIOException_h_