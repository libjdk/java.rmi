#ifndef _sun_rmi_transport_tcp_TCPChannel$1_h_
#define _sun_rmi_transport_tcp_TCPChannel$1_h_
//$ class sun.rmi.transport.tcp.TCPChannel$1
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {
				class TCPChannel;
			}
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPChannel$1 : public ::java::lang::Runnable {
	$class(TCPChannel$1, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	TCPChannel$1();
	void init$(::sun::rmi::transport::tcp::TCPChannel* this$0);
	virtual void run() override;
	::sun::rmi::transport::tcp::TCPChannel* this$0 = nullptr;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPChannel$1_h_