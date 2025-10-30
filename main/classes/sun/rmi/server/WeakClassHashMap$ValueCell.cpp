#include <sun/rmi/server/WeakClassHashMap$ValueCell.h>

#include <java/lang/ref/Reference.h>
#include <sun/rmi/server/WeakClassHashMap.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $WeakClassHashMap = ::sun::rmi::server::WeakClassHashMap;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _WeakClassHashMap$ValueCell_FieldInfo_[] = {
	{"ref", "Ljava/lang/ref/Reference;", "Ljava/lang/ref/Reference<TT;>;", 0, $field(WeakClassHashMap$ValueCell, ref)},
	{}
};

$MethodInfo _WeakClassHashMap$ValueCell_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(WeakClassHashMap$ValueCell::*)()>(&WeakClassHashMap$ValueCell::init$))},
	{}
};

$InnerClassInfo _WeakClassHashMap$ValueCell_InnerClassesInfo_[] = {
	{"sun.rmi.server.WeakClassHashMap$ValueCell", "sun.rmi.server.WeakClassHashMap", "ValueCell", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _WeakClassHashMap$ValueCell_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.WeakClassHashMap$ValueCell",
	"java.lang.Object",
	nullptr,
	_WeakClassHashMap$ValueCell_FieldInfo_,
	_WeakClassHashMap$ValueCell_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_WeakClassHashMap$ValueCell_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.WeakClassHashMap"
};

$Object* allocate$WeakClassHashMap$ValueCell($Class* clazz) {
	return $of($alloc(WeakClassHashMap$ValueCell));
}

void WeakClassHashMap$ValueCell::init$() {
	$set(this, ref, nullptr);
}

WeakClassHashMap$ValueCell::WeakClassHashMap$ValueCell() {
}

$Class* WeakClassHashMap$ValueCell::load$($String* name, bool initialize) {
	$loadClass(WeakClassHashMap$ValueCell, name, initialize, &_WeakClassHashMap$ValueCell_ClassInfo_, allocate$WeakClassHashMap$ValueCell);
	return class$;
}

$Class* WeakClassHashMap$ValueCell::class$ = nullptr;

		} // server
	} // rmi
} // sun