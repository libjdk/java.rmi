#ifndef _sun_rmi_server_LoaderHandler$LoaderKey_h_
#define _sun_rmi_server_LoaderHandler$LoaderKey_h_
//$ class sun.rmi.server.LoaderHandler$LoaderKey
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace java {
	namespace net {
		class URL;
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class LoaderHandler$LoaderKey : public ::java::lang::Object {
	$class(LoaderHandler$LoaderKey, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LoaderHandler$LoaderKey();
	void init$($Array<::java::net::URL>* urls, ::java::lang::ClassLoader* parent);
	virtual bool equals(Object$* obj) override;
	virtual int32_t hashCode() override;
	$Array<::java::net::URL>* urls = nullptr;
	::java::lang::ClassLoader* parent = nullptr;
	int32_t hashValue = 0;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_LoaderHandler$LoaderKey_h_