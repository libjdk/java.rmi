#ifndef _sun_rmi_log_LogInputStream_h_
#define _sun_rmi_log_LogInputStream_h_
//$ class sun.rmi.log.LogInputStream
//$ extends java.io.InputStream

#include <java/io/InputStream.h>
#include <java/lang/Array.h>

namespace sun {
	namespace rmi {
		namespace log {

class LogInputStream : public ::java::io::InputStream {
	$class(LogInputStream, $HAS_FINALIZE | $NO_CLASS_INIT, ::java::io::InputStream)
public:
	LogInputStream();
	void init$(::java::io::InputStream* in, int32_t length);
	virtual int32_t available() override;
	virtual void close() override;
	virtual void finalize() override;
	virtual int32_t read() override;
	virtual int32_t read($bytes* b) override;
	virtual int32_t read($bytes* b, int32_t off, int32_t len) override;
	virtual int64_t skip(int64_t n) override;
	::java::io::InputStream* in = nullptr;
	int32_t length = 0;
};

		} // log
	} // rmi
} // sun

#endif // _sun_rmi_log_LogInputStream_h_