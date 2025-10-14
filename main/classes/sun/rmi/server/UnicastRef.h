#ifndef _sun_rmi_server_UnicastRef_h_
#define _sun_rmi_server_UnicastRef_h_
//$ class sun.rmi.server.UnicastRef
//$ extends java.rmi.server.RemoteRef

#include <java/lang/Array.h>
#include <java/rmi/server/RemoteRef.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectOutput;
	}
}
namespace java {
	namespace lang {
		class Boolean;
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
			class LiveRef;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $export UnicastRef : public ::java::rmi::server::RemoteRef {
	$class(UnicastRef, 0, ::java::rmi::server::RemoteRef)
public:
	UnicastRef();
	void init$();
	void init$(::sun::rmi::transport::LiveRef* liveRef);
	virtual void done(::java::rmi::server::RemoteCall* call) override;
	void free(::java::rmi::server::RemoteCall* call, bool reuse);
	virtual ::sun::rmi::transport::LiveRef* getLiveRef();
	virtual $String* getRefClass(::java::io::ObjectOutput* out) override;
	virtual $Object* invoke(::java::rmi::Remote* obj, ::java::lang::reflect::Method* method, $ObjectArray* params, int64_t opnum) override;
	virtual void invoke(::java::rmi::server::RemoteCall* call) override;
	static ::java::lang::Boolean* lambda$static$0();
	virtual void logClientCall(Object$* obj, Object$* method);
	virtual void marshalCustomCallData(::java::io::ObjectOutput* out);
	static void marshalValue($Class* type, Object$* value, ::java::io::ObjectOutput* out);
	virtual ::java::rmi::server::RemoteCall* newCall(::java::rmi::server::RemoteObject* obj, $Array<::java::rmi::server::Operation>* ops, int32_t opnum, int64_t hash) override;
	virtual void readExternal(::java::io::ObjectInput* in) override;
	virtual bool remoteEquals(::java::rmi::server::RemoteRef* sub) override;
	virtual int32_t remoteHashCode() override;
	virtual $String* remoteToString() override;
	static $Object* unmarshalValue($Class* type, ::java::io::ObjectInput* in);
	virtual void writeExternal(::java::io::ObjectOutput* out) override;
	static ::sun::rmi::runtime::Log* clientRefLog;
	static ::sun::rmi::runtime::Log* clientCallLog;
	static const int64_t serialVersionUID = (int64_t)0x729BA1F19D8F4E02;
	::sun::rmi::transport::LiveRef* ref = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_UnicastRef_h_