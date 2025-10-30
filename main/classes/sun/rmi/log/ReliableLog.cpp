#include <sun/rmi/log/ReliableLog.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutput.h>
#include <java/io/DataOutputStream.h>
#include <java/io/EOFException.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FilterInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/RandomAccessFile.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Constructor.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/log/LogHandler.h>
#include <sun/rmi/log/LogInputStream.h>
#include <sun/rmi/log/LogOutputStream.h>
#include <sun/rmi/log/ReliableLog$1.h>
#include <sun/rmi/log/ReliableLog$LogFile.h>
#include <jcpp.h>

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutput = ::java::io::DataOutput;
using $DataOutputStream = ::java::io::DataOutputStream;
using $EOFException = ::java::io::EOFException;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $RandomAccessFile = ::java::io::RandomAccessFile;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Constructor = ::java::lang::reflect::Constructor;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LogHandler = ::sun::rmi::log::LogHandler;
using $LogInputStream = ::sun::rmi::log::LogInputStream;
using $LogOutputStream = ::sun::rmi::log::LogOutputStream;
using $ReliableLog$1 = ::sun::rmi::log::ReliableLog$1;
using $ReliableLog$LogFile = ::sun::rmi::log::ReliableLog$LogFile;

namespace sun {
	namespace rmi {
		namespace log {

class ReliableLog$$Lambda$lambda$new$0 : public $PrivilegedAction {
	$class(ReliableLog$$Lambda$lambda$new$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ReliableLog::lambda$new$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReliableLog$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReliableLog$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ReliableLog$$Lambda$lambda$new$0::*)()>(&ReliableLog$$Lambda$lambda$new$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ReliableLog$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.log.ReliableLog$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ReliableLog$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ReliableLog$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReliableLog$$Lambda$lambda$new$0::class$ = nullptr;

class ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1 : public $PrivilegedAction {
	$class(ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ReliableLog::lambda$getLogClassConstructor$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::*)()>(&ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.log.ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::load$($String* name, bool initialize) {
	$loadClass(ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::class$ = nullptr;

$FieldInfo _ReliableLog_FieldInfo_[] = {
	{"PreferredMajorVersion", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ReliableLog, PreferredMajorVersion)},
	{"PreferredMinorVersion", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ReliableLog, PreferredMinorVersion)},
	{"Debug", "Z", nullptr, $PRIVATE, $field(ReliableLog, Debug)},
	{"snapshotPrefix", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ReliableLog, snapshotPrefix)},
	{"logfilePrefix", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ReliableLog, logfilePrefix)},
	{"versionFile", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ReliableLog, versionFile)},
	{"newVersionFile", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(ReliableLog, newVersionFile)},
	{"intBytes", "I", nullptr, $PRIVATE | $STATIC, $staticField(ReliableLog, intBytes)},
	{"diskPageSize", "J", nullptr, $PRIVATE | $STATIC, $staticField(ReliableLog, diskPageSize)},
	{"dir", "Ljava/io/File;", nullptr, $PRIVATE, $field(ReliableLog, dir)},
	{"version", "I", nullptr, $PRIVATE, $field(ReliableLog, version)},
	{"logName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ReliableLog, logName)},
	{"log", "Lsun/rmi/log/ReliableLog$LogFile;", nullptr, $PRIVATE, $field(ReliableLog, log)},
	{"snapshotBytes", "J", nullptr, $PRIVATE, $field(ReliableLog, snapshotBytes)},
	{"logBytes", "J", nullptr, $PRIVATE, $field(ReliableLog, logBytes)},
	{"logEntries", "I", nullptr, $PRIVATE, $field(ReliableLog, logEntries)},
	{"lastSnapshot", "J", nullptr, $PRIVATE, $field(ReliableLog, lastSnapshot)},
	{"lastLog", "J", nullptr, $PRIVATE, $field(ReliableLog, lastLog)},
	{"handler", "Lsun/rmi/log/LogHandler;", nullptr, $PRIVATE, $field(ReliableLog, handler)},
	{"intBuf", "[B", nullptr, $PRIVATE | $FINAL, $field(ReliableLog, intBuf)},
	{"majorFormatVersion", "I", nullptr, $PRIVATE, $field(ReliableLog, majorFormatVersion)},
	{"minorFormatVersion", "I", nullptr, $PRIVATE, $field(ReliableLog, minorFormatVersion)},
	{"logClassConstructor", "Ljava/lang/reflect/Constructor;", "Ljava/lang/reflect/Constructor<+Lsun/rmi/log/ReliableLog$LogFile;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ReliableLog, logClassConstructor)},
	{}
};

$MethodInfo _ReliableLog_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Lsun/rmi/log/LogHandler;Z)V", nullptr, $PUBLIC, $method(static_cast<void(ReliableLog::*)($String*,$LogHandler*,bool)>(&ReliableLog::init$)), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;Lsun/rmi/log/LogHandler;)V", nullptr, $PUBLIC, $method(static_cast<void(ReliableLog::*)($String*,$LogHandler*)>(&ReliableLog::init$)), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"commitToNewVersion", "()V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)()>(&ReliableLog::commitToNewVersion)), "java.io.IOException"},
	{"createFirstVersion", "()V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)()>(&ReliableLog::createFirstVersion)), "java.io.IOException"},
	{"deleteFile", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)($String*)>(&ReliableLog::deleteFile)), "java.io.IOException"},
	{"deleteLogFile", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)(int32_t)>(&ReliableLog::deleteLogFile)), "java.io.IOException"},
	{"deleteNewVersionFile", "()V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)()>(&ReliableLog::deleteNewVersionFile)), "java.io.IOException"},
	{"deleteSnapshot", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)(int32_t)>(&ReliableLog::deleteSnapshot)), "java.io.IOException"},
	{"fName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(ReliableLog::*)($String*)>(&ReliableLog::fName))},
	{"getLogClassConstructor", "()Ljava/lang/reflect/Constructor;", "()Ljava/lang/reflect/Constructor<+Lsun/rmi/log/ReliableLog$LogFile;>;", $PRIVATE | $STATIC, $method(static_cast<$Constructor*(*)()>(&ReliableLog::getLogClassConstructor))},
	{"getVersion", "()V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)()>(&ReliableLog::getVersion)), "java.io.IOException"},
	{"incrVersion", "()V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)()>(&ReliableLog::incrVersion))},
	{"initializeLogFile", "()V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)()>(&ReliableLog::initializeLogFile)), "java.io.IOException"},
	{"lambda$getLogClassConstructor$1", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&ReliableLog::lambda$getLogClassConstructor$1))},
	{"lambda$new$0", "()Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)()>(&ReliableLog::lambda$new$0))},
	{"logSize", "()J", nullptr, $PUBLIC},
	{"openLogFile", "(Z)V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)(bool)>(&ReliableLog::openLogFile)), "java.io.IOException"},
	{"readVersion", "(Ljava/lang/String;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(ReliableLog::*)($String*)>(&ReliableLog::readVersion)), "java.io.IOException"},
	{"recover", "()Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"recoverUpdates", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(ReliableLog::*)(Object$*)>(&ReliableLog::recoverUpdates)), "java.io.IOException"},
	{"snapshot", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"snapshotSize", "()J", nullptr, $PUBLIC},
	{"update", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"update", "(Ljava/lang/Object;Z)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"versionName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(ReliableLog::*)($String*)>(&ReliableLog::versionName))},
	{"versionName", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(ReliableLog::*)($String*,int32_t)>(&ReliableLog::versionName))},
	{"writeInt", "(Ljava/io/DataOutput;I)V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)($DataOutput*,int32_t)>(&ReliableLog::writeInt)), "java.io.IOException"},
	{"writeVersionFile", "(Z)V", nullptr, $PRIVATE, $method(static_cast<void(ReliableLog::*)(bool)>(&ReliableLog::writeVersionFile)), "java.io.IOException"},
	{}
};

$InnerClassInfo _ReliableLog_InnerClassesInfo_[] = {
	{"sun.rmi.log.ReliableLog$LogFile", "sun.rmi.log.ReliableLog", "LogFile", $PUBLIC | $STATIC},
	{"sun.rmi.log.ReliableLog$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ReliableLog_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.log.ReliableLog",
	"java.lang.Object",
	nullptr,
	_ReliableLog_FieldInfo_,
	_ReliableLog_MethodInfo_,
	nullptr,
	nullptr,
	_ReliableLog_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.log.ReliableLog$LogFile,sun.rmi.log.ReliableLog$1"
};

$Object* allocate$ReliableLog($Class* clazz) {
	return $of($alloc(ReliableLog));
}

$String* ReliableLog::snapshotPrefix = nullptr;
$String* ReliableLog::logfilePrefix = nullptr;
$String* ReliableLog::versionFile = nullptr;
$String* ReliableLog::newVersionFile = nullptr;
int32_t ReliableLog::intBytes = 0;
int64_t ReliableLog::diskPageSize = 0;
$Constructor* ReliableLog::logClassConstructor = nullptr;

void ReliableLog::init$($String* dirPath, $LogHandler* handler, bool pad) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	this->Debug = false;
	this->version = 0;
	$set(this, logName, nullptr);
	$set(this, log, nullptr);
	this->snapshotBytes = 0;
	this->logBytes = 0;
	this->logEntries = 0;
	this->lastSnapshot = 0;
	this->lastLog = 0;
	$set(this, intBuf, $new($bytes, 4));
	this->majorFormatVersion = 0;
	this->minorFormatVersion = 0;
	this->Debug = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ReliableLog$$Lambda$lambda$new$0)))))))->booleanValue();
	$set(this, dir, $new($File, dirPath));
	bool var$0 = $nc(this->dir)->exists();
	if (!(var$0 && $nc(this->dir)->isDirectory())) {
		if (!$nc(this->dir)->mkdir()) {
			$throwNew($IOException, $$str({"could not create directory for log: "_s, dirPath}));
		}
	}
	$set(this, handler, handler);
	this->lastSnapshot = 0;
	this->lastLog = 0;
	getVersion();
	if (this->version == 0) {
		try {
			snapshot($($nc(handler)->initialSnapshot()));
		} catch ($IOException& e) {
			$throw(e);
		} catch ($Exception& e) {
			$throwNew($IOException, $$str({"initial snapshot failed with exception: "_s, e}));
		}
	}
}

void ReliableLog::init$($String* dirPath, $LogHandler* handler) {
	ReliableLog::init$(dirPath, handler, false);
}

$Object* ReliableLog::recover() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->Debug) {
			$nc($System::err)->println("log.debug: recover()"_s);
		}
		if (this->version == 0) {
			return $of(nullptr);
		}
		$var($Object, snapshot, nullptr);
		$var($String, fname, versionName(ReliableLog::snapshotPrefix));
		$var($File, snapshotFile, $new($File, fname));
		$var($InputStream, in, $new($BufferedInputStream, $$new($FileInputStream, snapshotFile)));
		if (this->Debug) {
			$nc($System::err)->println($$str({"log.debug: recovering from "_s, fname}));
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$assign(snapshot, $nc(this->handler)->recover(in));
				} catch ($IOException& e) {
					$throw(e);
				} catch ($Exception& e) {
					if (this->Debug) {
						$nc($System::err)->println($$str({"log.debug: recovery failed: "_s, e}));
					}
					$throwNew($IOException, $$str({"log recover failed with exception: "_s, e}));
				}
				this->snapshotBytes = snapshotFile->length();
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				in->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		return $of(recoverUpdates(snapshot));
	}
}

void ReliableLog::update(Object$* value) {
	$synchronized(this) {
		update(value, true);
	}
}

void ReliableLog::update(Object$* value, bool forceToDisk) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->log == nullptr) {
			$throwNew($IOException, "log is inaccessible, it may have been corrupted or closed"_s);
		}
		int64_t entryStart = $nc(this->log)->getFilePointer();
		bool spansBoundary = $nc(this->log)->checkSpansBoundary(entryStart);
		writeInt(this->log, spansBoundary ? 1 << 31 : 0);
		try {
			$nc(this->handler)->writeUpdate($$new($LogOutputStream, this->log), value);
		} catch ($IOException& e) {
			$throw(e);
		} catch ($Exception& e) {
			$throw($cast($IOException, $($$new($IOException, "write update failed"_s)->initCause(e))));
		}
		$nc(this->log)->sync();
		int64_t entryEnd = $nc(this->log)->getFilePointer();
		int32_t updateLen = (int32_t)((entryEnd - entryStart) - ReliableLog::intBytes);
		$nc(this->log)->seek(entryStart);
		if (spansBoundary) {
			writeInt(this->log, updateLen | (1 << 31));
			$nc(this->log)->sync();
			$nc(this->log)->seek(entryStart);
			$nc(this->log)->writeByte(updateLen >> 24);
			$nc(this->log)->sync();
		} else {
			writeInt(this->log, updateLen);
			$nc(this->log)->sync();
		}
		$nc(this->log)->seek(entryEnd);
		this->logBytes = entryEnd;
		this->lastLog = $System::currentTimeMillis();
		++this->logEntries;
	}
}

$Constructor* ReliableLog::getLogClassConstructor() {
	$init(ReliableLog);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, logClassName, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1)))));
	if (logClassName != nullptr) {
		try {
			$var($ClassLoader, loader, $cast($ClassLoader, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ReliableLog$1)))));
			$load($ReliableLog$LogFile);
			$Class* cl = $nc($nc(loader)->loadClass(logClassName))->asSubclass($ReliableLog$LogFile::class$);
			return $nc(cl)->getConstructor($$new($ClassArray, {
				$String::class$,
				$String::class$
			}));
		} catch ($Exception& e) {
			$nc($System::err)->println("Exception occurred:"_s);
			e->printStackTrace();
		}
	}
	return nullptr;
}

void ReliableLog::snapshot(Object$* value) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		int32_t oldVersion = this->version;
		incrVersion();
		$var($String, fname, versionName(ReliableLog::snapshotPrefix));
		$var($File, snapshotFile, $new($File, fname));
		$var($FileOutputStream, out, $new($FileOutputStream, snapshotFile));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$nc(this->handler)->snapshot(out, value);
				} catch ($IOException& e) {
					$throw(e);
				} catch ($Exception& e) {
					$throwNew($IOException, "snapshot failed"_s, e);
				}
				this->lastSnapshot = $System::currentTimeMillis();
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				out->close();
				this->snapshotBytes = snapshotFile->length();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		openLogFile(true);
		writeVersionFile(true);
		commitToNewVersion();
		deleteSnapshot(oldVersion);
		deleteLogFile(oldVersion);
	}
}

void ReliableLog::close() {
	$synchronized(this) {
		if (this->log == nullptr) {
			return;
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				$nc(this->log)->close();
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$set(this, log, nullptr);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

int64_t ReliableLog::snapshotSize() {
	return this->snapshotBytes;
}

int64_t ReliableLog::logSize() {
	return this->logBytes;
}

void ReliableLog::writeInt($DataOutput* out, int32_t val) {
	$nc(this->intBuf)->set(0, (int8_t)(val >> 24));
	$nc(this->intBuf)->set(1, (int8_t)(val >> 16));
	$nc(this->intBuf)->set(2, (int8_t)(val >> 8));
	$nc(this->intBuf)->set(3, (int8_t)val);
	$nc(out)->write(this->intBuf);
}

$String* ReliableLog::fName($String* name) {
	$init($File);
	return $str({$($nc(this->dir)->getPath()), $File::separator, name});
}

$String* ReliableLog::versionName($String* name) {
	return versionName(name, 0);
}

$String* ReliableLog::versionName($String* prefix, int32_t ver) {
	$useLocalCurrentObjectStackCache();
	ver = (ver == 0) ? this->version : ver;
	$var($String, var$0, $(fName(prefix)));
	return $concat(var$0, $($String::valueOf(ver)));
}

void ReliableLog::incrVersion() {
	do {
		++this->version;
	} while (this->version == 0);
}

void ReliableLog::deleteFile($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($File, f, $new($File, name));
	if (!f->delete$()) {
		$throwNew($IOException, $$str({"couldn\'t remove file: "_s, name}));
	}
}

void ReliableLog::deleteNewVersionFile() {
	deleteFile($(fName(ReliableLog::newVersionFile)));
}

void ReliableLog::deleteSnapshot(int32_t ver) {
	if (ver == 0) {
		return;
	}
	deleteFile($(versionName(ReliableLog::snapshotPrefix, ver)));
}

void ReliableLog::deleteLogFile(int32_t ver) {
	if (ver == 0) {
		return;
	}
	deleteFile($(versionName(ReliableLog::logfilePrefix, ver)));
}

void ReliableLog::openLogFile(bool truncate) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		close();
	} catch ($IOException& e) {
	}
	$set(this, logName, versionName(ReliableLog::logfilePrefix));
	try {
		$set(this, log, ReliableLog::logClassConstructor == nullptr ? $new($ReliableLog$LogFile, this->logName, "rw"_s) : $cast($ReliableLog$LogFile, $nc(ReliableLog::logClassConstructor)->newInstance($$new($ObjectArray, {
			$of(this->logName),
			$of("rw"_s)
		}))));
	} catch ($Exception& e) {
		$throw($cast($IOException, $($$new($IOException, "unable to construct LogFile instance"_s)->initCause(e))));
	}
	if (truncate) {
		initializeLogFile();
	}
}

void ReliableLog::initializeLogFile() {
	$nc(this->log)->setLength(0);
	this->majorFormatVersion = ReliableLog::PreferredMajorVersion;
	writeInt(this->log, ReliableLog::PreferredMajorVersion);
	this->minorFormatVersion = ReliableLog::PreferredMinorVersion;
	writeInt(this->log, ReliableLog::PreferredMinorVersion);
	this->logBytes = ReliableLog::intBytes * 2;
	this->logEntries = 0;
}

void ReliableLog::writeVersionFile(bool newVersion) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, nullptr);
	if (newVersion) {
		$assign(name, ReliableLog::newVersionFile);
	} else {
		$assign(name, ReliableLog::versionFile);
	}
	{
		$var($FileOutputStream, fos, $new($FileOutputStream, $(fName(name))));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($DataOutputStream, out, $new($DataOutputStream, fos));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								writeInt(out, this->version);
							} catch ($Throwable& t$) {
								try {
									out->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							out->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						fos->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				fos->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void ReliableLog::createFirstVersion() {
	this->version = 0;
	writeVersionFile(false);
}

void ReliableLog::commitToNewVersion() {
	writeVersionFile(false);
	deleteNewVersionFile();
}

int32_t ReliableLog::readVersion($String* name) {
	$useLocalCurrentObjectStackCache();
	{
		$var($DataInputStream, in, $new($DataInputStream, $$new($FileInputStream, name)));
		{
			$var($Throwable, var$0, nullptr);
			int32_t var$2 = 0;
			bool return$1 = false;
			try {
				try {
					var$2 = in->readInt();
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					try {
						in->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				in->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

void ReliableLog::getVersion() {
	$useLocalCurrentObjectStackCache();
	try {
		this->version = readVersion($(fName(ReliableLog::newVersionFile)));
		commitToNewVersion();
	} catch ($IOException& e) {
		try {
			deleteNewVersionFile();
		} catch ($IOException& ex) {
		}
		try {
			this->version = readVersion($(fName(ReliableLog::versionFile)));
		} catch ($IOException& ex) {
			createFirstVersion();
		}
	}
}

$Object* ReliableLog::recoverUpdates(Object$* state$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Object, state, state$renamed);
	this->logBytes = 0;
	this->logEntries = 0;
	if (this->version == 0) {
		return $of(state);
	}
	$var($String, fname, versionName(ReliableLog::logfilePrefix));
	$var($InputStream, in, $new($BufferedInputStream, $$new($FileInputStream, fname)));
	$var($DataInputStream, dataIn, $new($DataInputStream, in));
	if (this->Debug) {
		$nc($System::err)->println($$str({"log.debug: reading updates from "_s, fname}));
	}
	try {
		this->majorFormatVersion = dataIn->readInt();
		this->logBytes += ReliableLog::intBytes;
		this->minorFormatVersion = dataIn->readInt();
		this->logBytes += ReliableLog::intBytes;
	} catch ($EOFException& e) {
		openLogFile(true);
		$assign(in, nullptr);
	}
	if (this->majorFormatVersion != ReliableLog::PreferredMajorVersion) {
		if (this->Debug) {
			$nc($System::err)->println($$str({"log.debug: major version mismatch: "_s, $$str(this->majorFormatVersion), "."_s, $$str(this->minorFormatVersion)}));
		}
		$throwNew($IOException, $$str({"Log file "_s, this->logName, " has a version "_s, $$str(this->majorFormatVersion), "."_s, $$str(this->minorFormatVersion), " format, and this implementation  understands only version "_s, $$str(ReliableLog::PreferredMajorVersion), "."_s, $$str(ReliableLog::PreferredMinorVersion)}));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			while (in != nullptr) {
				int32_t updateLen = 0;
				try {
					updateLen = dataIn->readInt();
				} catch ($EOFException& e) {
					if (this->Debug) {
						$nc($System::err)->println("log.debug: log was sync\'d cleanly"_s);
					}
					break;
				}
				if (updateLen <= 0) {
					if (this->Debug) {
						$nc($System::err)->println($$str({"log.debug: last update incomplete, updateLen = 0x"_s, $($Integer::toHexString(updateLen))}));
					}
					break;
				}
				if (in->available() < updateLen) {
					if (this->Debug) {
						$nc($System::err)->println("log.debug: log was truncated"_s);
					}
					break;
				}
				if (this->Debug) {
					$nc($System::err)->println($$str({"log.debug: rdUpdate size "_s, $$str(updateLen)}));
				}
				try {
					$assign(state, $nc(this->handler)->readUpdate($$new($LogInputStream, in, updateLen), state));
				} catch ($IOException& e) {
					$throw(e);
				} catch ($Exception& e) {
					e->printStackTrace();
					$throwNew($IOException, $$str({"read update failed with exception: "_s, e}));
				}
				this->logBytes += (ReliableLog::intBytes + updateLen);
				++this->logEntries;
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (in != nullptr) {
				in->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	if (this->Debug) {
		$nc($System::err)->println($$str({"log.debug: recovered updates: "_s, $$str(this->logEntries)}));
	}
	openLogFile(false);
	if (this->log == nullptr) {
		$throwNew($IOException, "rmid\'s log is inaccessible, it may have been corrupted or closed"_s);
	}
	$nc(this->log)->seek(this->logBytes);
	$nc(this->log)->setLength(this->logBytes);
	return $of(state);
}

$String* ReliableLog::lambda$getLogClassConstructor$1() {
	$init(ReliableLog);
	return $System::getProperty("sun.rmi.log.class"_s);
}

$Boolean* ReliableLog::lambda$new$0() {
	$init(ReliableLog);
	return $Boolean::valueOf($Boolean::getBoolean("sun.rmi.log.debug"_s));
}

void clinit$ReliableLog($Class* class$) {
	$assignStatic(ReliableLog::snapshotPrefix, "Snapshot."_s);
	$assignStatic(ReliableLog::logfilePrefix, "Logfile."_s);
	$assignStatic(ReliableLog::versionFile, "Version_Number"_s);
	$assignStatic(ReliableLog::newVersionFile, "New_Version_Number"_s);
	ReliableLog::intBytes = 4;
	ReliableLog::diskPageSize = 512;
	$assignStatic(ReliableLog::logClassConstructor, ReliableLog::getLogClassConstructor());
}

ReliableLog::ReliableLog() {
}

$Class* ReliableLog::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ReliableLog$$Lambda$lambda$new$0::classInfo$.name)) {
			return ReliableLog$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::classInfo$.name)) {
			return ReliableLog$$Lambda$lambda$getLogClassConstructor$1$1::load$(name, initialize);
		}
	}
	$loadClass(ReliableLog, name, initialize, &_ReliableLog_ClassInfo_, clinit$ReliableLog, allocate$ReliableLog);
	return class$;
}

$Class* ReliableLog::class$ = nullptr;

		} // log
	} // rmi
} // sun