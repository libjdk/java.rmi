#include <sun/rmi/transport/DGCImpl_Stub.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Module.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/UnexpectedException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/dgc/Lease.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/rmi/server/UID.h>
#include <java/util/ArrayList.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <sun/rmi/transport/tcp/TCPConnection.h>
#include <jcpp.h>

#undef ALLOWED
#undef DGCCLIENT_MAX_ARRAY_SIZE
#undef DGCCLIENT_MAX_DEPTH
#undef REJECTED
#undef UNDECIDED

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $OperationArray = $Array<::java::rmi::server::Operation>;
using $DataOutput = ::java::io::DataOutput;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $ObjectOutput = ::java::io::ObjectOutput;
using $Serializable = ::java::io::Serializable;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StackTraceElement = ::java::lang::StackTraceElement;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MarshalException = ::java::rmi::MarshalException;
using $RemoteException = ::java::rmi::RemoteException;
using $UnexpectedException = ::java::rmi::UnexpectedException;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $DGC = ::java::rmi::dgc::DGC;
using $Lease = ::java::rmi::dgc::Lease;
using $VMID = ::java::rmi::dgc::VMID;
using $Operation = ::java::rmi::server::Operation;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $UID = ::java::rmi::server::UID;
using $ArrayList = ::java::util::ArrayList;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;
using $TCPConnection = ::sun::rmi::transport::tcp::TCPConnection;

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl_Stub$$Lambda$leaseFilter : public $ObjectInputFilter {
	$class(DGCImpl_Stub$$Lambda$leaseFilter, $NO_CLASS_INIT, $ObjectInputFilter)
public:
	void init$() {
	}
	virtual $ObjectInputFilter$Status* checkInput($ObjectInputFilter$FilterInfo* filterInfo) override {
		 return DGCImpl_Stub::leaseFilter(filterInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCImpl_Stub$$Lambda$leaseFilter>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCImpl_Stub$$Lambda$leaseFilter::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl_Stub$$Lambda$leaseFilter::*)()>(&DGCImpl_Stub$$Lambda$leaseFilter::init$))},
	{"checkInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCImpl_Stub$$Lambda$leaseFilter::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCImpl_Stub$$Lambda$leaseFilter",
	"java.lang.Object",
	"java.io.ObjectInputFilter",
	nullptr,
	methodInfos
};
$Class* DGCImpl_Stub$$Lambda$leaseFilter::load$($String* name, bool initialize) {
	$loadClass(DGCImpl_Stub$$Lambda$leaseFilter, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCImpl_Stub$$Lambda$leaseFilter::class$ = nullptr;

$FieldInfo _DGCImpl_Stub_FieldInfo_[] = {
	{"operations", "[Ljava/rmi/server/Operation;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl_Stub, operations)},
	{"interfaceHash", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DGCImpl_Stub, interfaceHash)},
	{"DGCCLIENT_MAX_DEPTH", "I", nullptr, $PRIVATE | $STATIC, $staticField(DGCImpl_Stub, DGCCLIENT_MAX_DEPTH)},
	{"DGCCLIENT_MAX_ARRAY_SIZE", "I", nullptr, $PRIVATE | $STATIC, $staticField(DGCImpl_Stub, DGCCLIENT_MAX_ARRAY_SIZE)},
	{}
};

$MethodInfo _DGCImpl_Stub_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl_Stub::*)()>(&DGCImpl_Stub::init$))},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl_Stub::*)($RemoteRef*)>(&DGCImpl_Stub::init$))},
	{"clean", "([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/VMID;Z)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"dirty", "([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/Lease;)Ljava/rmi/dgc/Lease;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"leaseFilter", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ObjectInputFilter$Status*(*)($ObjectInputFilter$FilterInfo*)>(&DGCImpl_Stub::leaseFilter))},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DGCImpl_Stub_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.transport.DGCImpl_Stub",
	"java.rmi.server.RemoteStub",
	"java.rmi.dgc.DGC",
	_DGCImpl_Stub_FieldInfo_,
	_DGCImpl_Stub_MethodInfo_
};

$Object* allocate$DGCImpl_Stub($Class* clazz) {
	return $of($alloc(DGCImpl_Stub));
}

int32_t DGCImpl_Stub::hashCode() {
	 return this->$RemoteStub::hashCode();
}

bool DGCImpl_Stub::equals(Object$* obj) {
	 return this->$RemoteStub::equals(obj);
}

$String* DGCImpl_Stub::toString() {
	 return this->$RemoteStub::toString();
}

$Object* DGCImpl_Stub::clone() {
	 return this->$RemoteStub::clone();
}

void DGCImpl_Stub::finalize() {
	this->$RemoteStub::finalize();
}

$OperationArray* DGCImpl_Stub::operations = nullptr;
int32_t DGCImpl_Stub::DGCCLIENT_MAX_DEPTH = 0;
int32_t DGCImpl_Stub::DGCCLIENT_MAX_ARRAY_SIZE = 0;

void DGCImpl_Stub::init$() {
	$RemoteStub::init$();
}

void DGCImpl_Stub::init$($RemoteRef* ref) {
	$RemoteStub::init$(ref);
}

void DGCImpl_Stub::clean($ObjIDArray* $param_arrayOf_ObjID_1, int64_t $param_long_2, $VMID* $param_VMID_3, bool $param_boolean_4) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(static_cast<$RemoteObject*>(this), DGCImpl_Stub::operations, 0, DGCImpl_Stub::interfaceHash)));
		$nc(call)->setObjectInputFilter(static_cast<$ObjectInputFilter*>($$new(DGCImpl_Stub$$Lambda$leaseFilter)));
		try {
			$var($ObjectOutput, out, call->getOutputStream());
			$nc(out)->writeObject($param_arrayOf_ObjID_1);
			out->writeLong($param_long_2);
			out->writeObject($param_VMID_3);
			out->writeBoolean($param_boolean_4);
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshalling arguments"_s, e);
		}
		$nc(this->ref)->invoke(call);
		$nc(this->ref)->done(call);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

$Lease* DGCImpl_Stub::dirty($ObjIDArray* $param_arrayOf_ObjID_1, int64_t $param_long_2, $Lease* $param_Lease_3) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(static_cast<$RemoteObject*>(this), DGCImpl_Stub::operations, 1, DGCImpl_Stub::interfaceHash)));
		$nc(call)->setObjectInputFilter(static_cast<$ObjectInputFilter*>($$new(DGCImpl_Stub$$Lambda$leaseFilter)));
		try {
			$var($ObjectOutput, out, call->getOutputStream());
			$nc(out)->writeObject($param_arrayOf_ObjID_1);
			out->writeLong($param_long_2);
			out->writeObject($param_Lease_3);
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshalling arguments"_s, e);
		}
		$nc(this->ref)->invoke(call);
		$var($Lease, $result, nullptr);
		$var($Connection, connection, call->getConnection());
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ObjectInput, in, call->getInputStream());
					$assign($result, $cast($Lease, $nc(in)->readObject()));
				} catch ($ClassCastException& e) {
					if ($instanceOf($TCPConnection, connection)) {
						$nc($($nc(($cast($TCPConnection, connection)))->getChannel()))->free(connection, false);
					}
					call->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				} catch ($IOException& e) {
					if ($instanceOf($TCPConnection, connection)) {
						$nc($($nc(($cast($TCPConnection, connection)))->getChannel()))->free(connection, false);
					}
					call->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				} catch ($ClassNotFoundException& e) {
					if ($instanceOf($TCPConnection, connection)) {
						$nc($($nc(($cast($TCPConnection, connection)))->getChannel()))->free(connection, false);
					}
					call->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->ref)->done(call);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		return $result;
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$ObjectInputFilter$Status* DGCImpl_Stub::leaseFilter($ObjectInputFilter$FilterInfo* filterInfo) {
	$init(DGCImpl_Stub);
	if ($nc(filterInfo)->depth() > DGCImpl_Stub::DGCCLIENT_MAX_DEPTH) {
		$init($ObjectInputFilter$Status);
		return $ObjectInputFilter$Status::REJECTED;
	}
	$Class* clazz = $nc(filterInfo)->serialClass();
	if (clazz != nullptr) {
		while ($nc(clazz)->isArray()) {
			bool var$0 = filterInfo->arrayLength() >= 0;
			if (var$0 && filterInfo->arrayLength() > DGCImpl_Stub::DGCCLIENT_MAX_ARRAY_SIZE) {
				$init($ObjectInputFilter$Status);
				return $ObjectInputFilter$Status::REJECTED;
			}
			clazz = clazz->getComponentType();
		}
		if ($nc(clazz)->isPrimitive()) {
			$init($ObjectInputFilter$Status);
			return $ObjectInputFilter$Status::ALLOWED;
		}
		$load($UID);
		$load($VMID);
		$load($Lease);
		bool var$2 = clazz == $UID::class$ || clazz == $VMID::class$ || clazz == $Lease::class$;
		if (!var$2) {
			bool var$3 = $Throwable::class$->isAssignableFrom(clazz);
			if (var$3) {
				bool var$4 = $Object::class$->getModule() == $nc(clazz)->getModule();
				if (!var$4) {
					$load($RemoteException);
					var$4 = $RemoteException::class$->getModule() == $nc(clazz)->getModule();
				}
				var$3 = (var$4);
			}
			var$2 = (var$3);
		}
		$load($StackTraceElement);
		$load($ArrayList);
		bool var$1 = var$2 || clazz == $StackTraceElement::class$ || clazz == $ArrayList::class$ || clazz == $Object::class$;
		$init($ObjectInputFilter$Status);
		return (var$1 || $nc($($nc(clazz)->getName()))->equals("java.util.Collections$EmptyList"_s)) ? $ObjectInputFilter$Status::ALLOWED : $ObjectInputFilter$Status::REJECTED;
	}
	$init($ObjectInputFilter$Status);
	return $ObjectInputFilter$Status::UNDECIDED;
}

void clinit$DGCImpl_Stub($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DGCImpl_Stub::operations, $new($OperationArray, {
		$$new($Operation, "void clean(java.rmi.server.ObjID[], long, java.rmi.dgc.VMID, boolean)"_s),
		$$new($Operation, "java.rmi.dgc.Lease dirty(java.rmi.server.ObjID[], long, java.rmi.dgc.Lease)"_s)
	}));
	DGCImpl_Stub::DGCCLIENT_MAX_DEPTH = 6;
	DGCImpl_Stub::DGCCLIENT_MAX_ARRAY_SIZE = 10000;
}

DGCImpl_Stub::DGCImpl_Stub() {
}

$Class* DGCImpl_Stub::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DGCImpl_Stub$$Lambda$leaseFilter::classInfo$.name)) {
			return DGCImpl_Stub$$Lambda$leaseFilter::load$(name, initialize);
		}
	}
	$loadClass(DGCImpl_Stub, name, initialize, &_DGCImpl_Stub_ClassInfo_, clinit$DGCImpl_Stub, allocate$DGCImpl_Stub);
	return class$;
}

$Class* DGCImpl_Stub::class$ = nullptr;

		} // transport
	} // rmi
} // sun