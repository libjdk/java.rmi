#include <java/rmi/registry/RegistryHandler.h>

#include <java/rmi/registry/Registry.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $Registry = ::java::rmi::registry::Registry;

namespace java {
	namespace rmi {
		namespace registry {

$CompoundAttribute _RegistryHandler_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RegistryHandler_MethodAnnotations_registryImpl0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RegistryHandler_MethodAnnotations_registryStub1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$MethodInfo _RegistryHandler_MethodInfo_[] = {
	{"registryImpl", "(I)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.rmi.RemoteException", nullptr, _RegistryHandler_MethodAnnotations_registryImpl0},
	{"registryStub", "(Ljava/lang/String;I)Ljava/rmi/registry/Registry;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.rmi.RemoteException,java.rmi.UnknownHostException", nullptr, _RegistryHandler_MethodAnnotations_registryStub1},
	{}
};

$ClassInfo _RegistryHandler_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.registry.RegistryHandler",
	nullptr,
	nullptr,
	nullptr,
	_RegistryHandler_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RegistryHandler_Annotations_
};

$Object* allocate$RegistryHandler($Class* clazz) {
	return $of($alloc(RegistryHandler));
}

$Class* RegistryHandler::load$($String* name, bool initialize) {
	$loadClass(RegistryHandler, name, initialize, &_RegistryHandler_ClassInfo_, allocate$RegistryHandler);
	return class$;
}

$Class* RegistryHandler::class$ = nullptr;

		} // registry
	} // rmi
} // java