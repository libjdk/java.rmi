#ifndef _sun_rmi_server_UnicastServerRef2_h_
#define _sun_rmi_server_UnicastServerRef2_h_
//$ class sun.rmi.server.UnicastServerRef2
//$ extends sun.rmi.server.UnicastServerRef

#include <sun/rmi/server/UnicastServerRef.h>

namespace java {
	namespace io {
		class ObjectInputFilter;
		class ObjectOutput;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
			class RemoteRef;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace transport {
			class LiveRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $import UnicastServerRef2 : public ::sun::rmi::server::UnicastServerRef {
	$class(UnicastServerRef2, $NO_CLASS_INIT, ::sun::rmi::server::UnicastServerRef)
public:
	UnicastServerRef2();
	void init$();
	void init$(::sun::rmi::transport::LiveRef* ref);
	void init$(::sun::rmi::transport::LiveRef* ref, ::java::io::ObjectInputFilter* filter);
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf, ::java::io::ObjectInputFilter* filter);
	virtual ::java::rmi::server::RemoteRef* getClientRef() override;
	virtual $String* getRefClass(::java::io::ObjectOutput* out) override;
	static const int64_t serialVersionUID = (int64_t)0xE0395683857F5482;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_UnicastServerRef2_h_