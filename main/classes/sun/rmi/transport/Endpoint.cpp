#include <sun/rmi/transport/Endpoint.h>

#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/Transport.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Channel = ::sun::rmi::transport::Channel;
using $Target = ::sun::rmi::transport::Target;
using $Transport = ::sun::rmi::transport::Transport;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _Endpoint_MethodInfo_[] = {
	{"exportObject", "(Lsun/rmi/transport/Target;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{"getChannel", "()Lsun/rmi/transport/Channel;", nullptr, $PUBLIC | $ABSTRACT},
	{"getInboundTransport", "()Lsun/rmi/transport/Transport;", nullptr, $PUBLIC | $ABSTRACT},
	{"getOutboundTransport", "()Lsun/rmi/transport/Transport;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _Endpoint_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.rmi.transport.Endpoint",
	nullptr,
	nullptr,
	nullptr,
	_Endpoint_MethodInfo_
};

$Object* allocate$Endpoint($Class* clazz) {
	return $of($alloc(Endpoint));
}

$Class* Endpoint::load$($String* name, bool initialize) {
	$loadClass(Endpoint, name, initialize, &_Endpoint_ClassInfo_, allocate$Endpoint);
	return class$;
}

$Class* Endpoint::class$ = nullptr;

		} // transport
	} // rmi
} // sun