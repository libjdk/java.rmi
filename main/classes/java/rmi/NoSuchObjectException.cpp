#include <java/rmi/NoSuchObjectException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _NoSuchObjectException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NoSuchObjectException, serialVersionUID)},
	{}
};

$MethodInfo _NoSuchObjectException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(NoSuchObjectException::*)($String*)>(&NoSuchObjectException::init$))},
	{}
};

$ClassInfo _NoSuchObjectException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.NoSuchObjectException",
	"java.rmi.RemoteException",
	nullptr,
	_NoSuchObjectException_FieldInfo_,
	_NoSuchObjectException_MethodInfo_
};

$Object* allocate$NoSuchObjectException($Class* clazz) {
	return $of($alloc(NoSuchObjectException));
}

void NoSuchObjectException::init$($String* s) {
	$RemoteException::init$(s);
}

NoSuchObjectException::NoSuchObjectException() {
}

NoSuchObjectException::NoSuchObjectException(const NoSuchObjectException& e) : $RemoteException(e) {
}

void NoSuchObjectException::throw$() {
	throw *this;
}

$Class* NoSuchObjectException::load$($String* name, bool initialize) {
	$loadClass(NoSuchObjectException, name, initialize, &_NoSuchObjectException_ClassInfo_, allocate$NoSuchObjectException);
	return class$;
}

$Class* NoSuchObjectException::class$ = nullptr;

	} // rmi
} // java