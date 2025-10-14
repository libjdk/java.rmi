#ifndef _sun_rmi_server_MarshalOutputStream_h_
#define _sun_rmi_server_MarshalOutputStream_h_
//$ class sun.rmi.server.MarshalOutputStream
//$ extends java.io.ObjectOutputStream

#include <java/io/ObjectOutputStream.h>

namespace java {
	namespace io {
		class OutputStream;
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $export MarshalOutputStream : public ::java::io::ObjectOutputStream {
	$class(MarshalOutputStream, $NO_CLASS_INIT, ::java::io::ObjectOutputStream)
public:
	MarshalOutputStream();
	void init$(::java::io::OutputStream* out);
	void init$(::java::io::OutputStream* out, int32_t protocolVersion);
	static bool access$000(::sun::rmi::server::MarshalOutputStream* x0, bool x1);
	virtual void annotateClass($Class* cl) override;
	virtual void annotateProxyClass($Class* cl) override;
	virtual $Object* replaceObject(Object$* obj) override;
	virtual void writeLocation($String* location);
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_MarshalOutputStream_h_