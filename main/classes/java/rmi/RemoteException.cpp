#include <java/rmi/RemoteException.h>

#include <java/io/IOException.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {

$FieldInfo _RemoteException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RemoteException, serialVersionUID)},
	{"detail", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(RemoteException, detail)},
	{}
};

$MethodInfo _RemoteException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RemoteException::*)()>(&RemoteException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(RemoteException::*)($String*)>(&RemoteException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(RemoteException::*)($String*,$Throwable*)>(&RemoteException::init$))},
	{"getCause", "()Ljava/lang/Throwable;", nullptr, $PUBLIC},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _RemoteException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.RemoteException",
	"java.io.IOException",
	nullptr,
	_RemoteException_FieldInfo_,
	_RemoteException_MethodInfo_
};

$Object* allocate$RemoteException($Class* clazz) {
	return $of($alloc(RemoteException));
}

void RemoteException::init$() {
	$IOException::init$();
	initCause(nullptr);
}

void RemoteException::init$($String* s) {
	$IOException::init$(s);
	initCause(nullptr);
}

void RemoteException::init$($String* s, $Throwable* cause) {
	$IOException::init$(s);
	initCause(nullptr);
	$set(this, detail, cause);
}

$String* RemoteException::getMessage() {
	$useLocalCurrentObjectStackCache();
	if (this->detail == nullptr) {
		return $IOException::getMessage();
	} else {
		$var($String, var$0, $$str({$($IOException::getMessage()), "; nested exception is: \n\t"_s}));
		return $concat(var$0, $($nc(this->detail)->toString()));
	}
}

$Throwable* RemoteException::getCause() {
	return this->detail;
}

RemoteException::RemoteException() {
}

RemoteException::RemoteException(const RemoteException& e) : $IOException(e) {
}

void RemoteException::throw$() {
	throw *this;
}

$Class* RemoteException::load$($String* name, bool initialize) {
	$loadClass(RemoteException, name, initialize, &_RemoteException_ClassInfo_, allocate$RemoteException);
	return class$;
}

$Class* RemoteException::class$ = nullptr;

	} // rmi
} // java