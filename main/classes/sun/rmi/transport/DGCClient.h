#ifndef _sun_rmi_transport_DGCClient_h_
#define _sun_rmi_transport_DGCClient_h_
//$ class sun.rmi.transport.DGCClient
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("SOCKET_ACC")
#undef SOCKET_ACC

namespace java {
	namespace lang {
		class Long;
	}
}
namespace java {
	namespace rmi {
		namespace dgc {
			class VMID;
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
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Endpoint;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient : public ::java::lang::Object {
	$class(DGCClient, 0, ::java::lang::Object)
public:
	DGCClient();
	void init$();
	static int64_t computeRenewTime(int64_t grantTime, int64_t duration);
	static int64_t getNextSequenceNum();
	static ::java::lang::Long* lambda$static$0();
	static ::java::lang::Long* lambda$static$1();
	static ::java::lang::Long* lambda$static$2();
	static void registerRefs(::sun::rmi::transport::Endpoint* ep, ::java::util::List* refs);
	static int64_t nextSequenceNum;
	static ::java::rmi::dgc::VMID* vmid;
	static int64_t leaseValue;
	static int64_t cleanInterval;
	static int64_t gcInterval;
	static const int32_t dirtyFailureRetries = 5;
	static const int32_t cleanFailureRetries = 5;
	static $Array<::java::rmi::server::ObjID>* emptyObjIDArray;
	static ::java::rmi::server::ObjID* dgcID;
	static ::java::security::AccessControlContext* SOCKET_ACC;
};

		} // transport
	} // rmi
} // sun

#pragma pop_macro("SOCKET_ACC")

#endif // _sun_rmi_transport_DGCClient_h_