#ifndef _sun_rmi_runtime_Log$LogStreamLog_h_
#define _sun_rmi_runtime_Log$LogStreamLog_h_
//$ class sun.rmi.runtime.Log$LogStreamLog
//$ extends sun.rmi.runtime.Log

#include <sun/rmi/runtime/Log.h>

namespace java {
	namespace io {
		class OutputStream;
		class PrintStream;
	}
}
namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class LogStream;
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Level;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$LogStreamLog : public ::sun::rmi::runtime::Log {
	$class(Log$LogStreamLog, $NO_CLASS_INIT, ::sun::rmi::runtime::Log)
public:
	Log$LogStreamLog();
	void init$(::java::rmi::server::LogStream* stream, ::java::util::logging::Level* level);
	virtual ::java::io::PrintStream* getPrintStream() override;
	virtual bool isLoggable(::java::util::logging::Level* level) override;
	virtual void log(::java::util::logging::Level* messageLevel, $String* message) override;
	virtual void log(::java::util::logging::Level* level, $String* message, $Throwable* thrown) override;
	virtual void setOutputStream(::java::io::OutputStream* out) override;
	static $String* unqualifiedName($String* name);
	::java::rmi::server::LogStream* stream = nullptr;
	int32_t levelValue = 0;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LogStreamLog_h_