#ifndef _sun_rmi_transport_DGCImpl$1_h_
#define _sun_rmi_transport_DGCImpl$1_h_
//$ class sun.rmi.transport.DGCImpl$1
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace sun {
	namespace rmi {
		namespace transport {
			class DGCImpl;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl$1 : public ::java::lang::Runnable {
	$class(DGCImpl$1, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	DGCImpl$1();
	void init$(::sun::rmi::transport::DGCImpl* this$0);
	virtual void run() override;
	::sun::rmi::transport::DGCImpl* this$0 = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCImpl$1_h_