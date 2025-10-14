#ifndef _sun_rmi_transport_DGCClient$EndpointEntry$RenewCleanThread_h_
#define _sun_rmi_transport_DGCClient$EndpointEntry$RenewCleanThread_h_
//$ class sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace java {
	namespace lang {
		class Void;
	}
}
namespace java {
	namespace util {
		class Set;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class DGCClient$EndpointEntry;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry$RenewCleanThread : public ::java::lang::Runnable {
	$class(DGCClient$EndpointEntry$RenewCleanThread, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	DGCClient$EndpointEntry$RenewCleanThread();
	void init$(::sun::rmi::transport::DGCClient$EndpointEntry* this$0);
	::java::lang::Void* lambda$run$0(bool needRenewal_, ::java::util::Set* refsToDirty_, int64_t sequenceNum_);
	virtual void run() override;
	::sun::rmi::transport::DGCClient$EndpointEntry* this$0 = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCClient$EndpointEntry$RenewCleanThread_h_