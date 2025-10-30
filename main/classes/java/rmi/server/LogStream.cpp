#include <java/rmi/server/LogStream.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/StringBuffer.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/util/AbstractMap.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/logging/LoggingPermission.h>
#include <jcpp.h>

#undef BRIEF
#undef SILENT
#undef VERBOSE

using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $PrintStream = ::java::io::PrintStream;
using $Writer = ::java::io::Writer;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $SecurityManager = ::java::lang::SecurityManager;
using $StringBuffer = ::java::lang::StringBuffer;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $AbstractMap = ::java::util::AbstractMap;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $LoggingPermission = ::java::util::logging::LoggingPermission;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _LogStream_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_getDefaultStream1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_getOutputStream2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_log3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_parseLevel4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_setDefaultStream5[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_setOutputStream6[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_toString7[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_write8[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LogStream_MethodAnnotations_write9[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _LogStream_FieldInfo_[] = {
	{"known", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/rmi/server/LogStream;>;", $PRIVATE | $STATIC, $staticField(LogStream, known)},
	{"defaultStream", "Ljava/io/PrintStream;", nullptr, $PRIVATE | $STATIC, $staticField(LogStream, defaultStream)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogStream, name)},
	{"logOut", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(LogStream, logOut)},
	{"logWriter", "Ljava/io/OutputStreamWriter;", nullptr, $PRIVATE, $field(LogStream, logWriter)},
	{"buffer", "Ljava/lang/StringBuffer;", nullptr, $PRIVATE, $field(LogStream, buffer)},
	{"bufOut", "Ljava/io/ByteArrayOutputStream;", nullptr, $PRIVATE, $field(LogStream, bufOut)},
	{"SILENT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LogStream, SILENT)},
	{"BRIEF", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LogStream, BRIEF)},
	{"VERBOSE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(LogStream, VERBOSE)},
	{}
};

$MethodInfo _LogStream_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/io/OutputStream;)V", nullptr, $PRIVATE | $DEPRECATED, $method(static_cast<void(LogStream::*)($String*,$OutputStream*)>(&LogStream::init$)), nullptr, nullptr, _LogStream_MethodAnnotations_init$0},
	{"getDefaultStream", "()Ljava/io/PrintStream;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED | $DEPRECATED, $method(static_cast<$PrintStream*(*)()>(&LogStream::getDefaultStream)), nullptr, nullptr, _LogStream_MethodAnnotations_getDefaultStream1},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC | $SYNCHRONIZED | $DEPRECATED, nullptr, nullptr, nullptr, _LogStream_MethodAnnotations_getOutputStream2},
	{"log", "(Ljava/lang/String;)Ljava/rmi/server/LogStream;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $method(static_cast<LogStream*(*)($String*)>(&LogStream::log)), nullptr, nullptr, _LogStream_MethodAnnotations_log3},
	{"parseLevel", "(Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $method(static_cast<int32_t(*)($String*)>(&LogStream::parseLevel)), nullptr, nullptr, _LogStream_MethodAnnotations_parseLevel4},
	{"setDefaultStream", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED | $DEPRECATED, $method(static_cast<void(*)($PrintStream*)>(&LogStream::setDefaultStream)), nullptr, nullptr, _LogStream_MethodAnnotations_setDefaultStream5},
	{"setOutputStream", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED | $DEPRECATED, nullptr, nullptr, nullptr, _LogStream_MethodAnnotations_setOutputStream6},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _LogStream_MethodAnnotations_toString7},
	{"write", "(I)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _LogStream_MethodAnnotations_write8},
	{"write", "([BII)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _LogStream_MethodAnnotations_write9},
	{}
};

$ClassInfo _LogStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.LogStream",
	"java.io.PrintStream",
	nullptr,
	_LogStream_FieldInfo_,
	_LogStream_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_LogStream_Annotations_
};

$Object* allocate$LogStream($Class* clazz) {
	return $of($alloc(LogStream));
}

$Map* LogStream::known = nullptr;
$PrintStream* LogStream::defaultStream = nullptr;

void LogStream::init$($String* name, $OutputStream* out) {
	$PrintStream::init$(static_cast<$OutputStream*>($$new($ByteArrayOutputStream)));
	$set(this, buffer, $new($StringBuffer));
	$set(this, bufOut, $cast($ByteArrayOutputStream, this->out));
	$set(this, name, name);
	setOutputStream(out);
}

LogStream* LogStream::log($String* name) {
	$init(LogStream);
	$var(LogStream, stream, nullptr);
	$synchronized(LogStream::known) {
		$assign(stream, $cast(LogStream, $nc(LogStream::known)->get(name)));
		if (stream == nullptr) {
			$assign(stream, $new(LogStream, name, LogStream::defaultStream));
		}
		$nc(LogStream::known)->put(name, stream);
	}
	return stream;
}

$PrintStream* LogStream::getDefaultStream() {
	$load(LogStream);
	$synchronized(class$) {
		$init(LogStream);
		return LogStream::defaultStream;
	}
}

void LogStream::setDefaultStream($PrintStream* newDefault) {
	$load(LogStream);
	$synchronized(class$) {
		$init(LogStream);
		$useLocalCurrentObjectStackCache();
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkPermission($$new($LoggingPermission, "control"_s, nullptr));
		}
		$assignStatic(LogStream::defaultStream, newDefault);
	}
}

$OutputStream* LogStream::getOutputStream() {
	$synchronized(this) {
		return this->logOut;
	}
}

void LogStream::setOutputStream($OutputStream* out) {
	$synchronized(this) {
		$set(this, logOut, out);
		$set(this, logWriter, $new($OutputStreamWriter, this->logOut));
	}
}

void LogStream::write(int32_t b) {
	$useLocalCurrentObjectStackCache();
	if (b == u'\n') {
		$synchronized(this) {
			$synchronized(this->logOut) {
				$nc(this->buffer)->setLength(0);
				$nc(this->buffer)->append($(($$new($Date))->toString()));
				$nc(this->buffer)->append(u':');
				$nc(this->buffer)->append(this->name);
				$nc(this->buffer)->append(u':');
				$nc(this->buffer)->append($($($Thread::currentThread())->getName()));
				$nc(this->buffer)->append(u':');
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							$nc(this->logWriter)->write($($nc(this->buffer)->toString()));
							$nc(this->logWriter)->flush();
							$nc(this->bufOut)->writeTo(this->logOut);
							$nc(this->logOut)->write(b);
							$nc(this->logOut)->flush();
						} catch ($IOException& e) {
							setError();
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						$nc(this->bufOut)->reset();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
			}
		}
	} else {
		$PrintStream::write(b);
	}
}

void LogStream::write($bytes* b, int32_t off, int32_t len) {
	if (len < 0) {
		$throwNew($ArrayIndexOutOfBoundsException, len);
	}
	for (int32_t i = 0; i < len; ++i) {
		write((int32_t)$nc(b)->get(off + i));
	}
}

$String* LogStream::toString() {
	return this->name;
}

int32_t LogStream::parseLevel($String* s) {
	$init(LogStream);
	$useLocalCurrentObjectStackCache();
	if ((s == nullptr) || ($nc(s)->length() < 1)) {
		return -1;
	}
	try {
		return $Integer::parseInt(s);
	} catch ($NumberFormatException& e) {
	}
	if ($nc(s)->length() < 1) {
		return -1;
	}
	if ("SILENT"_s->startsWith($($nc(s)->toUpperCase()))) {
		return LogStream::SILENT;
	} else if ("BRIEF"_s->startsWith($($nc(s)->toUpperCase()))) {
		return LogStream::BRIEF;
	} else if ("VERBOSE"_s->startsWith($($nc(s)->toUpperCase()))) {
		return LogStream::VERBOSE;
	}
	return -1;
}

void clinit$LogStream($Class* class$) {
	$assignStatic(LogStream::known, $new($HashMap, 5));
	$assignStatic(LogStream::defaultStream, $System::err);
}

LogStream::LogStream() {
}

$Class* LogStream::load$($String* name, bool initialize) {
	$loadClass(LogStream, name, initialize, &_LogStream_ClassInfo_, clinit$LogStream, allocate$LogStream);
	return class$;
}

$Class* LogStream::class$ = nullptr;

		} // server
	} // rmi
} // java