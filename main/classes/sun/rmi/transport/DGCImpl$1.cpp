#include <sun/rmi/transport/DGCImpl$1.h>

#include <sun/rmi/transport/DGCImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCImpl$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/DGCImpl;", nullptr, $FINAL | $SYNTHETIC, $field(DGCImpl$1, this$0)},
	{}
};

$MethodInfo _DGCImpl$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCImpl;)V", nullptr, 0, $method(static_cast<void(DGCImpl$1::*)($DGCImpl*)>(&DGCImpl$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _DGCImpl$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.DGCImpl",
	"dirty",
	"([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/Lease;)Ljava/rmi/dgc/Lease;"
};

$InnerClassInfo _DGCImpl$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCImpl$1",
	"java.lang.Object",
	"java.lang.Runnable",
	_DGCImpl$1_FieldInfo_,
	_DGCImpl$1_MethodInfo_,
	nullptr,
	&_DGCImpl$1_EnclosingMethodInfo_,
	_DGCImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCImpl"
};

$Object* allocate$DGCImpl$1($Class* clazz) {
	return $of($alloc(DGCImpl$1));
}

void DGCImpl$1::init$($DGCImpl* this$0) {
	$set(this, this$0, this$0);
}

void DGCImpl$1::run() {
	this->this$0->checkLeases();
}

DGCImpl$1::DGCImpl$1() {
}

$Class* DGCImpl$1::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$1, name, initialize, &_DGCImpl$1_ClassInfo_, allocate$DGCImpl$1);
	return class$;
}

$Class* DGCImpl$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun