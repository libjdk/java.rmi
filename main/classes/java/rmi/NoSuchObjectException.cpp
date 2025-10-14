#include <java/rmi/NoSuchObjectException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
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

NoSuchObjectException::NoSuchObjectException(const NoSuchObjectException& e) {
}

NoSuchObjectException NoSuchObjectException::wrapper$() {
	$pendingException(this);
	return *this;
}

void NoSuchObjectException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* NoSuchObjectException::load$($String* name, bool initialize) {
	$loadClass(NoSuchObjectException, name, initialize, &_NoSuchObjectException_ClassInfo_, allocate$NoSuchObjectException);
	return class$;
}

$Class* NoSuchObjectException::class$ = nullptr;

	} // rmi
} // java