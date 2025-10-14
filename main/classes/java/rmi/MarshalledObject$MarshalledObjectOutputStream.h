#ifndef _java_rmi_MarshalledObject$MarshalledObjectOutputStream_h_
#define _java_rmi_MarshalledObject$MarshalledObjectOutputStream_h_
//$ class java.rmi.MarshalledObject$MarshalledObjectOutputStream
//$ extends sun.rmi.server.MarshalOutputStream

#include <sun/rmi/server/MarshalOutputStream.h>

namespace java {
	namespace io {
		class ObjectOutputStream;
		class OutputStream;
	}
}

namespace java {
	namespace rmi {

class MarshalledObject$MarshalledObjectOutputStream : public ::sun::rmi::server::MarshalOutputStream {
	$class(MarshalledObject$MarshalledObjectOutputStream, $NO_CLASS_INIT, ::sun::rmi::server::MarshalOutputStream)
public:
	MarshalledObject$MarshalledObjectOutputStream();
	void init$(::java::io::OutputStream* objOut, ::java::io::OutputStream* locOut);
	virtual void flush() override;
	virtual bool hadAnnotations();
	virtual void writeLocation($String* loc) override;
	::java::io::ObjectOutputStream* locOut = nullptr;
	bool hadAnnotations$ = false;
};

	} // rmi
} // java

#endif // _java_rmi_MarshalledObject$MarshalledObjectOutputStream_h_