#include <sun/rmi/transport/ObjectTable.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/rmi/NoSuchObjectException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ExportException.h>
#include <java/rmi/server/ObjID.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/GC$LatencyRequest.h>
#include <sun/rmi/transport/GC.h>
#include <sun/rmi/transport/ObjectEndpoint.h>
#include <sun/rmi/transport/ObjectTable$1.h>
#include <sun/rmi/transport/ObjectTable$Reaper.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/WeakRef.h>
#include <jcpp.h>

#undef VERBOSE

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $NoSuchObjectException = ::java::rmi::NoSuchObjectException;
using $Remote = ::java::rmi::Remote;
using $VMID = ::java::rmi::dgc::VMID;
using $ExportException = ::java::rmi::server::ExportException;
using $ObjID = ::java::rmi::server::ObjID;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $GC = ::sun::rmi::transport::GC;
using $GC$LatencyRequest = ::sun::rmi::transport::GC$LatencyRequest;
using $ObjectEndpoint = ::sun::rmi::transport::ObjectEndpoint;
using $ObjectTable$1 = ::sun::rmi::transport::ObjectTable$1;
using $ObjectTable$Reaper = ::sun::rmi::transport::ObjectTable$Reaper;
using $Target = ::sun::rmi::transport::Target;
using $Transport = ::sun::rmi::transport::Transport;
using $WeakRef = ::sun::rmi::transport::WeakRef;

namespace sun {
	namespace rmi {
		namespace transport {

class ObjectTable$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(ObjectTable$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ObjectTable::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectTable$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectTable$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ObjectTable$$Lambda$lambda$static$0::*)()>(&ObjectTable$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ObjectTable$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.ObjectTable$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ObjectTable$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(ObjectTable$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectTable$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _ObjectTable_FieldInfo_[] = {
	{"gcInterval", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectTable, gcInterval)},
	{"tableLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectTable, tableLock)},
	{"objTable", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/ObjectEndpoint;Lsun/rmi/transport/Target;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectTable, objTable)},
	{"implTable", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/WeakRef;Lsun/rmi/transport/Target;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectTable, implTable)},
	{"keepAliveLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectTable, keepAliveLock)},
	{"keepAliveCount", "I", nullptr, $PRIVATE | $STATIC, $staticField(ObjectTable, keepAliveCount)},
	{"reaper", "Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC, $staticField(ObjectTable, reaper)},
	{"reapQueue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;", $STATIC | $FINAL, $staticField(ObjectTable, reapQueue)},
	{"gcLatencyRequest", "Lsun/rmi/transport/GC$LatencyRequest;", nullptr, $PRIVATE | $STATIC, $staticField(ObjectTable, gcLatencyRequest)},
	{}
};

$MethodInfo _ObjectTable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ObjectTable::*)()>(&ObjectTable::init$))},
	{"decrementKeepAliveCount", "()V", nullptr, $STATIC, $method(static_cast<void(*)()>(&ObjectTable::decrementKeepAliveCount))},
	{"getStub", "(Ljava/rmi/Remote;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Remote*)>(&ObjectTable::getStub)), "java.rmi.NoSuchObjectException"},
	{"getTarget", "(Lsun/rmi/transport/ObjectEndpoint;)Lsun/rmi/transport/Target;", nullptr, $STATIC, $method(static_cast<$Target*(*)($ObjectEndpoint*)>(&ObjectTable::getTarget))},
	{"getTarget", "(Ljava/rmi/Remote;)Lsun/rmi/transport/Target;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Target*(*)($Remote*)>(&ObjectTable::getTarget))},
	{"incrementKeepAliveCount", "()V", nullptr, $STATIC, $method(static_cast<void(*)()>(&ObjectTable::incrementKeepAliveCount))},
	{"lambda$static$0", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&ObjectTable::lambda$static$0))},
	{"putTarget", "(Lsun/rmi/transport/Target;)V", nullptr, $STATIC, $method(static_cast<void(*)($Target*)>(&ObjectTable::putTarget)), "java.rmi.server.ExportException"},
	{"referenced", "(Ljava/rmi/server/ObjID;JLjava/rmi/dgc/VMID;)V", nullptr, $STATIC, $method(static_cast<void(*)($ObjID*,int64_t,$VMID*)>(&ObjectTable::referenced))},
	{"removeTarget", "(Lsun/rmi/transport/Target;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Target*)>(&ObjectTable::removeTarget))},
	{"unexportObject", "(Ljava/rmi/Remote;Z)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($Remote*,bool)>(&ObjectTable::unexportObject)), "java.rmi.NoSuchObjectException"},
	{"unreferenced", "(Ljava/rmi/server/ObjID;JLjava/rmi/dgc/VMID;Z)V", nullptr, $STATIC, $method(static_cast<void(*)($ObjID*,int64_t,$VMID*,bool)>(&ObjectTable::unreferenced))},
	{}
};

$InnerClassInfo _ObjectTable_InnerClassesInfo_[] = {
	{"sun.rmi.transport.ObjectTable$Reaper", "sun.rmi.transport.ObjectTable", "Reaper", $PRIVATE | $STATIC},
	{"sun.rmi.transport.ObjectTable$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ObjectTable_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.transport.ObjectTable",
	"java.lang.Object",
	nullptr,
	_ObjectTable_FieldInfo_,
	_ObjectTable_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectTable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.ObjectTable$Reaper,sun.rmi.transport.ObjectTable$1"
};

$Object* allocate$ObjectTable($Class* clazz) {
	return $of($alloc(ObjectTable));
}

int64_t ObjectTable::gcInterval = 0;
$Object* ObjectTable::tableLock = nullptr;
$Map* ObjectTable::objTable = nullptr;
$Map* ObjectTable::implTable = nullptr;
$Object* ObjectTable::keepAliveLock = nullptr;
int32_t ObjectTable::keepAliveCount = 0;
$Thread* ObjectTable::reaper = nullptr;
$ReferenceQueue* ObjectTable::reapQueue = nullptr;
$GC$LatencyRequest* ObjectTable::gcLatencyRequest = nullptr;

void ObjectTable::init$() {
}

$Target* ObjectTable::getTarget($ObjectEndpoint* oe) {
	$init(ObjectTable);
	$synchronized(ObjectTable::tableLock) {
		return $cast($Target, $nc(ObjectTable::objTable)->get(oe));
	}
}

$Target* ObjectTable::getTarget($Remote* impl) {
	$init(ObjectTable);
	$synchronized(ObjectTable::tableLock) {
		return $cast($Target, $nc(ObjectTable::implTable)->get($$new($WeakRef, impl)));
	}
}

$Remote* ObjectTable::getStub($Remote* impl) {
	$init(ObjectTable);
	$var($Target, target, getTarget(impl));
	if (target == nullptr) {
		$throwNew($NoSuchObjectException, "object not exported"_s);
	} else {
		return $nc(target)->getStub();
	}
}

bool ObjectTable::unexportObject($Remote* obj, bool force) {
	$init(ObjectTable);
	$synchronized(ObjectTable::tableLock) {
		$var($Target, target, getTarget(obj));
		if (target == nullptr) {
			$throwNew($NoSuchObjectException, "object not exported"_s);
		} else if ($nc(target)->unexport(force)) {
			removeTarget(target);
			return true;
		} else {
			return false;
		}
	}
}

void ObjectTable::putTarget($Target* target) {
	$init(ObjectTable);
	$useLocalCurrentObjectStackCache();
	$var($ObjectEndpoint, oe, $nc(target)->getObjectEndpoint());
	$var($WeakRef, weakImpl, target->getWeakImpl());
	$init($DGCImpl);
	$init($Log);
	if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
		$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"add object "_s, oe}));
	}
	$synchronized(ObjectTable::tableLock) {
		if (target->getImpl() != nullptr) {
			if ($nc(ObjectTable::objTable)->containsKey(oe)) {
				$throwNew($ExportException, "internal error: ObjID already in use"_s);
			} else {
				if ($nc(ObjectTable::implTable)->containsKey(weakImpl)) {
					$throwNew($ExportException, "object already exported"_s);
				}
			}
			$nc(ObjectTable::objTable)->put(oe, target);
			$nc(ObjectTable::implTable)->put(weakImpl, target);
			if (!target->isPermanent()) {
				incrementKeepAliveCount();
			}
		}
	}
}

void ObjectTable::removeTarget($Target* target) {
	$init(ObjectTable);
	$useLocalCurrentObjectStackCache();
	$var($ObjectEndpoint, oe, $nc(target)->getObjectEndpoint());
	$var($WeakRef, weakImpl, target->getWeakImpl());
	$init($DGCImpl);
	$init($Log);
	if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
		$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"remove object "_s, oe}));
	}
	$nc(ObjectTable::objTable)->remove(oe);
	$nc(ObjectTable::implTable)->remove(weakImpl);
	target->markRemoved();
}

void ObjectTable::referenced($ObjID* id, int64_t sequenceNum, $VMID* vmid) {
	$init(ObjectTable);
	$useLocalCurrentObjectStackCache();
	$synchronized(ObjectTable::tableLock) {
		$var($ObjectEndpoint, oe, $new($ObjectEndpoint, id, $($Transport::currentTransport())));
		$var($Target, target, $cast($Target, $nc(ObjectTable::objTable)->get(oe)));
		if (target != nullptr) {
			target->referenced(sequenceNum, vmid);
		}
	}
}

void ObjectTable::unreferenced($ObjID* id, int64_t sequenceNum, $VMID* vmid, bool strong) {
	$init(ObjectTable);
	$useLocalCurrentObjectStackCache();
	$synchronized(ObjectTable::tableLock) {
		$var($ObjectEndpoint, oe, $new($ObjectEndpoint, id, $($Transport::currentTransport())));
		$var($Target, target, $cast($Target, $nc(ObjectTable::objTable)->get(oe)));
		if (target != nullptr) {
			target->unreferenced(sequenceNum, vmid, strong);
		}
	}
}

void ObjectTable::incrementKeepAliveCount() {
	$init(ObjectTable);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$synchronized(ObjectTable::keepAliveLock) {
		++ObjectTable::keepAliveCount;
		if (ObjectTable::reaper == nullptr) {
			$assignStatic(ObjectTable::reaper, $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, $$new($ObjectTable$Reaper), "Reaper"_s, false)))));
			$nc(ObjectTable::reaper)->start();
		}
		if (ObjectTable::gcLatencyRequest == nullptr) {
			$assignStatic(ObjectTable::gcLatencyRequest, $GC::requestLatency(ObjectTable::gcInterval));
		}
	}
}

void ObjectTable::decrementKeepAliveCount() {
	$init(ObjectTable);
	$beforeCallerSensitive();
	$synchronized(ObjectTable::keepAliveLock) {
		--ObjectTable::keepAliveCount;
		if (ObjectTable::keepAliveCount == 0) {
			if (!(ObjectTable::reaper != nullptr)) {
				$throwNew($AssertionError);
			}
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ObjectTable$1)));
			$assignStatic(ObjectTable::reaper, nullptr);
			$nc(ObjectTable::gcLatencyRequest)->cancel();
			$assignStatic(ObjectTable::gcLatencyRequest, nullptr);
		}
	}
}

$Long* ObjectTable::lambda$static$0() {
	$init(ObjectTable);
	return $Long::getLong("sun.rmi.dgc.server.gcInterval"_s, (int64_t)0x0036EE80);
}

void clinit$ObjectTable($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	ObjectTable::gcInterval = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ObjectTable$$Lambda$lambda$static$0)))))))->longValue();
	$assignStatic(ObjectTable::tableLock, $new($Object));
	$assignStatic(ObjectTable::objTable, $new($HashMap));
	$assignStatic(ObjectTable::implTable, $new($HashMap));
	$assignStatic(ObjectTable::keepAliveLock, $new($Object));
	ObjectTable::keepAliveCount = 0;
	$assignStatic(ObjectTable::reaper, nullptr);
	$assignStatic(ObjectTable::reapQueue, $new($ReferenceQueue));
	$assignStatic(ObjectTable::gcLatencyRequest, nullptr);
}

ObjectTable::ObjectTable() {
}

$Class* ObjectTable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ObjectTable$$Lambda$lambda$static$0::classInfo$.name)) {
			return ObjectTable$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(ObjectTable, name, initialize, &_ObjectTable_ClassInfo_, clinit$ObjectTable, allocate$ObjectTable);
	return class$;
}

$Class* ObjectTable::class$ = nullptr;

		} // transport
	} // rmi
} // sun