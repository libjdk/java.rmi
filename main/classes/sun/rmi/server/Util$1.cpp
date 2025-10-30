#include <sun/rmi/server/Util$1.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/Proxy.h>
#include <java/rmi/Remote.h>
#include <sun/rmi/server/Util.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $Proxy = ::java::lang::reflect::Proxy;
using $Remote = ::java::rmi::Remote;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Util = ::sun::rmi::server::Util;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _Util$1_FieldInfo_[] = {
	{"val$handler", "Ljava/lang/reflect/InvocationHandler;", nullptr, $FINAL | $SYNTHETIC, $field(Util$1, val$handler)},
	{"val$interfaces", "[Ljava/lang/Class;", nullptr, $FINAL | $SYNTHETIC, $field(Util$1, val$interfaces)},
	{"val$loader", "Ljava/lang/ClassLoader;", nullptr, $FINAL | $SYNTHETIC, $field(Util$1, val$loader)},
	{}
};

$MethodInfo _Util$1_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;[Ljava/lang/Class;Ljava/lang/reflect/InvocationHandler;)V", "()V", 0, $method(static_cast<void(Util$1::*)($ClassLoader*,$ClassArray*,$InvocationHandler*)>(&Util$1::init$))},
	{"run", "()Ljava/rmi/Remote;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Util$1_EnclosingMethodInfo_ = {
	"sun.rmi.server.Util",
	"createProxy",
	"(Ljava/lang/Class;Ljava/rmi/server/RemoteRef;Z)Ljava/rmi/Remote;"
};

$InnerClassInfo _Util$1_InnerClassesInfo_[] = {
	{"sun.rmi.server.Util$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Util$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.Util$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Util$1_FieldInfo_,
	_Util$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/rmi/Remote;>;",
	&_Util$1_EnclosingMethodInfo_,
	_Util$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.Util"
};

$Object* allocate$Util$1($Class* clazz) {
	return $of($alloc(Util$1));
}

void Util$1::init$($ClassLoader* val$loader, $ClassArray* val$interfaces, $InvocationHandler* val$handler) {
	$set(this, val$loader, val$loader);
	$set(this, val$interfaces, val$interfaces);
	$set(this, val$handler, val$handler);
}

$Object* Util$1::run() {
	$beforeCallerSensitive();
	return $of($cast($Remote, $Proxy::newProxyInstance(this->val$loader, this->val$interfaces, this->val$handler)));
}

Util$1::Util$1() {
}

$Class* Util$1::load$($String* name, bool initialize) {
	$loadClass(Util$1, name, initialize, &_Util$1_ClassInfo_, allocate$Util$1);
	return class$;
}

$Class* Util$1::class$ = nullptr;

		} // server
	} // rmi
} // sun