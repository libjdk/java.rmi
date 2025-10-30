#include <java/rmi/dgc/DGC.h>

#include <java/rmi/dgc/Lease.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ObjID.h>
#include <jcpp.h>

#undef DGC

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $Lease = ::java::rmi::dgc::Lease;
using $VMID = ::java::rmi::dgc::VMID;

namespace java {
	namespace rmi {
		namespace dgc {

$MethodInfo _DGC_MethodInfo_[] = {
	{"clean", "([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/VMID;Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{"dirty", "([Ljava/rmi/server/ObjID;JLjava/rmi/dgc/Lease;)Ljava/rmi/dgc/Lease;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{}
};

$ClassInfo _DGC_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.dgc.DGC",
	nullptr,
	"java.rmi.Remote",
	nullptr,
	_DGC_MethodInfo_
};

$Object* allocate$DGC($Class* clazz) {
	return $of($alloc(DGC));
}

$Class* DGC::load$($String* name, bool initialize) {
	$loadClass(DGC, name, initialize, &_DGC_ClassInfo_, allocate$DGC);
	return class$;
}

$Class* DGC::class$ = nullptr;

		} // dgc
	} // rmi
} // java