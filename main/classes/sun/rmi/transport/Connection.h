#ifndef _sun_rmi_transport_Connection_h_
#define _sun_rmi_transport_Connection_h_
//$ interface sun.rmi.transport.Connection
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Channel;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $export Connection : public ::java::lang::Object {
	$interface(Connection, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void close() {}
	virtual ::sun::rmi::transport::Channel* getChannel() {return nullptr;}
	virtual ::java::io::InputStream* getInputStream() {return nullptr;}
	virtual ::java::io::OutputStream* getOutputStream() {return nullptr;}
	virtual bool isReusable() {return false;}
	virtual void releaseInputStream() {}
	virtual void releaseOutputStream() {}
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_Connection_h_