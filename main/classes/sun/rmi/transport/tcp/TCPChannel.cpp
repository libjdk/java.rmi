#include <sun/rmi/transport/tcp/TCPChannel.h>

#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/SoftReference.h>
#include <java/net/Socket.h>
#include <java/rmi/ConnectIOException.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/WeakHashMap.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/ScheduledExecutorService.h>
#include <java/util/concurrent/ScheduledFuture.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/RuntimeUtil$GetInstanceAction.h>
#include <sun/rmi/runtime/RuntimeUtil.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <sun/rmi/transport/tcp/ConnectionAcceptor.h>
#include <sun/rmi/transport/tcp/TCPChannel$1.h>
#include <sun/rmi/transport/tcp/TCPConnection.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef BRIEF
#undef MILLISECONDS
#undef VERBOSE

using $ConnectionArray = $Array<::sun::rmi::transport::Connection>;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $SecurityManager = ::java::lang::SecurityManager;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SoftReference = ::java::lang::ref::SoftReference;
using $Socket = ::java::net::Socket;
using $ConnectIOException = ::java::rmi::ConnectIOException;
using $RemoteException = ::java::rmi::RemoteException;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Future = ::java::util::concurrent::Future;
using $ScheduledExecutorService = ::java::util::concurrent::ScheduledExecutorService;
using $ScheduledFuture = ::java::util::concurrent::ScheduledFuture;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $RuntimeUtil = ::sun::rmi::runtime::RuntimeUtil;
using $RuntimeUtil$GetInstanceAction = ::sun::rmi::runtime::RuntimeUtil$GetInstanceAction;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $TransportConstants = ::sun::rmi::transport::TransportConstants;
using $ConnectionAcceptor = ::sun::rmi::transport::tcp::ConnectionAcceptor;
using $TCPChannel$1 = ::sun::rmi::transport::tcp::TCPChannel$1;
using $TCPConnection = ::sun::rmi::transport::tcp::TCPConnection;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPChannel$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(TCPChannel$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPChannel::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPChannel$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPChannel$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPChannel$$Lambda$lambda$static$0::*)()>(&TCPChannel$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPChannel$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPChannel$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPChannel$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(TCPChannel$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPChannel$$Lambda$lambda$static$0::class$ = nullptr;

class TCPChannel$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(TCPChannel$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPChannel::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPChannel$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPChannel$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPChannel$$Lambda$lambda$static$1$1::*)()>(&TCPChannel$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPChannel$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPChannel$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPChannel$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(TCPChannel$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPChannel$$Lambda$lambda$static$1$1::class$ = nullptr;

class TCPChannel$$Lambda$lambda$static$2$2 : public $PrivilegedAction {
	$class(TCPChannel$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPChannel::lambda$static$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPChannel$$Lambda$lambda$static$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPChannel$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPChannel$$Lambda$lambda$static$2$2::*)()>(&TCPChannel$$Lambda$lambda$static$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPChannel$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPChannel$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPChannel$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(TCPChannel$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPChannel$$Lambda$lambda$static$2$2::class$ = nullptr;

$FieldInfo _TCPChannel_FieldInfo_[] = {
	{"ep", "Lsun/rmi/transport/tcp/TCPEndpoint;", nullptr, $PRIVATE | $FINAL, $field(TCPChannel, ep)},
	{"tr", "Lsun/rmi/transport/tcp/TCPTransport;", nullptr, $PRIVATE | $FINAL, $field(TCPChannel, tr)},
	{"freeList", "Ljava/util/List;", "Ljava/util/List<Lsun/rmi/transport/tcp/TCPConnection;>;", $PRIVATE | $FINAL, $field(TCPChannel, freeList)},
	{"reaper", "Ljava/util/concurrent/Future;", "Ljava/util/concurrent/Future<*>;", $PRIVATE, $field(TCPChannel, reaper)},
	{"acceptor", "Lsun/rmi/transport/tcp/ConnectionAcceptor;", nullptr, $PRIVATE, $field(TCPChannel, acceptor)},
	{"okContext", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE, $field(TCPChannel, okContext)},
	{"authcache", "Ljava/util/WeakHashMap;", "Ljava/util/WeakHashMap<Ljava/security/AccessControlContext;Ljava/lang/ref/Reference<Ljava/security/AccessControlContext;>;>;", $PRIVATE, $field(TCPChannel, authcache)},
	{"cacheSecurityManager", "Ljava/lang/SecurityManager;", nullptr, $PRIVATE, $field(TCPChannel, cacheSecurityManager)},
	{"idleTimeout", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPChannel, idleTimeout)},
	{"handshakeTimeout", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPChannel, handshakeTimeout)},
	{"responseTimeout", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPChannel, responseTimeout)},
	{"scheduler", "Ljava/util/concurrent/ScheduledExecutorService;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPChannel, scheduler)},
	{}
};

$MethodInfo _TCPChannel_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPTransport;Lsun/rmi/transport/tcp/TCPEndpoint;)V", nullptr, 0, $method(static_cast<void(TCPChannel::*)($TCPTransport*,$TCPEndpoint*)>(&TCPChannel::init$))},
	{"checkConnectPermission", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPChannel::*)()>(&TCPChannel::checkConnectPermission)), "java.lang.SecurityException"},
	{"createConnection", "()Lsun/rmi/transport/Connection;", nullptr, $PRIVATE, $method(static_cast<$Connection*(TCPChannel::*)()>(&TCPChannel::createConnection)), "java.rmi.RemoteException"},
	{"free", "(Lsun/rmi/transport/Connection;Z)V", nullptr, $PUBLIC},
	{"freeCachedConnections", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPChannel::*)()>(&TCPChannel::freeCachedConnections))},
	{"getEndpoint", "()Lsun/rmi/transport/Endpoint;", nullptr, $PUBLIC},
	{"lambda$static$0", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&TCPChannel::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)()>(&TCPChannel::lambda$static$1))},
	{"lambda$static$2", "()Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)()>(&TCPChannel::lambda$static$2))},
	{"newConnection", "()Lsun/rmi/transport/Connection;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"shedCache", "()V", nullptr, $PUBLIC},
	{"writeTransportHeader", "(Ljava/io/DataOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(TCPChannel::*)($DataOutputStream*)>(&TCPChannel::writeTransportHeader)), "java.rmi.RemoteException"},
	{}
};

$InnerClassInfo _TCPChannel_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPChannel$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TCPChannel_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.tcp.TCPChannel",
	"java.lang.Object",
	"sun.rmi.transport.Channel",
	_TCPChannel_FieldInfo_,
	_TCPChannel_MethodInfo_,
	nullptr,
	nullptr,
	_TCPChannel_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPChannel$1"
};

$Object* allocate$TCPChannel($Class* clazz) {
	return $of($alloc(TCPChannel));
}

int64_t TCPChannel::idleTimeout = 0;
int32_t TCPChannel::handshakeTimeout = 0;
int32_t TCPChannel::responseTimeout = 0;
$ScheduledExecutorService* TCPChannel::scheduler = nullptr;

void TCPChannel::init$($TCPTransport* tr, $TCPEndpoint* ep) {
	$set(this, freeList, $new($ArrayList));
	$set(this, reaper, nullptr);
	$set(this, cacheSecurityManager, nullptr);
	$set(this, tr, tr);
	$set(this, ep, ep);
}

$Endpoint* TCPChannel::getEndpoint() {
	return this->ep;
}

void TCPChannel::checkConnectPermission() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security == nullptr) {
		return;
	}
	if (security != this->cacheSecurityManager) {
		$set(this, okContext, nullptr);
		$set(this, authcache, $new($WeakHashMap));
		$set(this, cacheSecurityManager, security);
	}
	$var($AccessControlContext, ctx, $AccessController::getContext());
	bool var$0 = this->okContext == nullptr;
	if (!var$0) {
		bool var$1 = $nc(this->okContext)->equals(ctx);
		var$0 = !(var$1 || $nc(this->authcache)->containsKey(ctx));
	}
	if (var$0) {
		$var($String, var$2, $nc(this->ep)->getHost());
		$nc(security)->checkConnect(var$2, $nc(this->ep)->getPort());
		$nc(this->authcache)->put(ctx, $$new($SoftReference, ctx));
	}
	$set(this, okContext, ctx);
}

$Connection* TCPChannel::newConnection() {
	$var($TCPConnection, conn, nullptr);
	do {
		$assign(conn, nullptr);
		$synchronized(this->freeList) {
			int32_t elementPos = $nc(this->freeList)->size() - 1;
			if (elementPos >= 0) {
				checkConnectPermission();
				$assign(conn, $cast($TCPConnection, $nc(this->freeList)->get(elementPos)));
				$nc(this->freeList)->remove(elementPos);
			}
		}
		if (conn != nullptr) {
			if (!conn->isDead()) {
				$init($TCPTransport);
				$init($Log);
				$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "reuse connection"_s);
				return conn;
			}
			this->free(conn, false);
		}
	} while (conn != nullptr);
	return (createConnection());
}

$Connection* TCPChannel::createConnection() {
	$useLocalCurrentObjectStackCache();
	$var($Connection, conn, nullptr);
	$init($TCPTransport);
	$init($Log);
	$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "create connection"_s);
	$var($Socket, sock, $nc(this->ep)->newSocket());
	$assign(conn, $new($TCPConnection, this, sock));
	try {
		$var($DataOutputStream, out, $new($DataOutputStream, $(conn->getOutputStream())));
		writeTransportHeader(out);
		if (!conn->isReusable()) {
			out->writeByte($TransportConstants::SingleOpProtocol);
		} else {
			out->writeByte($TransportConstants::StreamProtocol);
			out->flush();
			int32_t originalSoTimeout = 0;
			try {
				originalSoTimeout = $nc(sock)->getSoTimeout();
				sock->setSoTimeout(TCPChannel::handshakeTimeout);
			} catch ($Exception& e) {
			}
			$var($DataInputStream, in, $new($DataInputStream, $(conn->getInputStream())));
			int8_t ack = in->readByte();
			if (ack != $TransportConstants::ProtocolAck) {
				$throwNew($ConnectIOException, ack == $TransportConstants::ProtocolNack ? "JRMP StreamProtocol not supported by server"_s : "non-JRMP server at remote endpoint"_s);
			}
			$var($String, suggestedHost, in->readUTF());
			int32_t suggestedPort = in->readInt();
			if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
				$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"server suggested "_s, suggestedHost, ":"_s, $$str(suggestedPort)}));
			}
			$TCPEndpoint::setLocalHost(suggestedHost);
			$var($TCPEndpoint, localEp, $TCPEndpoint::getLocalEndpoint(0, nullptr, nullptr));
			out->writeUTF($($nc(localEp)->getHost()));
			out->writeInt($nc(localEp)->getPort());
			if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
				$var($String, var$0, $$str({"using "_s, $($nc(localEp)->getHost()), ":"_s}));
				$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$concat(var$0, $$str(localEp->getPort())));
			}
			try {
				$nc(sock)->setSoTimeout((originalSoTimeout != 0 ? originalSoTimeout : TCPChannel::responseTimeout));
			} catch ($Exception& e) {
			}
			out->flush();
		}
	} catch ($IOException& e) {
		try {
			conn->close();
		} catch ($Exception& ex) {
		}
		if ($instanceOf($RemoteException, e)) {
			$throw($cast($RemoteException, e));
		} else {
			$throwNew($ConnectIOException, "error during JRMP connection establishment"_s, e);
		}
	}
	return conn;
}

void TCPChannel::free($Connection* conn, bool reuse) {
	$useLocalCurrentObjectStackCache();
	if (conn == nullptr) {
		return;
	}
	if (reuse && $nc(conn)->isReusable()) {
		int64_t lastuse = $System::currentTimeMillis();
		$var($TCPConnection, tcpConnection, $cast($TCPConnection, conn));
		$init($TCPTransport);
		$init($Log);
		$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "reuse connection"_s);
		$synchronized(this->freeList) {
			$nc(this->freeList)->add(tcpConnection);
			if (this->reaper == nullptr) {
				$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "create reaper"_s);
				$init($TimeUnit);
				$set(this, reaper, $nc(TCPChannel::scheduler)->scheduleWithFixedDelay($$new($TCPChannel$1, this), TCPChannel::idleTimeout, TCPChannel::idleTimeout, $TimeUnit::MILLISECONDS));
			}
		}
		tcpConnection->setLastUseTime(lastuse);
		tcpConnection->setExpiration(lastuse + TCPChannel::idleTimeout);
	} else {
		$init($TCPTransport);
		$init($Log);
		$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "close connection"_s);
		try {
			conn->close();
		} catch ($IOException& ignored) {
		}
	}
}

void TCPChannel::writeTransportHeader($DataOutputStream* out) {
	try {
		$var($DataOutputStream, dataOut, $new($DataOutputStream, out));
		dataOut->writeInt($TransportConstants::Magic);
		dataOut->writeShort($TransportConstants::Version);
	} catch ($IOException& e) {
		$throwNew($ConnectIOException, "error writing JRMP transport header"_s, e);
	}
}

void TCPChannel::shedCache() {
	$useLocalCurrentObjectStackCache();
	$var($ConnectionArray, conn, nullptr);
	$synchronized(this->freeList) {
		$assign(conn, $fcast($ConnectionArray, $nc(this->freeList)->toArray($$new($ConnectionArray, $nc(this->freeList)->size()))));
		$nc(this->freeList)->clear();
	}
	for (int32_t i = $nc(conn)->length; --i >= 0;) {
		$var($Connection, c, conn->get(i));
		conn->set(i, nullptr);
		try {
			$nc(c)->close();
		} catch ($IOException& e) {
		}
	}
}

void TCPChannel::freeCachedConnections() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->freeList) {
		int32_t size = $nc(this->freeList)->size();
		if (size > 0) {
			int64_t time = $System::currentTimeMillis();
			$var($ListIterator, iter, $nc(this->freeList)->listIterator(size));
			while ($nc(iter)->hasPrevious()) {
				$var($TCPConnection, conn, $cast($TCPConnection, iter->previous()));
				if ($nc(conn)->expired(time)) {
					$init($TCPTransport);
					$init($Log);
					$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, "connection timeout expired"_s);
					try {
						conn->close();
					} catch ($IOException& e) {
					}
					iter->remove();
				}
			}
		}
		if ($nc(this->freeList)->isEmpty()) {
			$nc(this->reaper)->cancel(false);
			$set(this, reaper, nullptr);
		}
	}
}

$Integer* TCPChannel::lambda$static$2() {
	$init(TCPChannel);
	return $Integer::getInteger("sun.rmi.transport.tcp.responseTimeout"_s, 0);
}

$Integer* TCPChannel::lambda$static$1() {
	$init(TCPChannel);
	return $Integer::getInteger("sun.rmi.transport.tcp.handshakeTimeout"_s, 0x0000EA60);
}

$Long* TCPChannel::lambda$static$0() {
	$init(TCPChannel);
	return $Long::getLong("sun.rmi.transport.connectionTimeout"_s, (int64_t)15000);
}

void clinit$TCPChannel($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	TCPChannel::idleTimeout = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPChannel$$Lambda$lambda$static$0)))))))->longValue();
	TCPChannel::handshakeTimeout = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPChannel$$Lambda$lambda$static$1$1)))))))->intValue();
	TCPChannel::responseTimeout = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPChannel$$Lambda$lambda$static$2$2)))))))->intValue();
	$assignStatic(TCPChannel::scheduler, $nc(($cast($RuntimeUtil, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($RuntimeUtil$GetInstanceAction)))))))->getScheduler());
}

TCPChannel::TCPChannel() {
}

$Class* TCPChannel::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(TCPChannel$$Lambda$lambda$static$0::classInfo$.name)) {
			return TCPChannel$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(TCPChannel$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return TCPChannel$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(TCPChannel$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return TCPChannel$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
	}
	$loadClass(TCPChannel, name, initialize, &_TCPChannel_ClassInfo_, clinit$TCPChannel, allocate$TCPChannel);
	return class$;
}

$Class* TCPChannel::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun