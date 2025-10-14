#ifndef _sun_rmi_transport_DGCAckHandler_h_
#define _sun_rmi_transport_DGCAckHandler_h_
//$ class sun.rmi.transport.DGCAckHandler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Long;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class UID;
		}
	}
}
namespace java {
	namespace util {
		class List;
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
		namespace transport {

class $import DGCAckHandler : public ::java::lang::Object {
	$class(DGCAckHandler, 0, ::java::lang::Object)
public:
	DGCAckHandler();
	void init$(::java::rmi::server::UID* id);
	virtual void add(Object$* obj);
	static ::java::lang::Long* lambda$static$0();
	static void received(::java::rmi::server::UID* id);
	virtual void release();
	virtual void startTimer();
	static bool $assertionsDisabled;
	static int64_t dgcAckTimeout;
	static ::java::util::concurrent::ScheduledExecutorService* scheduler;
	static ::java::util::Map* idTable;
	::java::rmi::server::UID* id = nullptr;
	::java::util::List* objList = nullptr;
	::java::util::concurrent::Future* task = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCAckHandler_h_