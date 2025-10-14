#ifndef _sun_rmi_transport_tcp_TCPTransport$1_h_
#define _sun_rmi_transport_tcp_TCPTransport$1_h_
//$ class sun.rmi.transport.tcp.TCPTransport$1
//$ extends java.util.concurrent.ThreadFactory

#include <java/util/concurrent/ThreadFactory.h>

namespace java {
	namespace lang {
		class Runnable;
		class Thread;
	}
}

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPTransport$1 : public ::java::util::concurrent::ThreadFactory {
	$class(TCPTransport$1, $NO_CLASS_INIT, ::java::util::concurrent::ThreadFactory)
public:
	TCPTransport$1();
	void init$();
	virtual $Thread* newThread(::java::lang::Runnable* runnable) override;
};

			} // tcp
		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_tcp_TCPTransport$1_h_