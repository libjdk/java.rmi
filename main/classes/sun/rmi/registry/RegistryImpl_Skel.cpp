#include <sun/rmi/registry/RegistryImpl_Skel.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutput.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/SkeletonMismatchException.h>
#include <jdk/internal/access/JavaObjectInputStreamReadString.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <jcpp.h>

using $OperationArray = $Array<::java::rmi::server::Operation>;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputStream = ::java::io::ObjectInputStream;
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
using $Operation = ::java::rmi::server::Operation;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $Skeleton = ::java::rmi::server::Skeleton;
using $SkeletonMismatchException = ::java::rmi::server::SkeletonMismatchException;
using $JavaObjectInputStreamReadString = ::jdk::internal::access::JavaObjectInputStreamReadString;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $RegistryImpl = ::sun::rmi::registry::RegistryImpl;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;

namespace sun {
	namespace rmi {
		namespace registry {

$FieldInfo _RegistryImpl_Skel_FieldInfo_[] = {
	{"operations", "[Ljava/rmi/server/Operation;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RegistryImpl_Skel, operations)},
	{"interfaceHash", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RegistryImpl_Skel, interfaceHash)},
	{}
};

$MethodInfo _RegistryImpl_Skel_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl_Skel::*)()>(&RegistryImpl_Skel::init$))},
	{"dispatch", "(Ljava/rmi/Remote;Ljava/rmi/server/RemoteCall;IJ)V", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"getOperations", "()[Ljava/rmi/server/Operation;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _RegistryImpl_Skel_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.registry.RegistryImpl_Skel",
	"java.lang.Object",
	"java.rmi.server.Skeleton",
	_RegistryImpl_Skel_FieldInfo_,
	_RegistryImpl_Skel_MethodInfo_
};

$Object* allocate$RegistryImpl_Skel($Class* clazz) {
	return $of($alloc(RegistryImpl_Skel));
}

$OperationArray* RegistryImpl_Skel::operations = nullptr;

void RegistryImpl_Skel::init$() {
}

$OperationArray* RegistryImpl_Skel::getOperations() {
	return $cast($OperationArray, $nc(RegistryImpl_Skel::operations)->clone());
}

void RegistryImpl_Skel::dispatch($Remote* obj, $RemoteCall* remoteCall, int32_t opnum, int64_t hash) {
	if (opnum < 0) {
		if (hash == (int64_t)0x693FB79BBB53CEFE) {
			opnum = 0;
		} else if (hash == (int64_t)0x23AF58BBE96D7C34) {
			opnum = 1;
		} else if (hash == (int64_t)0x97614F3F477A89C7) {
			opnum = 2;
		} else if (hash == (int64_t)0x8BADB4AE7C9FED0E) {
			opnum = 3;
		} else if (hash == (int64_t)0x6560A7A458D70A7A) {
			opnum = 4;
		} else {
			$throwNew($UnmarshalException, "invalid method hash"_s);
		}
	} else if (hash != RegistryImpl_Skel::interfaceHash) {
		$throwNew($SkeletonMismatchException, "interface hash mismatch"_s);
	}
	$var($RegistryImpl, server, $cast($RegistryImpl, obj));
	$var($StreamRemoteCall, call, $cast($StreamRemoteCall, remoteCall));
	switch (opnum) {
	case 0:
		{
			{
				$RegistryImpl::checkAccess("Registry.bind"_s);
				$var($String, $param_String_1, nullptr);
				$var($Remote, $param_Remote_2, nullptr);
				{
					$var($Throwable, var$0, nullptr);
					try {
						try {
							$var($ObjectInputStream, in, $cast($ObjectInputStream, $nc(call)->getInputStream()));
							$assign($param_String_1, $nc($($SharedSecrets::getJavaObjectInputStreamReadString()))->readString(in));
							$assign($param_Remote_2, $cast($Remote, $nc(in)->readObject()));
						} catch ($ClassCastException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($IOException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($ClassNotFoundException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable&) {
						$assign(var$0, $catch());
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$0 != nullptr) {
						$throw(var$0);
					}
				}
				$nc(server)->bind($param_String_1, $param_Remote_2);
				try {
					call->getResultStream(true);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
					$throwNew($MarshalException, "error marshalling return"_s, e);
				}
				break;
			}
		}
	case 1:
		{
			{
				$nc(call)->releaseInputStream();
				$var($StringArray, $result, $nc(server)->list());
				try {
					$var($ObjectOutput, out, call->getResultStream(true));
					$nc(out)->writeObject($result);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
					$throwNew($MarshalException, "error marshalling return"_s, e);
				}
				break;
			}
		}
	case 2:
		{
			{
				$var($String, $param_String_1, nullptr);
				{
					$var($Throwable, var$1, nullptr);
					try {
						try {
							$var($ObjectInputStream, in, $cast($ObjectInputStream, $nc(call)->getInputStream()));
							$assign($param_String_1, $nc($($SharedSecrets::getJavaObjectInputStreamReadString()))->readString(in));
						} catch ($ClassCastException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($IOException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable&) {
						$assign(var$1, $catch());
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
				$var($Remote, $result, $nc(server)->lookup($param_String_1));
				try {
					$var($ObjectOutput, out, call->getResultStream(true));
					$nc(out)->writeObject($result);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
					$throwNew($MarshalException, "error marshalling return"_s, e);
				}
				break;
			}
		}
	case 3:
		{
			{
				$RegistryImpl::checkAccess("Registry.rebind"_s);
				$var($String, $param_String_1, nullptr);
				$var($Remote, $param_Remote_2, nullptr);
				{
					$var($Throwable, var$2, nullptr);
					try {
						try {
							$var($ObjectInputStream, in, $cast($ObjectInputStream, $nc(call)->getInputStream()));
							$assign($param_String_1, $nc($($SharedSecrets::getJavaObjectInputStreamReadString()))->readString(in));
							$assign($param_Remote_2, $cast($Remote, $nc(in)->readObject()));
						} catch ($ClassCastException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($IOException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($ClassNotFoundException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable&) {
						$assign(var$2, $catch());
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
				}
				$nc(server)->rebind($param_String_1, $param_Remote_2);
				try {
					call->getResultStream(true);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
					$throwNew($MarshalException, "error marshalling return"_s, e);
				}
				break;
			}
		}
	case 4:
		{
			{
				$RegistryImpl::checkAccess("Registry.unbind"_s);
				$var($String, $param_String_1, nullptr);
				{
					$var($Throwable, var$3, nullptr);
					try {
						try {
							$var($ObjectInputStream, in, $cast($ObjectInputStream, $nc(call)->getInputStream()));
							$assign($param_String_1, $nc($($SharedSecrets::getJavaObjectInputStreamReadString()))->readString(in));
						} catch ($ClassCastException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						} catch ($IOException&) {
							$var($Exception, e, $catch());
							$nc(call)->discardPendingRefs();
							$throwNew($UnmarshalException, "error unmarshalling arguments"_s, e);
						}
					} catch ($Throwable&) {
						$assign(var$3, $catch());
					} /*finally*/ {
						$nc(call)->releaseInputStream();
					}
					if (var$3 != nullptr) {
						$throw(var$3);
					}
				}
				$nc(server)->unbind($param_String_1);
				try {
					call->getResultStream(true);
				} catch ($IOException&) {
					$var($IOException, e, $catch());
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

void clinit$RegistryImpl_Skel($Class* class$) {
	$assignStatic(RegistryImpl_Skel::operations, $new($OperationArray, {
		$$new($Operation, "void bind(java.lang.String, java.rmi.Remote)"_s),
		$$new($Operation, "java.lang.String list()[]"_s),
		$$new($Operation, "java.rmi.Remote lookup(java.lang.String)"_s),
		$$new($Operation, "void rebind(java.lang.String, java.rmi.Remote)"_s),
		$$new($Operation, "void unbind(java.lang.String)"_s)
	}));
}

RegistryImpl_Skel::RegistryImpl_Skel() {
}

$Class* RegistryImpl_Skel::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl_Skel, name, initialize, &_RegistryImpl_Skel_ClassInfo_, clinit$RegistryImpl_Skel, allocate$RegistryImpl_Skel);
	return class$;
}

$Class* RegistryImpl_Skel::class$ = nullptr;

		} // registry
	} // rmi
} // sun