#include <sun/rmi/transport/ObjectEndpoint.h>

#include <java/lang/AssertionError.h>
#include <java/rmi/server/ObjID.h>
#include <sun/rmi/transport/Transport.h>
#include <jcpp.h>

#undef DGC_ID

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ObjID = ::java::rmi::server::ObjID;
using $Transport = ::sun::rmi::transport::Transport;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _ObjectEndpoint_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ObjectEndpoint, $assertionsDisabled)},
	{"id", "Ljava/rmi/server/ObjID;", nullptr, $PRIVATE | $FINAL, $field(ObjectEndpoint, id)},
	{"transport", "Lsun/rmi/transport/Transport;", nullptr, $PRIVATE | $FINAL, $field(ObjectEndpoint, transport)},
	{}
};

$MethodInfo _ObjectEndpoint_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/server/ObjID;Lsun/rmi/transport/Transport;)V", nullptr, 0, $method(static_cast<void(ObjectEndpoint::*)($ObjID*,$Transport*)>(&ObjectEndpoint::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ObjectEndpoint_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.ObjectEndpoint",
	"java.lang.Object",
	nullptr,
	_ObjectEndpoint_FieldInfo_,
	_ObjectEndpoint_MethodInfo_
};

$Object* allocate$ObjectEndpoint($Class* clazz) {
	return $of($alloc(ObjectEndpoint));
}

bool ObjectEndpoint::$assertionsDisabled = false;

void ObjectEndpoint::init$($ObjID* id, $Transport* transport) {
	if (id == nullptr) {
		$throwNew($NullPointerException);
	}
	if (!ObjectEndpoint::$assertionsDisabled && !(transport != nullptr || $nc(id)->equals($$new($ObjID, $ObjID::DGC_ID)))) {
		$throwNew($AssertionError);
	}
	$set(this, id, id);
	$set(this, transport, transport);
}

bool ObjectEndpoint::equals(Object$* obj) {
	if ($instanceOf(ObjectEndpoint, obj)) {
		$var(ObjectEndpoint, oe, $cast(ObjectEndpoint, obj));
		return $nc(this->id)->equals($nc(oe)->id) && this->transport == $nc(oe)->transport;
	} else {
		return false;
	}
}

int32_t ObjectEndpoint::hashCode() {
	int32_t var$0 = $nc(this->id)->hashCode();
	return var$0 ^ (this->transport != nullptr ? $nc($of(this->transport))->hashCode() : 0);
}

$String* ObjectEndpoint::toString() {
	return $nc(this->id)->toString();
}

void clinit$ObjectEndpoint($Class* class$) {
	ObjectEndpoint::$assertionsDisabled = !ObjectEndpoint::class$->desiredAssertionStatus();
}

ObjectEndpoint::ObjectEndpoint() {
}

$Class* ObjectEndpoint::load$($String* name, bool initialize) {
	$loadClass(ObjectEndpoint, name, initialize, &_ObjectEndpoint_ClassInfo_, clinit$ObjectEndpoint, allocate$ObjectEndpoint);
	return class$;
}

$Class* ObjectEndpoint::class$ = nullptr;

		} // transport
	} // rmi
} // sun