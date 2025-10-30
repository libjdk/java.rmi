#include <sun/rmi/server/Util.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/Math.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/StubNotFoundException.h>
#include <java/rmi/server/LogStream.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteObjectInvocationHandler.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/rmi/server/Skeleton.h>
#include <java/rmi/server/SkeletonNotFoundException.h>
#include <java/security/AccessController.h>
#include <java/security/DigestOutputStream.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/Util$1.h>
#include <jcpp.h>

#undef TYPE
#undef VERBOSE

using $MethodArray = $Array<::java::lang::reflect::Method>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $Short = ::java::lang::Short;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $Method = ::java::lang::reflect::Method;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $StubNotFoundException = ::java::rmi::StubNotFoundException;
using $LogStream = ::java::rmi::server::LogStream;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteObjectInvocationHandler = ::java::rmi::server::RemoteObjectInvocationHandler;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $Skeleton = ::java::rmi::server::Skeleton;
using $SkeletonNotFoundException = ::java::rmi::server::SkeletonNotFoundException;
using $AccessController = ::java::security::AccessController;
using $DigestOutputStream = ::java::security::DigestOutputStream;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $Util$1 = ::sun::rmi::server::Util$1;

namespace sun {
	namespace rmi {
		namespace server {

class Util$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(Util$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(Util::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Util$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Util$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Util$$Lambda$lambda$static$0::*)()>(&Util$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Util$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.Util$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* Util$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(Util$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Util$$Lambda$lambda$static$0::class$ = nullptr;

class Util$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(Util$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(Util::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Util$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Util$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Util$$Lambda$lambda$static$1$1::*)()>(&Util$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Util$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.Util$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* Util$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(Util$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Util$$Lambda$lambda$static$1$1::class$ = nullptr;

$FieldInfo _Util_FieldInfo_[] = {
	{"logLevel", "I", nullptr, $STATIC | $FINAL, $staticField(Util, logLevel)},
	{"serverRefLog", "Lsun/rmi/runtime/Log;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Util, serverRefLog)},
	{"ignoreStubClasses", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Util, ignoreStubClasses)},
	{"withoutStubs", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Ljava/lang/Void;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Util, withoutStubs)},
	{"stubConsParamTypes", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(Util, stubConsParamTypes)},
	{}
};

$MethodInfo _Util_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Util::*)()>(&Util::init$))},
	{"checkMethod", "(Ljava/lang/reflect/Method;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Method*)>(&Util::checkMethod))},
	{"computeMethodHash", "(Ljava/lang/reflect/Method;)J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($Method*)>(&Util::computeMethodHash))},
	{"createProxy", "(Ljava/lang/Class;Ljava/rmi/server/RemoteRef;Z)Ljava/rmi/Remote;", "(Ljava/lang/Class<*>;Ljava/rmi/server/RemoteRef;Z)Ljava/rmi/Remote;", $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Class*,$RemoteRef*,bool)>(&Util::createProxy)), "java.rmi.StubNotFoundException"},
	{"createSkeleton", "(Ljava/rmi/Remote;)Ljava/rmi/server/Skeleton;", nullptr, $STATIC, $method(static_cast<$Skeleton*(*)($Remote*)>(&Util::createSkeleton)), "java.rmi.server.SkeletonNotFoundException"},
	{"createStub", "(Ljava/lang/Class;Ljava/rmi/server/RemoteRef;)Ljava/rmi/server/RemoteStub;", "(Ljava/lang/Class<*>;Ljava/rmi/server/RemoteRef;)Ljava/rmi/server/RemoteStub;", $PRIVATE | $STATIC, $method(static_cast<$RemoteStub*(*)($Class*,$RemoteRef*)>(&Util::createStub)), "java.rmi.StubNotFoundException"},
	{"getMethodNameAndDescriptor", "(Ljava/lang/reflect/Method;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($Method*)>(&Util::getMethodNameAndDescriptor))},
	{"getRemoteClass", "(Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $method(static_cast<$Class*(*)($Class*)>(&Util::getRemoteClass)), "java.lang.ClassNotFoundException"},
	{"getRemoteInterfaces", "(Ljava/lang/Class;)[Ljava/lang/Class;", "(Ljava/lang/Class<*>;)[Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $method(static_cast<$ClassArray*(*)($Class*)>(&Util::getRemoteInterfaces))},
	{"getRemoteInterfaces", "(Ljava/util/ArrayList;Ljava/lang/Class;)V", "(Ljava/util/ArrayList<Ljava/lang/Class<*>;>;Ljava/lang/Class<*>;)V", $PRIVATE | $STATIC, $method(static_cast<void(*)($ArrayList*,$Class*)>(&Util::getRemoteInterfaces))},
	{"getTypeDescriptor", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PRIVATE | $STATIC, $method(static_cast<$String*(*)($Class*)>(&Util::getTypeDescriptor))},
	{"getUnqualifiedName", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PUBLIC | $STATIC, $method(static_cast<$String*(*)($Class*)>(&Util::getUnqualifiedName))},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&Util::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)()>(&Util::lambda$static$1))},
	{"stubClassExists", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $method(static_cast<bool(*)($Class*)>(&Util::stubClassExists))},
	{}
};

$InnerClassInfo _Util_InnerClassesInfo_[] = {
	{"sun.rmi.server.Util$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Util_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.server.Util",
	"java.lang.Object",
	nullptr,
	_Util_FieldInfo_,
	_Util_MethodInfo_,
	nullptr,
	nullptr,
	_Util_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.server.Util$1"
};

$Object* allocate$Util($Class* clazz) {
	return $of($alloc(Util));
}

int32_t Util::logLevel = 0;
$Log* Util::serverRefLog = nullptr;
bool Util::ignoreStubClasses = false;
$Map* Util::withoutStubs = nullptr;
$ClassArray* Util::stubConsParamTypes = nullptr;

void Util::init$() {
}

$Remote* Util::createProxy($Class* implClass, $RemoteRef* clientRef, bool forceStubUse) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* remoteClass = nullptr;
	try {
		remoteClass = getRemoteClass(implClass);
	} catch ($ClassNotFoundException& ex) {
		$throwNew($StubNotFoundException, $$str({"object does not implement a remote interface: "_s, $($nc(implClass)->getName())}));
	}
	if (forceStubUse || !(Util::ignoreStubClasses || !stubClassExists(remoteClass))) {
		return createStub(remoteClass, clientRef);
	}
	$var($ClassLoader, loader, $nc(implClass)->getClassLoader());
	$var($ClassArray, interfaces, getRemoteInterfaces(implClass));
	$var($InvocationHandler, handler, $new($RemoteObjectInvocationHandler, clientRef));
	try {
		return $cast($Remote, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Util$1, loader, interfaces, handler))));
	} catch ($IllegalArgumentException& e) {
		$throwNew($StubNotFoundException, "unable to create proxy"_s, e);
	}
	$shouldNotReachHere();
}

bool Util::stubClassExists($Class* remoteClass) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!$nc(Util::withoutStubs)->containsKey(remoteClass)) {
		try {
			$var($String, var$0, $str({$($nc(remoteClass)->getName()), "_Stub"_s}));
			$Class::forName(var$0, false, $(remoteClass->getClassLoader()));
			return true;
		} catch ($ClassNotFoundException& cnfe) {
			$nc(Util::withoutStubs)->put(remoteClass, nullptr);
		}
	}
	return false;
}

$Class* Util::getRemoteClass($Class* cl) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	while (cl != nullptr) {
		$var($ClassArray, interfaces, cl->getInterfaces());
		for (int32_t i = interfaces->length - 1; i >= 0; --i) {
			$load($Remote);
			if ($Remote::class$->isAssignableFrom(interfaces->get(i))) {
				return cl;
			}
		}
		cl = cl->getSuperclass();
	}
	$throwNew($ClassNotFoundException, "class does not implement java.rmi.Remote"_s);
}

$ClassArray* Util::getRemoteInterfaces($Class* remoteClass) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, list, $new($ArrayList));
	getRemoteInterfaces(list, remoteClass);
	return $fcast($ClassArray, list->toArray($$new($ClassArray, list->size())));
}

void Util::getRemoteInterfaces($ArrayList* list, $Class* cl) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* superclass = $nc(cl)->getSuperclass();
	if (superclass != nullptr) {
		getRemoteInterfaces(list, superclass);
	}
	$var($ClassArray, interfaces, cl->getInterfaces());
	for (int32_t i = 0; i < interfaces->length; ++i) {
		$Class* intf = interfaces->get(i);
		$load($Remote);
		if ($Remote::class$->isAssignableFrom(intf)) {
			if (!($nc(list)->contains(intf))) {
				$var($MethodArray, methods, $nc(intf)->getMethods());
				for (int32_t j = 0; j < $nc(methods)->length; ++j) {
					checkMethod(methods->get(j));
				}
				list->add(intf);
			}
		}
	}
}

void Util::checkMethod($Method* m) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$var($ClassArray, ex, $nc(m)->getExceptionTypes());
	for (int32_t i = 0; i < $nc(ex)->length; ++i) {
		$load($RemoteException);
		if ($nc(ex->get(i))->isAssignableFrom($RemoteException::class$)) {
			return;
		}
	}
	$throwNew($IllegalArgumentException, $$str({"illegal remote method encountered: "_s, m}));
}

$RemoteStub* Util::createStub($Class* remoteClass, $RemoteRef* ref) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, stubname, $str({$($nc(remoteClass)->getName()), "_Stub"_s}));
	try {
		$Class* stubcl = $Class::forName(stubname, false, $(remoteClass->getClassLoader()));
		$var($Constructor, cons, $nc(stubcl)->getConstructor(Util::stubConsParamTypes));
		return $cast($RemoteStub, $nc(cons)->newInstance($$new($ObjectArray, {$of(ref)})));
	} catch ($ClassNotFoundException& e) {
		$throwNew($StubNotFoundException, $$str({"Stub class not found: "_s, stubname}), e);
	} catch ($NoSuchMethodException& e) {
		$throwNew($StubNotFoundException, $$str({"Stub class missing constructor: "_s, stubname}), e);
	} catch ($InstantiationException& e) {
		$throwNew($StubNotFoundException, $$str({"Can\'t create instance of stub class: "_s, stubname}), e);
	} catch ($IllegalAccessException& e) {
		$throwNew($StubNotFoundException, $$str({"Stub class constructor not public: "_s, stubname}), e);
	} catch ($InvocationTargetException& e) {
		$throwNew($StubNotFoundException, $$str({"Exception creating instance of stub class: "_s, stubname}), e);
	} catch ($ClassCastException& e) {
		$throwNew($StubNotFoundException, $$str({"Stub class not instance of RemoteStub: "_s, stubname}), e);
	}
	$shouldNotReachHere();
}

$Skeleton* Util::createSkeleton($Remote* object) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* cl = nullptr;
	try {
		cl = getRemoteClass($nc($of(object))->getClass());
	} catch ($ClassNotFoundException& ex) {
		$throwNew($SkeletonNotFoundException, $$str({"object does not implement a remote interface: "_s, $($nc($of(object))->getClass()->getName())}));
	}
	$var($String, skelname, $str({$($nc(cl)->getName()), "_Skel"_s}));
	try {
		$Class* skelcl = $Class::forName(skelname, false, $(cl->getClassLoader()));
		return $cast($Skeleton, $nc(skelcl)->newInstance());
	} catch ($ClassNotFoundException& ex) {
		$throwNew($SkeletonNotFoundException, $$str({"Skeleton class not found: "_s, skelname}), ex);
	} catch ($InstantiationException& ex) {
		$throwNew($SkeletonNotFoundException, $$str({"Can\'t create skeleton: "_s, skelname}), ex);
	} catch ($IllegalAccessException& ex) {
		$throwNew($SkeletonNotFoundException, $$str({"No public constructor: "_s, skelname}), ex);
	} catch ($ClassCastException& ex) {
		$throwNew($SkeletonNotFoundException, $$str({"Skeleton not of correct class: "_s, skelname}), ex);
	}
	$shouldNotReachHere();
}

int64_t Util::computeMethodHash($Method* m) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	int64_t hash = 0;
	$var($ByteArrayOutputStream, sink, $new($ByteArrayOutputStream, 127));
	try {
		$var($MessageDigest, md, $MessageDigest::getInstance("SHA"_s));
		$var($DataOutputStream, out, $new($DataOutputStream, $$new($DigestOutputStream, sink, md)));
		$var($String, s, getMethodNameAndDescriptor(m));
		$init($Log);
		if ($nc(Util::serverRefLog)->isLoggable($Log::VERBOSE)) {
			$nc(Util::serverRefLog)->log($Log::VERBOSE, $$str({"string used for method hash: \""_s, s, "\""_s}));
		}
		out->writeUTF(s);
		out->flush();
		$var($bytes, hasharray, $nc(md)->digest());
		for (int32_t i = 0; i < $Math::min(8, $nc(hasharray)->length); ++i) {
			hash += $sl((int64_t)((int32_t)($nc(hasharray)->get(i) & (uint32_t)255)), i * 8);
		}
	} catch ($IOException& ignore) {
		hash = -1;
	} catch ($NoSuchAlgorithmException& complain) {
		$throwNew($SecurityException, $(complain->getMessage()));
	}
	return hash;
}

$String* Util::getMethodNameAndDescriptor($Method* m) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, desc, $new($StringBuilder, $($nc(m)->getName())));
	desc->append(u'(');
	$var($ClassArray, paramTypes, $nc(m)->getParameterTypes());
	for (int32_t i = 0; i < $nc(paramTypes)->length; ++i) {
		desc->append($(getTypeDescriptor(paramTypes->get(i))));
	}
	desc->append(u')');
	$Class* returnType = m->getReturnType();
	$init($Void);
	if (returnType == $Void::TYPE) {
		desc->append(u'V');
	} else {
		desc->append($(getTypeDescriptor(returnType)));
	}
	return desc->toString();
}

$String* Util::getTypeDescriptor($Class* type) {
	$init(Util);
	$useLocalCurrentObjectStackCache();
	if ($nc(type)->isPrimitive()) {
		$init($Integer);
		if (type == $Integer::TYPE) {
			return "I"_s;
		} else {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				return "Z"_s;
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					return "B"_s;
				} else {
					$init($Character);
					if (type == $Character::TYPE) {
						return "C"_s;
					} else {
						$init($Short);
						if (type == $Short::TYPE) {
							return "S"_s;
						} else {
							$init($Long);
							if (type == $Long::TYPE) {
								return "J"_s;
							} else {
								$init($Float);
								if (type == $Float::TYPE) {
									return "F"_s;
								} else {
									$init($Double);
									if (type == $Double::TYPE) {
										return "D"_s;
									} else {
										$init($Void);
										if (type == $Void::TYPE) {
											return "V"_s;
										} else {
											$throwNew($Error, $$str({"unrecognized primitive type: "_s, type}));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} else if (type->isArray()) {
		return $nc($(type->getName()))->replace(u'.', u'/');
	} else {
		return $str({"L"_s, $($nc($(type->getName()))->replace(u'.', u'/')), ";"_s});
	}
}

$String* Util::getUnqualifiedName($Class* c) {
	$init(Util);
	$var($String, binaryName, $nc(c)->getName());
	return $nc(binaryName)->substring(binaryName->lastIndexOf((int32_t)u'.') + 1);
}

$Boolean* Util::lambda$static$1() {
	$init(Util);
	return $Boolean::valueOf($Boolean::getBoolean("java.rmi.server.ignoreStubClasses"_s));
}

$String* Util::lambda$static$0() {
	$init(Util);
	return $System::getProperty("sun.rmi.server.logLevel"_s);
}

void clinit$Util($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	Util::logLevel = $LogStream::parseLevel($cast($String, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Util$$Lambda$lambda$static$0))))));
	$assignStatic(Util::serverRefLog, $Log::getLog("sun.rmi.server.ref"_s, "transport"_s, Util::logLevel));
	Util::ignoreStubClasses = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Util$$Lambda$lambda$static$1$1)))))))->booleanValue();
	$assignStatic(Util::withoutStubs, $Collections::synchronizedMap($$new($WeakHashMap, 11)));
	$load($RemoteRef);
	$assignStatic(Util::stubConsParamTypes, $new($ClassArray, {$RemoteRef::class$}));
}

Util::Util() {
}

$Class* Util::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Util$$Lambda$lambda$static$0::classInfo$.name)) {
			return Util$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(Util$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return Util$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
	}
	$loadClass(Util, name, initialize, &_Util_ClassInfo_, clinit$Util, allocate$Util);
	return class$;
}

$Class* Util::class$ = nullptr;

		} // server
	} // rmi
} // sun