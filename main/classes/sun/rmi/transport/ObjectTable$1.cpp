#include <sun/rmi/transport/ObjectTable$1.h>

#include <sun/rmi/transport/ObjectTable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _ObjectTable$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(ObjectTable$1::*)()>(&ObjectTable$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _ObjectTable$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.ObjectTable",
	"decrementKeepAliveCount",
	"()V"
};

$InnerClassInfo _ObjectTable$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.ObjectTable$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ObjectTable$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.ObjectTable$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_ObjectTable$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_ObjectTable$1_EnclosingMethodInfo_,
	_ObjectTable$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.ObjectTable"
};

$Object* allocate$ObjectTable$1($Class* clazz) {
	return $of($alloc(ObjectTable$1));
}

void ObjectTable$1::init$() {
}

$Object* ObjectTable$1::run() {
	$init($ObjectTable);
	$nc($ObjectTable::reaper)->interrupt();
	return $of(nullptr);
}

ObjectTable$1::ObjectTable$1() {
}

$Class* ObjectTable$1::load$($String* name, bool initialize) {
	$loadClass(ObjectTable$1, name, initialize, &_ObjectTable$1_ClassInfo_, allocate$ObjectTable$1);
	return class$;
}

$Class* ObjectTable$1::class$ = nullptr;

		} // transport
	} // rmi
} // sun