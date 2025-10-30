#include <sun/rmi/server/LoaderHandler$LoaderKey.h>

#include <java/lang/ClassLoader.h>
#include <java/net/URL.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <jcpp.h>

using $URLArray = $Array<::java::net::URL>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _LoaderHandler$LoaderKey_FieldInfo_[] = {
	{"urls", "[Ljava/net/URL;", nullptr, $PRIVATE, $field(LoaderHandler$LoaderKey, urls)},
	{"parent", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(LoaderHandler$LoaderKey, parent)},
	{"hashValue", "I", nullptr, $PRIVATE, $field(LoaderHandler$LoaderKey, hashValue)},
	{}
};

$MethodInfo _LoaderHandler$LoaderKey_MethodInfo_[] = {
	{"<init>", "([Ljava/net/URL;Ljava/lang/ClassLoader;)V", nullptr, $PUBLIC, $method(static_cast<void(LoaderHandler$LoaderKey::*)($URLArray*,$ClassLoader*)>(&LoaderHandler$LoaderKey::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LoaderHandler$LoaderKey_InnerClassesInfo_[] = {
	{"sun.rmi.server.LoaderHandler$LoaderKey", "sun.rmi.server.LoaderHandler", "LoaderKey", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LoaderHandler$LoaderKey_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.LoaderHandler$LoaderKey",
	"java.lang.Object",
	nullptr,
	_LoaderHandler$LoaderKey_FieldInfo_,
	_LoaderHandler$LoaderKey_MethodInfo_,
	nullptr,
	nullptr,
	_LoaderHandler$LoaderKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.LoaderHandler"
};

$Object* allocate$LoaderHandler$LoaderKey($Class* clazz) {
	return $of($alloc(LoaderHandler$LoaderKey));
}

void LoaderHandler$LoaderKey::init$($URLArray* urls, $ClassLoader* parent) {
	$set(this, urls, urls);
	$set(this, parent, parent);
	if (parent != nullptr) {
		this->hashValue = $of(parent)->hashCode();
	}
	for (int32_t i = 0; i < $nc(urls)->length; ++i) {
		this->hashValue ^= $nc(urls->get(i))->hashCode();
	}
}

int32_t LoaderHandler$LoaderKey::hashCode() {
	return this->hashValue;
}

bool LoaderHandler$LoaderKey::equals(Object$* obj) {
	if ($instanceOf(LoaderHandler$LoaderKey, obj)) {
		$var(LoaderHandler$LoaderKey, other, $cast(LoaderHandler$LoaderKey, obj));
		if (this->parent != $nc(other)->parent) {
			return false;
		}
		if (this->urls == $nc(other)->urls) {
			return true;
		}
		if ($nc(this->urls)->length != $nc($nc(other)->urls)->length) {
			return false;
		}
		for (int32_t i = 0; i < $nc(this->urls)->length; ++i) {
			if (!$nc($nc(this->urls)->get(i))->equals($nc($nc(other)->urls)->get(i))) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

LoaderHandler$LoaderKey::LoaderHandler$LoaderKey() {
}

$Class* LoaderHandler$LoaderKey::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$LoaderKey, name, initialize, &_LoaderHandler$LoaderKey_ClassInfo_, allocate$LoaderHandler$LoaderKey);
	return class$;
}

$Class* LoaderHandler$LoaderKey::class$ = nullptr;

		} // server
	} // rmi
} // sun