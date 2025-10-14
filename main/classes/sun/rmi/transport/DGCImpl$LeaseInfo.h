#ifndef _sun_rmi_transport_DGCImpl$LeaseInfo_h_
#define _sun_rmi_transport_DGCImpl$LeaseInfo_h_
//$ class sun.rmi.transport.DGCImpl$LeaseInfo
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace rmi {
		namespace dgc {
			class VMID;
		}
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

class DGCImpl$LeaseInfo : public ::java::lang::Object {
	$class(DGCImpl$LeaseInfo, $NO_CLASS_INIT, ::java::lang::Object)
public:
	DGCImpl$LeaseInfo();
	void init$(::java::rmi::dgc::VMID* vmid, int64_t lease);
	virtual bool expired(int64_t time);
	virtual void renew(int64_t lease);
	::java::rmi::dgc::VMID* vmid = nullptr;
	int64_t expiration = 0;
	::java::util::Set* notifySet = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCImpl$LeaseInfo_h_