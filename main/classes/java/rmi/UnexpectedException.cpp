#include <java/rmi/UnexpectedException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _UnexpectedException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnexpectedException, serialVersionUID)},
	{}
};

$MethodInfo _UnexpectedException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(UnexpectedException::*)($String*)>(&UnexpectedException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(UnexpectedException::*)($String*,$Exception*)>(&UnexpectedException::init$))},
	{}
};

$ClassInfo _UnexpectedException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.UnexpectedException",
	"java.rmi.RemoteException",
	nullptr,
	_UnexpectedException_FieldInfo_,
	_UnexpectedException_MethodInfo_
};

$Object* allocate$UnexpectedException($Class* clazz) {
	return $of($alloc(UnexpectedException));
}

void UnexpectedException::init$($String* s) {
	$RemoteException::init$(s);
}

void UnexpectedException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

UnexpectedException::UnexpectedException() {
}

UnexpectedException::UnexpectedException(const UnexpectedException& e) : $RemoteException(e) {
}

void UnexpectedException::throw$() {
	throw *this;
}

$Class* UnexpectedException::load$($String* name, bool initialize) {
	$loadClass(UnexpectedException, name, initialize, &_UnexpectedException_ClassInfo_, allocate$UnexpectedException);
	return class$;
}

$Class* UnexpectedException::class$ = nullptr;

	} // rmi
} // java