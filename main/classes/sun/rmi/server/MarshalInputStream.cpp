#include <sun/rmi/server/MarshalInputStream.h>

#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectStreamClass.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/NoClassDefFoundError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/server/RMIClassLoader.h>
#include <java/security/AccessControlException.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <jdk/internal/misc/VM.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectStreamClass = ::java::io::ObjectStreamClass;
using $Serializable = ::java::io::Serializable;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoClassDefFoundError = ::java::lang::NoClassDefFoundError;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $RMIClassLoader = ::java::rmi::server::RMIClassLoader;
using $AccessControlException = ::java::security::AccessControlException;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $VM = ::jdk::internal::misc::VM;

namespace sun {
	namespace rmi {
		namespace server {

class MarshalInputStream$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(MarshalInputStream$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(MarshalInputStream::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MarshalInputStream$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MarshalInputStream$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MarshalInputStream$$Lambda$lambda$static$0::*)()>(&MarshalInputStream$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MarshalInputStream$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.MarshalInputStream$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* MarshalInputStream$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(MarshalInputStream$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MarshalInputStream$$Lambda$lambda$static$0::class$ = nullptr;

$FieldInfo _MarshalInputStream_FieldInfo_[] = {
	{"useCodebaseOnlyProperty", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MarshalInputStream, useCodebaseOnlyProperty)},
	{"permittedSunClasses", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PROTECTED | $STATIC, $staticField(MarshalInputStream, permittedSunClasses)},
	{"skipDefaultResolveClass", "Z", nullptr, $PRIVATE, $field(MarshalInputStream, skipDefaultResolveClass$)},
	{"doneCallbacks", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Object;Ljava/lang/Runnable;>;", $PRIVATE | $FINAL, $field(MarshalInputStream, doneCallbacks)},
	{"useCodebaseOnly", "Z", nullptr, $PRIVATE, $field(MarshalInputStream, useCodebaseOnly$)},
	{}
};

$MethodInfo _MarshalInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(MarshalInputStream::*)($InputStream*)>(&MarshalInputStream::init$)), "java.io.IOException,java.io.StreamCorruptedException"},
	{"checkSunClass", "(Ljava/lang/String;Ljava/security/AccessControlException;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/security/AccessControlException;)Ljava/lang/Class<*>;", $PRIVATE, $method(static_cast<$Class*(MarshalInputStream::*)($String*,$AccessControlException*)>(&MarshalInputStream::checkSunClass)), "java.security.AccessControlException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"done", "()V", nullptr, $PUBLIC},
	{"getDoneCallback", "(Ljava/lang/Object;)Ljava/lang/Runnable;", nullptr, $PUBLIC},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&MarshalInputStream::lambda$static$0))},
	{"latestUserDefinedLoader", "()Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ClassLoader*(*)()>(&MarshalInputStream::latestUserDefinedLoader))},
	{"readLocation", "()Ljava/lang/Object;", nullptr, $PROTECTED, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"resolveClass", "(Ljava/io/ObjectStreamClass;)Ljava/lang/Class;", "(Ljava/io/ObjectStreamClass;)Ljava/lang/Class<*>;", $PROTECTED, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"resolveProxyClass", "([Ljava/lang/String;)Ljava/lang/Class;", "([Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setDoneCallback", "(Ljava/lang/Object;Ljava/lang/Runnable;)V", nullptr, $PUBLIC},
	{"skipDefaultResolveClass", "()V", nullptr, 0},
	{"useCodebaseOnly", "()V", nullptr, 0},
	{}
};

$ClassInfo _MarshalInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.server.MarshalInputStream",
	"java.io.ObjectInputStream",
	nullptr,
	_MarshalInputStream_FieldInfo_,
	_MarshalInputStream_MethodInfo_
};

$Object* allocate$MarshalInputStream($Class* clazz) {
	return $of($alloc(MarshalInputStream));
}

bool MarshalInputStream::useCodebaseOnlyProperty = false;
$Map* MarshalInputStream::permittedSunClasses = nullptr;

void MarshalInputStream::init$($InputStream* in) {
	$ObjectInputStream::init$(in);
	this->skipDefaultResolveClass$ = false;
	$set(this, doneCallbacks, $new($HashMap, 3));
	this->useCodebaseOnly$ = MarshalInputStream::useCodebaseOnlyProperty;
}

$Runnable* MarshalInputStream::getDoneCallback(Object$* key) {
	return $cast($Runnable, $nc(this->doneCallbacks)->get(key));
}

void MarshalInputStream::setDoneCallback(Object$* key, $Runnable* callback) {
	$nc(this->doneCallbacks)->put(key, callback);
}

void MarshalInputStream::done() {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, iter, $nc($($nc(this->doneCallbacks)->values()))->iterator());
	while ($nc(iter)->hasNext()) {
		$var($Runnable, callback, $cast($Runnable, iter->next()));
		$nc(callback)->run();
	}
	$nc(this->doneCallbacks)->clear();
}

void MarshalInputStream::close() {
	done();
	$ObjectInputStream::close();
}

$Class* MarshalInputStream::resolveClass($ObjectStreamClass* classDesc) {
	$useLocalCurrentObjectStackCache();
	$var($Object, annotation, readLocation());
	$var($String, className, $nc(classDesc)->getName());
	$var($ClassLoader, defaultLoader, this->skipDefaultResolveClass$ ? ($ClassLoader*)nullptr : latestUserDefinedLoader());
	$var($String, codebase, nullptr);
	if (!this->useCodebaseOnly$ && $instanceOf($String, annotation)) {
		$assign(codebase, $cast($String, annotation));
	}
	try {
		return $RMIClassLoader::loadClass(codebase, className, defaultLoader);
	} catch ($AccessControlException& e) {
		return checkSunClass(className, e);
	} catch ($ClassNotFoundException& e) {
		try {
			bool var$0 = $Character::isLowerCase($nc(className)->charAt(0));
			if (var$0 && $nc(className)->indexOf((int32_t)u'.') == -1) {
				return $ObjectInputStream::resolveClass(classDesc);
			}
		} catch ($ClassNotFoundException& e2) {
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

$Class* MarshalInputStream::resolveProxyClass($StringArray* interfaces) {
	$useLocalCurrentObjectStackCache();
	$var($Object, annotation, readLocation());
	$var($ClassLoader, defaultLoader, this->skipDefaultResolveClass$ ? ($ClassLoader*)nullptr : latestUserDefinedLoader());
	$var($String, codebase, nullptr);
	if (!this->useCodebaseOnly$ && $instanceOf($String, annotation)) {
		$assign(codebase, $cast($String, annotation));
	}
	return $RMIClassLoader::loadProxyClass(codebase, interfaces, defaultLoader);
}

$ClassLoader* MarshalInputStream::latestUserDefinedLoader() {
	$init(MarshalInputStream);
	return $VM::latestUserDefinedLoader();
}

$Class* MarshalInputStream::checkSunClass($String* className, $AccessControlException* e) {
	$useLocalCurrentObjectStackCache();
	$var($Permission, perm, $nc(e)->getPermission());
	$var($String, name, nullptr);
	if (perm != nullptr) {
		$assign(name, perm->getName());
	}
	$Class* resolvedClass = $cast($Class, $nc(MarshalInputStream::permittedSunClasses)->get(className));
	bool var$0 = (name == nullptr) || (resolvedClass == nullptr);
	if (!var$0) {
		bool var$1 = (!$nc(name)->equals("accessClassInPackage.sun.rmi.server"_s));
		var$0 = (var$1 && (!name->equals("accessClassInPackage.sun.rmi.registry"_s)));
	}
	if (var$0) {
		$throw(e);
	}
	return resolvedClass;
}

$Object* MarshalInputStream::readLocation() {
	return $of(readObject());
}

void MarshalInputStream::skipDefaultResolveClass() {
	this->skipDefaultResolveClass$ = true;
}

void MarshalInputStream::useCodebaseOnly() {
	this->useCodebaseOnly$ = true;
}

$String* MarshalInputStream::lambda$static$0() {
	$init(MarshalInputStream);
	return $System::getProperty("java.rmi.server.useCodebaseOnly"_s, "true"_s);
}

void clinit$MarshalInputStream($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	MarshalInputStream::useCodebaseOnlyProperty = !$nc(($cast($String, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(MarshalInputStream$$Lambda$lambda$static$0)))))))->equalsIgnoreCase("false"_s);
	$assignStatic(MarshalInputStream::permittedSunClasses, $new($HashMap, 3));
	{
		try {
			$var($String, registry, "sun.rmi.registry.RegistryImpl_Stub"_s);
			$nc(MarshalInputStream::permittedSunClasses)->put(registry, $Class::forName(registry));
		} catch ($ClassNotFoundException& e) {
			$throwNew($NoClassDefFoundError, $$str({"Missing system class: "_s, $(e->getMessage())}));
		}
	}
}

MarshalInputStream::MarshalInputStream() {
}

$Class* MarshalInputStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MarshalInputStream$$Lambda$lambda$static$0::classInfo$.name)) {
			return MarshalInputStream$$Lambda$lambda$static$0::load$(name, initialize);
		}
	}
	$loadClass(MarshalInputStream, name, initialize, &_MarshalInputStream_ClassInfo_, clinit$MarshalInputStream, allocate$MarshalInputStream);
	return class$;
}

$Class* MarshalInputStream::class$ = nullptr;

		} // server
	} // rmi
} // sun