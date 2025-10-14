#ifndef _java_rmi_dgc_DGC_h_
#define _java_rmi_dgc_DGC_h_
//$ interface java.rmi.dgc.DGC
//$ extends java.rmi.Remote

#include <java/lang/Array.h>
#include <java/rmi/Remote.h>

#pragma push_macro("DGC")
#undef DGC

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
		}
	}
}

namespace java {
	namespace rmi {
		namespace dgc {

class $import DGC : public ::java::rmi::Remote {
	$interface(DGC, $NO_CLASS_INIT, ::java::rmi::Remote)
public:
	virtual void clean($Array<::java::rmi::server::ObjID>* ids, int64_t sequenceNum, ::java::rmi::dgc::VMID* vmid, bool strong) {}
	virtual ::java::rmi::dgc::Lease* dirty($Array<::java::rmi::server::ObjID>* ids, int64_t sequenceNum, ::java::rmi::dgc::Lease* lease) {return nullptr;}
};

		} // dgc
	} // rmi
} // java

#pragma pop_macro("DGC")

#endif // _java_rmi_dgc_DGC_h_