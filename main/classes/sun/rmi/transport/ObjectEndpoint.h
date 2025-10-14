#ifndef _sun_rmi_transport_ObjectEndpoint_h_
#define _sun_rmi_transport_ObjectEndpoint_h_
//$ class sun.rmi.transport.ObjectEndpoint
//$ extends java.lang.Object

#include <java/lang/Object.h>

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
			class Transport;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class ObjectEndpoint : public ::java::lang::Object {
	$class(ObjectEndpoint, 0, ::java::lang::Object)
public:
	ObjectEndpoint();
	void init$(::java::rmi::server::ObjID* id, ::sun::rmi::transport::Transport* transport);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	::java::rmi::server::ObjID* id = nullptr;
	::sun::rmi::transport::Transport* transport = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_ObjectEndpoint_h_