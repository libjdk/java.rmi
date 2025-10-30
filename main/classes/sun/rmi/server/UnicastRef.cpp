#include <sun/rmi/server/UnicastRef.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/logging/Level.h>
#include <jdk/internal/access/JavaObjectInputStreamReadString.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <jcpp.h>

#undef BRIEF
#undef TYPE
#undef VERBOSE

using $OperationArray = $Array<::java::rmi::server::Operation>;
using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutput = ::java::io::ObjectOutput;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Short = ::java::lang::Short;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Method = ::java::lang::reflect::Method;
using $MarshalException = ::java::rmi::MarshalException;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $ObjID = ::java::rmi::server::ObjID;
using $Operation = ::java::rmi::server::Operation;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Level = ::java::util::logging::Level;
using $JavaObjectInputStreamReadString = ::jdk::internal::access::JavaObjectInputStreamReadString;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Log = ::sun::rmi::runtime::Log;
using $Util = ::sun::rmi::server::Util;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;

namespace sun {
	namespace rmi {
		namespace server {

class UnicastRef$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(UnicastRef$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(UnicastRef::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<UnicastRef$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo UnicastRef$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastRef$$Lambda$lambda$static$0::*)()>(&UnicastRef$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo UnicastRef$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.UnicastRef$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* UnicastRef$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(UnicastRef$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* UnicastRef$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _UnicastRef_FieldInfo_[] = {
	{"clientRefLog", "Lsun/rmi/runtime/Log;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UnicastRef, clientRefLog)},
	{"clientCallLog", "Lsun/rmi/runtime/Log;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UnicastRef, clientCallLog)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicastRef, serialVersionUID)},
	{"ref", "Lsun/rmi/transport/LiveRef;", nullptr, $PROTECTED, $field(UnicastRef, ref)},
	{}
};

$MethodInfo _UnicastRef_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastRef::*)()>(&UnicastRef::init$))},
	{"<init>", "(Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastRef::*)($LiveRef*)>(&UnicastRef::init$))},
	{"done", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"free", "(Ljava/rmi/server/RemoteCall;Z)V", nullptr, $PRIVATE, $method(static_cast<void(UnicastRef::*)($RemoteCall*,bool)>(&UnicastRef::free)), "java.rmi.RemoteException"},
	{"getLiveRef", "()Lsun/rmi/transport/LiveRef;", nullptr, $PUBLIC},
	{"getRefClass", "(Ljava/io/ObjectOutput;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"invoke", "(Ljava/rmi/Remote;Ljava/lang/reflect/Method;[Ljava/lang/Object;J)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"invoke", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"lambda$static$0", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)()>(&UnicastRef::lambda$static$0))},
	{"logClientCall", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, 0},
	{"marshalCustomCallData", "(Ljava/io/ObjectOutput;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"marshalValue", "(Ljava/lang/Class;Ljava/lang/Object;Ljava/io/ObjectOutput;)V", "(Ljava/lang/Class<*>;Ljava/lang/Object;Ljava/io/ObjectOutput;)V", $PROTECTED | $STATIC, $method(static_cast<void(*)($Class*,Object$*,$ObjectOutput*)>(&UnicastRef::marshalValue)), "java.io.IOException"},
	{"newCall", "(Ljava/rmi/server/RemoteObject;[Ljava/rmi/server/Operation;IJ)Ljava/rmi/server/RemoteCall;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"readExternal", "(Ljava/io/ObjectInput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remoteEquals", "(Ljava/rmi/server/RemoteRef;)Z", nullptr, $PUBLIC},
	{"remoteHashCode", "()I", nullptr, $PUBLIC},
	{"remoteToString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unmarshalValue", "(Ljava/lang/Class;Ljava/io/ObjectInput;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Ljava/io/ObjectInput;)Ljava/lang/Object;", $PROTECTED | $STATIC, $method(static_cast<$Object*(*)($Class*,$ObjectInput*)>(&UnicastRef::unmarshalValue)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeExternal", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _UnicastRef_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.server.UnicastRef",
	"java.lang.Object",
	"java.rmi.server.RemoteRef",
	_UnicastRef_FieldInfo_,
	_UnicastRef_MethodInfo_
};

$Object* allocate$UnicastRef($Class* clazz) {
	return $of($alloc(UnicastRef));
}

$Log* UnicastRef::clientRefLog = nullptr;
$Log* UnicastRef::clientCallLog = nullptr;

void UnicastRef::init$() {
}

void UnicastRef::init$($LiveRef* liveRef) {
	$set(this, ref, liveRef);
}

$LiveRef* UnicastRef::getLiveRef() {
	return this->ref;
}

$Object* UnicastRef::invoke($Remote* obj, $Method* method, $ObjectArray* params, int64_t opnum) {
	$useLocalCurrentObjectStackCache();
	$init($Log);
	if ($nc(UnicastRef::clientRefLog)->isLoggable($Log::VERBOSE)) {
		$nc(UnicastRef::clientRefLog)->log($Log::VERBOSE, $$str({"method: "_s, method}));
	}
	if ($nc(UnicastRef::clientCallLog)->isLoggable($Log::VERBOSE)) {
		logClientCall(obj, method);
	}
	$var($Connection, conn, $nc($($nc(this->ref)->getChannel()))->newConnection());
	$var($RemoteCall, call, nullptr);
	bool reuse = true;
	bool alreadyFreed = false;
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			try {
				if ($nc(UnicastRef::clientRefLog)->isLoggable($Log::VERBOSE)) {
					$nc(UnicastRef::clientRefLog)->log($Log::VERBOSE, $$str({"opnum = "_s, $$str(opnum)}));
				}
				$assign(call, $new($StreamRemoteCall, conn, $($nc(this->ref)->getObjID()), -1, opnum));
				try {
					$var($ObjectOutput, out, call->getOutputStream());
					marshalCustomCallData(out);
					$var($ClassArray, types, $nc(method)->getParameterTypes());
					for (int32_t i = 0; i < $nc(types)->length; ++i) {
						marshalValue(types->get(i), $nc(params)->get(i), out);
					}
				} catch ($IOException& e) {
					$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "IOException marshalling arguments: "_s, e);
					$throwNew($MarshalException, "error marshalling arguments"_s, e);
				}
				call->executeCall();
				{
					$var($Throwable, var$3, nullptr);
					$var($Object, var$5, nullptr);
					bool return$4 = false;
					try {
						try {
							$Class* rtype = $nc(method)->getReturnType();
							$init($Void);
							if (rtype == $Void::TYPE) {
								$assign(var$5, nullptr);
								return$4 = true;
								goto $finally1;
							}
							$var($ObjectInput, in, call->getInputStream());
							$var($Object, returnValue, unmarshalValue(rtype, in));
							alreadyFreed = true;
							$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "free connection (reuse = true)"_s);
							$nc($($nc(this->ref)->getChannel()))->free(conn, true);
							$assign(var$5, returnValue);
							return$4 = true;
							goto $finally1;
						} catch ($IOException& e) {
							$nc(($cast($StreamRemoteCall, call)))->discardPendingRefs();
							$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, $$str({$($of(e)->getClass()->getName()), " unmarshalling return: "_s}), e);
							$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
						} catch ($ClassNotFoundException& e) {
							$nc(($cast($StreamRemoteCall, call)))->discardPendingRefs();
							$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, $$str({$($of(e)->getClass()->getName()), " unmarshalling return: "_s}), e);
							$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
						}
					} catch ($Throwable& var$6) {
						$assign(var$3, var$6);
					} $finally1: {
						try {
							call->done();
						} catch ($IOException& e) {
							reuse = false;
						}
					}
					if (var$3 != nullptr) {
						$throw(var$3);
					}
					if (return$4) {
						$assign(var$2, var$5);
						return$1 = true;
						goto $finally;
					}
				}
			} catch ($RuntimeException& e) {
				if ((call == nullptr) || (!$equals($nc(($cast($StreamRemoteCall, call)))->getServerException(), e))) {
					reuse = false;
				}
				$throw(e);
			} catch ($RemoteException& e) {
				reuse = false;
				$throw(e);
			} catch ($Error& e) {
				reuse = false;
				$throw(e);
			}
		} catch ($Throwable& var$7) {
			$assign(var$0, var$7);
		} $finally: {
			if (!alreadyFreed) {
				if ($nc(UnicastRef::clientRefLog)->isLoggable($Log::BRIEF)) {
					$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, $$str({"free connection (reuse = "_s, $$str(reuse), ")"_s}));
				}
				$nc($($nc(this->ref)->getChannel()))->free(conn, reuse);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void UnicastRef::marshalCustomCallData($ObjectOutput* out) {
}

void UnicastRef::marshalValue($Class* type, Object$* value, $ObjectOutput* out) {
	$init(UnicastRef);
	if ($nc(type)->isPrimitive()) {
		$init($Integer);
		if (type == $Integer::TYPE) {
			$nc(out)->writeInt($nc(($cast($Integer, value)))->intValue());
		} else {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				$nc(out)->writeBoolean($nc(($cast($Boolean, value)))->booleanValue());
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					$nc(out)->writeByte($nc(($cast($Byte, value)))->byteValue());
				} else {
					$init($Character);
					if (type == $Character::TYPE) {
						$nc(out)->writeChar($nc(($cast($Character, value)))->charValue());
					} else {
						$init($Short);
						if (type == $Short::TYPE) {
							$nc(out)->writeShort($nc(($cast($Short, value)))->shortValue());
						} else {
							$init($Long);
							if (type == $Long::TYPE) {
								$nc(out)->writeLong($nc(($cast($Long, value)))->longValue());
							} else {
								$init($Float);
								if (type == $Float::TYPE) {
									$nc(out)->writeFloat($nc(($cast($Float, value)))->floatValue());
								} else {
									$init($Double);
									if (type == $Double::TYPE) {
										$nc(out)->writeDouble($nc(($cast($Double, value)))->doubleValue());
									} else {
										$throwNew($Error, $$str({"Unrecognized primitive type: "_s, type}));
									}
								}
							}
						}
					}
				}
			}
		}
	} else {
		$nc(out)->writeObject(value);
	}
}

$Object* UnicastRef::unmarshalValue($Class* type, $ObjectInput* in) {
	$init(UnicastRef);
	$useLocalCurrentObjectStackCache();
	if ($nc(type)->isPrimitive()) {
		$init($Integer);
		if (type == $Integer::TYPE) {
			return $of($Integer::valueOf($nc(in)->readInt()));
		} else {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				return $of($Boolean::valueOf($nc(in)->readBoolean()));
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					return $of($Byte::valueOf($nc(in)->readByte()));
				} else {
					$init($Character);
					if (type == $Character::TYPE) {
						return $of($Character::valueOf($nc(in)->readChar()));
					} else {
						$init($Short);
						if (type == $Short::TYPE) {
							return $of($Short::valueOf($nc(in)->readShort()));
						} else {
							$init($Long);
							if (type == $Long::TYPE) {
								return $of($Long::valueOf($nc(in)->readLong()));
							} else {
								$init($Float);
								if (type == $Float::TYPE) {
									return $of($Float::valueOf($nc(in)->readFloat()));
								} else {
									$init($Double);
									if (type == $Double::TYPE) {
										return $of($Double::valueOf($nc(in)->readDouble()));
									} else {
										$throwNew($Error, $$str({"Unrecognized primitive type: "_s, type}));
									}
								}
							}
						}
					}
				}
			}
		}
	} else if (type == $String::class$ && $instanceOf($ObjectInputStream, in)) {
		return $of($nc($($SharedSecrets::getJavaObjectInputStreamReadString()))->readString($cast($ObjectInputStream, in)));
	} else {
		return $of($nc(in)->readObject());
	}
}

$RemoteCall* UnicastRef::newCall($RemoteObject* obj, $OperationArray* ops, int32_t opnum, int64_t hash) {
	$useLocalCurrentObjectStackCache();
	$init($Log);
	$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "get connection"_s);
	$var($Connection, conn, $nc($($nc(this->ref)->getChannel()))->newConnection());
	try {
		$nc(UnicastRef::clientRefLog)->log($Log::VERBOSE, "create call context"_s);
		if ($nc(UnicastRef::clientCallLog)->isLoggable($Log::VERBOSE)) {
			logClientCall(obj, $nc(ops)->get(opnum));
		}
		$var($RemoteCall, call, $new($StreamRemoteCall, conn, $($nc(this->ref)->getObjID()), opnum, hash));
		try {
			marshalCustomCallData($(call->getOutputStream()));
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshaling custom call data"_s);
		}
		return call;
	} catch ($RemoteException& e) {
		$nc($($nc(this->ref)->getChannel()))->free(conn, false);
		$throw(e);
	}
	$shouldNotReachHere();
}

void UnicastRef::invoke($RemoteCall* call) {
	try {
		$init($Log);
		$nc(UnicastRef::clientRefLog)->log($Log::VERBOSE, "execute call"_s);
		$nc(call)->executeCall();
	} catch ($RemoteException& e) {
		$init($Log);
		$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "exception: "_s, e);
		free(call, false);
		$throw(e);
	} catch ($Error& e) {
		$init($Log);
		$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "error: "_s, e);
		free(call, false);
		$throw(e);
	} catch ($RuntimeException& e) {
		$init($Log);
		$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "exception: "_s, e);
		free(call, false);
		$throw(e);
	} catch ($Exception& e) {
		$init($Log);
		$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "exception: "_s, e);
		free(call, true);
		$throw(e);
	}
}

void UnicastRef::free($RemoteCall* call, bool reuse) {
	$useLocalCurrentObjectStackCache();
	$var($Connection, conn, $nc(($cast($StreamRemoteCall, call)))->getConnection());
	$nc($($nc(this->ref)->getChannel()))->free(conn, reuse);
}

void UnicastRef::done($RemoteCall* call) {
	$init($Log);
	$nc(UnicastRef::clientRefLog)->log($Log::BRIEF, "free connection (reuse = true)"_s);
	free(call, true);
	try {
		$nc(call)->done();
	} catch ($IOException& e) {
	}
}

void UnicastRef::logClientCall(Object$* obj, Object$* method) {
	$useLocalCurrentObjectStackCache();
	$init($Log);
	$var($String, var$3, $$str({"outbound call: "_s, this->ref, " : "_s}));
	$var($String, var$2, $$concat(var$3, $($nc($of(obj))->getClass()->getName())));
	$var($String, var$1, $$concat(var$2, $($nc($($nc(this->ref)->getObjID()))->toString())));
	$var($String, var$0, $$concat(var$1, ": "));
	$nc(UnicastRef::clientCallLog)->log($Log::VERBOSE, $$concat(var$0, $(method)));
}

$String* UnicastRef::getRefClass($ObjectOutput* out) {
	return "UnicastRef"_s;
}

void UnicastRef::writeExternal($ObjectOutput* out) {
	$nc(this->ref)->write(out, false);
}

void UnicastRef::readExternal($ObjectInput* in) {
	$set(this, ref, $LiveRef::read(in, false));
}

$String* UnicastRef::remoteToString() {
	return $str({$($Util::getUnqualifiedName($of(this)->getClass())), " [liveRef: "_s, this->ref, "]"_s});
}

int32_t UnicastRef::remoteHashCode() {
	return $nc(this->ref)->hashCode();
}

bool UnicastRef::remoteEquals($RemoteRef* sub) {
	if ($instanceOf(UnicastRef, sub)) {
		return $nc(this->ref)->remoteEquals($nc(($cast(UnicastRef, sub)))->ref);
	}
	return false;
}

$Boolean* UnicastRef::lambda$static$0() {
	$init(UnicastRef);
	return $Boolean::valueOf($Boolean::getBoolean("sun.rmi.client.logCalls"_s));
}

void clinit$UnicastRef($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($Util);
	$assignStatic(UnicastRef::clientRefLog, $Log::getLog("sun.rmi.client.ref"_s, "transport"_s, $Util::logLevel));
	$assignStatic(UnicastRef::clientCallLog, $Log::getLog("sun.rmi.client.call"_s, "RMI"_s, $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(UnicastRef$$Lambda$lambda$static$0)))))))->booleanValue()));
}

UnicastRef::UnicastRef() {
}

$Class* UnicastRef::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(UnicastRef$$Lambda$lambda$static$0::classInfo$.name)) {
			return UnicastRef$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(UnicastRef, name, initialize, &_UnicastRef_ClassInfo_, clinit$UnicastRef, allocate$UnicastRef);
	return class$;
}

$Class* UnicastRef::class$ = nullptr;

		} // server
	} // rmi
} // sun