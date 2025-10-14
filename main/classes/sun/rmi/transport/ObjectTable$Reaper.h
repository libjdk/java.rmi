#ifndef _sun_rmi_transport_ObjectTable$Reaper_h_
#define _sun_rmi_transport_ObjectTable$Reaper_h_
//$ class sun.rmi.transport.ObjectTable$Reaper
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace sun {
	namespace rmi {
		namespace transport {

class ObjectTable$Reaper : public ::java::lang::Runnable {
	$class(ObjectTable$Reaper, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	ObjectTable$Reaper();
	void init$();
	virtual void run() override;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_ObjectTable$Reaper_h_