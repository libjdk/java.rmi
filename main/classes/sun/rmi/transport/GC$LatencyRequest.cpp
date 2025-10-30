#include <sun/rmi/transport/GC$LatencyRequest.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/util/NavigableSet.h>
#include <java/util/SortedSet.h>
#include <java/util/TreeSet.h>
#include <sun/rmi/transport/GC.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NavigableSet = ::java::util::NavigableSet;
using $Set = ::java::util::Set;
using $SortedSet = ::java::util::SortedSet;
using $TreeSet = ::java::util::TreeSet;
using $GC = ::sun::rmi::transport::GC;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _GC$LatencyRequest_FieldInfo_[] = {
	{"counter", "J", nullptr, $PRIVATE | $STATIC, $staticField(GC$LatencyRequest, counter)},
	{"requests", "Ljava/util/SortedSet;", "Ljava/util/SortedSet<Lsun/rmi/transport/GC$LatencyRequest;>;", $PRIVATE | $STATIC, $staticField(GC$LatencyRequest, requests)},
	{"latency", "J", nullptr, $PRIVATE, $field(GC$LatencyRequest, latency)},
	{"id", "J", nullptr, $PRIVATE, $field(GC$LatencyRequest, id)},
	{}
};

$MethodInfo _GC$LatencyRequest_MethodInfo_[] = {
	{"<init>", "(J)V", nullptr, $PRIVATE, $method(static_cast<void(GC$LatencyRequest::*)(int64_t)>(&GC$LatencyRequest::init$))},
	{"adjustLatencyIfNeeded", "()V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)()>(&GC$LatencyRequest::adjustLatencyIfNeeded))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"compareTo", "(Lsun/rmi/transport/GC$LatencyRequest;)I", nullptr, $PUBLIC},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _GC$LatencyRequest_InnerClassesInfo_[] = {
	{"sun.rmi.transport.GC$LatencyRequest", "sun.rmi.transport.GC", "LatencyRequest", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _GC$LatencyRequest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.GC$LatencyRequest",
	"java.lang.Object",
	"java.lang.Comparable",
	_GC$LatencyRequest_FieldInfo_,
	_GC$LatencyRequest_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Lsun/rmi/transport/GC$LatencyRequest;>;",
	nullptr,
	_GC$LatencyRequest_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.GC"
};

$Object* allocate$GC$LatencyRequest($Class* clazz) {
	return $of($alloc(GC$LatencyRequest));
}

int64_t GC$LatencyRequest::counter = 0;
$SortedSet* GC$LatencyRequest::requests = nullptr;

void GC$LatencyRequest::adjustLatencyIfNeeded() {
	$init(GC$LatencyRequest);
	if ((GC$LatencyRequest::requests == nullptr) || $nc(GC$LatencyRequest::requests)->isEmpty()) {
		$init($GC);
		if ($GC::latencyTarget != (int64_t)0x7FFFFFFFFFFFFFFF) {
			$GC::setLatencyTarget(0x7FFFFFFFFFFFFFFF);
		}
	} else {
		$var(GC$LatencyRequest, r, $cast(GC$LatencyRequest, $nc(GC$LatencyRequest::requests)->first()));
		$init($GC);
		if ($nc(r)->latency != $GC::latencyTarget) {
			$GC::setLatencyTarget(r->latency);
		}
	}
}

void GC$LatencyRequest::init$(int64_t ms) {
	$useLocalCurrentObjectStackCache();
	if (ms <= 0) {
		$throwNew($IllegalArgumentException, $$str({"Non-positive latency: "_s, $$str(ms)}));
	}
	this->latency = ms;
	$init($GC);
	$synchronized($GC::lock) {
		this->id = ++GC$LatencyRequest::counter;
		if (GC$LatencyRequest::requests == nullptr) {
			$assignStatic(GC$LatencyRequest::requests, $new($TreeSet));
		}
		$nc(GC$LatencyRequest::requests)->add(this);
		adjustLatencyIfNeeded();
	}
}

void GC$LatencyRequest::cancel() {
	$init($GC);
	$synchronized($GC::lock) {
		if (this->latency == (int64_t)0x7FFFFFFFFFFFFFFF) {
			$throwNew($IllegalStateException, "Request already cancelled"_s);
		}
		if (!$nc(GC$LatencyRequest::requests)->remove(this)) {
			$throwNew($InternalError, $$str({"Latency request "_s, this, " not found"_s}));
		}
		if ($nc(GC$LatencyRequest::requests)->isEmpty()) {
			$assignStatic(GC$LatencyRequest::requests, nullptr);
		}
		this->latency = 0x7FFFFFFFFFFFFFFF;
		adjustLatencyIfNeeded();
	}
}

int32_t GC$LatencyRequest::compareTo(GC$LatencyRequest* r) {
	int64_t d = this->latency - $nc(r)->latency;
	if (d == 0) {
		d = this->id - r->id;
	}
	return (d < 0) ? -1 : ((d > 0) ? +1 : 0);
}

$String* GC$LatencyRequest::toString() {
	$useLocalCurrentObjectStackCache();
	return ($str({$(GC$LatencyRequest::class$->getName()), "["_s, $$str(this->latency), ","_s, $$str(this->id), "]"_s}));
}

int32_t GC$LatencyRequest::compareTo(Object$* r) {
	return this->compareTo($cast(GC$LatencyRequest, r));
}

void clinit$GC$LatencyRequest($Class* class$) {
	GC$LatencyRequest::counter = 0;
	$assignStatic(GC$LatencyRequest::requests, nullptr);
}

GC$LatencyRequest::GC$LatencyRequest() {
}

$Class* GC$LatencyRequest::load$($String* name, bool initialize) {
	$loadClass(GC$LatencyRequest, name, initialize, &_GC$LatencyRequest_ClassInfo_, clinit$GC$LatencyRequest, allocate$GC$LatencyRequest);
	return class$;
}

$Class* GC$LatencyRequest::class$ = nullptr;

		} // transport
	} // rmi
} // sun