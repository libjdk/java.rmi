#ifndef _sun_rmi_transport_DGCImpl_Stub_h_
#define _sun_rmi_transport_DGCImpl_Stub_h_
//$ class sun.rmi.transport.DGCImpl_Stub
//$ extends java.rmi.server.RemoteStub
//$ implements java.rmi.dgc.DGC

#include <java/lang/Array.h>
#include <java/rmi/dgc/DGC.h>
#include <java/rmi/server/RemoteStub.h>

#pragma push_macro("DGCCLIENT_MAX_ARRAY_SIZE")
#undef DGCCLIENT_MAX_ARRAY_SIZE
#pragma push_macro("DGCCLIENT_MAX_DEPTH")
#undef DGCCLIENT_MAX_DEPTH

namespace java {
	namespace io {
		class ObjectInputFilter$FilterInfo;
		class ObjectInputFilter$Status;
	}
}
namespace java {
	namespace rmi {
		namespace dgc {
			class Lease;
			class VMID;
		}
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class ObjID;
			class Operation;
			class RemoteRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $import DGCImpl_Stub : public ::java::rmi::server::RemoteStub, public ::java::rmi::dgc::DGC {
	$class(DGCImpl_Stub, 0, ::java::rmi::server::RemoteStub, ::java::rmi::dgc::DGC)
public:
	DGCImpl_Stub();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void init$(::java::rmi::server::RemoteRef* ref);
	virtual void clean($Array<::java::rmi::server::ObjID>* $param_arrayOf_ObjID_1, int64_t $param_long_2, ::java::rmi::dgc::VMID* $param_VMID_3, bool $param_boolean_4) override;
	virtual ::java::rmi::dgc::Lease* dirty($Array<::java::rmi::server::ObjID>* $param_arrayOf_ObjID_1, int64_t $param_long_2, ::java::rmi::dgc::Lease* $param_Lease_3) override;
	static ::java::io::ObjectInputFilter$Status* leaseFilter(::java::io::ObjectInputFilter$FilterInfo* filterInfo);
	virtual $String* toString() override;
	static $Array<::java::rmi::server::Operation>* operations;
	static const int64_t interfaceHash = (int64_t)0xF6B6898D8BF28643;
	static int32_t DGCCLIENT_MAX_DEPTH;
	static int32_t DGCCLIENT_MAX_ARRAY_SIZE;
};

		} // transport
	} // rmi
} // sun

#pragma pop_macro("DGCCLIENT_MAX_ARRAY_SIZE")
#pragma pop_macro("DGCCLIENT_MAX_DEPTH")

#endif // _sun_rmi_transport_DGCImpl_Stub_h_