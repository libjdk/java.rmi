#ifndef _java_rmi_server_RemoteRef_h_
#define _java_rmi_server_RemoteRef_h_
//$ interface java.rmi.server.RemoteRef
//$ extends java.io.Externalizable

#include <java/io/Externalizable.h>
#include <java/lang/Array.h>

namespace java {
	namespace io {
		class ObjectOutput;
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
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
			class Operation;
			class RemoteCall;
			class RemoteObject;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export RemoteRef : public ::java::io::Externalizable {
	$interface(RemoteRef, 0, ::java::io::Externalizable)
public:
	virtual void done(::java::rmi::server::RemoteCall* call) {}
	virtual $String* getRefClass(::java::io::ObjectOutput* out) {return nullptr;}
	virtual $Object* invoke(::java::rmi::Remote* obj, ::java::lang::reflect::Method* method, $ObjectArray* params, int64_t opnum) {return nullptr;}
	virtual void invoke(::java::rmi::server::RemoteCall* call) {}
	virtual ::java::rmi::server::RemoteCall* newCall(::java::rmi::server::RemoteObject* obj, $Array<::java::rmi::server::Operation>* op, int32_t opnum, int64_t hash) {return nullptr;}
	virtual bool remoteEquals(::java::rmi::server::RemoteRef* obj) {return false;}
	virtual int32_t remoteHashCode() {return 0;}
	virtual $String* remoteToString() {return nullptr;}
	static const int64_t serialVersionUID = (int64_t)0x3269B97E7CD281B1;
	static $String* packagePrefix;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteRef_h_