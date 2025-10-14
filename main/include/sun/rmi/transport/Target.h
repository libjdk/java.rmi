#ifndef _sun_rmi_transport_Target_h_
#define _sun_rmi_transport_Target_h_
//$ class sun.rmi.transport.Target
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class ClassLoader;
		class Void;
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
			class Unreferenced;
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
		class Hashtable;
		class Vector;
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class Dispatcher;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class ObjectEndpoint;
			class Transport;
			class WeakRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $import Target : public ::java::lang::Object {
	$class(Target, 0, ::java::lang::Object)
public:
	Target();
	void init$(::java::rmi::Remote* impl, ::sun::rmi::server::Dispatcher* disp, ::java::rmi::Remote* stub, ::java::rmi::server::ObjID* id, bool permanent);
	static bool checkLoaderAncestry(::java::lang::ClassLoader* child, ::java::lang::ClassLoader* ancestor);
	void decrementCallCount();
	::java::security::AccessControlContext* getAccessControlContext();
	::java::lang::ClassLoader* getContextClassLoader();
	::sun::rmi::server::Dispatcher* getDispatcher();
	::java::rmi::Remote* getImpl();
	::sun::rmi::transport::ObjectEndpoint* getObjectEndpoint();
	::java::rmi::Remote* getStub();
	::sun::rmi::transport::WeakRef* getWeakImpl();
	void incrementCallCount();
	bool isEmpty();
	bool isPermanent();
	static ::java::lang::Void* lambda$refSetRemove$0(::java::rmi::server::Unreferenced* unrefObj);
	void lambda$refSetRemove$1(::java::rmi::server::Unreferenced* unrefObj);
	void markRemoved();
	void pinImpl();
	void refSetRemove(::java::rmi::dgc::VMID* vmid);
	void referenced(int64_t sequenceNum, ::java::rmi::dgc::VMID* vmid);
	void setExportedTransport(::sun::rmi::transport::Transport* exportedTransport);
	bool unexport(bool force);
	void unpinImpl();
	void unreferenced(int64_t sequenceNum, ::java::rmi::dgc::VMID* vmid, bool strong);
	void vmidDead(::java::rmi::dgc::VMID* vmid);
	::java::rmi::server::ObjID* id = nullptr;
	bool permanent = false;
	::sun::rmi::transport::WeakRef* weakImpl = nullptr;
	$volatile(::sun::rmi::server::Dispatcher*) disp = nullptr;
	::java::rmi::Remote* stub = nullptr;
	::java::util::Vector* refSet = nullptr;
	::java::util::Hashtable* sequenceTable = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
	::java::lang::ClassLoader* ccl = nullptr;
	int32_t callCount = 0;
	bool removed = false;
	$volatile(::sun::rmi::transport::Transport*) exportedTransport = nullptr;
	static int32_t nextThreadNum;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_Target_h_