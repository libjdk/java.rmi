#include <sun/rmi/transport/DGCImpl_Skel.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/dgc/Lease.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/SkeletonMismatchException.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <jcpp.h>

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $OperationArray = $Array<::java::rmi::server::Operation>;
using $DataInput = ::java::io::DataInput;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MarshalException = ::java::rmi::MarshalException;
using $Remote = ::java::rmi::Remote;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $Lease = ::java::rmi::dgc::Lease;
using $VMID = ::java::rmi::dgc::VMID;
using $ObjID = ::java::rmi::server::ObjID;
using $Operation = ::java::rmi::server::Operation;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $Skeleton = ::java::rmi::server::Skeleton;
using $SkeletonMismatchException = ::java::rmi::server::SkeletonMismatchException;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCImpl_Skel_FieldInfo_[] = {
	{"operations", "[Ljava/rmi/server/Operation;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DGCImpl_Skel, operations)},
	{"interfaceHash", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DGCImpl_Skel, interfaceHash)},
	{}
};

$MethodInfo _DGCImpl_Skel_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(DGCImpl_Skel::*)()>(&DGCImpl_Skel::init$))},
	{"dispatch", "(Ljava/rmi/Remote;Ljava/rmi/server/RemoteCall;IJ)V", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"getOperations", "()[Ljava/rmi/server/Operation;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DGCImpl_Skel_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.transport.DGCImpl_Skel",
	"java.lang.Object",
	"java.rmi.server.Skeleton",
	_DGCImpl_Skel_FieldInfo_,
	_DGCImpl_Skel_MethodInfo_
};

$Object* allocate$DGCImpl_Skel($Class* clazz) {
	return $of($alloc(DGCImpl_Skel));
}

$OperationArray* DGCImpl_Skel::operations = nullptr;

void DGCImpl_Skel::init$() {
}

$OperationArray* DGCImpl_Skel::getOperations() {
	return $cast($OperationArray, $nc(DGCImpl_Skel::operations)->clone());
}

void DGCImpl_Skel::dispatch($Remote* obj, $RemoteCall* remoteCall, int32_t opnum, int64_t hash) {
	$useLocalCurrentObjectStackCache();
	if (hash != DGCImpl_Skel::interfaceHash) {
		$throwNew($SkeletonMismatchException, "interface hash mismatch"_s);
	}
	$var($DGCImpl, server, $cast($DGCImpl, obj));
	$var($StreamRemoteCall, call, $cast($StreamRemoteCall, remoteCall));
	switch (opnum) {
	case 0:
		{
			{
				$var($ObjIDArray, $param_arrayOf_ObjID_1, nullptr);
				int64_t $param_long_2 = 0;
				$var($VMID, $param_VMID_3, nullptr);
				bool $param_boolean_4 = false;
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							$var($ObjectInput, in, $nc(call)->getInputStream());
							$assign($param_arrayOf_ObjID_1, $cast($ObjIDArray, $nc(in)->readObject()));
							$param_long_2 = in->readLong();
							$assign($param_VMID_3, $cast($VMID, in->readObject()));
							$param_boolean_4 = in->readBoolean();
						} catch ($ClassCastException& e) {
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($IOException& e) {
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($ClassNotFoundException& e) {
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable& var$1) {
						$assign(var$0, var$1);
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
				$nc(server)->clean($param_arrayOf_ObjID_1, $param_long_2, $param_VMID_3, $param_boolean_4);
				try {
					call->getResultStream(true);
				} catch ($IOException& e) {
					$throwNew($MarshalException, "error marshalling return"_s, e);
				}
				break;
			}
		}
	case 1:
		{
			{
				$var($ObjIDArray, $param_arrayOf_ObjID_1, nullptr);
				int64_t $param_long_2 = 0;
				$var($Lease, $param_Lease_3, nullptr);
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							$var($ObjectInput, in, $nc(call)->getInputStream());
							$assign($param_arrayOf_ObjID_1, $cast($ObjIDArray, $nc(in)->readObject()));
							$param_long_2 = in->readLong();
							$assign($param_Lease_3, $cast($Lease, in->readObject()));
						} catch ($ClassCastException& e) {
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($IOException& e) {
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($ClassNotFoundException& e) {
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable& var$3) {
						$assign(var$2, var$3);
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
				$var($Lease, $result, $nc(server)->dirty($param_arrayOf_ObjID_1, $param_long_2, $param_Lease_3));
				try {
					$var($ObjectOutput, out, call->getResultStream(true));
					$nc(out)->writeObject($result);
				} catch ($IOException& e) {
					$throwNew($MarshalException, "error marshalling return"_s, e);
				}
				break;
			}
		}
	default:
		{
			$throwNew($UnmarshalException, "invalid method number"_s);
		}
	}
}

void clinit$DGCImpl_Skel($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DGCImpl_Skel::operations, $new($OperationArray, {
		$$new($Operation, "void clean(java.rmi.server.ObjID[], long, java.rmi.dgc.VMID, boolean)"_s),
		$$new($Operation, "java.rmi.dgc.Lease dirty(java.rmi.server.ObjID[], long, java.rmi.dgc.Lease)"_s)
	}));
}

DGCImpl_Skel::DGCImpl_Skel() {
}

$Class* DGCImpl_Skel::load$($String* name, bool initialize) {
	$loadClass(DGCImpl_Skel, name, initialize, &_DGCImpl_Skel_ClassInfo_, clinit$DGCImpl_Skel, allocate$DGCImpl_Skel);
	return class$;
}

$Class* DGCImpl_Skel::class$ = nullptr;

		} // transport
	} // rmi
} // sun