#ifndef _sun_rmi_runtime_Log$LoggerLogFactory_h_
#define _sun_rmi_runtime_Log$LoggerLogFactory_h_
//$ class sun.rmi.runtime.Log$LoggerLogFactory
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

class Log$LoggerLogFactory : public ::sun::rmi::runtime::Log$LogFactory {
	$class(Log$LoggerLogFactory, $NO_CLASS_INIT, ::sun::rmi::runtime::Log$LogFactory)
public:
	Log$LoggerLogFactory();
	void init$();
	virtual ::sun::rmi::runtime::Log* createLog($String* loggerName, $String* oldLogName, ::java::util::logging::Level* level) override;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_Log$LoggerLogFactory_h_