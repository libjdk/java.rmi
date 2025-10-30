#include <java/rmi/Remote.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;

namespace java {
	namespace rmi {

$ClassInfo _Remote_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.Remote"
};

$Object* allocate$Remote($Class* clazz) {
	return $of($alloc(Remote));
}

$Class* Remote::load$($String* name, bool initialize) {
	$loadClass(Remote, name, initialize, &_Remote_ClassInfo_, allocate$Remote);
	return class$;
}

$Class* Remote::class$ = nullptr;

	} // rmi
} // java