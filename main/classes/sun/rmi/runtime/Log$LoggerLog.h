#ifndef _sun_rmi_runtime_Log$LoggerLog_h_
#define _sun_rmi_runtime_Log$LoggerLog_h_
//$ class sun.rmi.runtime.Log$LoggerLog
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
	namespace util {
		namespace logging {
			class Handler;
			class Level;
			class Logger;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log$InternalStreamHandler;
			class Log$LoggerPrintStream;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$LoggerLog : public ::sun::rmi::runtime::Log {
	$class(Log$LoggerLog, 0, ::sun::rmi::runtime::Log)
public:
	Log$LoggerLog();
	void init$(::java::util::logging::Logger* logger, ::java::util::logging::Level* level);
	virtual ::java::io::PrintStream* getPrintStream() override;
	virtual bool isLoggable(::java::util::logging::Level* level) override;
	virtual void log(::java::util::logging::Level* level, $String* message) override;
	virtual void log(::java::util::logging::Level* level, $String* message, $Throwable* thrown) override;
	virtual void setOutputStream(::java::io::OutputStream* out) override;
	virtual $String* toString() override;
	static ::java::util::logging::Handler* alternateConsole;
	::sun::rmi::runtime::Log$InternalStreamHandler* copyHandler = nullptr;
	::java::util::logging::Logger* logger = nullptr;
	::sun::rmi::runtime::Log$LoggerPrintStream* loggerSandwich = nullptr;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LoggerLog_h_