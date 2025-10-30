#ifndef _java_rmi_RMISecurityException_h_
#define _java_rmi_RMISecurityException_h_
//$ class java.rmi.RMISecurityException
//$ extends java.lang.SecurityException

#include <java/lang/SecurityException.h>

namespace java {
	namespace rmi {

class $import RMISecurityException : public ::java::lang::SecurityException {
	$class(RMISecurityException, $NO_CLASS_INIT, ::java::lang::SecurityException)
public:
	RMISecurityException();
	void init$($String* name);
	void init$($String* name, $String* arg);
	static const int64_t serialVersionUID = (int64_t)0x8AF685DB30DED396;
	RMISecurityException(const RMISecurityException& e);
	virtual void throw$() override;
	inline RMISecurityException* operator ->() {
		return (RMISecurityException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_RMISecurityException_h_