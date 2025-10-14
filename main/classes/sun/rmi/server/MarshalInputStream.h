#ifndef _sun_rmi_server_MarshalInputStream_h_
#define _sun_rmi_server_MarshalInputStream_h_
//$ class sun.rmi.server.MarshalInputStream
//$ extends java.io.ObjectInputStream

#include <java/io/ObjectInputStream.h>
#include <java/lang/Array.h>

namespace java {
	namespace io {
		class InputStream;
		class ObjectStreamClass;
	}
}
namespace java {
	namespace lang {
		class ClassLoader;
		class Runnable;
	}
}
namespace java {
	namespace security {
		class AccessControlException;
	}
}
namespace java {
	namespace util {
		class Map;
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $export MarshalInputStream : public ::java::io::ObjectInputStream {
	$class(MarshalInputStream, 0, ::java::io::ObjectInputStream)
public:
	MarshalInputStream();
	void init$(::java::io::InputStream* in);
	$Class* checkSunClass($String* className, ::java::security::AccessControlException* e);
	virtual void close() override;
	virtual void done();
	virtual ::java::lang::Runnable* getDoneCallback(Object$* key);
	static $String* lambda$static$0();
	static ::java::lang::ClassLoader* latestUserDefinedLoader();
	using ::java::io::ObjectInputStream::read;
	virtual $Object* readLocation();
	virtual $Class* resolveClass(::java::io::ObjectStreamClass* classDesc) override;
	virtual $Class* resolveProxyClass($StringArray* interfaces) override;
	virtual void setDoneCallback(Object$* key, ::java::lang::Runnable* callback);
	virtual void skipDefaultResolveClass();
	virtual void useCodebaseOnly();
	static bool useCodebaseOnlyProperty;
	static ::java::util::Map* permittedSunClasses;
	bool skipDefaultResolveClass$ = false;
	::java::util::Map* doneCallbacks = nullptr;
	bool useCodebaseOnly$ = false;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_MarshalInputStream_h_