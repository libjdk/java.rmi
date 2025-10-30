#include <java/rmi/server/RemoteRef.h>

#include <java/io/ObjectOutput.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <jcpp.h>

using $OperationArray = $Array<::java::rmi::server::Operation>;
using $Externalizable = ::java::io::Externalizable;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Method = ::java::lang::reflect::Method;
using $Remote = ::java::rmi::Remote;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $RemoteObject = ::java::rmi::server::RemoteObject;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _RemoteRef_FieldAnnotations_serialVersionUID[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteRef_MethodAnnotations_done0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteRef_MethodAnnotations_invoke3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteRef_MethodAnnotations_newCall4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RemoteRef_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $constField(RemoteRef, serialVersionUID), _RemoteRef_FieldAnnotations_serialVersionUID},
	{"packagePrefix", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(RemoteRef, packagePrefix)},
	{}
};

$MethodInfo _RemoteRef_MethodInfo_[] = {
	{"done", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.rmi.RemoteException", nullptr, _RemoteRef_MethodAnnotations_done0},
	{"getRefClass", "(Ljava/io/ObjectOutput;)Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"invoke", "(Ljava/rmi/Remote;Ljava/lang/reflect/Method;[Ljava/lang/Object;J)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.lang.Exception"},
	{"invoke", "(Ljava/rmi/server/RemoteCall;)V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.lang.Exception", nullptr, _RemoteRef_MethodAnnotations_invoke3},
	{"newCall", "(Ljava/rmi/server/RemoteObject;[Ljava/rmi/server/Operation;IJ)Ljava/rmi/server/RemoteCall;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.rmi.RemoteException", nullptr, _RemoteRef_MethodAnnotations_newCall4},
	{"remoteEquals", "(Ljava/rmi/server/RemoteRef;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"remoteHashCode", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"remoteToString", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _RemoteRef_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.RemoteRef",
	nullptr,
	"java.io.Externalizable",
	_RemoteRef_FieldInfo_,
	_RemoteRef_MethodInfo_
};

$Object* allocate$RemoteRef($Class* clazz) {
	return $of($alloc(RemoteRef));
}

$String* RemoteRef::packagePrefix = nullptr;

void clinit$RemoteRef($Class* class$) {
	$assignStatic(RemoteRef::packagePrefix, "sun.rmi.server"_s);
}

$Class* RemoteRef::load$($String* name, bool initialize) {
	$loadClass(RemoteRef, name, initialize, &_RemoteRef_ClassInfo_, clinit$RemoteRef, allocate$RemoteRef);
	return class$;
}

$Class* RemoteRef::class$ = nullptr;

		} // server
	} // rmi
} // java