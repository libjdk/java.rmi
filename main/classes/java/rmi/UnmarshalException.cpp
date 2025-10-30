#include <java/rmi/UnmarshalException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {

$FieldInfo _UnmarshalException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnmarshalException, serialVersionUID)},
	{}
};

$MethodInfo _UnmarshalException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(UnmarshalException::*)($String*)>(&UnmarshalException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(UnmarshalException::*)($String*,$Exception*)>(&UnmarshalException::init$))},
	{}
};

$ClassInfo _UnmarshalException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.UnmarshalException",
	"java.rmi.RemoteException",
	nullptr,
	_UnmarshalException_FieldInfo_,
	_UnmarshalException_MethodInfo_
};

$Object* allocate$UnmarshalException($Class* clazz) {
	return $of($alloc(UnmarshalException));
}

void UnmarshalException::init$($String* s) {
	$RemoteException::init$(s);
}

void UnmarshalException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

UnmarshalException::UnmarshalException() {
}

UnmarshalException::UnmarshalException(const UnmarshalException& e) : $RemoteException(e) {
}

void UnmarshalException::throw$() {
	throw *this;
}

$Class* UnmarshalException::load$($String* name, bool initialize) {
	$loadClass(UnmarshalException, name, initialize, &_UnmarshalException_ClassInfo_, allocate$UnmarshalException);
	return class$;
}

$Class* UnmarshalException::class$ = nullptr;

	} // rmi
} // java