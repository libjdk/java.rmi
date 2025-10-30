#include <sun/rmi/runtime/Log$InternalStreamHandler.h>

#include <java/io/OutputStream.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/SimpleFormatter.h>
#include <java/util/logging/StreamHandler.h>
#include <sun/rmi/runtime/Log.h>
#include <jcpp.h>

using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Formatter = ::java::util::logging::Formatter;
using $LogRecord = ::java::util::logging::LogRecord;
using $SimpleFormatter = ::java::util::logging::SimpleFormatter;
using $StreamHandler = ::java::util::logging::StreamHandler;
using $Log = ::sun::rmi::runtime::Log;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _Log$InternalStreamHandler_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, 0, $method(static_cast<void(Log$InternalStreamHandler::*)($OutputStream*)>(&Log$InternalStreamHandler::init$))},
	{"close", "()V", nullptr, $PUBLIC},
	{"publish", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Log$InternalStreamHandler_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$InternalStreamHandler", "sun.rmi.runtime.Log", "InternalStreamHandler", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Log$InternalStreamHandler_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.Log$InternalStreamHandler",
	"java.util.logging.StreamHandler",
	nullptr,
	nullptr,
	_Log$InternalStreamHandler_MethodInfo_,
	nullptr,
	nullptr,
	_Log$InternalStreamHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$InternalStreamHandler($Class* clazz) {
	return $of($alloc(Log$InternalStreamHandler));
}

void Log$InternalStreamHandler::init$($OutputStream* out) {
	$StreamHandler::init$(out, $$new($SimpleFormatter));
}

void Log$InternalStreamHandler::publish($LogRecord* record) {
	$StreamHandler::publish(record);
	flush();
}

void Log$InternalStreamHandler::close() {
	flush();
}

Log$InternalStreamHandler::Log$InternalStreamHandler() {
}

$Class* Log$InternalStreamHandler::load$($String* name, bool initialize) {
	$loadClass(Log$InternalStreamHandler, name, initialize, &_Log$InternalStreamHandler_ClassInfo_, allocate$Log$InternalStreamHandler);
	return class$;
}

$Class* Log$InternalStreamHandler::class$ = nullptr;

		} // runtime
	} // rmi
} // sun