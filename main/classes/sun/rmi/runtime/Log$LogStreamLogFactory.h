#ifndef _sun_rmi_runtime_Log$LogStreamLogFactory_h_
#define _sun_rmi_runtime_Log$LogStreamLogFactory_h_
//$ class sun.rmi.runtime.Log$LogStreamLogFactory
//$ extends sun.rmi.runtime.Log$LogFactory

#include <sun/rmi/runtime/Log$LogFactory.h>

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

class Log$LogStreamLogFactory : public ::sun::rmi::runtime::Log$LogFactory {
	$class(Log$LogStreamLogFactory, $NO_CLASS_INIT, ::sun::rmi::runtime::Log$LogFactory)
public:
	Log$LogStreamLogFactory();
	void init$();
	virtual ::sun::rmi::runtime::Log* createLog($String* loggerName, $String* oldLogName, ::java::util::logging::Level* level) override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LogStreamLogFactory_h_