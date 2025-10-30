#include <sun/rmi/runtime/Log$LoggerLogFactory.h>

#include <java/util/logging/Level.h>
#include <java/util/logging/Logger.h>
#include <sun/rmi/runtime/Log$LoggerLog.h>
#include <sun/rmi/runtime/Log.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Level = ::java::util::logging::Level;
using $Logger = ::java::util::logging::Logger;
using $Log = ::sun::rmi::runtime::Log;
using $Log$LogFactory = ::sun::rmi::runtime::Log$LogFactory;
using $Log$LoggerLog = ::sun::rmi::runtime::Log$LoggerLog;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _Log$LoggerLogFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Log$LoggerLogFactory::*)()>(&Log$LoggerLogFactory::init$))},
	{"createLog", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/logging/Level;)Lsun/rmi/runtime/Log;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Log$LoggerLogFactory_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$LoggerLogFactory", "sun.rmi.runtime.Log", "LoggerLogFactory", $PRIVATE | $STATIC},
	{"sun.rmi.runtime.Log$LogFactory", "sun.rmi.runtime.Log", "LogFactory", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Log$LoggerLogFactory_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.Log$LoggerLogFactory",
	"java.lang.Object",
	"sun.rmi.runtime.Log$LogFactory",
	nullptr,
	_Log$LoggerLogFactory_MethodInfo_,
	nullptr,
	nullptr,
	_Log$LoggerLogFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$LoggerLogFactory($Class* clazz) {
	return $of($alloc(Log$LoggerLogFactory));
}

void Log$LoggerLogFactory::init$() {
}

$Log* Log$LoggerLogFactory::createLog($String* loggerName, $String* oldLogName, $Level* level) {
	$beforeCallerSensitive();
	$var($Logger, logger, $Logger::getLogger(loggerName));
	return $new($Log$LoggerLog, logger, level);
}

Log$LoggerLogFactory::Log$LoggerLogFactory() {
}

$Class* Log$LoggerLogFactory::load$($String* name, bool initialize) {
	$loadClass(Log$LoggerLogFactory, name, initialize, &_Log$LoggerLogFactory_ClassInfo_, allocate$Log$LoggerLogFactory);
	return class$;
}

$Class* Log$LoggerLogFactory::class$ = nullptr;

		} // runtime
	} // rmi
} // sun