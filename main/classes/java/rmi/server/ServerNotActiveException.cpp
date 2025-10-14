#include <java/rmi/server/ServerNotActiveException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _ServerNotActiveException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServerNotActiveException, serialVersionUID)},
	{}
};

$MethodInfo _ServerNotActiveException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ServerNotActiveException::*)()>(&ServerNotActiveException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ServerNotActiveException::*)($String*)>(&ServerNotActiveException::init$))},
	{}
};

$ClassInfo _ServerNotActiveException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.ServerNotActiveException",
	"java.lang.Exception",
	nullptr,
	_ServerNotActiveException_FieldInfo_,
	_ServerNotActiveException_MethodInfo_
};

$Object* allocate$ServerNotActiveException($Class* clazz) {
	return $of($alloc(ServerNotActiveException));
}

void ServerNotActiveException::init$() {
	$Exception::init$();
}

void ServerNotActiveException::init$($String* s) {
	$Exception::init$(s);
}

ServerNotActiveException::ServerNotActiveException() {
}

ServerNotActiveException::ServerNotActiveException(const ServerNotActiveException& e) {
}

ServerNotActiveException ServerNotActiveException::wrapper$() {
	$pendingException(this);
	return *this;
}

void ServerNotActiveException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* ServerNotActiveException::load$($String* name, bool initialize) {
	$loadClass(ServerNotActiveException, name, initialize, &_ServerNotActiveException_ClassInfo_, allocate$ServerNotActiveException);
	return class$;
}

$Class* ServerNotActiveException::class$ = nullptr;

		} // server
	} // rmi
} // java