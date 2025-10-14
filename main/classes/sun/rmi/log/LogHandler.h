#ifndef _sun_rmi_log_LogHandler_h_
#define _sun_rmi_log_LogHandler_h_
//$ class sun.rmi.log.LogHandler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace sun {
	namespace rmi {
		namespace log {
			class LogInputStream;
			class LogOutputStream;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace log {

class LogHandler : public ::java::lang::Object {
	$class(LogHandler, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LogHandler();
	void init$();
	virtual $Object* applyUpdate(Object$* update, Object$* state) {return nullptr;}
	virtual $Object* initialSnapshot() {return nullptr;}
	virtual $Object* readUpdate(::sun::rmi::log::LogInputStream* in, Object$* state);
	virtual $Object* recover(::java::io::InputStream* in);
	virtual void snapshot(::java::io::OutputStream* out, Object$* value);
	virtual void writeUpdate(::sun::rmi::log::LogOutputStream* out, Object$* value);
};

		} // log
	} // rmi
} // sun

#endif // _sun_rmi_log_LogHandler_h_