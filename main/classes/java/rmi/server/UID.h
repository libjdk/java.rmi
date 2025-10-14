#ifndef _java_rmi_server_UID_h_
#define _java_rmi_server_UID_h_
//$ class java.rmi.server.UID
//$ extends java.io.Serializable

#include <java/io/Serializable.h>

#pragma push_macro("UID")
#undef UID

namespace java {
	namespace io {
		class DataInput;
		class DataOutput;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export UID : public ::java::io::Serializable {
	$class(UID, 0, ::java::io::Serializable)
public:
	UID();
	void init$();
	void init$(int16_t num);
	void init$(int32_t unique, int64_t time, int16_t count);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	static ::java::rmi::server::UID* read(::java::io::DataInput* in);
	virtual $String* toString() override;
	void write(::java::io::DataOutput* out);
	static int32_t hostUnique;
	static bool hostUniqueSet;
	static $Object* lock;
	static int64_t lastTime;
	static int16_t lastCount;
	static const int64_t serialVersionUID = (int64_t)0x0F12700DBF364F12;
	int32_t unique = 0;
	int64_t time = 0;
	int16_t count = 0;
};

		} // server
	} // rmi
} // java

#pragma pop_macro("UID")

#endif // _java_rmi_server_UID_h_