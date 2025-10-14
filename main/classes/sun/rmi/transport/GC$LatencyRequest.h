#ifndef _sun_rmi_transport_GC$LatencyRequest_h_
#define _sun_rmi_transport_GC$LatencyRequest_h_
//$ class sun.rmi.transport.GC$LatencyRequest
//$ extends java.lang.Comparable

#include <java/lang/Comparable.h>

namespace java {
	namespace util {
		class SortedSet;
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class GC$LatencyRequest : public ::java::lang::Comparable {
	$class(GC$LatencyRequest, 0, ::java::lang::Comparable)
public:
	GC$LatencyRequest();
	void init$(int64_t ms);
	static void adjustLatencyIfNeeded();
	virtual void cancel();
	virtual int32_t compareTo(::sun::rmi::transport::GC$LatencyRequest* r);
	virtual int32_t compareTo(Object$* r) override;
	virtual $String* toString() override;
	static int64_t counter;
	static ::java::util::SortedSet* requests;
	int64_t latency = 0;
	int64_t id = 0;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_GC$LatencyRequest_h_