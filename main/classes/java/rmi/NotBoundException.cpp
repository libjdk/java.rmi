#include <java/rmi/NotBoundException.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {

$FieldInfo _NotBoundException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NotBoundException, serialVersionUID)},
	{}
};

$MethodInfo _NotBoundException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(NotBoundException::*)()>(&NotBoundException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(NotBoundException::*)($String*)>(&NotBoundException::init$))},
	{}
};

$ClassInfo _NotBoundException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.NotBoundException",
	"java.lang.Exception",
	nullptr,
	_NotBoundException_FieldInfo_,
	_NotBoundException_MethodInfo_
};

$Object* allocate$NotBoundException($Class* clazz) {
	return $of($alloc(NotBoundException));
}

void NotBoundException::init$() {
	$Exception::init$();
}

void NotBoundException::init$($String* s) {
	$Exception::init$(s);
}

NotBoundException::NotBoundException() {
}

NotBoundException::NotBoundException(const NotBoundException& e) : $Exception(e) {
}

void NotBoundException::throw$() {
	throw *this;
}

$Class* NotBoundException::load$($String* name, bool initialize) {
	$loadClass(NotBoundException, name, initialize, &_NotBoundException_ClassInfo_, allocate$NotBoundException);
	return class$;
}

$Class* NotBoundException::class$ = nullptr;

	} // rmi
} // java