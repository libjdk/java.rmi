#include <sun/rmi/log/LogHandler.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <sun/rmi/log/LogInputStream.h>
#include <sun/rmi/log/LogOutputStream.h>
#include <sun/rmi/server/MarshalInputStream.h>
#include <sun/rmi/server/MarshalOutputStream.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LogInputStream = ::sun::rmi::log::LogInputStream;
using $LogOutputStream = ::sun::rmi::log::LogOutputStream;
using $MarshalInputStream = ::sun::rmi::server::MarshalInputStream;
using $MarshalOutputStream = ::sun::rmi::server::MarshalOutputStream;

namespace sun {
	namespace rmi {
		namespace log {

$MethodInfo _LogHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogHandler::*)()>(&LogHandler::init$))},
	{"applyUpdate", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.lang.Exception"},
	{"initialSnapshot", "()Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.lang.Exception"},
	{"readUpdate", "(Lsun/rmi/log/LogInputStream;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"recover", "(Ljava/io/InputStream;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"snapshot", "(Ljava/io/OutputStream;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"writeUpdate", "(Lsun/rmi/log/LogOutputStream;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{}
};

$ClassInfo _LogHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.rmi.log.LogHandler",
	"java.lang.Object",
	nullptr,
	nullptr,
	_LogHandler_MethodInfo_
};

$Object* allocate$LogHandler($Class* clazz) {
	return $of($alloc(LogHandler));
}

void LogHandler::init$() {
}

void LogHandler::snapshot($OutputStream* out, Object$* value) {
	$var($MarshalOutputStream, s, $new($MarshalOutputStream, out));
	s->writeObject(value);
	s->flush();
}

$Object* LogHandler::recover($InputStream* in) {
	$var($MarshalInputStream, s, $new($MarshalInputStream, in));
	return $of(s->readObject());
}

void LogHandler::writeUpdate($LogOutputStream* out, Object$* value) {
	$var($MarshalOutputStream, s, $new($MarshalOutputStream, out));
	s->writeObject(value);
	s->flush();
}

$Object* LogHandler::readUpdate($LogInputStream* in, Object$* state) {
	$useLocalCurrentObjectStackCache();
	$var($MarshalInputStream, s, $new($MarshalInputStream, in));
	return $of(applyUpdate($(s->readObject()), state));
}

LogHandler::LogHandler() {
}

$Class* LogHandler::load$($String* name, bool initialize) {
	$loadClass(LogHandler, name, initialize, &_LogHandler_ClassInfo_, allocate$LogHandler);
	return class$;
}

$Class* LogHandler::class$ = nullptr;

		} // log
	} // rmi
} // sun