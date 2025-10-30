#include <java/rmi/ConnectException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _ConnectException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConnectException, serialVersionUID)},
	{}
};

$MethodInfo _ConnectException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectException::*)($String*)>(&ConnectException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectException::*)($String*,$Exception*)>(&ConnectException::init$))},
	{}
};

$ClassInfo _ConnectException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.ConnectException",
	"java.rmi.RemoteException",
	nullptr,
	_ConnectException_FieldInfo_,
	_ConnectException_MethodInfo_
};

$Object* allocate$ConnectException($Class* clazz) {
	return $of($alloc(ConnectException));
}

void ConnectException::init$($String* s) {
	$RemoteException::init$(s);
}

void ConnectException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

ConnectException::ConnectException() {
}

ConnectException::ConnectException(const ConnectException& e) : $RemoteException(e) {
}

void ConnectException::throw$() {
	throw *this;
}

$Class* ConnectException::load$($String* name, bool initialize) {
	$loadClass(ConnectException, name, initialize, &_ConnectException_ClassInfo_, allocate$ConnectException);
	return class$;
}

$Class* ConnectException::class$ = nullptr;

	} // rmi
} // java