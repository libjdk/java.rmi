#include <java/rmi/server/RMIFailureHandler.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _RMIFailureHandler_MethodInfo_[] = {
	{"failure", "(Ljava/lang/Exception;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _RMIFailureHandler_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.RMIFailureHandler",
	nullptr,
	nullptr,
	nullptr,
	_RMIFailureHandler_MethodInfo_
};

$Object* allocate$RMIFailureHandler($Class* clazz) {
	return $of($alloc(RMIFailureHandler));
}

$Class* RMIFailureHandler::load$($String* name, bool initialize) {
	$loadClass(RMIFailureHandler, name, initialize, &_RMIFailureHandler_ClassInfo_, allocate$RMIFailureHandler);
	return class$;
}

$Class* RMIFailureHandler::class$ = nullptr;

		} // server
	} // rmi
} // java