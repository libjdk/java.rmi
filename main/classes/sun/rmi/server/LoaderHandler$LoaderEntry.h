#ifndef _sun_rmi_server_LoaderHandler$LoaderEntry_h_
#define _sun_rmi_server_LoaderHandler$LoaderEntry_h_
//$ class sun.rmi.server.LoaderHandler$LoaderEntry
//$ extends java.lang.ref.WeakReference

#include <java/lang/ref/WeakReference.h>

namespace sun {
	namespace rmi {
		namespace server {
			class LoaderHandler$Loader;
			class LoaderHandler$LoaderKey;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace server {

class LoaderHandler$LoaderEntry : public ::java::lang::ref::WeakReference {
	$class(LoaderHandler$LoaderEntry, $NO_CLASS_INIT, ::java::lang::ref::WeakReference)
public:
	LoaderHandler$LoaderEntry();
	void init$(::sun::rmi::server::LoaderHandler$LoaderKey* key, ::sun::rmi::server::LoaderHandler$Loader* loader);
	::sun::rmi::server::LoaderHandler$LoaderKey* key = nullptr;
	bool removed = false;
};

		} // server
	} // rmi
} // sun

#endif // _sun_rmi_server_LoaderHandler$LoaderEntry_h_