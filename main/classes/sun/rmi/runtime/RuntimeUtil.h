#ifndef _sun_rmi_runtime_RuntimeUtil_h_
#define _sun_rmi_runtime_RuntimeUtil_h_
//$ class sun.rmi.runtime.RuntimeUtil
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("GET_INSTANCE_PERMISSION")
#undef GET_INSTANCE_PERMISSION

namespace java {
	namespace lang {
		class Integer;
	}
}
namespace java {
	namespace security {
		class Permission;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ScheduledThreadPoolExecutor;
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

class RuntimeUtil : public ::java::lang::Object {
	$class(RuntimeUtil, 0, ::java::lang::Object)
public:
	RuntimeUtil();
	void init$();
	static ::sun::rmi::runtime::RuntimeUtil* getInstance();
	::java::util::concurrent::ScheduledThreadPoolExecutor* getScheduler();
	static ::java::lang::Integer* lambda$static$0();
	static ::sun::rmi::runtime::Log* runtimeLog;
	static int32_t schedulerThreads;
	static ::java::security::Permission* GET_INSTANCE_PERMISSION;
	static ::sun::rmi::runtime::RuntimeUtil* instance;
	::java::util::concurrent::ScheduledThreadPoolExecutor* scheduler = nullptr;
};

		} // runtime
	} // rmi
} // sun

#pragma pop_macro("GET_INSTANCE_PERMISSION")

#endif // _sun_rmi_runtime_RuntimeUtil_h_