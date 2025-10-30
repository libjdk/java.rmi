#include <java/rmi/registry/LocateRegistry.h>

#include <java/net/InetAddress.h>
#include <java/rmi/Remote.h>
#include <java/rmi/registry/Registry.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RemoteRef.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastRef2.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <jcpp.h>

#undef REGISTRY_ID
#undef REGISTRY_PORT

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $Remote = ::java::rmi::Remote;
using $Registry = ::java::rmi::registry::Registry;
using $ObjID = ::java::rmi::server::ObjID;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $UnicastRef2 = ::sun::rmi::server::UnicastRef2;
using $Util = ::sun::rmi::server::Util;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;

namespace java {
	namespace rmi {
		namespace registry {

$MethodInfo _LocateRegistry_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(LocateRegistry::*)()>(&LocateRegistry::init$))},
	{"createRegistry", "(I)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)(int32_t)>(&LocateRegistry::createRegistry)), "java.rmi.RemoteException"},
	{"createRegistry", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&LocateRegistry::createRegistry)), "java.rmi.RemoteException"},
	{"getRegistry", "()Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)()>(&LocateRegistry::getRegistry)), "java.rmi.RemoteException"},
	{"getRegistry", "(I)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)(int32_t)>(&LocateRegistry::getRegistry)), "java.rmi.RemoteException"},
	{"getRegistry", "(Ljava/lang/String;)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)($String*)>(&LocateRegistry::getRegistry)), "java.rmi.RemoteException"},
	{"getRegistry", "(Ljava/lang/String;I)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)($String*,int32_t)>(&LocateRegistry::getRegistry)), "java.rmi.RemoteException"},
	{"getRegistry", "(Ljava/lang/String;ILjava/rmi/server/RMIClientSocketFactory;)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Registry*(*)($String*,int32_t,$RMIClientSocketFactory*)>(&LocateRegistry::getRegistry)), "java.rmi.RemoteException"},
	{}
};

$ClassInfo _LocateRegistry_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.registry.LocateRegistry",
	"java.lang.Object",
	nullptr,
	nullptr,
	_LocateRegistry_MethodInfo_
};

$Object* allocate$LocateRegistry($Class* clazz) {
	return $of($alloc(LocateRegistry));
}

void LocateRegistry::init$() {
}

$Registry* LocateRegistry::getRegistry() {
	return getRegistry(nullptr, $Registry::REGISTRY_PORT);
}

$Registry* LocateRegistry::getRegistry(int32_t port) {
	return getRegistry(nullptr, port);
}

$Registry* LocateRegistry::getRegistry($String* host) {
	return getRegistry(host, $Registry::REGISTRY_PORT);
}

$Registry* LocateRegistry::getRegistry($String* host, int32_t port) {
	return getRegistry(host, port, nullptr);
}

$Registry* LocateRegistry::getRegistry($String* host$renamed, int32_t port, $RMIClientSocketFactory* csf) {
	$useLocalCurrentObjectStackCache();
	$var($String, host, host$renamed);
	$var($Registry, registry, nullptr);
	if (port <= 0) {
		port = $Registry::REGISTRY_PORT;
	}
	if (host == nullptr || $nc(host)->length() == 0) {
		try {
			$assign(host, $nc($($InetAddress::getLocalHost()))->getHostAddress());
		} catch ($Exception& e) {
			$assign(host, ""_s);
		}
	}
	$var($ObjID, var$0, $new($ObjID, $ObjID::REGISTRY_ID));
	$var($LiveRef, liveRef, $new($LiveRef, var$0, static_cast<$Endpoint*>($$new($TCPEndpoint, host, port, csf, nullptr)), false));
	$var($RemoteRef, ref, (csf == nullptr) ? static_cast<$RemoteRef*>($new($UnicastRef, liveRef)) : static_cast<$RemoteRef*>($new($UnicastRef2, liveRef)));
	$load($RegistryImpl);
	return $cast($Registry, $Util::createProxy($RegistryImpl::class$, ref, false));
}

$Registry* LocateRegistry::createRegistry(int32_t port) {
	return $new($RegistryImpl, port);
}

$Registry* LocateRegistry::createRegistry(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	return $new($RegistryImpl, port, csf, ssf);
}

LocateRegistry::LocateRegistry() {
}

$Class* LocateRegistry::load$($String* name, bool initialize) {
	$loadClass(LocateRegistry, name, initialize, &_LocateRegistry_ClassInfo_, allocate$LocateRegistry);
	return class$;
}

$Class* LocateRegistry::class$ = nullptr;

		} // registry
	} // rmi
} // java