#ifndef _sun_rmi_server_WeakClassHashMap$ValueCell_h_
#define _sun_rmi_server_WeakClassHashMap$ValueCell_h_
//$ class sun.rmi.server.WeakClassHashMap$ValueCell
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		namespace ref {
			class Reference;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class WeakClassHashMap$ValueCell : public ::java::lang::Object {
	$class(WeakClassHashMap$ValueCell, $NO_CLASS_INIT, ::java::lang::Object)
public:
	WeakClassHashMap$ValueCell();
	void init$();
	::java::lang::ref::Reference* ref = nullptr;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_WeakClassHashMap$ValueCell_h_