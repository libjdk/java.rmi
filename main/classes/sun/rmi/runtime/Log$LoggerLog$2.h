#ifndef _sun_rmi_runtime_Log$LoggerLog$2_h_
#define _sun_rmi_runtime_Log$LoggerLog$2_h_
//$ class sun.rmi.runtime.Log$LoggerLog$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class Level;
			class Logger;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log$LoggerLog;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$LoggerLog$2 : public ::java::security::PrivilegedAction {
	$class(Log$LoggerLog$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Log$LoggerLog$2();
	void init$(::sun::rmi::runtime::Log$LoggerLog* this$0, ::java::util::logging::Logger* val$logger, ::java::util::logging::Level* val$level);
	virtual $Object* run() override;
	::sun::rmi::runtime::Log$LoggerLog* this$0 = nullptr;
	::java::util::logging::Level* val$level = nullptr;
	::java::util::logging::Logger* val$logger = nullptr;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LoggerLog$2_h_