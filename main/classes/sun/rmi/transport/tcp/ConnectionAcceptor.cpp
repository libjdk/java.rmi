#include <sun/rmi/transport/tcp/ConnectionAcceptor.h>

#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $Connection = ::sun::rmi::transport::Connection;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$FieldInfo _ConnectionAcceptor_FieldInfo_[] = {
	{"transport", "Lsun/rmi/transport/tcp/TCPTransport;", nullptr, $PRIVATE, $field(ConnectionAcceptor, transport)},
	{"queue", "Ljava/util/List;", "Ljava/util/List<Lsun/rmi/transport/Connection;>;", $PRIVATE, $field(ConnectionAcceptor, queue)},
	{"threadNum", "I", nullptr, $PRIVATE | $STATIC, $staticField(ConnectionAcceptor, threadNum)},
	{}
};

$MethodInfo _ConnectionAcceptor_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPTransport;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectionAcceptor::*)($TCPTransport*)>(&ConnectionAcceptor::init$))},
	{"accept", "(Lsun/rmi/transport/Connection;)V", nullptr, $PUBLIC},
	{"run", "()V", nullptr, $PUBLIC},
	{"startNewAcceptor", "()V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ConnectionAcceptor_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.tcp.ConnectionAcceptor",
	"java.lang.Object",
	"java.lang.Runnable",
	_ConnectionAcceptor_FieldInfo_,
	_ConnectionAcceptor_MethodInfo_
};

$Object* allocate$ConnectionAcceptor($Class* clazz) {
	return $of($alloc(ConnectionAcceptor));
}

int32_t ConnectionAcceptor::threadNum = 0;

void ConnectionAcceptor::init$($TCPTransport* transport) {
	$set(this, queue, $new($ArrayList));
	$set(this, transport, transport);
}

void ConnectionAcceptor::startNewAcceptor() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, var$0, "TCPChannel Accept-"_s);
	$var($Thread, t, $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, this, $$concat(var$0, $$str(++ConnectionAcceptor::threadNum)), true)))));
	$nc(t)->start();
}

void ConnectionAcceptor::accept($Connection* conn) {
	$synchronized(this->queue) {
		$nc(this->queue)->add(conn);
		$nc($of(this->queue))->notify();
	}
}

void ConnectionAcceptor::run() {
	$var($Connection, conn, nullptr);
	$synchronized(this->queue) {
		while ($nc(this->queue)->size() == 0) {
			try {
				$nc($of(this->queue))->wait();
			} catch ($InterruptedException& e) {
			}
		}
		startNewAcceptor();
		$assign(conn, $cast($Connection, $nc(this->queue)->remove(0)));
	}
	$nc(this->transport)->handleMessages(conn, true);
}

void clinit$ConnectionAcceptor($Class* class$) {
	ConnectionAcceptor::threadNum = 0;
}

ConnectionAcceptor::ConnectionAcceptor() {
}

$Class* ConnectionAcceptor::load$($String* name, bool initialize) {
	$loadClass(ConnectionAcceptor, name, initialize, &_ConnectionAcceptor_ClassInfo_, clinit$ConnectionAcceptor, allocate$ConnectionAcceptor);
	return class$;
}

$Class* ConnectionAcceptor::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun