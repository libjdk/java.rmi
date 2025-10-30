#include <sun/rmi/registry/RegistryImpl$3.h>

#include <java/net/InetAddress.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;

namespace sun {
	namespace rmi {
		namespace registry {

$FieldInfo _RegistryImpl$3_FieldInfo_[] = {
	{"val$clientHostName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$3, val$clientHostName)},
	{}
};

$MethodInfo _RegistryImpl$3_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", "()V", 0, $method(static_cast<void(RegistryImpl$3::*)($String*)>(&RegistryImpl$3::init$))},
	{"run", "()Ljava/net/InetAddress;", nullptr, $PUBLIC, nullptr, "java.net.UnknownHostException"},
	{}
};

$EnclosingMethodInfo _RegistryImpl$3_EnclosingMethodInfo_ = {
	"sun.rmi.registry.RegistryImpl",
	"checkAccess",
	"(Ljava/lang/String;)V"
};

$InnerClassInfo _RegistryImpl$3_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl$3_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.registry.RegistryImpl$3",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RegistryImpl$3_FieldInfo_,
	_RegistryImpl$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/net/InetAddress;>;",
	&_RegistryImpl$3_EnclosingMethodInfo_,
	_RegistryImpl$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl"
};

$Object* allocate$RegistryImpl$3($Class* clazz) {
	return $of($alloc(RegistryImpl$3));
}

void RegistryImpl$3::init$($String* val$clientHostName) {
	$set(this, val$clientHostName, val$clientHostName);
}

$Object* RegistryImpl$3::run() {
	return $of($InetAddress::getByName(this->val$clientHostName));
}

RegistryImpl$3::RegistryImpl$3() {
}

$Class* RegistryImpl$3::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$3, name, initialize, &_RegistryImpl$3_ClassInfo_, allocate$RegistryImpl$3);
	return class$;
}

$Class* RegistryImpl$3::class$ = nullptr;

		} // registry
	} // rmi
} // sun