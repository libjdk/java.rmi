#include <java/rmi/RMISecurityException.h>

#include <java/lang/SecurityException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;

namespace java {
	namespace rmi {

$CompoundAttribute _RMISecurityException_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RMISecurityException_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _RMISecurityException_MethodAnnotations_init$1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _RMISecurityException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RMISecurityException, serialVersionUID)},
	{}
};

$MethodInfo _RMISecurityException_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(static_cast<void(RMISecurityException::*)($String*)>(&RMISecurityException::init$)), nullptr, nullptr, _RMISecurityException_MethodAnnotations_init$0},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(static_cast<void(RMISecurityException::*)($String*,$String*)>(&RMISecurityException::init$)), nullptr, nullptr, _RMISecurityException_MethodAnnotations_init$1},
	{}
};

$ClassInfo _RMISecurityException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.RMISecurityException",
	"java.lang.SecurityException",
	nullptr,
	_RMISecurityException_FieldInfo_,
	_RMISecurityException_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_RMISecurityException_Annotations_
};

$Object* allocate$RMISecurityException($Class* clazz) {
	return $of($alloc(RMISecurityException));
}

void RMISecurityException::init$($String* name) {
	$SecurityException::init$(name);
}

void RMISecurityException::init$($String* name, $String* arg) {
	RMISecurityException::init$(name);
}

RMISecurityException::RMISecurityException() {
}

RMISecurityException::RMISecurityException(const RMISecurityException& e) : $SecurityException(e) {
}

void RMISecurityException::throw$() {
	throw *this;
}

$Class* RMISecurityException::load$($String* name, bool initialize) {
	$loadClass(RMISecurityException, name, initialize, &_RMISecurityException_ClassInfo_, allocate$RMISecurityException);
	return class$;
}

$Class* RMISecurityException::class$ = nullptr;

	} // rmi
} // java