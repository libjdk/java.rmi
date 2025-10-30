#include <sun/rmi/runtime/Log$LoggerPrintStream.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/Logger.h>
#include <sun/rmi/runtime/Log.h>
#include <jcpp.h>

#undef INFO

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Level = ::java::util::logging::Level;
using $Logger = ::java::util::logging::Logger;
using $Log = ::sun::rmi::runtime::Log;

namespace sun {
	namespace rmi {
		namespace runtime {

$FieldInfo _Log$LoggerPrintStream_FieldInfo_[] = {
	{"logger", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $FINAL, $field(Log$LoggerPrintStream, logger)},
	{"last", "I", nullptr, $PRIVATE, $field(Log$LoggerPrintStream, last)},
	{"bufOut", "Ljava/io/ByteArrayOutputStream;", nullptr, $PRIVATE | $FINAL, $field(Log$LoggerPrintStream, bufOut)},
	{}
};

$MethodInfo _Log$LoggerPrintStream_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(Log$LoggerPrintStream::*)($Logger*)>(&Log$LoggerPrintStream::init$))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"write", "(I)V", nullptr, $PUBLIC},
	{"write", "([BII)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Log$LoggerPrintStream_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$LoggerPrintStream", "sun.rmi.runtime.Log", "LoggerPrintStream", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Log$LoggerPrintStream_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.runtime.Log$LoggerPrintStream",
	"java.io.PrintStream",
	nullptr,
	_Log$LoggerPrintStream_FieldInfo_,
	_Log$LoggerPrintStream_MethodInfo_,
	nullptr,
	nullptr,
	_Log$LoggerPrintStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$LoggerPrintStream($Class* clazz) {
	return $of($alloc(Log$LoggerPrintStream));
}

void Log$LoggerPrintStream::init$($Logger* logger) {
	$PrintStream::init$(static_cast<$OutputStream*>($$new($ByteArrayOutputStream)));
	this->last = -1;
	$set(this, bufOut, $cast($ByteArrayOutputStream, this->out));
	$set(this, logger, logger);
}

void Log$LoggerPrintStream::write(int32_t b) {
	$useLocalCurrentObjectStackCache();
	if ((this->last == u'\r') && (b == u'\n')) {
		this->last = -1;
		return;
	} else if ((b == u'\n') || (b == u'\r')) {
		{
			$var($Throwable, var$0, nullptr);
			try {
				$var($String, var$1, $$str({$($($Thread::currentThread())->getName()), ": "_s}));
				$var($String, message, $concat(var$1, $($nc(this->bufOut)->toString())));
				$init($Level);
				$nc(this->logger)->logp($Level::INFO, "LogStream"_s, "print"_s, message);
			} catch ($Throwable& var$2) {
				$assign(var$0, var$2);
			} /*finally*/ {
				$nc(this->bufOut)->reset();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} else {
		$PrintStream::write(b);
	}
	this->last = b;
}

void Log$LoggerPrintStream::write($bytes* b, int32_t off, int32_t len) {
	if (len < 0) {
		$throwNew($ArrayIndexOutOfBoundsException, len);
	}
	for (int32_t i = 0; i < len; ++i) {
		write((int32_t)$nc(b)->get(off + i));
	}
}

$String* Log$LoggerPrintStream::toString() {
	return "RMI"_s;
}

Log$LoggerPrintStream::Log$LoggerPrintStream() {
}

$Class* Log$LoggerPrintStream::load$($String* name, bool initialize) {
	$loadClass(Log$LoggerPrintStream, name, initialize, &_Log$LoggerPrintStream_ClassInfo_, allocate$Log$LoggerPrintStream);
	return class$;
}

$Class* Log$LoggerPrintStream::class$ = nullptr;

		} // runtime
	} // rmi
} // sun