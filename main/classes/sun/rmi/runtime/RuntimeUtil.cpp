#include <sun/rmi/runtime/RuntimeUtil.h>

#include <java/io/Serializable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/RuntimeUtil$1.h>
#include <jcpp.h>

#undef GET_INSTANCE_PERMISSION

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $Log = ::sun::rmi::runtime::Log;
using $RuntimeUtil$1 = ::sun::rmi::runtime::RuntimeUtil$1;

namespace sun {
	namespace rmi {
		namespace runtime {

class RuntimeUtil$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(RuntimeUtil$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(RuntimeUtil::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RuntimeUtil$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RuntimeUtil$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RuntimeUtil$$Lambda$lambda$static$0::*)()>(&RuntimeUtil$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RuntimeUtil$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.runtime.RuntimeUtil$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* RuntimeUtil$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(RuntimeUtil$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RuntimeUtil$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _RuntimeUtil_FieldInfo_[] = {
	{"runtimeLog", "Lsun/rmi/runtime/Log;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RuntimeUtil, runtimeLog)},
	{"schedulerThreads", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RuntimeUtil, schedulerThreads)},
	{"GET_INSTANCE_PERMISSION", "Ljava/security/Permission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RuntimeUtil, GET_INSTANCE_PERMISSION)},
	{"instance", "Lsun/rmi/runtime/RuntimeUtil;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RuntimeUtil, instance)},
	{"scheduler", "Ljava/util/concurrent/ScheduledThreadPoolExecutor;", nullptr, $PRIVATE | $FINAL, $field(RuntimeUtil, scheduler)},
	{}
};

$MethodInfo _RuntimeUtil_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(RuntimeUtil::*)()>(&RuntimeUtil::init$))},
	{"getInstance", "()Lsun/rmi/runtime/RuntimeUtil;", nullptr, $PRIVATE | $STATIC, $method(static_cast<RuntimeUtil*(*)()>(&RuntimeUtil::getInstance))},
	{"getScheduler", "()Ljava/util/concurrent/ScheduledThreadPoolExecutor;", nullptr, $PUBLIC, $method(static_cast<$ScheduledThreadPoolExecutor*(RuntimeUtil::*)()>(&RuntimeUtil::getScheduler))},
	{"lambda$static$0", "()Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)()>(&RuntimeUtil::lambda$static$0))},
	{}
};

$InnerClassInfo _RuntimeUtil_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.RuntimeUtil$GetInstanceAction", "sun.rmi.runtime.RuntimeUtil", "GetInstanceAction", $PUBLIC | $STATIC},
	{"sun.rmi.runtime.RuntimeUtil$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RuntimeUtil_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.runtime.RuntimeUtil",
	"java.lang.Object",
	nullptr,
	_RuntimeUtil_FieldInfo_,
	_RuntimeUtil_MethodInfo_,
	nullptr,
	nullptr,
	_RuntimeUtil_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.runtime.RuntimeUtil$GetInstanceAction,sun.rmi.runtime.RuntimeUtil$1"
};

$Object* allocate$RuntimeUtil($Class* clazz) {
	return $of($alloc(RuntimeUtil));
}

$Log* RuntimeUtil::runtimeLog = nullptr;
int32_t RuntimeUtil::schedulerThreads = 0;
$Permission* RuntimeUtil::GET_INSTANCE_PERMISSION = nullptr;
RuntimeUtil* RuntimeUtil::instance = nullptr;

void RuntimeUtil::init$() {
	$set(this, scheduler, $new($ScheduledThreadPoolExecutor, RuntimeUtil::schedulerThreads, static_cast<$ThreadFactory*>($$new($RuntimeUtil$1, this))));
}

RuntimeUtil* RuntimeUtil::getInstance() {
	$init(RuntimeUtil);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(RuntimeUtil::GET_INSTANCE_PERMISSION);
	}
	return RuntimeUtil::instance;
}

$ScheduledThreadPoolExecutor* RuntimeUtil::getScheduler() {
	return this->scheduler;
}

$Integer* RuntimeUtil::lambda$static$0() {
	$init(RuntimeUtil);
	return $Integer::getInteger("sun.rmi.runtime.schedulerThreads"_s, 1);
}

void clinit$RuntimeUtil($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(RuntimeUtil::runtimeLog, $Log::getLog("sun.rmi.runtime"_s, ($String*)nullptr, false));
	RuntimeUtil::schedulerThreads = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(RuntimeUtil$$Lambda$lambda$static$0)))))))->intValue();
	$assignStatic(RuntimeUtil::GET_INSTANCE_PERMISSION, $new($RuntimePermission, "sun.rmi.runtime.RuntimeUtil.getInstance"_s));
	$assignStatic(RuntimeUtil::instance, $new(RuntimeUtil));
}

RuntimeUtil::RuntimeUtil() {
}

$Class* RuntimeUtil::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RuntimeUtil$$Lambda$lambda$static$0::classInfo$.name)) {
			return RuntimeUtil$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(RuntimeUtil, name, initialize, &_RuntimeUtil_ClassInfo_, clinit$RuntimeUtil, allocate$RuntimeUtil);
	return class$;
}

$Class* RuntimeUtil::class$ = nullptr;

		} // runtime
	} // rmi
} // sun