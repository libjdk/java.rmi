#ifndef _sun_rmi_log_ReliableLog$LogFile_h_
#define _sun_rmi_log_ReliableLog$LogFile_h_
//$ class sun.rmi.log.ReliableLog$LogFile
//$ extends java.io.RandomAccessFile

#include <java/io/RandomAccessFile.h>

namespace java {
	namespace io {
		class FileDescriptor;
	}
}

namespace sun {
	namespace rmi {
		namespace log {

class ReliableLog$LogFile : public ::java::io::RandomAccessFile {
	$class(ReliableLog$LogFile, $NO_CLASS_INIT, ::java::io::RandomAccessFile)
public:
	ReliableLog$LogFile();
	void init$($String* name, $String* mode);
	virtual bool checkSpansBoundary(int64_t fp);
	virtual void sync();
	::java::io::FileDescriptor* fd = nullptr;
};

		} // log
	} // rmi
} // sun

#endif // _sun_rmi_log_ReliableLog$LogFile_h_