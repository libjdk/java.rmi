#ifndef _java_rmi_AlreadyBoundException_h_
#define _java_rmi_AlreadyBoundException_h_
//$ class java.rmi.AlreadyBoundException
//$ extends java.lang.Exception

#include <java/lang/Exception.h>

namespace java {
	namespace rmi {

class $import AlreadyBoundException : public ::java::lang::Exception {
	$class(AlreadyBoundException, $NO_CLASS_INIT, ::java::lang::Exception)
public:
	AlreadyBoundException();
	void init$();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0x7FEF400728A6B416;
	AlreadyBoundException(const AlreadyBoundException& e);
	AlreadyBoundException wrapper$();
	virtual void throwWrapper$() override;
};

	} // rmi
} // java

#endif // _java_rmi_AlreadyBoundException_h_