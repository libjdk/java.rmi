#include <java/rmi/server/UID.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/lang/InterruptedException.h>
#include <java/security/SecureRandom.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef MIN_VALUE
#undef UID

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $SecureRandom = ::java::security::SecureRandom;
using $Random = ::java::util::Random;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _UID_FieldInfo_[] = {
	{"hostUnique", "I", nullptr, $PRIVATE | $STATIC, $staticField(UID, hostUnique)},
	{"hostUniqueSet", "Z", nullptr, $PRIVATE | $STATIC, $staticField(UID, hostUniqueSet)},
	{"lock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UID, lock)},
	{"lastTime", "J", nullptr, $PRIVATE | $STATIC, $staticField(UID, lastTime)},
	{"lastCount", "S", nullptr, $PRIVATE | $STATIC, $staticField(UID, lastCount)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UID, serialVersionUID)},
	{"unique", "I", nullptr, $PRIVATE | $FINAL, $field(UID, unique)},
	{"time", "J", nullptr, $PRIVATE | $FINAL, $field(UID, time)},
	{"count", "S", nullptr, $PRIVATE | $FINAL, $field(UID, count)},
	{}
};

$MethodInfo _UID_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UID::*)()>(&UID::init$))},
	{"<init>", "(S)V", nullptr, $PUBLIC, $method(static_cast<void(UID::*)(int16_t)>(&UID::init$))},
	{"<init>", "(IJS)V", nullptr, $PRIVATE, $method(static_cast<void(UID::*)(int32_t,int64_t,int16_t)>(&UID::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"read", "(Ljava/io/DataInput;)Ljava/rmi/server/UID;", nullptr, $PUBLIC | $STATIC, $method(static_cast<UID*(*)($DataInput*)>(&UID::read)), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"write", "(Ljava/io/DataOutput;)V", nullptr, $PUBLIC, $method(static_cast<void(UID::*)($DataOutput*)>(&UID::write)), "java.io.IOException"},
	{}
};

$ClassInfo _UID_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.server.UID",
	"java.lang.Object",
	"java.io.Serializable",
	_UID_FieldInfo_,
	_UID_MethodInfo_
};

$Object* allocate$UID($Class* clazz) {
	return $of($alloc(UID));
}

int32_t UID::hostUnique = 0;
bool UID::hostUniqueSet = false;
$Object* UID::lock = nullptr;
int64_t UID::lastTime = 0;
int16_t UID::lastCount = 0;

void UID::init$() {
	$useLocalCurrentObjectStackCache();
	$synchronized(UID::lock) {
		if (!UID::hostUniqueSet) {
			UID::hostUnique = ($$new($SecureRandom))->nextInt();
			UID::hostUniqueSet = true;
		}
		this->unique = UID::hostUnique;
		if (UID::lastCount == $Short::MAX_VALUE) {
			bool interrupted = $Thread::interrupted();
			bool done = false;
			while (!done) {
				int64_t now = $System::currentTimeMillis();
				if (now == UID::lastTime) {
					try {
						$Thread::sleep(1);
					} catch ($InterruptedException& e) {
						interrupted = true;
					}
				} else {
					UID::lastTime = (now < UID::lastTime) ? UID::lastTime + 1 : now;
					UID::lastCount = $Short::MIN_VALUE;
					done = true;
				}
			}
			if (interrupted) {
				$($Thread::currentThread())->interrupt();
			}
		}
		this->time = UID::lastTime;
		this->count = UID::lastCount++;
	}
}

void UID::init$(int16_t num) {
	this->unique = 0;
	this->time = 0;
	this->count = num;
}

void UID::init$(int32_t unique, int64_t time, int16_t count) {
	this->unique = unique;
	this->time = time;
	this->count = count;
}

int32_t UID::hashCode() {
	return (int32_t)this->time + (int32_t)this->count;
}

bool UID::equals(Object$* obj) {
	if ($instanceOf(UID, obj)) {
		$var(UID, uid, $cast(UID, obj));
		return (this->unique == $nc(uid)->unique && this->count == uid->count && this->time == uid->time);
	} else {
		return false;
	}
}

$String* UID::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$2, $$str({$($Integer::toString(this->unique, 16)), ":"_s}));
	$var($String, var$1, $$concat(var$2, $($Long::toString(this->time, 16))));
	$var($String, var$0, $$concat(var$1, ":"));
	return $concat(var$0, $($Integer::toString(this->count, 16)));
}

void UID::write($DataOutput* out) {
	$nc(out)->writeInt(this->unique);
	out->writeLong(this->time);
	out->writeShort(this->count);
}

UID* UID::read($DataInput* in) {
	$init(UID);
	int32_t unique = $nc(in)->readInt();
	int64_t time = in->readLong();
	int16_t count = in->readShort();
	return $new(UID, unique, time, count);
}

void clinit$UID($Class* class$) {
	UID::hostUniqueSet = false;
	$assignStatic(UID::lock, $new($Object));
	UID::lastTime = $System::currentTimeMillis();
	UID::lastCount = $Short::MIN_VALUE;
}

UID::UID() {
}

$Class* UID::load$($String* name, bool initialize) {
	$loadClass(UID, name, initialize, &_UID_ClassInfo_, clinit$UID, allocate$UID);
	return class$;
}

$Class* UID::class$ = nullptr;

		} // server
	} // rmi
} // java