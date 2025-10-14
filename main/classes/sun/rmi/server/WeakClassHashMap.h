#ifndef _sun_rmi_server_WeakClassHashMap_h_
#define _sun_rmi_server_WeakClassHashMap_h_
//$ class sun.rmi.server.WeakClassHashMap
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class Map;
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class $export WeakClassHashMap : public ::java::lang::Object {
	$class(WeakClassHashMap, $NO_CLASS_INIT, ::java::lang::Object)
public:
	WeakClassHashMap();
	void init$();
	virtual $Object* computeValue($Class* remoteClass) {return nullptr;}
	virtual $Object* get($Class* remoteClass);
	::java::util::Map* internalMap = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_WeakClassHashMap_h_