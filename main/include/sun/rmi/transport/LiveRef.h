#ifndef _sun_rmi_transport_LiveRef_h_
#define _sun_rmi_transport_LiveRef_h_
//$ class sun.rmi.transport.LiveRef
//$ extends java.lang.Cloneable

#include <java/lang/Cloneable.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectOutput;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class ObjID;
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class Channel;
			class Endpoint;
			class Target;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $import LiveRef : public ::java::lang::Cloneable {
	$class(LiveRef, $NO_CLASS_INIT, ::java::lang::Cloneable)
public:
	LiveRef();
	void init$(::java::rmi::server::ObjID* objID, ::sun::rmi::transport::Endpoint* endpoint, bool isLocal);
	void init$(int32_t port);
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	void init$(::java::rmi::server::ObjID* objID, int32_t port);
	void init$(::java::rmi::server::ObjID* objID, int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void exportObject(::sun::rmi::transport::Target* target);
	virtual ::sun::rmi::transport::Channel* getChannel();
	virtual ::java::rmi::server::RMIClientSocketFactory* getClientSocketFactory();
	virtual ::sun::rmi::transport::Endpoint* getEndpoint();
	virtual ::java::rmi::server::ObjID* getObjID();
	virtual int32_t getPort();
	virtual ::java::rmi::server::RMIServerSocketFactory* getServerSocketFactory();
	virtual int32_t hashCode() override;
	static ::sun::rmi::transport::LiveRef* read(::java::io::ObjectInput* in, bool useNewFormat);
	virtual bool remoteEquals(Object$* obj);
	virtual $String* toString() override;
	virtual void write(::java::io::ObjectOutput* out, bool useNewFormat);
	::sun::rmi::transport::Endpoint* ep = nullptr;
	::java::rmi::server::ObjID* id = nullptr;
	::sun::rmi::transport::Channel* ch = nullptr;
	bool isLocal = false;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_LiveRef_h_