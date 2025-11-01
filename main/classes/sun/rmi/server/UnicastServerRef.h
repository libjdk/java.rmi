#ifndef _sun_rmi_server_UnicastServerRef_h_
#define _sun_rmi_server_UnicastServerRef_h_
//$ class sun.rmi.server.UnicastServerRef
//$ extends sun.rmi.server.UnicastRef
//$ implements java.rmi.server.ServerRef,sun.rmi.server.Dispatcher

#include <java/rmi/server/ServerRef.h>
#include <sun/rmi/server/Dispatcher.h>
#include <sun/rmi/server/UnicastRef.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectInputFilter;
		class ObjectInputStream;
		class ObjectOutput;
	}
}
namespace java {
	namespace lang {
		class Boolean;
		class Throwable;
		class Void;
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
			class RemoteCall;
			class RemoteRef;
			class RemoteStub;
			class Skeleton;
		}
	}
}
namespace java {
	namespace util {
		class Map;
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
		namespace server {
			class WeakClassHashMap;
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

class $export UnicastServerRef : public ::sun::rmi::server::UnicastRef, public ::java::rmi::server::ServerRef, public ::sun::rmi::server::Dispatcher {
	$class(UnicastServerRef, 0, ::sun::rmi::server::UnicastRef, ::java::rmi::server::ServerRef, ::sun::rmi::server::Dispatcher)
public:
	UnicastServerRef();
	virtual $Object* clone() override;
	virtual void done(::java::rmi::server::RemoteCall* call) override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	virtual $Object* invoke(::java::rmi::Remote* obj, ::java::lang::reflect::Method* method, $ObjectArray* params, int64_t opnum) override;
	virtual void invoke(::java::rmi::server::RemoteCall* call) override;
	void init$();
	void init$(::sun::rmi::transport::LiveRef* ref);
	void init$(::sun::rmi::transport::LiveRef* ref, ::java::io::ObjectInputFilter* filter);
	void init$(int32_t port);
	void init$(bool forceStubUse);
	static void clearStackTraces($Throwable* t);
	virtual void dispatch(::java::rmi::Remote* obj, ::java::rmi::server::RemoteCall* call) override;
	virtual ::java::rmi::server::RemoteStub* exportObject(::java::rmi::Remote* impl, Object$* data) override;
	virtual ::java::rmi::Remote* exportObject(::java::rmi::Remote* impl, Object$* data, bool permanent);
	virtual $String* getClientHost() override;
	virtual ::java::rmi::server::RemoteRef* getClientRef();
	virtual $String* getRefClass(::java::io::ObjectOutput* out) override;
	static ::java::lang::Boolean* lambda$static$0();
	static ::java::lang::Boolean* lambda$static$1();
	static ::java::lang::Boolean* lambda$static$2();
	::java::lang::Void* lambda$unmarshalCustomCallData$3(::java::io::ObjectInputStream* ois);
	void logCall(::java::rmi::Remote* obj, Object$* method);
	void logCallException($Throwable* e);
	virtual ::java::rmi::server::RemoteCall* newCall(::java::rmi::server::RemoteObject* obj, $Array<::java::rmi::server::Operation>* ops, int32_t opnum, int64_t hash) override;
	void oldDispatch(::java::rmi::Remote* obj, ::java::rmi::server::RemoteCall* call, int32_t op);
	virtual void readExternal(::java::io::ObjectInput* in) override;
	virtual bool remoteEquals(::java::rmi::server::RemoteRef* sub) override;
	virtual int32_t remoteHashCode() override;
	virtual $String* remoteToString() override;
	virtual void setSkeleton(::java::rmi::Remote* impl);
	virtual $String* toString() override;
	virtual void unmarshalCustomCallData(::java::io::ObjectInput* in);
	virtual void writeExternal(::java::io::ObjectOutput* out) override;
	static bool logCalls;
	static ::sun::rmi::runtime::Log* callLog;
	static const int64_t serialVersionUID = (int64_t)0x9985C838F3945334;
	static bool wantExceptionLog;
	bool forceStubUse = false;
	static bool suppressStackTraces;
	::java::rmi::server::Skeleton* skel = nullptr;
	::java::io::ObjectInputFilter* filter = nullptr;
	::java::util::Map* hashToMethod_Map = nullptr;
	static ::sun::rmi::server::WeakClassHashMap* hashToMethod_Maps;
	static ::java::util::Map* withoutSkeletons;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_UnicastServerRef_h_