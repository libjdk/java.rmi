#include <java/rmi/server/Unreferenced.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _Unreferenced_MethodInfo_[] = {
	{"unreferenced", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _Unreferenced_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.Unreferenced",
	nullptr,
	nullptr,
	nullptr,
	_Unreferenced_MethodInfo_
};

$Object* allocate$Unreferenced($Class* clazz) {
	return $of($alloc(Unreferenced));
}

$Class* Unreferenced::load$($String* name, bool initialize) {
	$loadClass(Unreferenced, name, initialize, &_Unreferenced_ClassInfo_, allocate$Unreferenced);
	return class$;
}

$Class* Unreferenced::class$ = nullptr;

		} // server
	} // rmi
} // java