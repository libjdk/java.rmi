#include <sun/rmi/registry/RegistryImpl$2.h>

#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/server/ObjID.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ObjID = ::java::rmi::server::ObjID;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$2$$Lambda$registryFilter : public $ObjectInputFilter {
	$class(RegistryImpl$2$$Lambda$registryFilter, $NO_CLASS_INIT, $ObjectInputFilter)
public:
	void init$() {
	}
	virtual $ObjectInputFilter$Status* checkInput($ObjectInputFilter$FilterInfo* filterInfo) override {
		 return $RegistryImpl::registryFilter(filterInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RegistryImpl$2$$Lambda$registryFilter>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RegistryImpl$2$$Lambda$registryFilter::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl$2$$Lambda$registryFilter::*)()>(&RegistryImpl$2$$Lambda$registryFilter::init$))},
	{"checkInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RegistryImpl$2$$Lambda$registryFilter::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.registry.RegistryImpl$2$$Lambda$registryFilter",
	"java.lang.Object",
	"java.io.ObjectInputFilter",
	nullptr,
	methodInfos
};
$Class* RegistryImpl$2$$Lambda$registryFilter::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$2$$Lambda$registryFilter, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RegistryImpl$2$$Lambda$registryFilter::class$ = nullptr;

$FieldInfo _RegistryImpl$2_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/registry/RegistryImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$2, this$0)},
	{"val$port", "I", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$2, val$port)},
	{}
};

$MethodInfo _RegistryImpl$2_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/registry/RegistryImpl;I)V", "()V", 0, $method(static_cast<void(RegistryImpl$2::*)($RegistryImpl*,int32_t)>(&RegistryImpl$2::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{}
};

$EnclosingMethodInfo _RegistryImpl$2_EnclosingMethodInfo_ = {
	"sun.rmi.registry.RegistryImpl",
	"<init>",
	"(I)V"
};

$InnerClassInfo _RegistryImpl$2_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.registry.RegistryImpl$2",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RegistryImpl$2_FieldInfo_,
	_RegistryImpl$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Void;>;",
	&_RegistryImpl$2_EnclosingMethodInfo_,
	_RegistryImpl$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl"
};

$Object* allocate$RegistryImpl$2($Class* clazz) {
	return $of($alloc(RegistryImpl$2));
}

void RegistryImpl$2::init$($RegistryImpl* this$0, int32_t val$port) {
	$set(this, this$0, this$0);
	this->val$port = val$port;
}

$Object* RegistryImpl$2::run() {
	$useLocalCurrentObjectStackCache();
	$init($RegistryImpl);
	$var($LiveRef, lref, $new($LiveRef, $RegistryImpl::id, this->val$port));
	this->this$0->setup($$new($UnicastServerRef, lref, static_cast<$ObjectInputFilter*>($$new(RegistryImpl$2$$Lambda$registryFilter))));
	return $of(nullptr);
}

RegistryImpl$2::RegistryImpl$2() {
}

$Class* RegistryImpl$2::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RegistryImpl$2$$Lambda$registryFilter::classInfo$.name)) {
			return RegistryImpl$2$$Lambda$registryFilter::load$(name, initialize);
		}
	}
	$loadClass(RegistryImpl$2, name, initialize, &_RegistryImpl$2_ClassInfo_, allocate$RegistryImpl$2);
	return class$;
}

$Class* RegistryImpl$2::class$ = nullptr;

		} // registry
	} // rmi
} // sun