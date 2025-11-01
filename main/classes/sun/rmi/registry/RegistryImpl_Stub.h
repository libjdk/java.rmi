#ifndef _sun_rmi_registry_RegistryImpl_Stub_h_
#define _sun_rmi_registry_RegistryImpl_Stub_h_
//$ class sun.rmi.registry.RegistryImpl_Stub
//$ extends java.rmi.server.RemoteStub
//$ implements java.rmi.registry.Registry

#include <java/lang/Array.h>
#include <java/rmi/registry/Registry.h>
#include <java/rmi/server/RemoteStub.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class Operation;
			class RemoteRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace registry {

class $export RegistryImpl_Stub : public ::java::rmi::server::RemoteStub, public ::java::rmi::registry::Registry {
	$class(RegistryImpl_Stub, 0, ::java::rmi::server::RemoteStub, ::java::rmi::registry::Registry)
public:
	RegistryImpl_Stub();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void init$(::java::rmi::server::RemoteRef* ref);
	virtual void bind($String* $param_String_1, ::java::rmi::Remote* $param_Remote_2) override;
	virtual $StringArray* list() override;
	virtual ::java::rmi::Remote* lookup($String* $param_String_1) override;
	virtual void rebind($String* $param_String_1, ::java::rmi::Remote* $param_Remote_2) override;
	virtual $String* toString() override;
	virtual void unbind($String* $param_String_1) override;
	static $Array<::java::rmi::server::Operation>* operations;
	static const int64_t interfaceHash = (int64_t)0x44154DC9D4E63BDF;
};

		} // registry
	} // rmi
} // sun

#endif // _sun_rmi_registry_RegistryImpl_Stub_h_