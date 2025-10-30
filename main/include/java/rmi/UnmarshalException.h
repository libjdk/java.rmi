#ifndef _java_rmi_UnmarshalException_h_
#define _java_rmi_UnmarshalException_h_
//$ class java.rmi.UnmarshalException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $import UnmarshalException : public ::java::rmi::RemoteException {
	$class(UnmarshalException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	UnmarshalException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x083FAA3ABFE9087A;
	UnmarshalException(const UnmarshalException& e);
	virtual void throw$() override;
	inline UnmarshalException* operator ->() {
		return (UnmarshalException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_UnmarshalException_h_