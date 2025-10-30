#include <sun/rmi/server/LoaderHandler$1.h>

#include <java/lang/ClassLoader.h>
#include <java/net/URL.h>
#include <sun/rmi/server/LoaderHandler$Loader.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <jcpp.h>

using $URLArray = $Array<::java::net::URL>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;
using $LoaderHandler$Loader = ::sun::rmi::server::LoaderHandler$Loader;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _LoaderHandler$1_FieldInfo_[] = {
	{"val$parent", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(LoaderHandler$1, val$parent)},
	{"val$urls", "[Ljava/net/URL;", nullptr, $FINAL | $SYNTHETIC, $field(LoaderHandler$1, val$urls)},
	{}
};

$MethodInfo _LoaderHandler$1_MethodInfo_[] = {
	{"<init>", "([Ljava/net/URL;Ljava/lang/ClassLoader;)V", "()V", 0, $method(static_cast<void(LoaderHandler$1::*)($URLArray*,$ClassLoader*)>(&LoaderHandler$1::init$))},
	{"run", "()Lsun/rmi/server/LoaderHandler$Loader;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LoaderHandler$1_EnclosingMethodInfo_ = {
	"sun.rmi.server.LoaderHandler",
	"lookupLoader",
	"([Ljava/net/URL;Ljava/lang/ClassLoader;)Lsun/rmi/server/LoaderHandler$Loader;"
};

$InnerClassInfo _LoaderHandler$1_InnerClassesInfo_[] = {
	{"sun.rmi.server.LoaderHandler$1", nullptr, nullptr, 0},
	{"sun.rmi.server.LoaderHandler$Loader", "sun.rmi.server.LoaderHandler", "Loader", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LoaderHandler$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.LoaderHandler$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LoaderHandler$1_FieldInfo_,
	_LoaderHandler$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Lsun/rmi/server/LoaderHandler$Loader;>;",
	&_LoaderHandler$1_EnclosingMethodInfo_,
	_LoaderHandler$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.LoaderHandler"
};

$Object* allocate$LoaderHandler$1($Class* clazz) {
	return $of($alloc(LoaderHandler$1));
}

void LoaderHandler$1::init$($URLArray* val$urls, $ClassLoader* val$parent) {
	$set(this, val$urls, val$urls);
	$set(this, val$parent, val$parent);
}

$Object* LoaderHandler$1::run() {
	return $of($new($LoaderHandler$Loader, this->val$urls, this->val$parent));
}

LoaderHandler$1::LoaderHandler$1() {
}

$Class* LoaderHandler$1::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$1, name, initialize, &_LoaderHandler$1_ClassInfo_, allocate$LoaderHandler$1);
	return class$;
}

$Class* LoaderHandler$1::class$ = nullptr;

		} // server
	} // rmi
} // sun