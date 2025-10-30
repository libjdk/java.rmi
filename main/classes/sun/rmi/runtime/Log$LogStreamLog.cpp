#include <sun/rmi/runtime/Log$LogStreamLog.h>

#include <java/io/OutputStream.h>
#include <java/lang/StackWalker$StackFrame.h>
#include <java/rmi/server/LogStream.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <jcpp.h>

#undef OFF
#undef VERBOSE

using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackWalker$StackFrame = ::java::lang::StackWalker$StackFrame;
using $LogStream = ::java::rmi::server::LogStream;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;

namespace sun {
	namespace rmi {
		namespace runtime {

$FieldInfo _Log$LogStreamLog_FieldInfo_[] = {
	{"stream", "Ljava/rmi/server/LogStream;", nullptr, $PRIVATE | $FINAL, $field(Log$LogStreamLog, stream)},
	{"levelValue", "I", nullptr, $PRIVATE, $field(Log$LogStreamLog, levelValue)},
	{}
};

$MethodInfo _Log$LogStreamLog_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/server/LogStream;Ljava/util/logging/Level;)V", nullptr, $PRIVATE, $method(static_cast<void(Log$LogStreamLog::*)($LogStream*,$Level*)>(&Log$LogStreamLog::init$))},
	{"getPrintStream", "()Ljava/io/PrintStream;", nullptr, $PUBLIC},
	{"isLoggable", "(Ljava/util/logging/Level;)Z", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"setOutputStream", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"unqualifiedName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&Log$LogStreamLog::unqualifiedName))},
	{}
};

$InnerClassInfo _Log$LogStreamLog_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$LogStreamLog", "sun.rmi.runtime.Log", "LogStreamLog", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Log$LogStreamLog_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.Log$LogStreamLog",
	"sun.rmi.runtime.Log",
	nullptr,
	_Log$LogStreamLog_FieldInfo_,
	_Log$LogStreamLog_MethodInfo_,
	nullptr,
	nullptr,
	_Log$LogStreamLog_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$LogStreamLog($Class* clazz) {
	return $of($alloc(Log$LogStreamLog));
}

void Log$LogStreamLog::init$($LogStream* stream, $Level* level) {
	$Log::init$();
	$init($Level);
	this->levelValue = $nc($Level::OFF)->intValue();
	if ((stream != nullptr) && (level != nullptr)) {
		this->levelValue = level->intValue();
	}
	$set(this, stream, stream);
}

bool Log$LogStreamLog::isLoggable($Level* level) {
	$synchronized(this) {
		return ($nc(level)->intValue() >= this->levelValue);
	}
}

void Log$LogStreamLog::log($Level* messageLevel, $String* message) {
	$useLocalCurrentObjectStackCache();
	if (isLoggable(messageLevel)) {
		$var($StackWalker$StackFrame, sourceFrame, $Log::getSource());
		$var($String, var$2, $$str({$(unqualifiedName($($nc(sourceFrame)->getClassName()))), "."_s}));
		$var($String, var$1, $$concat(var$2, $($nc(sourceFrame)->getMethodName())));
		$var($String, var$0, $$concat(var$1, ": "));
		$nc(this->stream)->println($$concat(var$0, message));
	}
}

void Log$LogStreamLog::log($Level* level, $String* message, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	if (isLoggable(level)) {
		$synchronized(this->stream) {
			$var($StackWalker$StackFrame, sourceFrame, $Log::getSource());
			$var($String, var$2, $$str({$(unqualifiedName($($nc(sourceFrame)->getClassName()))), "."_s}));
			$var($String, var$1, $$concat(var$2, $($nc(sourceFrame)->getMethodName())));
			$var($String, var$0, $$concat(var$1, ": "));
			$nc(this->stream)->println($$concat(var$0, message));
			$nc(thrown)->printStackTrace(static_cast<$PrintStream*>(this->stream));
		}
	}
}

$PrintStream* Log$LogStreamLog::getPrintStream() {
	return this->stream;
}

void Log$LogStreamLog::setOutputStream($OutputStream* out) {
	$synchronized(this) {
		if (out != nullptr) {
			$init($Log);
			if ($nc($Log::VERBOSE)->intValue() < this->levelValue) {
				this->levelValue = $nc($Log::VERBOSE)->intValue();
			}
			$nc(this->stream)->setOutputStream(out);
		} else {
			$init($Level);
			this->levelValue = $nc($Level::OFF)->intValue();
		}
	}
}

$String* Log$LogStreamLog::unqualifiedName($String* name$renamed) {
	$init(Log$LogStreamLog);
	$var($String, name, name$renamed);
	int32_t lastDot = $nc(name)->lastIndexOf((int32_t)u'.');
	if (lastDot >= 0) {
		$assign(name, name->substring(lastDot + 1));
	}
	$assign(name, name->replace(u'$', u'.'));
	return name;
}

Log$LogStreamLog::Log$LogStreamLog() {
}

$Class* Log$LogStreamLog::load$($String* name, bool initialize) {
	$loadClass(Log$LogStreamLog, name, initialize, &_Log$LogStreamLog_ClassInfo_, allocate$Log$LogStreamLog);
	return class$;
}

$Class* Log$LogStreamLog::class$ = nullptr;

		} // runtime
	} // rmi
} // sun