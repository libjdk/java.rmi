#include <sun/rmi/transport/WeakRef.h>

#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/WeakReference.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <jcpp.h>

#undef VERBOSE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $WeakReference = ::java::lang::ref::WeakReference;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _WeakRef_FieldInfo_[] = {
	{"hashValue", "I", nullptr, $PRIVATE, $field(WeakRef, hashValue)},
	{"strongRef", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(WeakRef, strongRef)},
	{}
};

$MethodInfo _WeakRef_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(WeakRef::*)(Object$*)>(&WeakRef::init$))},
	{"<init>", "(Ljava/lang/Object;Ljava/lang/ref/ReferenceQueue;)V", "(Ljava/lang/Object;Ljava/lang/ref/ReferenceQueue<Ljava/lang/Object;>;)V", $PUBLIC, $method(static_cast<void(WeakRef::*)(Object$*,$ReferenceQueue*)>(&WeakRef::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"pin", "()V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setHashValue", "(Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(static_cast<void(WeakRef::*)(Object$*)>(&WeakRef::setHashValue))},
	{"unpin", "()V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$ClassInfo _WeakRef_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.WeakRef",
	"java.lang.ref.WeakReference",
	nullptr,
	_WeakRef_FieldInfo_,
	_WeakRef_MethodInfo_,
	"Ljava/lang/ref/WeakReference<Ljava/lang/Object;>;"
};

$Object* allocate$WeakRef($Class* clazz) {
	return $of($alloc(WeakRef));
}

void WeakRef::init$(Object$* obj) {
	$WeakReference::init$(obj);
	$set(this, strongRef, nullptr);
	setHashValue(obj);
}

void WeakRef::init$(Object$* obj, $ReferenceQueue* q) {
	$WeakReference::init$(obj, q);
	$set(this, strongRef, nullptr);
	setHashValue(obj);
}

void WeakRef::pin() {
	$synchronized(this) {
		if (this->strongRef == nullptr) {
			$set(this, strongRef, get());
			$init($DGCImpl);
			$init($Log);
			if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
				$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"strongRef = "_s, this->strongRef}));
			}
		}
	}
}

void WeakRef::unpin() {
	$synchronized(this) {
		if (this->strongRef != nullptr) {
			$init($DGCImpl);
			$init($Log);
			if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
				$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"strongRef = "_s, this->strongRef}));
			}
			$set(this, strongRef, nullptr);
		}
	}
}

void WeakRef::setHashValue(Object$* obj) {
	if (obj != nullptr) {
		this->hashValue = $System::identityHashCode(obj);
	} else {
		this->hashValue = 0;
	}
}

int32_t WeakRef::hashCode() {
	return this->hashValue;
}

bool WeakRef::equals(Object$* obj) {
	if ($instanceOf(WeakRef, obj)) {
		if ($equals(obj, this)) {
			return true;
		}
		$var($Object, referent, get());
		return (referent != nullptr) && ($equals(referent, $nc(($cast(WeakRef, obj)))->get()));
	} else {
		return false;
	}
}

WeakRef::WeakRef() {
}

$Class* WeakRef::load$($String* name, bool initialize) {
	$loadClass(WeakRef, name, initialize, &_WeakRef_ClassInfo_, allocate$WeakRef);
	return class$;
}

$Class* WeakRef::class$ = nullptr;

		} // transport
	} // rmi
} // sun