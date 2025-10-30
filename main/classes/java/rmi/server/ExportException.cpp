#include <java/rmi/server/ExportException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _ExportException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ExportException, serialVersionUID)},
	{}
};

$MethodInfo _ExportException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ExportException::*)($String*)>(&ExportException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(ExportException::*)($String*,$Exception*)>(&ExportException::init$))},
	{}
};

$ClassInfo _ExportException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.ExportException",
	"java.rmi.RemoteException",
	nullptr,
	_ExportException_FieldInfo_,
	_ExportException_MethodInfo_
};

$Object* allocate$ExportException($Class* clazz) {
	return $of($alloc(ExportException));
}

void ExportException::init$($String* s) {
	$RemoteException::init$(s);
}

void ExportException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

ExportException::ExportException() {
}

ExportException::ExportException(const ExportException& e) : $RemoteException(e) {
}

void ExportException::throw$() {
	throw *this;
}

$Class* ExportException::load$($String* name, bool initialize) {
	$loadClass(ExportException, name, initialize, &_ExportException_ClassInfo_, allocate$ExportException);
	return class$;
}

$Class* ExportException::class$ = nullptr;

		} // server
	} // rmi
} // java