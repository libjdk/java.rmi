#include <sun/rmi/transport/tcp/TCPTransport$1.h>

#include <java/lang/Runnable.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/ExecutorService.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$MethodInfo _TCPTransport$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(TCPTransport$1::*)()>(&TCPTransport$1::init$))},
	{"newThread", "(Ljava/lang/Runnable;)Ljava/lang/Thread;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _TCPTransport$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.tcp.TCPTransport",
	nullptr,
	nullptr
};

$InnerClassInfo _TCPTransport$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPTransport$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TCPTransport$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.tcp.TCPTransport$1",
	"java.lang.Object",
	"java.util.concurrent.ThreadFactory",
	nullptr,
	_TCPTransport$1_MethodInfo_,
	nullptr,
	&_TCPTransport$1_EnclosingMethodInfo_,
	_TCPTransport$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPTransport"
};

$Object* allocate$TCPTransport$1($Class* clazz) {
	return $of($alloc(TCPTransport$1));
}

void TCPTransport$1::init$() {
}

$Thread* TCPTransport$1::newThread($Runnable* runnable) {
	$beforeCallerSensitive();
	return $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, runnable, "TCP Connection(idle)"_s, true, true))));
}

TCPTransport$1::TCPTransport$1() {
}

$Class* TCPTransport$1::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$1, name, initialize, &_TCPTransport$1_ClassInfo_, allocate$TCPTransport$1);
	return class$;
}

$Class* TCPTransport$1::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun