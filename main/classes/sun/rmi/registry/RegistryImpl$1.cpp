#include <sun/rmi/registry/RegistryImpl$1.h>

#include <java/io/ObjectInputFilter.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/UnicastServerRef2.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ObjID = ::java::rmi::server::ObjID;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $UnicastServerRef2 = ::sun::rmi::server::UnicastServerRef2;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace registry {

$FieldInfo _RegistryImpl$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/registry/RegistryImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$1, this$0)},
	{"val$serialFilter", "Ljava/io/ObjectInputFilter;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$1, val$serialFilter)},
	{"val$ssf", "Ljava/rmi/server/RMIServerSocketFactory;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$1, val$ssf)},
	{"val$csf", "Ljava/rmi/server/RMIClientSocketFactory;", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$1, val$csf)},
	{"val$port", "I", nullptr, $FINAL | $SYNTHETIC, $field(RegistryImpl$1, val$port)},
	{}
};

$MethodInfo _RegistryImpl$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/registry/RegistryImpl;ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/io/ObjectInputFilter;)V", "()V", 0, $method(static_cast<void(RegistryImpl$1::*)($RegistryImpl*,int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*,$ObjectInputFilter*)>(&RegistryImpl$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{}
};

$EnclosingMethodInfo _RegistryImpl$1_EnclosingMethodInfo_ = {
	"sun.rmi.registry.RegistryImpl",
	"<init>",
	"(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/io/ObjectInputFilter;)V"
};

$InnerClassInfo _RegistryImpl$1_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.registry.RegistryImpl$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_RegistryImpl$1_FieldInfo_,
	_RegistryImpl$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljava/lang/Void;>;",
	&_RegistryImpl$1_EnclosingMethodInfo_,
	_RegistryImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl"
};

$Object* allocate$RegistryImpl$1($Class* clazz) {
	return $of($alloc(RegistryImpl$1));
}

void RegistryImpl$1::init$($RegistryImpl* this$0, int32_t val$port, $RMIClientSocketFactory* val$csf, $RMIServerSocketFactory* val$ssf, $ObjectInputFilter* val$serialFilter) {
	$set(this, this$0, this$0);
	this->val$port = val$port;
	$set(this, val$csf, val$csf);
	$set(this, val$ssf, val$ssf);
	$set(this, val$serialFilter, val$serialFilter);
}

$Object* RegistryImpl$1::run() {
	$useLocalCurrentObjectStackCache();
	$init($RegistryImpl);
	$var($LiveRef, lref, $new($LiveRef, $RegistryImpl::id, this->val$port, this->val$csf, this->val$ssf));
	this->this$0->setup($$new($UnicastServerRef2, lref, this->val$serialFilter));
	return $of(nullptr);
}

RegistryImpl$1::RegistryImpl$1() {
}

$Class* RegistryImpl$1::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$1, name, initialize, &_RegistryImpl$1_ClassInfo_, allocate$RegistryImpl$1);
	return class$;
}

$Class* RegistryImpl$1::class$ = nullptr;

		} // registry
	} // rmi
} // sun