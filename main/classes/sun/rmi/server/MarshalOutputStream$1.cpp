#include <sun/rmi/server/MarshalOutputStream$1.h>

#include <sun/rmi/server/MarshalOutputStream.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $MarshalOutputStream = ::sun::rmi::server::MarshalOutputStream;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _MarshalOutputStream$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/server/MarshalOutputStream;", nullptr, $FINAL | $SYNTHETIC, $field(MarshalOutputStream$1, this$0)},
	{}
};

$MethodInfo _MarshalOutputStream$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/server/MarshalOutputStream;)V", nullptr, 0, $method(static_cast<void(MarshalOutputStream$1::*)($MarshalOutputStream*)>(&MarshalOutputStream$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _MarshalOutputStream$1_EnclosingMethodInfo_ = {
	"sun.rmi.server.MarshalOutputStream",
	"<init>",
	"(Ljava/io/OutputStream;I)V"
};

$InnerClassInfo _MarshalOutputStream$1_InnerClassesInfo_[] = {
	{"sun.rmi.server.MarshalOutputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MarshalOutputStream$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.MarshalOutputStream$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_MarshalOutputStream$1_FieldInfo_,
	_MarshalOutputStream$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_MarshalOutputStream$1_EnclosingMethodInfo_,
	_MarshalOutputStream$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.MarshalOutputStream"
};

$Object* allocate$MarshalOutputStream$1($Class* clazz) {
	return $of($alloc(MarshalOutputStream$1));
}

void MarshalOutputStream$1::init$($MarshalOutputStream* this$0) {
	$set(this, this$0, this$0);
}

$Object* MarshalOutputStream$1::run() {
	$MarshalOutputStream::access$000(this->this$0, true);
	return $of(nullptr);
}

MarshalOutputStream$1::MarshalOutputStream$1() {
}

$Class* MarshalOutputStream$1::load$($String* name, bool initialize) {
	$loadClass(MarshalOutputStream$1, name, initialize, &_MarshalOutputStream$1_ClassInfo_, allocate$MarshalOutputStream$1);
	return class$;
}

$Class* MarshalOutputStream$1::class$ = nullptr;

		} // server
	} // rmi
} // sun