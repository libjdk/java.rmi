#ifndef _sun_rmi_transport_Channel_h_
#define _sun_rmi_transport_Channel_h_
//$ interface sun.rmi.transport.Channel
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace rmi {
		namespace transport {
			class Connection;
			class Endpoint;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $import Channel : public ::java::lang::Object {
	$interface(Channel, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void free(::sun::rmi::transport::Connection* conn, bool reuse) {}
	virtual ::sun::rmi::transport::Endpoint* getEndpoint() {return nullptr;}
	virtual ::sun::rmi::transport::Connection* newConnection() {return nullptr;}
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_Channel_h_