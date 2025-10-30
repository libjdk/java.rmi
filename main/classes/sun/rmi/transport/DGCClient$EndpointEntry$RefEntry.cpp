#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry.h>

#include <java/lang/AssertionError.h>
#include <java/util/AbstractSet.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <sun/rmi/transport/DGCClient.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractSet = ::java::util::AbstractSet;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $DGCClient = ::sun::rmi::transport::DGCClient;
using $DGCClient$EndpointEntry = ::sun::rmi::transport::DGCClient$EndpointEntry;
using $DGCClient$EndpointEntry$RefEntry$PhantomLiveRef = ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCClient$EndpointEntry$RefEntry_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/DGCClient$EndpointEntry;", nullptr, $FINAL | $SYNTHETIC, $field(DGCClient$EndpointEntry$RefEntry, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(DGCClient$EndpointEntry$RefEntry, $assertionsDisabled)},
	{"ref", "Lsun/rmi/transport/LiveRef;", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry$RefEntry, ref)},
	{"refSet", "Ljava/util/Set;", "Ljava/util/Set<Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;>;", $PRIVATE, $field(DGCClient$EndpointEntry$RefEntry, refSet)},
	{"dirtyFailed", "Z", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry$RefEntry, dirtyFailed)},
	{}
};

$MethodInfo _DGCClient$EndpointEntry$RefEntry_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCClient$EndpointEntry;Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC, $method(static_cast<void(DGCClient$EndpointEntry$RefEntry::*)($DGCClient$EndpointEntry*,$LiveRef*)>(&DGCClient$EndpointEntry$RefEntry::init$))},
	{"addInstanceToRefSet", "(Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC},
	{"getRef", "()Lsun/rmi/transport/LiveRef;", nullptr, $PUBLIC},
	{"hasDirtyFailed", "()Z", nullptr, $PUBLIC},
	{"isRefSetEmpty", "()Z", nullptr, $PUBLIC},
	{"markDirtyFailed", "()V", nullptr, $PUBLIC},
	{"removeInstanceFromRefSet", "(Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _DGCClient$EndpointEntry$RefEntry_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry", "sun.rmi.transport.DGCClient$EndpointEntry", "RefEntry", $PRIVATE},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry$PhantomLiveRef", "sun.rmi.transport.DGCClient$EndpointEntry$RefEntry", "PhantomLiveRef", $PRIVATE},
	{}
};

$ClassInfo _DGCClient$EndpointEntry$RefEntry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry",
	"java.lang.Object",
	nullptr,
	_DGCClient$EndpointEntry$RefEntry_FieldInfo_,
	_DGCClient$EndpointEntry$RefEntry_MethodInfo_,
	nullptr,
	nullptr,
	_DGCClient$EndpointEntry$RefEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient"
};

$Object* allocate$DGCClient$EndpointEntry$RefEntry($Class* clazz) {
	return $of($alloc(DGCClient$EndpointEntry$RefEntry));
}

bool DGCClient$EndpointEntry$RefEntry::$assertionsDisabled = false;

void DGCClient$EndpointEntry$RefEntry::init$($DGCClient$EndpointEntry* this$0, $LiveRef* ref) {
	$set(this, this$0, this$0);
	$set(this, refSet, $new($HashSet, 5));
	this->dirtyFailed = false;
	$set(this, ref, ref);
}

$LiveRef* DGCClient$EndpointEntry$RefEntry::getRef() {
	return this->ref;
}

void DGCClient$EndpointEntry$RefEntry::addInstanceToRefSet($LiveRef* ref) {
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$Thread::holdsLock(this->this$0)) {
		$throwNew($AssertionError);
	}
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$nc(ref)->equals(this->ref)) {
		$throwNew($AssertionError);
	}
	$nc(this->refSet)->add($$new($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, this, ref));
}

void DGCClient$EndpointEntry$RefEntry::removeInstanceFromRefSet($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef* phantom) {
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$Thread::holdsLock(this->this$0)) {
		$throwNew($AssertionError);
	}
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$nc(this->refSet)->contains(phantom)) {
		$throwNew($AssertionError);
	}
	$nc(this->refSet)->remove(phantom);
}

bool DGCClient$EndpointEntry$RefEntry::isRefSetEmpty() {
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$Thread::holdsLock(this->this$0)) {
		$throwNew($AssertionError);
	}
	return $nc(this->refSet)->size() == 0;
}

void DGCClient$EndpointEntry$RefEntry::markDirtyFailed() {
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$Thread::holdsLock(this->this$0)) {
		$throwNew($AssertionError);
	}
	this->dirtyFailed = true;
}

bool DGCClient$EndpointEntry$RefEntry::hasDirtyFailed() {
	if (!DGCClient$EndpointEntry$RefEntry::$assertionsDisabled && !$Thread::holdsLock(this->this$0)) {
		$throwNew($AssertionError);
	}
	return this->dirtyFailed;
}

void clinit$DGCClient$EndpointEntry$RefEntry($Class* class$) {
	$load($DGCClient);
	DGCClient$EndpointEntry$RefEntry::$assertionsDisabled = !$DGCClient::class$->desiredAssertionStatus();
}

DGCClient$EndpointEntry$RefEntry::DGCClient$EndpointEntry$RefEntry() {
}

$Class* DGCClient$EndpointEntry$RefEntry::load$($String* name, bool initialize) {
	$loadClass(DGCClient$EndpointEntry$RefEntry, name, initialize, &_DGCClient$EndpointEntry$RefEntry_ClassInfo_, clinit$DGCClient$EndpointEntry$RefEntry, allocate$DGCClient$EndpointEntry$RefEntry);
	return class$;
}

$Class* DGCClient$EndpointEntry$RefEntry::class$ = nullptr;

		} // transport
	} // rmi
} // sun