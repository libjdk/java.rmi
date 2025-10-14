#ifndef _sun_rmi_transport_GC$Daemon_h_
#define _sun_rmi_transport_GC$Daemon_h_
//$ class sun.rmi.transport.GC$Daemon
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace sun {
	namespace rmi {
		namespace transport {

class GC$Daemon : public ::java::lang::Runnable {
	$class(GC$Daemon, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	GC$Daemon();
	void init$();
	static void create();
	virtual void run() override;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_GC$Daemon_h_