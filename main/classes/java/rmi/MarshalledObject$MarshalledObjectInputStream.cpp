#include <java/rmi/MarshalledObject$MarshalledObjectInputStream.h>

#include <java/io/InputStream.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/MarshalledObject.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/server/MarshalInputStream.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MarshalledObject = ::java::rmi::MarshalledObject;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $MarshalInputStream = ::sun::rmi::server::MarshalInputStream;

namespace java {
	namespace rmi {

class MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0 : public $PrivilegedAction {
	$class(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(MarshalledObject$MarshalledObjectInputStream* inst, $ObjectInputFilter* filter) {
		$set(this, inst$, inst);
		$set(this, filter, filter);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$new$0(filter));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0>());
	}
	MarshalledObject$MarshalledObjectInputStream* inst$ = nullptr;
	$ObjectInputFilter* filter = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0, inst$)},
	{"filter", "Ljava/io/ObjectInputFilter;", nullptr, $PUBLIC, $field(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0, filter)},
	{}
};
$MethodInfo MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljava/rmi/MarshalledObject$MarshalledObjectInputStream;Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC, $method(static_cast<void(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::*)(MarshalledObject$MarshalledObjectInputStream*,$ObjectInputFilter*)>(&MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.rmi.MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _MarshalledObject$MarshalledObjectInputStream_FieldInfo_[] = {
	{"locIn", "Ljava/io/ObjectInputStream;", nullptr, $PRIVATE, $field(MarshalledObject$MarshalledObjectInputStream, locIn)},
	{}
};

$MethodInfo _MarshalledObject$MarshalledObjectInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;Ljava/io/InputStream;Ljava/io/ObjectInputFilter;)V", nullptr, 0, $method(static_cast<void(MarshalledObject$MarshalledObjectInputStream::*)($InputStream*,$InputStream*,$ObjectInputFilter*)>(&MarshalledObject$MarshalledObjectInputStream::init$)), "java.io.IOException"},
	{"lambda$new$0", "(Ljava/io/ObjectInputFilter;)Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(MarshalledObject$MarshalledObjectInputStream::*)($ObjectInputFilter*)>(&MarshalledObject$MarshalledObjectInputStream::lambda$new$0))},
	{"readLocation", "()Ljava/lang/Object;", nullptr, $PROTECTED, nullptr, "java.io.IOException,java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _MarshalledObject$MarshalledObjectInputStream_InnerClassesInfo_[] = {
	{"java.rmi.MarshalledObject$MarshalledObjectInputStream", "java.rmi.MarshalledObject", "MarshalledObjectInputStream", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _MarshalledObject$MarshalledObjectInputStream_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.MarshalledObject$MarshalledObjectInputStream",
	"sun.rmi.server.MarshalInputStream",
	nullptr,
	_MarshalledObject$MarshalledObjectInputStream_FieldInfo_,
	_MarshalledObject$MarshalledObjectInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_MarshalledObject$MarshalledObjectInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.MarshalledObject"
};

$Object* allocate$MarshalledObject$MarshalledObjectInputStream($Class* clazz) {
	return $of($alloc(MarshalledObject$MarshalledObjectInputStream));
}

void MarshalledObject$MarshalledObjectInputStream::init$($InputStream* objIn, $InputStream* locIn, $ObjectInputFilter* filter) {
	$beforeCallerSensitive();
	$MarshalInputStream::init$(objIn);
	$set(this, locIn, locIn == nullptr ? ($ObjectInputStream*)nullptr : $new($ObjectInputStream, locIn));
	if (filter != nullptr) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0, this, filter)));
	}
}

$Object* MarshalledObject$MarshalledObjectInputStream::readLocation() {
	return $of((this->locIn == nullptr ? ($Object*)nullptr : $nc(this->locIn)->readObject()));
}

$Void* MarshalledObject$MarshalledObjectInputStream::lambda$new$0($ObjectInputFilter* filter) {
	this->setObjectInputFilter(filter);
	if (this->locIn != nullptr) {
		$nc(this->locIn)->setObjectInputFilter(filter);
	}
	return nullptr;
}

MarshalledObject$MarshalledObjectInputStream::MarshalledObject$MarshalledObjectInputStream() {
}

$Class* MarshalledObject$MarshalledObjectInputStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::classInfo$.name)) {
			return MarshalledObject$MarshalledObjectInputStream$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(MarshalledObject$MarshalledObjectInputStream, name, initialize, &_MarshalledObject$MarshalledObjectInputStream_ClassInfo_, allocate$MarshalledObject$MarshalledObjectInputStream);
	return class$;
}

$Class* MarshalledObject$MarshalledObjectInputStream::class$ = nullptr;

	} // rmi
} // java