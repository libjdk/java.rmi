#include <sun/rmi/transport/SequenceEntry.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _SequenceEntry_FieldInfo_[] = {
	{"sequenceNum", "J", nullptr, 0, $field(SequenceEntry, sequenceNum)},
	{"keep", "Z", nullptr, 0, $field(SequenceEntry, keep)},
	{}
};

$MethodInfo _SequenceEntry_MethodInfo_[] = {
	{"<init>", "(J)V", nullptr, 0, $method(static_cast<void(SequenceEntry::*)(int64_t)>(&SequenceEntry::init$))},
	{"retain", "(J)V", nullptr, 0},
	{"update", "(J)V", nullptr, 0},
	{}
};

$ClassInfo _SequenceEntry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.SequenceEntry",
	"java.lang.Object",
	nullptr,
	_SequenceEntry_FieldInfo_,
	_SequenceEntry_MethodInfo_
};

$Object* allocate$SequenceEntry($Class* clazz) {
	return $of($alloc(SequenceEntry));
}

void SequenceEntry::init$(int64_t sequenceNum) {
	this->sequenceNum = sequenceNum;
	this->keep = false;
}

void SequenceEntry::retain(int64_t sequenceNum) {
	this->sequenceNum = sequenceNum;
	this->keep = true;
}

void SequenceEntry::update(int64_t sequenceNum) {
	this->sequenceNum = sequenceNum;
}

SequenceEntry::SequenceEntry() {
}

$Class* SequenceEntry::load$($String* name, bool initialize) {
	$loadClass(SequenceEntry, name, initialize, &_SequenceEntry_ClassInfo_, allocate$SequenceEntry);
	return class$;
}

$Class* SequenceEntry::class$ = nullptr;

		} // transport
	} // rmi
} // sun