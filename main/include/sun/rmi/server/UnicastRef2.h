#ifndef _sun_rmi_server_UnicastRef2_h_
#define _sun_rmi_server_UnicastRef2_h_
//$ class sun.rmi.server.UnicastRef2
//$ extends sun.rmi.server.UnicastRef

#include <sun/rmi/server/UnicastRef.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectOutput;
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

class $import UnicastRef2 : public ::sun::rmi::server::UnicastRef {
	$class(UnicastRef2, $NO_CLASS_INIT, ::sun::rmi::server::UnicastRef)
public:
	UnicastRef2();
	void init$();
	void init$(::sun::rmi::transport::LiveRef* liveRef);
	virtual $String* getRefClass(::java::io::ObjectOutput* out) override;
	virtual void readExternal(::java::io::ObjectInput* in) override;
	virtual void writeExternal(::java::io::ObjectOutput* out) override;
	static const int64_t serialVersionUID = (int64_t)0x1963D2AD3494976E;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_UnicastRef2_h_