#include <sun/rmi/transport/DGCImpl$2$1.h>

#include <java/rmi/Remote.h>
#include <java/rmi/dgc/DGC.h>
#include <java/rmi/server/ObjID.h>
#include <sun/rmi/server/Dispatcher.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/transport/DGCImpl$2.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/Target.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $DGC = ::java::rmi::dgc::DGC;
using $ObjID = ::java::rmi::server::ObjID;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Dispatcher = ::sun::rmi::server::Dispatcher;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $DGCImpl$2 = ::sun::rmi::transport::DGCImpl$2;
using $Target = ::sun::rmi::transport::Target;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCImpl$2$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/DGCImpl$2;", nullptr, $FINAL | $SYNTHETIC, $field(DGCImpl$2$1, this$0)},
	{"val$dgcID", "Ljava/rmi/server/ObjID;", nullptr, $FINAL | $SYNTHETIC, $field(DGCImpl$2$1, val$dgcID)},
	{"val$stub", "Ljava/rmi/Remote;", nullptr, $FINAL | $SYNTHETIC, $field(DGCImpl$2$1, val$stub)},
	{"val$disp", "Lsun/rmi/server/UnicastServerRef;", nullptr, $FINAL | $SYNTHETIC, $field(DGCImpl$2$1, val$disp)},
	{}
};

$MethodInfo _DGCImpl$2$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCImpl$2;Lsun/rmi/server/UnicastServerRef;Ljava/rmi/Remote;Ljava/rmi/server/ObjID;)V", "()V", 0, $method(static_cast<void(DGCImpl$2$1::*)($DGCImpl$2*,$UnicastServerRef*,$Remote*,$ObjID*)>(&DGCImpl$2$1::init$))},
	{"run", "()Lsun/rmi/transport/Target;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _DGCImpl$2$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.DGCImpl$2",
	"run",
	"()Ljava/lang/Void;"
};

$InnerClassInfo _DGCImpl$2$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCImpl$2", nullptr, nullptr, 0},
	{"sun.rmi.transport.DGCImpl$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCImpl$2$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCImpl$2$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_DGCImpl$2$1_FieldInfo_,
	_DGCImpl$2$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Lsun/rmi/transport/Target;>;",
	&_DGCImpl$2$1_EnclosingMethodInfo_,
	_DGCImpl$2$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCImpl"
};

$Object* allocate$DGCImpl$2$1($Class* clazz) {
	return $of($alloc(DGCImpl$2$1));
}

void DGCImpl$2$1::init$($DGCImpl$2* this$0, $UnicastServerRef* val$disp, $Remote* val$stub, $ObjID* val$dgcID) {
	$set(this, this$0, this$0);
	$set(this, val$disp, val$disp);
	$set(this, val$stub, val$stub);
	$set(this, val$dgcID, val$dgcID);
}

$Object* DGCImpl$2$1::run() {
	$init($DGCImpl);
	return $of($new($Target, $DGCImpl::dgc, this->val$disp, this->val$stub, this->val$dgcID, true));
}

DGCImpl$2$1::DGCImpl$2$1() {
}

$Class* DGCImpl$2$1::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$2$1, name, initialize, &_DGCImpl$2$1_ClassInfo_, allocate$DGCImpl$2$1);
	return class$;
}

$Class* DGCImpl$2$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun