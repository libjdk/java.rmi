#include <sun/rmi/registry/RegistryImpl$4.h>

#include <java/net/InetAddress.h>
#include <java/net/ServerSocket.h>
#include <java/util/Hashtable.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Hashtable = ::java::util::Hashtable;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;

namespace sun {
	namespace rmi {
		namespace registry {

$FieldInfo _RegistryImpl$4_FieldInfo_[] = {
	{"val$finalClientHost", "Ljava/net/InetAddress;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$4, val$finalClientHost)},
	{}
};

$MethodInfo _RegistryImpl$4_MethodInfo_[] = {
	{"<init>", "(Ljava/net/InetAddress;)V", "()V", 0, $method(static_cast<void(RegistryImpl$4::*)($InetAddress*)>(&RegistryImpl$4::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$EnclosingMethodInfo _RegistryImpl$4_EnclosingMethodInfo_ = {
	"sun.rmi.registry.RegistryImpl",
	"checkAccess",
	"(Ljava/lang/String;)V"
};

$InnerClassInfo _RegistryImpl$4_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$4", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl$4_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.registry.RegistryImpl$4",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RegistryImpl$4_FieldInfo_,
	_RegistryImpl$4_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Void;>;",
	&_RegistryImpl$4_EnclosingMethodInfo_,
	_RegistryImpl$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl"
};

$Object* allocate$RegistryImpl$4($Class* clazz) {
	return $of($alloc(RegistryImpl$4));
}

void RegistryImpl$4::init$($InetAddress* val$finalClientHost) {
	$set(this, val$finalClientHost, val$finalClientHost);
}

$Object* RegistryImpl$4::run() {
	($$new($ServerSocket, 0, 10, this->val$finalClientHost))->close();
	$init($RegistryImpl);
	$nc($RegistryImpl::allowedAccessCache)->put(this->val$finalClientHost, this->val$finalClientHost);
	return $of(nullptr);
}

RegistryImpl$4::RegistryImpl$4() {
}

$Class* RegistryImpl$4::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$4, name, initialize, &_RegistryImpl$4_ClassInfo_, allocate$RegistryImpl$4);
	return class$;
}

$Class* RegistryImpl$4::class$ = nullptr;

		} // registry
	} // rmi
} // sun