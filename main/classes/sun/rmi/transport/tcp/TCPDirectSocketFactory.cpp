#include <sun/rmi/transport/tcp/TCPDirectSocketFactory.h>

#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/rmi/server/RMISocketFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $RMISocketFactory = ::java::rmi::server::RMISocketFactory;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$MethodInfo _TCPDirectSocketFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPDirectSocketFactory::*)()>(&TCPDirectSocketFactory::init$))},
	{"createServerSocket", "(I)Ljava/net/ServerSocket;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"createSocket", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _TCPDirectSocketFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.tcp.TCPDirectSocketFactory",
	"java.rmi.server.RMISocketFactory",
	nullptr,
	nullptr,
	_TCPDirectSocketFactory_MethodInfo_
};

$Object* allocate$TCPDirectSocketFactory($Class* clazz) {
	return $of($alloc(TCPDirectSocketFactory));
}

void TCPDirectSocketFactory::init$() {
	$RMISocketFactory::init$();
}

$Socket* TCPDirectSocketFactory::createSocket($String* host, int32_t port) {
	return $new($Socket, host, port);
}

$ServerSocket* TCPDirectSocketFactory::createServerSocket(int32_t port) {
	return $new($ServerSocket, port);
}

TCPDirectSocketFactory::TCPDirectSocketFactory() {
}

$Class* TCPDirectSocketFactory::load$($String* name, bool initialize) {
	$loadClass(TCPDirectSocketFactory, name, initialize, &_TCPDirectSocketFactory_ClassInfo_, allocate$TCPDirectSocketFactory);
	return class$;
}

$Class* TCPDirectSocketFactory::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun