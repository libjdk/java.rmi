#include <sun/rmi/log/ReliableLog$1.h>

#include <java/lang/ClassLoader.h>
#include <sun/rmi/log/ReliableLog.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ReliableLog = ::sun::rmi::log::ReliableLog;

namespace sun {
	namespace rmi {
		namespace log {

$MethodInfo _ReliableLog$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(ReliableLog$1::*)()>(&ReliableLog$1::init$))},
	{"run", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _ReliableLog$1_EnclosingMethodInfo_ = {
	"sun.rmi.log.ReliableLog",
	"getLogClassConstructor",
	"()Ljava/lang/reflect/Constructor;"
};

$InnerClassInfo _ReliableLog$1_InnerClassesInfo_[] = {
	{"sun.rmi.log.ReliableLog$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReliableLog$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.log.ReliableLog$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_ReliableLog$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/ClassLoader;>;",
	&_ReliableLog$1_EnclosingMethodInfo_,
	_ReliableLog$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.log.ReliableLog"
};

$Object* allocate$ReliableLog$1($Class* clazz) {
	return $of($alloc(ReliableLog$1));
}

void ReliableLog$1::init$() {
}

$Object* ReliableLog$1::run() {
	$beforeCallerSensitive();
	return $of($ClassLoader::getSystemClassLoader());
}

ReliableLog$1::ReliableLog$1() {
}

$Class* ReliableLog$1::load$($String* name, bool initialize) {
	$loadClass(ReliableLog$1, name, initialize, &_ReliableLog$1_ClassInfo_, allocate$ReliableLog$1);
	return class$;
}

$Class* ReliableLog$1::class$ = nullptr;

		} // log
	} // rmi
} // sun