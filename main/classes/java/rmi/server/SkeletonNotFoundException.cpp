#include <java/rmi/server/SkeletonNotFoundException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/CompoundAttribute.h>
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
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {
		namespace server {
$CompoundAttribute _SkeletonNotFoundException_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};


$FieldInfo _SkeletonNotFoundException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SkeletonNotFoundException, serialVersionUID)},
	{}
};

$MethodInfo _SkeletonNotFoundException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SkeletonNotFoundException::*)($String*)>(&SkeletonNotFoundException::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Exception;)V", nullptr, $PUBLIC, $method(static_cast<void(SkeletonNotFoundException::*)($String*,$Exception*)>(&SkeletonNotFoundException::init$))},
	{}
};

$ClassInfo _SkeletonNotFoundException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.SkeletonNotFoundException",
	"java.rmi.RemoteException",
	nullptr,
	_SkeletonNotFoundException_FieldInfo_,
	_SkeletonNotFoundException_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_SkeletonNotFoundException_Annotations_
};

$Object* allocate$SkeletonNotFoundException($Class* clazz) {
	return $of($alloc(SkeletonNotFoundException));
}

void SkeletonNotFoundException::init$($String* s) {
	$RemoteException::init$(s);
}

void SkeletonNotFoundException::init$($String* s, $Exception* ex) {
	$RemoteException::init$(s, ex);
}

SkeletonNotFoundException::SkeletonNotFoundException() {
}

SkeletonNotFoundException::SkeletonNotFoundException(const SkeletonNotFoundException& e) {
}

SkeletonNotFoundException SkeletonNotFoundException::wrapper$() {
	$pendingException(this);
	return *this;
}

void SkeletonNotFoundException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* SkeletonNotFoundException::load$($String* name, bool initialize) {
	$loadClass(SkeletonNotFoundException, name, initialize, &_SkeletonNotFoundException_ClassInfo_, allocate$SkeletonNotFoundException);
	return class$;
}

$Class* SkeletonNotFoundException::class$ = nullptr;

		} // server
	} // rmi
} // java