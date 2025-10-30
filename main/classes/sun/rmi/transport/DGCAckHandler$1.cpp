#include <sun/rmi/transport/DGCAckHandler$1.h>

#include <java/rmi/server/UID.h>
#include <java/util/Map.h>
#include <sun/rmi/transport/DGCAckHandler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $UID = ::java::rmi::server::UID;
using $Map = ::java::util::Map;
using $DGCAckHandler = ::sun::rmi::transport::DGCAckHandler;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCAckHandler$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/DGCAckHandler;", nullptr, $FINAL | $SYNTHETIC, $field(DGCAckHandler$1, this$0)},
	{}
};

$MethodInfo _DGCAckHandler$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/DGCAckHandler;)V", nullptr, 0, $method(static_cast<void(DGCAckHandler$1::*)($DGCAckHandler*)>(&DGCAckHandler$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _DGCAckHandler$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.DGCAckHandler",
	"startTimer",
	"()V"
};

$InnerClassInfo _DGCAckHandler$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCAckHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCAckHandler$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCAckHandler$1",
	"java.lang.Object",
	"java.lang.Runnable",
	_DGCAckHandler$1_FieldInfo_,
	_DGCAckHandler$1_MethodInfo_,
	nullptr,
	&_DGCAckHandler$1_EnclosingMethodInfo_,
	_DGCAckHandler$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCAckHandler"
};

$Object* allocate$DGCAckHandler$1($Class* clazz) {
	return $of($alloc(DGCAckHandler$1));
}

void DGCAckHandler$1::init$($DGCAckHandler* this$0) {
	$set(this, this$0, this$0);
}

void DGCAckHandler$1::run() {
	if (this->this$0->id != nullptr) {
		$init($DGCAckHandler);
		$nc($DGCAckHandler::idTable)->remove(this->this$0->id);
	}
	this->this$0->release();
}

DGCAckHandler$1::DGCAckHandler$1() {
}

$Class* DGCAckHandler$1::load$($String* name, bool initialize) {
	$loadClass(DGCAckHandler$1, name, initialize, &_DGCAckHandler$1_ClassInfo_, allocate$DGCAckHandler$1);
	return class$;
}

$Class* DGCAckHandler$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun