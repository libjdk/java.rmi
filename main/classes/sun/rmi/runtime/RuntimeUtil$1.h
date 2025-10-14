#ifndef _sun_rmi_runtime_RuntimeUtil$1_h_
#define _sun_rmi_runtime_RuntimeUtil$1_h_
//$ class sun.rmi.runtime.RuntimeUtil$1
//$ extends java.util.concurrent.ThreadFactory

#include <java/util/concurrent/ThreadFactory.h>

namespace java {
	namespace lang {
		class Runnable;
		class Thread;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicInteger;
			}
		}
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class RuntimeUtil;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class RuntimeUtil$1 : public ::java::util::concurrent::ThreadFactory {
	$class(RuntimeUtil$1, $NO_CLASS_INIT, ::java::util::concurrent::ThreadFactory)
public:
	RuntimeUtil$1();
	void init$(::sun::rmi::runtime::RuntimeUtil* this$0);
	virtual $Thread* newThread(::java::lang::Runnable* runnable) override;
	::sun::rmi::runtime::RuntimeUtil* this$0 = nullptr;
	::java::util::concurrent::atomic::AtomicInteger* count = nullptr;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_RuntimeUtil$1_h_