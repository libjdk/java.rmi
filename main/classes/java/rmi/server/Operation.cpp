#include <java/rmi/server/Operation.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _Operation_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Operation_MethodAnnotations_init$0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Operation_MethodAnnotations_getOperation1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Operation_MethodAnnotations_toString2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Operation_FieldInfo_[] = {
	{"operation", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Operation, operation)},
	{}
};

$MethodInfo _Operation_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $method(static_cast<void(Operation::*)($String*)>(&Operation::init$)), nullptr, nullptr, _Operation_MethodAnnotations_init$0},
	{"getOperation", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _Operation_MethodAnnotations_getOperation1},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _Operation_MethodAnnotations_toString2},
	{}
};

$ClassInfo _Operation_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.Operation",
	"java.lang.Object",
	nullptr,
	_Operation_FieldInfo_,
	_Operation_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_Operation_Annotations_
};

$Object* allocate$Operation($Class* clazz) {
	return $of($alloc(Operation));
}

void Operation::init$($String* op) {
	$set(this, operation, op);
}

$String* Operation::getOperation() {
	return this->operation;
}

$String* Operation::toString() {
	return this->operation;
}

Operation::Operation() {
}

$Class* Operation::load$($String* name, bool initialize) {
	$loadClass(Operation, name, initialize, &_Operation_ClassInfo_, allocate$Operation);
	return class$;
}

$Class* Operation::class$ = nullptr;

		} // server
	} // rmi
} // java