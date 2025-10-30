#include <java/rmi/dgc/Lease.h>

#include <java/rmi/dgc/VMID.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $VMID = ::java::rmi::dgc::VMID;

namespace java {
	namespace rmi {
		namespace dgc {

$FieldInfo _Lease_FieldInfo_[] = {
	{"vmid", "Ljava/rmi/dgc/VMID;", nullptr, $PRIVATE, $field(Lease, vmid)},
	{"value", "J", nullptr, $PRIVATE, $field(Lease, value)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Lease, serialVersionUID)},
	{}
};

$MethodInfo _Lease_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/dgc/VMID;J)V", nullptr, $PUBLIC, $method(static_cast<void(Lease::*)($VMID*,int64_t)>(&Lease::init$))},
	{"getVMID", "()Ljava/rmi/dgc/VMID;", nullptr, $PUBLIC, $method(static_cast<$VMID*(Lease::*)()>(&Lease::getVMID))},
	{"getValue", "()J", nullptr, $PUBLIC, $method(static_cast<int64_t(Lease::*)()>(&Lease::getValue))},
	{}
};

$ClassInfo _Lease_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.dgc.Lease",
	"java.lang.Object",
	"java.io.Serializable",
	_Lease_FieldInfo_,
	_Lease_MethodInfo_
};

$Object* allocate$Lease($Class* clazz) {
	return $of($alloc(Lease));
}

void Lease::init$($VMID* id, int64_t duration) {
	$set(this, vmid, id);
	this->value = duration;
}

$VMID* Lease::getVMID() {
	return this->vmid;
}

int64_t Lease::getValue() {
	return this->value;
}

Lease::Lease() {
}

$Class* Lease::load$($String* name, bool initialize) {
	$loadClass(Lease, name, initialize, &_Lease_ClassInfo_, allocate$Lease);
	return class$;
}

$Class* Lease::class$ = nullptr;

		} // dgc
	} // rmi
} // java