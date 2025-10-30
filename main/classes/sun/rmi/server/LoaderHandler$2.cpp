#include <sun/rmi/server/LoaderHandler$2.h>

#include <java/net/URL.h>
#include <java/security/CodeSource.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/Policy.h>
#include <java/security/cert/Certificate.h>
#include <sun/rmi/server/LoaderHandler.h>
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
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;

namespace sun {
	namespace rmi {
		namespace server {

$MethodInfo _LoaderHandler$2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(LoaderHandler$2::*)()>(&LoaderHandler$2::init$))},
	{"run", "()Ljava/security/PermissionCollection;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LoaderHandler$2_EnclosingMethodInfo_ = {
	"sun.rmi.server.LoaderHandler",
	"getLoaderAccessControlContext",
	"([Ljava/net/URL;)Ljava/security/AccessControlContext;"
};

$InnerClassInfo _LoaderHandler$2_InnerClassesInfo_[] = {
	{"sun.rmi.server.LoaderHandler$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LoaderHandler$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.LoaderHandler$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_LoaderHandler$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/security/PermissionCollection;>;",
	&_LoaderHandler$2_EnclosingMethodInfo_,
	_LoaderHandler$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.LoaderHandler"
};

$Object* allocate$LoaderHandler$2($Class* clazz) {
	return $of($alloc(LoaderHandler$2));
}

void LoaderHandler$2::init$() {
}

$Object* LoaderHandler$2::run() {
	$useLocalCurrentObjectStackCache();
	$var($CodeSource, codesource, $new($CodeSource, ($URL*)nullptr, ($CertificateArray*)nullptr));
	$var($Policy, p, $Policy::getPolicy());
	if (p != nullptr) {
		return $of(p->getPermissions(codesource));
	} else {
		return $of($new($Permissions));
	}
}

LoaderHandler$2::LoaderHandler$2() {
}

$Class* LoaderHandler$2::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$2, name, initialize, &_LoaderHandler$2_ClassInfo_, allocate$LoaderHandler$2);
	return class$;
}

$Class* LoaderHandler$2::class$ = nullptr;

		} // server
	} // rmi
} // sun