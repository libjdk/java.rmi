#include <sun/rmi/registry/RegistryImpl$6.h>

#include <java/net/URL.h>
#include <java/security/CodeSource.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/Policy.h>
#include <java/security/cert/Certificate.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <jcpp.h>

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $CodeSource = ::java::security::CodeSource;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $Policy = ::java::security::Policy;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Certificate = ::java::security::cert::Certificate;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;

namespace sun {
	namespace rmi {
		namespace registry {

$MethodInfo _RegistryImpl$6_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(RegistryImpl$6::*)()>(&RegistryImpl$6::init$))},
	{"run", "()Ljava/security/PermissionCollection;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RegistryImpl$6_EnclosingMethodInfo_ = {
	"sun.rmi.registry.RegistryImpl",
	"getAccessControlContext",
	"(I)Ljava/security/AccessControlContext;"
};

$InnerClassInfo _RegistryImpl$6_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$6", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl$6_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.registry.RegistryImpl$6",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_RegistryImpl$6_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/security/PermissionCollection;>;",
	&_RegistryImpl$6_EnclosingMethodInfo_,
	_RegistryImpl$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl"
};

$Object* allocate$RegistryImpl$6($Class* clazz) {
	return $of($alloc(RegistryImpl$6));
}

void RegistryImpl$6::init$() {
}

$Object* RegistryImpl$6::run() {
	$useLocalCurrentObjectStackCache();
	$var($CodeSource, codesource, $new($CodeSource, ($URL*)nullptr, ($CertificateArray*)nullptr));
	$var($Policy, p, $Policy::getPolicy());
	if (p != nullptr) {
		return $of(p->getPermissions(codesource));
	} else {
		return $of($new($Permissions));
	}
}

RegistryImpl$6::RegistryImpl$6() {
}

$Class* RegistryImpl$6::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$6, name, initialize, &_RegistryImpl$6_ClassInfo_, allocate$RegistryImpl$6);
	return class$;
}

$Class* RegistryImpl$6::class$ = nullptr;

		} // registry
	} // rmi
} // sun