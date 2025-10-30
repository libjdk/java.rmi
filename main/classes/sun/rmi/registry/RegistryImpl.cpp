#include <sun/rmi/registry/RegistryImpl.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Number.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Proxy.h>
#include <java/net/InetAddress.h>
#include <java/net/MalformedURLException.h>
#include <java/net/SocketPermission.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLClassLoader.h>
#include <java/net/UnknownHostException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/rmi/AccessException.h>
#include <java/rmi/AlreadyBoundException.h>
#include <java/rmi/NotBoundException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/registry/Registry.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteServer.h>
#include <java/rmi/server/ServerNotActiveException.h>
#include <java/rmi/server/UID.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/SecureClassLoader.h>
#include <java/security/Security.h>
#include <java/security/cert/Certificate.h>
#include <java/text/MessageFormat.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable.h>
#include <java/util/List.h>
#include <java/util/MissingResourceException.h>
#include <java/util/ResourceBundle.h>
#include <java/util/logging/Level.h>
#include <jdk/internal/access/JavaObjectInputFilterAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/rmi/registry/RegistryImpl$1.h>
#include <sun/rmi/registry/RegistryImpl$2.h>
#include <sun/rmi/registry/RegistryImpl$3.h>
#include <sun/rmi/registry/RegistryImpl$4.h>
#include <sun/rmi/registry/RegistryImpl$5.h>
#include <sun/rmi/registry/RegistryImpl$6.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/UnicastServerRef2.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

#undef ALLOWED
#undef BRIEF
#undef MAX_VALUE
#undef REGISTRY_FILTER_PROPNAME
#undef REGISTRY_ID
#undef REGISTRY_MAX_ARRAY_SIZE
#undef REGISTRY_MAX_DEPTH
#undef REGISTRY_PORT
#undef REJECTED
#undef UNDECIDED

using $URLArray = $Array<::java::net::URL>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $PermissionArray = $Array<::java::security::Permission>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Number = ::java::lang::Number;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Proxy = ::java::lang::reflect::Proxy;
using $InetAddress = ::java::net::InetAddress;
using $MalformedURLException = ::java::net::MalformedURLException;
using $SocketPermission = ::java::net::SocketPermission;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $URLClassLoader = ::java::net::URLClassLoader;
using $UnknownHostException = ::java::net::UnknownHostException;
using $LinkOption = ::java::nio::file::LinkOption;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $AccessException = ::java::rmi::AccessException;
using $AlreadyBoundException = ::java::rmi::AlreadyBoundException;
using $NotBoundException = ::java::rmi::NotBoundException;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $Registry = ::java::rmi::registry::Registry;
using $ObjID = ::java::rmi::server::ObjID;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteServer = ::java::rmi::server::RemoteServer;
using $ServerNotActiveException = ::java::rmi::server::ServerNotActiveException;
using $UID = ::java::rmi::server::UID;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $SecureClassLoader = ::java::security::SecureClassLoader;
using $Security = ::java::security::Security;
using $Certificate = ::java::security::cert::Certificate;
using $MessageFormat = ::java::text::MessageFormat;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable = ::java::util::Hashtable;
using $List = ::java::util::List;
using $MissingResourceException = ::java::util::MissingResourceException;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Level = ::java::util::logging::Level;
using $JavaObjectInputFilterAccess = ::jdk::internal::access::JavaObjectInputFilterAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $RegistryImpl$1 = ::sun::rmi::registry::RegistryImpl$1;
using $RegistryImpl$2 = ::sun::rmi::registry::RegistryImpl$2;
using $RegistryImpl$3 = ::sun::rmi::registry::RegistryImpl$3;
using $RegistryImpl$4 = ::sun::rmi::registry::RegistryImpl$4;
using $RegistryImpl$5 = ::sun::rmi::registry::RegistryImpl$5;
using $RegistryImpl$6 = ::sun::rmi::registry::RegistryImpl$6;
using $Log = ::sun::rmi::runtime::Log;
using $LoaderHandler = ::sun::rmi::server::LoaderHandler;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $UnicastServerRef2 = ::sun::rmi::server::UnicastServerRef2;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace registry {

class RegistryImpl$$Lambda$initRegistryFilter : public $PrivilegedAction {
	$class(RegistryImpl$$Lambda$initRegistryFilter, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(RegistryImpl::initRegistryFilter());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RegistryImpl$$Lambda$initRegistryFilter>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RegistryImpl$$Lambda$initRegistryFilter::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl$$Lambda$initRegistryFilter::*)()>(&RegistryImpl$$Lambda$initRegistryFilter::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RegistryImpl$$Lambda$initRegistryFilter::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.registry.RegistryImpl$$Lambda$initRegistryFilter",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* RegistryImpl$$Lambda$initRegistryFilter::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$$Lambda$initRegistryFilter, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RegistryImpl$$Lambda$initRegistryFilter::class$ = nullptr;

class RegistryImpl$$Lambda$registryFilter$1 : public $ObjectInputFilter {
	$class(RegistryImpl$$Lambda$registryFilter$1, $NO_CLASS_INIT, $ObjectInputFilter)
public:
	void init$() {
	}
	virtual $ObjectInputFilter$Status* checkInput($ObjectInputFilter$FilterInfo* filterInfo) override {
		 return RegistryImpl::registryFilter(filterInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RegistryImpl$$Lambda$registryFilter$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RegistryImpl$$Lambda$registryFilter$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl$$Lambda$registryFilter$1::*)()>(&RegistryImpl$$Lambda$registryFilter$1::init$))},
	{"checkInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RegistryImpl$$Lambda$registryFilter$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.registry.RegistryImpl$$Lambda$registryFilter$1",
	"java.lang.Object",
	"java.io.ObjectInputFilter",
	nullptr,
	methodInfos
};
$Class* RegistryImpl$$Lambda$registryFilter$1::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl$$Lambda$registryFilter$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RegistryImpl$$Lambda$registryFilter$1::class$ = nullptr;

$FieldInfo _RegistryImpl_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RegistryImpl, serialVersionUID)},
	{"bindings", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljava/rmi/Remote;>;", $PRIVATE, $field(RegistryImpl, bindings)},
	{"allowedAccessCache", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/net/InetAddress;Ljava/net/InetAddress;>;", $PRIVATE | $STATIC, $staticField(RegistryImpl, allowedAccessCache)},
	{"registry", "Lsun/rmi/registry/RegistryImpl;", nullptr, $PRIVATE | $STATIC, $staticField(RegistryImpl, registry)},
	{"id", "Ljava/rmi/server/ObjID;", nullptr, $PRIVATE | $STATIC, $staticField(RegistryImpl, id)},
	{"resources", "Ljava/util/ResourceBundle;", nullptr, $PRIVATE | $STATIC, $staticField(RegistryImpl, resources)},
	{"REGISTRY_FILTER_PROPNAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RegistryImpl, REGISTRY_FILTER_PROPNAME)},
	{"REGISTRY_MAX_DEPTH", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RegistryImpl, REGISTRY_MAX_DEPTH)},
	{"REGISTRY_MAX_ARRAY_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RegistryImpl, REGISTRY_MAX_ARRAY_SIZE)},
	{"registryFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RegistryImpl, registryFilter$)},
	{}
};

$MethodInfo _RegistryImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&RegistryImpl::init$)), "java.rmi.RemoteException"},
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*,$ObjectInputFilter*)>(&RegistryImpl::init$)), "java.rmi.RemoteException"},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl::*)(int32_t)>(&RegistryImpl::init$)), "java.rmi.RemoteException"},
	{"bind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException,java.rmi.AlreadyBoundException,java.rmi.AccessException"},
	{"checkAccess", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($String*)>(&RegistryImpl::checkAccess)), "java.rmi.AccessException"},
	{"createRegistry", "(I)Lsun/rmi/registry/RegistryImpl;", nullptr, $PUBLIC | $STATIC, $method(static_cast<RegistryImpl*(*)(int32_t)>(&RegistryImpl::createRegistry)), "java.rmi.RemoteException"},
	{"getAccessControlContext", "(I)Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$AccessControlContext*(*)(int32_t)>(&RegistryImpl::getAccessControlContext))},
	{"getID", "()Ljava/rmi/server/ObjID;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ObjID*(*)()>(&RegistryImpl::getID))},
	{"getTextResource", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&RegistryImpl::getTextResource))},
	{"initRegistryFilter", "()Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ObjectInputFilter*(*)()>(&RegistryImpl::initRegistryFilter))},
	{"list", "()[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"lookup", "(Ljava/lang/String;)Ljava/rmi/Remote;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException,java.rmi.NotBoundException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($StringArray*)>(&RegistryImpl::main))},
	{"pathToURLs", "(Ljava/lang/String;)[Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$URLArray*(*)($String*)>(&RegistryImpl::pathToURLs))},
	{"rebind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException,java.rmi.AccessException"},
	{"registryFilter", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$ObjectInputFilter$Status*(*)($ObjectInputFilter$FilterInfo*)>(&RegistryImpl::registryFilter))},
	{"setup", "(Lsun/rmi/server/UnicastServerRef;)V", nullptr, $PRIVATE, $method(static_cast<void(RegistryImpl::*)($UnicastServerRef*)>(&RegistryImpl::setup)), "java.rmi.RemoteException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unbind", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException,java.rmi.NotBoundException,java.rmi.AccessException"},
	{}
};

$InnerClassInfo _RegistryImpl_InnerClassesInfo_[] = {
	{"sun.rmi.registry.RegistryImpl$6", nullptr, nullptr, 0},
	{"sun.rmi.registry.RegistryImpl$5", nullptr, nullptr, 0},
	{"sun.rmi.registry.RegistryImpl$4", nullptr, nullptr, 0},
	{"sun.rmi.registry.RegistryImpl$3", nullptr, nullptr, 0},
	{"sun.rmi.registry.RegistryImpl$2", nullptr, nullptr, 0},
	{"sun.rmi.registry.RegistryImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RegistryImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.registry.RegistryImpl",
	"java.rmi.server.RemoteServer",
	"java.rmi.registry.Registry",
	_RegistryImpl_FieldInfo_,
	_RegistryImpl_MethodInfo_,
	nullptr,
	nullptr,
	_RegistryImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.registry.RegistryImpl$6,sun.rmi.registry.RegistryImpl$5,sun.rmi.registry.RegistryImpl$4,sun.rmi.registry.RegistryImpl$3,sun.rmi.registry.RegistryImpl$2,sun.rmi.registry.RegistryImpl$1"
};

$Object* allocate$RegistryImpl($Class* clazz) {
	return $of($alloc(RegistryImpl));
}

int32_t RegistryImpl::hashCode() {
	 return this->$RemoteServer::hashCode();
}

bool RegistryImpl::equals(Object$* obj) {
	 return this->$RemoteServer::equals(obj);
}

$String* RegistryImpl::toString() {
	 return this->$RemoteServer::toString();
}

$Object* RegistryImpl::clone() {
	 return this->$RemoteServer::clone();
}

void RegistryImpl::finalize() {
	this->$RemoteServer::finalize();
}

$Hashtable* RegistryImpl::allowedAccessCache = nullptr;
RegistryImpl* RegistryImpl::registry = nullptr;
$ObjID* RegistryImpl::id = nullptr;
$ResourceBundle* RegistryImpl::resources = nullptr;
$String* RegistryImpl::REGISTRY_FILTER_PROPNAME = nullptr;
$ObjectInputFilter* RegistryImpl::registryFilter$ = nullptr;

$ObjectInputFilter* RegistryImpl::initRegistryFilter() {
	$init(RegistryImpl);
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputFilter, filter, nullptr);
	$var($String, props, $System::getProperty(RegistryImpl::REGISTRY_FILTER_PROPNAME));
	if (props == nullptr) {
		$assign(props, $Security::getProperty(RegistryImpl::REGISTRY_FILTER_PROPNAME));
	}
	if (props != nullptr) {
		$assign(filter, $nc($($SharedSecrets::getJavaObjectInputFilterAccess()))->createFilter2(props));
		$var($Log, regLog, $Log::getLog("sun.rmi.registry"_s, "registry"_s, -1));
		if ($nc(regLog)->isLoggable($Log::BRIEF)) {
			regLog->log($Log::BRIEF, $$str({"registryFilter = "_s, filter}));
		}
	}
	return filter;
}

void RegistryImpl::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	RegistryImpl::init$(port, csf, ssf, static_cast<$ObjectInputFilter*>($$new(RegistryImpl$$Lambda$registryFilter$1)));
}

void RegistryImpl::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf, $ObjectInputFilter* serialFilter) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$RemoteServer::init$();
	$set(this, bindings, $new($Hashtable, 101));
	if (port == $Registry::REGISTRY_PORT && $System::getSecurityManager() != nullptr) {
		try {
			$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($RegistryImpl$1, this, port, csf, ssf, serialFilter)));
			$AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($SocketPermission, $$str({"localhost:"_s, $$str(port)}), "listen,accept"_s))}));
		} catch ($PrivilegedActionException& pae) {
			$throw($cast($RemoteException, $(pae->getException())));
		}
	} else {
		$var($LiveRef, lref, $new($LiveRef, RegistryImpl::id, port, csf, ssf));
		setup($$new($UnicastServerRef2, lref, serialFilter));
	}
}

void RegistryImpl::init$(int32_t port) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$RemoteServer::init$();
	$set(this, bindings, $new($Hashtable, 101));
	if (port == $Registry::REGISTRY_PORT && $System::getSecurityManager() != nullptr) {
		try {
			$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($RegistryImpl$2, this, port)));
			$AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($SocketPermission, $$str({"localhost:"_s, $$str(port)}), "listen,accept"_s))}));
		} catch ($PrivilegedActionException& pae) {
			$throw($cast($RemoteException, $(pae->getException())));
		}
	} else {
		$var($LiveRef, lref, $new($LiveRef, RegistryImpl::id, port));
		setup($$new($UnicastServerRef, lref, static_cast<$ObjectInputFilter*>($$new(RegistryImpl$$Lambda$registryFilter$1))));
	}
}

void RegistryImpl::setup($UnicastServerRef* uref) {
	$set(this, ref, static_cast<$RemoteRef*>(static_cast<$UnicastRef*>(uref)));
	$nc(uref)->exportObject(static_cast<$Remote*>(static_cast<$RemoteObject*>(static_cast<$RemoteServer*>(this))), nullptr, true);
}

$Remote* RegistryImpl::lookup($String* name) {
	$synchronized(this->bindings) {
		$var($Remote, obj, $cast($Remote, $nc(this->bindings)->get(name)));
		if (obj == nullptr) {
			$throwNew($NotBoundException, name);
		}
		return obj;
	}
}

void RegistryImpl::bind($String* name, $Remote* obj) {
	$synchronized(this->bindings) {
		$var($Remote, curr, $cast($Remote, $nc(this->bindings)->get(name)));
		if (curr != nullptr) {
			$throwNew($AlreadyBoundException, name);
		}
		$nc(this->bindings)->put(name, obj);
	}
}

void RegistryImpl::unbind($String* name) {
	$synchronized(this->bindings) {
		$var($Remote, obj, $cast($Remote, $nc(this->bindings)->get(name)));
		if (obj == nullptr) {
			$throwNew($NotBoundException, name);
		}
		$nc(this->bindings)->remove(name);
	}
}

void RegistryImpl::rebind($String* name, $Remote* obj) {
	$nc(this->bindings)->put(name, obj);
}

$StringArray* RegistryImpl::list() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, names, nullptr);
	$synchronized(this->bindings) {
		int32_t i = $nc(this->bindings)->size();
		$assign(names, $new($StringArray, i));
		$var($Enumeration, enum_, $nc(this->bindings)->keys());
		while ((--i) >= 0) {
			names->set(i, $cast($String, $($nc(enum_)->nextElement())));
		}
	}
	return names;
}

void RegistryImpl::checkAccess($String* op) {
	$init(RegistryImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($String, clientHostName, getClientHost());
		$var($InetAddress, clientHost, nullptr);
		try {
			$assign(clientHost, $cast($InetAddress, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($RegistryImpl$3, clientHostName)))));
		} catch ($PrivilegedActionException& pae) {
			$throw($cast($UnknownHostException, $(pae->getException())));
		}
		if ($nc(RegistryImpl::allowedAccessCache)->get(clientHost) == nullptr) {
			if ($nc(clientHost)->isAnyLocalAddress()) {
				$throwNew($AccessException, $$str({op, " disallowed; origin unknown"_s}));
			}
			try {
				$var($InetAddress, finalClientHost, clientHost);
				$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($RegistryImpl$4, finalClientHost)));
			} catch ($PrivilegedActionException& pae) {
				$throwNew($AccessException, $$str({op, " disallowed; origin "_s, clientHost, " is non-local host"_s}));
			}
		}
	} catch ($ServerNotActiveException& ex) {
	} catch ($UnknownHostException& ex) {
		$throwNew($AccessException, $$str({op, " disallowed; origin is unknown host"_s}));
	}
}

$ObjID* RegistryImpl::getID() {
	$init(RegistryImpl);
	return RegistryImpl::id;
}

$String* RegistryImpl::getTextResource($String* key) {
	$init(RegistryImpl);
	$beforeCallerSensitive();
	if (RegistryImpl::resources == nullptr) {
		try {
			$assignStatic(RegistryImpl::resources, $ResourceBundle::getBundle("sun.rmi.registry.resources.rmiregistry"_s));
		} catch ($MissingResourceException& mre) {
		}
		if (RegistryImpl::resources == nullptr) {
			return ($str({"[missing resource file: "_s, key, "]"_s}));
		}
	}
	$var($String, val, nullptr);
	try {
		$assign(val, $nc(RegistryImpl::resources)->getString(key));
	} catch ($MissingResourceException& mre) {
	}
	if (val == nullptr) {
		return ($str({"[missing resource: "_s, key, "]"_s}));
	} else {
		return (val);
	}
}

$URLArray* RegistryImpl::pathToURLs($String* path) {
	$init(RegistryImpl);
	$useLocalCurrentObjectStackCache();
	$var($List, paths, $new($ArrayList));
	{
		$init($File);
		$var($StringArray, arr$, $nc(path)->split($File::pathSeparator));
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, entry, arr$->get(i$));
			{
				$var($Path, p, $Paths::get(entry, $$new($StringArray, 0)));
				try {
					$assign(p, $nc(p)->toRealPath($$new($LinkOptionArray, 0)));
				} catch ($IOException& x) {
					$assign(p, $nc(p)->toAbsolutePath());
				}
				try {
					paths->add($($nc($($nc(p)->toUri()))->toURL()));
				} catch ($MalformedURLException& e) {
				}
			}
		}
	}
	return $fcast($URLArray, paths->toArray($$new($URLArray, 0)));
}

$ObjectInputFilter$Status* RegistryImpl::registryFilter($ObjectInputFilter$FilterInfo* filterInfo) {
	$init(RegistryImpl);
	if (RegistryImpl::registryFilter$ != nullptr) {
		$ObjectInputFilter$Status* status = $nc(RegistryImpl::registryFilter$)->checkInput(filterInfo);
		$init($ObjectInputFilter$Status);
		if (status != $ObjectInputFilter$Status::UNDECIDED) {
			return status;
		}
	}
	if ($nc(filterInfo)->depth() > RegistryImpl::REGISTRY_MAX_DEPTH) {
		$init($ObjectInputFilter$Status);
		return $ObjectInputFilter$Status::REJECTED;
	}
	$Class* clazz = $nc(filterInfo)->serialClass();
	if (clazz != nullptr) {
		if (clazz->isArray()) {
			bool var$0 = filterInfo->arrayLength() >= 0;
			$init($ObjectInputFilter$Status);
			return (var$0 && filterInfo->arrayLength() > RegistryImpl::REGISTRY_MAX_ARRAY_SIZE) ? $ObjectInputFilter$Status::REJECTED : $ObjectInputFilter$Status::UNDECIDED;
		}
		$load($Number);
		bool var$6 = $String::class$ == clazz || $Number::class$->isAssignableFrom(clazz);
		$load($Remote);
		bool var$5 = var$6 || $Remote::class$->isAssignableFrom(clazz);
		$load($Proxy);
		bool var$4 = var$5 || $Proxy::class$->isAssignableFrom(clazz);
		$load($UnicastRef);
		bool var$3 = var$4 || $UnicastRef::class$->isAssignableFrom(clazz);
		$load($RMIClientSocketFactory);
		bool var$2 = var$3 || $RMIClientSocketFactory::class$->isAssignableFrom(clazz);
		$load($RMIServerSocketFactory);
		bool var$1 = var$2 || $RMIServerSocketFactory::class$->isAssignableFrom(clazz);
		$load($UID);
		if (var$1 || $UID::class$->isAssignableFrom(clazz)) {
			$init($ObjectInputFilter$Status);
			return $ObjectInputFilter$Status::ALLOWED;
		} else {
			$init($ObjectInputFilter$Status);
			return $ObjectInputFilter$Status::REJECTED;
		}
	}
	$init($ObjectInputFilter$Status);
	return $ObjectInputFilter$Status::UNDECIDED;
}

RegistryImpl* RegistryImpl::createRegistry(int32_t regPort) {
	$init(RegistryImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($System::getSecurityManager() == nullptr) {
		$System::setSecurityManager($$new($SecurityManager));
	}
	$var($String, envcp, $System::getProperty("env.class.path"_s));
	if (envcp == nullptr) {
		$assign(envcp, "."_s);
	}
	$var($URLArray, urls, pathToURLs(envcp));
	$var($ClassLoader, cl, $new($URLClassLoader, urls));
	$LoaderHandler::registerCodebaseLoader(cl);
	$($Thread::currentThread())->setContextClassLoader(cl);
	$var(RegistryImpl, registryImpl, nullptr);
	try {
		$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($RegistryImpl$5, regPort)));
		$assign(registryImpl, $cast(RegistryImpl, $AccessController::doPrivileged(var$0, $(getAccessControlContext(regPort)))));
	} catch ($PrivilegedActionException& ex) {
		$throw($cast($RemoteException, $(ex->getException())));
	}
	return registryImpl;
}

void RegistryImpl::main($StringArray* args) {
	$init(RegistryImpl);
	$useLocalCurrentObjectStackCache();
	try {
		int32_t regPort = ($nc(args)->length >= 1) ? $Integer::parseInt($nc(args)->get(0)) : $Registry::REGISTRY_PORT;
		$assignStatic(RegistryImpl::registry, createRegistry(regPort));
		while (true) {
			try {
				$Thread::sleep($Long::MAX_VALUE);
			} catch ($InterruptedException& e) {
			}
		}
	} catch ($NumberFormatException& e) {
		$nc($System::err)->println($($MessageFormat::format($(getTextResource("rmiregistry.port.badnumber"_s)), $$new($ObjectArray, {$of($nc(args)->get(0))}))));
		$nc($System::err)->println($($MessageFormat::format($(getTextResource("rmiregistry.usage"_s)), $$new($ObjectArray, {$of("rmiregistry"_s)}))));
	} catch ($Exception& e) {
		e->printStackTrace();
	}
	$System::exit(1);
}

$AccessControlContext* RegistryImpl::getAccessControlContext(int32_t port) {
	$init(RegistryImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PermissionCollection, perms, $cast($PermissionCollection, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RegistryImpl$6)))));
	$nc(perms)->add($$new($SocketPermission, "*"_s, "connect,accept"_s));
	perms->add($$new($SocketPermission, $$str({"localhost:"_s, $$str(port)}), "listen,accept"_s));
	perms->add($$new($RuntimePermission, "accessClassInPackage.sun.jvmstat.*"_s));
	perms->add($$new($RuntimePermission, "accessClassInPackage.sun.jvm.hotspot.*"_s));
	perms->add($$new($FilePermission, "<<ALL FILES>>"_s, "read"_s));
	$var($ProtectionDomain, pd, $new($ProtectionDomain, $$new($CodeSource, ($URL*)nullptr, ($CertificateArray*)nullptr), perms));
	return $new($AccessControlContext, $$new($ProtectionDomainArray, {pd}));
}

void clinit$RegistryImpl($Class* class$) {
	$assignStatic(RegistryImpl::REGISTRY_FILTER_PROPNAME, "sun.rmi.registry.registryFilter"_s);
	$beforeCallerSensitive();
	$assignStatic(RegistryImpl::allowedAccessCache, $new($Hashtable, 3));
	$assignStatic(RegistryImpl::id, $new($ObjID, $ObjID::REGISTRY_ID));
	$assignStatic(RegistryImpl::resources, nullptr);
	$assignStatic(RegistryImpl::registryFilter$, $cast($ObjectInputFilter, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(RegistryImpl$$Lambda$initRegistryFilter)))));
}

RegistryImpl::RegistryImpl() {
}

$Class* RegistryImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RegistryImpl$$Lambda$initRegistryFilter::classInfo$.name)) {
			return RegistryImpl$$Lambda$initRegistryFilter::load$(name, initialize);
		}
		if (name->equals(RegistryImpl$$Lambda$registryFilter$1::classInfo$.name)) {
			return RegistryImpl$$Lambda$registryFilter$1::load$(name, initialize);
		}
	}
	$loadClass(RegistryImpl, name, initialize, &_RegistryImpl_ClassInfo_, clinit$RegistryImpl, allocate$RegistryImpl);
	return class$;
}

$Class* RegistryImpl::class$ = nullptr;

		} // registry
	} // rmi
} // sun