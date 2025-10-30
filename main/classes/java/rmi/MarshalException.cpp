#include <java/rmi/MarshalException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _MarshalException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MarshalException, serialVersionUID)},
	{}
};

$MethodInfo _MarshalException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(MarshalException::*)($String*)>(&MarshalException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(MarshalException::*)($String*,$Exception*)>(&MarshalException::init$))},
	{}
};

$ClassInfo _MarshalException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.MarshalException",
	"java.rmi.RemoteException",
	nullptr,
	_MarshalException_FieldInfo_,
	_MarshalException_MethodInfo_
};

$Object* allocate$MarshalException($Class* clazz) {
	return $of($alloc(MarshalException));
}

void MarshalException::init$($String* s) {
	$RemoteException::init$(s);
}

void MarshalException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

MarshalException::MarshalException() {
}

MarshalException::MarshalException(const MarshalException& e) : $RemoteException(e) {
}

void MarshalException::throw$() {
	throw *this;
}

$Class* MarshalException::load$($String* name, bool initialize) {
	$loadClass(MarshalException, name, initialize, &_MarshalException_ClassInfo_, allocate$MarshalException);
	return class$;
}

$Class* MarshalException::class$ = nullptr;

	} // rmi
} // java