#ifndef _sun_rmi_transport_WeakRef_h_
#define _sun_rmi_transport_WeakRef_h_
//$ class sun.rmi.transport.WeakRef
//$ extends java.lang.ref.WeakReference

#include <java/lang/ref/WeakReference.h>

namespace java {
	namespace lang {
		namespace ref {
			class ReferenceQueue;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class WeakRef : public ::java::lang::ref::WeakReference {
	$class(WeakRef, $NO_CLASS_INIT, ::java::lang::ref::WeakReference)
public:
	WeakRef();
	void init$(Object$* obj);
	void init$(Object$* obj, ::java::lang::ref::ReferenceQueue* q);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	virtual void pin();
	void setHashValue(Object$* obj);
	virtual void unpin();
	int32_t hashValue = 0;
	$Object* strongRef = nullptr;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_WeakRef_h_