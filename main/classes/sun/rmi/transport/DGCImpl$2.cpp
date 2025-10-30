#include <sun/rmi/transport/DGCImpl$2.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/SocketPermission.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/dgc/DGC.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/transport/DGCImpl$2$1.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/Target.h>
#include <jcpp.h>

#undef DGC_ID

using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $IOException = ::java::io::IOException;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SocketPermission = ::java::net::SocketPermission;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $DGC = ::java::rmi::dgc::DGC;
using $ObjID = ::java::rmi::server::ObjID;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $Util = ::sun::rmi::server::Util;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $DGCImpl$2$1 = ::sun::rmi::transport::DGCImpl$2$1;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;
using $Target = ::sun::rmi::transport::Target;

namespace sun {
	namespace rmi {
		namespace transport {

class DGCImpl$2$$Lambda$checkInput : public $ObjectInputFilter {
	$class(DGCImpl$2$$Lambda$checkInput, $NO_CLASS_INIT, $ObjectInputFilter)
public:
	void init$() {
	}
	virtual $ObjectInputFilter$Status* checkInput($ObjectInputFilter$FilterInfo* filterInfo) override {
		 return $DGCImpl::checkInput(filterInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCImpl$2$$Lambda$checkInput>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCImpl$2$$Lambda$checkInput::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl$2$$Lambda$checkInput::*)()>(&DGCImpl$2$$Lambda$checkInput::init$))},
	{"checkInput", "(Ljava/io/ObjectInputFilter$FilterInfo;)Ljava/io/ObjectInputFilter$Status;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCImpl$2$$Lambda$checkInput::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCImpl$2$$Lambda$checkInput",
	"java.lang.Object",
	"java.io.ObjectInputFilter",
	nullptr,
	methodInfos
};
$Class* DGCImpl$2$$Lambda$checkInput::load$($String* name, bool initialize) {
	$loadClass(DGCImpl$2$$Lambda$checkInput, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCImpl$2$$Lambda$checkInput::class$ = nullptr;

$MethodInfo _DGCImpl$2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(DGCImpl$2::*)()>(&DGCImpl$2::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _DGCImpl$2_EnclosingMethodInfo_ = {
	"sun.rmi.transport.DGCImpl",
	nullptr,
	nullptr
};

$InnerClassInfo _DGCImpl$2_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCImpl$2", nullptr, nullptr, 0},
	{"sun.rmi.transport.DGCImpl$2$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DGCImpl$2_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCImpl$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_DGCImpl$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_DGCImpl$2_EnclosingMethodInfo_,
	_DGCImpl$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCImpl"
};

$Object* allocate$DGCImpl$2($Class* clazz) {
	return $of($alloc(DGCImpl$2));
}

void DGCImpl$2::init$() {
}

$Object* DGCImpl$2::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, savedCcl, $($Thread::currentThread())->getContextClassLoader());
	{
		$var($Throwable, var$0, nullptr);
		try {
			$($Thread::currentThread())->setContextClassLoader($($ClassLoader::getSystemClassLoader()));
			try {
				$init($DGCImpl);
				$assignStatic($DGCImpl::dgc, $new($DGCImpl));
				$var($ObjID, dgcID, $new($ObjID, $ObjID::DGC_ID));
				$var($LiveRef, ref, $new($LiveRef, dgcID, 0));
				$var($UnicastServerRef, disp, $new($UnicastServerRef, ref, static_cast<$ObjectInputFilter*>($$new(DGCImpl$2$$Lambda$checkInput))));
				$var($Remote, stub, $Util::createProxy($DGCImpl::class$, $$new($UnicastRef, ref), true));
				disp->setSkeleton($DGCImpl::dgc);
				$var($Permissions, perms, $new($Permissions));
				perms->add($$new($SocketPermission, "*"_s, "accept,resolve"_s));
				$var($ProtectionDomainArray, pd, $new($ProtectionDomainArray, {$$new($ProtectionDomain, nullptr, perms)}));
				$var($AccessControlContext, acceptAcc, $new($AccessControlContext, pd));
				$var($Target, target, $cast($Target, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($DGCImpl$2$1, this, disp, stub, dgcID)), acceptAcc)));
				$ObjectTable::putTarget(target);
			} catch ($RemoteException& e) {
				$throwNew($Error, "exception initializing server-side DGC"_s, e);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$($Thread::currentThread())->setContextClassLoader(savedCcl);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	return $of(nullptr);
}

DGCImpl$2::DGCImpl$2() {
}

$Class* DGCImpl$2::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DGCImpl$2$$Lambda$checkInput::classInfo$.name)) {
			return DGCImpl$2$$Lambda$checkInput::load$(name, initialize);
		}
	}
	$loadClass(DGCImpl$2, name, initialize, &_DGCImpl$2_ClassInfo_, allocate$DGCImpl$2);
	return class$;
}

$Class* DGCImpl$2::class$ = nullptr;

		} // transport
	} // rmi
} // sun