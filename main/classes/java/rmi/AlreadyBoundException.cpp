#include <java/rmi/AlreadyBoundException.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {

$FieldInfo _AlreadyBoundException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AlreadyBoundException, serialVersionUID)},
	{}
};

$MethodInfo _AlreadyBoundException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(AlreadyBoundException::*)()>(&AlreadyBoundException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(AlreadyBoundException::*)($String*)>(&AlreadyBoundException::init$))},
	{}
};

$ClassInfo _AlreadyBoundException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.AlreadyBoundException",
	"java.lang.Exception",
	nullptr,
	_AlreadyBoundException_FieldInfo_,
	_AlreadyBoundException_MethodInfo_
};

$Object* allocate$AlreadyBoundException($Class* clazz) {
	return $of($alloc(AlreadyBoundException));
}

void AlreadyBoundException::init$() {
	$Exception::init$();
}

void AlreadyBoundException::init$($String* s) {
	$Exception::init$(s);
}

AlreadyBoundException::AlreadyBoundException() {
}

AlreadyBoundException::AlreadyBoundException(const AlreadyBoundException& e) : $Exception(e) {
}

void AlreadyBoundException::throw$() {
	throw *this;
}

$Class* AlreadyBoundException::load$($String* name, bool initialize) {
	$loadClass(AlreadyBoundException, name, initialize, &_AlreadyBoundException_ClassInfo_, allocate$AlreadyBoundException);
	return class$;
}

$Class* AlreadyBoundException::class$ = nullptr;

	} // rmi
} // java