#ifndef _sun_rmi_transport_StreamRemoteCall_h_
#define _sun_rmi_transport_StreamRemoteCall_h_
//$ class sun.rmi.transport.StreamRemoteCall
//$ extends java.rmi.server.RemoteCall

#include <java/rmi/server/RemoteCall.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectInputFilter;
		class ObjectOutput;
	}
}
namespace java {
	namespace lang {
		class Exception;
		class Void;
	}
}
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
			class Connection;
			class ConnectionInputStream;
			class ConnectionOutputStream;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $import StreamRemoteCall : public ::java::rmi::server::RemoteCall {
	$class(StreamRemoteCall, $NO_CLASS_INIT, ::java::rmi::server::RemoteCall)
public:
	StreamRemoteCall();
	void init$(::sun::rmi::transport::Connection* c);
	void init$(::sun::rmi::transport::Connection* c, ::java::rmi::server::ObjID* id, int32_t op, int64_t hash);
	virtual void discardPendingRefs();
	virtual void done() override;
	virtual void exceptionReceivedFromServer(::java::lang::Exception* ex);
	virtual void executeCall() override;
	virtual ::sun::rmi::transport::Connection* getConnection();
	virtual ::java::io::ObjectInput* getInputStream() override;
	virtual ::java::io::ObjectOutput* getOutputStream() override;
	::java::io::ObjectOutput* getOutputStream(bool resultStream);
	virtual ::java::io::ObjectOutput* getResultStream(bool success) override;
	virtual ::java::lang::Exception* getServerException();
	::java::lang::Void* lambda$getInputStream$0();
	virtual void releaseInputStream() override;
	virtual void releaseOutputStream() override;
	virtual void setObjectInputFilter(::java::io::ObjectInputFilter* filter);
	::sun::rmi::transport::ConnectionInputStream* in = nullptr;
	::sun::rmi::transport::ConnectionOutputStream* out = nullptr;
	::sun::rmi::transport::Connection* conn = nullptr;
	::java::io::ObjectInputFilter* filter = nullptr;
	bool resultStarted = false;
	::java::lang::Exception* serverException = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_StreamRemoteCall_h_