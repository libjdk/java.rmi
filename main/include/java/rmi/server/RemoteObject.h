#ifndef _java_rmi_server_RemoteObject_h_
#define _java_rmi_server_RemoteObject_h_
//$ class java.rmi.server.RemoteObject
//$ extends java.rmi.Remote
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <java/rmi/Remote.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteRef;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import RemoteObject : public ::java::rmi::Remote, public ::java::io::Serializable {
	$class(RemoteObject, $NO_CLASS_INIT, ::java::rmi::Remote, ::java::io::Serializable)
public:
	RemoteObject();
	virtual $Object* clone() override;
	virtual void finalize() override;
	void init$();
	void init$(::java::rmi::server::RemoteRef* newref);
	virtual bool equals(Object$* obj) override;
	virtual ::java::rmi::server::RemoteRef* getRef();
	virtual int32_t hashCode() override;
	void readObject(::java::io::ObjectInputStream* in);
	virtual $String* toString() override;
	static ::java::rmi::Remote* toStub(::java::rmi::Remote* obj);
	void writeObject(::java::io::ObjectOutputStream* out);
	::java::rmi::server::RemoteRef* ref = nullptr;
	static const int64_t serialVersionUID = (int64_t)0xD361B4910C61331E;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteObject_h_