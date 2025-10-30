#include <sun/rmi/transport/GC.h>

#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/transport/GC$1.h>
#include <sun/rmi/transport/GC$Daemon.h>
#include <sun/rmi/transport/GC$LatencyLock.h>
#include <sun/rmi/transport/GC$LatencyRequest.h>
#include <jcpp.h>

#undef GC
#undef NO_TARGET

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $GC$1 = ::sun::rmi::transport::GC$1;
using $GC$Daemon = ::sun::rmi::transport::GC$Daemon;
using $GC$LatencyLock = ::sun::rmi::transport::GC$LatencyLock;
using $GC$LatencyRequest = ::sun::rmi::transport::GC$LatencyRequest;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _GC_FieldInfo_[] = {
	{"NO_TARGET", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(GC, NO_TARGET)},
	{"latencyTarget", "J", nullptr, $PRIVATE | $STATIC, $staticField(GC, latencyTarget)},
	{"daemon", "Ljava/lang/Thread;", nullptr, $PRIVATE | $STATIC, $staticField(GC, daemon)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticField(GC, lock)},
	{}
};

$MethodInfo _GC_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(GC::*)()>(&GC::init$))},
	{"currentLatencyTarget", "()J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)()>(&GC::currentLatencyTarget))},
	{"maxObjectInspectionAge", "()J", nullptr, $PUBLIC | $STATIC | $NATIVE, $method(static_cast<int64_t(*)()>(&GC::maxObjectInspectionAge))},
	{"requestLatency", "(J)Lsun/rmi/transport/GC$LatencyRequest;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$GC$LatencyRequest*(*)(int64_t)>(&GC::requestLatency))},
	{"setLatencyTarget", "(J)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)(int64_t)>(&GC::setLatencyTarget))},
	{}
};

#define _METHOD_INDEX_maxObjectInspectionAge 2

$InnerClassInfo _GC_InnerClassesInfo_[] = {
	{"sun.rmi.transport.GC$LatencyRequest", "sun.rmi.transport.GC", "LatencyRequest", $PUBLIC | $STATIC},
	{"sun.rmi.transport.GC$Daemon", "sun.rmi.transport.GC", "Daemon", $PRIVATE | $STATIC},
	{"sun.rmi.transport.GC$LatencyLock", "sun.rmi.transport.GC", "LatencyLock", $PRIVATE | $STATIC},
	{"sun.rmi.transport.GC$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GC_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.GC",
	"java.lang.Object",
	nullptr,
	_GC_FieldInfo_,
	_GC_MethodInfo_,
	nullptr,
	nullptr,
	_GC_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.GC$LatencyRequest,sun.rmi.transport.GC$Daemon,sun.rmi.transport.GC$Daemon$1,sun.rmi.transport.GC$LatencyLock,sun.rmi.transport.GC$1"
};

$Object* allocate$GC($Class* clazz) {
	return $of($alloc(GC));
}

int64_t GC::latencyTarget = 0;
$Thread* GC::daemon = nullptr;
$Object* GC::lock = nullptr;

void GC::init$() {
}

int64_t GC::maxObjectInspectionAge() {
	$init(GC);
	int64_t $ret = 0;
	$prepareNativeStatic(GC, maxObjectInspectionAge, int64_t);
	$ret = $invokeNativeStatic(GC, maxObjectInspectionAge);
	$finishNativeStatic();
	return $ret;
}

void GC::setLatencyTarget(int64_t ms) {
	$init(GC);
	GC::latencyTarget = ms;
	if (GC::daemon == nullptr) {
		$GC$Daemon::create();
	} else {
		$nc($of(GC::lock))->notify();
	}
}

$GC$LatencyRequest* GC::requestLatency(int64_t latency) {
	$init(GC);
	return $new($GC$LatencyRequest, latency);
}

int64_t GC::currentLatencyTarget() {
	$init(GC);
	int64_t t = GC::latencyTarget;
	return (t == GC::NO_TARGET) ? (int64_t)0 : t;
}

void clinit$GC($Class* class$) {
	$beforeCallerSensitive();
	GC::latencyTarget = GC::NO_TARGET;
	$assignStatic(GC::daemon, nullptr);
	$assignStatic(GC::lock, $new($GC$LatencyLock));
	{
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GC$1)));
	}
}

GC::GC() {
}

$Class* GC::load$($String* name, bool initialize) {
	$loadClass(GC, name, initialize, &_GC_ClassInfo_, clinit$GC, allocate$GC);
	return class$;
}

$Class* GC::class$ = nullptr;

		} // transport
	} // rmi
} // sun