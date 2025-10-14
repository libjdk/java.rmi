#ifndef _sun_rmi_transport_ConnectionOutputStream_h_
#define _sun_rmi_transport_ConnectionOutputStream_h_
//$ class sun.rmi.transport.ConnectionOutputStream
//$ extends sun.rmi.server.MarshalOutputStream

#include <sun/rmi/server/MarshalOutputStream.h>

namespace java {
	namespace rmi {
		namespace server {
			class UID;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Connection;
			class DGCAckHandler;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class ConnectionOutputStream : public ::sun::rmi::server::MarshalOutputStream {
	$class(ConnectionOutputStream, 0, ::sun::rmi::server::MarshalOutputStream)
public:
	ConnectionOutputStream();
	void init$(::sun::rmi::transport::Connection* conn, bool resultStream);
	virtual void done();
	virtual ::sun::rmi::transport::DGCAckHandler* getDGCAckHandler();
	virtual bool isResultStream();
	virtual void saveObject(Object$* obj);
	virtual void writeID();
	static bool $assertionsDisabled;
	::sun::rmi::transport::Connection* conn = nullptr;
	bool resultStream = false;
	::java::rmi::server::UID* ackID = nullptr;
	::sun::rmi::transport::DGCAckHandler* dgcAckHandler = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_ConnectionOutputStream_h_