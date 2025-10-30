#include <java/rmi/AccessException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _AccessException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AccessException, serialVersionUID)},
	{}
};

$MethodInfo _AccessException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(AccessException::*)($String*)>(&AccessException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(AccessException::*)($String*,$Exception*)>(&AccessException::init$))},
	{}
};

$ClassInfo _AccessException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.AccessException",
	"java.rmi.RemoteException",
	nullptr,
	_AccessException_FieldInfo_,
	_AccessException_MethodInfo_
};

$Object* allocate$AccessException($Class* clazz) {
	return $of($alloc(AccessException));
}

void AccessException::init$($String* s) {
	$RemoteException::init$(s);
}

void AccessException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

AccessException::AccessException() {
}

AccessException::AccessException(const AccessException& e) : $RemoteException(e) {
}

void AccessException::throw$() {
	throw *this;
}

$Class* AccessException::load$($String* name, bool initialize) {
	$loadClass(AccessException, name, initialize, &_AccessException_ClassInfo_, allocate$AccessException);
	return class$;
}

$Class* AccessException::class$ = nullptr;

	} // rmi
} // java