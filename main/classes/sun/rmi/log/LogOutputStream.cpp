#include <sun/rmi/log/LogOutputStream.h>

#include <java/io/OutputStream.h>
#include <java/io/RandomAccessFile.h>
#include <jcpp.h>

using $OutputStream = ::java::io::OutputStream;
using $RandomAccessFile = ::java::io::RandomAccessFile;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace rmi {
		namespace log {

$FieldInfo _LogOutputStream_FieldInfo_[] = {
	{"raf", "Ljava/io/RandomAccessFile;", nullptr, $PRIVATE, $field(LogOutputStream, raf)},
	{}
};

$MethodInfo _LogOutputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/RandomAccessFile;)V", nullptr, $PUBLIC, $method(static_cast<void(LogOutputStream::*)($RandomAccessFile*)>(&LogOutputStream::init$)), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $FINAL, nullptr, "java.io.IOException"},
	{"write", "(I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write", "([B)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write", "([BII)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _LogOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.log.LogOutputStream",
	"java.io.OutputStream",
	nullptr,
	_LogOutputStream_FieldInfo_,
	_LogOutputStream_MethodInfo_
};

$Object* allocate$LogOutputStream($Class* clazz) {
	return $of($alloc(LogOutputStream));
}

void LogOutputStream::init$($RandomAccessFile* raf) {
	$OutputStream::init$();
	$set(this, raf, raf);
}

void LogOutputStream::write(int32_t b) {
	$nc(this->raf)->write(b);
}

void LogOutputStream::write($bytes* b) {
	$nc(this->raf)->write(b);
}

void LogOutputStream::write($bytes* b, int32_t off, int32_t len) {
	$nc(this->raf)->write(b, off, len);
}

void LogOutputStream::close() {
}

LogOutputStream::LogOutputStream() {
}

$Class* LogOutputStream::load$($String* name, bool initialize) {
	$loadClass(LogOutputStream, name, initialize, &_LogOutputStream_ClassInfo_, allocate$LogOutputStream);
	return class$;
}

$Class* LogOutputStream::class$ = nullptr;

		} // log
	} // rmi
} // sun