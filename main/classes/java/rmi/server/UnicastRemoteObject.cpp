#include <java/rmi/server/UnicastRemoteObject.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteServer.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/rmi/server/ServerCloneException.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/UnicastServerRef2.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $RemoteException = ::java::rmi::RemoteException;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $RemoteServer = ::java::rmi::server::RemoteServer;
using $RemoteStub = ::java::rmi::server::RemoteStub;
using $ServerCloneException = ::java::rmi::server::ServerCloneException;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $UnicastServerRef2 = ::sun::rmi::server::UnicastServerRef2;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;

namespace java {
	namespace rmi {
		namespace server {

$CompoundAttribute _UnicastRemoteObject_MethodAnnotations_exportObject4[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _UnicastRemoteObject_FieldInfo_[] = {
	{"port", "I", nullptr, $PRIVATE, $field(UnicastRemoteObject, port)},
	{"csf", "Ljava/rmi/server/RMIClientSocketFactory;", nullptr, $PRIVATE, $field(UnicastRemoteObject, csf)},
	{"ssf", "Ljava/rmi/server/RMIServerSocketFactory;", nullptr, $PRIVATE, $field(UnicastRemoteObject, ssf)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicastRemoteObject, serialVersionUID)},
	{}
};

$MethodInfo _UnicastRemoteObject_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(UnicastRemoteObject::*)()>(&UnicastRemoteObject::init$)), "java.rmi.RemoteException"},
	{"<init>", "(I)V", nullptr, $PROTECTED, $method(static_cast<void(UnicastRemoteObject::*)(int32_t)>(&UnicastRemoteObject::init$)), "java.rmi.RemoteException"},
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $PROTECTED, $method(static_cast<void(UnicastRemoteObject::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&UnicastRemoteObject::init$)), "java.rmi.RemoteException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.lang.CloneNotSupportedException"},
	{"exportObject", "(Ljava/rmi/Remote;)Ljava/rmi/server/RemoteStub;", nullptr, $PUBLIC | $STATIC | $DEPRECATED, $method(static_cast<$RemoteStub*(*)($Remote*)>(&UnicastRemoteObject::exportObject)), "java.rmi.RemoteException", nullptr, _UnicastRemoteObject_MethodAnnotations_exportObject4},
	{"exportObject", "(Ljava/rmi/Remote;I)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Remote*,int32_t)>(&UnicastRemoteObject::exportObject)), "java.rmi.RemoteException"},
	{"exportObject", "(Ljava/rmi/Remote;ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Remote*,int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&UnicastRemoteObject::exportObject)), "java.rmi.RemoteException"},
	{"exportObject", "(Ljava/rmi/Remote;ILjava/io/ObjectInputFilter;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Remote*,int32_t,$ObjectInputFilter*)>(&UnicastRemoteObject::exportObject)), "java.rmi.RemoteException"},
	{"exportObject", "(Ljava/rmi/Remote;ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/io/ObjectInputFilter;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($Remote*,int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*,$ObjectInputFilter*)>(&UnicastRemoteObject::exportObject)), "java.rmi.RemoteException"},
	{"exportObject", "(Ljava/rmi/Remote;Lsun/rmi/server/UnicastServerRef;)Ljava/rmi/Remote;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Remote*(*)($Remote*,$UnicastServerRef*)>(&UnicastRemoteObject::exportObject)), "java.rmi.RemoteException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(UnicastRemoteObject::*)($ObjectInputStream*)>(&UnicastRemoteObject::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"reexport", "()V", nullptr, $PRIVATE, $method(static_cast<void(UnicastRemoteObject::*)()>(&UnicastRemoteObject::reexport)), "java.rmi.RemoteException"},
	{"unexportObject", "(Ljava/rmi/Remote;Z)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($Remote*,bool)>(&UnicastRemoteObject::unexportObject)), "java.rmi.NoSuchObjectException"},
	{}
};

$ClassInfo _UnicastRemoteObject_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.rmi.server.UnicastRemoteObject",
	"java.rmi.server.RemoteServer",
	nullptr,
	_UnicastRemoteObject_FieldInfo_,
	_UnicastRemoteObject_MethodInfo_
};

$Object* allocate$UnicastRemoteObject($Class* clazz) {
	return $of($alloc(UnicastRemoteObject));
}

void UnicastRemoteObject::init$() {
	UnicastRemoteObject::init$(0);
}

void UnicastRemoteObject::init$(int32_t port) {
	$RemoteServer::init$();
	this->port = 0;
	$set(this, csf, nullptr);
	$set(this, ssf, nullptr);
	this->port = port;
	exportObject(static_cast<$Remote*>(this), port);
}

void UnicastRemoteObject::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	$RemoteServer::init$();
	this->port = 0;
	$set(this, csf, nullptr);
	$set(this, ssf, nullptr);
	this->port = port;
	$set(this, csf, csf);
	$set(this, ssf, ssf);
	exportObject(static_cast<$Remote*>(this), port, csf, ssf);
}

void UnicastRemoteObject::readObject($ObjectInputStream* in) {
	$nc(in)->defaultReadObject();
	reexport();
}

$Object* UnicastRemoteObject::clone() {
	try {
		$var(UnicastRemoteObject, cloned, $cast(UnicastRemoteObject, $RemoteServer::clone()));
		$nc(cloned)->reexport();
		return $of(cloned);
	} catch ($RemoteException& e) {
		$throwNew($ServerCloneException, "Clone failed"_s, e);
	}
	$shouldNotReachHere();
}

void UnicastRemoteObject::reexport() {
	if (this->csf == nullptr && this->ssf == nullptr) {
		exportObject(static_cast<$Remote*>(this), this->port);
	} else {
		exportObject(static_cast<$Remote*>(this), this->port, this->csf, this->ssf);
	}
}

$RemoteStub* UnicastRemoteObject::exportObject($Remote* obj) {
	$init(UnicastRemoteObject);
	return $cast($RemoteStub, exportObject(obj, $$new($UnicastServerRef, true)));
}

$Remote* UnicastRemoteObject::exportObject($Remote* obj, int32_t port) {
	$init(UnicastRemoteObject);
	return exportObject(obj, $$new($UnicastServerRef, port));
}

$Remote* UnicastRemoteObject::exportObject($Remote* obj, int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	$init(UnicastRemoteObject);
	return exportObject(obj, static_cast<$UnicastServerRef*>($$new($UnicastServerRef2, port, csf, ssf)));
}

$Remote* UnicastRemoteObject::exportObject($Remote* obj, int32_t port, $ObjectInputFilter* filter) {
	$init(UnicastRemoteObject);
	$useLocalCurrentObjectStackCache();
	return exportObject(obj, $$new($UnicastServerRef, $$new($LiveRef, port), filter));
}

$Remote* UnicastRemoteObject::exportObject($Remote* obj, int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf, $ObjectInputFilter* filter) {
	$init(UnicastRemoteObject);
	return exportObject(obj, static_cast<$UnicastServerRef*>($$new($UnicastServerRef2, port, csf, ssf, filter)));
}

bool UnicastRemoteObject::unexportObject($Remote* obj, bool force) {
	$init(UnicastRemoteObject);
	return $ObjectTable::unexportObject(obj, force);
}

$Remote* UnicastRemoteObject::exportObject($Remote* obj, $UnicastServerRef* sref) {
	$init(UnicastRemoteObject);
	if ($instanceOf(UnicastRemoteObject, obj)) {
		$set($nc($cast(UnicastRemoteObject, obj)), ref, static_cast<$RemoteRef*>(static_cast<$UnicastRef*>(sref)));
	}
	return $nc(sref)->exportObject(obj, nullptr, false);
}

UnicastRemoteObject::UnicastRemoteObject() {
}

$Class* UnicastRemoteObject::load$($String* name, bool initialize) {
	$loadClass(UnicastRemoteObject, name, initialize, &_UnicastRemoteObject_ClassInfo_, allocate$UnicastRemoteObject);
	return class$;
}

$Class* UnicastRemoteObject::class$ = nullptr;

		} // server
	} // rmi
} // java