#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps.h>

#include <java/lang/reflect/Method.h>
#include <java/rmi/Remote.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps$1.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/server/WeakClassHashMap.h>
#include <jcpp.h>

using $MethodArray = $Array<::java::lang::reflect::Method>;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Method = ::java::lang::reflect::Method;
using $Remote = ::java::rmi::Remote;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $UnicastServerRef$HashToMethod_Maps$1 = ::sun::rmi::server::UnicastServerRef$HashToMethod_Maps$1;
using $Util = ::sun::rmi::server::Util;
using $WeakClassHashMap = ::sun::rmi::server::WeakClassHashMap;

namespace sun {
	namespace rmi {
		namespace server {

$MethodInfo _UnicastServerRef$HashToMethod_Maps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(UnicastServerRef$HashToMethod_Maps::*)()>(&UnicastServerRef$HashToMethod_Maps::init$))},
	{"computeValue", "(Ljava/lang/Class;)Ljava/util/Map;", "(Ljava/lang/Class<*>;)Ljava/util/Map<Ljava/lang/Long;Ljava/lang/reflect/Method;>;", $PROTECTED},
	{}
};

$InnerClassInfo _UnicastServerRef$HashToMethod_Maps_InnerClassesInfo_[] = {
	{"sun.rmi.server.UnicastServerRef$HashToMethod_Maps", "sun.rmi.server.UnicastServerRef", "HashToMethod_Maps", $PRIVATE | $STATIC},
	{"sun.rmi.server.UnicastServerRef$HashToMethod_Maps$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnicastServerRef$HashToMethod_Maps_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.UnicastServerRef$HashToMethod_Maps",
	"sun.rmi.server.WeakClassHashMap",
	nullptr,
	nullptr,
	_UnicastServerRef$HashToMethod_Maps_MethodInfo_,
	"Lsun/rmi/server/WeakClassHashMap<Ljava/util/Map<Ljava/lang/Long;Ljava/lang/reflect/Method;>;>;",
	nullptr,
	_UnicastServerRef$HashToMethod_Maps_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.UnicastServerRef"
};

$Object* allocate$UnicastServerRef$HashToMethod_Maps($Class* clazz) {
	return $of($alloc(UnicastServerRef$HashToMethod_Maps));
}

void UnicastServerRef$HashToMethod_Maps::init$() {
	$WeakClassHashMap::init$();
}

$Object* UnicastServerRef$HashToMethod_Maps::computeValue($Class* remoteClass) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Map, map, $new($HashMap));
	{
		$Class* cl = remoteClass;
		for (; cl != nullptr; cl = $nc(cl)->getSuperclass()) {
			{
				$var($ClassArray, arr$, cl->getInterfaces());
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$Class* intf = arr$->get(i$);
					{
						$load($Remote);
						if ($Remote::class$->isAssignableFrom(intf)) {
							{
								$var($MethodArray, arr$, $nc(intf)->getMethods());
								int32_t len$ = arr$->length;
								int32_t i$ = 0;
								for (; i$ < len$; ++i$) {
									$var($Method, method, arr$->get(i$));
									{
										$var($Method, m, method);
										$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($UnicastServerRef$HashToMethod_Maps$1, this, m)));
										map->put($($Long::valueOf($Util::computeMethodHash(m))), m);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return $of(map);
}

UnicastServerRef$HashToMethod_Maps::UnicastServerRef$HashToMethod_Maps() {
}

$Class* UnicastServerRef$HashToMethod_Maps::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef$HashToMethod_Maps, name, initialize, &_UnicastServerRef$HashToMethod_Maps_ClassInfo_, allocate$UnicastServerRef$HashToMethod_Maps);
	return class$;
}

$Class* UnicastServerRef$HashToMethod_Maps::class$ = nullptr;

		} // server
	} // rmi
} // sun