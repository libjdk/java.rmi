#ifndef _sun_rmi_runtime_Log$InternalStreamHandler_h_
#define _sun_rmi_runtime_Log$InternalStreamHandler_h_
//$ class sun.rmi.runtime.Log$InternalStreamHandler
//$ extends java.util.logging.StreamHandler

#include <java/util/logging/StreamHandler.h>

namespace java {
	namespace io {
		class OutputStream;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogRecord;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$InternalStreamHandler : public ::java::util::logging::StreamHandler {
	$class(Log$InternalStreamHandler, $NO_CLASS_INIT, ::java::util::logging::StreamHandler)
public:
	Log$InternalStreamHandler();
	void init$(::java::io::OutputStream* out);
	virtual void close() override;
	virtual void publish(::java::util::logging::LogRecord* record) override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$InternalStreamHandler_h_