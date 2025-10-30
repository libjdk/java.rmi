#ifndef _java_rmi_server_SkeletonMismatchException_h_
#define _java_rmi_server_SkeletonMismatchException_h_
//$ class java.rmi.server.SkeletonMismatchException
//$ extends java.rmi.RemoteException

#include <java/rmi/RemoteException.h>

namespace java {
	namespace rmi {
		namespace server {

class $export SkeletonMismatchException : public ::java::rmi::RemoteException {
	$class(SkeletonMismatchException, $NO_CLASS_INIT, ::java::rmi::RemoteException)
public:
	SkeletonMismatchException();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0x94064070618C36EF;
	SkeletonMismatchException(const SkeletonMismatchException& e);
	virtual void throw$() override;
	inline SkeletonMismatchException* operator ->() {
		return (SkeletonMismatchException*)throwing$;
	}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_SkeletonMismatchException_h_