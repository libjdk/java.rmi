#ifndef _java_rmi_dgc_Lease_h_
#define _java_rmi_dgc_Lease_h_
//$ class java.rmi.dgc.Lease
//$ extends java.io.Serializable

#include <java/io/Serializable.h>

namespace java {
	namespace rmi {
		namespace dgc {
			class VMID;
		}
	}
}

namespace java {
	namespace rmi {
		namespace dgc {

class $import Lease : public ::java::io::Serializable {
	$class(Lease, $NO_CLASS_INIT, ::java::io::Serializable)
public:
	Lease();
	void init$(::java::rmi::dgc::VMID* id, int64_t duration);
	::java::rmi::dgc::VMID* getVMID();
	int64_t getValue();
	::java::rmi::dgc::VMID* vmid = nullptr;
	int64_t value = 0;
	static const int64_t serialVersionUID = (int64_t)0xB0B5E2660C4ADC34;
};

		} // dgc
	} // rmi
} // java

#endif // _java_rmi_dgc_Lease_h_