#include <java/rmi/server/ObjID.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/server/UID.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/SecureRandom.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <jcpp.h>

#undef ACTIVATOR_ID
#undef DGC_ID
#undef REGISTRY_ID

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $UID = ::java::rmi::server::UID;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SecureRandom = ::java::security::SecureRandom;
using $Random = ::java::util::Random;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;

namespace java {
	namespace rmi {
		namespace server {

class ObjID$$Lambda$lambda$useRandomIDs$0 : public $PrivilegedAction {
	$class(ObjID$$Lambda$lambda$useRandomIDs$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(ObjID::lambda$useRandomIDs$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjID$$Lambda$lambda$useRandomIDs$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjID$$Lambda$lambda$useRandomIDs$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ObjID$$Lambda$lambda$useRandomIDs$0::*)()>(&ObjID$$Lambda$lambda$useRandomIDs$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ObjID$$Lambda$lambda$useRandomIDs$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.rmi.server.ObjID$$Lambda$lambda$useRandomIDs$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* ObjID$$Lambda$lambda$useRandomIDs$0::load$($String* name, bool initialize) {
	$loadClass(ObjID$$Lambda$lambda$useRandomIDs$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjID$$Lambda$lambda$useRandomIDs$0::class$ = nullptr;

$FieldInfo _ObjID_FieldInfo_[] = {
	{"REGISTRY_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ObjID, REGISTRY_ID)},
	{"ACTIVATOR_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ObjID, ACTIVATOR_ID)},
	{"DGC_ID", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ObjID, DGC_ID)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ObjID, serialVersionUID)},
	{"nextObjNum", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjID, nextObjNum)},
	{"mySpace", "Ljava/rmi/server/UID;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjID, mySpace)},
	{"secureRandom", "Ljava/security/SecureRandom;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjID, secureRandom)},
	{"objNum", "J", nullptr, $PRIVATE | $FINAL, $field(ObjID, objNum)},
	{"space", "Ljava/rmi/server/UID;", nullptr, $PRIVATE | $FINAL, $field(ObjID, space)},
	{}
};

$MethodInfo _ObjID_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ObjID::*)()>(&ObjID::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(ObjID::*)(int32_t)>(&ObjID::init$))},
	{"<init>", "(JLjava/rmi/server/UID;)V", nullptr, $PRIVATE, $method(static_cast<void(ObjID::*)(int64_t,$UID*)>(&ObjID::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"lambda$useRandomIDs$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&ObjID::lambda$useRandomIDs$0))},
	{"read", "(Ljava/io/ObjectInput;)Ljava/rmi/server/ObjID;", nullptr, $PUBLIC | $STATIC, $method(static_cast<ObjID*(*)($ObjectInput*)>(&ObjID::read)), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"useRandomIDs", "()Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)()>(&ObjID::useRandomIDs))},
	{"write", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, $method(static_cast<void(ObjID::*)($ObjectOutput*)>(&ObjID::write)), "java.io.IOException"},
	{}
};

$ClassInfo _ObjID_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.server.ObjID",
	"java.lang.Object",
	"java.io.Serializable",
	_ObjID_FieldInfo_,
	_ObjID_MethodInfo_
};

$Object* allocate$ObjID($Class* clazz) {
	return $of($alloc(ObjID));
}

$AtomicLong* ObjID::nextObjNum = nullptr;
$UID* ObjID::mySpace = nullptr;
$SecureRandom* ObjID::secureRandom = nullptr;

void ObjID::init$() {
	if (useRandomIDs()) {
		$set(this, space, $new($UID));
		this->objNum = $nc(ObjID::secureRandom)->nextLong();
	} else {
		$set(this, space, ObjID::mySpace);
		this->objNum = $nc(ObjID::nextObjNum)->getAndIncrement();
	}
}

void ObjID::init$(int32_t objNum) {
	$set(this, space, $new($UID, (int16_t)0));
	this->objNum = objNum;
}

void ObjID::init$(int64_t objNum, $UID* space) {
	this->objNum = objNum;
	$set(this, space, space);
}

void ObjID::write($ObjectOutput* out) {
	$nc(out)->writeLong(this->objNum);
	$nc(this->space)->write(out);
}

ObjID* ObjID::read($ObjectInput* in) {
	$init(ObjID);
	int64_t num = $nc(in)->readLong();
	$var($UID, space, $UID::read(in));
	return $new(ObjID, num, space);
}

int32_t ObjID::hashCode() {
	return (int32_t)this->objNum;
}

bool ObjID::equals(Object$* obj) {
	if ($instanceOf(ObjID, obj)) {
		$var(ObjID, id, $cast(ObjID, obj));
		return this->objNum == $nc(id)->objNum && $nc(this->space)->equals(id->space);
	} else {
		return false;
	}
}

$String* ObjID::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({"["_s, ($nc(this->space)->equals(ObjID::mySpace) ? ""_s : $$str({this->space, ", "_s})), $$str(this->objNum), "]"_s});
}

bool ObjID::useRandomIDs() {
	$init(ObjID);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, value, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(ObjID$$Lambda$lambda$useRandomIDs$0)))));
	return value == nullptr ? true : $Boolean::parseBoolean(value);
}

$String* ObjID::lambda$useRandomIDs$0() {
	$init(ObjID);
	return $System::getProperty("java.rmi.server.randomIDs"_s);
}

void clinit$ObjID($Class* class$) {
	$assignStatic(ObjID::nextObjNum, $new($AtomicLong));
	$assignStatic(ObjID::mySpace, $new($UID));
	$assignStatic(ObjID::secureRandom, $new($SecureRandom));
}

ObjID::ObjID() {
}

$Class* ObjID::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ObjID$$Lambda$lambda$useRandomIDs$0::classInfo$.name)) {
			return ObjID$$Lambda$lambda$useRandomIDs$0::load$(name, initialize);
		}
	}
	$loadClass(ObjID, name, initialize, &_ObjID_ClassInfo_, clinit$ObjID, allocate$ObjID);
	return class$;
}

$Class* ObjID::class$ = nullptr;

		} // server
	} // rmi
} // java