#ifndef _sun_rmi_transport_ConnectionInputStream_h_
#define _sun_rmi_transport_ConnectionInputStream_h_
//$ class sun.rmi.transport.ConnectionInputStream
//$ extends sun.rmi.server.MarshalInputStream

#include <sun/rmi/server/MarshalInputStream.h>

namespace java {
	namespace io {
		class InputStream;
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
		class Map;
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Connection;
			class LiveRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class ConnectionInputStream : public ::sun::rmi::server::MarshalInputStream {
	$class(ConnectionInputStream, $NO_CLASS_INIT, ::sun::rmi::server::MarshalInputStream)
public:
	ConnectionInputStream();
	using ::sun::rmi::server::MarshalInputStream::done;
	void init$(::java::io::InputStream* in);
	virtual void discardRefs();
	virtual void done(::sun::rmi::transport::Connection* c);
	using ::sun::rmi::server::MarshalInputStream::read;
	virtual void readID();
	virtual void registerRefs();
	virtual void saveRef(::sun::rmi::transport::LiveRef* ref);
	virtual void setAckNeeded();
	bool dgcAckNeeded = false;
	::java::util::Map* incomingRefTable = nullptr;
	::java::rmi::server::UID* ackID = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_ConnectionInputStream_h_