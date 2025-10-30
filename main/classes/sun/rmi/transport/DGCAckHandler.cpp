#include <sun/rmi/transport/DGCAckHandler.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/server/UID.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <sun/rmi/runtime/RuntimeUtil$GetInstanceAction.h>
#include <sun/rmi/runtime/RuntimeUtil.h>
#include <sun/rmi/transport/DGCAckHandler$1.h>
#include <jcpp.h>

#undef MILLISECONDS

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
using $UID = ::java::rmi::server::UID;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Future = ::java::util::concurrent::Future;
using $ScheduledExecutorService = ::java::util::concurrent::ScheduledExecutorService;
using $ScheduledFuture = ::java::util::concurrent::ScheduledFuture;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $RuntimeUtil = ::sun::rmi::runtime::RuntimeUtil;
using $RuntimeUtil$GetInstanceAction = ::sun::rmi::runtime::RuntimeUtil$GetInstanceAction;
using $DGCAckHandler$1 = ::sun::rmi::transport::DGCAckHandler$1;

namespace sun {
	namespace rmi {
		namespace transport {

class DGCAckHandler$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(DGCAckHandler$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCAckHandler::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCAckHandler$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCAckHandler$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCAckHandler$$Lambda$lambda$static$0::*)()>(&DGCAckHandler$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCAckHandler$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCAckHandler$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCAckHandler$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(DGCAckHandler$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCAckHandler$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _DGCAckHandler_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(DGCAckHandler, $assertionsDisabled)},
	{"dgcAckTimeout", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCAckHandler, dgcAckTimeout)},
	{"scheduler", "Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCAckHandler, scheduler)},
	{"idTable", "Ljava/util/Map;", "Ljava/util/Map<Ljava/rmi/server/UID;Lsun/rmi/transport/DGCAckHandler;>;", $PRIVATE | $STATIC | $FINAL, $staticField(DGCAckHandler, idTable)},
	{"id", "Ljava/rmi/server/UID;", nullptr, $PRIVATE | $FINAL, $field(DGCAckHandler, id)},
	{"objList", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE, $field(DGCAckHandler, objList)},
	{"task", "Ljava/util/concurrent/Future;", "Ljava/util/concurrent/Future<*>;", $PRIVATE, $field(DGCAckHandler, task)},
	{}
};

$MethodInfo _DGCAckHandler_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/server/UID;)V", nullptr, 0, $method(static_cast<void(DGCAckHandler::*)($UID*)>(&DGCAckHandler::init$))},
	{"add", "(Ljava/lang/Object;)V", nullptr, $SYNCHRONIZED},
	{"lambda$static$0", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&DGCAckHandler::lambda$static$0))},
	{"received", "(Ljava/rmi/server/UID;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($UID*)>(&DGCAckHandler::received))},
	{"release", "()V", nullptr, $SYNCHRONIZED},
	{"startTimer", "()V", nullptr, $SYNCHRONIZED},
	{}
};

$InnerClassInfo _DGCAckHandler_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCAckHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCAckHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.DGCAckHandler",
	"java.lang.Object",
	nullptr,
	_DGCAckHandler_FieldInfo_,
	_DGCAckHandler_MethodInfo_,
	nullptr,
	nullptr,
	_DGCAckHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCAckHandler$1"
};

$Object* allocate$DGCAckHandler($Class* clazz) {
	return $of($alloc(DGCAckHandler));
}

bool DGCAckHandler::$assertionsDisabled = false;
int64_t DGCAckHandler::dgcAckTimeout = 0;
$ScheduledExecutorService* DGCAckHandler::scheduler = nullptr;
$Map* DGCAckHandler::idTable = nullptr;

void DGCAckHandler::init$($UID* id) {
	$set(this, objList, $new($ArrayList));
	$set(this, task, nullptr);
	$set(this, id, id);
	if (id != nullptr) {
		if (!DGCAckHandler::$assertionsDisabled && ! !$nc(DGCAckHandler::idTable)->containsKey(id)) {
			$throwNew($AssertionError);
		}
		$nc(DGCAckHandler::idTable)->put(id, this);
	}
}

void DGCAckHandler::add(Object$* obj) {
	$synchronized(this) {
		if (this->objList != nullptr) {
			$nc(this->objList)->add(obj);
		}
	}
}

void DGCAckHandler::startTimer() {
	$synchronized(this) {
		if (this->objList != nullptr && this->task == nullptr) {
			$init($TimeUnit);
			$set(this, task, $nc(DGCAckHandler::scheduler)->schedule(static_cast<$Runnable*>($$new($DGCAckHandler$1, this)), DGCAckHandler::dgcAckTimeout, $TimeUnit::MILLISECONDS));
		}
	}
}

void DGCAckHandler::release() {
	$synchronized(this) {
		if (this->task != nullptr) {
			$nc(this->task)->cancel(false);
			$set(this, task, nullptr);
		}
		$set(this, objList, nullptr);
	}
}

void DGCAckHandler::received($UID* id) {
	$init(DGCAckHandler);
	$var(DGCAckHandler, h, $cast(DGCAckHandler, $nc(DGCAckHandler::idTable)->remove(id)));
	if (h != nullptr) {
		h->release();
	}
}

$Long* DGCAckHandler::lambda$static$0() {
	$init(DGCAckHandler);
	return $Long::getLong("sun.rmi.dgc.ackTimeout"_s, (int64_t)0x000493E0);
}

void clinit$DGCAckHandler($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	DGCAckHandler::$assertionsDisabled = !DGCAckHandler::class$->desiredAssertionStatus();
	DGCAckHandler::dgcAckTimeout = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCAckHandler$$Lambda$lambda$static$0)))))))->longValue();
	$assignStatic(DGCAckHandler::scheduler, $nc(($cast($RuntimeUtil, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RuntimeUtil$GetInstanceAction)))))))->getScheduler());
	$assignStatic(DGCAckHandler::idTable, $Collections::synchronizedMap($$new($HashMap)));
}

DGCAckHandler::DGCAckHandler() {
}

$Class* DGCAckHandler::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DGCAckHandler$$Lambda$lambda$static$0::classInfo$.name)) {
			return DGCAckHandler$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(DGCAckHandler, name, initialize, &_DGCAckHandler_ClassInfo_, clinit$DGCAckHandler, allocate$DGCAckHandler);
	return class$;
}

$Class* DGCAckHandler::class$ = nullptr;

		} // transport
	} // rmi
} // sun