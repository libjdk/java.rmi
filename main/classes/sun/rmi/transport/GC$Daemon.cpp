#include <sun/rmi/transport/GC$Daemon.h>

#include <java/lang/InterruptedException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/transport/GC$Daemon$1.h>
#include <sun/rmi/transport/GC.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $GC = ::sun::rmi::transport::GC;
using $GC$Daemon$1 = ::sun::rmi::transport::GC$Daemon$1;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _GC$Daemon_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(GC$Daemon::*)()>(&GC$Daemon::init$))},
	{"create", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&GC$Daemon::create))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _GC$Daemon_InnerClassesInfo_[] = {
	{"sun.rmi.transport.GC$Daemon", "sun.rmi.transport.GC", "Daemon", $PRIVATE | $STATIC},
	{"sun.rmi.transport.GC$Daemon$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GC$Daemon_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.GC$Daemon",
	"java.lang.Object",
	"java.lang.Runnable",
	nullptr,
	_GC$Daemon_MethodInfo_,
	nullptr,
	nullptr,
	_GC$Daemon_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.GC"
};

$Object* allocate$GC$Daemon($Class* clazz) {
	return $of($alloc(GC$Daemon));
}

void GC$Daemon::init$() {
}

void GC$Daemon::run() {
	for (;;) {
		int64_t l = 0;
		$init($GC);
		$synchronized($GC::lock) {
			l = $GC::latencyTarget;
			if (l == (int64_t)0x7FFFFFFFFFFFFFFF) {
				$assignStatic($GC::daemon, nullptr);
				return;
			}
			int64_t d = $GC::maxObjectInspectionAge();
			if (d >= l) {
				$System::gc();
				d = 0;
			}
			try {
				$nc($of($GC::lock))->wait(l - d);
			} catch ($InterruptedException& x) {
				continue;
			}
		}
	}
}

void GC$Daemon::create() {
	$init(GC$Daemon);
	$beforeCallerSensitive();
	$var($PrivilegedAction, pa, $new($GC$Daemon$1));
	$AccessController::doPrivileged(pa);
}

GC$Daemon::GC$Daemon() {
}

$Class* GC$Daemon::load$($String* name, bool initialize) {
	$loadClass(GC$Daemon, name, initialize, &_GC$Daemon_ClassInfo_, allocate$GC$Daemon);
	return class$;
}

$Class* GC$Daemon::class$ = nullptr;

		} // transport
	} // rmi
} // sun