#include <sun/rmi/runtime/NewThreadAction$1.h>

#include <java/lang/ThreadGroup.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $PrivilegedAction = ::java::security::PrivilegedAction;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _NewThreadAction$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(NewThreadAction$1::*)()>(&NewThreadAction$1::init$))},
	{"run", "()Ljava/lang/ThreadGroup;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _NewThreadAction$1_EnclosingMethodInfo_ = {
	"sun.rmi.runtime.NewThreadAction",
	nullptr,
	nullptr
};

$InnerClassInfo _NewThreadAction$1_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.NewThreadAction$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NewThreadAction$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.NewThreadAction$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_NewThreadAction$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/ThreadGroup;>;",
	&_NewThreadAction$1_EnclosingMethodInfo_,
	_NewThreadAction$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.NewThreadAction"
};

$Object* allocate$NewThreadAction$1($Class* clazz) {
	return $of($alloc(NewThreadAction$1));
}

void NewThreadAction$1::init$() {
}

$Object* NewThreadAction$1::run() {
	$useLocalCurrentObjectStackCache();
	$var($ThreadGroup, group, $($Thread::currentThread())->getThreadGroup());
	$var($ThreadGroup, parent, nullptr);
	while (($assign(parent, $nc(group)->getParent())) != nullptr) {
		$assign(group, parent);
	}
	return $of(group);
}

NewThreadAction$1::NewThreadAction$1() {
}

$Class* NewThreadAction$1::load$($String* name, bool initialize) {
	$loadClass(NewThreadAction$1, name, initialize, &_NewThreadAction$1_ClassInfo_, allocate$NewThreadAction$1);
	return class$;
}

$Class* NewThreadAction$1::class$ = nullptr;

		} // runtime
	} // rmi
} // sun