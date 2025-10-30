#include <sun/rmi/runtime/Log$LoggerLog.h>

#include <java/io/OutputStream.h>
#include <java/lang/StackWalker$StackFrame.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/Logger.h>
#include <java/util/logging/StreamHandler.h>
#include <sun/rmi/runtime/Log$InternalStreamHandler.h>
#include <sun/rmi/runtime/Log$LoggerLog$1.h>
#include <sun/rmi/runtime/Log$LoggerLog$2.h>
#include <sun/rmi/runtime/Log$LoggerPrintStream.h>
#include <sun/rmi/runtime/Log.h>
#include <jcpp.h>

#undef VERBOSE

using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackWalker$StackFrame = ::java::lang::StackWalker$StackFrame;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $Logger = ::java::util::logging::Logger;
using $StreamHandler = ::java::util::logging::StreamHandler;
using $Log = ::sun::rmi::runtime::Log;
using $Log$InternalStreamHandler = ::sun::rmi::runtime::Log$InternalStreamHandler;
using $Log$LoggerLog$1 = ::sun::rmi::runtime::Log$LoggerLog$1;
using $Log$LoggerLog$2 = ::sun::rmi::runtime::Log$LoggerLog$2;
using $Log$LoggerPrintStream = ::sun::rmi::runtime::Log$LoggerPrintStream;

namespace sun {
	namespace rmi {
		namespace runtime {

$FieldInfo _Log$LoggerLog_FieldInfo_[] = {
	{"alternateConsole", "Ljava/util/logging/Handler;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Log$LoggerLog, alternateConsole)},
	{"copyHandler", "Lsun/rmi/runtime/Log$InternalStreamHandler;", nullptr, $PRIVATE, $field(Log$LoggerLog, copyHandler)},
	{"logger", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $FINAL, $field(Log$LoggerLog, logger)},
	{"loggerSandwich", "Lsun/rmi/runtime/Log$LoggerPrintStream;", nullptr, $PRIVATE, $field(Log$LoggerLog, loggerSandwich)},
	{}
};

$MethodInfo _Log$LoggerLog_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/Logger;Ljava/util/logging/Level;)V", nullptr, $PRIVATE, $method(static_cast<void(Log$LoggerLog::*)($Logger*,$Level*)>(&Log$LoggerLog::init$))},
	{"getPrintStream", "()Ljava/io/PrintStream;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"isLoggable", "(Ljava/util/logging/Level;)Z", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"setOutputStream", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Log$LoggerLog_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$LoggerLog", "sun.rmi.runtime.Log", "LoggerLog", $PRIVATE | $STATIC},
	{"sun.rmi.runtime.Log$LoggerLog$2", nullptr, nullptr, 0},
	{"sun.rmi.runtime.Log$LoggerLog$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Log$LoggerLog_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.Log$LoggerLog",
	"sun.rmi.runtime.Log",
	nullptr,
	_Log$LoggerLog_FieldInfo_,
	_Log$LoggerLog_MethodInfo_,
	nullptr,
	nullptr,
	_Log$LoggerLog_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$LoggerLog($Class* clazz) {
	return $of($alloc(Log$LoggerLog));
}

$Handler* Log$LoggerLog::alternateConsole = nullptr;

void Log$LoggerLog::init$($Logger* logger, $Level* level) {
	$beforeCallerSensitive();
	$Log::init$();
	$set(this, copyHandler, nullptr);
	$set(this, logger, logger);
	if (level != nullptr) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Log$LoggerLog$2, this, logger, level)));
	}
}

bool Log$LoggerLog::isLoggable($Level* level) {
	return $nc(this->logger)->isLoggable(level);
}

void Log$LoggerLog::log($Level* level, $String* message) {
	$useLocalCurrentObjectStackCache();
	if (isLoggable(level)) {
		$var($StackWalker$StackFrame, sourceFrame, $Log::getSource());
		$var($Level, var$0, level);
		$var($String, var$1, $nc(sourceFrame)->getClassName());
		$var($String, var$2, sourceFrame->getMethodName());
		$nc(this->logger)->logp(var$0, var$1, var$2, $$str({$($($Thread::currentThread())->getName()), ": "_s, message}));
	}
}

void Log$LoggerLog::log($Level* level, $String* message, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (isLoggable(level)) {
		$var($StackWalker$StackFrame, sourceFrame, $Log::getSource());
		$var($Level, var$0, level);
		$var($String, var$1, $nc(sourceFrame)->getClassName());
		$var($String, var$2, sourceFrame->getMethodName());
		$nc(this->logger)->logp(var$0, var$1, var$2, $$str({$($($Thread::currentThread())->getName()), ": "_s, message}), thrown);
	}
}

$String* Log$LoggerLog::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$2, $$str({$($nc($of(this->logger))->toString()), ", level: "_s}));
	$var($String, var$1, $$concat(var$2, $($nc(this->logger)->getLevel())));
	$var($String, var$0, $$concat(var$1, ", name: "));
	return $concat(var$0, $($nc(this->logger)->getName()));
}

void Log$LoggerLog::setOutputStream($OutputStream* out) {
	$synchronized(this) {
		if (out != nullptr) {
			$init($Log);
			if (!$nc(this->logger)->isLoggable($Log::VERBOSE)) {
				$nc(this->logger)->setLevel($Log::VERBOSE);
			}
			$set(this, copyHandler, $new($Log$InternalStreamHandler, out));
			$nc(this->copyHandler)->setLevel($Log::VERBOSE);
			$nc(this->logger)->addHandler(this->copyHandler);
		} else {
			if (this->copyHandler != nullptr) {
				$nc(this->logger)->removeHandler(this->copyHandler);
			}
			$set(this, copyHandler, nullptr);
		}
	}
}

$PrintStream* Log$LoggerLog::getPrintStream() {
	$synchronized(this) {
		if (this->loggerSandwich == nullptr) {
			$set(this, loggerSandwich, $new($Log$LoggerPrintStream, this->logger));
		}
		return this->loggerSandwich;
	}
}

void clinit$Log$LoggerLog($Class* class$) {
	$beforeCallerSensitive();
	$assignStatic(Log$LoggerLog::alternateConsole, $cast($Handler, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Log$LoggerLog$1)))));
}

Log$LoggerLog::Log$LoggerLog() {
}

$Class* Log$LoggerLog::load$($String* name, bool initialize) {
	$loadClass(Log$LoggerLog, name, initialize, &_Log$LoggerLog_ClassInfo_, clinit$Log$LoggerLog, allocate$Log$LoggerLog);
	return class$;
}

$Class* Log$LoggerLog::class$ = nullptr;

		} // runtime
	} // rmi
} // sun