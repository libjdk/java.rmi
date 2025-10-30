#include <sun/rmi/transport/GC$LatencyLock.h>

#include <sun/rmi/transport/GC.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GC = ::sun::rmi::transport::GC;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _GC$LatencyLock_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(GC$LatencyLock::*)()>(&GC$LatencyLock::init$))},
	{}
};

$InnerClassInfo _GC$LatencyLock_InnerClassesInfo_[] = {
	{"sun.rmi.transport.GC$LatencyLock", "sun.rmi.transport.GC", "LatencyLock", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _GC$LatencyLock_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.GC$LatencyLock",
	"java.lang.Object",
	nullptr,
	nullptr,
	_GC$LatencyLock_MethodInfo_,
	nullptr,
	nullptr,
	_GC$LatencyLock_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.GC"
};

$Object* allocate$GC$LatencyLock($Class* clazz) {
	return $of($alloc(GC$LatencyLock));
}

void GC$LatencyLock::init$() {
}

GC$LatencyLock::GC$LatencyLock() {
}

$Class* GC$LatencyLock::load$($String* name, bool initialize) {
	$loadClass(GC$LatencyLock, name, initialize, &_GC$LatencyLock_ClassInfo_, allocate$GC$LatencyLock);
	return class$;
}

$Class* GC$LatencyLock::class$ = nullptr;

		} // transport
	} // rmi
} // sun