#include <sun/rmi/server/LoaderHandler.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/SoftReference.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/net/JarURLConnection.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <java/net/URLConnection.h>
#include <java/rmi/server/LogStream.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/SecureClassLoader.h>
#include <java/security/cert/Certificate.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/PropertyPermission.h>
#include <java/util/StringTokenizer.h>
#include <java/util/WeakHashMap.h>
#include <java/util/logging/Level.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/LoaderHandler$1.h>
#include <sun/rmi/server/LoaderHandler$2.h>
#include <sun/rmi/server/LoaderHandler$Loader.h>
#include <sun/rmi/server/LoaderHandler$LoaderEntry.h>
#include <sun/rmi/server/LoaderHandler$LoaderKey.h>
#include <jcpp.h>

#undef BRIEF
#undef VERBOSE

using $ClassLoaderArray = $Array<::java::lang::ClassLoader>;
using $URLArray = $Array<::java::net::URL>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessError = ::java::lang::IllegalAccessError;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $SoftReference = ::java::lang::ref::SoftReference;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $JarURLConnection = ::java::net::JarURLConnection;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $URLClassLoader = ::java::net::URLClassLoader;
using $URLConnection = ::java::net::URLConnection;
using $LogStream = ::java::rmi::server::LogStream;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $SecureClassLoader = ::java::security::SecureClassLoader;
using $Certificate = ::java::security::cert::Certificate;
using $AbstractMap = ::java::util::AbstractMap;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $PropertyPermission = ::java::util::PropertyPermission;
using $StringTokenizer = ::java::util::StringTokenizer;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Level = ::java::util::logging::Level;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $Log = ::sun::rmi::runtime::Log;
using $LoaderHandler$1 = ::sun::rmi::server::LoaderHandler$1;
using $LoaderHandler$2 = ::sun::rmi::server::LoaderHandler$2;
using $LoaderHandler$Loader = ::sun::rmi::server::LoaderHandler$Loader;
using $LoaderHandler$LoaderEntry = ::sun::rmi::server::LoaderHandler$LoaderEntry;
using $LoaderHandler$LoaderKey = ::sun::rmi::server::LoaderHandler$LoaderKey;

namespace sun {
	namespace rmi {
		namespace server {

class LoaderHandler$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(LoaderHandler$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(LoaderHandler::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoaderHandler$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LoaderHandler$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LoaderHandler$$Lambda$lambda$static$0::*)()>(&LoaderHandler$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LoaderHandler$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.LoaderHandler$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* LoaderHandler$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoaderHandler$$Lambda$lambda$static$0::class$ = nullptr;

class LoaderHandler$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(LoaderHandler$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(LoaderHandler::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoaderHandler$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LoaderHandler$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LoaderHandler$$Lambda$lambda$static$1$1::*)()>(&LoaderHandler$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LoaderHandler$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.server.LoaderHandler$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* LoaderHandler$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoaderHandler$$Lambda$lambda$static$1$1::class$ = nullptr;

$FieldInfo _LoaderHandler_FieldInfo_[] = {
	{"logLevel", "I", nullptr, $STATIC | $FINAL, $staticField(LoaderHandler, logLevel)},
	{"loaderLog", "Lsun/rmi/runtime/Log;", nullptr, $STATIC | $FINAL, $staticField(LoaderHandler, loaderLog)},
	{"codebaseProperty", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(LoaderHandler, codebaseProperty)},
	{"codebaseURLs", "[Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticField(LoaderHandler, codebaseURLs)},
	{"codebaseLoaders", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/ClassLoader;Ljava/lang/Void;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LoaderHandler, codebaseLoaders)},
	{"loaderTable", "Ljava/util/HashMap;", "Ljava/util/HashMap<Lsun/rmi/server/LoaderHandler$LoaderKey;Lsun/rmi/server/LoaderHandler$LoaderEntry;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LoaderHandler, loaderTable)},
	{"refQueue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Lsun/rmi/server/LoaderHandler$Loader;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LoaderHandler, refQueue)},
	{"pathToURLsCache", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[Ljava/lang/Object;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LoaderHandler, pathToURLsCache)},
	{}
};

$MethodInfo _LoaderHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(LoaderHandler::*)()>(&LoaderHandler::init$))},
	{"addPermissionsForURLs", "([Ljava/net/URL;Ljava/security/PermissionCollection;Z)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($URLArray*,$PermissionCollection*,bool)>(&LoaderHandler::addPermissionsForURLs))},
	{"getClassAnnotation", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PUBLIC | $STATIC, $method(static_cast<$String*(*)($Class*)>(&LoaderHandler::getClassAnnotation))},
	{"getClassLoader", "(Ljava/lang/String;)Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ClassLoader*(*)($String*)>(&LoaderHandler::getClassLoader)), "java.net.MalformedURLException"},
	{"getDefaultCodebaseURLs", "()[Ljava/net/URL;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<$URLArray*(*)()>(&LoaderHandler::getDefaultCodebaseURLs)), "java.net.MalformedURLException"},
	{"getLoaderAccessControlContext", "([Ljava/net/URL;)Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$AccessControlContext*(*)($URLArray*)>(&LoaderHandler::getLoaderAccessControlContext))},
	{"getRMIContextClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ClassLoader*(*)()>(&LoaderHandler::getRMIContextClassLoader))},
	{"getSecurityContext", "(Ljava/lang/ClassLoader;)Ljava/lang/Object;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Object*(*)($ClassLoader*)>(&LoaderHandler::getSecurityContext))},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&LoaderHandler::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&LoaderHandler::lambda$static$1))},
	{"loadClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $method(static_cast<$Class*(*)($String*,$String*,$ClassLoader*)>(&LoaderHandler::loadClass)), "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{"loadClass", "([Ljava/net/URL;Ljava/lang/String;)Ljava/lang/Class;", "([Ljava/net/URL;Ljava/lang/String;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $method(static_cast<$Class*(*)($URLArray*,$String*)>(&LoaderHandler::loadClass)), "java.lang.ClassNotFoundException"},
	{"loadClassForName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $method(static_cast<$Class*(*)($String*,bool,$ClassLoader*)>(&LoaderHandler::loadClassForName)), "java.lang.ClassNotFoundException"},
	{"loadProxyClass", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $method(static_cast<$Class*(*)($String*,$StringArray*,$ClassLoader*)>(&LoaderHandler::loadProxyClass)), "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{"loadProxyClass", "([Ljava/lang/String;Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;Z)Ljava/lang/Class;", "([Ljava/lang/String;Ljava/lang/ClassLoader;Ljava/lang/ClassLoader;Z)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $method(static_cast<$Class*(*)($StringArray*,$ClassLoader*,$ClassLoader*,bool)>(&LoaderHandler::loadProxyClass)), "java.lang.ClassNotFoundException"},
	{"loadProxyClass", "(Ljava/lang/ClassLoader;[Ljava/lang/Class;)Ljava/lang/Class;", "(Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $method(static_cast<$Class*(*)($ClassLoader*,$ClassArray*)>(&LoaderHandler::loadProxyClass)), "java.lang.ClassNotFoundException"},
	{"loadProxyInterfaces", "([Ljava/lang/String;Ljava/lang/ClassLoader;[Ljava/lang/Class;[Z)Ljava/lang/ClassLoader;", "([Ljava/lang/String;Ljava/lang/ClassLoader;[Ljava/lang/Class<*>;[Z)Ljava/lang/ClassLoader;", $PRIVATE | $STATIC, $method(static_cast<$ClassLoader*(*)($StringArray*,$ClassLoader*,$ClassArray*,$booleans*)>(&LoaderHandler::loadProxyInterfaces)), "java.lang.ClassNotFoundException"},
	{"lookupLoader", "([Ljava/net/URL;Ljava/lang/ClassLoader;)Lsun/rmi/server/LoaderHandler$Loader;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$LoaderHandler$Loader*(*)($URLArray*,$ClassLoader*)>(&LoaderHandler::lookupLoader))},
	{"pathToURLs", "(Ljava/lang/String;)[Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$URLArray*(*)($String*)>(&LoaderHandler::pathToURLs)), "java.net.MalformedURLException"},
	{"registerCodebaseLoader", "(Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($ClassLoader*)>(&LoaderHandler::registerCodebaseLoader))},
	{"urlsToPath", "([Ljava/net/URL;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($URLArray*)>(&LoaderHandler::urlsToPath))},
	{}
};

$InnerClassInfo _LoaderHandler_InnerClassesInfo_[] = {
	{"sun.rmi.server.LoaderHandler$Loader", "sun.rmi.server.LoaderHandler", "Loader", $PRIVATE | $STATIC},
	{"sun.rmi.server.LoaderHandler$LoaderEntry", "sun.rmi.server.LoaderHandler", "LoaderEntry", $PRIVATE | $STATIC},
	{"sun.rmi.server.LoaderHandler$LoaderKey", "sun.rmi.server.LoaderHandler", "LoaderKey", $PRIVATE | $STATIC},
	{"sun.rmi.server.LoaderHandler$2", nullptr, nullptr, 0},
	{"sun.rmi.server.LoaderHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LoaderHandler_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.server.LoaderHandler",
	"java.lang.Object",
	nullptr,
	_LoaderHandler_FieldInfo_,
	_LoaderHandler_MethodInfo_,
	nullptr,
	nullptr,
	_LoaderHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.server.LoaderHandler$Loader,sun.rmi.server.LoaderHandler$LoaderEntry,sun.rmi.server.LoaderHandler$LoaderKey,sun.rmi.server.LoaderHandler$2,sun.rmi.server.LoaderHandler$1"
};

$Object* allocate$LoaderHandler($Class* clazz) {
	return $of($alloc(LoaderHandler));
}

int32_t LoaderHandler::logLevel = 0;
$Log* LoaderHandler::loaderLog = nullptr;
$String* LoaderHandler::codebaseProperty = nullptr;
$URLArray* LoaderHandler::codebaseURLs = nullptr;
$Map* LoaderHandler::codebaseLoaders = nullptr;
$HashMap* LoaderHandler::loaderTable = nullptr;
$ReferenceQueue* LoaderHandler::refQueue = nullptr;
$Map* LoaderHandler::pathToURLsCache = nullptr;

void LoaderHandler::init$() {
}

$URLArray* LoaderHandler::getDefaultCodebaseURLs() {
	$load(LoaderHandler);
	$synchronized(class$) {
		$init(LoaderHandler);
		if (LoaderHandler::codebaseURLs == nullptr) {
			if (LoaderHandler::codebaseProperty != nullptr) {
				$assignStatic(LoaderHandler::codebaseURLs, pathToURLs(LoaderHandler::codebaseProperty));
			} else {
				$assignStatic(LoaderHandler::codebaseURLs, $new($URLArray, 0));
			}
		}
		return LoaderHandler::codebaseURLs;
	}
}

$Class* LoaderHandler::loadClass($String* codebase, $String* name, $ClassLoader* defaultLoader) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($Log);
	if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
		$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, $$str({"name = \""_s, name, "\", codebase = \""_s, (codebase != nullptr ? codebase : ""_s), "\""_s, (defaultLoader != nullptr ? $$str({", defaultLoader = "_s, defaultLoader}) : ""_s)}));
	}
	$var($URLArray, urls, nullptr);
	if (codebase != nullptr) {
		$assign(urls, pathToURLs(codebase));
	} else {
		$assign(urls, getDefaultCodebaseURLs());
	}
	if (defaultLoader != nullptr) {
		try {
			$Class* c = loadClassForName(name, false, defaultLoader);
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
				$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"class \""_s, name, "\" found via defaultLoader, defined by "_s, $($nc(c)->getClassLoader())}));
			}
			return c;
		} catch ($ClassNotFoundException& e) {
		}
	}
	return loadClass(urls, name);
}

$String* LoaderHandler::getClassAnnotation($Class* cl) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, name, $nc(cl)->getName());
	int32_t nameLength = $nc(name)->length();
	if (nameLength > 0 && name->charAt(0) == u'[') {
		int32_t i = 1;
		while (nameLength > i && name->charAt(i) == u'[') {
			++i;
		}
		if (nameLength > i && name->charAt(i) != u'L') {
			return nullptr;
		}
	}
	$var($ClassLoader, loader, cl->getClassLoader());
	if (loader == nullptr || $nc(LoaderHandler::codebaseLoaders)->containsKey(loader)) {
		return LoaderHandler::codebaseProperty;
	}
	$var($String, annotation, nullptr);
	if ($instanceOf($LoaderHandler$Loader, loader)) {
		$assign(annotation, $nc(($cast($LoaderHandler$Loader, loader)))->getClassAnnotation());
	} else if ($instanceOf($URLClassLoader, loader)) {
		try {
			$var($URLArray, urls, $nc(($cast($URLClassLoader, loader)))->getURLs());
			if (urls != nullptr) {
				$var($SecurityManager, sm, $System::getSecurityManager());
				if (sm != nullptr) {
					$var($Permissions, perms, $new($Permissions));
					for (int32_t i = 0; i < urls->length; ++i) {
						$var($Permission, p, $nc($($nc(urls->get(i))->openConnection()))->getPermission());
						if (p != nullptr) {
							if (!perms->implies(p)) {
								sm->checkPermission(p);
								perms->add(p);
							}
						}
					}
				}
				$assign(annotation, urlsToPath(urls));
			}
		} catch ($SecurityException& e) {
		} catch ($IOException& e) {
		}
	}
	if (annotation != nullptr) {
		return annotation;
	} else {
		return LoaderHandler::codebaseProperty;
	}
}

$ClassLoader* LoaderHandler::getClassLoader($String* codebase) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$var($ClassLoader, parent, getRMIContextClassLoader());
	$var($URLArray, urls, nullptr);
	if (codebase != nullptr) {
		$assign(urls, pathToURLs(codebase));
	} else {
		$assign(urls, getDefaultCodebaseURLs());
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "getClassLoader"_s));
	} else {
		return parent;
	}
	$var($LoaderHandler$Loader, loader, lookupLoader(urls, parent));
	if (loader != nullptr) {
		loader->checkPermissions();
	}
	return loader;
}

$Object* LoaderHandler::getSecurityContext($ClassLoader* loader) {
	$init(LoaderHandler);
	if ($instanceOf($LoaderHandler$Loader, loader)) {
		$var($URLArray, urls, $nc(($cast($LoaderHandler$Loader, loader)))->getURLs());
		if ($nc(urls)->length > 0) {
			return $of(urls->get(0));
		}
	}
	return $of(nullptr);
}

void LoaderHandler::registerCodebaseLoader($ClassLoader* loader) {
	$init(LoaderHandler);
	$nc(LoaderHandler::codebaseLoaders)->put(loader, nullptr);
}

$Class* LoaderHandler::loadClass($URLArray* urls, $String* name) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, parent, getRMIContextClassLoader());
	$init($Log);
	if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
		$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"(thread context class loader: "_s, parent, ")"_s}));
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		try {
			$Class* c = $Class::forName(name, false, parent);
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
				$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"class \""_s, name, "\" found via thread context class loader (no security manager: codebase disabled), defined by "_s, $($nc(c)->getClassLoader())}));
			}
			return c;
		} catch ($ClassNotFoundException& e) {
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
				$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, $$str({"class \""_s, name, "\" not found via thread context class loader (no security manager: codebase disabled)"_s}), e);
			}
			$var($String, var$0, $str({$(e->getMessage()), " (no security manager: RMI class loader disabled)"_s}));
			$throwNew($ClassNotFoundException, var$0, $(e->getException()));
		}
	}
	$var($LoaderHandler$Loader, loader, lookupLoader(urls, parent));
	try {
		if (loader != nullptr) {
			loader->checkPermissions();
		}
	} catch ($SecurityException& e) {
		try {
			$Class* c = loadClassForName(name, false, parent);
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
				$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"class \""_s, name, "\" found via thread context class loader (access to codebase denied), defined by "_s, $($nc(c)->getClassLoader())}));
			}
			return c;
		} catch ($ClassNotFoundException& unimportant) {
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
				$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, $$str({"class \""_s, name, "\" not found via thread context class loader (access to codebase denied)"_s}), e);
			}
			$throwNew($ClassNotFoundException, "access to class loader denied"_s, e);
		}
	}
	try {
		$Class* c = loadClassForName(name, false, loader);
		if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
			$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"class \""_s, name, "\" found via codebase, defined by "_s, $($nc(c)->getClassLoader())}));
		}
		return c;
	} catch ($ClassNotFoundException& e) {
		if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
			$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, $$str({"class \""_s, name, "\" not found via codebase"_s}), e);
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

$Class* LoaderHandler::loadProxyClass($String* codebase, $StringArray* interfaces, $ClassLoader* defaultLoader) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($Log);
	if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
		$var($String, var$0, $$str({"interfaces = "_s, $($Arrays::asList(interfaces)), ", codebase = \""_s, (codebase != nullptr ? codebase : ""_s), "\""_s}));
		$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, $$concat(var$0, (defaultLoader != nullptr ? $$str({", defaultLoader = "_s, defaultLoader}) : ""_s)));
	}
	$var($ClassLoader, parent, getRMIContextClassLoader());
	if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
		$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"(thread context class loader: "_s, parent, ")"_s}));
	}
	$var($URLArray, urls, nullptr);
	if (codebase != nullptr) {
		$assign(urls, pathToURLs(codebase));
	} else {
		$assign(urls, getDefaultCodebaseURLs());
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		try {
			$Class* c = loadProxyClass(interfaces, defaultLoader, parent, false);
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
				$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"(no security manager: codebase disabled) proxy class defined by "_s, $($nc(c)->getClassLoader())}));
			}
			return c;
		} catch ($ClassNotFoundException& e) {
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
				$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, "(no security manager: codebase disabled) proxy class resolution failed"_s, e);
			}
			$var($String, var$1, $str({$(e->getMessage()), " (no security manager: RMI class loader disabled)"_s}));
			$throwNew($ClassNotFoundException, var$1, $(e->getException()));
		}
	}
	$var($LoaderHandler$Loader, loader, lookupLoader(urls, parent));
	try {
		if (loader != nullptr) {
			loader->checkPermissions();
		}
	} catch ($SecurityException& e) {
		try {
			$Class* c = loadProxyClass(interfaces, defaultLoader, parent, false);
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
				$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"(access to codebase denied) proxy class defined by "_s, $($nc(c)->getClassLoader())}));
			}
			return c;
		} catch ($ClassNotFoundException& unimportant) {
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
				$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, "(access to codebase denied) proxy class resolution failed"_s, e);
			}
			$throwNew($ClassNotFoundException, "access to class loader denied"_s, e);
		}
	}
	try {
		$Class* c = loadProxyClass(interfaces, defaultLoader, loader, true);
		if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
			$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"proxy class defined by "_s, $($nc(c)->getClassLoader())}));
		}
		return c;
	} catch ($ClassNotFoundException& e) {
		if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::BRIEF)) {
			$nc(LoaderHandler::loaderLog)->log($Log::BRIEF, "proxy class resolution failed"_s, e);
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

$Class* LoaderHandler::loadProxyClass($StringArray* interfaceNames, $ClassLoader* defaultLoader, $ClassLoader* codebaseLoader, bool preferCodebase) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, proxyLoader, nullptr);
	$var($ClassArray, classObjs, $new($ClassArray, $nc(interfaceNames)->length));
	$var($booleans, nonpublic, $new($booleans, {false}));
	bool defaultLoaderCase$break = false;
	for (;;) {
		if (defaultLoader != nullptr) {
			try {
				$assign(proxyLoader, loadProxyInterfaces(interfaceNames, defaultLoader, classObjs, nonpublic));
				$init($Log);
				if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
					$var($ClassLoaderArray, definingLoaders, $new($ClassLoaderArray, classObjs->length));
					for (int32_t i = 0; i < definingLoaders->length; ++i) {
						definingLoaders->set(i, $($nc(classObjs->get(i))->getClassLoader()));
					}
					$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"proxy interfaces found via defaultLoader, defined by "_s, $($Arrays::asList(definingLoaders))}));
				}
			} catch ($ClassNotFoundException& e) {
				defaultLoaderCase$break = true;
				break;
			}
			if (!nonpublic->get(0)) {
				if (preferCodebase) {
					try {
						return $Proxy::getProxyClass(codebaseLoader, classObjs);
					} catch ($IllegalArgumentException& e) {
					}
				}
				$assign(proxyLoader, defaultLoader);
			}
			return loadProxyClass(proxyLoader, classObjs);
		}
		break;
	}
	nonpublic->set(0, false);
	$assign(proxyLoader, loadProxyInterfaces(interfaceNames, codebaseLoader, classObjs, nonpublic));
	$init($Log);
	if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
		$var($ClassLoaderArray, definingLoaders, $new($ClassLoaderArray, classObjs->length));
		for (int32_t i = 0; i < definingLoaders->length; ++i) {
			definingLoaders->set(i, $($nc(classObjs->get(i))->getClassLoader()));
		}
		$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"proxy interfaces found via codebase, defined by "_s, $($Arrays::asList(definingLoaders))}));
	}
	if (!nonpublic->get(0)) {
		$assign(proxyLoader, codebaseLoader);
	}
	return loadProxyClass(proxyLoader, classObjs);
}

$Class* LoaderHandler::loadProxyClass($ClassLoader* loader, $ClassArray* interfaces) {
	$init(LoaderHandler);
	$beforeCallerSensitive();
	try {
		return $Proxy::getProxyClass(loader, interfaces);
	} catch ($IllegalArgumentException& e) {
		$throwNew($ClassNotFoundException, "error creating dynamic proxy class"_s, e);
	}
	$shouldNotReachHere();
}

$ClassLoader* LoaderHandler::loadProxyInterfaces($StringArray* interfaces, $ClassLoader* loader, $ClassArray* classObjs, $booleans* nonpublic) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, nonpublicLoader, nullptr);
	for (int32_t i = 0; i < $nc(interfaces)->length; ++i) {
		$Class* cl = ($nc(classObjs)->set(i, loadClassForName(interfaces->get(i), false, loader)));
		if (!$Modifier::isPublic($nc(cl)->getModifiers())) {
			$var($ClassLoader, current, $nc(cl)->getClassLoader());
			$init($Log);
			if ($nc(LoaderHandler::loaderLog)->isLoggable($Log::VERBOSE)) {
				$nc(LoaderHandler::loaderLog)->log($Log::VERBOSE, $$str({"non-public interface \""_s, interfaces->get(i), "\" defined by "_s, current}));
			}
			if (!$nc(nonpublic)->get(0)) {
				$assign(nonpublicLoader, current);
				nonpublic->set(0, true);
			} else if (current != nonpublicLoader) {
				$throwNew($IllegalAccessError, "non-public interfaces defined in different class loaders"_s);
			}
		}
	}
	return nonpublicLoader;
}

$URLArray* LoaderHandler::pathToURLs($String* path) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$synchronized(LoaderHandler::pathToURLsCache) {
		$var($ObjectArray, v, $cast($ObjectArray, $nc(LoaderHandler::pathToURLsCache)->get(path)));
		if (v != nullptr) {
			return ($cast($URLArray, v->get(0)));
		}
	}
	$var($StringTokenizer, st, $new($StringTokenizer, path));
	$var($URLArray, urls, $new($URLArray, st->countTokens()));
	for (int32_t i = 0; st->hasMoreTokens(); ++i) {
		urls->set(i, $$new($URL, $(st->nextToken())));
	}
	$synchronized(LoaderHandler::pathToURLsCache) {
		$nc(LoaderHandler::pathToURLsCache)->put(path, $$new($ObjectArray, {
			$of(urls),
			$of($$new($SoftReference, path))
		}));
	}
	return urls;
}

$String* LoaderHandler::urlsToPath($URLArray* urls) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	if ($nc(urls)->length == 0) {
		return nullptr;
	} else if (urls->length == 1) {
		return $nc(urls->get(0))->toExternalForm();
	} else {
		$var($StringBuilder, path, $new($StringBuilder, $($nc(urls->get(0))->toExternalForm())));
		for (int32_t i = 1; i < urls->length; ++i) {
			path->append(u' ');
			path->append($($nc(urls->get(i))->toExternalForm()));
		}
		return path->toString();
	}
}

$ClassLoader* LoaderHandler::getRMIContextClassLoader() {
	$init(LoaderHandler);
	$beforeCallerSensitive();
	return $($Thread::currentThread())->getContextClassLoader();
}

$LoaderHandler$Loader* LoaderHandler::lookupLoader($URLArray* urls, $ClassLoader* parent) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($LoaderHandler$LoaderEntry, entry, nullptr);
	$var($LoaderHandler$Loader, loader, nullptr);
	$synchronized(LoaderHandler::class$) {
		while (($assign(entry, $cast($LoaderHandler$LoaderEntry, $nc(LoaderHandler::refQueue)->poll()))) != nullptr) {
			if (!$nc(entry)->removed) {
				$nc(LoaderHandler::loaderTable)->remove(entry->key);
			}
		}
		$var($LoaderHandler$LoaderKey, key, $new($LoaderHandler$LoaderKey, urls, parent));
		$assign(entry, $cast($LoaderHandler$LoaderEntry, $nc(LoaderHandler::loaderTable)->get(key)));
		if (entry == nullptr || ($assign(loader, $cast($LoaderHandler$Loader, $nc(entry)->get()))) == nullptr) {
			if (entry != nullptr) {
				$nc(LoaderHandler::loaderTable)->remove(key);
				entry->removed = true;
			}
			$var($AccessControlContext, acc, getLoaderAccessControlContext(urls));
			$assign(loader, $cast($LoaderHandler$Loader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LoaderHandler$1, urls, parent)), acc)));
			$assign(entry, $new($LoaderHandler$LoaderEntry, key, loader));
			$nc(LoaderHandler::loaderTable)->put(key, entry);
		}
	}
	return loader;
}

$AccessControlContext* LoaderHandler::getLoaderAccessControlContext($URLArray* urls) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PermissionCollection, perms, $cast($PermissionCollection, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LoaderHandler$2)))));
	$nc(perms)->add($$new($RuntimePermission, "createClassLoader"_s));
	perms->add($$new($PropertyPermission, "java.*"_s, "read"_s));
	addPermissionsForURLs(urls, perms, true);
	$var($ProtectionDomain, pd, $new($ProtectionDomain, $$new($CodeSource, ($nc(urls)->length > 0 ? $nc(urls)->get(0) : ($URL*)nullptr), ($CertificateArray*)nullptr), perms));
	return $new($AccessControlContext, $$new($ProtectionDomainArray, {pd}));
}

void LoaderHandler::addPermissionsForURLs($URLArray* urls, $PermissionCollection* perms, bool forLoader) {
	$init(LoaderHandler);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(urls)->length; ++i) {
		$var($URL, url, urls->get(i));
		try {
			$var($URLConnection, urlConnection, $nc(url)->openConnection());
			$var($Permission, p, $nc(urlConnection)->getPermission());
			if (p != nullptr) {
				if ($instanceOf($FilePermission, p)) {
					$var($String, path, p->getName());
					$init($File);
					int32_t endIndex = $nc(path)->lastIndexOf((int32_t)$File::separatorChar);
					if (endIndex != -1) {
						$assign(path, path->substring(0, endIndex + 1));
						if (path->endsWith($File::separator)) {
							$plusAssign(path, "-"_s);
						}
						$var($Permission, p2, $new($FilePermission, path, "read"_s));
						if (!$nc(perms)->implies(p2)) {
							perms->add(p2);
						}
						$nc(perms)->add($$new($FilePermission, path, "read"_s));
					} else if (!$nc(perms)->implies(p)) {
						perms->add(p);
					}
				} else {
					if (!$nc(perms)->implies(p)) {
						perms->add(p);
					}
					if (forLoader) {
						$var($URL, hostURL, url);
						{
							$var($URLConnection, conn, urlConnection);
							for (; $instanceOf($JarURLConnection, conn);) {
								$assign(hostURL, $nc(($cast($JarURLConnection, conn)))->getJarFileURL());
								$assign(conn, $nc(hostURL)->openConnection());
							}
						}
						$var($String, host, $nc(hostURL)->getHost());
						if (host != nullptr && p->implies($$new($SocketPermission, host, "resolve"_s))) {
							$var($Permission, p2, $new($SocketPermission, host, "connect,accept"_s));
							if (!$nc(perms)->implies(p2)) {
								perms->add(p2);
							}
						}
					}
				}
			}
		} catch ($IOException& e) {
		}
	}
}

$Class* LoaderHandler::loadClassForName($String* name, bool initialize, $ClassLoader* loader) {
	$init(LoaderHandler);
	$beforeCallerSensitive();
	if (loader == nullptr) {
		$ReflectUtil::checkPackageAccess(name);
	}
	return $Class::forName(name, initialize, loader);
}

$String* LoaderHandler::lambda$static$1() {
	$init(LoaderHandler);
	return $System::getProperty("java.rmi.server.codebase"_s);
}

$String* LoaderHandler::lambda$static$0() {
	$init(LoaderHandler);
	return $System::getProperty("sun.rmi.loader.logLevel"_s);
}

void clinit$LoaderHandler($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	LoaderHandler::logLevel = $LogStream::parseLevel($cast($String, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(LoaderHandler$$Lambda$lambda$static$0))))));
	$assignStatic(LoaderHandler::loaderLog, $Log::getLog("sun.rmi.loader"_s, "loader"_s, LoaderHandler::logLevel));
	$assignStatic(LoaderHandler::codebaseProperty, nullptr);
	{
		$var($String, prop, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(LoaderHandler$$Lambda$lambda$static$1$1)))));
		if (prop != nullptr && $(prop->trim())->length() > 0) {
			$assignStatic(LoaderHandler::codebaseProperty, prop);
		}
	}
	$assignStatic(LoaderHandler::codebaseURLs, nullptr);
	$assignStatic(LoaderHandler::codebaseLoaders, $Collections::synchronizedMap($$new($IdentityHashMap, 5)));
	{
		{
			$var($ClassLoader, codebaseLoader, $ClassLoader::getSystemClassLoader());
			for (; codebaseLoader != nullptr; $assign(codebaseLoader, $nc(codebaseLoader)->getParent())) {
				$nc(LoaderHandler::codebaseLoaders)->put(codebaseLoader, nullptr);
			}
		}
	}
	$assignStatic(LoaderHandler::loaderTable, $new($HashMap, 5));
	$assignStatic(LoaderHandler::refQueue, $new($ReferenceQueue));
	$assignStatic(LoaderHandler::pathToURLsCache, $new($WeakHashMap, 5));
}

LoaderHandler::LoaderHandler() {
}

$Class* LoaderHandler::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LoaderHandler$$Lambda$lambda$static$0::classInfo$.name)) {
			return LoaderHandler$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(LoaderHandler$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return LoaderHandler$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
	}
	$loadClass(LoaderHandler, name, initialize, &_LoaderHandler_ClassInfo_, clinit$LoaderHandler, allocate$LoaderHandler);
	return class$;
}

$Class* LoaderHandler::class$ = nullptr;

		} // server
	} // rmi
} // sun