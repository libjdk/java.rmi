#ifndef _sun_rmi_transport_Endpoint_h_
#define _sun_rmi_transport_Endpoint_h_
//$ interface sun.rmi.transport.Endpoint
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace rmi {
		namespace transport {
			class Channel;
			class Target;
			class Transport;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $export Endpoint : public ::java::lang::Object {
	$interface(Endpoint, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void exportObject(::sun::rmi::transport::Target* target) {}
	virtual ::sun::rmi::transport::Channel* getChannel() {return nullptr;}
	virtual ::sun::rmi::transport::Transport* getInboundTransport() {return nullptr;}
	virtual ::sun::rmi::transport::Transport* getOutboundTransport() {return nullptr;}
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_Endpoint_h_