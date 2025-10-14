#ifndef _sun_rmi_log_LogOutputStream_h_
#define _sun_rmi_log_LogOutputStream_h_
//$ class sun.rmi.log.LogOutputStream
//$ extends java.io.OutputStream

#include <java/io/OutputStream.h>
#include <java/lang/Array.h>

namespace java {
	namespace io {
		class RandomAccessFile;
	}
}

namespace sun {
	namespace rmi {
		namespace log {

class LogOutputStream : public ::java::io::OutputStream {
	$class(LogOutputStream, $NO_CLASS_INIT, ::java::io::OutputStream)
public:
	LogOutputStream();
	void init$(::java::io::RandomAccessFile* raf);
	virtual void close() override;
	virtual void write(int32_t b) override;
	virtual void write($bytes* b) override;
	virtual void write($bytes* b, int32_t off, int32_t len) override;
	::java::io::RandomAccessFile* raf = nullptr;
};

		} // log
	} // rmi
} // sun

#endif // _sun_rmi_log_LogOutputStream_h_