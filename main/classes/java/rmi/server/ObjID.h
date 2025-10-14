#ifndef _java_rmi_server_ObjID_h_
#define _java_rmi_server_ObjID_h_
//$ class java.rmi.server.ObjID
//$ extends java.io.Serializable

#include <java/io/Serializable.h>

#pragma push_macro("ACTIVATOR_ID")
#undef ACTIVATOR_ID
#pragma push_macro("DGC_ID")
#undef DGC_ID
#pragma push_macro("REGISTRY_ID")
#undef REGISTRY_ID

namespace java {
	namespace io {
		class ObjectInput;
		class ObjectOutput;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class UID;
		}
	}
}
namespace java {
	namespace security {
		class SecureRandom;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export ObjID : public ::java::io::Serializable {
	$class(ObjID, 0, ::java::io::Serializable)
public:
	ObjID();
	void init$();
	void init$(int32_t objNum);
	void init$(int64_t objNum, ::java::rmi::server::UID* space);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	static $String* lambda$useRandomIDs$0();
	static ::java::rmi::server::ObjID* read(::java::io::ObjectInput* in);
	virtual $String* toString() override;
	static bool useRandomIDs();
	void write(::java::io::ObjectOutput* out);
	static const int32_t REGISTRY_ID = 0;
	static const int32_t ACTIVATOR_ID = 1;
	static const int32_t DGC_ID = 2;
	static const int64_t serialVersionUID = (int64_t)0xA75EFA128DDCE55C;
	static ::java::util::concurrent::atomic::AtomicLong* nextObjNum;
	static ::java::rmi::server::UID* mySpace;
	static ::java::security::SecureRandom* secureRandom;
	int64_t objNum = 0;
	::java::rmi::server::UID* space = nullptr;
};

		} // server
	} // rmi
} // java

#pragma pop_macro("ACTIVATOR_ID")
#pragma pop_macro("DGC_ID")
#pragma pop_macro("REGISTRY_ID")

#endif // _java_rmi_server_ObjID_h_