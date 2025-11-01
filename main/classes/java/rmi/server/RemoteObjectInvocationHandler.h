#ifndef _java_rmi_server_RemoteObjectInvocationHandler_h_
#define _java_rmi_server_RemoteObjectInvocationHandler_h_
//$ class java.rmi.server.RemoteObjectInvocationHandler
//$ extends java.rmi.server.RemoteObject
//$ implements java.lang.reflect.InvocationHandler

#include <java/lang/Array.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/rmi/server/RemoteObject.h>

namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class RemoteObjectInvocationHandler$MethodToHash_Maps;
			class RemoteRef;
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export RemoteObjectInvocationHandler : public ::java::rmi::server::RemoteObject, public ::java::lang::reflect::InvocationHandler {
	$class(RemoteObjectInvocationHandler, 0, ::java::rmi::server::RemoteObject, ::java::lang::reflect::InvocationHandler)
public:
	RemoteObjectInvocationHandler();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::java::rmi::server::RemoteRef* ref);
	static int64_t getMethodHash(::java::lang::reflect::Method* method);
	virtual $Object* invoke(Object$* proxy, ::java::lang::reflect::Method* method, $ObjectArray* args) override;
	$Object* invokeObjectMethod(Object$* proxy, ::java::lang::reflect::Method* method, $ObjectArray* args);
	$Object* invokeRemoteMethod(Object$* proxy, ::java::lang::reflect::Method* method, $ObjectArray* args);
	$String* proxyToString(Object$* proxy);
	void readObjectNoData();
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)2;
	static ::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps* methodToHash_Maps;
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteObjectInvocationHandler_h_