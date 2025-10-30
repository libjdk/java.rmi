#include <java/rmi/server/SocketSecurityException.h>

#include <java/rmi/server/ExportException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ExportException = ::java::rmi::server::ExportException;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _SocketSecurityException_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _SocketSecurityException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SocketSecurityException, serialVersionUID)},
	{}
};

$MethodInfo _SocketSecurityException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketSecurityException::*)($String*)>(&SocketSecurityException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketSecurityException::*)($String*,$Exception*)>(&SocketSecurityException::init$))},
	{}
};

$ClassInfo _SocketSecurityException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.SocketSecurityException",
	"java.rmi.server.ExportException",
	nullptr,
	_SocketSecurityException_FieldInfo_,
	_SocketSecurityException_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_SocketSecurityException_Annotations_
};

$Object* allocate$SocketSecurityException($Class* clazz) {
	return $of($alloc(SocketSecurityException));
}

void SocketSecurityException::init$($String* s) {
	$ExportException::init$(s);
}

void SocketSecurityException::init$($String* s, $Exception* ex) {
	$ExportException::init$(s, ex);
}

SocketSecurityException::SocketSecurityException() {
}

SocketSecurityException::SocketSecurityException(const SocketSecurityException& e) : $ExportException(e) {
}

void SocketSecurityException::throw$() {
	throw *this;
}

$Class* SocketSecurityException::load$($String* name, bool initialize) {
	$loadClass(SocketSecurityException, name, initialize, &_SocketSecurityException_ClassInfo_, allocate$SocketSecurityException);
	return class$;
}

$Class* SocketSecurityException::class$ = nullptr;

		} // server
	} // rmi
} // java