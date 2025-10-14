#ifndef _sun_rmi_runtime_Log$LoggerPrintStream_h_
#define _sun_rmi_runtime_Log$LoggerPrintStream_h_
//$ class sun.rmi.runtime.Log$LoggerPrintStream
//$ extends java.io.PrintStream

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>

namespace java {
	namespace io {
		class ByteArrayOutputStream;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Logger;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$LoggerPrintStream : public ::java::io::PrintStream {
	$class(Log$LoggerPrintStream, $NO_CLASS_INIT, ::java::io::PrintStream)
public:
	Log$LoggerPrintStream();
	void init$(::java::util::logging::Logger* logger);
	virtual $String* toString() override;
	using ::java::io::PrintStream::write;
	virtual void write(int32_t b) override;
	virtual void write($bytes* b, int32_t off, int32_t len) override;
	::java::util::logging::Logger* logger = nullptr;
	int32_t last = 0;
	::java::io::ByteArrayOutputStream* bufOut = nullptr;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LoggerPrintStream_h_