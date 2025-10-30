#include <sun/rmi/transport/DGCClient$EndpointEntry$RenewCleanThread.h>

#include <java/io/Serializable.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractSet.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <sun/rmi/transport/DGCClient.h>
#include <jcpp.h>

#undef MIN_VALUE
#undef SOCKET_ACC

using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractSet = ::java::util::AbstractSet;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $DGCClient = ::sun::rmi::transport::DGCClient;
using $DGCClient$EndpointEntry = ::sun::rmi::transport::DGCClient$EndpointEntry;
using $DGCClient$EndpointEntry$RefEntry$PhantomLiveRef = ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0 : public $PrivilegedAction {
	$class(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(DGCClient$EndpointEntry$RenewCleanThread* inst, bool needRenewal_, $Set* refsToDirty_, int64_t sequenceNum_) {
		$set(this, inst$, inst);
		this->needRenewal_ = needRenewal_;
		$set(this, refsToDirty_, refsToDirty_);
		this->sequenceNum_ = sequenceNum_;
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$run$0(needRenewal_, refsToDirty_, sequenceNum_));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0>());
	}
	DGCClient$EndpointEntry$RenewCleanThread* inst$ = nullptr;
	bool needRenewal_ = false;
	$Set* refsToDirty_ = nullptr;
	int64_t sequenceNum_ = 0;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::fieldInfos[5] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, inst$)},
	{"needRenewal_", "Z", nullptr, $PUBLIC, $field(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, needRenewal_)},
	{"refsToDirty_", "Ljava/util/Set;", nullptr, $PUBLIC, $field(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, refsToDirty_)},
	{"sequenceNum_", "J", nullptr, $PUBLIC, $field(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, sequenceNum_)},
	{}
};
$MethodInfo DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::methodInfos[3] = {
	{"<init>", "(Lsun/rmi/transport/DGCClient$EndpointEntry$RenewCleanThread;ZLjava/util/Set;J)V", nullptr, $PUBLIC, $method(static_cast<void(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::*)(DGCClient$EndpointEntry$RenewCleanThread*,bool,$Set*,int64_t)>(&DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::load$($String* name, bool initialize) {
	$loadClass(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::class$ = nullptr;

$FieldInfo _DGCClient$EndpointEntry$RenewCleanThread_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/DGCClient$EndpointEntry;", nullptr, $FINAL | $SYNTHETIC, $field(DGCClient$EndpointEntry$RenewCleanThread, this$0)},
	{}
};

$MethodInfo _DGCClient$EndpointEntry$RenewCleanThread_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCClient$EndpointEntry;)V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient$EndpointEntry$RenewCleanThread::*)($DGCClient$EndpointEntry*)>(&DGCClient$EndpointEntry$RenewCleanThread::init$))},
	{"lambda$run$0", "(ZLjava/util/Set;J)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(DGCClient$EndpointEntry$RenewCleanThread::*)(bool,$Set*,int64_t)>(&DGCClient$EndpointEntry$RenewCleanThread::lambda$run$0))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _DGCClient$EndpointEntry$RenewCleanThread_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread", "sun.rmi.transport.DGCClient$EndpointEntry", "RenewCleanThread", $PRIVATE},
	{}
};

$ClassInfo _DGCClient$EndpointEntry$RenewCleanThread_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread",
	"java.lang.Object",
	"java.lang.Runnable",
	_DGCClient$EndpointEntry$RenewCleanThread_FieldInfo_,
	_DGCClient$EndpointEntry$RenewCleanThread_MethodInfo_,
	nullptr,
	nullptr,
	_DGCClient$EndpointEntry$RenewCleanThread_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient"
};

$Object* allocate$DGCClient$EndpointEntry$RenewCleanThread($Class* clazz) {
	return $of($alloc(DGCClient$EndpointEntry$RenewCleanThread));
}

void DGCClient$EndpointEntry$RenewCleanThread::init$($DGCClient$EndpointEntry* this$0) {
	$set(this, this$0, this$0);
}

void DGCClient$EndpointEntry$RenewCleanThread::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	do {
		int64_t timeToWait = 0;
		$var($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, phantom, nullptr);
		bool needRenewal = false;
		$var($Set, refsToDirty, nullptr);
		int64_t sequenceNum = $Long::MIN_VALUE;
		$synchronized(this->this$0) {
			int64_t timeUntilRenew = this->this$0->renewTime - $System::currentTimeMillis();
			timeToWait = $Math::max(timeUntilRenew, (int64_t)1);
			if (!$nc(this->this$0->pendingCleans)->isEmpty()) {
				$init($DGCClient);
				timeToWait = $Math::min(timeToWait, $DGCClient::cleanInterval);
			}
			this->this$0->interruptible = true;
		}
		try {
			$assign(phantom, $cast($DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, $nc(this->this$0->refQueue)->remove(timeToWait)));
		} catch ($InterruptedException& e) {
		}
		$synchronized(this->this$0) {
			this->this$0->interruptible = false;
			$Thread::interrupted();
			if (phantom != nullptr) {
				this->this$0->processPhantomRefs(phantom);
			}
			int64_t currentTime = $System::currentTimeMillis();
			if (currentTime > this->this$0->renewTime) {
				needRenewal = true;
				if (!$nc(this->this$0->invalidRefs)->isEmpty()) {
					$assign(refsToDirty, this->this$0->invalidRefs);
					$set(this->this$0, invalidRefs, $new($HashSet, 5));
				}
				sequenceNum = $DGCClient::getNextSequenceNum();
			}
		}
		bool needRenewal_ = needRenewal;
		$var($Set, refsToDirty_, refsToDirty);
		int64_t sequenceNum_ = sequenceNum;
		$init($DGCClient);
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0, this, needRenewal_, refsToDirty_, sequenceNum_)), $DGCClient::SOCKET_ACC);
	} while (!this->this$0->removed || !$nc(this->this$0->pendingCleans)->isEmpty());
}

$Void* DGCClient$EndpointEntry$RenewCleanThread::lambda$run$0(bool needRenewal_, $Set* refsToDirty_, int64_t sequenceNum_) {
	if (needRenewal_) {
		this->this$0->makeDirtyCall(refsToDirty_, sequenceNum_);
	}
	if (!$nc(this->this$0->pendingCleans)->isEmpty()) {
		this->this$0->makeCleanCalls();
	}
	return nullptr;
}

DGCClient$EndpointEntry$RenewCleanThread::DGCClient$EndpointEntry$RenewCleanThread() {
}

$Class* DGCClient$EndpointEntry$RenewCleanThread::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::classInfo$.name)) {
			return DGCClient$EndpointEntry$RenewCleanThread$$Lambda$lambda$run$0::load$(name, initialize);
		}
	}
	$loadClass(DGCClient$EndpointEntry$RenewCleanThread, name, initialize, &_DGCClient$EndpointEntry$RenewCleanThread_ClassInfo_, allocate$DGCClient$EndpointEntry$RenewCleanThread);
	return class$;
}

$Class* DGCClient$EndpointEntry$RenewCleanThread::class$ = nullptr;

		} // transport
	} // rmi
} // sun