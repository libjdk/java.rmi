#include <java/rmi/server/RMISocketFactory.h>

#include <java/lang/SecurityManager.h>
#include <java/net/SocketException.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIFailureHandler.h>
#include <sun/rmi/transport/tcp/TCPDirectSocketFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $SocketException = ::java::net::SocketException;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIFailureHandler = ::java::rmi::server::RMIFailureHandler;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $TCPDirectSocketFactory = ::sun::rmi::transport::tcp::TCPDirectSocketFactory;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _RMISocketFactory_FieldInfo_[] = {
	{"factory", "Ljava/rmi/server/RMISocketFactory;", nullptr, $PRIVATE | $STATIC, $staticField(RMISocketFactory, factory)},
	{"defaultSocketFactory", "Ljava/rmi/server/RMISocketFactory;", nullptr, $PRIVATE | $STATIC, $staticField(RMISocketFactory, defaultSocketFactory)},
	{"handler", "Ljava/rmi/server/RMIFailureHandler;", nullptr, $PRIVATE | $STATIC, $staticField(RMISocketFactory, handler)},
	{}
};

$MethodInfo _RMISocketFactory_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"createServerSocket", "(I)Ljava/net/ServerSocket;", nullptr, $PUBLIC | $ABSTRACT},
	{"createSocket", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PUBLIC | $ABSTRACT},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RMISocketFactory::*)()>(&RMISocketFactory::init$))},
	{"getDefaultSocketFactory", "()Ljava/rmi/server/RMISocketFactory;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<RMISocketFactory*(*)()>(&RMISocketFactory::getDefaultSocketFactory))},
	{"getFailureHandler", "()Ljava/rmi/server/RMIFailureHandler;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<$RMIFailureHandler*(*)()>(&RMISocketFactory::getFailureHandler))},
	{"getSocketFactory", "()Ljava/rmi/server/RMISocketFactory;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<RMISocketFactory*(*)()>(&RMISocketFactory::getSocketFactory))},
	{"setFailureHandler", "(Ljava/rmi/server/RMIFailureHandler;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($RMIFailureHandler*)>(&RMISocketFactory::setFailureHandler))},
	{"setSocketFactory", "(Ljava/rmi/server/RMISocketFactory;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)(RMISocketFactory*)>(&RMISocketFactory::setSocketFactory)), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _RMISocketFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.rmi.server.RMISocketFactory",
	"java.lang.Object",
	"java.rmi.server.RMIClientSocketFactory,java.rmi.server.RMIServerSocketFactory",
	_RMISocketFactory_FieldInfo_,
	_RMISocketFactory_MethodInfo_
};

$Object* allocate$RMISocketFactory($Class* clazz) {
	return $of($alloc(RMISocketFactory));
}

int32_t RMISocketFactory::hashCode() {
	 return this->$RMIClientSocketFactory::hashCode();
}

bool RMISocketFactory::equals(Object$* arg0) {
	 return this->$RMIClientSocketFactory::equals(arg0);
}

$Object* RMISocketFactory::clone() {
	 return this->$RMIClientSocketFactory::clone();
}

$String* RMISocketFactory::toString() {
	 return this->$RMIClientSocketFactory::toString();
}

void RMISocketFactory::finalize() {
	this->$RMIClientSocketFactory::finalize();
}

RMISocketFactory* RMISocketFactory::factory = nullptr;
RMISocketFactory* RMISocketFactory::defaultSocketFactory = nullptr;
$RMIFailureHandler* RMISocketFactory::handler = nullptr;

void RMISocketFactory::init$() {
}

void RMISocketFactory::setSocketFactory(RMISocketFactory* fac) {
	$load(RMISocketFactory);
	$synchronized(class$) {
		$init(RMISocketFactory);
		if (RMISocketFactory::factory != nullptr) {
			$throwNew($SocketException, "factory already defined"_s);
		}
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			security->checkSetFactory();
		}
		$assignStatic(RMISocketFactory::factory, fac);
	}
}

RMISocketFactory* RMISocketFactory::getSocketFactory() {
	$load(RMISocketFactory);
	$synchronized(class$) {
		$init(RMISocketFactory);
		return RMISocketFactory::factory;
	}
}

RMISocketFactory* RMISocketFactory::getDefaultSocketFactory() {
	$load(RMISocketFactory);
	$synchronized(class$) {
		$init(RMISocketFactory);
		if (RMISocketFactory::defaultSocketFactory == nullptr) {
			$assignStatic(RMISocketFactory::defaultSocketFactory, $new($TCPDirectSocketFactory));
		}
		return RMISocketFactory::defaultSocketFactory;
	}
}

void RMISocketFactory::setFailureHandler($RMIFailureHandler* fh) {
	$load(RMISocketFactory);
	$synchronized(class$) {
		$init(RMISocketFactory);
		$var($SecurityManager, security, $System::getSecurityManager());
		if (security != nullptr) {
			security->checkSetFactory();
		}
		$assignStatic(RMISocketFactory::handler, fh);
	}
}

$RMIFailureHandler* RMISocketFactory::getFailureHandler() {
	$load(RMISocketFactory);
	$synchronized(class$) {
		$init(RMISocketFactory);
		return RMISocketFactory::handler;
	}
}

void clinit$RMISocketFactory($Class* class$) {
	$assignStatic(RMISocketFactory::factory, nullptr);
	$assignStatic(RMISocketFactory::handler, nullptr);
}

RMISocketFactory::RMISocketFactory() {
}

$Class* RMISocketFactory::load$($String* name, bool initialize) {
	$loadClass(RMISocketFactory, name, initialize, &_RMISocketFactory_ClassInfo_, clinit$RMISocketFactory, allocate$RMISocketFactory);
	return class$;
}

$Class* RMISocketFactory::class$ = nullptr;

		} // server
	} // rmi
} // java