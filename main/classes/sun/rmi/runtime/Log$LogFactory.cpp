#include <sun/rmi/runtime/Log$LogFactory.h>

#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;

namespace sun {
	namespace rmi {
		namespace runtime {

$MethodInfo _Log$LogFactory_MethodInfo_[] = {
	{"createLog", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/logging/Level;)Lsun/rmi/runtime/Log;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _Log$LogFactory_InnerClassesInfo_[] = {
	{"sun.rmi.runtime.Log$LogFactory", "sun.rmi.runtime.Log", "LogFactory", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Log$LogFactory_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"sun.rmi.runtime.Log$LogFactory",
	nullptr,
	nullptr,
	nullptr,
	_Log$LogFactory_MethodInfo_,
	nullptr,
	nullptr,
	_Log$LogFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.runtime.Log"
};

$Object* allocate$Log$LogFactory($Class* clazz) {
	return $of($alloc(Log$LogFactory));
}

$Class* Log$LogFactory::load$($String* name, bool initialize) {
	$loadClass(Log$LogFactory, name, initialize, &_Log$LogFactory_ClassInfo_, allocate$Log$LogFactory);
	return class$;
}

$Class* Log$LogFactory::class$ = nullptr;

		} // runtime
	} // rmi
} // sun