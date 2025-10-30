#include <java/rmi/server/RemoteServer.h>

#include <java/io/OutputStream.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteRef.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteObject = ::java::rmi::server::RemoteObject;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $Log = ::sun::rmi::runtime::Log;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace java {
	namespace rmi {
		namespace server {

$FieldInfo _RemoteServer_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(RemoteServer, serialVersionUID)},
	{"logNull", "Z", nullptr, $PRIVATE | $STATIC, $staticField(RemoteServer, logNull)},
	{}
};

$MethodInfo _RemoteServer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(RemoteServer::*)()>(&RemoteServer::init$))},
	{"<init>", "(Ljava/rmi/server/RemoteRef;)V", nullptr, $PROTECTED, $method(static_cast<void(RemoteServer::*)($RemoteRef*)>(&RemoteServer::init$))},
	{"getClientHost", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)()>(&RemoteServer::getClientHost)), "java.rmi.server.ServerNotActiveException"},
	{"getLog", "()Ljava/io/PrintStream;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$PrintStream*(*)()>(&RemoteServer::getLog))},
	{"setLog", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($OutputStream*)>(&RemoteServer::setLog))},
	{}
};

$ClassInfo _RemoteServer_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.rmi.server.RemoteServer",
	"java.rmi.server.RemoteObject",
	nullptr,
	_RemoteServer_FieldInfo_,
	_RemoteServer_MethodInfo_
};

$Object* allocate$RemoteServer($Class* clazz) {
	return $of($alloc(RemoteServer));
}

bool RemoteServer::logNull = false;

void RemoteServer::init$() {
	$RemoteObject::init$();
}

void RemoteServer::init$($RemoteRef* ref) {
	$RemoteObject::init$(ref);
}

$String* RemoteServer::getClientHost() {
	$init(RemoteServer);
	return $TCPTransport::getClientHost();
}

void RemoteServer::setLog($OutputStream* out) {
	$init(RemoteServer);
	RemoteServer::logNull = (out == nullptr);
	$init($UnicastServerRef);
	$nc($UnicastServerRef::callLog)->setOutputStream(out);
}

$PrintStream* RemoteServer::getLog() {
	$init(RemoteServer);
	$init($UnicastServerRef);
	return (RemoteServer::logNull ? ($PrintStream*)nullptr : $nc($UnicastServerRef::callLog)->getPrintStream());
}

void clinit$RemoteServer($Class* class$) {
	$init($UnicastServerRef);
	RemoteServer::logNull = !$UnicastServerRef::logCalls;
}

RemoteServer::RemoteServer() {
}

$Class* RemoteServer::load$($String* name, bool initialize) {
	$loadClass(RemoteServer, name, initialize, &_RemoteServer_ClassInfo_, clinit$RemoteServer, allocate$RemoteServer);
	return class$;
}

$Class* RemoteServer::class$ = nullptr;

		} // server
	} // rmi
} // java