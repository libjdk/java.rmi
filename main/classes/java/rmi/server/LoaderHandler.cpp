#include <java/rmi/server/LoaderHandler.h>

#include <java/lang/ClassLoader.h>
#include <java/net/URL.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $URL = ::java::net::URL;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _LoaderHandler_Annotations_[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LoaderHandler_MethodAnnotations_getSecurityContext0[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LoaderHandler_MethodAnnotations_loadClass1[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _LoaderHandler_MethodAnnotations_loadClass2[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _LoaderHandler_FieldInfo_[] = {
	{"packagePrefix", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LoaderHandler, packagePrefix)},
	{}
};

$MethodInfo _LoaderHandler_MethodInfo_[] = {
	{"getSecurityContext", "(Ljava/lang/ClassLoader;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, nullptr, nullptr, _LoaderHandler_MethodAnnotations_getSecurityContext0},
	{"loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.net.MalformedURLException,java.lang.ClassNotFoundException", nullptr, _LoaderHandler_MethodAnnotations_loadClass1},
	{"loadClass", "(Ljava/net/URL;Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/net/URL;Ljava/lang/String;)Ljava/lang/Class<*>;", $PUBLIC | $ABSTRACT | $DEPRECATED, nullptr, "java.net.MalformedURLException,java.lang.ClassNotFoundException", nullptr, _LoaderHandler_MethodAnnotations_loadClass2},
	{}
};

$ClassInfo _LoaderHandler_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.rmi.server.LoaderHandler",
	nullptr,
	nullptr,
	_LoaderHandler_FieldInfo_,
	_LoaderHandler_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_LoaderHandler_Annotations_
};

$Object* allocate$LoaderHandler($Class* clazz) {
	return $of($alloc(LoaderHandler));
}

$String* LoaderHandler::packagePrefix = nullptr;

void clinit$LoaderHandler($Class* class$) {
	$assignStatic(LoaderHandler::packagePrefix, "sun.rmi.server"_s);
}

$Class* LoaderHandler::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler, name, initialize, &_LoaderHandler_ClassInfo_, clinit$LoaderHandler, allocate$LoaderHandler);
	return class$;
}

$Class* LoaderHandler::class$ = nullptr;

		} // server
	} // rmi
} // java