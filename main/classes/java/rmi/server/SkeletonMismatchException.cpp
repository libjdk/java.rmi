#include <java/rmi/server/SkeletonMismatchException.h>

#include <java/rmi/RemoteException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _SkeletonMismatchException_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _SkeletonMismatchException_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _SkeletonMismatchException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SkeletonMismatchException, serialVersionUID)},
	{}
};

$MethodInfo _SkeletonMismatchException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(static_cast<void(SkeletonMismatchException::*)($String*)>(&SkeletonMismatchException::init$)), nullptr, nullptr, _SkeletonMismatchException_MethodAnnotations_init$0},
	{}
};

$ClassInfo _SkeletonMismatchException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.SkeletonMismatchException",
	"java.rmi.RemoteException",
	nullptr,
	_SkeletonMismatchException_FieldInfo_,
	_SkeletonMismatchException_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_SkeletonMismatchException_Annotations_
};

$Object* allocate$SkeletonMismatchException($Class* clazz) {
	return $of($alloc(SkeletonMismatchException));
}

void SkeletonMismatchException::init$($String* s) {
	$RemoteException::init$(s);
}

SkeletonMismatchException::SkeletonMismatchException() {
}

SkeletonMismatchException::SkeletonMismatchException(const SkeletonMismatchException& e) : $RemoteException(e) {
}

void SkeletonMismatchException::throw$() {
	throw *this;
}

$Class* SkeletonMismatchException::load$($String* name, bool initialize) {
	$loadClass(SkeletonMismatchException, name, initialize, &_SkeletonMismatchException_ClassInfo_, allocate$SkeletonMismatchException);
	return class$;
}

$Class* SkeletonMismatchException::class$ = nullptr;

		} // server
	} // rmi
} // java