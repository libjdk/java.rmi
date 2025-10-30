#include <sun/rmi/registry/RegistryImpl_Stub.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/rmi/AlreadyBoundException.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/NotBoundException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/UnexpectedException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteStub.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <jcpp.h>

using $OperationArray = $Array<::java::rmi::server::Operation>;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $AlreadyBoundException = ::java::rmi::AlreadyBoundException;
using $MarshalException = ::java::rmi::MarshalException;
using $NotBoundException = ::java::rmi::NotBoundException;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $UnexpectedException = ::java::rmi::UnexpectedException;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $Registry = ::java::rmi::registry::Registry;
using $Operation = ::java::rmi::server::Operation;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;

namespace sun {
	namespace rmi {
		namespace registry {

$FieldInfo _RegistryImpl_Stub_FieldInfo_[] = {
	{"operations", "[Ljava/rmi/server/Operation;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RegistryImpl_Stub, operations)},
	{"interfaceHash", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RegistryImpl_Stub, interfaceHash)},
	{}
};

$MethodInfo _RegistryImpl_Stub_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl_Stub::*)()>(&RegistryImpl_Stub::init$))},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PUBLIC, $method(static_cast<void(RegistryImpl_Stub::*)($RemoteRef*)>(&RegistryImpl_Stub::init$))},
	{"bind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC, nullptr, "java.rmi.AccessException,java.rmi.AlreadyBoundException,java.rmi.RemoteException"},
	{"list", "()[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.rmi.AccessException,java.rmi.RemoteException"},
	{"lookup", "(Ljava/lang/String;)Ljava/rmi/Remote;", nullptr, $PUBLIC, nullptr, "java.rmi.AccessException,java.rmi.NotBoundException,java.rmi.RemoteException"},
	{"rebind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC, nullptr, "java.rmi.AccessException,java.rmi.RemoteException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unbind", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.rmi.AccessException,java.rmi.NotBoundException,java.rmi.RemoteException"},
	{}
};

$ClassInfo _RegistryImpl_Stub_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.rmi.registry.RegistryImpl_Stub",
	"java.rmi.server.RemoteStub",
	"java.rmi.registry.Registry",
	_RegistryImpl_Stub_FieldInfo_,
	_RegistryImpl_Stub_MethodInfo_
};

$Object* allocate$RegistryImpl_Stub($Class* clazz) {
	return $of($alloc(RegistryImpl_Stub));
}

int32_t RegistryImpl_Stub::hashCode() {
	 return this->$RemoteStub::hashCode();
}

bool RegistryImpl_Stub::equals(Object$* obj) {
	 return this->$RemoteStub::equals(obj);
}

$String* RegistryImpl_Stub::toString() {
	 return this->$RemoteStub::toString();
}

$Object* RegistryImpl_Stub::clone() {
	 return this->$RemoteStub::clone();
}

void RegistryImpl_Stub::finalize() {
	this->$RemoteStub::finalize();
}

$OperationArray* RegistryImpl_Stub::operations = nullptr;

void RegistryImpl_Stub::init$() {
	$RemoteStub::init$();
}

void RegistryImpl_Stub::init$($RemoteRef* ref) {
	$RemoteStub::init$(ref);
}

void RegistryImpl_Stub::bind($String* $param_String_1, $Remote* $param_Remote_2) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(this, RegistryImpl_Stub::operations, 0, RegistryImpl_Stub::interfaceHash)));
		try {
			$var($ObjectOutput, out, $nc(call)->getOutputStream());
			$nc(out)->writeObject($param_String_1);
			out->writeObject($param_Remote_2);
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshalling arguments"_s, e);
		}
		$nc(this->ref)->invoke(call);
		$nc(this->ref)->done(call);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($AlreadyBoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

$StringArray* RegistryImpl_Stub::list() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(this, RegistryImpl_Stub::operations, 1, RegistryImpl_Stub::interfaceHash)));
		$nc(this->ref)->invoke(call);
		$var($StringArray, $result, nullptr);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ObjectInput, in, $nc(call)->getInputStream());
					$assign($result, $cast($StringArray, $nc(in)->readObject()));
				} catch ($ClassCastException& e) {
					$nc(call)->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				} catch ($IOException& e) {
					$nc(call)->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				} catch ($ClassNotFoundException& e) {
					$nc(call)->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->ref)->done(call);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		return $result;
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

$Remote* RegistryImpl_Stub::lookup($String* $param_String_1) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(this, RegistryImpl_Stub::operations, 2, RegistryImpl_Stub::interfaceHash)));
		try {
			$var($ObjectOutput, out, $nc(call)->getOutputStream());
			$nc(out)->writeObject($param_String_1);
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshalling arguments"_s, e);
		}
		$nc(this->ref)->invoke(call);
		$var($Remote, $result, nullptr);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ObjectInput, in, $nc(call)->getInputStream());
					$assign($result, $cast($Remote, $nc(in)->readObject()));
				} catch ($ClassCastException& e) {
					$nc(call)->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				} catch ($IOException& e) {
					$nc(call)->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				} catch ($ClassNotFoundException& e) {
					$nc(call)->discardPendingRefs();
					$throwNew($UnmarshalException, "error unmarshalling return"_s, e);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->ref)->done(call);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
		return $result;
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($NotBoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
	$shouldNotReachHere();
}

void RegistryImpl_Stub::rebind($String* $param_String_1, $Remote* $param_Remote_2) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(this, RegistryImpl_Stub::operations, 3, RegistryImpl_Stub::interfaceHash)));
		try {
			$var($ObjectOutput, out, $nc(call)->getOutputStream());
			$nc(out)->writeObject($param_String_1);
			out->writeObject($param_Remote_2);
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshalling arguments"_s, e);
		}
		$nc(this->ref)->invoke(call);
		$nc(this->ref)->done(call);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

void RegistryImpl_Stub::unbind($String* $param_String_1) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($StreamRemoteCall, call, $cast($StreamRemoteCall, $nc(this->ref)->newCall(this, RegistryImpl_Stub::operations, 4, RegistryImpl_Stub::interfaceHash)));
		try {
			$var($ObjectOutput, out, $nc(call)->getOutputStream());
			$nc(out)->writeObject($param_String_1);
		} catch ($IOException& e) {
			$throwNew($MarshalException, "error marshalling arguments"_s, e);
		}
		$nc(this->ref)->invoke(call);
		$nc(this->ref)->done(call);
	} catch ($RuntimeException& e) {
		$throw(e);
	} catch ($RemoteException& e) {
		$throw(e);
	} catch ($NotBoundException& e) {
		$throw(e);
	} catch ($Exception& e) {
		$throwNew($UnexpectedException, "undeclared checked exception"_s, e);
	}
}

void clinit$RegistryImpl_Stub($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(RegistryImpl_Stub::operations, $new($OperationArray, {
		$$new($Operation, "void bind(java.lang.String, java.rmi.Remote)"_s),
		$$new($Operation, "java.lang.String list()[]"_s),
		$$new($Operation, "java.rmi.Remote lookup(java.lang.String)"_s),
		$$new($Operation, "void rebind(java.lang.String, java.rmi.Remote)"_s),
		$$new($Operation, "void unbind(java.lang.String)"_s)
	}));
}

RegistryImpl_Stub::RegistryImpl_Stub() {
}

$Class* RegistryImpl_Stub::load$($String* name, bool initialize) {
	$loadClass(RegistryImpl_Stub, name, initialize, &_RegistryImpl_Stub_ClassInfo_, clinit$RegistryImpl_Stub, allocate$RegistryImpl_Stub);
	return class$;
}

$Class* RegistryImpl_Stub::class$ = nullptr;

		} // registry
	} // rmi
} // sun