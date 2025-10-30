#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps$1.h>

#include <java/lang/reflect/Method.h>
#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps.h>
#include <java/util/WeakHashMap.h>
#include <sun/rmi/server/Util.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Method = ::java::lang::reflect::Method;
using $RemoteObjectInvocationHandler$MethodToHash_Maps = ::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Util = ::sun::rmi::server::Util;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _RemoteObjectInvocationHandler$MethodToHash_Maps$1_FieldInfo_[] = {
	{"this$0", "Ljava/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps;", nullptr, $FINAL | $SYNTHETIC, $field(RemoteObjectInvocationHandler$MethodToHash_Maps$1, this$0)},
	{}
};

$MethodInfo _RemoteObjectInvocationHandler$MethodToHash_Maps$1_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps;)V", nullptr, 0, $method(static_cast<void(RemoteObjectInvocationHandler$MethodToHash_Maps$1::*)($RemoteObjectInvocationHandler$MethodToHash_Maps*)>(&RemoteObjectInvocationHandler$MethodToHash_Maps$1::init$))},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Long;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$EnclosingMethodInfo _RemoteObjectInvocationHandler$MethodToHash_Maps$1_EnclosingMethodInfo_ = {
	"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps",
	"computeValue",
	"(Ljava/lang/Class;)Ljava/util/Map;"
};

$InnerClassInfo _RemoteObjectInvocationHandler$MethodToHash_Maps$1_InnerClassesInfo_[] = {
	{"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps", "java.rmi.server.RemoteObjectInvocationHandler", "MethodToHash_Maps", $PRIVATE | $STATIC},
	{"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RemoteObjectInvocationHandler$MethodToHash_Maps$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps$1",
	"java.util.WeakHashMap",
	nullptr,
	_RemoteObjectInvocationHandler$MethodToHash_Maps$1_FieldInfo_,
	_RemoteObjectInvocationHandler$MethodToHash_Maps$1_MethodInfo_,
	"Ljava/util/WeakHashMap<Ljava/lang/reflect/Method;Ljava/lang/Long;>;",
	&_RemoteObjectInvocationHandler$MethodToHash_Maps$1_EnclosingMethodInfo_,
	_RemoteObjectInvocationHandler$MethodToHash_Maps$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.server.RemoteObjectInvocationHandler"
};

$Object* allocate$RemoteObjectInvocationHandler$MethodToHash_Maps$1($Class* clazz) {
	return $of($alloc(RemoteObjectInvocationHandler$MethodToHash_Maps$1));
}

void RemoteObjectInvocationHandler$MethodToHash_Maps$1::init$($RemoteObjectInvocationHandler$MethodToHash_Maps* this$0) {
	$set(this, this$0, this$0);
	$WeakHashMap::init$();
}

$Object* RemoteObjectInvocationHandler$MethodToHash_Maps$1::get(Object$* key) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Long, hash, $cast($Long, $WeakHashMap::get(key)));
		if (hash == nullptr) {
			$var($Method, method, $cast($Method, key));
			$assign(hash, $Long::valueOf($Util::computeMethodHash(method)));
			put(method, hash);
		}
		return $of(hash);
	}
}

RemoteObjectInvocationHandler$MethodToHash_Maps$1::RemoteObjectInvocationHandler$MethodToHash_Maps$1() {
}

$Class* RemoteObjectInvocationHandler$MethodToHash_Maps$1::load$($String* name, bool initialize) {
	$loadClass(RemoteObjectInvocationHandler$MethodToHash_Maps$1, name, initialize, &_RemoteObjectInvocationHandler$MethodToHash_Maps$1_ClassInfo_, allocate$RemoteObjectInvocationHandler$MethodToHash_Maps$1);
	return class$;
}

$Class* RemoteObjectInvocationHandler$MethodToHash_Maps$1::class$ = nullptr;

		} // server
	} // rmi
} // java