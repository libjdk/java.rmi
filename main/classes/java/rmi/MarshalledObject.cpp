#include <java/rmi/MarshalledObject.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/rmi/MarshalledObject$MarshalledObjectInputStream.h>
#include <java/rmi/MarshalledObject$MarshalledObjectOutputStream.h>
#include <jcpp.h>

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $InputStream = ::java::io::InputStream;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MarshalledObject$MarshalledObjectInputStream = ::java::rmi::MarshalledObject$MarshalledObjectInputStream;
using $MarshalledObject$MarshalledObjectOutputStream = ::java::rmi::MarshalledObject$MarshalledObjectOutputStream;
using $MarshalInputStream = ::sun::rmi::server::MarshalInputStream;

namespace java {
	namespace rmi {

$FieldInfo _MarshalledObject_FieldInfo_[] = {
	{"objBytes", "[B", nullptr, $PRIVATE, $field(MarshalledObject, objBytes)},
	{"locBytes", "[B", nullptr, $PRIVATE, $field(MarshalledObject, locBytes)},
	{"hash", "I", nullptr, $PRIVATE, $field(MarshalledObject, hash)},
	{"objectInputFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $TRANSIENT, $field(MarshalledObject, objectInputFilter)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MarshalledObject, serialVersionUID)},
	{}
};

$MethodInfo _MarshalledObject_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Object;)V", "(TT;)V", $PUBLIC, $method(static_cast<void(MarshalledObject::*)(Object$*)>(&MarshalledObject::init$)), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"get", "()Ljava/lang/Object;", "()TT;", $PUBLIC, $method(static_cast<$Object*(MarshalledObject::*)()>(&MarshalledObject::get)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(MarshalledObject::*)($ObjectInputStream*)>(&MarshalledObject::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _MarshalledObject_InnerClassesInfo_[] = {
	{"java.rmi.MarshalledObject$MarshalledObjectInputStream", "java.rmi.MarshalledObject", "MarshalledObjectInputStream", $PRIVATE | $STATIC},
	{"java.rmi.MarshalledObject$MarshalledObjectOutputStream", "java.rmi.MarshalledObject", "MarshalledObjectOutputStream", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _MarshalledObject_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.MarshalledObject",
	"java.lang.Object",
	"java.io.Serializable",
	_MarshalledObject_FieldInfo_,
	_MarshalledObject_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/io/Serializable;",
	nullptr,
	_MarshalledObject_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.rmi.MarshalledObject$MarshalledObjectInputStream,java.rmi.MarshalledObject$MarshalledObjectOutputStream"
};

$Object* allocate$MarshalledObject($Class* clazz) {
	return $of($alloc(MarshalledObject));
}

void MarshalledObject::init$(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$set(this, objBytes, nullptr);
	$set(this, locBytes, nullptr);
	$set(this, objectInputFilter, nullptr);
	if (obj == nullptr) {
		this->hash = 13;
		return;
	}
	$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream));
	$var($ByteArrayOutputStream, lout, $new($ByteArrayOutputStream));
	$var($MarshalledObject$MarshalledObjectOutputStream, out, $new($MarshalledObject$MarshalledObjectOutputStream, bout, lout));
	out->writeObject(obj);
	out->flush();
	$set(this, objBytes, bout->toByteArray());
	$set(this, locBytes, out->hadAnnotations() ? lout->toByteArray() : ($bytes*)nullptr);
	int32_t h = 0;
	for (int32_t i = 0; i < $nc(this->objBytes)->length; ++i) {
		h = 31 * h + $nc(this->objBytes)->get(i);
	}
	this->hash = h;
}

void MarshalledObject::readObject($ObjectInputStream* stream) {
	$nc(stream)->defaultReadObject();
	$set(this, objectInputFilter, stream->getObjectInputFilter());
}

$Object* MarshalledObject::get() {
	$useLocalCurrentObjectStackCache();
	if (this->objBytes == nullptr) {
		return $of(nullptr);
	}
	$var($ByteArrayInputStream, bin, $new($ByteArrayInputStream, this->objBytes));
	$var($ByteArrayInputStream, lin, this->locBytes == nullptr ? ($ByteArrayInputStream*)nullptr : $new($ByteArrayInputStream, this->locBytes));
	$var($MarshalledObject$MarshalledObjectInputStream, in, $new($MarshalledObject$MarshalledObjectInputStream, bin, lin, this->objectInputFilter));
	$var($Object, obj, in->readObject());
	in->close();
	return $of(obj);
}

int32_t MarshalledObject::hashCode() {
	return this->hash;
}

bool MarshalledObject::equals(Object$* obj) {
	if ($equals(obj, this)) {
		return true;
	}
	if (obj != nullptr && $instanceOf(MarshalledObject, obj)) {
		$var(MarshalledObject, other, $cast(MarshalledObject, obj));
		if (this->objBytes == nullptr || other->objBytes == nullptr) {
			return this->objBytes == other->objBytes;
		}
		if ($nc(this->objBytes)->length != $nc(other->objBytes)->length) {
			return false;
		}
		for (int32_t i = 0; i < $nc(this->objBytes)->length; ++i) {
			if ($nc(this->objBytes)->get(i) != $nc(other->objBytes)->get(i)) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}

MarshalledObject::MarshalledObject() {
}

$Class* MarshalledObject::load$($String* name, bool initialize) {
	$loadClass(MarshalledObject, name, initialize, &_MarshalledObject_ClassInfo_, allocate$MarshalledObject);
	return class$;
}

$Class* MarshalledObject::class$ = nullptr;

	} // rmi
} // java