#include <sun/rmi/server/LoaderHandler$LoaderEntry.h>

#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/WeakReference.h>
#include <sun/rmi/server/LoaderHandler$Loader.h>
#include <sun/rmi/server/LoaderHandler$LoaderKey.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $WeakReference = ::java::lang::ref::WeakReference;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;
using $LoaderHandler$Loader = ::sun::rmi::server::LoaderHandler$Loader;
using $LoaderHandler$LoaderKey = ::sun::rmi::server::LoaderHandler$LoaderKey;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _LoaderHandler$LoaderEntry_FieldInfo_[] = {
	{"key", "Lsun/rmi/server/LoaderHandler$LoaderKey;", nullptr, $PUBLIC, $field(LoaderHandler$LoaderEntry, key)},
	{"removed", "Z", nullptr, $PUBLIC, $field(LoaderHandler$LoaderEntry, removed)},
	{}
};

$MethodInfo _LoaderHandler$LoaderEntry_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/server/LoaderHandler$LoaderKey;Lsun/rmi/server/LoaderHandler$Loader;)V", nullptr, $PUBLIC, $method(static_cast<void(LoaderHandler$LoaderEntry::*)($LoaderHandler$LoaderKey*,$LoaderHandler$Loader*)>(&LoaderHandler$LoaderEntry::init$))},
	{}
};

$InnerClassInfo _LoaderHandler$LoaderEntry_InnerClassesInfo_[] = {
	{"sun.rmi.server.LoaderHandler$LoaderEntry", "sun.rmi.server.LoaderHandler", "LoaderEntry", $PRIVATE | $STATIC},
	{"sun.rmi.server.LoaderHandler$Loader", "sun.rmi.server.LoaderHandler", "Loader", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LoaderHandler$LoaderEntry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.LoaderHandler$LoaderEntry",
	"java.lang.ref.WeakReference",
	nullptr,
	_LoaderHandler$LoaderEntry_FieldInfo_,
	_LoaderHandler$LoaderEntry_MethodInfo_,
	"Ljava/lang/ref/WeakReference<Lsun/rmi/server/LoaderHandler$Loader;>;",
	nullptr,
	_LoaderHandler$LoaderEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.LoaderHandler"
};

$Object* allocate$LoaderHandler$LoaderEntry($Class* clazz) {
	return $of($alloc(LoaderHandler$LoaderEntry));
}

void LoaderHandler$LoaderEntry::init$($LoaderHandler$LoaderKey* key, $LoaderHandler$Loader* loader) {
	$init($LoaderHandler);
	$WeakReference::init$(loader, $LoaderHandler::refQueue);
	this->removed = false;
	$set(this, key, key);
}

LoaderHandler$LoaderEntry::LoaderHandler$LoaderEntry() {
}

$Class* LoaderHandler$LoaderEntry::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$LoaderEntry, name, initialize, &_LoaderHandler$LoaderEntry_ClassInfo_, allocate$LoaderHandler$LoaderEntry);
	return class$;
}

$Class* LoaderHandler$LoaderEntry::class$ = nullptr;

		} // server
	} // rmi
} // sun