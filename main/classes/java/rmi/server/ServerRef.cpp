#include <java/rmi/server/ServerRef.h>

#include <java/rmi/Remote.h>
#include <java/rmi/server/RemoteStub.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _ServerRef_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _ServerRef_FieldAnnotations_serialVersionUID[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ServerRef_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(ServerRef, serialVersionUID), _ServerRef_FieldAnnotations_serialVersionUID},
	{}
};

$MethodInfo _ServerRef_MethodInfo_[] = {
	{"exportObject", "(Ljava/rmi/Remote;Ljava/lang/Object;)Ljava/rmi/server/RemoteStub;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.RemoteException"},
	{"getClientHost", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.rmi.server.ServerNotActiveException"},
	{}
};

$ClassInfo _ServerRef_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.ServerRef",
	nullptr,
	"java.rmi.server.RemoteRef",
	_ServerRef_FieldInfo_,
	_ServerRef_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_ServerRef_Annotations_
};

$Object* allocate$ServerRef($Class* clazz) {
	return $of($alloc(ServerRef));
}

$Class* ServerRef::load$($String* name, bool initialize) {
	$loadClass(ServerRef, name, initialize, &_ServerRef_ClassInfo_, allocate$ServerRef);
	return class$;
}

$Class* ServerRef::class$ = nullptr;

		} // server
	} // rmi
} // java