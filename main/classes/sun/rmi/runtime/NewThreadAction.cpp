#include <sun/rmi/runtime/NewThreadAction.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/Runnable.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ThreadGroup.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/runtime/NewThreadAction$1.h>
#include <sun/rmi/runtime/NewThreadAction$2.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef GET_CLASSLOADER_PERMISSION

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $NewThreadAction$1 = ::sun::rmi::runtime::NewThreadAction$1;
using $NewThreadAction$2 = ::sun::rmi::runtime::NewThreadAction$2;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace rmi {
		namespace runtime {

$FieldInfo _NewThreadAction_FieldInfo_[] = {
	{"systemThreadGroup", "Ljava/lang/ThreadGroup;", nullptr, $STATIC | $FINAL, $staticField(NewThreadAction, systemThreadGroup)},
	{"userThreadGroup", "Ljava/lang/ThreadGroup;", nullptr, $STATIC | $FINAL, $staticField(NewThreadAction, userThreadGroup)},
	{"group", "Ljava/lang/ThreadGroup;", nullptr, $PRIVATE | $FINAL, $field(NewThreadAction, group)},
	{"runnable", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(NewThreadAction, runnable)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(NewThreadAction, name)},
	{"daemon", "Z", nullptr, $PRIVATE | $FINAL, $field(NewThreadAction, daemon)},
	{}
};

$MethodInfo _NewThreadAction_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ThreadGroup;Ljava/lang/Runnable;Ljava/lang/String;Z)V", nullptr, 0, $method(static_cast<void(NewThreadAction::*)($ThreadGroup*,$Runnable*,$String*,bool)>(&NewThreadAction::init$))},
	{"<init>", "(Ljava/lang/Runnable;Ljava/lang/String;Z)V", nullptr, $PUBLIC, $method(static_cast<void(NewThreadAction::*)($Runnable*,$String*,bool)>(&NewThreadAction::init$))},
	{"<init>", "(Ljava/lang/Runnable;Ljava/lang/String;ZZ)V", nullptr, $PUBLIC, $method(static_cast<void(NewThreadAction::*)($Runnable*,$String*,bool,bool)>(&NewThreadAction::init$))},
	{"run", "()Ljava/lang/Thread;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _NewThreadAction_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.NewThreadAction$2", nullptr, nullptr, 0},
	{"sun.rmi.runtime.NewThreadAction$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _NewThreadAction_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.runtime.NewThreadAction",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_NewThreadAction_FieldInfo_,
	_NewThreadAction_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Thread;>;",
	nullptr,
	_NewThreadAction_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.runtime.NewThreadAction$2,sun.rmi.runtime.NewThreadAction$1"
};

$Object* allocate$NewThreadAction($Class* clazz) {
	return $of($alloc(NewThreadAction));
}

$ThreadGroup* NewThreadAction::systemThreadGroup = nullptr;
$ThreadGroup* NewThreadAction::userThreadGroup = nullptr;

void NewThreadAction::init$($ThreadGroup* group, $Runnable* runnable, $String* name, bool daemon) {
	$set(this, group, group);
	$set(this, runnable, runnable);
	$set(this, name, name);
	this->daemon = daemon;
}

void NewThreadAction::init$($Runnable* runnable, $String* name, bool daemon) {
	NewThreadAction::init$(NewThreadAction::systemThreadGroup, runnable, name, daemon);
}

void NewThreadAction::init$($Runnable* runnable, $String* name, bool daemon, bool user) {
	NewThreadAction::init$(user ? NewThreadAction::userThreadGroup : NewThreadAction::systemThreadGroup, runnable, name, daemon);
}

$Object* NewThreadAction::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($SecurityConstants);
		sm->checkPermission($SecurityConstants::GET_CLASSLOADER_PERMISSION);
	}
	$var($Thread, t, $new($Thread, this->group, this->runnable, $$str({"RMI "_s, this->name})));
	t->setContextClassLoader($($ClassLoader::getSystemClassLoader()));
	t->setDaemon(this->daemon);
	return $of(t);
}

void clinit$NewThreadAction($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$assignStatic(NewThreadAction::systemThreadGroup, $cast($ThreadGroup, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction$1)))));
	$assignStatic(NewThreadAction::userThreadGroup, $cast($ThreadGroup, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction$2)))));
}

NewThreadAction::NewThreadAction() {
}

$Class* NewThreadAction::load$($String* name, bool initialize) {
	$loadClass(NewThreadAction, name, initialize, &_NewThreadAction_ClassInfo_, clinit$NewThreadAction, allocate$NewThreadAction);
	return class$;
}

$Class* NewThreadAction::class$ = nullptr;

		} // runtime
	} // rmi
} // sun