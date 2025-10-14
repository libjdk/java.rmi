#include <java/rmi/ServerException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _ServerException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServerException, serialVersionUID)},
	{}
};

$MethodInfo _ServerException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ServerException::*)($String*)>(&ServerException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(ServerException::*)($String*,$Exception*)>(&ServerException::init$))},
	{}
};

$ClassInfo _ServerException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.ServerException",
	"java.rmi.RemoteException",
	nullptr,
	_ServerException_FieldInfo_,
	_ServerException_MethodInfo_
};

$Object* allocate$ServerException($Class* clazz) {
	return $of($alloc(ServerException));
}

void ServerException::init$($String* s) {
	$RemoteException::init$(s);
}

void ServerException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

ServerException::ServerException() {
}

ServerException::ServerException(const ServerException& e) {
}

ServerException ServerException::wrapper$() {
	$pendingException(this);
	return *this;
}

void ServerException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* ServerException::load$($String* name, bool initialize) {
	$loadClass(ServerException, name, initialize, &_ServerException_ClassInfo_, allocate$ServerException);
	return class$;
}

$Class* ServerException::class$ = nullptr;

	} // rmi
} // java