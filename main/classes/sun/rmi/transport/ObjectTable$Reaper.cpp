#include <sun/rmi/transport/ObjectTable$Reaper.h>

#include <java/lang/Error.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/util/Map.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/WeakRef.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $Map = ::java::util::Map;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;
using $Target = ::sun::rmi::transport::Target;
using $WeakRef = ::sun::rmi::transport::WeakRef;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _ObjectTable$Reaper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ObjectTable$Reaper::*)()>(&ObjectTable$Reaper::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ObjectTable$Reaper_InnerClassesInfo_[] = {
	{"sun.rmi.transport.ObjectTable$Reaper", "sun.rmi.transport.ObjectTable", "Reaper", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ObjectTable$Reaper_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.ObjectTable$Reaper",
	"java.lang.Object",
	"java.lang.Runnable",
	nullptr,
	_ObjectTable$Reaper_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectTable$Reaper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.ObjectTable"
};

$Object* allocate$ObjectTable$Reaper($Class* clazz) {
	return $of($alloc(ObjectTable$Reaper));
}

void ObjectTable$Reaper::init$() {
}

void ObjectTable$Reaper::run() {
	$useLocalCurrentObjectStackCache();
	try {
		do {
			$init($ObjectTable);
			$var($WeakRef, weakImpl, $cast($WeakRef, $nc($ObjectTable::reapQueue)->remove()));
			$synchronized($ObjectTable::tableLock) {
				$var($Target, target, $cast($Target, $nc($ObjectTable::implTable)->get(weakImpl)));
				if (target != nullptr) {
					if (!target->isEmpty()) {
						$throwNew($Error, "object with known references collected"_s);
					} else if (target->isPermanent()) {
						$throwNew($Error, "permanent object collected"_s);
					}
					$ObjectTable::removeTarget(target);
				}
			}
		} while (!$Thread::interrupted());
	} catch ($InterruptedException& e) {
	}
}

ObjectTable$Reaper::ObjectTable$Reaper() {
}

$Class* ObjectTable$Reaper::load$($String* name, bool initialize) {
	$loadClass(ObjectTable$Reaper, name, initialize, &_ObjectTable$Reaper_ClassInfo_, allocate$ObjectTable$Reaper);
	return class$;
}

$Class* ObjectTable$Reaper::class$ = nullptr;

		} // transport
	} // rmi
} // sun