#include <java/rmi/server/RemoteObject.h>

#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutput.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/Proxy.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/RemoteObjectInvocationHandler.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteStub.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <jcpp.h>

using $Externalizable = ::java::io::Externalizable;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $Proxy = ::java::lang::reflect::Proxy;
using $MarshalException = ::java::rmi::MarshalException;
using $Remote = ::java::rmi::Remote;
using $RemoteObjectInvocationHandler = ::java::rmi::server::RemoteObjectInvocationHandler;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $Util = ::sun::rmi::server::Util;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _RemoteObject_FieldInfo_[] = {
	{"ref", "Ljava/rmi/server/RemoteRef;", nullptr, $PROTECTED | $TRANSIENT, $field(RemoteObject, ref)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RemoteObject, serialVersionUID)},
	{}
};

$MethodInfo _RemoteObject_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(RemoteObject::*)()>(&RemoteObject::init$))},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PROTECTED, $method(static_cast<void(RemoteObject::*)($RemoteRef*)>(&RemoteObject::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getRef", "()Ljava/rmi/server/RemoteRef;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(RemoteObject::*)($ObjectInputStream*)>(&RemoteObject::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"toStub", "(Ljava/rmi/Remote;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Remote*)>(&RemoteObject::toStub)), "java.rmi.NoSuchObjectException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(RemoteObject::*)($ObjectOutputStream*)>(&RemoteObject::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _RemoteObject_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.rmi.server.RemoteObject",
	"java.lang.Object",
	"java.rmi.Remote,java.io.Serializable",
	_RemoteObject_FieldInfo_,
	_RemoteObject_MethodInfo_
};

$Object* allocate$RemoteObject($Class* clazz) {
	return $of($alloc(RemoteObject));
}

$Object* RemoteObject::clone() {
	 return this->$Remote::clone();
}

void RemoteObject::finalize() {
	this->$Remote::finalize();
}

void RemoteObject::init$() {
	$set(this, ref, nullptr);
}

void RemoteObject::init$($RemoteRef* newref) {
	$set(this, ref, newref);
}

$RemoteRef* RemoteObject::getRef() {
	return this->ref;
}

$Remote* RemoteObject::toStub($Remote* obj) {
	$init(RemoteObject);
	$beforeCallerSensitive();
	bool var$0 = $instanceOf($RemoteStub, obj);
	if (!var$0) {
		bool var$1 = obj != nullptr && $Proxy::isProxyClass($of(obj)->getClass());
		var$0 = (var$1 && $instanceOf($RemoteObjectInvocationHandler, $($Proxy::getInvocationHandler(obj))));
	}
	if (var$0) {
		return obj;
	} else {
		return $ObjectTable::getStub(obj);
	}
}

int32_t RemoteObject::hashCode() {
	return (this->ref == nullptr) ? $Remote::hashCode() : $nc(this->ref)->remoteHashCode();
}

bool RemoteObject::equals(Object$* obj) {
	if ($instanceOf(RemoteObject, obj)) {
		if (this->ref == nullptr) {
			return $equals(obj, this);
		} else {
			return $nc(this->ref)->remoteEquals($nc(($cast(RemoteObject, obj)))->ref);
		}
	} else if (obj != nullptr) {
		return $of(obj)->equals(this);
	} else {
		return false;
	}
}

$String* RemoteObject::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, classname, $Util::getUnqualifiedName($of(this)->getClass()));
	return (this->ref == nullptr) ? classname : $str({classname, "["_s, $($nc(this->ref)->remoteToString()), "]"_s});
}

void RemoteObject::writeObject($ObjectOutputStream* out) {
	if (this->ref == nullptr) {
		$throwNew($MarshalException, "Invalid remote object"_s);
	} else {
		$var($String, refClassName, $nc(this->ref)->getRefClass(out));
		if (refClassName == nullptr || $nc(refClassName)->length() == 0) {
			$nc(out)->writeUTF(""_s);
			out->writeObject(this->ref);
		} else {
			$nc(out)->writeUTF(refClassName);
			$nc(this->ref)->writeExternal(out);
		}
	}
}

void RemoteObject::readObject($ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, refClassName, $nc(in)->readUTF());
	if (refClassName == nullptr || $nc(refClassName)->length() == 0) {
		$set(this, ref, $cast($RemoteRef, in->readObject()));
	} else {
		$init($RemoteRef);
		$var($String, internalRefClassName, $str({$RemoteRef::packagePrefix, "."_s, refClassName}));
		$Class* refClass = $Class::forName(internalRefClassName);
		try {
			$var($Object, tmp, $nc(refClass)->newInstance());
			$set(this, ref, $cast($RemoteRef, tmp));
		} catch ($InstantiationException& e) {
			$throwNew($ClassNotFoundException, internalRefClassName, e);
		} catch ($IllegalAccessException& e) {
			$throwNew($ClassNotFoundException, internalRefClassName, e);
		} catch ($ClassCastException& e) {
			$throwNew($ClassNotFoundException, internalRefClassName, e);
		}
		$nc(this->ref)->readExternal(in);
	}
}

RemoteObject::RemoteObject() {
}

$Class* RemoteObject::load$($String* name, bool initialize) {
	$loadClass(RemoteObject, name, initialize, &_RemoteObject_ClassInfo_, allocate$RemoteObject);
	return class$;
}

$Class* RemoteObject::class$ = nullptr;

		} // server
	} // rmi
} // java