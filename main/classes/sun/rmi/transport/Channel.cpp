#include <sun/rmi/transport/Channel.h>

#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/Endpoint.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Connection = ::sun::rmi::transport::Connection;
using $Endpoint = ::sun::rmi::transport::Endpoint;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _Channel_MethodInfo_[] = {
	{"free", "(Lsun/rmi/transport/Connection;Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{"getEndpoint", "()Lsun/rmi/transport/Endpoint;", nullptr, $PUBLIC | $ABSTRACT},
	{"newConnection", "()Lsun/rmi/transport/Connection;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{}
};

$ClassInfo _Channel_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.rmi.transport.Channel",
	nullptr,
	nullptr,
	nullptr,
	_Channel_MethodInfo_
};

$Object* allocate$Channel($Class* clazz) {
	return $of($alloc(Channel));
}

$Class* Channel::load$($String* name, bool initialize) {
	$loadClass(Channel, name, initialize, &_Channel_ClassInfo_, allocate$Channel);
	return class$;
}

$Class* Channel::class$ = nullptr;

		} // transport
	} // rmi
} // sun