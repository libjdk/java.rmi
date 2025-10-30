#include <java/rmi/server/RMIClassLoader$1.h>

#include <java/rmi/server/RMIClassLoader.h>
#include <java/rmi/server/RMIClassLoaderSpi.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RMIClassLoader = ::java::rmi::server::RMIClassLoader;
using $RMIClassLoaderSpi = ::java::rmi::server::RMIClassLoaderSpi;
using $PrivilegedAction = ::java::security::PrivilegedAction;

namespace java {
	namespace rmi {
		namespace server {

$MethodInfo _RMIClassLoader$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(RMIClassLoader$1::*)()>(&RMIClassLoader$1::init$))},
	{"run", "()Ljava/rmi/server/RMIClassLoaderSpi;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RMIClassLoader$1_EnclosingMethodInfo_ = {
	"java.rmi.server.RMIClassLoader",
	nullptr,
	nullptr
};

$InnerClassInfo _RMIClassLoader$1_InnerClassesInfo_[] = {
	{"java.rmi.server.RMIClassLoader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RMIClassLoader$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.server.RMIClassLoader$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_RMIClassLoader$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/rmi/server/RMIClassLoaderSpi;>;",
	&_RMIClassLoader$1_EnclosingMethodInfo_,
	_RMIClassLoader$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.server.RMIClassLoader"
};

$Object* allocate$RMIClassLoader$1($Class* clazz) {
	return $of($alloc(RMIClassLoader$1));
}

void RMIClassLoader$1::init$() {
}

$Object* RMIClassLoader$1::run() {
	return $of($RMIClassLoader::initializeProvider());
}

RMIClassLoader$1::RMIClassLoader$1() {
}

$Class* RMIClassLoader$1::load$($String* name, bool initialize) {
	$loadClass(RMIClassLoader$1, name, initialize, &_RMIClassLoader$1_ClassInfo_, allocate$RMIClassLoader$1);
	return class$;
}

$Class* RMIClassLoader$1::class$ = nullptr;

		} // server
	} // rmi
} // java