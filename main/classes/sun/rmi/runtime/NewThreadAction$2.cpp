#include <sun/rmi/runtime/NewThreadAction$2.h>

#include <java/lang/ThreadGroup.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _NewThreadAction$2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(NewThreadAction$2::*)()>(&NewThreadAction$2::init$))},
	{"run", "()Ljava/lang/ThreadGroup;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _NewThreadAction$2_EnclosingMethodInfo_ = {
	"sun.rmi.runtime.NewThreadAction",
	nullptr,
	nullptr
};

$InnerClassInfo _NewThreadAction$2_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.NewThreadAction$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NewThreadAction$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.NewThreadAction$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_NewThreadAction$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/ThreadGroup;>;",
	&_NewThreadAction$2_EnclosingMethodInfo_,
	_NewThreadAction$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.NewThreadAction"
};

$Object* allocate$NewThreadAction$2($Class* clazz) {
	return $of($alloc(NewThreadAction$2));
}

void NewThreadAction$2::init$() {
}

$Object* NewThreadAction$2::run() {
	$init($NewThreadAction);
	return $of($new($ThreadGroup, $NewThreadAction::systemThreadGroup, "RMI Runtime"_s));
}

NewThreadAction$2::NewThreadAction$2() {
}

$Class* NewThreadAction$2::load$($String* name, bool initialize) {
	$loadClass(NewThreadAction$2, name, initialize, &_NewThreadAction$2_ClassInfo_, allocate$NewThreadAction$2);
	return class$;
}

$Class* NewThreadAction$2::class$ = nullptr;

		} // runtime
	} // rmi
} // sun