#include <sun/rmi/server/LoaderHandler$Loader.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/SecurityManager.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/util/Enumeration.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <jcpp.h>

using $URLArray = $Array<::java::net::URL>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $URLClassLoader = ::java::net::URLClassLoader;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $Enumeration = ::java::util::Enumeration;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _LoaderHandler$Loader_FieldInfo_[] = {
	{"parent", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE, $field(LoaderHandler$Loader, parent)},
	{"annotation", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LoaderHandler$Loader, annotation)},
	{"permissions", "Ljava/security/Permissions;", nullptr, $PRIVATE, $field(LoaderHandler$Loader, permissions)},
	{}
};

$MethodInfo _LoaderHandler$Loader_MethodInfo_[] = {
	{"<init>", "([Ljava/net/URL;Ljava/lang/ClassLoader;)V", nullptr, $PRIVATE, $method(static_cast<void(LoaderHandler$Loader::*)($URLArray*,$ClassLoader*)>(&LoaderHandler$Loader::init$))},
	{"checkPermissions", "()V", nullptr, $PRIVATE, $method(static_cast<void(LoaderHandler$Loader::*)()>(&LoaderHandler$Loader::checkPermissions))},
	{"getClassAnnotation", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PROTECTED},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, nullptr, "java.lang.ClassNotFoundException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LoaderHandler$Loader_InnerClassesInfo_[] = {
	{"sun.rmi.server.LoaderHandler$Loader", "sun.rmi.server.LoaderHandler", "Loader", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LoaderHandler$Loader_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.server.LoaderHandler$Loader",
	"java.net.URLClassLoader",
	nullptr,
	_LoaderHandler$Loader_FieldInfo_,
	_LoaderHandler$Loader_MethodInfo_,
	nullptr,
	nullptr,
	_LoaderHandler$Loader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.server.LoaderHandler"
};

$Object* allocate$LoaderHandler$Loader($Class* clazz) {
	return $of($alloc(LoaderHandler$Loader));
}

void LoaderHandler$Loader::init$($URLArray* urls, $ClassLoader* parent) {
	$URLClassLoader::init$(urls, parent);
	$set(this, parent, parent);
	$set(this, permissions, $new($Permissions));
	$LoaderHandler::addPermissionsForURLs(urls, this->permissions, false);
	$set(this, annotation, $LoaderHandler::urlsToPath(urls));
}

$String* LoaderHandler$Loader::getClassAnnotation() {
	return this->annotation;
}

void LoaderHandler$Loader::checkPermissions() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($Enumeration, enum_, $nc(this->permissions)->elements());
		while ($nc(enum_)->hasMoreElements()) {
			sm->checkPermission($cast($Permission, $(enum_->nextElement())));
		}
	}
}

$PermissionCollection* LoaderHandler$Loader::getPermissions($CodeSource* codesource) {
	$var($PermissionCollection, perms, $URLClassLoader::getPermissions(codesource));
	return perms;
}

$String* LoaderHandler$Loader::toString() {
	return $str({$($URLClassLoader::toString()), "[\""_s, this->annotation, "\"]"_s});
}

$Class* LoaderHandler$Loader::loadClass($String* name, bool resolve) {
	if (this->parent == nullptr) {
		$ReflectUtil::checkPackageAccess(name);
	}
	return $URLClassLoader::loadClass(name, resolve);
}

LoaderHandler$Loader::LoaderHandler$Loader() {
}

$Class* LoaderHandler$Loader::load$($String* name, bool initialize) {
	$loadClass(LoaderHandler$Loader, name, initialize, &_LoaderHandler$Loader_ClassInfo_, allocate$LoaderHandler$Loader);
	return class$;
}

$Class* LoaderHandler$Loader::class$ = nullptr;

		} // server
	} // rmi
} // sun