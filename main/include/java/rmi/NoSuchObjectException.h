#ifndef _java_rmi_NoSuchObjectException_h_
#define _java_rmi_NoSuchObjectException_h_
//$ class java.rmi.NoSuchObjectException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace rmi {

class $import NoSuchObjectException : public ::java::rmi::RemoteException {
	$class(NoSuchObjectException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	NoSuchObjectException();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0x5BDCD18C01045019;
	NoSuchObjectException(const NoSuchObjectException& e);
	virtual void throw$() override;
	inline NoSuchObjectException* operator ->() {
		return (NoSuchObjectException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_NoSuchObjectException_h_