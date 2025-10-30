#include <sun/rmi/server/UnicastRef2.h>

#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _UnicastRef2_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicastRef2, serialVersionUID)},
	{}
};

$MethodInfo _UnicastRef2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastRef2::*)()>(&UnicastRef2::init$))},
	{"<init>", "(Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastRef2::*)($LiveRef*)>(&UnicastRef2::init$))},
	{"getRefClass", "(Ljava/io/ObjectOutput;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"readExternal", "(Ljava/io/ObjectInput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{"writeExternal", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _UnicastRef2_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.server.UnicastRef2",
	"sun.rmi.server.UnicastRef",
	nullptr,
	_UnicastRef2_FieldInfo_,
	_UnicastRef2_MethodInfo_
};

$Object* allocate$UnicastRef2($Class* clazz) {
	return $of($alloc(UnicastRef2));
}

void UnicastRef2::init$() {
	$UnicastRef::init$();
}

void UnicastRef2::init$($LiveRef* liveRef) {
	$UnicastRef::init$(liveRef);
}

$String* UnicastRef2::getRefClass($ObjectOutput* out) {
	return "UnicastRef2"_s;
}

void UnicastRef2::writeExternal($ObjectOutput* out) {
	$nc(this->ref)->write(out, true);
}

void UnicastRef2::readExternal($ObjectInput* in) {
	$set(this, ref, $LiveRef::read(in, true));
}

UnicastRef2::UnicastRef2() {
}

$Class* UnicastRef2::load$($String* name, bool initialize) {
	$loadClass(UnicastRef2, name, initialize, &_UnicastRef2_ClassInfo_, allocate$UnicastRef2);
	return class$;
}

$Class* UnicastRef2::class$ = nullptr;

		} // server
	} // rmi
} // sun