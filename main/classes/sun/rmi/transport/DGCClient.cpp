#include <sun/rmi/transport/DGCClient.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/SocketPermission.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ObjID.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/List.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <sun/rmi/transport/Endpoint.h>
#include <jcpp.h>

#undef DGC_ID
#undef MIN_VALUE
#undef SOCKET_ACC

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SocketPermission = ::java::net::SocketPermission;
using $VMID = ::java::rmi::dgc::VMID;
using $ObjID = ::java::rmi::server::ObjID;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $List = ::java::util::List;
using $DGCClient$EndpointEntry = ::sun::rmi::transport::DGCClient$EndpointEntry;
using $Endpoint = ::sun::rmi::transport::Endpoint;

namespace sun {
	namespace rmi {
		namespace transport {

class DGCClient$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(DGCClient$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCClient::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCClient$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCClient$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCClient$$Lambda$lambda$static$0::*)()>(&DGCClient$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCClient$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCClient$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCClient$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(DGCClient$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCClient$$Lambda$lambda$static$0::class$ = nullptr;

class DGCClient$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(DGCClient$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCClient::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCClient$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCClient$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCClient$$Lambda$lambda$static$1$1::*)()>(&DGCClient$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCClient$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCClient$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCClient$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(DGCClient$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCClient$$Lambda$lambda$static$1$1::class$ = nullptr;

class DGCClient$$Lambda$lambda$static$2$2 : public $PrivilegedAction {
	$class(DGCClient$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(DGCClient::lambda$static$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DGCClient$$Lambda$lambda$static$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo DGCClient$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCClient$$Lambda$lambda$static$2$2::*)()>(&DGCClient$$Lambda$lambda$static$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DGCClient$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.DGCClient$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* DGCClient$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(DGCClient$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DGCClient$$Lambda$lambda$static$2$2::class$ = nullptr;

$FieldInfo _DGCClient_FieldInfo_[] = {
	{"nextSequenceNum", "J", nullptr, $PRIVATE | $STATIC, $staticField(DGCClient, nextSequenceNum)},
	{"vmid", "Ljava/rmi/dgc/VMID;", nullptr, $PRIVATE | $STATIC, $staticField(DGCClient, vmid)},
	{"leaseValue", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCClient, leaseValue)},
	{"cleanInterval", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCClient, cleanInterval)},
	{"gcInterval", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCClient, gcInterval)},
	{"dirtyFailureRetries", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DGCClient, dirtyFailureRetries)},
	{"cleanFailureRetries", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DGCClient, cleanFailureRetries)},
	{"emptyObjIDArray", "[Ljava/rmi/server/ObjID;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCClient, emptyObjIDArray)},
	{"dgcID", "Ljava/rmi/server/ObjID;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCClient, dgcID)},
	{"SOCKET_ACC", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCClient, SOCKET_ACC)},
	{}
};

$MethodInfo _DGCClient_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(DGCClient::*)()>(&DGCClient::init$))},
	{"computeRenewTime", "(JJ)J", nullptr, $PRIVATE | $STATIC, $method(static_cast<int64_t(*)(int64_t,int64_t)>(&DGCClient::computeRenewTime))},
	{"getNextSequenceNum", "()J", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<int64_t(*)()>(&DGCClient::getNextSequenceNum))},
	{"lambda$static$0", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&DGCClient::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&DGCClient::lambda$static$1))},
	{"lambda$static$2", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&DGCClient::lambda$static$2))},
	{"registerRefs", "(Lsun/rmi/transport/Endpoint;Ljava/util/List;)V", "(Lsun/rmi/transport/Endpoint;Ljava/util/List<Lsun/rmi/transport/LiveRef;>;)V", $STATIC, $method(static_cast<void(*)($Endpoint*,$List*)>(&DGCClient::registerRefs))},
	{}
};

$InnerClassInfo _DGCClient_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DGCClient_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.rmi.transport.DGCClient",
	"java.lang.Object",
	nullptr,
	_DGCClient_FieldInfo_,
	_DGCClient_MethodInfo_,
	nullptr,
	nullptr,
	_DGCClient_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient$EndpointEntry,sun.rmi.transport.DGCClient$EndpointEntry$RefEntry,sun.rmi.transport.DGCClient$EndpointEntry$RefEntry$PhantomLiveRef,sun.rmi.transport.DGCClient$EndpointEntry$CleanRequest,sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread,sun.rmi.transport.DGCClient$EndpointEntry$1"
};

$Object* allocate$DGCClient($Class* clazz) {
	return $of($alloc(DGCClient));
}

int64_t DGCClient::nextSequenceNum = 0;
$VMID* DGCClient::vmid = nullptr;
int64_t DGCClient::leaseValue = 0;
int64_t DGCClient::cleanInterval = 0;
int64_t DGCClient::gcInterval = 0;
$ObjIDArray* DGCClient::emptyObjIDArray = nullptr;
$ObjID* DGCClient::dgcID = nullptr;
$AccessControlContext* DGCClient::SOCKET_ACC = nullptr;

void DGCClient::init$() {
}

void DGCClient::registerRefs($Endpoint* ep, $List* refs) {
	$init(DGCClient);
	$var($DGCClient$EndpointEntry, epEntry, nullptr);
	do {
		$assign(epEntry, $DGCClient$EndpointEntry::lookup(ep));
	} while (!$nc(epEntry)->registerRefs(refs));
}

int64_t DGCClient::getNextSequenceNum() {
	$load(DGCClient);
	$synchronized(class$) {
		$init(DGCClient);
		return DGCClient::nextSequenceNum++;
	}
}

int64_t DGCClient::computeRenewTime(int64_t grantTime, int64_t duration) {
	$init(DGCClient);
	return grantTime + (duration / 2);
}

$Long* DGCClient::lambda$static$2() {
	$init(DGCClient);
	return $Long::getLong("sun.rmi.dgc.client.gcInterval"_s, (int64_t)0x0036EE80);
}

$Long* DGCClient::lambda$static$1() {
	$init(DGCClient);
	return $Long::getLong("sun.rmi.dgc.cleanInterval"_s, (int64_t)0x0002BF20);
}

$Long* DGCClient::lambda$static$0() {
	$init(DGCClient);
	return $Long::getLong("java.rmi.dgc.leaseValue"_s, (int64_t)0x000927C0);
}

void clinit$DGCClient($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	DGCClient::nextSequenceNum = $Long::MIN_VALUE;
	$assignStatic(DGCClient::vmid, $new($VMID));
	DGCClient::leaseValue = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCClient$$Lambda$lambda$static$0)))))))->longValue();
	DGCClient::cleanInterval = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCClient$$Lambda$lambda$static$1$1)))))))->longValue();
	DGCClient::gcInterval = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(DGCClient$$Lambda$lambda$static$2$2)))))))->longValue();
	$assignStatic(DGCClient::emptyObjIDArray, $new($ObjIDArray, 0));
	$assignStatic(DGCClient::dgcID, $new($ObjID, $ObjID::DGC_ID));
	{
		$var($Permissions, perms, $new($Permissions));
		perms->add($$new($SocketPermission, "*"_s, "connect,resolve"_s));
		$var($ProtectionDomainArray, pd, $new($ProtectionDomainArray, {$$new($ProtectionDomain, nullptr, perms)}));
		$assignStatic(DGCClient::SOCKET_ACC, $new($AccessControlContext, pd));
	}
}

DGCClient::DGCClient() {
}

$Class* DGCClient::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DGCClient$$Lambda$lambda$static$0::classInfo$.name)) {
			return DGCClient$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(DGCClient$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return DGCClient$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(DGCClient$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return DGCClient$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
	}
	$loadClass(DGCClient, name, initialize, &_DGCClient_ClassInfo_, clinit$DGCClient, allocate$DGCClient);
	return class$;
}

$Class* DGCClient::class$ = nullptr;

		} // transport
	} // rmi
} // sun