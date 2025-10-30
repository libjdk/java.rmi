#include <sun/rmi/runtime/RuntimeUtil$GetInstanceAction.h>

#include <sun/rmi/runtime/RuntimeUtil.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $RuntimeUtil = ::sun::rmi::runtime::RuntimeUtil;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _RuntimeUtil$GetInstanceAction_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RuntimeUtil$GetInstanceAction::*)()>(&RuntimeUtil$GetInstanceAction::init$))},
	{"run", "()Lsun/rmi/runtime/RuntimeUtil;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _RuntimeUtil$GetInstanceAction_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.RuntimeUtil$GetInstanceAction", "sun.rmi.runtime.RuntimeUtil", "GetInstanceAction", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _RuntimeUtil$GetInstanceAction_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.runtime.RuntimeUtil$GetInstanceAction",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_RuntimeUtil$GetInstanceAction_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Lsun/rmi/runtime/RuntimeUtil;>;",
	nullptr,
	_RuntimeUtil$GetInstanceAction_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.RuntimeUtil"
};

$Object* allocate$RuntimeUtil$GetInstanceAction($Class* clazz) {
	return $of($alloc(RuntimeUtil$GetInstanceAction));
}

void RuntimeUtil$GetInstanceAction::init$() {
}

$Object* RuntimeUtil$GetInstanceAction::run() {
	return $of($RuntimeUtil::getInstance());
}

RuntimeUtil$GetInstanceAction::RuntimeUtil$GetInstanceAction() {
}

$Class* RuntimeUtil$GetInstanceAction::load$($String* name, bool initialize) {
	$loadClass(RuntimeUtil$GetInstanceAction, name, initialize, &_RuntimeUtil$GetInstanceAction_ClassInfo_, allocate$RuntimeUtil$GetInstanceAction);
	return class$;
}

$Class* RuntimeUtil$GetInstanceAction::class$ = nullptr;

		} // runtime
	} // rmi
} // sun