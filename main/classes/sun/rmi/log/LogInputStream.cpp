#include <sun/rmi/log/LogInputStream.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <jcpp.h>

#undef MAX_VALUE

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace rmi {
		namespace log {

$FieldInfo _LogInputStream_FieldInfo_[] = {
	{"in", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(LogInputStream, in)},
	{"length", "I", nullptr, $PRIVATE, $field(LogInputStream, length)},
	{}
};

$MethodInfo _LogInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;I)V", nullptr, $PUBLIC, $method(static_cast<void(LogInputStream::*)($InputStream*,int32_t)>(&LogInputStream::init$)), "java.io.IOException"},
	{"available", "()I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC},
	{"finalize", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{"read", "()I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"read", "([B)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"skip", "(J)J", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _LogInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.log.LogInputStream",
	"java.io.InputStream",
	nullptr,
	_LogInputStream_FieldInfo_,
	_LogInputStream_MethodInfo_
};

$Object* allocate$LogInputStream($Class* clazz) {
	return $of($alloc(LogInputStream));
}

void LogInputStream::init$($InputStream* in, int32_t length) {
	$InputStream::init$();
	$set(this, in, in);
	this->length = length;
}

int32_t LogInputStream::read() {
	if (this->length == 0) {
		return -1;
	}
	int32_t c = $nc(this->in)->read();
	this->length = (c != -1) ? this->length - 1 : 0;
	return c;
}

int32_t LogInputStream::read($bytes* b) {
	return read(b, 0, $nc(b)->length);
}

int32_t LogInputStream::read($bytes* b, int32_t off, int32_t len) {
	if (this->length == 0) {
		return -1;
	}
	len = (this->length < len) ? this->length : len;
	int32_t n = $nc(this->in)->read(b, off, len);
	this->length = (n != -1) ? this->length - n : 0;
	return n;
}

int64_t LogInputStream::skip(int64_t n) {
	$useLocalCurrentObjectStackCache();
	if (n > $Integer::MAX_VALUE) {
		$throwNew($IOException, $$str({"Too many bytes to skip - "_s, $$str(n)}));
	}
	if (this->length == 0) {
		return 0;
	}
	n = (this->length < n) ? (int64_t)this->length : n;
	n = $nc(this->in)->skip(n);
	this->length -= n;
	return n;
}

int32_t LogInputStream::available() {
	int32_t avail = $nc(this->in)->available();
	return (this->length < avail) ? this->length : avail;
}

void LogInputStream::close() {
	this->length = 0;
}

void LogInputStream::finalize() {
	close();
}

LogInputStream::LogInputStream() {
}

$Class* LogInputStream::load$($String* name, bool initialize) {
	$loadClass(LogInputStream, name, initialize, &_LogInputStream_ClassInfo_, allocate$LogInputStream);
	return class$;
}

$Class* LogInputStream::class$ = nullptr;

		} // log
	} // rmi
} // sun