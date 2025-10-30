#include <java/rmi/server/RemoteObjectInvocationHandler.h>

#include <java/io/IOException.h>
#include <java/io/InvalidObjectException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Proxy.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/UnexpectedException.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/util/Map.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $InvocationHandler = ::java::lang::reflect::InvocationHandler;
using $Method = ::java::lang::reflect::Method;
using $Proxy = ::java::lang::reflect::Proxy;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $UnexpectedException = ::java::rmi::UnexpectedException;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteObjectInvocationHandler$MethodToHash_Maps = ::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $Map = ::java::util::Map;
using $WeakClassHashMap = ::sun::rmi::server::WeakClassHashMap;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _RemoteObjectInvocationHandler_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RemoteObjectInvocationHandler, serialVersionUID)},
	{"methodToHash_Maps", "Ljava/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(RemoteObjectInvocationHandler, methodToHash_Maps)},
	{}
};

$MethodInfo _RemoteObjectInvocationHandler_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PUBLIC, $method(static_cast<void(RemoteObjectInvocationHandler::*)($RemoteRef*)>(&RemoteObjectInvocationHandler::init$))},
	{"getMethodHash", "(Ljava/lang/reflect/Method;)J", nullptr, $PRIVATE | $STATIC, $method(static_cast<int64_t(*)($Method*)>(&RemoteObjectInvocationHandler::getMethodHash))},
	{"invoke", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.Throwable"},
	{"invokeObjectMethod", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(RemoteObjectInvocationHandler::*)(Object$*,$Method*,$ObjectArray*)>(&RemoteObjectInvocationHandler::invokeObjectMethod))},
	{"invokeRemoteMethod", "(Ljava/lang/Object;Ljava/lang/reflect/Method;[Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(RemoteObjectInvocationHandler::*)(Object$*,$Method*,$ObjectArray*)>(&RemoteObjectInvocationHandler::invokeRemoteMethod)), "java.lang.Exception"},
	{"proxyToString", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(RemoteObjectInvocationHandler::*)(Object$*)>(&RemoteObjectInvocationHandler::proxyToString))},
	{"readObjectNoData", "()V", nullptr, $PRIVATE, $method(static_cast<void(RemoteObjectInvocationHandler::*)()>(&RemoteObjectInvocationHandler::readObjectNoData)), "java.io.InvalidObjectException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _RemoteObjectInvocationHandler_InnerClassesInfo_[] = {
	{"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps", "java.rmi.server.RemoteObjectInvocationHandler", "MethodToHash_Maps", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _RemoteObjectInvocationHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.RemoteObjectInvocationHandler",
	"java.rmi.server.RemoteObject",
	"java.lang.reflect.InvocationHandler",
	_RemoteObjectInvocationHandler_FieldInfo_,
	_RemoteObjectInvocationHandler_MethodInfo_,
	nullptr,
	nullptr,
	_RemoteObjectInvocationHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps,java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps$1"
};

$Object* allocate$RemoteObjectInvocationHandler($Class* clazz) {
	return $of($alloc(RemoteObjectInvocationHandler));
}

int32_t RemoteObjectInvocationHandler::hashCode() {
	 return this->$RemoteObject::hashCode();
}

bool RemoteObjectInvocationHandler::equals(Object$* obj) {
	 return this->$RemoteObject::equals(obj);
}

$String* RemoteObjectInvocationHandler::toString() {
	 return this->$RemoteObject::toString();
}

$Object* RemoteObjectInvocationHandler::clone() {
	 return this->$RemoteObject::clone();
}

void RemoteObjectInvocationHandler::finalize() {
	this->$RemoteObject::finalize();
}

$RemoteObjectInvocationHandler$MethodToHash_Maps* RemoteObjectInvocationHandler::methodToHash_Maps = nullptr;

void RemoteObjectInvocationHandler::init$($RemoteRef* ref) {
	$RemoteObject::init$(ref);
	if (ref == nullptr) {
		$throwNew($NullPointerException);
	}
}

$Object* RemoteObjectInvocationHandler::invoke(Object$* proxy, $Method* method, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!$Proxy::isProxyClass($nc($of(proxy))->getClass())) {
		$throwNew($IllegalArgumentException, "not a proxy"_s);
	}
	if (!$equals($Proxy::getInvocationHandler(proxy), this)) {
		$throwNew($IllegalArgumentException, "handler mismatch"_s);
	}
	if ($nc(method)->getDeclaringClass() == $Object::class$) {
		return $of(invokeObjectMethod(proxy, method, args));
	} else {
		bool var$1 = "finalize"_s->equals($(method->getName()));
		if (var$1 && method->getParameterCount() == 0) {
			return $of(nullptr);
		} else {
			return $of(invokeRemoteMethod(proxy, method, args));
		}
	}
}

$Object* RemoteObjectInvocationHandler::invokeObjectMethod(Object$* proxy, $Method* method, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, name, $nc(method)->getName());
	if ($nc(name)->equals("hashCode"_s)) {
		return $of($Integer::valueOf(hashCode()));
	} else if (name->equals("equals"_s)) {
		$var($Object0, obj, $nc(args)->get(0));
		$var($InvocationHandler, hdlr, nullptr);
		bool var$0 = $equals(proxy, obj);
		if (!var$0) {
			bool var$2 = obj != nullptr && $Proxy::isProxyClass($of(obj)->getClass());
			bool var$1 = var$2 && $instanceOf(RemoteObjectInvocationHandler, $assign(hdlr, $Proxy::getInvocationHandler(obj)));
			var$0 = (var$1 && this->equals(hdlr));
		}
		return $of($Boolean::valueOf(var$0));
	} else if (name->equals("toString"_s)) {
		return $of(proxyToString(proxy));
	} else {
		$throwNew($IllegalArgumentException, $$str({"unexpected Object method: "_s, method}));
	}
}

$Object* RemoteObjectInvocationHandler::invokeRemoteMethod(Object$* proxy, $Method* method$renamed, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($Method, method, method$renamed);
	$beforeCallerSensitive();
	try {
		if (!($instanceOf($Remote, proxy))) {
			$throwNew($IllegalArgumentException, "proxy not Remote instance"_s);
		}
		$Class* decl = $nc(method)->getDeclaringClass();
		$load($Remote);
		if (!$Remote::class$->isAssignableFrom(decl)) {
			$throwNew($RemoteException, $$str({"Method is not Remote: "_s, decl, "::"_s, method}));
		}
		return $of($nc(this->ref)->invoke($cast($Remote, proxy), method, args, getMethodHash(method)));
	} catch ($Exception& e) {
		if (!($instanceOf($RuntimeException, e))) {
			$Class* cl = $nc($of(proxy))->getClass();
			try {
				$var($String, var$0, $nc(method)->getName());
				$assign(method, $nc(cl)->getMethod(var$0, $(method->getParameterTypes())));
			} catch ($NoSuchMethodException& nsme) {
				$throw($cast($IllegalArgumentException, $($$new($IllegalArgumentException)->initCause(nsme))));
			}
			$Class* thrownType = $of(e)->getClass();
			{
				$var($ClassArray, arr$, $nc(method)->getExceptionTypes());
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$Class* declaredType = arr$->get(i$);
					{
						if ($nc(declaredType)->isAssignableFrom(thrownType)) {
							$throw(e);
						}
					}
				}
			}
			$assign(e, $new($UnexpectedException, "unexpected exception"_s, e));
		}
		$throw(e);
	}
	$shouldNotReachHere();
}

$String* RemoteObjectInvocationHandler::proxyToString(Object$* proxy) {
	$useLocalCurrentObjectStackCache();
	$var($ClassArray, interfaces, $nc($of(proxy))->getClass()->getInterfaces());
	if (interfaces->length == 0) {
		return $str({"Proxy["_s, this, "]"_s});
	}
	$var($String, iface, $nc(interfaces->get(0))->getName());
	if ($nc(iface)->equals("java.rmi.Remote"_s) && interfaces->length > 1) {
		$assign(iface, $nc(interfaces->get(1))->getName());
	}
	int32_t dot = $nc(iface)->lastIndexOf((int32_t)u'.');
	if (dot >= 0) {
		$assign(iface, iface->substring(dot + 1));
	}
	return $str({"Proxy["_s, iface, ","_s, this, "]"_s});
}

void RemoteObjectInvocationHandler::readObjectNoData() {
	$useLocalCurrentObjectStackCache();
	$throwNew($InvalidObjectException, $$str({"no data in stream; class: "_s, $($of(this)->getClass()->getName())}));
}

int64_t RemoteObjectInvocationHandler::getMethodHash($Method* method) {
	$init(RemoteObjectInvocationHandler);
	$useLocalCurrentObjectStackCache();
	return $nc(($cast($Long, $($nc(($cast($Map, $($nc(RemoteObjectInvocationHandler::methodToHash_Maps)->get($nc(method)->getDeclaringClass())))))->get(method)))))->longValue();
}

void clinit$RemoteObjectInvocationHandler($Class* class$) {
	$assignStatic(RemoteObjectInvocationHandler::methodToHash_Maps, $new($RemoteObjectInvocationHandler$MethodToHash_Maps));
}

RemoteObjectInvocationHandler::RemoteObjectInvocationHandler() {
}

$Class* RemoteObjectInvocationHandler::load$($String* name, bool initialize) {
	$loadClass(RemoteObjectInvocationHandler, name, initialize, &_RemoteObjectInvocationHandler_ClassInfo_, clinit$RemoteObjectInvocationHandler, allocate$RemoteObjectInvocationHandler);
	return class$;
}

$Class* RemoteObjectInvocationHandler::class$ = nullptr;

		} // server
	} // rmi
} // java