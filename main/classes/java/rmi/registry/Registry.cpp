#include <java/rmi/registry/Registry.h>

#include <jcpp.h>

#undef REGISTRY_PORT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;

namespace java {
	namespace rmi {
		namespace registry {

$FieldInfo _Registry_FieldInfo_[] = {
	{"REGISTRY_PORT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Registry, REGISTRY_PORT)},
	{}
};

$MethodInfo _Registry_MethodInfo_[] = {
	{"bind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException,java.rmi.AlreadyBoundException,java.rmi.AccessException"},
	{"list", "()[Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException,java.rmi.AccessException"},
	{"lookup", "(Ljava/lang/String;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException,java.rmi.NotBoundException,java.rmi.AccessException"},
	{"rebind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException,java.rmi.AccessException"},
	{"unbind", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException,java.rmi.NotBoundException,java.rmi.AccessException"},
	{}
};

$ClassInfo _Registry_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.registry.Registry",
	nullptr,
	"java.rmi.Remote",
	_Registry_FieldInfo_,
	_Registry_MethodInfo_
};

$Object* allocate$Registry($Class* clazz) {
	return $of($alloc(Registry));
}

$Class* Registry::load$($String* name, bool initialize) {
	$loadClass(Registry, name, initialize, &_Registry_ClassInfo_, allocate$Registry);
	return class$;
}

$Class* Registry::class$ = nullptr;

		} // registry
	} // rmi
} // java