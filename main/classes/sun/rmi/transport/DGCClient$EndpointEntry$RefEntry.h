#ifndef _sun_rmi_transport_DGCClient$EndpointEntry$RefEntry_h_
#define _sun_rmi_transport_DGCClient$EndpointEntry$RefEntry_h_
//$ class sun.rmi.transport.DGCClient$EndpointEntry$RefEntry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class Set;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class DGCClient$EndpointEntry;
			class DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;
			class LiveRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry$RefEntry : public ::java::lang::Object {
	$class(DGCClient$EndpointEntry$RefEntry, 0, ::java::lang::Object)
public:
	DGCClient$EndpointEntry$RefEntry();
	void init$(::sun::rmi::transport::DGCClient$EndpointEntry* this$0, ::sun::rmi::transport::LiveRef* ref);
	virtual void addInstanceToRefSet(::sun::rmi::transport::LiveRef* ref);
	virtual ::sun::rmi::transport::LiveRef* getRef();
	virtual bool hasDirtyFailed();
	virtual bool isRefSetEmpty();
	virtual void markDirtyFailed();
	virtual void removeInstanceFromRefSet(::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef* phantom);
	::sun::rmi::transport::DGCClient$EndpointEntry* this$0 = nullptr;
	static bool $assertionsDisabled;
	::sun::rmi::transport::LiveRef* ref = nullptr;
	::java::util::Set* refSet = nullptr;
	bool dirtyFailed = false;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCClient$EndpointEntry$RefEntry_h_