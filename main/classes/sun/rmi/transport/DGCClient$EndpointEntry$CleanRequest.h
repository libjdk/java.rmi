#ifndef _sun_rmi_transport_DGCClient$EndpointEntry$CleanRequest_h_
#define _sun_rmi_transport_DGCClient$EndpointEntry$CleanRequest_h_
//$ class sun.rmi.transport.DGCClient$EndpointEntry$CleanRequest
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace rmi {
		namespace server {
			class ObjID;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$EndpointEntry$CleanRequest : public ::java::lang::Object {
	$class(DGCClient$EndpointEntry$CleanRequest, $NO_CLASS_INIT, ::java::lang::Object)
public:
	DGCClient$EndpointEntry$CleanRequest();
	void init$($Array<::java::rmi::server::ObjID>* objIDs, int64_t sequenceNum, bool strong);
	$Array<::java::rmi::server::ObjID>* objIDs = nullptr;
	int64_t sequenceNum = 0;
	bool strong = false;
	int32_t failures = 0;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCClient$EndpointEntry$CleanRequest_h_