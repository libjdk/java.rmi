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

class $export UnexpectedException : public ::java::rmi::RemoteException {
	$class(UnexpectedException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	UnexpectedException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* ex);
	static const int64_t serialVersionUID = (int64_t)0x18FC8BA33916AF47;
	UnexpectedException(const UnexpectedException& e);
	virtual void throw$() override;
	inline UnexpectedException* operator ->() {
		return (UnexpectedException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_UnexpectedException_h_