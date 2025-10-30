#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef.h>

#include <java/lang/ref/PhantomReference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PhantomReference = ::java::lang::ref::PhantomReference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $DGCClient$EndpointEntry = ::sun::rmi::transport::DGCClient$EndpointEntry;
using $DGCClient$EndpointEntry$RefEntry = ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_FieldInfo_[] = {
	{"this$1", "Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;", nullptr, $FINAL | $SYNTHETIC, $field(DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, this$1)},
	{}
};

$MethodInfo _DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC, $method(static_cast<void(DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::*)($DGCClient$EndpointEntry$RefEntry*,$LiveRef*)>(&DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::init$))},
	{"getRefEntry", "()Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry", "sun.rmi.transport.DGCClient$EndpointEntry", "RefEntry", $PRIVATE},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry$PhantomLiveRef", "sun.rmi.transport.DGCClient$EndpointEntry$RefEntry", "PhantomLiveRef", $PRIVATE},
	{}
};

$ClassInfo _DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry$PhantomLiveRef",
	"java.lang.ref.PhantomReference",
	nullptr,
	_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_FieldInfo_,
	_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_MethodInfo_,
	"Ljava/lang/ref/PhantomReference<Lsun/rmi/transport/LiveRef;>;",
	nullptr,
	_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient"
};

$Object* allocate$DGCClient$EndpointEntry$RefEntry$PhantomLiveRef($Class* clazz) {
	return $of($alloc(DGCClient$EndpointEntry$RefEntry$PhantomLiveRef));
}

void DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::init$($DGCClient$EndpointEntry$RefEntry* this$1, $LiveRef* ref) {
	$set(this, this$1, this$1);
	$PhantomReference::init$(ref, $nc(this$1->this$0)->refQueue);
}

$DGCClient$EndpointEntry$RefEntry* DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::getRefEntry() {
	return this->this$1;
}

DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef() {
}

$Class* DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::load$($String* name, bool initialize) {
	$loadClass(DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, name, initialize, &_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_ClassInfo_, allocate$DGCClient$EndpointEntry$RefEntry$PhantomLiveRef);
	return class$;
}

$Class* DGCClient$EndpointEntry$RefEntry$PhantomLiveRef::class$ = nullptr;

		} // transport
	} // rmi
} // sun