#ifndef _sun_rmi_runtime_Log$LogFactory_h_
#define _sun_rmi_runtime_Log$LogFactory_h_
//$ interface sun.rmi.runtime.Log$LogFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
			class Log;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log$LogFactory : public ::java::lang::Object {
	$interface(Log$LogFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::sun::rmi::runtime::Log* createLog($String* loggerName, $String* oldLogName, ::java::util::logging::Level* level) {return nullptr;}
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LogFactory_h_