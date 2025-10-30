#ifndef _java_rmi_UnknownHostException_h_
#define _java_rmi_UnknownHostException_h_
//$ class java.rmi.UnknownHostException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $import UnknownHostException : public ::java::rmi::RemoteException {
	$class(UnknownHostException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	UnknownHostException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x8EDBC1399086994C;
	UnknownHostException(const UnknownHostException& e);
	virtual void throw$() override;
	inline UnknownHostException* operator ->() {
		return (UnknownHostException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_UnknownHostException_h_