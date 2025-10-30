#include <java/rmi/MarshalledObject$MarshalledObjectOutputStream.h>

#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamConstants.h>
#include <java/io/OutputStream.h>
#include <java/rmi/MarshalledObject.h>
#include <sun/rmi/server/MarshalOutputStream.h>
#include <jcpp.h>

#undef PROTOCOL_VERSION_2

using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectStreamConstants = ::java::io::ObjectStreamConstants;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $MarshalOutputStream = ::sun::rmi::server::MarshalOutputStream;

namespace java {
	namespace rmi {

$FieldInfo _MarshalledObject$MarshalledObjectOutputStream_FieldInfo_[] = {
	{"locOut", "Ljava/io/ObjectOutputStream;", nullptr, $PRIVATE, $field(MarshalledObject$MarshalledObjectOutputStream, locOut)},
	{"hadAnnotations", "Z", nullptr, $PRIVATE, $field(MarshalledObject$MarshalledObjectOutputStream, hadAnnotations$)},
	{}
};

$MethodInfo _MarshalledObject$MarshalledObjectOutputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;Ljava/io/OutputStream;)V", nullptr, 0, $method(static_cast<void(MarshalledObject$MarshalledObjectOutputStream::*)($OutputStream*,$OutputStream*)>(&MarshalledObject$MarshalledObjectOutputStream::init$)), "java.io.IOException"},
	{"flush", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"hadAnnotations", "()Z", nullptr, 0},
	{"writeLocation", "(Ljava/lang/String;)V", nullptr, $PROTECTED, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _MarshalledObject$MarshalledObjectOutputStream_InnerClassesInfo_[] = {
	{"java.rmi.MarshalledObject$MarshalledObjectOutputStream", "java.rmi.MarshalledObject", "MarshalledObjectOutputStream", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _MarshalledObject$MarshalledObjectOutputStream_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.MarshalledObject$MarshalledObjectOutputStream",
	"sun.rmi.server.MarshalOutputStream",
	nullptr,
	_MarshalledObject$MarshalledObjectOutputStream_FieldInfo_,
	_MarshalledObject$MarshalledObjectOutputStream_MethodInfo_,
	nullptr,
	nullptr,
	_MarshalledObject$MarshalledObjectOutputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.MarshalledObject"
};

$Object* allocate$MarshalledObject$MarshalledObjectOutputStream($Class* clazz) {
	return $of($alloc(MarshalledObject$MarshalledObjectOutputStream));
}

void MarshalledObject$MarshalledObjectOutputStream::init$($OutputStream* objOut, $OutputStream* locOut) {
	$MarshalOutputStream::init$(objOut);
	this->useProtocolVersion($ObjectStreamConstants::PROTOCOL_VERSION_2);
	$set(this, locOut, $new($ObjectOutputStream, locOut));
	this->hadAnnotations$ = false;
}

bool MarshalledObject$MarshalledObjectOutputStream::hadAnnotations() {
	return this->hadAnnotations$;
}

void MarshalledObject$MarshalledObjectOutputStream::writeLocation($String* loc) {
	this->hadAnnotations$ |= (loc != nullptr);
	$nc(this->locOut)->writeObject(loc);
}

void MarshalledObject$MarshalledObjectOutputStream::flush() {
	$MarshalOutputStream::flush();
	$nc(this->locOut)->flush();
}

MarshalledObject$MarshalledObjectOutputStream::MarshalledObject$MarshalledObjectOutputStream() {
}

$Class* MarshalledObject$MarshalledObjectOutputStream::load$($String* name, bool initialize) {
	$loadClass(MarshalledObject$MarshalledObjectOutputStream, name, initialize, &_MarshalledObject$MarshalledObjectOutputStream_ClassInfo_, allocate$MarshalledObject$MarshalledObjectOutputStream);
	return class$;
}

$Class* MarshalledObject$MarshalledObjectOutputStream::class$ = nullptr;

	} // rmi
} // java