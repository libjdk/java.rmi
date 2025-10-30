#include <java/rmi/server/ServerCloneException.h>

#include <java/lang/CloneNotSupportedException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _ServerCloneException_FieldInfo_[] = {
	{"detail", "Ljava/lang/Exception;", nullptr, $PUBLIC, $field(ServerCloneException, detail)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServerCloneException, serialVersionUID)},
	{}
};

$MethodInfo _ServerCloneException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ServerCloneException::*)($String*)>(&ServerCloneException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(ServerCloneException::*)($String*,$Exception*)>(&ServerCloneException::init$))},
	{"getCause", "()Ljava/lang/Throwable;", nullptr, $PUBLIC},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ServerCloneException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.ServerCloneException",
	"java.lang.CloneNotSupportedException",
	nullptr,
	_ServerCloneException_FieldInfo_,
	_ServerCloneException_MethodInfo_
};

$Object* allocate$ServerCloneException($Class* clazz) {
	return $of($alloc(ServerCloneException));
}

void ServerCloneException::init$($String* s) {
	$CloneNotSupportedException::init$(s);
	initCause(nullptr);
}

void ServerCloneException::init$($String* s, $Exception* cause) {
	$CloneNotSupportedException::init$(s);
	initCause(nullptr);
	$set(this, detail, cause);
}

$String* ServerCloneException::getMessage() {
	$useLocalCurrentObjectStackCache();
	if (this->detail == nullptr) {
		return $CloneNotSupportedException::getMessage();
	} else {
		$var($String, var$0, $$str({$($CloneNotSupportedException::getMessage()), "; nested exception is: \n\t"_s}));
		return $concat(var$0, $($nc(this->detail)->toString()));
	}
}

$Throwable* ServerCloneException::getCause() {
	return this->detail;
}

ServerCloneException::ServerCloneException() {
}

ServerCloneException::ServerCloneException(const ServerCloneException& e) : $CloneNotSupportedException(e) {
}

void ServerCloneException::throw$() {
	throw *this;
}

$Class* ServerCloneException::load$($String* name, bool initialize) {
	$loadClass(ServerCloneException, name, initialize, &_ServerCloneException_ClassInfo_, allocate$ServerCloneException);
	return class$;
}

$Class* ServerCloneException::class$ = nullptr;

		} // server
	} // rmi
} // java