#include <java/rmi/server/RemoteStub.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _RemoteStub_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteStub_MethodAnnotations_setRef2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RemoteStub_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RemoteStub, serialVersionUID)},
	{}
};

$MethodInfo _RemoteStub_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(RemoteStub::*)()>(&RemoteStub::init$))},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PROTECTED, $method(static_cast<void(RemoteStub::*)($RemoteRef*)>(&RemoteStub::init$))},
	{"setRef", "(Ljava/rmi/server/RemoteStub;Ljava/rmi/server/RemoteRef;)V", nullptr, $PROTECTED | $STATIC | $DEPRECATED, $method(static_cast<void(*)(RemoteStub*,$RemoteRef*)>(&RemoteStub::setRef)), nullptr, nullptr, _RemoteStub_MethodAnnotations_setRef2},
	{}
};

$ClassInfo _RemoteStub_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.rmi.server.RemoteStub",
	"java.rmi.server.RemoteObject",
	nullptr,
	_RemoteStub_FieldInfo_,
	_RemoteStub_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RemoteStub_Annotations_
};

$Object* allocate$RemoteStub($Class* clazz) {
	return $of($alloc(RemoteStub));
}

void RemoteStub::init$() {
	$RemoteObject::init$();
}

void RemoteStub::init$($RemoteRef* ref) {
	$RemoteObject::init$(ref);
}

void RemoteStub::setRef(RemoteStub* stub, $RemoteRef* ref) {
	$init(RemoteStub);
	$throwNew($UnsupportedOperationException);
}

RemoteStub::RemoteStub() {
}

$Class* RemoteStub::load$($String* name, bool initialize) {
	$loadClass(RemoteStub, name, initialize, &_RemoteStub_ClassInfo_, allocate$RemoteStub);
	return class$;
}

$Class* RemoteStub::class$ = nullptr;

		} // server
	} // rmi
} // java