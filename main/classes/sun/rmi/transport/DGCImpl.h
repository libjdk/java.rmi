#ifndef _sun_rmi_transport_DGCImpl_h_
#define _sun_rmi_transport_DGCImpl_h_
//$ class sun.rmi.transport.DGCImpl
//$ extends java.rmi.dgc.DGC

#include <java/lang/Array.h>
#include <java/rmi/dgc/DGC.h>

#pragma push_macro("DGC_FILTER_PROPNAME")
#undef DGC_FILTER_PROPNAME
#pragma push_macro("DGC_MAX_ARRAY_SIZE")
#undef DGC_MAX_ARRAY_SIZE
#pragma push_macro("DGC_MAX_DEPTH")
#undef DGC_MAX_DEPTH

namespace java {
	namespace io {
		class ObjectInputFilter;
		class ObjectInputFilter$FilterInfo;
		class ObjectInputFilter$Status;
	}
}
namespace java {
	namespace lang {
		class Long;
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
		}
	}
}
namespace java {
	namespace util {
		class Map;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Future;
			class ScheduledExecutorService;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Target;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl : public ::java::rmi::dgc::DGC {
	$class(DGCImpl, 0, ::java::rmi::dgc::DGC)
public:
	DGCImpl();
	void init$();
	static ::java::io::ObjectInputFilter$Status* checkInput(::java::io::ObjectInputFilter$FilterInfo* filterInfo);
	void checkLeases();
	virtual void clean($Array<::java::rmi::server::ObjID>* ids, int64_t sequenceNum, ::java::rmi::dgc::VMID* vmid, bool strong) override;
	virtual ::java::rmi::dgc::Lease* dirty($Array<::java::rmi::server::ObjID>* ids, int64_t sequenceNum, ::java::rmi::dgc::Lease* lease) override;
	static ::sun::rmi::transport::DGCImpl* getDGCImpl();
	static ::java::io::ObjectInputFilter* initDgcFilter();
	static $String* lambda$static$0();
	static ::java::lang::Long* lambda$static$1();
	static ::java::lang::Long* lambda$static$2();
	void registerTarget(::java::rmi::dgc::VMID* vmid, ::sun::rmi::transport::Target* target);
	void unregisterTarget(::java::rmi::dgc::VMID* vmid, ::sun::rmi::transport::Target* target);
	static ::sun::rmi::runtime::Log* dgcLog;
	static int64_t leaseValue;
	static int64_t leaseCheckInterval;
	static ::java::util::concurrent::ScheduledExecutorService* scheduler;
	static ::sun::rmi::transport::DGCImpl* dgc;
	::java::util::Map* leaseTable = nullptr;
	::java::util::concurrent::Future* checker = nullptr;
	static $String* DGC_FILTER_PROPNAME;
	static int32_t DGC_MAX_DEPTH;
	static int32_t DGC_MAX_ARRAY_SIZE;
	static ::java::io::ObjectInputFilter* dgcFilter;
};

		} // transport
	} // rmi
} // sun

#pragma pop_macro("DGC_FILTER_PROPNAME")
#pragma pop_macro("DGC_MAX_ARRAY_SIZE")
#pragma pop_macro("DGC_MAX_DEPTH")

#endif // _sun_rmi_transport_DGCImpl_h_