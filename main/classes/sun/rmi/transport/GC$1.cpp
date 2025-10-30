#include <sun/rmi/transport/GC$1.h>

#include <sun/rmi/transport/GC.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $GC = ::sun::rmi::transport::GC;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _GC$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(GC$1::*)()>(&GC$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _GC$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.GC",
	nullptr,
	nullptr
};

$InnerClassInfo _GC$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.GC$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _GC$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.GC$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_GC$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_GC$1_EnclosingMethodInfo_,
	_GC$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.GC"
};

$Object* allocate$GC$1($Class* clazz) {
	return $of($alloc(GC$1));
}

void GC$1::init$() {
}

$Object* GC$1::run() {
	$beforeCallerSensitive();
	$System::loadLibrary("rmi"_s);
	return $of(nullptr);
}

GC$1::GC$1() {
}

$Class* GC$1::load$($String* name, bool initialize) {
	$loadClass(GC$1, name, initialize, &_GC$1_ClassInfo_, allocate$GC$1);
	return class$;
}

$Class* GC$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun