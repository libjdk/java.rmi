#include <sun/rmi/transport/DGCImpl.h>

#include <java/io/ObjectInputFilter$Config.h>
#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/dgc/Lease.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/LogStream.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RemoteServer.h>
#include <java/rmi/server/ServerNotActiveException.h>
#include <java/rmi/server/UID.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Security.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/RuntimeUtil$GetInstanceAction.h>
#include <sun/rmi/runtime/RuntimeUtil.h>
#include <sun/rmi/transport/DGCImpl$1.h>
#include <sun/rmi/transport/DGCImpl$2.h>
#include <sun/rmi/transport/DGCImpl$LeaseInfo.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/Target.h>
#include <jcpp.h>

#undef ALLOWED
#undef BRIEF
#undef DGC_FILTER_PROPNAME
#undef DGC_MAX_ARRAY_SIZE
#undef DGC_MAX_DEPTH
#undef MILLISECONDS
#undef REJECTED
#undef UNDECIDED
#undef VERBOSE

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$Config = ::java::io::ObjectInputFilter$Config;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $Serializable = ::java::io::Serializable;
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
using $DGC = ::java::rmi::dgc::DGC;
using $Lease = ::java::rmi::dgc::Lease;
using $VMID = ::java::rmi::dgc::VMID;
using $LogStream = ::java::rmi::server::LogStream;
using $ObjID = ::java::rmi::server::ObjID;
using $RemoteServer = ::java::rmi::server::RemoteServer;
using $ServerNotActiveException = ::java::rmi::server::ServerNotActiveException;
using $UID = ::java::rmi::server::UID;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Security = ::java::security::Security;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Future = ::java::util::concurrent::Future;
using $ScheduledExecutorService = ::java::util::concurrent::ScheduledExecutorService;
using $ScheduledFuture = ::java::util::concurrent::ScheduledFuture;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $RuntimeUtil = ::sun::rmi::runtime::RuntimeUtil;
using $RuntimeUtil$GetInstanceAction = ::sun::rmi::runtime::RuntimeUtil$GetInstanceAction;
using $DGCImpl$1 = ::sun::rmi::transport::DGCImpl$1;
using $DGCImpl$2 = ::sun::rmi::transport::DGCImpl$2;
using $DGCImpl$LeaseInfo = ::sun::rmi::transport::DGCImpl$LeaseInfo;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;
using $Target = ::sun::rmi::transport::Target;

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(DGCImpl$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCImpl::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCImpl$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCImpl$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl$$Lambda$lambda$static$0::*)()>(&DGCImpl$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCImpl$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCImpl$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCImpl$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCImpl$$Lambda$lambda$static$0::class$ = nullptr;

class DGCImpl$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(DGCImpl$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCImpl::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCImpl$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCImpl$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl$$Lambda$lambda$static$1$1::*)()>(&DGCImpl$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCImpl$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCImpl$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCImpl$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCImpl$$Lambda$lambda$static$1$1::class$ = nullptr;

class DGCImpl$$Lambda$lambda$static$2$2 : public $PrivilegedAction {
	$class(DGCImpl$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCImpl::lambda$static$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCImpl$$Lambda$lambda$static$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCImpl$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl$$Lambda$lambda$static$2$2::*)()>(&DGCImpl$$Lambda$lambda$static$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCImpl$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCImpl$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCImpl$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCImpl$$Lambda$lambda$static$2$2::class$ = nullptr;

class DGCImpl$$Lambda$initDgcFilter$3 : public $PrivilegedAction {
	$class(DGCImpl$$Lambda$initDgcFilter$3, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCImpl::initDgcFilter());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCImpl$$Lambda$initDgcFilter$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCImpl$$Lambda$initDgcFilter$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl$$Lambda$initDgcFilter$3::*)()>(&DGCImpl$$Lambda$initDgcFilter$3::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCImpl$$Lambda$initDgcFilter$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCImpl$$Lambda$initDgcFilter$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCImpl$$Lambda$initDgcFilter$3::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$$Lambda$initDgcFilter$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCImpl$$Lambda$initDgcFilter$3::class$ = nullptr;

$FieldInfo _DGCImpl_FieldInfo_[] = {
	{"dgcLog", "Lsun/rmi/runtime/Log;", nullptr, $STATIC | $FINAL, $staticField(DGCImpl, dgcLog)},
	{"leaseValue", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl, leaseValue)},
	{"leaseCheckInterval", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl, leaseCheckInterval)},
	{"scheduler", "Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl, scheduler)},
	{"dgc", "Lsun/rmi/transport/DGCImpl;", nullptr, $PRIVATE | $STATIC, $staticField(DGCImpl, dgc)},
	{"leaseTable", "Ljava/util/Map;", "Ljava/util/Map<Ljava/rmi/dgc/VMID;Lsun/rmi/transport/DGCImpl$LeaseInfo;>;", $PRIVATE, $field(DGCImpl, leaseTable)},
	{"checker", "Ljava/util/concurrent/Future;", "Ljava/util/concurrent/Future<*>;", $PRIVATE, $field(DGCImpl, checker)},
	{"DGC_FILTER_PROPNAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl, DGC_FILTER_PROPNAME)},
	{"DGC_MAX_DEPTH", "I", nullptr, $PRIVATE | $STATIC, $staticField(DGCImpl, DGC_MAX_DEPTH)},
	{"DGC_MAX_ARRAY_SIZE", "I", nullptr, $PRIVATE | $STATIC, $staticField(DGCImpl, DGC_MAX_ARRAY_SIZE)},
	{"dgcFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl, dgcFilter)},
	{}
};

$MethodInfo _DGCImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(DGCImpl::*)()>(&DGCImpl::init$))},
	{"checkInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ObjectInputFilter$Status*(*)($ObjectInputFilter$FilterInfo*)>(&DGCImpl::checkInput))},
	{"checkLeases", "()V", nullptr, $PRIVATE, $method(static_cast<void(DGCImpl::*)()>(&DGCImpl::checkLeases))},
	{"clean", "([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/VMID;Z)V", nullptr, $PUBLIC},
	{"dirty", "([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/Lease;)Ljava/rmi/dgc/Lease;", nullptr, $PUBLIC},
	{"getDGCImpl", "()Lsun/rmi/transport/DGCImpl;", nullptr, $STATIC, $method(static_cast<DGCImpl*(*)()>(&DGCImpl::getDGCImpl))},
	{"initDgcFilter", "()Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ObjectInputFilter*(*)()>(&DGCImpl::initDgcFilter))},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&DGCImpl::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&DGCImpl::lambda$static$1))},
	{"lambda$static$2", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&DGCImpl::lambda$static$2))},
	{"registerTarget", "(Ljava/rmi/dgc/VMID;Lsun/rmi/transport/Target;)V", nullptr, 0, $method(static_cast<void(DGCImpl::*)($VMID*,$Target*)>(&DGCImpl::registerTarget))},
	{"unregisterTarget", "(Ljava/rmi/dgc/VMID;Lsun/rmi/transport/Target;)V", nullptr, 0, $method(static_cast<void(DGCImpl::*)($VMID*,$Target*)>(&DGCImpl::unregisterTarget))},
	{}
};

$InnerClassInfo _DGCImpl_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCImpl$LeaseInfo", "sun.rmi.transport.DGCImpl", "LeaseInfo", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCImpl$2", nullptr, nullptr, 0},
	{"sun.rmi.transport.DGCImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCImpl_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.rmi.transport.DGCImpl",
	"java.lang.Object",
	"java.rmi.dgc.DGC",
	_DGCImpl_FieldInfo_,
	_DGCImpl_MethodInfo_,
	nullptr,
	nullptr,
	_DGCImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCImpl$LeaseInfo,sun.rmi.transport.DGCImpl$2,sun.rmi.transport.DGCImpl$2$1,sun.rmi.transport.DGCImpl$1"
};

$Object* allocate$DGCImpl($Class* clazz) {
	return $of($alloc(DGCImpl));
}

$Log* DGCImpl::dgcLog = nullptr;
int64_t DGCImpl::leaseValue = 0;
int64_t DGCImpl::leaseCheckInterval = 0;
$ScheduledExecutorService* DGCImpl::scheduler = nullptr;
DGCImpl* DGCImpl::dgc = nullptr;
$String* DGCImpl::DGC_FILTER_PROPNAME = nullptr;
int32_t DGCImpl::DGC_MAX_DEPTH = 0;
int32_t DGCImpl::DGC_MAX_ARRAY_SIZE = 0;
$ObjectInputFilter* DGCImpl::dgcFilter = nullptr;

DGCImpl* DGCImpl::getDGCImpl() {
	$init(DGCImpl);
	return DGCImpl::dgc;
}

$ObjectInputFilter* DGCImpl::initDgcFilter() {
	$init(DGCImpl);
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputFilter, filter, nullptr);
	$var($String, props, $System::getProperty(DGCImpl::DGC_FILTER_PROPNAME));
	if (props == nullptr) {
		$assign(props, $Security::getProperty(DGCImpl::DGC_FILTER_PROPNAME));
	}
	if (props != nullptr) {
		$assign(filter, $ObjectInputFilter$Config::createFilter(props));
		$init($Log);
		if ($nc(DGCImpl::dgcLog)->isLoggable($Log::BRIEF)) {
			$nc(DGCImpl::dgcLog)->log($Log::BRIEF, $$str({"dgcFilter = "_s, filter}));
		}
	}
	return filter;
}

void DGCImpl::init$() {
	$set(this, leaseTable, $new($HashMap));
	$set(this, checker, nullptr);
}

$Lease* DGCImpl::dirty($ObjIDArray* ids, int64_t sequenceNum, $Lease* lease$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Lease, lease, lease$renamed);
	$var($VMID, vmid, $nc(lease)->getVMID());
	int64_t duration = DGCImpl::leaseValue;
	$init($Log);
	if ($nc(DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
		$nc(DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"vmid = "_s, vmid}));
	}
	if (vmid == nullptr) {
		$assign(vmid, $new($VMID));
		if ($nc(DGCImpl::dgcLog)->isLoggable($Log::BRIEF)) {
			$var($String, clientHost, nullptr);
			try {
				$assign(clientHost, $RemoteServer::getClientHost());
			} catch ($ServerNotActiveException& e) {
				$assign(clientHost, "<unknown host>"_s);
			}
			$nc(DGCImpl::dgcLog)->log($Log::BRIEF, $$str({" assigning vmid "_s, vmid, " to client "_s, clientHost}));
		}
	}
	$assign(lease, $new($Lease, vmid, duration));
	$synchronized(this->leaseTable) {
		$var($DGCImpl$LeaseInfo, info, $cast($DGCImpl$LeaseInfo, $nc(this->leaseTable)->get(vmid)));
		if (info == nullptr) {
			$nc(this->leaseTable)->put(vmid, $$new($DGCImpl$LeaseInfo, vmid, duration));
			if (this->checker == nullptr) {
				$init($TimeUnit);
				$set(this, checker, $nc(DGCImpl::scheduler)->scheduleWithFixedDelay($$new($DGCImpl$1, this), DGCImpl::leaseCheckInterval, DGCImpl::leaseCheckInterval, $TimeUnit::MILLISECONDS));
			}
		} else {
			$nc(info)->renew(duration);
		}
	}
	{
		$var($ObjIDArray, arr$, ids);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ObjID, id, arr$->get(i$));
			{
				if ($nc(DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
					$nc(DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"id = "_s, id, ", vmid = "_s, vmid, ", duration = "_s, $$str(duration)}));
				}
				$ObjectTable::referenced(id, sequenceNum, vmid);
			}
		}
	}
	return lease;
}

void DGCImpl::clean($ObjIDArray* ids, int64_t sequenceNum, $VMID* vmid, bool strong) {
	$useLocalCurrentObjectStackCache();
	{
		$var($ObjIDArray, arr$, ids);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ObjID, id, arr$->get(i$));
			{
				$init($Log);
				if ($nc(DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
					$nc(DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"id = "_s, id, ", vmid = "_s, vmid, ", strong = "_s, $$str(strong)}));
				}
				$ObjectTable::unreferenced(id, sequenceNum, vmid, strong);
			}
		}
	}
}

void DGCImpl::registerTarget($VMID* vmid, $Target* target) {
	$synchronized(this->leaseTable) {
		$var($DGCImpl$LeaseInfo, info, $cast($DGCImpl$LeaseInfo, $nc(this->leaseTable)->get(vmid)));
		if (info == nullptr) {
			$nc(target)->vmidDead(vmid);
		} else {
			$nc($nc(info)->notifySet)->add(target);
		}
	}
}

void DGCImpl::unregisterTarget($VMID* vmid, $Target* target) {
	$synchronized(this->leaseTable) {
		$var($DGCImpl$LeaseInfo, info, $cast($DGCImpl$LeaseInfo, $nc(this->leaseTable)->get(vmid)));
		if (info != nullptr) {
			$nc(info->notifySet)->remove(target);
		}
	}
}

void DGCImpl::checkLeases() {
	$useLocalCurrentObjectStackCache();
	int64_t time = $System::currentTimeMillis();
	$var($List, toUnregister, $new($ArrayList));
	$synchronized(this->leaseTable) {
		$var($Iterator, iter, $nc($($nc(this->leaseTable)->values()))->iterator());
		while ($nc(iter)->hasNext()) {
			$var($DGCImpl$LeaseInfo, info, $cast($DGCImpl$LeaseInfo, iter->next()));
			if ($nc(info)->expired(time)) {
				toUnregister->add(info);
				iter->remove();
			}
		}
		if ($nc(this->leaseTable)->isEmpty()) {
			$nc(this->checker)->cancel(false);
			$set(this, checker, nullptr);
		}
	}
	{
		$var($Iterator, i$, toUnregister->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DGCImpl$LeaseInfo, info, $cast($DGCImpl$LeaseInfo, i$->next()));
			{
				{
					$var($Iterator, i$, $nc($nc(info)->notifySet)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Target, target, $cast($Target, i$->next()));
						{
							$nc(target)->vmidDead(info->vmid);
						}
					}
				}
			}
		}
	}
}

$ObjectInputFilter$Status* DGCImpl::checkInput($ObjectInputFilter$FilterInfo* filterInfo) {
	$init(DGCImpl);
	if (DGCImpl::dgcFilter != nullptr) {
		$ObjectInputFilter$Status* status = $nc(DGCImpl::dgcFilter)->checkInput(filterInfo);
		$init($ObjectInputFilter$Status);
		if (status != $ObjectInputFilter$Status::UNDECIDED) {
			return status;
		}
	}
	if ($nc(filterInfo)->depth() > DGCImpl::DGC_MAX_DEPTH) {
		$init($ObjectInputFilter$Status);
		return $ObjectInputFilter$Status::REJECTED;
	}
	$Class* clazz = $nc(filterInfo)->serialClass();
	if (clazz != nullptr) {
		while ($nc(clazz)->isArray()) {
			bool var$0 = filterInfo->arrayLength() >= 0;
			if (var$0 && filterInfo->arrayLength() > DGCImpl::DGC_MAX_ARRAY_SIZE) {
				$init($ObjectInputFilter$Status);
				return $ObjectInputFilter$Status::REJECTED;
			}
			clazz = clazz->getComponentType();
		}
		if ($nc(clazz)->isPrimitive()) {
			$init($ObjectInputFilter$Status);
			return $ObjectInputFilter$Status::ALLOWED;
		}
		$load($ObjID);
		$load($UID);
		$load($VMID);
		$load($Lease);
		$init($ObjectInputFilter$Status);
		return (clazz == $ObjID::class$ || clazz == $UID::class$ || clazz == $VMID::class$ || clazz == $Lease::class$) ? $ObjectInputFilter$Status::ALLOWED : $ObjectInputFilter$Status::REJECTED;
	}
	$init($ObjectInputFilter$Status);
	return $ObjectInputFilter$Status::UNDECIDED;
}

$Long* DGCImpl::lambda$static$2() {
	$init(DGCImpl);
	return $Long::getLong("sun.rmi.dgc.checkInterval"_s, DGCImpl::leaseValue / 2);
}

$Long* DGCImpl::lambda$static$1() {
	$init(DGCImpl);
	return $Long::getLong("java.rmi.dgc.leaseValue"_s, (int64_t)0x000927C0);
}

$String* DGCImpl::lambda$static$0() {
	$init(DGCImpl);
	return $System::getProperty("sun.rmi.dgc.logLevel"_s);
}

void clinit$DGCImpl($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DGCImpl::DGC_FILTER_PROPNAME, "sun.rmi.transport.dgcFilter"_s);
	$beforeCallerSensitive();
	$assignStatic(DGCImpl::dgcLog, $Log::getLog("sun.rmi.dgc"_s, "dgc"_s, $LogStream::parseLevel($cast($String, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCImpl$$Lambda$lambda$static$0))))))));
	DGCImpl::leaseValue = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCImpl$$Lambda$lambda$static$1$1)))))))->longValue();
	DGCImpl::leaseCheckInterval = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCImpl$$Lambda$lambda$static$2$2)))))))->longValue();
	$assignStatic(DGCImpl::scheduler, $nc(($cast($RuntimeUtil, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RuntimeUtil$GetInstanceAction)))))))->getScheduler());
	DGCImpl::DGC_MAX_DEPTH = 5;
	DGCImpl::DGC_MAX_ARRAY_SIZE = 10000;
	$assignStatic(DGCImpl::dgcFilter, $cast($ObjectInputFilter, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCImpl$$Lambda$initDgcFilter$3)))));
	{
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($DGCImpl$2)));
	}
}

DGCImpl::DGCImpl() {
}

$Class* DGCImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DGCImpl$$Lambda$lambda$static$0::classInfo$.name)) {
			return DGCImpl$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(DGCImpl$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return DGCImpl$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(DGCImpl$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return DGCImpl$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
		if (name->equals(DGCImpl$$Lambda$initDgcFilter$3::classInfo$.name)) {
			return DGCImpl$$Lambda$initDgcFilter$3::load$(name, initialize);
		}
	}
	$loadClass(DGCImpl, name, initialize, &_DGCImpl_ClassInfo_, clinit$DGCImpl, allocate$DGCImpl);
	return class$;
}

$Class* DGCImpl::class$ = nullptr;

		} // transport
	} // rmi
} // sun