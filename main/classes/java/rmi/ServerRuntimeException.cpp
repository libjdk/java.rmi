#include <java/rmi/ServerRuntimeException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$CompoundAttribute _ServerRuntimeException_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _ServerRuntimeException_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ServerRuntimeException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ServerRuntimeException, serialVersionUID)},
	{}
};

$MethodInfo _ServerRuntimeException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC | $DEPRECATED, $method(static_cast<void(ServerRuntimeException::*)($String*,$Exception*)>(&ServerRuntimeException::init$)), nullptr, nullptr, _ServerRuntimeException_MethodAnnotations_init$0},
	{}
};

$ClassInfo _ServerRuntimeException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.ServerRuntimeException",
	"java.rmi.RemoteException",
	nullptr,
	_ServerRuntimeException_FieldInfo_,
	_ServerRuntimeException_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_ServerRuntimeException_Annotations_
};

$Object* allocate$ServerRuntimeException($Class* clazz) {
	return $of($alloc(ServerRuntimeException));
}

void ServerRuntimeException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

ServerRuntimeException::ServerRuntimeException() {
}

ServerRuntimeException::ServerRuntimeException(const ServerRuntimeException& e) : $RemoteException(e) {
}

void ServerRuntimeException::throw$() {
	throw *this;
}

$Class* ServerRuntimeException::load$($String* name, bool initialize) {
	$loadClass(ServerRuntimeException, name, initialize, &_ServerRuntimeException_ClassInfo_, allocate$ServerRuntimeException);
	return class$;
}

$Class* ServerRuntimeException::class$ = nullptr;

	} // rmi
} // java