#ifndef _sun_rmi_transport_SequenceEntry_h_
#define _sun_rmi_transport_SequenceEntry_h_
//$ class sun.rmi.transport.SequenceEntry
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace sun {
	namespace rmi {
		namespace transport {

class SequenceEntry : public ::java::lang::Object {
	$class(SequenceEntry, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SequenceEntry();
	void init$(int64_t sequenceNum);
	virtual void retain(int64_t sequenceNum);
	virtual void update(int64_t sequenceNum);
	int64_t sequenceNum = 0;
	bool keep = false;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_SequenceEntry_h_