#include <sun/rmi/transport/DGCClient$EndpointEntry.h>

#include <java/io/InvalidClassException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/dgc/DGC.h>
#include <java/rmi/dgc/Lease.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$1.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$CleanRequest.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RenewCleanThread.h>
#include <sun/rmi/transport/DGCClient.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/GC$LatencyRequest.h>
#include <sun/rmi/transport/GC.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/Transport.h>
#include <jcpp.h>

#undef BRIEF
#undef MAX_VALUE
#undef MIN_VALUE

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $InvalidClassException = ::java::io::InvalidClassException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $DGC = ::java::rmi::dgc::DGC;
using $Lease = ::java::rmi::dgc::Lease;
using $VMID = ::java::rmi::dgc::VMID;
using $ObjID = ::java::rmi::server::ObjID;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $Util = ::sun::rmi::server::Util;
using $DGCClient = ::sun::rmi::transport::DGCClient;
using $DGCClient$EndpointEntry$1 = ::sun::rmi::transport::DGCClient$EndpointEntry$1;
using $DGCClient$EndpointEntry$CleanRequest = ::sun::rmi::transport::DGCClient$EndpointEntry$CleanRequest;
using $DGCClient$EndpointEntry$RefEntry = ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry;
using $DGCClient$EndpointEntry$RefEntry$PhantomLiveRef = ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;
using $DGCClient$EndpointEntry$RenewCleanThread = ::sun::rmi::transport::DGCClient$EndpointEntry$RenewCleanThread;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $GC = ::sun::rmi::transport::GC;
using $GC$LatencyRequest = ::sun::rmi::transport::GC$LatencyRequest;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $Transport = ::sun::rmi::transport::Transport;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCClient$EndpointEntry_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(DGCClient$EndpointEntry, $assertionsDisabled)},
	{"endpoint", "Lsun/rmi/transport/Endpoint;", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, endpoint)},
	{"dgc", "Ljava/rmi/dgc/DGC;", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, dgc)},
	{"refTable", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/LiveRef;Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;>;", $PRIVATE, $field(DGCClient$EndpointEntry, refTable)},
	{"invalidRefs", "Ljava/util/Set;", "Ljava/util/Set<Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;>;", $PRIVATE, $field(DGCClient$EndpointEntry, invalidRefs)},
	{"removed", "Z", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, removed)},
	{"renewTime", "J", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, renewTime)},
	{"expirationTime", "J", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, expirationTime)},
	{"dirtyFailures", "I", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, dirtyFailures)},
	{"dirtyFailureStartTime", "J", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, dirtyFailureStartTime)},
	{"dirtyFailureDuration", "J", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, dirtyFailureDuration)},
	{"renewCleanThread", "Ljava/lang/Thread;", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, renewCleanThread)},
	{"interruptible", "Z", nullptr, $PRIVATE, $field(DGCClient$EndpointEntry, interruptible)},
	{"refQueue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Lsun/rmi/transport/LiveRef;>;", $PRIVATE, $field(DGCClient$EndpointEntry, refQueue)},
	{"pendingCleans", "Ljava/util/Set;", "Ljava/util/Set<Lsun/rmi/transport/DGCClient$EndpointEntry$CleanRequest;>;", $PRIVATE, $field(DGCClient$EndpointEntry, pendingCleans)},
	{"endpointTable", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/Endpoint;Lsun/rmi/transport/DGCClient$EndpointEntry;>;", $PRIVATE | $STATIC, $staticField(DGCClient$EndpointEntry, endpointTable)},
	{"gcLatencyRequest", "Lsun/rmi/transport/GC$LatencyRequest;", nullptr, $PRIVATE | $STATIC, $staticField(DGCClient$EndpointEntry, gcLatencyRequest)},
	{}
};

$MethodInfo _DGCClient$EndpointEntry_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/Endpoint;)V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry::*)($Endpoint*)>(&DGCClient$EndpointEntry::init$))},
	{"createObjIDArray", "(Ljava/util/Set;)[Ljava/rmi/server/ObjID;", "(Ljava/util/Set<Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;>;)[Ljava/rmi/server/ObjID;", $PRIVATE | $STATIC, $method(static_cast<$ObjIDArray*(*)($Set*)>(&DGCClient$EndpointEntry::createObjIDArray))},
	{"lookup", "(Lsun/rmi/transport/Endpoint;)Lsun/rmi/transport/DGCClient$EndpointEntry;", nullptr, $PUBLIC | $STATIC, $method(static_cast<DGCClient$EndpointEntry*(*)($Endpoint*)>(&DGCClient$EndpointEntry::lookup))},
	{"makeCleanCalls", "()V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry::*)()>(&DGCClient$EndpointEntry::makeCleanCalls))},
	{"makeDirtyCall", "(Ljava/util/Set;J)V", "(Ljava/util/Set<Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;>;J)V", $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry::*)($Set*,int64_t)>(&DGCClient$EndpointEntry::makeDirtyCall))},
	{"processPhantomRefs", "(Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;)V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry::*)($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef*)>(&DGCClient$EndpointEntry::processPhantomRefs))},
	{"registerRefs", "(Ljava/util/List;)Z", "(Ljava/util/List<Lsun/rmi/transport/LiveRef;>;)Z", $PUBLIC},
	{"removeRefEntry", "(Lsun/rmi/transport/DGCClient$EndpointEntry$RefEntry;)V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry::*)($DGCClient$EndpointEntry$RefEntry*)>(&DGCClient$EndpointEntry::removeRefEntry))},
	{"setRenewTime", "(J)V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry::*)(int64_t)>(&DGCClient$EndpointEntry::setRenewTime))},
	{}
};

$InnerClassInfo _DGCClient$EndpointEntry_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RefEntry", "sun.rmi.transport.DGCClient$EndpointEntry", "RefEntry", $PRIVATE},
	{"sun.rmi.transport.DGCClient$EndpointEntry$CleanRequest", "sun.rmi.transport.DGCClient$EndpointEntry", "CleanRequest", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread", "sun.rmi.transport.DGCClient$EndpointEntry", "RenewCleanThread", $PRIVATE},
	{"sun.rmi.transport.DGCClient$EndpointEntry$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCClient$EndpointEntry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCClient$EndpointEntry",
	"java.lang.Object",
	nullptr,
	_DGCClient$EndpointEntry_FieldInfo_,
	_DGCClient$EndpointEntry_MethodInfo_,
	nullptr,
	nullptr,
	_DGCClient$EndpointEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient"
};

$Object* allocate$DGCClient$EndpointEntry($Class* clazz) {
	return $of($alloc(DGCClient$EndpointEntry));
}

bool DGCClient$EndpointEntry::$assertionsDisabled = false;
$Map* DGCClient$EndpointEntry::endpointTable = nullptr;
$GC$LatencyRequest* DGCClient$EndpointEntry::gcLatencyRequest = nullptr;

DGCClient$EndpointEntry* DGCClient$EndpointEntry::lookup($Endpoint* ep) {
	$init(DGCClient$EndpointEntry);
	$synchronized(DGCClient$EndpointEntry::endpointTable) {
		$var(DGCClient$EndpointEntry, entry, $cast(DGCClient$EndpointEntry, $nc(DGCClient$EndpointEntry::endpointTable)->get(ep)));
		if (entry == nullptr) {
			$assign(entry, $new(DGCClient$EndpointEntry, ep));
			$nc(DGCClient$EndpointEntry::endpointTable)->put(ep, entry);
			if (DGCClient$EndpointEntry::gcLatencyRequest == nullptr) {
				$init($DGCClient);
				$assignStatic(DGCClient$EndpointEntry::gcLatencyRequest, $GC::requestLatency($DGCClient::gcInterval));
			}
		}
		return entry;
	}
}

void DGCClient$EndpointEntry::init$($Endpoint* endpoint) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$set(this, refTable, $new($HashMap, 5));
	$set(this, invalidRefs, $new($HashSet, 5));
	this->removed = false;
	this->renewTime = $Long::MAX_VALUE;
	this->expirationTime = $Long::MIN_VALUE;
	this->dirtyFailures = 0;
	this->interruptible = false;
	$set(this, refQueue, $new($ReferenceQueue));
	$set(this, pendingCleans, $new($HashSet, 5));
	$set(this, endpoint, endpoint);
	try {
		$init($DGCClient);
		$var($LiveRef, dgcRef, $new($LiveRef, $DGCClient::dgcID, endpoint, false));
		$load($DGCImpl);
		$set(this, dgc, $cast($DGC, $Util::createProxy($DGCImpl::class$, $$new($UnicastRef, dgcRef), true)));
	} catch ($RemoteException& e) {
		$throwNew($Error, "internal error creating DGC stub"_s);
	}
	$var($Runnable, var$0, static_cast<$Runnable*>($new($DGCClient$EndpointEntry$RenewCleanThread, this)));
	$set(this, renewCleanThread, $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, var$0, $$str({"RenewClean-"_s, endpoint}), true)))));
	$nc(this->renewCleanThread)->start();
}

bool DGCClient$EndpointEntry::registerRefs($List* refs) {
	$useLocalCurrentObjectStackCache();
	if (!DGCClient$EndpointEntry::$assertionsDisabled && ! !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$var($Set, refsToDirty, nullptr);
	int64_t sequenceNum = 0;
	$synchronized(this) {
		if (this->removed) {
			return false;
		}
		$var($Iterator, iter, $nc(refs)->iterator());
		while ($nc(iter)->hasNext()) {
			$var($LiveRef, ref, $cast($LiveRef, iter->next()));
			if (!DGCClient$EndpointEntry::$assertionsDisabled && !$nc($of($($nc(ref)->getEndpoint())))->equals(this->endpoint)) {
				$throwNew($AssertionError);
			}
			$var($DGCClient$EndpointEntry$RefEntry, refEntry, $cast($DGCClient$EndpointEntry$RefEntry, $nc(this->refTable)->get(ref)));
			if (refEntry == nullptr) {
				$var($LiveRef, refClone, $cast($LiveRef, $nc(ref)->clone()));
				$assign(refEntry, $new($DGCClient$EndpointEntry$RefEntry, this, refClone));
				$nc(this->refTable)->put(refClone, refEntry);
				if (refsToDirty == nullptr) {
					$assign(refsToDirty, $new($HashSet, 5));
				}
				$nc(refsToDirty)->add(refEntry);
			}
			$nc(refEntry)->addInstanceToRefSet(ref);
		}
		if (refsToDirty == nullptr) {
			return true;
		}
		$nc(refsToDirty)->addAll(this->invalidRefs);
		$nc(this->invalidRefs)->clear();
		sequenceNum = $DGCClient::getNextSequenceNum();
	}
	makeDirtyCall(refsToDirty, sequenceNum);
	return true;
}

void DGCClient$EndpointEntry::removeRefEntry($DGCClient$EndpointEntry$RefEntry* refEntry) {
	$useLocalCurrentObjectStackCache();
	if (!DGCClient$EndpointEntry::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	if (!DGCClient$EndpointEntry::$assertionsDisabled && ! !this->removed) {
		$throwNew($AssertionError);
	}
	if (!DGCClient$EndpointEntry::$assertionsDisabled && !$nc(this->refTable)->containsKey($($nc(refEntry)->getRef()))) {
		$throwNew($AssertionError);
	}
	$nc(this->refTable)->remove($($nc(refEntry)->getRef()));
	$nc(this->invalidRefs)->remove(refEntry);
	if ($nc(this->refTable)->isEmpty()) {
		$synchronized(DGCClient$EndpointEntry::endpointTable) {
			$nc(DGCClient$EndpointEntry::endpointTable)->remove(this->endpoint);
			$var($Transport, transport, $nc(this->endpoint)->getOutboundTransport());
			$nc(transport)->free(this->endpoint);
			if ($nc(DGCClient$EndpointEntry::endpointTable)->isEmpty()) {
				if (!DGCClient$EndpointEntry::$assertionsDisabled && !(DGCClient$EndpointEntry::gcLatencyRequest != nullptr)) {
					$throwNew($AssertionError);
				}
				$nc(DGCClient$EndpointEntry::gcLatencyRequest)->cancel();
				$assignStatic(DGCClient$EndpointEntry::gcLatencyRequest, nullptr);
			}
			this->removed = true;
		}
	}
}

void DGCClient$EndpointEntry::makeDirtyCall($Set* refEntries, int64_t sequenceNum) {
	$useLocalCurrentObjectStackCache();
	if (!DGCClient$EndpointEntry::$assertionsDisabled && ! !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$var($ObjIDArray, ids, nullptr);
	if (refEntries != nullptr) {
		$assign(ids, createObjIDArray(refEntries));
	} else {
		$init($DGCClient);
		$assign(ids, $DGCClient::emptyObjIDArray);
	}
	int64_t startTime = $System::currentTimeMillis();
	try {
		$init($DGCClient);
		$var($Lease, lease, $nc(this->dgc)->dirty(ids, sequenceNum, $$new($Lease, $DGCClient::vmid, $DGCClient::leaseValue)));
		int64_t duration = $nc(lease)->getValue();
		int64_t newRenewTime = $DGCClient::computeRenewTime(startTime, duration);
		int64_t newExpirationTime = startTime + duration;
		$synchronized(this) {
			this->dirtyFailures = 0;
			setRenewTime(newRenewTime);
			this->expirationTime = newExpirationTime;
		}
	} catch ($Exception& e) {
		int64_t endTime = $System::currentTimeMillis();
		$synchronized(this) {
			++this->dirtyFailures;
			if ($instanceOf($UnmarshalException, e) && $instanceOf($InvalidClassException, $(e->getCause()))) {
				$init($DGCImpl);
				$init($Log);
				$nc($DGCImpl::dgcLog)->log($Log::BRIEF, "InvalidClassException exception in DGC dirty call"_s, e);
				return;
			}
			if (this->dirtyFailures == 1) {
				this->dirtyFailureStartTime = startTime;
				this->dirtyFailureDuration = endTime - startTime;
				setRenewTime(endTime);
			} else {
				int32_t n = this->dirtyFailures - 2;
				if (n == 0) {
					this->dirtyFailureDuration = $Math::max((this->dirtyFailureDuration + (endTime - startTime)) >> 1, (int64_t)1000);
				}
				int64_t newRenewTime = endTime + ($sl(this->dirtyFailureDuration, n));
				$init($DGCClient);
				if (newRenewTime < this->expirationTime || this->dirtyFailures < 5 || newRenewTime < this->dirtyFailureStartTime + $DGCClient::leaseValue) {
					setRenewTime(newRenewTime);
				} else {
					setRenewTime($Long::MAX_VALUE);
				}
			}
			if (refEntries != nullptr) {
				$nc(this->invalidRefs)->addAll(refEntries);
				$var($Iterator, iter, refEntries->iterator());
				while ($nc(iter)->hasNext()) {
					$var($DGCClient$EndpointEntry$RefEntry, refEntry, $cast($DGCClient$EndpointEntry$RefEntry, iter->next()));
					$nc(refEntry)->markDirtyFailed();
				}
			}
			if (this->renewTime >= this->expirationTime) {
				$nc(this->invalidRefs)->addAll($($nc(this->refTable)->values()));
			}
		}
	}
}

void DGCClient$EndpointEntry::setRenewTime(int64_t newRenewTime) {
	$beforeCallerSensitive();
	if (!DGCClient$EndpointEntry::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	if (newRenewTime < this->renewTime) {
		this->renewTime = newRenewTime;
		if (this->interruptible) {
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($DGCClient$EndpointEntry$1, this)));
		}
	} else {
		this->renewTime = newRenewTime;
	}
}

void DGCClient$EndpointEntry::processPhantomRefs($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef* phantom$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, phantom, phantom$renamed);
	if (!DGCClient$EndpointEntry::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$var($Set, strongCleans, nullptr);
	$var($Set, normalCleans, nullptr);
	do {
		$var($DGCClient$EndpointEntry$RefEntry, refEntry, $nc(phantom)->getRefEntry());
		$nc(refEntry)->removeInstanceFromRefSet(phantom);
		if (refEntry->isRefSetEmpty()) {
			if (refEntry->hasDirtyFailed()) {
				if (strongCleans == nullptr) {
					$assign(strongCleans, $new($HashSet, 5));
				}
				$nc(strongCleans)->add(refEntry);
			} else {
				if (normalCleans == nullptr) {
					$assign(normalCleans, $new($HashSet, 5));
				}
				$nc(normalCleans)->add(refEntry);
			}
			removeRefEntry(refEntry);
		}
	} while (($assign(phantom, $cast($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, $nc(this->refQueue)->poll()))) != nullptr);
	if (strongCleans != nullptr) {
		$var($ObjIDArray, var$0, createObjIDArray(strongCleans));
		$nc(this->pendingCleans)->add($$new($DGCClient$EndpointEntry$CleanRequest, var$0, $DGCClient::getNextSequenceNum(), true));
	}
	if (normalCleans != nullptr) {
		$var($ObjIDArray, var$1, createObjIDArray(normalCleans));
		$nc(this->pendingCleans)->add($$new($DGCClient$EndpointEntry$CleanRequest, var$1, $DGCClient::getNextSequenceNum(), false));
	}
}

void DGCClient$EndpointEntry::makeCleanCalls() {
	$useLocalCurrentObjectStackCache();
	if (!DGCClient$EndpointEntry::$assertionsDisabled && ! !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$var($Iterator, iter, $nc(this->pendingCleans)->iterator());
	while ($nc(iter)->hasNext()) {
		$var($DGCClient$EndpointEntry$CleanRequest, request, $cast($DGCClient$EndpointEntry$CleanRequest, iter->next()));
		try {
			$init($DGCClient);
			$nc(this->dgc)->clean($nc(request)->objIDs, request->sequenceNum, $DGCClient::vmid, request->strong);
			iter->remove();
		} catch ($Exception& e) {
			if (++$nc(request)->failures >= 5) {
				iter->remove();
			}
		}
	}
}

$ObjIDArray* DGCClient$EndpointEntry::createObjIDArray($Set* refEntries) {
	$init(DGCClient$EndpointEntry);
	$useLocalCurrentObjectStackCache();
	$var($ObjIDArray, ids, $new($ObjIDArray, $nc(refEntries)->size()));
	$var($Iterator, iter, refEntries->iterator());
	for (int32_t i = 0; i < ids->length; ++i) {
		ids->set(i, $($nc($($nc(($cast($DGCClient$EndpointEntry$RefEntry, $($nc(iter)->next()))))->getRef()))->getObjID()));
	}
	return ids;
}

void clinit$DGCClient$EndpointEntry($Class* class$) {
	$load($DGCClient);
	DGCClient$EndpointEntry::$assertionsDisabled = !$DGCClient::class$->desiredAssertionStatus();
	$assignStatic(DGCClient$EndpointEntry::endpointTable, $new($HashMap, 5));
	$assignStatic(DGCClient$EndpointEntry::gcLatencyRequest, nullptr);
}

DGCClient$EndpointEntry::DGCClient$EndpointEntry() {
}

$Class* DGCClient$EndpointEntry::load$($String* name, bool initialize) {
	$loadClass(DGCClient$EndpointEntry, name, initialize, &_DGCClient$EndpointEntry_ClassInfo_, clinit$DGCClient$EndpointEntry, allocate$DGCClient$EndpointEntry);
	return class$;
}

$Class* DGCClient$EndpointEntry::class$ = nullptr;

		} // transport
	} // rmi
} // sun