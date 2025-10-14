#include <java/rmi/UnknownHostException.h>

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

$FieldInfo _UnknownHostException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnknownHostException, serialVersionUID)},
	{}
};

$MethodInfo _UnknownHostException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(UnknownHostException::*)($String*)>(&UnknownHostException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(UnknownHostException::*)($String*,$Exception*)>(&UnknownHostException::init$))},
	{}
};

$ClassInfo _UnknownHostException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.UnknownHostException",
	"java.rmi.RemoteException",
	nullptr,
	_UnknownHostException_FieldInfo_,
	_UnknownHostException_MethodInfo_
};

$Object* allocate$UnknownHostException($Class* clazz) {
	return $of($alloc(UnknownHostException));
}

void UnknownHostException::init$($String* s) {
	$RemoteException::init$(s);
}

void UnknownHostException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

UnknownHostException::UnknownHostException() {
}

UnknownHostException::UnknownHostException(const UnknownHostException& e) {
}

UnknownHostException UnknownHostException::wrapper$() {
	$pendingException(this);
	return *this;
}

void UnknownHostException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* UnknownHostException::load$($String* name, bool initialize) {
	$loadClass(UnknownHostException, name, initialize, &_UnknownHostException_ClassInfo_, allocate$UnknownHostException);
	return class$;
}

$Class* UnknownHostException::class$ = nullptr;

	} // rmi
} // java