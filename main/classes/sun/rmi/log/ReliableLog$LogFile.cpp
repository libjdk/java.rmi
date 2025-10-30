#include <sun/rmi/log/ReliableLog$LogFile.h>

#include <java/io/FileDescriptor.h>
#include <java/io/RandomAccessFile.h>
#include <sun/rmi/log/ReliableLog.h>
#include <jcpp.h>

using $FileDescriptor = ::java::io::FileDescriptor;
using $RandomAccessFile = ::java::io::RandomAccessFile;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReliableLog = ::sun::rmi::log::ReliableLog;

namespace sun {
	namespace rmi {
		namespace log {

$FieldInfo _ReliableLog$LogFile_FieldInfo_[] = {
	{"fd", "Ljava/io/FileDescriptor;", nullptr, $PRIVATE | $FINAL, $field(ReliableLog$LogFile, fd)},
	{}
};

$MethodInfo _ReliableLog$LogFile_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ReliableLog$LogFile::*)($String*,$String*)>(&ReliableLog$LogFile::init$)), "java.io.FileNotFoundException,java.io.IOException"},
	{"checkSpansBoundary", "(J)Z", nullptr, $PROTECTED},
	{"sync", "()V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _ReliableLog$LogFile_InnerClassesInfo_[] = {
	{"sun.rmi.log.ReliableLog$LogFile", "sun.rmi.log.ReliableLog", "LogFile", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _ReliableLog$LogFile_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.log.ReliableLog$LogFile",
	"java.io.RandomAccessFile",
	nullptr,
	_ReliableLog$LogFile_FieldInfo_,
	_ReliableLog$LogFile_MethodInfo_,
	nullptr,
	nullptr,
	_ReliableLog$LogFile_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.log.ReliableLog"
};

$Object* allocate$ReliableLog$LogFile($Class* clazz) {
	return $of($alloc(ReliableLog$LogFile));
}

void ReliableLog$LogFile::init$($String* name, $String* mode) {
	$RandomAccessFile::init$(name, mode);
	$set(this, fd, getFD());
}

void ReliableLog$LogFile::sync() {
	$nc(this->fd)->sync();
}

bool ReliableLog$LogFile::checkSpansBoundary(int64_t fp) {
	return fp % 512 > 508;
}

ReliableLog$LogFile::ReliableLog$LogFile() {
}

$Class* ReliableLog$LogFile::load$($String* name, bool initialize) {
	$loadClass(ReliableLog$LogFile, name, initialize, &_ReliableLog$LogFile_ClassInfo_, allocate$ReliableLog$LogFile);
	return class$;
}

$Class* ReliableLog$LogFile::class$ = nullptr;

		} // log
	} // rmi
} // sun