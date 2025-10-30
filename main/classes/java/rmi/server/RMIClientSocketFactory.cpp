#include <java/rmi/server/RMIClientSocketFactory.h>

#include <java/net/Socket.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Socket = ::java::net::Socket;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _RMIClientSocketFactory_MethodInfo_[] = {
	{"createSocket", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _RMIClientSocketFactory_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.RMIClientSocketFactory",
	nullptr,
	nullptr,
	nullptr,
	_RMIClientSocketFactory_MethodInfo_
};

$Object* allocate$RMIClientSocketFactory($Class* clazz) {
	return $of($alloc(RMIClientSocketFactory));
}

$Class* RMIClientSocketFactory::load$($String* name, bool initialize) {
	$loadClass(RMIClientSocketFactory, name, initialize, &_RMIClientSocketFactory_ClassInfo_, allocate$RMIClientSocketFactory);
	return class$;
}

$Class* RMIClientSocketFactory::class$ = nullptr;

		} // server
	} // rmi
} // java