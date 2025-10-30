#include <sun/rmi/server/UnicastServerRef.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/AccessException.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/ServerError.h>
#include <java/rmi/ServerException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/server/ExportException.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/rmi/server/ServerNotActiveException.h>
#include <java/rmi/server/Skeleton.h>
#include <java/rmi/server/SkeletonNotFoundException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/Dispatcher.h>
#include <sun/rmi/server/MarshalInputStream.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/server/WeakClassHashMap.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef BRIEF
#undef TYPE
#undef VERBOSE

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $OperationArray = $Array<::java::rmi::server::Operation>;
using $DataInput = ::java::io::DataInput;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutput = ::java::io::ObjectOutput;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StackTraceElement = ::java::lang::StackTraceElement;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $AccessException = ::java::rmi::AccessException;
using $MarshalException = ::java::rmi::MarshalException;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $ServerError = ::java::rmi::ServerError;
using $ServerException = ::java::rmi::ServerException;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $ExportException = ::java::rmi::server::ExportException;
using $ObjID = ::java::rmi::server::ObjID;
using $Operation = ::java::rmi::server::Operation;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $ServerNotActiveException = ::java::rmi::server::ServerNotActiveException;
using $ServerRef = ::java::rmi::server::ServerRef;
using $Skeleton = ::java::rmi::server::Skeleton;
using $SkeletonNotFoundException = ::java::rmi::server::SkeletonNotFoundException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $Dispatcher = ::sun::rmi::server::Dispatcher;
using $MarshalInputStream = ::sun::rmi::server::MarshalInputStream;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $UnicastServerRef$HashToMethod_Maps = ::sun::rmi::server::UnicastServerRef$HashToMethod_Maps;
using $Util = ::sun::rmi::server::Util;
using $WeakClassHashMap = ::sun::rmi::server::WeakClassHashMap;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;
using $Target = ::sun::rmi::transport::Target;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace server {

class UnicastServerRef$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(UnicastServerRef$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(UnicastServerRef::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnicastServerRef$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo UnicastServerRef$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef$$Lambda$lambda$static$0::*)()>(&UnicastServerRef$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo UnicastServerRef$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.UnicastServerRef$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* UnicastServerRef$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnicastServerRef$$Lambda$lambda$static$0::class$ = nullptr;

class UnicastServerRef$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(UnicastServerRef$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(UnicastServerRef::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnicastServerRef$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo UnicastServerRef$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef$$Lambda$lambda$static$1$1::*)()>(&UnicastServerRef$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo UnicastServerRef$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.UnicastServerRef$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* UnicastServerRef$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnicastServerRef$$Lambda$lambda$static$1$1::class$ = nullptr;

class UnicastServerRef$$Lambda$lambda$static$2$2 : public $PrivilegedAction {
	$class(UnicastServerRef$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(UnicastServerRef::lambda$static$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnicastServerRef$$Lambda$lambda$static$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo UnicastServerRef$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef$$Lambda$lambda$static$2$2::*)()>(&UnicastServerRef$$Lambda$lambda$static$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo UnicastServerRef$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.UnicastServerRef$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* UnicastServerRef$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnicastServerRef$$Lambda$lambda$static$2$2::class$ = nullptr;

class UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3 : public $PrivilegedAction {
	$class(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(UnicastServerRef* inst, $ObjectInputStream* ois) {
		$set(this, inst$, inst);
		$set(this, ois, ois);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$unmarshalCustomCallData$3(ois));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3>());
	}
	UnicastServerRef* inst$ = nullptr;
	$ObjectInputStream* ois = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3, inst$)},
	{"ois", "Ljava/io/ObjectInputStream;", nullptr, $PUBLIC, $field(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3, ois)},
	{}
};
$MethodInfo UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::methodInfos[3] = {
	{"<init>", "(Lsun/rmi/server/UnicastServerRef;Ljava/io/ObjectInputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::*)(UnicastServerRef*,$ObjectInputStream*)>(&UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::class$ = nullptr;

$FieldInfo _UnicastServerRef_FieldInfo_[] = {
	{"logCalls", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UnicastServerRef, logCalls)},
	{"callLog", "Lsun/rmi/runtime/Log;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UnicastServerRef, callLog)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicastServerRef, serialVersionUID)},
	{"wantExceptionLog", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnicastServerRef, wantExceptionLog)},
	{"forceStubUse", "Z", nullptr, $PRIVATE, $field(UnicastServerRef, forceStubUse)},
	{"suppressStackTraces", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnicastServerRef, suppressStackTraces)},
	{"skel", "Ljava/rmi/server/Skeleton;", nullptr, $PRIVATE | $TRANSIENT, $field(UnicastServerRef, skel)},
	{"filter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $FINAL | $TRANSIENT, $field(UnicastServerRef, filter)},
	{"hashToMethod_Map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Long;Ljava/lang/reflect/Method;>;", $PRIVATE | $TRANSIENT, $field(UnicastServerRef, hashToMethod_Map)},
	{"hashToMethod_Maps", "Lsun/rmi/server/WeakClassHashMap;", "Lsun/rmi/server/WeakClassHashMap<Ljava/util/Map<Ljava/lang/Long;Ljava/lang/reflect/Method;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(UnicastServerRef, hashToMethod_Maps)},
	{"withoutSkeletons", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;*>;", $PRIVATE | $STATIC | $FINAL, $staticField(UnicastServerRef, withoutSkeletons)},
	{}
};

$MethodInfo _UnicastServerRef_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*done", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef::*)()>(&UnicastServerRef::init$))},
	{"<init>", "(Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef::*)($LiveRef*)>(&UnicastServerRef::init$))},
	{"<init>", "(Lsun/rmi/transport/LiveRef;Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef::*)($LiveRef*,$ObjectInputFilter*)>(&UnicastServerRef::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef::*)(int32_t)>(&UnicastServerRef::init$))},
	{"<init>", "(Z)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef::*)(bool)>(&UnicastServerRef::init$))},
	{"clearStackTraces", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Throwable*)>(&UnicastServerRef::clearStackTraces))},
	{"dispatch", "(Ljava/rmi/Remote;Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"exportObject", "(Ljava/rmi/Remote;Ljava/lang/Object;)Ljava/rmi/server/RemoteStub;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"exportObject", "(Ljava/rmi/Remote;Ljava/lang/Object;Z)Ljava/rmi/Remote;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"getClientHost", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.rmi.server.ServerNotActiveException"},
	{"getClientRef", "()Ljava/rmi/server/RemoteRef;", nullptr, $PROTECTED},
	{"getRefClass", "(Ljava/io/ObjectOutput;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*invoke", "(Ljava/rmi/Remote;Ljava/lang/reflect/Method;[Ljava/lang/Object;J)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*invoke", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC},
	{"lambda$static$0", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)()>(&UnicastServerRef::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)()>(&UnicastServerRef::lambda$static$1))},
	{"lambda$static$2", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)()>(&UnicastServerRef::lambda$static$2))},
	{"lambda$unmarshalCustomCallData$3", "(Ljava/io/ObjectInputStream;)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(UnicastServerRef::*)($ObjectInputStream*)>(&UnicastServerRef::lambda$unmarshalCustomCallData$3))},
	{"logCall", "(Ljava/rmi/Remote;Ljava/lang/Object;)V", nullptr, $PRIVATE, $method(static_cast<void(UnicastServerRef::*)($Remote*,Object$*)>(&UnicastServerRef::logCall))},
	{"logCallException", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(UnicastServerRef::*)($Throwable*)>(&UnicastServerRef::logCallException))},
	{"*newCall", "(Ljava/rmi/server/RemoteObject;[Ljava/rmi/server/Operation;IJ)Ljava/rmi/server/RemoteCall;", nullptr, $PUBLIC},
	{"oldDispatch", "(Ljava/rmi/Remote;Ljava/rmi/server/RemoteCall;I)V", nullptr, $PRIVATE, $method(static_cast<void(UnicastServerRef::*)($Remote*,$RemoteCall*,int32_t)>(&UnicastServerRef::oldDispatch)), "java.lang.Exception"},
	{"readExternal", "(Ljava/io/ObjectInput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"*remoteEquals", "(Ljava/rmi/server/RemoteRef;)Z", nullptr, $PUBLIC},
	{"*remoteHashCode", "()I", nullptr, $PUBLIC},
	{"*remoteToString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"setSkeleton", "(Ljava/rmi/Remote;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unmarshalCustomCallData", "(Ljava/io/ObjectInput;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeExternal", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _UnicastServerRef_InnerClassesInfo_[] = {
	{"sun.rmi.server.UnicastServerRef$HashToMethod_Maps", "sun.rmi.server.UnicastServerRef", "HashToMethod_Maps", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _UnicastServerRef_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.server.UnicastServerRef",
	"sun.rmi.server.UnicastRef",
	"java.rmi.server.ServerRef,sun.rmi.server.Dispatcher",
	_UnicastServerRef_FieldInfo_,
	_UnicastServerRef_MethodInfo_,
	nullptr,
	nullptr,
	_UnicastServerRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.server.UnicastServerRef$HashToMethod_Maps,sun.rmi.server.UnicastServerRef$HashToMethod_Maps$1"
};

$Object* allocate$UnicastServerRef($Class* clazz) {
	return $of($alloc(UnicastServerRef));
}

$Object* UnicastServerRef::invoke($Remote* obj, $Method* method, $ObjectArray* params, int64_t opnum) {
	 return this->$UnicastRef::invoke(obj, method, params, opnum);
}

$RemoteCall* UnicastServerRef::newCall($RemoteObject* obj, $OperationArray* ops, int32_t opnum, int64_t hash) {
	 return this->$UnicastRef::newCall(obj, ops, opnum, hash);
}

void UnicastServerRef::invoke($RemoteCall* call) {
	this->$UnicastRef::invoke(call);
}

void UnicastServerRef::done($RemoteCall* call) {
	this->$UnicastRef::done(call);
}

$String* UnicastServerRef::remoteToString() {
	 return this->$UnicastRef::remoteToString();
}

int32_t UnicastServerRef::remoteHashCode() {
	 return this->$UnicastRef::remoteHashCode();
}

bool UnicastServerRef::remoteEquals($RemoteRef* sub) {
	 return this->$UnicastRef::remoteEquals(sub);
}

int32_t UnicastServerRef::hashCode() {
	 return this->$UnicastRef::hashCode();
}

bool UnicastServerRef::equals(Object$* arg0) {
	 return this->$UnicastRef::equals(arg0);
}

$Object* UnicastServerRef::clone() {
	 return this->$UnicastRef::clone();
}

$String* UnicastServerRef::toString() {
	 return this->$UnicastRef::toString();
}

void UnicastServerRef::finalize() {
	this->$UnicastRef::finalize();
}

bool UnicastServerRef::logCalls = false;
$Log* UnicastServerRef::callLog = nullptr;
bool UnicastServerRef::wantExceptionLog = false;
bool UnicastServerRef::suppressStackTraces = false;
$WeakClassHashMap* UnicastServerRef::hashToMethod_Maps = nullptr;
$Map* UnicastServerRef::withoutSkeletons = nullptr;

void UnicastServerRef::init$() {
	$UnicastRef::init$();
	this->forceStubUse = false;
	$set(this, hashToMethod_Map, nullptr);
	$set(this, filter, nullptr);
}

void UnicastServerRef::init$($LiveRef* ref) {
	$UnicastRef::init$(ref);
	this->forceStubUse = false;
	$set(this, hashToMethod_Map, nullptr);
	$set(this, filter, nullptr);
}

void UnicastServerRef::init$($LiveRef* ref, $ObjectInputFilter* filter) {
	$UnicastRef::init$(ref);
	this->forceStubUse = false;
	$set(this, hashToMethod_Map, nullptr);
	$set(this, filter, filter);
}

void UnicastServerRef::init$(int32_t port) {
	$UnicastRef::init$($$new($LiveRef, port));
	this->forceStubUse = false;
	$set(this, hashToMethod_Map, nullptr);
	$set(this, filter, nullptr);
}

void UnicastServerRef::init$(bool forceStubUse) {
	UnicastServerRef::init$(0);
	this->forceStubUse = forceStubUse;
}

$RemoteStub* UnicastServerRef::exportObject($Remote* impl, Object$* data) {
	this->forceStubUse = true;
	return $cast($RemoteStub, exportObject(impl, data, false));
}

$Remote* UnicastServerRef::exportObject($Remote* impl, Object$* data, bool permanent) {
	$useLocalCurrentObjectStackCache();
	$Class* implClass = $nc($of(impl))->getClass();
	$var($Remote, stub, nullptr);
	try {
		$assign(stub, $Util::createProxy(implClass, $(getClientRef()), this->forceStubUse));
	} catch ($IllegalArgumentException& e) {
		$throwNew($ExportException, "remote object implements illegal remote interface"_s, e);
	}
	if ($instanceOf($RemoteStub, stub)) {
		setSkeleton(impl);
	}
	$var($Target, target, $new($Target, impl, this, stub, $($nc(this->ref)->getObjID()), permanent));
	$nc(this->ref)->exportObject(target);
	$set(this, hashToMethod_Map, $cast($Map, $nc(UnicastServerRef::hashToMethod_Maps)->get(implClass)));
	return stub;
}

$String* UnicastServerRef::getClientHost() {
	return $TCPTransport::getClientHost();
}

void UnicastServerRef::setSkeleton($Remote* impl) {
	if (!$nc(UnicastServerRef::withoutSkeletons)->containsKey($nc($of(impl))->getClass())) {
		try {
			$set(this, skel, $Util::createSkeleton(impl));
		} catch ($SkeletonNotFoundException& e) {
			$nc(UnicastServerRef::withoutSkeletons)->put($nc($of(impl))->getClass(), nullptr);
		}
	}
}

void UnicastServerRef::dispatch($Remote* obj, $RemoteCall* call) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int32_t num = 0;
	int64_t op = 0;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($ObjectInput, in, nullptr);
				try {
					$assign(in, $nc(call)->getInputStream());
					num = $nc(in)->readInt();
				} catch ($Exception& readEx) {
					$throwNew($UnmarshalException, "error unmarshalling call header"_s, readEx);
				}
				if (this->skel != nullptr) {
					oldDispatch(obj, call, num);
					return$1 = true;
					goto $finally;
				} else if (num >= 0) {
					$throwNew($UnmarshalException, "skeleton class not found but required for client version"_s);
				}
				try {
					op = $nc(in)->readLong();
				} catch ($Exception& readEx) {
					$throwNew($UnmarshalException, "error unmarshalling call header"_s, readEx);
				}
				$var($MarshalInputStream, marshalStream, $cast($MarshalInputStream, in));
				$nc(marshalStream)->skipDefaultResolveClass();
				$var($Method, method, $cast($Method, $nc(this->hashToMethod_Map)->get($($Long::valueOf(op)))));
				if (method == nullptr) {
					$throwNew($UnmarshalException, "unrecognized method hash: method not supported by remote object"_s);
				}
				logCall(obj, method);
				$var($ClassArray, types, $nc(method)->getParameterTypes());
				$var($ObjectArray, params, $new($ObjectArray, $nc(types)->length));
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							unmarshalCustomCallData(in);
							for (int32_t i = 0; i < types->length; ++i) {
								params->set(i, $(unmarshalValue(types->get(i), in)));
							}
						} catch ($AccessException& aex) {
							$nc(($cast($StreamRemoteCall, call)))->discardPendingRefs();
							$throw(aex);
						} catch ($IOException& e) {
							$nc(($cast($StreamRemoteCall, call)))->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($ClassNotFoundException& e) {
							$nc(($cast($StreamRemoteCall, call)))->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
				$var($Object, result, nullptr);
				try {
					$assign(result, method->invoke(obj, params));
				} catch ($InvocationTargetException& e) {
					$throw($(e->getTargetException()));
				}
				try {
					$var($ObjectOutput, out, call->getResultStream(true));
					$Class* rtype = method->getReturnType();
					$init($Void);
					if (rtype != $Void::TYPE) {
						marshalValue(rtype, result, out);
					}
				} catch ($IOException& ex) {
					$throwNew($MarshalException, "error marshalling return"_s, ex);
				}
			} catch ($Throwable& e) {
				$var($Throwable, origEx, e);
				logCallException(e);
				$var($ObjectOutput, out, $nc(call)->getResultStream(false));
				if ($instanceOf($Error, e)) {
					$assign(e, $new($ServerError, "Error occurred in server thread"_s, $cast($Error, e)));
				} else if ($instanceOf($RemoteException, e)) {
					$assign(e, $new($ServerException, "RemoteException occurred in server thread"_s, $cast($Exception, e)));
				}
				if (UnicastServerRef::suppressStackTraces) {
					clearStackTraces(e);
				}
				$nc(out)->writeObject(e);
				if ($instanceOf($AccessException, origEx)) {
					$throwNew($IOException, "Connection is not reusable"_s, origEx);
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(call)->releaseInputStream();
			call->releaseOutputStream();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

void UnicastServerRef::unmarshalCustomCallData($ObjectInput* in) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->filter != nullptr && $instanceOf($ObjectInputStream, in)) {
		$var($ObjectInputStream, ois, $cast($ObjectInputStream, in));
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3, this, ois)));
	}
}

void UnicastServerRef::oldDispatch($Remote* obj, $RemoteCall* call, int32_t op) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int64_t hash = 0;
	$var($ObjectInput, in, nullptr);
	$assign(in, $nc(call)->getInputStream());
	try {
		$Class* clazz = $Class::forName("sun.rmi.transport.DGCImpl_Skel"_s);
		if ($nc(clazz)->isAssignableFrom($nc($of(this->skel))->getClass())) {
			$nc(($cast($MarshalInputStream, in)))->useCodebaseOnly();
		}
	} catch ($ClassNotFoundException& ignore) {
	}
	try {
		hash = $nc(in)->readLong();
	} catch ($Exception& ioe) {
		$throwNew($UnmarshalException, "error unmarshalling call header"_s, ioe);
	}
	$var($OperationArray, operations, $nc(this->skel)->getOperations());
	logCall(obj, op >= 0 && op < $nc(operations)->length ? $of($nc(operations)->get(op)) : $of($$str({"op: "_s, $$str(op)})));
	unmarshalCustomCallData(in);
	$nc(this->skel)->dispatch(obj, call, op, hash);
}

void UnicastServerRef::clearStackTraces($Throwable* t$renamed) {
	$init(UnicastServerRef);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	$var($StackTraceElementArray, empty, $new($StackTraceElementArray, 0));
	while (t != nullptr) {
		t->setStackTrace(empty);
		$assign(t, t->getCause());
	}
}

void UnicastServerRef::logCall($Remote* obj, Object$* method) {
	$useLocalCurrentObjectStackCache();
	$init($Log);
	if ($nc(UnicastServerRef::callLog)->isLoggable($Log::VERBOSE)) {
		$var($String, clientHost, nullptr);
		try {
			$assign(clientHost, getClientHost());
		} catch ($ServerNotActiveException& snae) {
			$assign(clientHost, "(local)"_s);
		}
		$var($String, var$3, $$str({"["_s, clientHost, ": "_s, $($nc($of(obj))->getClass()->getName())}));
		$var($String, var$2, $$concat(var$3, $($nc($($nc(this->ref)->getObjID()))->toString())));
		$var($String, var$1, $$concat(var$2, ": "));
		$var($String, var$0, $$concat(var$1, $(method)));
		$nc(UnicastServerRef::callLog)->log($Log::VERBOSE, $$concat(var$0, "]"));
	}
}

void UnicastServerRef::logCallException($Throwable* e) {
	$useLocalCurrentObjectStackCache();
	$init($Log);
	if ($nc(UnicastServerRef::callLog)->isLoggable($Log::BRIEF)) {
		$var($String, clientHost, ""_s);
		try {
			$assign(clientHost, $str({"["_s, $(getClientHost()), "] "_s}));
		} catch ($ServerNotActiveException& snae) {
		}
		$nc(UnicastServerRef::callLog)->log($Log::BRIEF, $$str({clientHost, "exception: "_s}), e);
	}
	if (UnicastServerRef::wantExceptionLog) {
		$var($PrintStream, log, $System::err);
		$synchronized(log) {
			$nc(log)->println();
			$var($String, var$3, $$str({"Exception dispatching call to "_s, $($nc(this->ref)->getObjID()), " in thread \""_s}));
			$var($String, var$2, $$concat(var$3, $($($Thread::currentThread())->getName())));
			$var($String, var$1, $$concat(var$2, "\" at "));
			$var($String, var$0, $$concat(var$1, $(($new($Date)))));
			log->println($$concat(var$0, ":"));
			$nc(e)->printStackTrace(log);
		}
	}
}

$String* UnicastServerRef::getRefClass($ObjectOutput* out) {
	return "UnicastServerRef"_s;
}

$RemoteRef* UnicastServerRef::getClientRef() {
	return $new($UnicastRef, this->ref);
}

void UnicastServerRef::writeExternal($ObjectOutput* out) {
}

void UnicastServerRef::readExternal($ObjectInput* in) {
	$set(this, ref, nullptr);
	$set(this, skel, nullptr);
}

$Void* UnicastServerRef::lambda$unmarshalCustomCallData$3($ObjectInputStream* ois) {
	$nc(ois)->setObjectInputFilter(this->filter);
	return nullptr;
}

$Boolean* UnicastServerRef::lambda$static$2() {
	$init(UnicastServerRef);
	return $Boolean::valueOf($Boolean::getBoolean("sun.rmi.server.suppressStackTraces"_s));
}

$Boolean* UnicastServerRef::lambda$static$1() {
	$init(UnicastServerRef);
	return $Boolean::valueOf($Boolean::getBoolean("sun.rmi.server.exceptionTrace"_s));
}

$Boolean* UnicastServerRef::lambda$static$0() {
	$init(UnicastServerRef);
	return $Boolean::valueOf($Boolean::getBoolean("java.rmi.server.logCalls"_s));
}

void clinit$UnicastServerRef($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	UnicastServerRef::logCalls = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(UnicastServerRef$$Lambda$lambda$static$0)))))))->booleanValue();
	$assignStatic(UnicastServerRef::callLog, $Log::getLog("sun.rmi.server.call"_s, "RMI"_s, UnicastServerRef::logCalls));
	UnicastServerRef::wantExceptionLog = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(UnicastServerRef$$Lambda$lambda$static$1$1)))))))->booleanValue();
	UnicastServerRef::suppressStackTraces = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(UnicastServerRef$$Lambda$lambda$static$2$2)))))))->booleanValue();
	$assignStatic(UnicastServerRef::hashToMethod_Maps, $new($UnicastServerRef$HashToMethod_Maps));
	$assignStatic(UnicastServerRef::withoutSkeletons, $Collections::synchronizedMap($$new($WeakHashMap)));
}

UnicastServerRef::UnicastServerRef() {
}

$Class* UnicastServerRef::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(UnicastServerRef$$Lambda$lambda$static$0::classInfo$.name)) {
			return UnicastServerRef$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(UnicastServerRef$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return UnicastServerRef$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(UnicastServerRef$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return UnicastServerRef$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
		if (name->equals(UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::classInfo$.name)) {
			return UnicastServerRef$$Lambda$lambda$unmarshalCustomCallData$3$3::load$(name, initialize);
		}
	}
	$loadClass(UnicastServerRef, name, initialize, &_UnicastServerRef_ClassInfo_, clinit$UnicastServerRef, allocate$UnicastServerRef);
	return class$;
}

$Class* UnicastServerRef::class$ = nullptr;

		} // server
	} // rmi
} // sun