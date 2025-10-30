#include <sun/rmi/server/MarshalOutputStream.h>

#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamConstants.h>
#include <java/io/OutputStream.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/RMIClassLoader.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/server/MarshalOutputStream$1.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/Target.h>
#include <jcpp.h>

#undef PROTOCOL_VERSION_1

using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectStreamConstants = ::java::io::ObjectStreamConstants;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RMIClassLoader = ::java::rmi::server::RMIClassLoader;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $MarshalOutputStream$1 = ::sun::rmi::server::MarshalOutputStream$1;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;
using $Target = ::sun::rmi::transport::Target;

namespace sun {
	namespace rmi {
		namespace server {

$MethodInfo _MarshalOutputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(MarshalOutputStream::*)($OutputStream*)>(&MarshalOutputStream::init$)), "java.io.IOException"},
	{"<init>", "(Ljava/io/OutputStream;I)V", nullptr, $PUBLIC, $method(static_cast<void(MarshalOutputStream::*)($OutputStream*,int32_t)>(&MarshalOutputStream::init$)), "java.io.IOException"},
	{"access$000", "(Lsun/rmi/server/MarshalOutputStream;Z)Z", nullptr, $STATIC | $SYNTHETIC, $method(static_cast<bool(*)(MarshalOutputStream*,bool)>(&MarshalOutputStream::access$000)), "java.lang.SecurityException"},
	{"annotateClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PROTECTED, nullptr, "java.io.IOException"},
	{"annotateProxyClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PROTECTED, nullptr, "java.io.IOException"},
	{"replaceObject", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PROTECTED | $FINAL, nullptr, "java.io.IOException"},
	{"writeLocation", "(Ljava/lang/String;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _MarshalOutputStream_InnerClassesInfo_[] = {
	{"sun.rmi.server.MarshalOutputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MarshalOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.server.MarshalOutputStream",
	"java.io.ObjectOutputStream",
	nullptr,
	nullptr,
	_MarshalOutputStream_MethodInfo_,
	nullptr,
	nullptr,
	_MarshalOutputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.server.MarshalOutputStream$1"
};

$Object* allocate$MarshalOutputStream($Class* clazz) {
	return $of($alloc(MarshalOutputStream));
}

bool MarshalOutputStream::access$000(MarshalOutputStream* x0, bool x1) {
	$init(MarshalOutputStream);
	return $nc(x0)->enableReplaceObject(x1);
}

void MarshalOutputStream::init$($OutputStream* out) {
	MarshalOutputStream::init$(out, $ObjectStreamConstants::PROTOCOL_VERSION_1);
}

void MarshalOutputStream::init$($OutputStream* out, int32_t protocolVersion) {
	$beforeCallerSensitive();
	$ObjectOutputStream::init$(out);
	this->useProtocolVersion(protocolVersion);
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($MarshalOutputStream$1, this)));
}

$Object* MarshalOutputStream::replaceObject(Object$* obj) {
	if (($instanceOf($Remote, obj)) && !($instanceOf($RemoteStub, obj))) {
		$var($Target, target, $ObjectTable::getTarget($cast($Remote, obj)));
		if (target != nullptr) {
			return $of(target->getStub());
		}
	}
	return $of(obj);
}

void MarshalOutputStream::annotateClass($Class* cl) {
	writeLocation($($RMIClassLoader::getClassAnnotation(cl)));
}

void MarshalOutputStream::annotateProxyClass($Class* cl) {
	annotateClass(cl);
}

void MarshalOutputStream::writeLocation($String* location) {
	writeObject(location);
}

MarshalOutputStream::MarshalOutputStream() {
}

$Class* MarshalOutputStream::load$($String* name, bool initialize) {
	$loadClass(MarshalOutputStream, name, initialize, &_MarshalOutputStream_ClassInfo_, allocate$MarshalOutputStream);
	return class$;
}

$Class* MarshalOutputStream::class$ = nullptr;

		} // server
	} // rmi
} // sun