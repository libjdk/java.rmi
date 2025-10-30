#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps$1.h>

#include <java/lang/reflect/Method.h>
#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Method = ::java::lang::reflect::Method;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $UnicastServerRef$HashToMethod_Maps = ::sun::rmi::server::UnicastServerRef$HashToMethod_Maps;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _UnicastServerRef$HashToMethod_Maps$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/server/UnicastServerRef$HashToMethod_Maps;", nullptr, $FINAL | $SYNTHETIC, $field(UnicastServerRef$HashToMethod_Maps$1, this$0)},
	{"val$m", "Ljava/lang/reflect/Method;", nullptr, $FINAL | $SYNTHETIC, $field(UnicastServerRef$HashToMethod_Maps$1, val$m)},
	{}
};

$MethodInfo _UnicastServerRef$HashToMethod_Maps$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/server/UnicastServerRef$HashToMethod_Maps;Ljava/lang/reflect/Method;)V", "()V", 0, $method(static_cast<void(UnicastServerRef$HashToMethod_Maps$1::*)($UnicastServerRef$HashToMethod_Maps*,$Method*)>(&UnicastServerRef$HashToMethod_Maps$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _UnicastServerRef$HashToMethod_Maps$1_EnclosingMethodInfo_ = {
	"sun.rmi.server.UnicastServerRef$HashToMethod_Maps",
	"computeValue",
	"(Ljava/lang/Class;)Ljava/util/Map;"
};

$InnerClassInfo _UnicastServerRef$HashToMethod_Maps$1_InnerClassesInfo_[] = {
	{"sun.rmi.server.UnicastServerRef$HashToMethod_Maps", "sun.rmi.server.UnicastServerRef", "HashToMethod_Maps", $PRIVATE | $STATIC},
	{"sun.rmi.server.UnicastServerRef$HashToMethod_Maps$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _UnicastServerRef$HashToMethod_Maps$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.UnicastServerRef$HashToMethod_Maps$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_UnicastServerRef$HashToMethod_Maps$1_FieldInfo_,
	_UnicastServerRef$HashToMethod_Maps$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_UnicastServerRef$HashToMethod_Maps$1_EnclosingMethodInfo_,
	_UnicastServerRef$HashToMethod_Maps$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.UnicastServerRef"
};

$Object* allocate$UnicastServerRef$HashToMethod_Maps$1($Class* clazz) {
	return $of($alloc(UnicastServerRef$HashToMethod_Maps$1));
}

void UnicastServerRef$HashToMethod_Maps$1::init$($UnicastServerRef$HashToMethod_Maps* this$0, $Method* val$m) {
	$set(this, this$0, this$0);
	$set(this, val$m, val$m);
}

$Object* UnicastServerRef$HashToMethod_Maps$1::run() {
	$beforeCallerSensitive();
	$nc(this->val$m)->setAccessible(true);
	return $of(nullptr);
}

UnicastServerRef$HashToMethod_Maps$1::UnicastServerRef$HashToMethod_Maps$1() {
}

$Class* UnicastServerRef$HashToMethod_Maps$1::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef$HashToMethod_Maps$1, name, initialize, &_UnicastServerRef$HashToMethod_Maps$1_ClassInfo_, allocate$UnicastServerRef$HashToMethod_Maps$1);
	return class$;
}

$Class* UnicastServerRef$HashToMethod_Maps$1::class$ = nullptr;

		} // server
	} // rmi
} // sun