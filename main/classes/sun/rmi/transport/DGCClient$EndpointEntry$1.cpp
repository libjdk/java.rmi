#include <sun/rmi/transport/DGCClient$EndpointEntry$1.h>

#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $DGCClient$EndpointEntry = ::sun::rmi::transport::DGCClient$EndpointEntry;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCClient$EndpointEntry$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/DGCClient$EndpointEntry;", nullptr, $FINAL | $SYNTHETIC, $field(DGCClient$EndpointEntry$1, this$0)},
	{}
};

$MethodInfo _DGCClient$EndpointEntry$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCClient$EndpointEntry;)V", nullptr, 0, $method(static_cast<void(DGCClient$EndpointEntry$1::*)($DGCClient$EndpointEntry*)>(&DGCClient$EndpointEntry$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _DGCClient$EndpointEntry$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.DGCClient$EndpointEntry",
	"setRenewTime",
	"(J)V"
};

$InnerClassInfo _DGCClient$EndpointEntry$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCClient$EndpointEntry$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCClient$EndpointEntry$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_DGCClient$EndpointEntry$1_FieldInfo_,
	_DGCClient$EndpointEntry$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_DGCClient$EndpointEntry$1_EnclosingMethodInfo_,
	_DGCClient$EndpointEntry$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient"
};

$Object* allocate$DGCClient$EndpointEntry$1($Class* clazz) {
	return $of($alloc(DGCClient$EndpointEntry$1));
}

void DGCClient$EndpointEntry$1::init$($DGCClient$EndpointEntry* this$0) {
	$set(this, this$0, this$0);
}

$Object* DGCClient$EndpointEntry$1::run() {
	$nc(this->this$0->renewCleanThread)->interrupt();
	return $of(nullptr);
}

DGCClient$EndpointEntry$1::DGCClient$EndpointEntry$1() {
}

$Class* DGCClient$EndpointEntry$1::load$($String* name, bool initialize) {
	$loadClass(DGCClient$EndpointEntry$1, name, initialize, &_DGCClient$EndpointEntry$1_ClassInfo_, allocate$DGCClient$EndpointEntry$1);
	return class$;
}

$Class* DGCClient$EndpointEntry$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun