#include <java/rmi/server/Skeleton.h>

#include <java/rmi/Remote.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <jcpp.h>

using $OperationArray = $Array<::java::rmi::server::Operation>;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RemoteCall = ::java::rmi::server::RemoteCall;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _Skeleton_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Skeleton_MethodAnnotations_dispatch0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Skeleton_MethodAnnotations_getOperations1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$MethodInfo _Skeleton_MethodInfo_[] = {
	{"dispatch", "(Ljava/rmi/Remote;Ljava/rmi/server/RemoteCall;IJ)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.lang.Exception", nullptr, _Skeleton_MethodAnnotations_dispatch0},
	{"getOperations", "()[Ljava/rmi/server/Operation;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, nullptr, nullptr, _Skeleton_MethodAnnotations_getOperations1},
	{}
};

$ClassInfo _Skeleton_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.Skeleton",
	nullptr,
	nullptr,
	nullptr,
	_Skeleton_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_Skeleton_Annotations_
};

$Object* allocate$Skeleton($Class* clazz) {
	return $of($alloc(Skeleton));
}

$Class* Skeleton::load$($String* name, bool initialize) {
	$loadClass(Skeleton, name, initialize, &_Skeleton_ClassInfo_, allocate$Skeleton);
	return class$;
}

$Class* Skeleton::class$ = nullptr;

		} // server
	} // rmi
} // java