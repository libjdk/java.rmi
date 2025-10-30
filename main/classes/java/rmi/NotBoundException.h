#ifndef _java_rmi_NotBoundException_h_
#define _java_rmi_NotBoundException_h_
//$ class java.rmi.NotBoundException
//$ extends java.lang.Exception

#include <java/lang/Exception.h>

namespace java {
	namespace rmi {

class $export NotBoundException : public ::java::lang::Exception {
	$class(NotBoundException, $NO_CLASS_INIT, ::java::lang::Exception)
public:
	NotBoundException();
	void init$();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0xE637F9A72D7C3AFB;
	NotBoundException(const NotBoundException& e);
	virtual void throw$() override;
	inline NotBoundException* operator ->() {
		return (NotBoundException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_NotBoundException_h_