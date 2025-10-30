#include <java/rmi/server/RMIServerSocketFactory.h>

#include <java/net/ServerSocket.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ServerSocket = ::java::net::ServerSocket;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _RMIServerSocketFactory_MethodInfo_[] = {
	{"createServerSocket", "(I)Ljava/net/ServerSocket;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _RMIServerSocketFactory_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.RMIServerSocketFactory",
	nullptr,
	nullptr,
	nullptr,
	_RMIServerSocketFactory_MethodInfo_
};

$Object* allocate$RMIServerSocketFactory($Class* clazz) {
	return $of($alloc(RMIServerSocketFactory));
}

$Class* RMIServerSocketFactory::load$($String* name, bool initialize) {
	$loadClass(RMIServerSocketFactory, name, initialize, &_RMIServerSocketFactory_ClassInfo_, allocate$RMIServerSocketFactory);
	return class$;
}

$Class* RMIServerSocketFactory::class$ = nullptr;

		} // server
	} // rmi
} // java