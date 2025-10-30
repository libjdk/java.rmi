#ifndef _java_rmi_RemoteException_h_
#define _java_rmi_RemoteException_h_
//$ class java.rmi.RemoteException
//$ extends java.io.IOException

#include <java/io/IOException.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}

namespace java {
	namespace rmi {

class $export RemoteException : public ::java::io::IOException {
	$class(RemoteException, $NO_CLASS_INIT, ::java::io::IOException)
public:
	RemoteException();
	void init$();
	void init$($String* s);
	void init$($String* s, $Throwable* cause);
	virtual $Throwable* getCause() override;
	virtual $String* getMessage() override;
	static const int64_t serialVersionUID = (int64_t)0xB88C9D4EDEE47A22;
	$Throwable* detail = nullptr;
	RemoteException(const RemoteException& e);
	virtual void throw$() override;
	inline RemoteException* operator ->() {
		return (RemoteException*)throwing$;
	}
};

	} // rmi
} // java

#endif // _java_rmi_RemoteException_h_