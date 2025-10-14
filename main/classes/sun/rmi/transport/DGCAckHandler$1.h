#ifndef _sun_rmi_transport_DGCAckHandler$1_h_
#define _sun_rmi_transport_DGCAckHandler$1_h_
//$ class sun.rmi.transport.DGCAckHandler$1
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace sun {
	namespace rmi {
		namespace transport {
			class DGCAckHandler;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCAckHandler$1 : public ::java::lang::Runnable {
	$class(DGCAckHandler$1, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	DGCAckHandler$1();
	void init$(::sun::rmi::transport::DGCAckHandler* this$0);
	virtual void run() override;
	::sun::rmi::transport::DGCAckHandler* this$0 = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCAckHandler$1_h_