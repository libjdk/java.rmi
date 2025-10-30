#include <java/rmi/server/RMIClassLoader.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessError.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationError.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/LinkageError.h>
#include <java/lang/NoClassDefFoundError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/net/URL.h>
#include <java/rmi/server/RMIClassLoader$1.h>
#include <java/rmi/server/RMIClassLoader$2.h>
#include <java/rmi/server/RMIClassLoaderSpi.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Iterator.h>
#include <java/util/ServiceLoader.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <jcpp.h>

using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessError = ::java::lang::IllegalAccessError;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationError = ::java::lang::InstantiationError;
using $InstantiationException = ::java::lang::InstantiationException;
using $LinkageError = ::java::lang::LinkageError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoClassDefFoundError = ::java::lang::NoClassDefFoundError;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $URL = ::java::net::URL;
using $RMIClassLoader$1 = ::java::rmi::server::RMIClassLoader$1;
using $RMIClassLoader$2 = ::java::rmi::server::RMIClassLoader$2;
using $RMIClassLoaderSpi = ::java::rmi::server::RMIClassLoaderSpi;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Iterator = ::java::util::Iterator;
using $ServiceLoader = ::java::util::ServiceLoader;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _RMIClassLoader_MethodAnnotations_getSecurityContext4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RMIClassLoader_MethodAnnotations_loadClass6[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RMIClassLoader_FieldInfo_[] = {
	{"defaultProvider", "Ljava/rmi/server/RMIClassLoaderSpi;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIClassLoader, defaultProvider)},
	{"provider", "Ljava/rmi/server/RMIClassLoaderSpi;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RMIClassLoader, provider)},
	{}
};

$MethodInfo _RMIClassLoader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(RMIClassLoader::*)()>(&RMIClassLoader::init$))},
	{"getClassAnnotation", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PUBLIC | $STATIC, $method(static_cast<$String*(*)($Class*)>(&RMIClassLoader::getClassAnnotation))},
	{"getClassLoader", "(Ljava/lang/String;)Ljava/lang/ClassLoader;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ClassLoader*(*)($String*)>(&RMIClassLoader::getClassLoader)), "java.net.MalformedURLException,java.lang.SecurityException"},
	{"getDefaultProviderInstance", "()Ljava/rmi/server/RMIClassLoaderSpi;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$RMIClassLoaderSpi*(*)()>(&RMIClassLoader::getDefaultProviderInstance))},
	{"getSecurityContext", "(Ljava/lang/ClassLoader;)Ljava/lang/Object;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $method(static_cast<$Object*(*)($ClassLoader*)>(&RMIClassLoader::getSecurityContext)), nullptr, nullptr, _RMIClassLoader_MethodAnnotations_getSecurityContext4},
	{"initializeProvider", "()Ljava/rmi/server/RMIClassLoaderSpi;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$RMIClassLoaderSpi*(*)()>(&RMIClassLoader::initializeProvider))},
	{"loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC | $DEPRECATED, $method(static_cast<$Class*(*)($String*)>(&RMIClassLoader::loadClass)), "java.net.MalformedURLException,java.lang.ClassNotFoundException", nullptr, _RMIClassLoader_MethodAnnotations_loadClass6},
	{"loadClass", "(Ljava/net/URL;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/net/URL;Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $method(static_cast<$Class*(*)($URL*,$String*)>(&RMIClassLoader::loadClass)), "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $method(static_cast<$Class*(*)($String*,$String*)>(&RMIClassLoader::loadClass)), "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $method(static_cast<$Class*(*)($String*,$String*,$ClassLoader*)>(&RMIClassLoader::loadClass)), "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{"loadProxyClass", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC | $STATIC, $method(static_cast<$Class*(*)($String*,$StringArray*,$ClassLoader*)>(&RMIClassLoader::loadProxyClass)), "java.lang.ClassNotFoundException,java.net.MalformedURLException"},
	{"newDefaultProviderInstance", "()Ljava/rmi/server/RMIClassLoaderSpi;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$RMIClassLoaderSpi*(*)()>(&RMIClassLoader::newDefaultProviderInstance))},
	{}
};

$InnerClassInfo _RMIClassLoader_InnerClassesInfo_[] = {
	{"java.rmi.server.RMIClassLoader$2", nullptr, nullptr, 0},
	{"java.rmi.server.RMIClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIClassLoader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.RMIClassLoader",
	"java.lang.Object",
	nullptr,
	_RMIClassLoader_FieldInfo_,
	_RMIClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_RMIClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.rmi.server.RMIClassLoader$2,java.rmi.server.RMIClassLoader$1"
};

$Object* allocate$RMIClassLoader($Class* clazz) {
	return $of($alloc(RMIClassLoader));
}

$RMIClassLoaderSpi* RMIClassLoader::defaultProvider = nullptr;
$RMIClassLoaderSpi* RMIClassLoader::provider = nullptr;

void RMIClassLoader::init$() {
}

$Class* RMIClassLoader::loadClass($String* name) {
	$init(RMIClassLoader);
	return loadClass(($String*)nullptr, name);
}

$Class* RMIClassLoader::loadClass($URL* codebase, $String* name) {
	$init(RMIClassLoader);
	return $nc(RMIClassLoader::provider)->loadClass(codebase != nullptr ? $($nc(codebase)->toString()) : ($String*)nullptr, name, nullptr);
}

$Class* RMIClassLoader::loadClass($String* codebase, $String* name) {
	$init(RMIClassLoader);
	return $nc(RMIClassLoader::provider)->loadClass(codebase, name, nullptr);
}

$Class* RMIClassLoader::loadClass($String* codebase, $String* name, $ClassLoader* defaultLoader) {
	$init(RMIClassLoader);
	return $nc(RMIClassLoader::provider)->loadClass(codebase, name, defaultLoader);
}

$Class* RMIClassLoader::loadProxyClass($String* codebase, $StringArray* interfaces, $ClassLoader* defaultLoader) {
	$init(RMIClassLoader);
	return $nc(RMIClassLoader::provider)->loadProxyClass(codebase, interfaces, defaultLoader);
}

$ClassLoader* RMIClassLoader::getClassLoader($String* codebase) {
	$init(RMIClassLoader);
	return $nc(RMIClassLoader::provider)->getClassLoader(codebase);
}

$String* RMIClassLoader::getClassAnnotation($Class* cl) {
	$init(RMIClassLoader);
	return $nc(RMIClassLoader::provider)->getClassAnnotation(cl);
}

$RMIClassLoaderSpi* RMIClassLoader::getDefaultProviderInstance() {
	$init(RMIClassLoader);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "setFactory"_s));
	}
	return RMIClassLoader::defaultProvider;
}

$Object* RMIClassLoader::getSecurityContext($ClassLoader* loader) {
	$init(RMIClassLoader);
	return $of($LoaderHandler::getSecurityContext(loader));
}

$RMIClassLoaderSpi* RMIClassLoader::newDefaultProviderInstance() {
	$init(RMIClassLoader);
	return $new($RMIClassLoader$2);
}

$RMIClassLoaderSpi* RMIClassLoader::initializeProvider() {
	$init(RMIClassLoader);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, providerClassName, $System::getProperty("java.rmi.server.RMIClassLoaderSpi"_s));
	if (providerClassName != nullptr) {
		if (providerClassName->equals("default"_s)) {
			return RMIClassLoader::defaultProvider;
		}
		try {
			$load($RMIClassLoaderSpi);
			$Class* providerClass = $Class::forName(providerClassName, false, $($ClassLoader::getSystemClassLoader()))->asSubclass($RMIClassLoaderSpi::class$);
			$var($RMIClassLoaderSpi, result, $cast($RMIClassLoaderSpi, $nc(providerClass)->newInstance()));
			return result;
		} catch ($ClassNotFoundException& e) {
			$throwNew($NoClassDefFoundError, $(e->getMessage()));
		} catch ($IllegalAccessException& e) {
			$throwNew($IllegalAccessError, $(e->getMessage()));
		} catch ($InstantiationException& e) {
			$throwNew($InstantiationError, $(e->getMessage()));
		} catch ($ClassCastException& e) {
			$var($Error, error, $new($LinkageError, "provider class not assignable to RMIClassLoaderSpi"_s));
			error->initCause(e);
			$throw(error);
		}
	}
	$load($RMIClassLoaderSpi);
	$var($Iterator, iter, $nc($($ServiceLoader::load($RMIClassLoaderSpi::class$, $($ClassLoader::getSystemClassLoader()))))->iterator());
	if ($nc(iter)->hasNext()) {
		try {
			return $cast($RMIClassLoaderSpi, iter->next());
		} catch ($ClassCastException& e) {
			$var($Error, error, $new($LinkageError, "provider class not assignable to RMIClassLoaderSpi"_s));
			error->initCause(e);
			$throw(error);
		}
	}
	return RMIClassLoader::defaultProvider;
}

void clinit$RMIClassLoader($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(RMIClassLoader::defaultProvider, RMIClassLoader::newDefaultProviderInstance());
	$assignStatic(RMIClassLoader::provider, $cast($RMIClassLoaderSpi, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RMIClassLoader$1)))));
}

RMIClassLoader::RMIClassLoader() {
}

$Class* RMIClassLoader::load$($String* name, bool initialize) {
	$loadClass(RMIClassLoader, name, initialize, &_RMIClassLoader_ClassInfo_, clinit$RMIClassLoader, allocate$RMIClassLoader);
	return class$;
}

$Class* RMIClassLoader::class$ = nullptr;

		} // server
	} // rmi
} // java