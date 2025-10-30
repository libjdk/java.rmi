#include <java/rmi/ConnectIOException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _ConnectIOException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConnectIOException, serialVersionUID)},
	{}
};

$MethodInfo _ConnectIOException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectIOException::*)($String*)>(&ConnectIOException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectIOException::*)($String*,$Exception*)>(&ConnectIOException::init$))},
	{}
};

$ClassInfo _ConnectIOException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.ConnectIOException",
	"java.rmi.RemoteException",
	nullptr,
	_ConnectIOException_FieldInfo_,
	_ConnectIOException_MethodInfo_
};

$Object* allocate$ConnectIOException($Class* clazz) {
	return $of($alloc(ConnectIOException));
}

void ConnectIOException::init$($String* s) {
	$RemoteException::init$(s);
}

void ConnectIOException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

ConnectIOException::ConnectIOException() {
}

ConnectIOException::ConnectIOException(const ConnectIOException& e) : $RemoteException(e) {
}

void ConnectIOException::throw$() {
	throw *this;
}

$Class* ConnectIOException::load$($String* name, bool initialize) {
	$loadClass(ConnectIOException, name, initialize, &_ConnectIOException_ClassInfo_, allocate$ConnectIOException);
	return class$;
}

$Class* ConnectIOException::class$ = nullptr;

	} // rmi
} // java