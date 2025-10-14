#ifndef _sun_rmi_log_ReliableLog_h_
#define _sun_rmi_log_ReliableLog_h_
//$ class sun.rmi.log.ReliableLog
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace io {
		class DataOutput;
		class File;
	}
}
namespace java {
	namespace lang {
		class Boolean;
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class Constructor;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace log {
			class LogHandler;
			class ReliableLog$LogFile;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace log {

class ReliableLog : public ::java::lang::Object {
	$class(ReliableLog, 0, ::java::lang::Object)
public:
	ReliableLog();
	void init$($String* dirPath, ::sun::rmi::log::LogHandler* handler, bool pad);
	void init$($String* dirPath, ::sun::rmi::log::LogHandler* handler);
	virtual void close();
	void commitToNewVersion();
	void createFirstVersion();
	void deleteFile($String* name);
	void deleteLogFile(int32_t ver);
	void deleteNewVersionFile();
	void deleteSnapshot(int32_t ver);
	$String* fName($String* name);
	static ::java::lang::reflect::Constructor* getLogClassConstructor();
	void getVersion();
	void incrVersion();
	void initializeLogFile();
	static $String* lambda$getLogClassConstructor$1();
	static ::java::lang::Boolean* lambda$new$0();
	virtual int64_t logSize();
	void openLogFile(bool truncate);
	int32_t readVersion($String* name);
	virtual $Object* recover();
	$Object* recoverUpdates(Object$* state);
	virtual void snapshot(Object$* value);
	virtual int64_t snapshotSize();
	virtual void update(Object$* value);
	virtual void update(Object$* value, bool forceToDisk);
	$String* versionName($String* name);
	$String* versionName($String* prefix, int32_t ver);
	void writeInt(::java::io::DataOutput* out, int32_t val);
	void writeVersionFile(bool newVersion);
	static const int32_t PreferredMajorVersion = 0;
	static const int32_t PreferredMinorVersion = 2;
	bool Debug = false;
	static $String* snapshotPrefix;
	static $String* logfilePrefix;
	static $String* versionFile;
	static $String* newVersionFile;
	static int32_t intBytes;
	static int64_t diskPageSize;
	::java::io::File* dir = nullptr;
	int32_t version = 0;
	$String* logName = nullptr;
	::sun::rmi::log::ReliableLog$LogFile* log = nullptr;
	int64_t snapshotBytes = 0;
	int64_t logBytes = 0;
	int32_t logEntries = 0;
	int64_t lastSnapshot = 0;
	int64_t lastLog = 0;
	::sun::rmi::log::LogHandler* handler = nullptr;
	$bytes* intBuf = nullptr;
	int32_t majorFormatVersion = 0;
	int32_t minorFormatVersion = 0;
	static ::java::lang::reflect::Constructor* logClassConstructor;
};

		} // log
	} // rmi
} // sun

#endif // _sun_rmi_log_ReliableLog_h_