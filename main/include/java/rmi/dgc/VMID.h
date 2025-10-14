#ifndef _java_rmi_dgc_VMID_h_
#define _java_rmi_dgc_VMID_h_
//$ class java.rmi.dgc.VMID
//$ extends java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>

#pragma push_macro("VMID")
#undef VMID

namespace java {
	namespace rmi {
		namespace server {
			class UID;
		}
	}
}

namespace java {
	namespace rmi {
		namespace dgc {

class $import VMID : public ::java::io::Serializable {
	$class(VMID, 0, ::java::io::Serializable)
public:
	VMID();
	void init$();
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	static bool isUnique();
	virtual $String* toString() override;
	static $bytes* randomBytes;
	$bytes* addr = nullptr;
	::java::rmi::server::UID* uid = nullptr;
	static const int64_t serialVersionUID = (int64_t)0xF8865BAFA4A56DB6;
};

		} // dgc
	} // rmi
} // java

#pragma pop_macro("VMID")

#endif // _java_rmi_dgc_VMID_h_