#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps.h>

#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps$1.h>
#include <java/rmi/server/RemoteObjectInvocationHandler.h>
#include <sun/rmi/server/WeakClassHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteObjectInvocationHandler = ::java::rmi::server::RemoteObjectInvocationHandler;
using $RemoteObjectInvocationHandler$MethodToHash_Maps$1 = ::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps$1;
using $WeakClassHashMap = ::sun::rmi::server::WeakClassHashMap;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _RemoteObjectInvocationHandler$MethodToHash_Maps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(RemoteObjectInvocationHandler$MethodToHash_Maps::*)()>(&RemoteObjectInvocationHandler$MethodToHash_Maps::init$))},
	{"computeValue", "(Ljava/lang/Class;)Ljava/util/Map;", "(Ljava/lang/Class<*>;)Ljava/util/Map<Ljava/lang/reflect/Method;Ljava/lang/Long;>;", $PROTECTED},
	{}
};

$InnerClassInfo _RemoteObjectInvocationHandler$MethodToHash_Maps_InnerClassesInfo_[] = {
	{"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps", "java.rmi.server.RemoteObjectInvocationHandler", "MethodToHash_Maps", $PRIVATE | $STATIC},
	{"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RemoteObjectInvocationHandler$MethodToHash_Maps_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps",
	"sun.rmi.server.WeakClassHashMap",
	nullptr,
	nullptr,
	_RemoteObjectInvocationHandler$MethodToHash_Maps_MethodInfo_,
	"Lsun/rmi/server/WeakClassHashMap<Ljava/util/Map<Ljava/lang/reflect/Method;Ljava/lang/Long;>;>;",
	nullptr,
	_RemoteObjectInvocationHandler$MethodToHash_Maps_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.server.RemoteObjectInvocationHandler"
};

$Object* allocate$RemoteObjectInvocationHandler$MethodToHash_Maps($Class* clazz) {
	return $of($alloc(RemoteObjectInvocationHandler$MethodToHash_Maps));
}

void RemoteObjectInvocationHandler$MethodToHash_Maps::init$() {
	$WeakClassHashMap::init$();
}

$Object* RemoteObjectInvocationHandler$MethodToHash_Maps::computeValue($Class* remoteClass) {
	return $of($new($RemoteObjectInvocationHandler$MethodToHash_Maps$1, this));
}

RemoteObjectInvocationHandler$MethodToHash_Maps::RemoteObjectInvocationHandler$MethodToHash_Maps() {
}

$Class* RemoteObjectInvocationHandler$MethodToHash_Maps::load$($String* name, bool initialize) {
	$loadClass(RemoteObjectInvocationHandler$MethodToHash_Maps, name, initialize, &_RemoteObjectInvocationHandler$MethodToHash_Maps_ClassInfo_, allocate$RemoteObjectInvocationHandler$MethodToHash_Maps);
	return class$;
}

$Class* RemoteObjectInvocationHandler$MethodToHash_Maps::class$ = nullptr;

		} // server
	} // rmi
} // java