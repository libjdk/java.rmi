#include <java/rmi/server/RMIClassLoader$2.h>

#include <java/lang/ClassLoader.h>
#include <java/rmi/server/RMIClassLoader.h>
#include <java/rmi/server/RMIClassLoaderSpi.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RMIClassLoader = ::java::rmi::server::RMIClassLoader;
using $RMIClassLoaderSpi = ::java::rmi::server::RMIClassLoaderSpi;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _RMIClassLoader$2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(RMIClassLoader$2::*)()>(&RMIClassLoader$2::init$))},
	{"getClassAnnotation", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PUBLIC},
	{"getClassLoader", "(Ljava/lang/String;)Ljava/lang/ClassLoader;", nullptr, $PUBLIC, nullptr, "java.net.MalformedURLException"},
	{"loadClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC, nullptr, "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{"loadProxyClass", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PUBLIC, nullptr, "java.net.MalformedURLException,java.lang.ClassNotFoundException"},
	{}
};

$EnclosingMethodInfo _RMIClassLoader$2_EnclosingMethodInfo_ = {
	"java.rmi.server.RMIClassLoader",
	"newDefaultProviderInstance",
	"()Ljava/rmi/server/RMIClassLoaderSpi;"
};

$InnerClassInfo _RMIClassLoader$2_InnerClassesInfo_[] = {
	{"java.rmi.server.RMIClassLoader$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIClassLoader$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.server.RMIClassLoader$2",
	"java.rmi.server.RMIClassLoaderSpi",
	nullptr,
	nullptr,
	_RMIClassLoader$2_MethodInfo_,
	nullptr,
	&_RMIClassLoader$2_EnclosingMethodInfo_,
	_RMIClassLoader$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.server.RMIClassLoader"
};

$Object* allocate$RMIClassLoader$2($Class* clazz) {
	return $of($alloc(RMIClassLoader$2));
}

void RMIClassLoader$2::init$() {
	$RMIClassLoaderSpi::init$();
}

$Class* RMIClassLoader$2::loadClass($String* codebase, $String* name, $ClassLoader* defaultLoader) {
	return $LoaderHandler::loadClass(codebase, name, defaultLoader);
}

$Class* RMIClassLoader$2::loadProxyClass($String* codebase, $StringArray* interfaces, $ClassLoader* defaultLoader) {
	return $LoaderHandler::loadProxyClass(codebase, interfaces, defaultLoader);
}

$ClassLoader* RMIClassLoader$2::getClassLoader($String* codebase) {
	return $LoaderHandler::getClassLoader(codebase);
}

$String* RMIClassLoader$2::getClassAnnotation($Class* cl) {
	return $LoaderHandler::getClassAnnotation(cl);
}

RMIClassLoader$2::RMIClassLoader$2() {
}

$Class* RMIClassLoader$2::load$($String* name, bool initialize) {
	$loadClass(RMIClassLoader$2, name, initialize, &_RMIClassLoader$2_ClassInfo_, allocate$RMIClassLoader$2);
	return class$;
}

$Class* RMIClassLoader$2::class$ = nullptr;

		} // server
	} // rmi
} // java