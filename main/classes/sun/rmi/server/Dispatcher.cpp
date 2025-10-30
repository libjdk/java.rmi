#include <sun/rmi/server/Dispatcher.h>

#include <java/rmi/Remote.h>
#include <java/rmi/server/RemoteCall.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RemoteCall = ::java::rmi::server::RemoteCall;

namespace sun {
	namespace rmi {
		namespace server {

$MethodInfo _Dispatcher_MethodInfo_[] = {
	{"dispatch", "(Ljava/rmi/Remote;Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _Dispatcher_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.rmi.server.Dispatcher",
	nullptr,
	nullptr,
	nullptr,
	_Dispatcher_MethodInfo_
};

$Object* allocate$Dispatcher($Class* clazz) {
	return $of($alloc(Dispatcher));
}

$Class* Dispatcher::load$($String* name, bool initialize) {
	$loadClass(Dispatcher, name, initialize, &_Dispatcher_ClassInfo_, allocate$Dispatcher);
	return class$;
}

$Class* Dispatcher::class$ = nullptr;

		} // server
	} // rmi
} // sun