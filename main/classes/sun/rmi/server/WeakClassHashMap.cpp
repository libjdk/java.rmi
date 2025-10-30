#include <sun/rmi/server/WeakClassHashMap.h>

#include <java/lang/ref/Reference.h>
#include <java/lang/ref/SoftReference.h>
#include <java/util/AbstractMap.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <sun/rmi/server/WeakClassHashMap$ValueCell.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $SoftReference = ::java::lang::ref::SoftReference;
using $AbstractMap = ::java::util::AbstractMap;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;
using $WeakClassHashMap$ValueCell = ::sun::rmi::server::WeakClassHashMap$ValueCell;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _WeakClassHashMap_FieldInfo_[] = {
	{"internalMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Class<*>;Lsun/rmi/server/WeakClassHashMap$ValueCell<TV;>;>;", $PRIVATE, $field(WeakClassHashMap, internalMap)},
	{}
};

$MethodInfo _WeakClassHashMap_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(WeakClassHashMap::*)()>(&WeakClassHashMap::init$))},
	{"computeValue", "(Ljava/lang/Class;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;)TV;", $PROTECTED | $ABSTRACT},
	{"get", "(Ljava/lang/Class;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;)TV;", $PUBLIC},
	{}
};

$InnerClassInfo _WeakClassHashMap_InnerClassesInfo_[] = {
	{"sun.rmi.server.WeakClassHashMap$ValueCell", "sun.rmi.server.WeakClassHashMap", "ValueCell", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WeakClassHashMap_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"sun.rmi.server.WeakClassHashMap",
	"java.lang.Object",
	nullptr,
	_WeakClassHashMap_FieldInfo_,
	_WeakClassHashMap_MethodInfo_,
	"<V:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_WeakClassHashMap_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.server.WeakClassHashMap$ValueCell"
};

$Object* allocate$WeakClassHashMap($Class* clazz) {
	return $of($alloc(WeakClassHashMap));
}

void WeakClassHashMap::init$() {
	$set(this, internalMap, $new($WeakHashMap));
}

$Object* WeakClassHashMap::get($Class* remoteClass) {
	$useLocalCurrentObjectStackCache();
	$var($WeakClassHashMap$ValueCell, valueCell, nullptr);
	$synchronized(this->internalMap) {
		$assign(valueCell, $cast($WeakClassHashMap$ValueCell, $nc(this->internalMap)->get(remoteClass)));
		if (valueCell == nullptr) {
			$assign(valueCell, $new($WeakClassHashMap$ValueCell));
			$nc(this->internalMap)->put(remoteClass, valueCell);
		}
	}
	$synchronized(valueCell) {
		$var($Object, value, nullptr);
		if ($nc(valueCell)->ref != nullptr) {
			$assign(value, $nc(valueCell->ref)->get());
		}
		if (value == nullptr) {
			$assign(value, computeValue(remoteClass));
			$set($nc(valueCell), ref, $new($SoftReference, value));
		}
		return $of(value);
	}
}

WeakClassHashMap::WeakClassHashMap() {
}

$Class* WeakClassHashMap::load$($String* name, bool initialize) {
	$loadClass(WeakClassHashMap, name, initialize, &_WeakClassHashMap_ClassInfo_, allocate$WeakClassHashMap);
	return class$;
}

$Class* WeakClassHashMap::class$ = nullptr;

		} // server
	} // rmi
} // sun