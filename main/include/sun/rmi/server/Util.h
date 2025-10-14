#ifndef _sun_rmi_server_Util_h_
#define _sun_rmi_server_Util_h_
//$ class sun.rmi.server.Util
//$ extends java.lang.Object

#include <java/lang/Array.h>

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
			class RemoteRef;
			class RemoteStub;
			class Skeleton;
		}
	}
}
namespace java {
	namespace util {
		class ArrayList;
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

class $import Util : public ::java::lang::Object {
	$class(Util, 0, ::java::lang::Object)
public:
	Util();
	void init$();
	static void checkMethod(::java::lang::reflect::Method* m);
	static int64_t computeMethodHash(::java::lang::reflect::Method* m);
	static ::java::rmi::Remote* createProxy($Class* implClass, ::java::rmi::server::RemoteRef* clientRef, bool forceStubUse);
	static ::java::rmi::server::Skeleton* createSkeleton(::java::rmi::Remote* object);
	static ::java::rmi::server::RemoteStub* createStub($Class* remoteClass, ::java::rmi::server::RemoteRef* ref);
	static $String* getMethodNameAndDescriptor(::java::lang::reflect::Method* m);
	static $Class* getRemoteClass($Class* cl);
	static $ClassArray* getRemoteInterfaces($Class* remoteClass);
	static void getRemoteInterfaces(::java::util::ArrayList* list, $Class* cl);
	static $String* getTypeDescriptor($Class* type);
	static $String* getUnqualifiedName($Class* c);
	static $String* lambda$static$0();
	static ::java::lang::Boolean* lambda$static$1();
	static bool stubClassExists($Class* remoteClass);
	static int32_t logLevel;
	static ::sun::rmi::runtime::Log* serverRefLog;
	static bool ignoreStubClasses;
	static ::java::util::Map* withoutStubs;
	static $ClassArray* stubConsParamTypes;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_Util_h_