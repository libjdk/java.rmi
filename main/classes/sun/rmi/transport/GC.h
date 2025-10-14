#ifndef _sun_rmi_transport_GC_h_
#define _sun_rmi_transport_GC_h_
//$ class sun.rmi.transport.GC
//$ extends java.lang.Object

#include <java/lang/Long.h>

#pragma push_macro("GC")
#undef GC
#pragma push_macro("MAX_VALUE")
#undef MAX_VALUE
#pragma push_macro("NO_TARGET")
#undef NO_TARGET

namespace java {
	namespace lang {
		class Thread;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class GC$LatencyRequest;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class GC : public ::java::lang::Object {
	$class(GC, 0, ::java::lang::Object)
public:
	GC();
	void init$();
	static int64_t currentLatencyTarget();
	static int64_t maxObjectInspectionAge();
	static ::sun::rmi::transport::GC$LatencyRequest* requestLatency(int64_t latency);
	static void setLatencyTarget(int64_t ms);
	static const int64_t NO_TARGET = ::java::lang::Long::MAX_VALUE;
	static int64_t latencyTarget;
	static $Thread* daemon;
	static $Object* lock;
};

		} // transport
	} // rmi
} // sun

#pragma pop_macro("GC")
#pragma pop_macro("MAX_VALUE")
#pragma pop_macro("NO_TARGET")

#endif // _sun_rmi_transport_GC_h_