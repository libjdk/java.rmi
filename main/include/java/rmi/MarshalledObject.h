#ifndef _java_rmi_MarshalledObject_h_
#define _java_rmi_MarshalledObject_h_
//$ class java.rmi.MarshalledObject
//$ extends java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>

namespace java {
	namespace io {
		class ObjectInputFilter;
		class ObjectInputStream;
	}
}

namespace java {
	namespace rmi {

class $import MarshalledObject : public ::java::io::Serializable {
	$class(MarshalledObject, $NO_CLASS_INIT, ::java::io::Serializable)
public:
	MarshalledObject();
	void init$(Object$* obj);
	virtual bool equals(Object$* obj) override;
	$Object* get();
	virtual int32_t hashCode() override;
	void readObject(::java::io::ObjectInputStream* stream);
	$bytes* objBytes = nullptr;
	$bytes* locBytes = nullptr;
	int32_t hash = 0;
	::java::io::ObjectInputFilter* objectInputFilter = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x7CBD1E97ED63FC3E;
};

	} // rmi
} // java

#endif // _java_rmi_MarshalledObject_h_