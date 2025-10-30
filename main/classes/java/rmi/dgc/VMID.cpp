#include <java/rmi/dgc/VMID.h>

#include <java/rmi/server/UID.h>
#include <java/security/SecureRandom.h>
#include <jcpp.h>

#undef VMID

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $UID = ::java::rmi::server::UID;
using $SecureRandom = ::java::security::SecureRandom;

namespace java {
	namespace rmi {
		namespace dgc {

$CompoundAttribute _VMID_MethodAnnotations_isUnique3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _VMID_FieldInfo_[] = {
	{"randomBytes", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(VMID, randomBytes)},
	{"addr", "[B", nullptr, $PRIVATE, $field(VMID, addr)},
	{"uid", "Ljava/rmi/server/UID;", nullptr, $PRIVATE, $field(VMID, uid)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(VMID, serialVersionUID)},
	{}
};

$MethodInfo _VMID_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(VMID::*)()>(&VMID::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isUnique", "()Z", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $method(static_cast<bool(*)()>(&VMID::isUnique)), nullptr, nullptr, _VMID_MethodAnnotations_isUnique3},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _VMID_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.dgc.VMID",
	"java.lang.Object",
	"java.io.Serializable",
	_VMID_FieldInfo_,
	_VMID_MethodInfo_
};

$Object* allocate$VMID($Class* clazz) {
	return $of($alloc(VMID));
}

$bytes* VMID::randomBytes = nullptr;

void VMID::init$() {
	$set(this, addr, VMID::randomBytes);
	$set(this, uid, $new($UID));
}

bool VMID::isUnique() {
	$init(VMID);
	return true;
}

int32_t VMID::hashCode() {
	return $nc(this->uid)->hashCode();
}

bool VMID::equals(Object$* obj) {
	if ($instanceOf(VMID, obj)) {
		$var(VMID, vmid, $cast(VMID, obj));
		if (!$nc(this->uid)->equals($nc(vmid)->uid)) {
			return false;
		}
		if ((this->addr == nullptr) ^ ($nc(vmid)->addr == nullptr)) {
			return false;
		}
		if (this->addr != nullptr) {
			if ($nc(this->addr)->length != $nc($nc(vmid)->addr)->length) {
				return false;
			}
			for (int32_t i = 0; i < $nc(this->addr)->length; ++i) {
				if ($nc(this->addr)->get(i) != $nc($nc(vmid)->addr)->get(i)) {
					return false;
				}
			}
		}
		return true;
	} else {
		return false;
	}
}

$String* VMID::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	if (this->addr != nullptr) {
		for (int32_t i = 0; i < $nc(this->addr)->length; ++i) {
			int32_t x = (int32_t)($nc(this->addr)->get(i) & (uint32_t)255);
			sb->append($$str({(x < 16 ? "0"_s : ""_s), $($Integer::toString(x, 16))}));
		}
	}
	sb->append(u':');
	sb->append($($nc(this->uid)->toString()));
	return sb->toString();
}

void clinit$VMID($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$var($SecureRandom, secureRandom, $new($SecureRandom));
		$var($bytes, bytes, $new($bytes, 8));
		secureRandom->nextBytes(bytes);
		$assignStatic(VMID::randomBytes, bytes);
	}
}

VMID::VMID() {
}

$Class* VMID::load$($String* name, bool initialize) {
	$loadClass(VMID, name, initialize, &_VMID_ClassInfo_, clinit$VMID, allocate$VMID);
	return class$;
}

$Class* VMID::class$ = nullptr;

		} // dgc
	} // rmi
} // java