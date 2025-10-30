#include <sun/rmi/transport/Target.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/rmi/NoSuchObjectException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/Unreferenced.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable.h>
#include <java/util/Vector.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/server/Dispatcher.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/ObjectEndpoint.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/SequenceEntry.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/WeakRef.h>
#include <jcpp.h>

#undef BRIEF
#undef VERBOSE

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
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
using $NoSuchObjectException = ::java::rmi::NoSuchObjectException;
using $Remote = ::java::rmi::Remote;
using $VMID = ::java::rmi::dgc::VMID;
using $ObjID = ::java::rmi::server::ObjID;
using $Unreferenced = ::java::rmi::server::Unreferenced;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable = ::java::util::Hashtable;
using $Vector = ::java::util::Vector;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $Dispatcher = ::sun::rmi::server::Dispatcher;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $ObjectEndpoint = ::sun::rmi::transport::ObjectEndpoint;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;
using $SequenceEntry = ::sun::rmi::transport::SequenceEntry;
using $Transport = ::sun::rmi::transport::Transport;
using $WeakRef = ::sun::rmi::transport::WeakRef;

namespace sun {
	namespace rmi {
		namespace transport {

class Target$$Lambda$lambda$refSetRemove$1 : public $Runnable {
	$class(Target$$Lambda$lambda$refSetRemove$1, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Target* inst, $Unreferenced* unrefObj) {
		$set(this, inst$, inst);
		$set(this, unrefObj, unrefObj);
	}
	virtual void run() override {
		$nc(inst$)->lambda$refSetRemove$1(unrefObj);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Target$$Lambda$lambda$refSetRemove$1>());
	}
	Target* inst$ = nullptr;
	$Unreferenced* unrefObj = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Target$$Lambda$lambda$refSetRemove$1::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Target$$Lambda$lambda$refSetRemove$1, inst$)},
	{"unrefObj", "Ljava/rmi/server/Unreferenced;", nullptr, $PUBLIC, $field(Target$$Lambda$lambda$refSetRemove$1, unrefObj)},
	{}
};
$MethodInfo Target$$Lambda$lambda$refSetRemove$1::methodInfos[3] = {
	{"<init>", "(Lsun/rmi/transport/Target;Ljava/rmi/server/Unreferenced;)V", nullptr, $PUBLIC, $method(static_cast<void(Target$$Lambda$lambda$refSetRemove$1::*)(Target*,$Unreferenced*)>(&Target$$Lambda$lambda$refSetRemove$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Target$$Lambda$lambda$refSetRemove$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.Target$$Lambda$lambda$refSetRemove$1",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Target$$Lambda$lambda$refSetRemove$1::load$($String* name, bool initialize) {
	$loadClass(Target$$Lambda$lambda$refSetRemove$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Target$$Lambda$lambda$refSetRemove$1::class$ = nullptr;

class Target$$Lambda$lambda$refSetRemove$0$1 : public $PrivilegedAction {
	$class(Target$$Lambda$lambda$refSetRemove$0$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Unreferenced* unrefObj) {
		$set(this, unrefObj, unrefObj);
	}
	virtual $Object* run() override {
		 return $of(Target::lambda$refSetRemove$0(unrefObj));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Target$$Lambda$lambda$refSetRemove$0$1>());
	}
	$Unreferenced* unrefObj = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Target$$Lambda$lambda$refSetRemove$0$1::fieldInfos[2] = {
	{"unrefObj", "Ljava/rmi/server/Unreferenced;", nullptr, $PUBLIC, $field(Target$$Lambda$lambda$refSetRemove$0$1, unrefObj)},
	{}
};
$MethodInfo Target$$Lambda$lambda$refSetRemove$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/rmi/server/Unreferenced;)V", nullptr, $PUBLIC, $method(static_cast<void(Target$$Lambda$lambda$refSetRemove$0$1::*)($Unreferenced*)>(&Target$$Lambda$lambda$refSetRemove$0$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Target$$Lambda$lambda$refSetRemove$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.Target$$Lambda$lambda$refSetRemove$0$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Target$$Lambda$lambda$refSetRemove$0$1::load$($String* name, bool initialize) {
	$loadClass(Target$$Lambda$lambda$refSetRemove$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Target$$Lambda$lambda$refSetRemove$0$1::class$ = nullptr;

$FieldInfo _Target_FieldInfo_[] = {
	{"id", "Ljava/rmi/server/ObjID;", nullptr, $PRIVATE | $FINAL, $field(Target, id)},
	{"permanent", "Z", nullptr, $PRIVATE | $FINAL, $field(Target, permanent)},
	{"weakImpl", "Lsun/rmi/transport/WeakRef;", nullptr, $PRIVATE | $FINAL, $field(Target, weakImpl)},
	{"disp", "Lsun/rmi/server/Dispatcher;", nullptr, $PRIVATE | $VOLATILE, $field(Target, disp)},
	{"stub", "Ljava/rmi/Remote;", nullptr, $PRIVATE | $FINAL, $field(Target, stub)},
	{"refSet", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/rmi/dgc/VMID;>;", $PRIVATE | $FINAL, $field(Target, refSet)},
	{"sequenceTable", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/rmi/dgc/VMID;Lsun/rmi/transport/SequenceEntry;>;", $PRIVATE | $FINAL, $field(Target, sequenceTable)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(Target, acc)},
	{"ccl", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(Target, ccl)},
	{"callCount", "I", nullptr, $PRIVATE, $field(Target, callCount)},
	{"removed", "Z", nullptr, $PRIVATE, $field(Target, removed)},
	{"exportedTransport", "Lsun/rmi/transport/Transport;", nullptr, $PRIVATE | $VOLATILE, $field(Target, exportedTransport)},
	{"nextThreadNum", "I", nullptr, $PRIVATE | $STATIC, $staticField(Target, nextThreadNum)},
	{}
};

$MethodInfo _Target_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/Remote;Lsun/rmi/server/Dispatcher;Ljava/rmi/Remote;Ljava/rmi/server/ObjID;Z)V", nullptr, $PUBLIC, $method(static_cast<void(Target::*)($Remote*,$Dispatcher*,$Remote*,$ObjID*,bool)>(&Target::init$))},
	{"checkLoaderAncestry", "(Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($ClassLoader*,$ClassLoader*)>(&Target::checkLoaderAncestry))},
	{"decrementCallCount", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)()>(&Target::decrementCallCount))},
	{"getAccessControlContext", "()Ljava/security/AccessControlContext;", nullptr, 0, $method(static_cast<$AccessControlContext*(Target::*)()>(&Target::getAccessControlContext))},
	{"getContextClassLoader", "()Ljava/lang/ClassLoader;", nullptr, 0, $method(static_cast<$ClassLoader*(Target::*)()>(&Target::getContextClassLoader))},
	{"getDispatcher", "()Lsun/rmi/server/Dispatcher;", nullptr, 0, $method(static_cast<$Dispatcher*(Target::*)()>(&Target::getDispatcher))},
	{"getImpl", "()Ljava/rmi/Remote;", nullptr, 0, $method(static_cast<$Remote*(Target::*)()>(&Target::getImpl))},
	{"getObjectEndpoint", "()Lsun/rmi/transport/ObjectEndpoint;", nullptr, 0, $method(static_cast<$ObjectEndpoint*(Target::*)()>(&Target::getObjectEndpoint))},
	{"getStub", "()Ljava/rmi/Remote;", nullptr, $PUBLIC, $method(static_cast<$Remote*(Target::*)()>(&Target::getStub))},
	{"getWeakImpl", "()Lsun/rmi/transport/WeakRef;", nullptr, 0, $method(static_cast<$WeakRef*(Target::*)()>(&Target::getWeakImpl))},
	{"incrementCallCount", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)()>(&Target::incrementCallCount)), "java.rmi.NoSuchObjectException"},
	{"isEmpty", "()Z", nullptr, 0, $method(static_cast<bool(Target::*)()>(&Target::isEmpty))},
	{"isPermanent", "()Z", nullptr, 0, $method(static_cast<bool(Target::*)()>(&Target::isPermanent))},
	{"lambda$refSetRemove$0", "(Ljava/rmi/server/Unreferenced;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)($Unreferenced*)>(&Target::lambda$refSetRemove$0))},
	{"lambda$refSetRemove$1", "(Ljava/rmi/server/Unreferenced;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(Target::*)($Unreferenced*)>(&Target::lambda$refSetRemove$1))},
	{"markRemoved", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)()>(&Target::markRemoved))},
	{"pinImpl", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)()>(&Target::pinImpl))},
	{"refSetRemove", "(Ljava/rmi/dgc/VMID;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(Target::*)($VMID*)>(&Target::refSetRemove))},
	{"referenced", "(JLjava/rmi/dgc/VMID;)V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)(int64_t,$VMID*)>(&Target::referenced))},
	{"setExportedTransport", "(Lsun/rmi/transport/Transport;)V", nullptr, 0, $method(static_cast<void(Target::*)($Transport*)>(&Target::setExportedTransport))},
	{"unexport", "(Z)Z", nullptr, $SYNCHRONIZED, $method(static_cast<bool(Target::*)(bool)>(&Target::unexport))},
	{"unpinImpl", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)()>(&Target::unpinImpl))},
	{"unreferenced", "(JLjava/rmi/dgc/VMID;Z)V", nullptr, $SYNCHRONIZED, $method(static_cast<void(Target::*)(int64_t,$VMID*,bool)>(&Target::unreferenced))},
	{"vmidDead", "(Ljava/rmi/dgc/VMID;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $method(static_cast<void(Target::*)($VMID*)>(&Target::vmidDead))},
	{}
};

$ClassInfo _Target_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.transport.Target",
	"java.lang.Object",
	nullptr,
	_Target_FieldInfo_,
	_Target_MethodInfo_
};

$Object* allocate$Target($Class* clazz) {
	return $of($alloc(Target));
}

int32_t Target::nextThreadNum = 0;

void Target::init$($Remote* impl, $Dispatcher* disp, $Remote* stub, $ObjID* id, bool permanent) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$set(this, refSet, $new($Vector));
	$set(this, sequenceTable, $new($Hashtable, 5));
	this->callCount = 0;
	this->removed = false;
	$set(this, exportedTransport, nullptr);
	$init($ObjectTable);
	$set(this, weakImpl, $new($WeakRef, impl, $ObjectTable::reapQueue));
	$set(this, disp, disp);
	$set(this, stub, stub);
	$set(this, id, id);
	$set(this, acc, $AccessController::getContext());
	$var($ClassLoader, threadContextLoader, $($Thread::currentThread())->getContextClassLoader());
	$var($ClassLoader, serverLoader, $nc($of(impl))->getClass()->getClassLoader());
	if (checkLoaderAncestry(threadContextLoader, serverLoader)) {
		$set(this, ccl, threadContextLoader);
	} else {
		$set(this, ccl, serverLoader);
	}
	this->permanent = permanent;
	if (permanent) {
		pinImpl();
	}
}

bool Target::checkLoaderAncestry($ClassLoader* child, $ClassLoader* ancestor) {
	$init(Target);
	$beforeCallerSensitive();
	if (ancestor == nullptr) {
		return true;
	} else if (child == nullptr) {
		return false;
	} else {
		{
			$var($ClassLoader, parent, child);
			for (; parent != nullptr; $assign(parent, $nc(parent)->getParent())) {
				if (parent == ancestor) {
					return true;
				}
			}
		}
		return false;
	}
}

$Remote* Target::getStub() {
	return this->stub;
}

$ObjectEndpoint* Target::getObjectEndpoint() {
	return $new($ObjectEndpoint, this->id, this->exportedTransport);
}

$WeakRef* Target::getWeakImpl() {
	return this->weakImpl;
}

$Dispatcher* Target::getDispatcher() {
	return this->disp;
}

$AccessControlContext* Target::getAccessControlContext() {
	return this->acc;
}

$ClassLoader* Target::getContextClassLoader() {
	return this->ccl;
}

$Remote* Target::getImpl() {
	return $cast($Remote, $nc(this->weakImpl)->get());
}

bool Target::isPermanent() {
	return this->permanent;
}

void Target::pinImpl() {
	$synchronized(this) {
		$nc(this->weakImpl)->pin();
	}
}

void Target::unpinImpl() {
	$synchronized(this) {
		if (!this->permanent && $nc(this->refSet)->isEmpty()) {
			$nc(this->weakImpl)->unpin();
		}
	}
}

void Target::setExportedTransport($Transport* exportedTransport) {
	if (this->exportedTransport == nullptr) {
		$set(this, exportedTransport, exportedTransport);
	}
}

void Target::referenced(int64_t sequenceNum, $VMID* vmid) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($SequenceEntry, entry, $cast($SequenceEntry, $nc(this->sequenceTable)->get(vmid)));
		if (entry == nullptr) {
			$nc(this->sequenceTable)->put(vmid, $$new($SequenceEntry, sequenceNum));
		} else if ($nc(entry)->sequenceNum < sequenceNum) {
			entry->update(sequenceNum);
		} else {
			return;
		}
		if (!$nc(this->refSet)->contains(vmid)) {
			pinImpl();
			if (getImpl() == nullptr) {
				return;
			}
			$init($DGCImpl);
			$init($Log);
			if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
				$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"add to dirty set: "_s, vmid}));
			}
			$nc(this->refSet)->addElement(vmid);
			$nc($($DGCImpl::getDGCImpl()))->registerTarget(vmid, this);
		}
	}
}

void Target::unreferenced(int64_t sequenceNum, $VMID* vmid, bool strong) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($SequenceEntry, entry, $cast($SequenceEntry, $nc(this->sequenceTable)->get(vmid)));
		if (entry == nullptr || $nc(entry)->sequenceNum > sequenceNum) {
			return;
		} else if (strong) {
			entry->retain(sequenceNum);
		} else if (entry->keep == false) {
			$nc(this->sequenceTable)->remove(vmid);
		}
		$init($DGCImpl);
		$init($Log);
		if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
			$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"remove from dirty set: "_s, vmid}));
		}
		refSetRemove(vmid);
	}
}

void Target::refSetRemove($VMID* vmid) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$nc($($DGCImpl::getDGCImpl()))->unregisterTarget(vmid, this);
		bool var$0 = $nc(this->refSet)->removeElement(vmid);
		if (var$0 && $nc(this->refSet)->isEmpty()) {
			$init($Log);
			if ($nc($DGCImpl::dgcLog)->isLoggable($Log::VERBOSE)) {
				$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, $$str({"reference set is empty: target = "_s, this}));
			}
			$var($Remote, obj, getImpl());
			if ($instanceOf($Unreferenced, obj)) {
				$var($Unreferenced, unrefObj, $cast($Unreferenced, obj));
				$var($String, var$1, "Unreferenced-"_s);
				$nc(($cast($Thread, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, static_cast<$Runnable*>($$new(Target$$Lambda$lambda$refSetRemove$1, this, unrefObj)), $$concat(var$1, $$str(Target::nextThreadNum++)), false, true)))))))->start();
			}
			unpinImpl();
		}
	}
}

bool Target::unexport(bool force) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if ((force == true) || (this->callCount == 0) || (this->disp == nullptr)) {
			$set(this, disp, nullptr);
			unpinImpl();
			$var($DGCImpl, dgc, $DGCImpl::getDGCImpl());
			$var($Enumeration, enum_, $nc(this->refSet)->elements());
			while ($nc(enum_)->hasMoreElements()) {
				$var($VMID, vmid, $cast($VMID, enum_->nextElement()));
				$nc(dgc)->unregisterTarget(vmid, this);
			}
			return true;
		} else {
			return false;
		}
	}
}

void Target::markRemoved() {
	$synchronized(this) {
		if (!(!this->removed)) {
			$throwNew($AssertionError);
		}
		this->removed = true;
		if (!this->permanent && this->callCount == 0) {
			$ObjectTable::decrementKeepAliveCount();
		}
		if (this->exportedTransport != nullptr) {
			$nc(this->exportedTransport)->targetUnexported();
		}
	}
}

void Target::incrementCallCount() {
	$synchronized(this) {
		if (this->disp != nullptr) {
			++this->callCount;
		} else {
			$throwNew($NoSuchObjectException, "object not accepting new calls"_s);
		}
	}
}

void Target::decrementCallCount() {
	$synchronized(this) {
		if (--this->callCount < 0) {
			$throwNew($Error, "internal error: call count less than zero"_s);
		}
		if (!this->permanent && this->removed && this->callCount == 0) {
			$ObjectTable::decrementKeepAliveCount();
		}
	}
}

bool Target::isEmpty() {
	return $nc(this->refSet)->isEmpty();
}

void Target::vmidDead($VMID* vmid) {
	$synchronized(this) {
		$init($DGCImpl);
		$init($Log);
		if ($nc($DGCImpl::dgcLog)->isLoggable($Log::BRIEF)) {
			$nc($DGCImpl::dgcLog)->log($Log::BRIEF, $$str({"removing endpoint "_s, vmid, " from reference set"_s}));
		}
		$nc(this->sequenceTable)->remove(vmid);
		refSetRemove(vmid);
	}
}

void Target::lambda$refSetRemove$1($Unreferenced* unrefObj) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$($Thread::currentThread())->setContextClassLoader(this->ccl);
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Target$$Lambda$lambda$refSetRemove$0$1, unrefObj)), this->acc);
}

$Void* Target::lambda$refSetRemove$0($Unreferenced* unrefObj) {
	$init(Target);
	$nc(unrefObj)->unreferenced();
	return nullptr;
}

void clinit$Target($Class* class$) {
	Target::nextThreadNum = 0;
}

Target::Target() {
}

$Class* Target::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Target$$Lambda$lambda$refSetRemove$1::classInfo$.name)) {
			return Target$$Lambda$lambda$refSetRemove$1::load$(name, initialize);
		}
		if (name->equals(Target$$Lambda$lambda$refSetRemove$0$1::classInfo$.name)) {
			return Target$$Lambda$lambda$refSetRemove$0$1::load$(name, initialize);
		}
	}
	$loadClass(Target, name, initialize, &_Target_ClassInfo_, clinit$Target, allocate$Target);
	return class$;
}

$Class* Target::class$ = nullptr;

		} // transport
	} // rmi
} // sun