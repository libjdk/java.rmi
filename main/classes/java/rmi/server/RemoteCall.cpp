#include <java/rmi/server/RemoteCall.h>

#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <jcpp.h>

using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _RemoteCall_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_done0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_executeCall1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_getInputStream2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_getOutputStream3[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_getResultStream4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_releaseInputStream5[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RemoteCall_MethodAnnotations_releaseOutputStream6[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$MethodInfo _RemoteCall_MethodInfo_[] = {
	{"done", "()V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.io.IOException", nullptr, _RemoteCall_MethodAnnotations_done0},
	{"executeCall", "()V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.lang.Exception", nullptr, _RemoteCall_MethodAnnotations_executeCall1},
	{"getInputStream", "()Ljava/io/ObjectInput;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.io.IOException", nullptr, _RemoteCall_MethodAnnotations_getInputStream2},
	{"getOutputStream", "()Ljava/io/ObjectOutput;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.io.IOException", nullptr, _RemoteCall_MethodAnnotations_getOutputStream3},
	{"getResultStream", "(Z)Ljava/io/ObjectOutput;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.io.IOException,java.io.StreamCorruptedException", nullptr, _RemoteCall_MethodAnnotations_getResultStream4},
	{"releaseInputStream", "()V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.io.IOException", nullptr, _RemoteCall_MethodAnnotations_releaseInputStream5},
	{"releaseOutputStream", "()V", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.io.IOException", nullptr, _RemoteCall_MethodAnnotations_releaseOutputStream6},
	{}
};

$ClassInfo _RemoteCall_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.RemoteCall",
	nullptr,
	nullptr,
	nullptr,
	_RemoteCall_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RemoteCall_Annotations_
};

$Object* allocate$RemoteCall($Class* clazz) {
	return $of($alloc(RemoteCall));
}

$Class* RemoteCall::load$($String* name, bool initialize) {
	$loadClass(RemoteCall, name, initialize, &_RemoteCall_ClassInfo_, allocate$RemoteCall);
	return class$;
}

$Class* RemoteCall::class$ = nullptr;

		} // server
	} // rmi
} // java