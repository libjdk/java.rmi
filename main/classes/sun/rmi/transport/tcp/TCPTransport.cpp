#include <sun/rmi/transport/tcp/TCPTransport.h>

#include <java/io/DataInput.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ThreadLocal.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/WeakReference.h>
#include <java/net/BindException.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/net/SocketException.h>
#include <java/rmi/server/ExportException.h>
#include <java/rmi/server/LogStream.h>
#include <java/rmi/server/RMISocketFactory.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/ServerNotActiveException.h>
#include <java/rmi/server/UID.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/CodeSource.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <java/util/concurrent/AbstractExecutorService.h>
#include <java/util/concurrent/BlockingQueue.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/SynchronousQueue.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/ThreadPoolExecutor.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/DGCAckHandler.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <sun/rmi/transport/tcp/TCPChannel.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <sun/rmi/transport/tcp/TCPTransport$1.h>
#include <sun/rmi/transport/tcp/TCPTransport$AcceptLoop.h>
#include <sun/rmi/transport/tcp/TCPTransport$ConnectionHandler.h>
#include <jcpp.h>

#undef BRIEF
#undef MAX_VALUE
#undef MILLISECONDS
#undef NOPERMS_ACC
#undef VERBOSE

using $ProtectionDomainArray = $Array<::java::security::ProtectionDomain>;
using $DataInput = ::java::io::DataInput;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SecurityManager = ::java::lang::SecurityManager;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Reference = ::java::lang::ref::Reference;
using $WeakReference = ::java::lang::ref::WeakReference;
using $BindException = ::java::net::BindException;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $SocketException = ::java::net::SocketException;
using $ExportException = ::java::rmi::server::ExportException;
using $LogStream = ::java::rmi::server::LogStream;
using $RMISocketFactory = ::java::rmi::server::RMISocketFactory;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $ServerNotActiveException = ::java::rmi::server::ServerNotActiveException;
using $UID = ::java::rmi::server::UID;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $CodeSource = ::java::security::CodeSource;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;
using $AbstractExecutorService = ::java::util::concurrent::AbstractExecutorService;
using $BlockingQueue = ::java::util::concurrent::BlockingQueue;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $SynchronousQueue = ::java::util::concurrent::SynchronousQueue;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $ThreadPoolExecutor = ::java::util::concurrent::ThreadPoolExecutor;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $DGCAckHandler = ::sun::rmi::transport::DGCAckHandler;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $StreamRemoteCall = ::sun::rmi::transport::StreamRemoteCall;
using $Target = ::sun::rmi::transport::Target;
using $Transport = ::sun::rmi::transport::Transport;
using $TransportConstants = ::sun::rmi::transport::TransportConstants;
using $TCPChannel = ::sun::rmi::transport::tcp::TCPChannel;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;
using $TCPTransport$1 = ::sun::rmi::transport::tcp::TCPTransport$1;
using $TCPTransport$AcceptLoop = ::sun::rmi::transport::tcp::TCPTransport$AcceptLoop;
using $TCPTransport$ConnectionHandler = ::sun::rmi::transport::tcp::TCPTransport$ConnectionHandler;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPTransport$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(TCPTransport$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPTransport::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPTransport$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPTransport$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPTransport$$Lambda$lambda$static$0::*)()>(&TCPTransport$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPTransport$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPTransport$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPTransport$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPTransport$$Lambda$lambda$static$0::class$ = nullptr;

class TCPTransport$$Lambda$lambda$static$1$1 : public $PrivilegedAction {
	$class(TCPTransport$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPTransport::lambda$static$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPTransport$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPTransport$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPTransport$$Lambda$lambda$static$1$1::*)()>(&TCPTransport$$Lambda$lambda$static$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPTransport$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPTransport$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPTransport$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPTransport$$Lambda$lambda$static$1$1::class$ = nullptr;

class TCPTransport$$Lambda$lambda$static$2$2 : public $PrivilegedAction {
	$class(TCPTransport$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPTransport::lambda$static$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPTransport$$Lambda$lambda$static$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPTransport$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPTransport$$Lambda$lambda$static$2$2::*)()>(&TCPTransport$$Lambda$lambda$static$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPTransport$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPTransport$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPTransport$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPTransport$$Lambda$lambda$static$2$2::class$ = nullptr;

class TCPTransport$$Lambda$lambda$static$3$3 : public $PrivilegedAction {
	$class(TCPTransport$$Lambda$lambda$static$3$3, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPTransport::lambda$static$3());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPTransport$$Lambda$lambda$static$3$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPTransport$$Lambda$lambda$static$3$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPTransport$$Lambda$lambda$static$3$3::*)()>(&TCPTransport$$Lambda$lambda$static$3$3::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPTransport$$Lambda$lambda$static$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPTransport$$Lambda$lambda$static$3$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPTransport$$Lambda$lambda$static$3$3::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$$Lambda$lambda$static$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPTransport$$Lambda$lambda$static$3$3::class$ = nullptr;

$FieldInfo _TCPTransport_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(TCPTransport, $assertionsDisabled)},
	{"tcpLog", "Lsun/rmi/runtime/Log;", nullptr, $STATIC | $FINAL, $staticField(TCPTransport, tcpLog)},
	{"maxConnectionThreads", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, maxConnectionThreads)},
	{"threadKeepAliveTime", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, threadKeepAliveTime)},
	{"connectionThreadPool", "Ljava/util/concurrent/ExecutorService;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, connectionThreadPool)},
	{"connectionCount", "Ljava/util/concurrent/atomic/AtomicInteger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, connectionCount)},
	{"threadConnectionHandler", "Ljava/lang/ThreadLocal;", "Ljava/lang/ThreadLocal<Lsun/rmi/transport/tcp/TCPTransport$ConnectionHandler;>;", $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, threadConnectionHandler)},
	{"NOPERMS_ACC", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, NOPERMS_ACC)},
	{"epList", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Lsun/rmi/transport/tcp/TCPEndpoint;>;", $PRIVATE | $FINAL, $field(TCPTransport, epList)},
	{"exportCount", "I", nullptr, $PRIVATE, $field(TCPTransport, exportCount)},
	{"server", "Ljava/net/ServerSocket;", nullptr, $PRIVATE, $field(TCPTransport, server)},
	{"channelTable", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/tcp/TCPEndpoint;Ljava/lang/ref/Reference<Lsun/rmi/transport/tcp/TCPChannel;>;>;", $PRIVATE | $FINAL, $field(TCPTransport, channelTable)},
	{"defaultSocketFactory", "Ljava/rmi/server/RMISocketFactory;", nullptr, $STATIC | $FINAL, $staticField(TCPTransport, defaultSocketFactory)},
	{"connectionReadTimeout", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TCPTransport, connectionReadTimeout)},
	{}
};

$MethodInfo _TCPTransport_MethodInfo_[] = {
	{"<init>", "(Ljava/util/LinkedList;)V", "(Ljava/util/LinkedList<Lsun/rmi/transport/tcp/TCPEndpoint;>;)V", 0, $method(static_cast<void(TCPTransport::*)($LinkedList*)>(&TCPTransport::init$))},
	{"checkAcceptPermission", "(Ljava/security/AccessControlContext;)V", nullptr, $PROTECTED},
	{"closeSocket", "(Ljava/net/Socket;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Socket*)>(&TCPTransport::closeSocket))},
	{"decrementExportCount", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPTransport::*)()>(&TCPTransport::decrementExportCount))},
	{"exportObject", "(Lsun/rmi/transport/Target;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"free", "(Lsun/rmi/transport/Endpoint;)V", nullptr, $PUBLIC},
	{"getChannel", "(Lsun/rmi/transport/Endpoint;)Lsun/rmi/transport/tcp/TCPChannel;", nullptr, $PUBLIC},
	{"getClientHost", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)()>(&TCPTransport::getClientHost)), "java.rmi.server.ServerNotActiveException"},
	{"getEndpoint", "()Lsun/rmi/transport/tcp/TCPEndpoint;", nullptr, $PRIVATE, $method(static_cast<$TCPEndpoint*(TCPTransport::*)()>(&TCPTransport::getEndpoint))},
	{"handleMessages", "(Lsun/rmi/transport/Connection;Z)V", nullptr, 0},
	{"lambda$static$0", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&TCPTransport::lambda$static$0))},
	{"lambda$static$1", "()Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)()>(&TCPTransport::lambda$static$1))},
	{"lambda$static$2", "()Ljava/lang/Long;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Long*(*)()>(&TCPTransport::lambda$static$2))},
	{"lambda$static$3", "()Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)()>(&TCPTransport::lambda$static$3))},
	{"listen", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPTransport::*)()>(&TCPTransport::listen)), "java.rmi.RemoteException"},
	{"shedConnectionCaches", "()V", nullptr, $PUBLIC},
	{"targetUnexported", "()V", nullptr, $PROTECTED | $SYNCHRONIZED},
	{}
};

$InnerClassInfo _TCPTransport_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPTransport$ConnectionHandler", "sun.rmi.transport.tcp.TCPTransport", "ConnectionHandler", $PRIVATE},
	{"sun.rmi.transport.tcp.TCPTransport$AcceptLoop", "sun.rmi.transport.tcp.TCPTransport", "AcceptLoop", $PRIVATE},
	{"sun.rmi.transport.tcp.TCPTransport$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TCPTransport_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.tcp.TCPTransport",
	"sun.rmi.transport.Transport",
	nullptr,
	_TCPTransport_FieldInfo_,
	_TCPTransport_MethodInfo_,
	nullptr,
	nullptr,
	_TCPTransport_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPTransport$ConnectionHandler,sun.rmi.transport.tcp.TCPTransport$AcceptLoop,sun.rmi.transport.tcp.TCPTransport$1"
};

$Object* allocate$TCPTransport($Class* clazz) {
	return $of($alloc(TCPTransport));
}

bool TCPTransport::$assertionsDisabled = false;
$Log* TCPTransport::tcpLog = nullptr;
int32_t TCPTransport::maxConnectionThreads = 0;
int64_t TCPTransport::threadKeepAliveTime = 0;
$ExecutorService* TCPTransport::connectionThreadPool = nullptr;
$AtomicInteger* TCPTransport::connectionCount = nullptr;
$ThreadLocal* TCPTransport::threadConnectionHandler = nullptr;
$AccessControlContext* TCPTransport::NOPERMS_ACC = nullptr;
$RMISocketFactory* TCPTransport::defaultSocketFactory = nullptr;
int32_t TCPTransport::connectionReadTimeout = 0;

void TCPTransport::init$($LinkedList* epList) {
	$useLocalCurrentObjectStackCache();
	$Transport::init$();
	this->exportCount = 0;
	$set(this, server, nullptr);
	$set(this, channelTable, $new($WeakHashMap));
	$set(this, epList, epList);
	$init($Log);
	if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
		$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"Version = "_s, $$str($TransportConstants::Version), ", ep = "_s, $(getEndpoint())}));
	}
}

void TCPTransport::shedConnectionCaches() {
	$useLocalCurrentObjectStackCache();
	$var($List, channels, nullptr);
	$synchronized(this->channelTable) {
		$assign(channels, $new($ArrayList, $nc($($nc(this->channelTable)->values()))->size()));
		{
			$var($Iterator, i$, $nc($($nc(this->channelTable)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Reference, ref, $cast($Reference, i$->next()));
				{
					$var($TCPChannel, ch, $cast($TCPChannel, $nc(ref)->get()));
					if (ch != nullptr) {
						channels->add(ch);
					}
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc(channels)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TCPChannel, channel, $cast($TCPChannel, i$->next()));
			{
				$nc(channel)->shedCache();
			}
		}
	}
}

$Channel* TCPTransport::getChannel($Endpoint* ep) {
	$useLocalCurrentObjectStackCache();
	$var($TCPChannel, ch, nullptr);
	if ($instanceOf($TCPEndpoint, ep)) {
		$synchronized(this->channelTable) {
			$var($Reference, ref, $cast($Reference, $nc(this->channelTable)->get(ep)));
			if (ref != nullptr) {
				$assign(ch, $cast($TCPChannel, ref->get()));
			}
			if (ch == nullptr) {
				$var($TCPEndpoint, tcpEndpoint, $cast($TCPEndpoint, ep));
				$assign(ch, $new($TCPChannel, this, tcpEndpoint));
				$nc(this->channelTable)->put(tcpEndpoint, $$new($WeakReference, ch));
			}
		}
	}
	return ch;
}

void TCPTransport::free($Endpoint* ep) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($TCPEndpoint, ep)) {
		$synchronized(this->channelTable) {
			$var($Reference, ref, $cast($Reference, $nc(this->channelTable)->remove(ep)));
			if (ref != nullptr) {
				$var($TCPChannel, channel, $cast($TCPChannel, ref->get()));
				if (channel != nullptr) {
					channel->shedCache();
				}
			}
		}
	}
}

void TCPTransport::exportObject($Target* target) {
	$synchronized(this) {
		listen();
		++this->exportCount;
	}
	bool ok = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			$Transport::exportObject(target);
			ok = true;
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!ok) {
				$synchronized(this) {
					decrementExportCount();
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void TCPTransport::targetUnexported() {
	$synchronized(this) {
		decrementExportCount();
	}
}

void TCPTransport::decrementExportCount() {
	$useLocalCurrentObjectStackCache();
	if (!TCPTransport::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	--this->exportCount;
	$init($Log);
	if ($nc(TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
		$nc(TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"server socket: "_s, this->server, ", exportCount: "_s, $$str(this->exportCount)}));
	}
	if (this->exportCount == 0 && $nc($(getEndpoint()))->getListenPort() != 0) {
		$var($ServerSocket, ss, this->server);
		$set(this, server, nullptr);
		try {
			if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
				$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"server socket close: "_s, ss}));
			}
			$nc(ss)->close();
		} catch ($IOException& e) {
			if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
				$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"server socket close throws: "_s, e}));
			}
		}
	}
}

void TCPTransport::checkAcceptPermission($AccessControlContext* acc) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return;
	}
	$var($TCPTransport$ConnectionHandler, h, $cast($TCPTransport$ConnectionHandler, $nc(TCPTransport::threadConnectionHandler)->get()));
	if (h == nullptr) {
		$throwNew($Error, "checkAcceptPermission not in ConnectionHandler thread"_s);
	}
	$nc(h)->checkAcceptPermission(sm, acc);
}

$TCPEndpoint* TCPTransport::getEndpoint() {
	$synchronized(this->epList) {
		return $cast($TCPEndpoint, $nc(this->epList)->getLast());
	}
}

void TCPTransport::listen() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!TCPTransport::$assertionsDisabled && !$Thread::holdsLock(this)) {
		$throwNew($AssertionError);
	}
	$var($TCPEndpoint, ep, getEndpoint());
	int32_t port = $nc(ep)->getPort();
	if (this->server == nullptr) {
		$init($Log);
		if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
			$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"(port "_s, $$str(port), ") create server socket"_s}));
		}
		try {
			$set(this, server, ep->newServerSocket());
			$var($Thread, t, $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, $$new($TCPTransport$AcceptLoop, this, this->server), $$str({"TCP Accept-"_s, $$str(port)}), true)))));
			$nc(t)->start();
		} catch ($BindException& e) {
			$throwNew($ExportException, $$str({"Port already in use: "_s, $$str(port)}), e);
		} catch ($IOException& e) {
			$throwNew($ExportException, $$str({"Listen failed on port: "_s, $$str(port)}), e);
		}
	} else {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkListen(port);
		}
	}
}

void TCPTransport::closeSocket($Socket* sock) {
	$init(TCPTransport);
	$useLocalCurrentObjectStackCache();
	try {
		$init($Log);
		if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
			$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"socket close: "_s, sock}));
		}
		$nc(sock)->close();
	} catch ($IOException& ex) {
		$init($Log);
		if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
			$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"socket close throws: "_s, ex}));
		}
	}
}

void TCPTransport::handleMessages($Connection* conn, bool persistent) {
	$useLocalCurrentObjectStackCache();
	int32_t port = $nc($(getEndpoint()))->getPort();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($DataInputStream, in, $new($DataInputStream, $($nc(conn)->getInputStream())));
				do {
					int32_t op = in->read();
					if (op == -1) {
						$init($Log);
						if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
							$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"(port "_s, $$str(port), ") connection closed"_s}));
						}
						break;
					}
					$init($Log);
					if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
						$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"(port "_s, $$str(port), ") op = "_s, $$str(op)}));
					}
					{
						$var($RemoteCall, call, nullptr)
						$var($DataOutputStream, out, nullptr)
						switch (op) {
						case $TransportConstants::Call:
							{
								$assign(call, $new($StreamRemoteCall, conn));
								if (serviceCall(call) == false) {
									return$1 = true;
									goto $finally;
								}
								break;
							}
						case $TransportConstants::Ping:
							{
								$assign(out, $new($DataOutputStream, $($nc(conn)->getOutputStream())));
								$nc(out)->writeByte($TransportConstants::PingAck);
								$nc(conn)->releaseOutputStream();
								break;
							}
						case $TransportConstants::DGCAck:
							{
								$DGCAckHandler::received($($UID::read(in)));
								break;
							}
						default:
							{
								$throwNew($IOException, $$str({"unknown transport op "_s, $$str(op)}));
							}
						}
					}
				} while (persistent);
			} catch ($IOException& e) {
				$init($Log);
				if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
					$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"(port "_s, $$str(port), ") exception: "_s}), e);
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			try {
				$nc(conn)->close();
			} catch ($IOException& ex) {
				$init($Log);
				if ($nc(TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
					$nc(TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"Connection close throws "_s, ex}));
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

$String* TCPTransport::getClientHost() {
	$init(TCPTransport);
	$var($TCPTransport$ConnectionHandler, h, $cast($TCPTransport$ConnectionHandler, $nc(TCPTransport::threadConnectionHandler)->get()));
	if (h != nullptr) {
		return h->getClientHost();
	} else {
		$throwNew($ServerNotActiveException, "not in a remote call"_s);
	}
}

$Integer* TCPTransport::lambda$static$3() {
	$init(TCPTransport);
	return $Integer::getInteger("sun.rmi.transport.tcp.readTimeout"_s, 2 * 3600 * 1000);
}

$Long* TCPTransport::lambda$static$2() {
	$init(TCPTransport);
	return $Long::getLong("sun.rmi.transport.tcp.threadKeepAliveTime"_s, (int64_t)0x0000EA60);
}

$Integer* TCPTransport::lambda$static$1() {
	$init(TCPTransport);
	return $Integer::getInteger("sun.rmi.transport.tcp.maxConnectionThreads"_s, $Integer::MAX_VALUE);
}

$String* TCPTransport::lambda$static$0() {
	$init(TCPTransport);
	return $System::getProperty("sun.rmi.transport.tcp.logLevel"_s);
}

void clinit$TCPTransport($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	TCPTransport::$assertionsDisabled = !TCPTransport::class$->desiredAssertionStatus();
	$assignStatic(TCPTransport::tcpLog, $Log::getLog("sun.rmi.transport.tcp"_s, "tcp"_s, $LogStream::parseLevel($cast($String, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPTransport$$Lambda$lambda$static$0))))))));
	TCPTransport::maxConnectionThreads = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPTransport$$Lambda$lambda$static$1$1)))))))->intValue();
	TCPTransport::threadKeepAliveTime = $nc(($cast($Long, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPTransport$$Lambda$lambda$static$2$2)))))))->longValue();
	int32_t var$0 = TCPTransport::maxConnectionThreads;
	int64_t var$1 = TCPTransport::threadKeepAliveTime;
	$init($TimeUnit);
	$var($TimeUnit, var$2, $TimeUnit::MILLISECONDS);
	$var($BlockingQueue, var$3, static_cast<$BlockingQueue*>($new($SynchronousQueue)));
	$assignStatic(TCPTransport::connectionThreadPool, $new($ThreadPoolExecutor, 0, var$0, var$1, var$2, var$3, static_cast<$ThreadFactory*>($$new($TCPTransport$1))));
	$assignStatic(TCPTransport::connectionCount, $new($AtomicInteger));
	$assignStatic(TCPTransport::threadConnectionHandler, $new($ThreadLocal));
	{
		$var($Permissions, perms, $new($Permissions));
		$var($ProtectionDomainArray, pd, $new($ProtectionDomainArray, {$$new($ProtectionDomain, nullptr, perms)}));
		$assignStatic(TCPTransport::NOPERMS_ACC, $new($AccessControlContext, pd));
	}
	$assignStatic(TCPTransport::defaultSocketFactory, $RMISocketFactory::getDefaultSocketFactory());
	TCPTransport::connectionReadTimeout = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPTransport$$Lambda$lambda$static$3$3)))))))->intValue();
}

TCPTransport::TCPTransport() {
}

$Class* TCPTransport::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(TCPTransport$$Lambda$lambda$static$0::classInfo$.name)) {
			return TCPTransport$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(TCPTransport$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return TCPTransport$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(TCPTransport$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return TCPTransport$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
		if (name->equals(TCPTransport$$Lambda$lambda$static$3$3::classInfo$.name)) {
			return TCPTransport$$Lambda$lambda$static$3$3::load$(name, initialize);
		}
	}
	$loadClass(TCPTransport, name, initialize, &_TCPTransport_ClassInfo_, clinit$TCPTransport, allocate$TCPTransport);
	return class$;
}

$Class* TCPTransport::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun