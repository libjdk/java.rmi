#ifndef _java_rmi_MarshalledObject$MarshalledObjectInputStream_h_
#define _java_rmi_MarshalledObject$MarshalledObjectInputStream_h_
//$ class java.rmi.MarshalledObject$MarshalledObjectInputStream
//$ extends sun.rmi.server.MarshalInputStream

#include <sun/rmi/server/MarshalInputStream.h>

namespace java {
	namespace io {
		class InputStream;
		class ObjectInputFilter;
		class ObjectInputStream;
	}
}
namespace java {
	namespace lang {
		class Void;
	}
}

namespace java {
	namespace rmi {

class MarshalledObject$MarshalledObjectInputStream : public ::sun::rmi::server::MarshalInputStream {
	$class(MarshalledObject$MarshalledObjectInputStream, $NO_CLASS_INIT, ::sun::rmi::server::MarshalInputStream)
public:
	MarshalledObject$MarshalledObjectInputStream();
	void init$(::java::io::InputStream* objIn, ::java::io::InputStream* locIn, ::java::io::ObjectInputFilter* filter);
	::java::lang::Void* lambda$new$0(::java::io::ObjectInputFilter* filter);
	using ::sun::rmi::server::MarshalInputStream::read;
	virtual $Object* readLocation() override;
	::java::io::ObjectInputStream* locIn = nullptr;
};

	} // rmi
} // java

#endif // _java_rmi_MarshalledObject$MarshalledObjectInputStream_h_