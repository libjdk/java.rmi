#include <sun/rmi/transport/GC$Daemon$1.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Runnable.h>
#include <jdk/internal/misc/InnocuousThread.h>
#include <sun/rmi/transport/GC$Daemon.h>
#include <sun/rmi/transport/GC.h>
#include <jcpp.h>

#undef MIN_PRIORITY

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $InnocuousThread = ::jdk::internal::misc::InnocuousThread;
using $GC = ::sun::rmi::transport::GC;
using $GC$Daemon = ::sun::rmi::transport::GC$Daemon;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _GC$Daemon$1_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(GC$Daemon$1, $assertionsDisabled)},
	{}
};

$MethodInfo _GC$Daemon$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(GC$Daemon$1::*)()>(&GC$Daemon$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _GC$Daemon$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.GC$Daemon",
	"create",
	"()V"
};

$InnerClassInfo _GC$Daemon$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.GC$Daemon", "sun.rmi.transport.GC", "Daemon", $PRIVATE | $STATIC},
	{"sun.rmi.transport.GC$Daemon$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GC$Daemon$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.GC$Daemon$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_GC$Daemon$1_FieldInfo_,
	_GC$Daemon$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_GC$Daemon$1_EnclosingMethodInfo_,
	_GC$Daemon$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.GC"
};

$Object* allocate$GC$Daemon$1($Class* clazz) {
	return $of($alloc(GC$Daemon$1));
}

bool GC$Daemon$1::$assertionsDisabled = false;

void GC$Daemon$1::init$() {
}

$Object* GC$Daemon$1::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Thread, t, $InnocuousThread::newSystemThread("RMI GC Daemon"_s, $$new($GC$Daemon)));
	if (!GC$Daemon$1::$assertionsDisabled && !($nc(t)->getContextClassLoader() == nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(t)->setDaemon(true);
	t->setPriority($Thread::MIN_PRIORITY + 1);
	t->start();
	$init($GC);
	$assignStatic($GC::daemon, t);
	return $of(nullptr);
}

void clinit$GC$Daemon$1($Class* class$) {
	$load($GC);
	GC$Daemon$1::$assertionsDisabled = !$GC::class$->desiredAssertionStatus();
}

GC$Daemon$1::GC$Daemon$1() {
}

$Class* GC$Daemon$1::load$($String* name, bool initialize) {
	$loadClass(GC$Daemon$1, name, initialize, &_GC$Daemon$1_ClassInfo_, clinit$GC$Daemon$1, allocate$GC$Daemon$1);
	return class$;
}

$Class* GC$Daemon$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun