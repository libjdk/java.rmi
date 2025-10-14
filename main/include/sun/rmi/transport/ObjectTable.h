#ifndef _sun_rmi_transport_ObjectTable_h_
#define _sun_rmi_transport_ObjectTable_h_
//$ class sun.rmi.transport.ObjectTable
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Long;
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
		class Remote;
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
	namespace util {
		class Map;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class GC$LatencyRequest;
			class ObjectEndpoint;
			class Target;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $import ObjectTable : public ::java::lang::Object {
	$class(ObjectTable, 0, ::java::lang::Object)
public:
	ObjectTable();
	void init$();
	static void decrementKeepAliveCount();
	static ::java::rmi::Remote* getStub(::java::rmi::Remote* impl);
	static ::sun::rmi::transport::Target* getTarget(::sun::rmi::transport::ObjectEndpoint* oe);
	static ::sun::rmi::transport::Target* getTarget(::java::rmi::Remote* impl);
	static void incrementKeepAliveCount();
	static ::java::lang::Long* lambda$static$0();
	static void putTarget(::sun::rmi::transport::Target* target);
	static void referenced(::java::rmi::server::ObjID* id, int64_t sequenceNum, ::java::rmi::dgc::VMID* vmid);
	static void removeTarget(::sun::rmi::transport::Target* target);
	static bool unexportObject(::java::rmi::Remote* obj, bool force);
	static void unreferenced(::java::rmi::server::ObjID* id, int64_t sequenceNum, ::java::rmi::dgc::VMID* vmid, bool strong);
	static int64_t gcInterval;
	static $Object* tableLock;
	static ::java::util::Map* objTable;
	static ::java::util::Map* implTable;
	static $Object* keepAliveLock;
	static int32_t keepAliveCount;
	static $Thread* reaper;
	static ::java::lang::ref::ReferenceQueue* reapQueue;
	static ::sun::rmi::transport::GC$LatencyRequest* gcLatencyRequest;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_ObjectTable_h_