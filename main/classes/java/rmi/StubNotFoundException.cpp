#include <java/rmi/StubNotFoundException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _StubNotFoundException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StubNotFoundException, serialVersionUID)},
	{}
};

$MethodInfo _StubNotFoundException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(StubNotFoundException::*)($String*)>(&StubNotFoundException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(StubNotFoundException::*)($String*,$Exception*)>(&StubNotFoundException::init$))},
	{}
};

$ClassInfo _StubNotFoundException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.StubNotFoundException",
	"java.rmi.RemoteException",
	nullptr,
	_StubNotFoundException_FieldInfo_,
	_StubNotFoundException_MethodInfo_
};

$Object* allocate$StubNotFoundException($Class* clazz) {
	return $of($alloc(StubNotFoundException));
}

void StubNotFoundException::init$($String* s) {
	$RemoteException::init$(s);
}

void StubNotFoundException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

StubNotFoundException::StubNotFoundException() {
}

StubNotFoundException::StubNotFoundException(const StubNotFoundException& e) : $RemoteException(e) {
}

void StubNotFoundException::throw$() {
	throw *this;
}

$Class* StubNotFoundException::load$($String* name, bool initialize) {
	$loadClass(StubNotFoundException, name, initialize, &_StubNotFoundException_ClassInfo_, allocate$StubNotFoundException);
	return class$;
}

$Class* StubNotFoundException::class$ = nullptr;

	} // rmi
} // java