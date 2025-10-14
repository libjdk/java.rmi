#ifndef _java_rmi_server_UnicastRemoteObject_h_
#define _java_rmi_server_UnicastRemoteObject_h_
//$ class java.rmi.server.UnicastRemoteObject
//$ extends java.rmi.server.RemoteServer

#include <java/rmi/server/RemoteServer.h>

namespace java {
	namespace io {
		class ObjectInputFilter;
		class ObjectInputStream;
	}
}
namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
			class RemoteStub;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class UnicastServerRef;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import UnicastRemoteObject : public ::java::rmi::server::RemoteServer {
	$class(UnicastRemoteObject, $NO_CLASS_INIT, ::java::rmi::server::RemoteServer)
public:
	UnicastRemoteObject();
	void init$();
	void init$(int32_t port);
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	virtual $Object* clone() override;
	static ::java::rmi::server::RemoteStub* exportObject(::java::rmi::Remote* obj);
	static ::java::rmi::Remote* exportObject(::java::rmi::Remote* obj, int32_t port);
	static ::java::rmi::Remote* exportObject(::java::rmi::Remote* obj, int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	static ::java::rmi::Remote* exportObject(::java::rmi::Remote* obj, int32_t port, ::java::io::ObjectInputFilter* filter);
	static ::java::rmi::Remote* exportObject(::java::rmi::Remote* obj, int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf, ::java::io::ObjectInputFilter* filter);
	static ::java::rmi::Remote* exportObject(::java::rmi::Remote* obj, ::sun::rmi::server::UnicastServerRef* sref);
	void readObject(::java::io::ObjectInputStream* in);
	void reexport();
	static bool unexportObject(::java::rmi::Remote* obj, bool force);
	int32_t port = 0;
	::java::rmi::server::RMIClientSocketFactory* csf = nullptr;
	::java::rmi::server::RMIServerSocketFactory* ssf = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x45091215F5E27E31;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_UnicastRemoteObject_h_