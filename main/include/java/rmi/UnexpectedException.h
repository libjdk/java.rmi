#ifndef _java_rmi_UnexpectedException_h_
#define _java_rmi_UnexpectedException_h_
//$ class java.rmi.UnexpectedException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace rmi {

class $import UnexpectedException : public ::java::rmi::RemoteException {
	$class(UnexpectedException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	UnexpectedException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x18FC8BA33916AF47;
	UnexpectedException(const UnexpectedException& e);
	UnexpectedException wrapper$();
	virtual void throwWrapper$() override;
};

	} // rmi
} // java

#endif // _java_rmi_UnexpectedException_h_