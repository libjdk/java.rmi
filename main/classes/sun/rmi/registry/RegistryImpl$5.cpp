#include <sun/rmi/registry/RegistryImpl$5.h>

#include <sun/rmi/registry/RegistryImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;

namespace sun {
	namespace rmi {
		namespace registry {

$FieldInfo _RegistryImpl$5_FieldInfo_[] = {
	{"val$regPort", "I", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$5, val$regPort)},
	{}
};

$MethodInfo _RegistryImpl$5_MethodInfo_[] = {
	{"<init>", "(I)V", "()V", 0, $method(static_cast<void(RegistryImpl$5::*)(int32_t)>(&RegistryImpl$5::init$))},
	{"run", "()Lsun/rmi/registry/RegistryImpl;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{}
};

$EnclosingMethodInfo _RegistryImpl$5_EnclosingMethodInfo_ = {
	"sun.rmi.registry.RegistryImpl",
	"createRegistry",
	"(I)Lsun/rmi/registry/RegistryImpl;"
};

$InnerClassInfo _RegistryImpl$5_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$5", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl$5_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.registry.RegistryImpl$5",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RegistryImpl$5_FieldInfo_,
	_RegistryImpl$5_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Lsun/rmi/registry/RegistryImpl;>;",
	&_RegistryImpl$5_EnclosingMethodInfo_,
	_RegistryImpl$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl"
};

$Object* allocate$RegistryImpl$5($Class* clazz) {
	return $of($alloc(RegistryImpl$5));
}

void RegistryImpl$5::init$(int32_t val$regPort) {
	this->val$regPort = val$regPort;
}

$Object* RegistryImpl$5::run() {
	return $of($new($RegistryImpl, this->val$regPort));
}

RegistryImpl$5::RegistryImpl$5() {
}

$Class* RegistryImpl$5::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$5, name, initialize, &_RegistryImpl$5_ClassInfo_, allocate$RegistryImpl$5);
	return class$;
}

$Class* RegistryImpl$5::class$ = nullptr;

		} // registry
	} // rmi
} // sun