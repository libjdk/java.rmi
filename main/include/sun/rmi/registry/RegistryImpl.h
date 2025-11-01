#ifndef _sun_rmi_registry_RegistryImpl_h_
#define _sun_rmi_registry_RegistryImpl_h_
//$ class sun.rmi.registry.RegistryImpl
//$ extends java.rmi.server.RemoteServer
//$ implements java.rmi.registry.Registry

#include <java/lang/Array.h>
#include <java/rmi/registry/Registry.h>
#include <java/rmi/server/RemoteServer.h>

#pragma push_macro("REGISTRY_FILTER_PROPNAME")
#undef REGISTRY_FILTER_PROPNAME
#pragma push_macro("REGISTRY_MAX_ARRAY_SIZE")
#undef REGISTRY_MAX_ARRAY_SIZE
#pragma push_macro("REGISTRY_MAX_DEPTH")
#undef REGISTRY_MAX_DEPTH

namespace java {
	namespace io {
		class ObjectInputFilter;
		class ObjectInputFilter$FilterInfo;
		class ObjectInputFilter$Status;
	}
}
namespace java {
	namespace net {
		class URL;
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
			class ObjID;
			class RMIClientSocketFactory;
			class RMIServerSocketFactory;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class Hashtable;
		class ResourceBundle;
	}
}
namespace sun {
	namespace rmi {
		namespace server {
			class UnicastServerRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace registry {

class $import RegistryImpl : public ::java::rmi::server::RemoteServer, public ::java::rmi::registry::Registry {
	$class(RegistryImpl, 0, ::java::rmi::server::RemoteServer, ::java::rmi::registry::Registry)
public:
	RegistryImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf);
	void init$(int32_t port, ::java::rmi::server::RMIClientSocketFactory* csf, ::java::rmi::server::RMIServerSocketFactory* ssf, ::java::io::ObjectInputFilter* serialFilter);
	void init$(int32_t port);
	virtual void bind($String* name, ::java::rmi::Remote* obj) override;
	static void checkAccess($String* op);
	static ::sun::rmi::registry::RegistryImpl* createRegistry(int32_t regPort);
	static ::java::security::AccessControlContext* getAccessControlContext(int32_t port);
	static ::java::rmi::server::ObjID* getID();
	static $String* getTextResource($String* key);
	static ::java::io::ObjectInputFilter* initRegistryFilter();
	virtual $StringArray* list() override;
	virtual ::java::rmi::Remote* lookup($String* name) override;
	static void main($StringArray* args);
	static $Array<::java::net::URL>* pathToURLs($String* path);
	virtual void rebind($String* name, ::java::rmi::Remote* obj) override;
	static ::java::io::ObjectInputFilter$Status* registryFilter(::java::io::ObjectInputFilter$FilterInfo* filterInfo);
	void setup(::sun::rmi::server::UnicastServerRef* uref);
	virtual $String* toString() override;
	virtual void unbind($String* name) override;
	static const int64_t serialVersionUID = (int64_t)0x40C40E240AEB82C5;
	::java::util::Hashtable* bindings = nullptr;
	static ::java::util::Hashtable* allowedAccessCache;
	static ::sun::rmi::registry::RegistryImpl* registry;
	static ::java::rmi::server::ObjID* id;
	static ::java::util::ResourceBundle* resources;
	static $String* REGISTRY_FILTER_PROPNAME;
	static const int32_t REGISTRY_MAX_DEPTH = 20;
	static const int32_t REGISTRY_MAX_ARRAY_SIZE = 0x000F4240;
	static ::java::io::ObjectInputFilter* registryFilter$;
};

		} // registry
	} // rmi
} // sun

#pragma pop_macro("REGISTRY_FILTER_PROPNAME")
#pragma pop_macro("REGISTRY_MAX_ARRAY_SIZE")
#pragma pop_macro("REGISTRY_MAX_DEPTH")

#endif // _sun_rmi_registry_RegistryImpl_h_