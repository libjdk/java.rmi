#include <sun/rmi/runtime/RuntimeUtil$1.h>

#include <java/lang/Runnable.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/runtime/RuntimeUtil.h>
#include <jcpp.h>

#undef WARNING

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $RuntimeUtil = ::sun::rmi::runtime::RuntimeUtil;

namespace sun {
	namespace rmi {
		namespace runtime {

$FieldInfo _RuntimeUtil$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/runtime/RuntimeUtil;", nullptr, $FINAL | $SYNTHETIC, $field(RuntimeUtil$1, this$0)},
	{"count", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $FINAL, $field(RuntimeUtil$1, count)},
	{}
};

$MethodInfo _RuntimeUtil$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/runtime/RuntimeUtil;)V", nullptr, 0, $method(static_cast<void(RuntimeUtil$1::*)($RuntimeUtil*)>(&RuntimeUtil$1::init$))},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RuntimeUtil$1_EnclosingMethodInfo_ = {
	"sun.rmi.runtime.RuntimeUtil",
	"<init>",
	"()V"
};

$InnerClassInfo _RuntimeUtil$1_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.RuntimeUtil$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RuntimeUtil$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.RuntimeUtil$1",
	"java.lang.Object",
	"java.util.concurrent.ThreadFactory",
	_RuntimeUtil$1_FieldInfo_,
	_RuntimeUtil$1_MethodInfo_,
	nullptr,
	&_RuntimeUtil$1_EnclosingMethodInfo_,
	_RuntimeUtil$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.RuntimeUtil"
};

$Object* allocate$RuntimeUtil$1($Class* clazz) {
	return $of($alloc(RuntimeUtil$1));
}

void RuntimeUtil$1::init$($RuntimeUtil* this$0) {
	$set(this, this$0, this$0);
	$set(this, count, $new($AtomicInteger));
}

$Thread* RuntimeUtil$1::newThread($Runnable* runnable) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		return $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, runnable, $$str({"Scheduler("_s, $$str($nc(this->count)->getAndIncrement()), ")"_s}), true))));
	} catch ($Throwable& t) {
		$init($RuntimeUtil);
		$init($Level);
		$nc($RuntimeUtil::runtimeLog)->log($Level::WARNING, "scheduler thread factory throws"_s, t);
		return nullptr;
	}
	$shouldNotReachHere();
}

RuntimeUtil$1::RuntimeUtil$1() {
}

$Class* RuntimeUtil$1::load$($String* name, bool initialize) {
	$loadClass(RuntimeUtil$1, name, initialize, &_RuntimeUtil$1_ClassInfo_, allocate$RuntimeUtil$1);
	return class$;
}

$Class* RuntimeUtil$1::class$ = nullptr;

		} // runtime
	} // rmi
} // sun