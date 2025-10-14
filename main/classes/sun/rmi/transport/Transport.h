#ifndef _sun_rmi_transport_Transport_h_
#define _sun_rmi_transport_Transport_h_
//$ class sun.rmi.transport.Transport
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("SETCCL_ACC")
#undef SETCCL_ACC

namespace java {
	namespace lang {
		class ClassLoader;
		class ThreadLocal;
		class Void;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class ObjID;
			class RemoteCall;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log;
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

class $export Transport : public ::java::lang::Object {
	$class(Transport, 0, ::java::lang::Object)
public:
	Transport();
	void init$();
	virtual void checkAcceptPermission(::java::security::AccessControlContext* acc) {}
	static ::sun::rmi::transport::Transport* currentTransport();
	virtual void exportObject(::sun::rmi::transport::Target* target);
	virtual void free(::sun::rmi::transport::Endpoint* ep) {}
	virtual ::sun::rmi::transport::Channel* getChannel(::sun::rmi::transport::Endpoint* ep) {return nullptr;}
	static $String* getLogLevel();
	static $String* lambda$getLogLevel$0();
	static ::java::lang::Void* lambda$setContextClassLoader$1(::java::lang::ClassLoader* ccl);
	virtual bool serviceCall(::java::rmi::server::RemoteCall* call);
	static void setContextClassLoader(::java::lang::ClassLoader* ccl);
	virtual void targetUnexported();
	static int32_t logLevel;
	static ::sun::rmi::runtime::Log* transportLog;
	static ::java::lang::ThreadLocal* currentTransport$;
	static ::java::rmi::server::ObjID* dgcID;
	static ::java::security::AccessControlContext* SETCCL_ACC;
};

		} // transport
	} // rmi
} // sun

#pragma pop_macro("SETCCL_ACC")

#endif // _sun_rmi_transport_Transport_h_