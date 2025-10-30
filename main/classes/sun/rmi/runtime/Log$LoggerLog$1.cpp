#include <sun/rmi/runtime/Log$LoggerLog$1.h>

#include <java/io/FilterOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log$InternalStreamHandler.h>
#include <jcpp.h>

#undef ALL

using $FilterOutputStream = ::java::io::FilterOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $Log$InternalStreamHandler = ::sun::rmi::runtime::Log$InternalStreamHandler;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _Log$LoggerLog$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Log$LoggerLog$1::*)()>(&Log$LoggerLog$1::init$))},
	{"run", "()Ljava/util/logging/Handler;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Log$LoggerLog$1_EnclosingMethodInfo_ = {
	"sun.rmi.runtime.Log$LoggerLog",
	nullptr,
	nullptr
};

$InnerClassInfo _Log$LoggerLog$1_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$LoggerLog", "sun.rmi.runtime.Log", "LoggerLog", $PRIVATE | $STATIC},
	{"sun.rmi.runtime.Log$LoggerLog$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Log$LoggerLog$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.Log$LoggerLog$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_Log$LoggerLog$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/util/logging/Handler;>;",
	&_Log$LoggerLog$1_EnclosingMethodInfo_,
	_Log$LoggerLog$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$LoggerLog$1($Class* clazz) {
	return $of($alloc(Log$LoggerLog$1));
}

void Log$LoggerLog$1::init$() {
}

$Object* Log$LoggerLog$1::run() {
	$var($Log$InternalStreamHandler, alternate, $new($Log$InternalStreamHandler, $System::err));
	$init($Level);
	alternate->setLevel($Level::ALL);
	return $of(alternate);
}

Log$LoggerLog$1::Log$LoggerLog$1() {
}

$Class* Log$LoggerLog$1::load$($String* name, bool initialize) {
	$loadClass(Log$LoggerLog$1, name, initialize, &_Log$LoggerLog$1_ClassInfo_, allocate$Log$LoggerLog$1);
	return class$;
}

$Class* Log$LoggerLog$1::class$ = nullptr;

		} // runtime
	} // rmi
} // sun