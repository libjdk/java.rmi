#ifndef _sun_rmi_transport_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_h_
#define _sun_rmi_transport_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_h_
//$ class sun.rmi.transport.DGCClient$EndpointEntry$RefEntry$PhantomLiveRef
//$ extends java.lang.ref.PhantomReference

#include <java/lang/ref/PhantomReference.h>

namespace sun {
	namespace rmi {
		namespace transport {
			class DGCClient$EndpointEntry$RefEntry;
			class LiveRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry$RefEntry$PhantomLiveRef : public ::java::lang::ref::PhantomReference {
	$class(DGCClient$EndpointEntry$RefEntry$PhantomLiveRef, $NO_CLASS_INIT, ::java::lang::ref::PhantomReference)
public:
	DGCClient$EndpointEntry$RefEntry$PhantomLiveRef();
	void init$(::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry* this$1, ::sun::rmi::transport::LiveRef* ref);
	virtual ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry* getRefEntry();
	::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry* this$1 = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCClient$EndpointEntry$RefEntry$PhantomLiveRef_h_