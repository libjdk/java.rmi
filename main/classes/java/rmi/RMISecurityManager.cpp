#include <java/rmi/RMISecurityManager.h>

#include <java/lang/SecurityManager.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $SecurityManager = ::java::lang::SecurityManager;

namespace java {
	namespace rmi {

$NamedAttribute RMISecurityManager_Attribute_var$0[] = {
	{"since", 's', "1.8"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _RMISecurityManager_Annotations_[] = {
	{"Ljava/lang/Deprecated;", RMISecurityManager_Attribute_var$0},
	{}
};

$MethodInfo _RMISecurityManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RMISecurityManager::*)()>(&RMISecurityManager::init$))},
	{}
};

$ClassInfo _RMISecurityManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.RMISecurityManager",
	"java.lang.SecurityManager",
	nullptr,
	nullptr,
	_RMISecurityManager_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RMISecurityManager_Annotations_
};

$Object* allocate$RMISecurityManager($Class* clazz) {
	return $of($alloc(RMISecurityManager));
}

void RMISecurityManager::init$() {
	$SecurityManager::init$();
}

RMISecurityManager::RMISecurityManager() {
}

$Class* RMISecurityManager::load$($String* name, bool initialize) {
	$loadClass(RMISecurityManager, name, initialize, &_RMISecurityManager_ClassInfo_, allocate$RMISecurityManager);
	return class$;
}

$Class* RMISecurityManager::class$ = nullptr;

	} // rmi
} // java