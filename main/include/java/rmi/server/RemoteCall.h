#ifndef _java_rmi_server_RemoteCall_h_
#define _java_rmi_server_RemoteCall_h_
//$ interface java.rmi.server.RemoteCall
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectOutput;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import RemoteCall : public ::java::lang::Object {
	$interface(RemoteCall, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void done() {}
	virtual void executeCall() {}
	virtual ::java::io::ObjectInput* getInputStream() {return nullptr;}
	virtual ::java::io::ObjectOutput* getOutputStream() {return nullptr;}
	virtual ::java::io::ObjectOutput* getResultStream(bool success) {return nullptr;}
	virtual void releaseInputStream() {}
	virtual void releaseOutputStream() {}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_RemoteCall_h_