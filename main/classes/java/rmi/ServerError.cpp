#include <java/rmi/ServerError.h>

#include <java/lang/Error.h>
#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _ServerError_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServerError, serialVersionUID)},
	{}
};

$MethodInfo _ServerError_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/Error;)V", nullptr, $PUBLIC, $method(static_cast<void(ServerError::*)($String*,$Error*)>(&ServerError::init$))},
	{}
};

$ClassInfo _ServerError_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.ServerError",
	"java.rmi.RemoteException",
	nullptr,
	_ServerError_FieldInfo_,
	_ServerError_MethodInfo_
};

$Object* allocate$ServerError($Class* clazz) {
	return $of($alloc(ServerError));
}

void ServerError::init$($String* s, $Error* err) {
	$RemoteException::init$(s, err);
}

ServerError::ServerError() {
}

ServerError::ServerError(const ServerError& e) : $RemoteException(e) {
}

void ServerError::throw$() {
	throw *this;
}

$Class* ServerError::load$($String* name, bool initialize) {
	$loadClass(ServerError, name, initialize, &_ServerError_ClassInfo_, allocate$ServerError);
	return class$;
}

$Class* ServerError::class$ = nullptr;

	} // rmi
} // java