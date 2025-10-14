#ifndef _sun_rmi_transport_DGCClient$EndpointEntry_h_
#define _sun_rmi_transport_DGCClient$EndpointEntry_h_
//$ class sun.rmi.transport.DGCClient$EndpointEntry
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Thread;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class ReferenceQueue;
		}
	}
}
namespace java {
	namespace rmi {
		namespace dgc {
			class DGC;
		}
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class ObjID;
		}
	}
}
namespace java {
	namespace util {
		class List;
		class Map;
		class Set;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class DGCClient$EndpointEntry$RefEntry;
			class DGCClient$EndpointEntry$RefEntry$PhantomLiveRef;
			class Endpoint;
			class GC$LatencyRequest;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry : public ::java::lang::Object {
	$class(DGCClient$EndpointEntry, 0, ::java::lang::Object)
public:
	DGCClient$EndpointEntry();
	void init$(::sun::rmi::transport::Endpoint* endpoint);
	static $Array<::java::rmi::server::ObjID>* createObjIDArray(::java::util::Set* refEntries);
	static ::sun::rmi::transport::DGCClient$EndpointEntry* lookup(::sun::rmi::transport::Endpoint* ep);
	void makeCleanCalls();
	void makeDirtyCall(::java::util::Set* refEntries, int64_t sequenceNum);
	void processPhantomRefs(::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef* phantom);
	virtual bool registerRefs(::java::util::List* refs);
	void removeRefEntry(::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry* refEntry);
	void setRenewTime(int64_t newRenewTime);
	static bool $assertionsDisabled;
	::sun::rmi::transport::Endpoint* endpoint = nullptr;
	::java::rmi::dgc::DGC* dgc = nullptr;
	::java::util::Map* refTable = nullptr;
	::java::util::Set* invalidRefs = nullptr;
	bool removed = false;
	int64_t renewTime = 0;
	int64_t expirationTime = 0;
	int32_t dirtyFailures = 0;
	int64_t dirtyFailureStartTime = 0;
	int64_t dirtyFailureDuration = 0;
	$Thread* renewCleanThread = nullptr;
	bool interruptible = false;
	::java::lang::ref::ReferenceQueue* refQueue = nullptr;
	::java::util::Set* pendingCleans = nullptr;
	static ::java::util::Map* endpointTable;
	static ::sun::rmi::transport::GC$LatencyRequest* gcLatencyRequest;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCClient$EndpointEntry_h_