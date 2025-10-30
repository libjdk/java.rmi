#include <sun/rmi/transport/tcp/TCPTransport$ConnectionHandler.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/FilterInputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ThreadLocal.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/SoftReference.h>
#include <java/net/InetAddress.h>
#include <java/net/Socket.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/Map.h>
#include <java/util/WeakHashMap.h>
#include <java/util/concurrent/atomic/AtomicInteger.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <sun/rmi/transport/tcp/TCPChannel.h>
#include <sun/rmi/transport/tcp/TCPConnection.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef BRIEF
#undef NOPERMS_ACC
#undef POST
#undef VERBOSE

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $SecurityManager = ::java::lang::SecurityManager;
using $ThreadLocal = ::java::lang::ThreadLocal;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SoftReference = ::java::lang::ref::SoftReference;
using $InetAddress = ::java::net::InetAddress;
using $Socket = ::java::net::Socket;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $Map = ::java::util::Map;
using $WeakHashMap = ::java::util::WeakHashMap;
using $AtomicInteger = ::java::util::concurrent::atomic::AtomicInteger;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $Connection = ::sun::rmi::transport::Connection;
using $TransportConstants = ::sun::rmi::transport::TransportConstants;
using $TCPChannel = ::sun::rmi::transport::tcp::TCPChannel;
using $TCPConnection = ::sun::rmi::transport::tcp::TCPConnection;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPTransport$ConnectionHandler$$Lambda$lambda$run$0 : public $PrivilegedAction {
	$class(TCPTransport$ConnectionHandler$$Lambda$lambda$run$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(TCPTransport$ConnectionHandler* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$run$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPTransport$ConnectionHandler$$Lambda$lambda$run$0>());
	}
	TCPTransport$ConnectionHandler* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(TCPTransport$ConnectionHandler$$Lambda$lambda$run$0, inst$)},
	{}
};
$MethodInfo TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::methodInfos[3] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPTransport$ConnectionHandler;)V", nullptr, $PUBLIC, $method(static_cast<void(TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::*)(TCPTransport$ConnectionHandler*)>(&TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPTransport$ConnectionHandler$$Lambda$lambda$run$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$ConnectionHandler$$Lambda$lambda$run$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::class$ = nullptr;

$FieldInfo _TCPTransport$ConnectionHandler_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/tcp/TCPTransport;", nullptr, $FINAL | $SYNTHETIC, $field(TCPTransport$ConnectionHandler, this$0)},
	{"POST", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TCPTransport$ConnectionHandler, POST)},
	{"okContext", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE, $field(TCPTransport$ConnectionHandler, okContext)},
	{"authCache", "Ljava/util/Map;", "Ljava/util/Map<Ljava/security/AccessControlContext;Ljava/lang/ref/Reference<Ljava/security/AccessControlContext;>;>;", $PRIVATE, $field(TCPTransport$ConnectionHandler, authCache)},
	{"cacheSecurityManager", "Ljava/lang/SecurityManager;", nullptr, $PRIVATE, $field(TCPTransport$ConnectionHandler, cacheSecurityManager)},
	{"socket", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(TCPTransport$ConnectionHandler, socket)},
	{"remoteHost", "Ljava/lang/String;", nullptr, $PRIVATE, $field(TCPTransport$ConnectionHandler, remoteHost)},
	{}
};

$MethodInfo _TCPTransport$ConnectionHandler_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPTransport;Ljava/net/Socket;Ljava/lang/String;)V", nullptr, 0, $method(static_cast<void(TCPTransport$ConnectionHandler::*)($TCPTransport*,$Socket*,$String*)>(&TCPTransport$ConnectionHandler::init$))},
	{"checkAcceptPermission", "(Ljava/lang/SecurityManager;Ljava/security/AccessControlContext;)V", nullptr, 0},
	{"getClientHost", "()Ljava/lang/String;", nullptr, 0},
	{"lambda$run$0", "()Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(TCPTransport$ConnectionHandler::*)()>(&TCPTransport$ConnectionHandler::lambda$run$0))},
	{"run", "()V", nullptr, $PUBLIC},
	{"run0", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPTransport$ConnectionHandler::*)()>(&TCPTransport$ConnectionHandler::run0))},
	{}
};

$InnerClassInfo _TCPTransport$ConnectionHandler_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPTransport$ConnectionHandler", "sun.rmi.transport.tcp.TCPTransport", "ConnectionHandler", $PRIVATE},
	{}
};

$ClassInfo _TCPTransport$ConnectionHandler_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.tcp.TCPTransport$ConnectionHandler",
	"java.lang.Object",
	"java.lang.Runnable",
	_TCPTransport$ConnectionHandler_FieldInfo_,
	_TCPTransport$ConnectionHandler_MethodInfo_,
	nullptr,
	nullptr,
	_TCPTransport$ConnectionHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPTransport"
};

$Object* allocate$TCPTransport$ConnectionHandler($Class* clazz) {
	return $of($alloc(TCPTransport$ConnectionHandler));
}

void TCPTransport$ConnectionHandler::init$($TCPTransport* this$0, $Socket* socket, $String* remoteHost) {
	$set(this, this$0, this$0);
	$set(this, cacheSecurityManager, nullptr);
	$set(this, socket, socket);
	$set(this, remoteHost, remoteHost);
}

$String* TCPTransport$ConnectionHandler::getClientHost() {
	return this->remoteHost;
}

void TCPTransport$ConnectionHandler::checkAcceptPermission($SecurityManager* sm, $AccessControlContext* acc) {
	$useLocalCurrentObjectStackCache();
	if (sm != this->cacheSecurityManager) {
		$set(this, okContext, nullptr);
		$set(this, authCache, $new($WeakHashMap));
		$set(this, cacheSecurityManager, sm);
	}
	bool var$0 = $nc(acc)->equals(this->okContext);
	if (var$0 || $nc(this->authCache)->containsKey(acc)) {
		return;
	}
	$var($InetAddress, addr, $nc(this->socket)->getInetAddress());
	$var($String, host, (addr != nullptr) ? $nc(addr)->getHostAddress() : "*"_s);
	$nc(sm)->checkAccept(host, $nc(this->socket)->getPort());
	$nc(this->authCache)->put(acc, $$new($SoftReference, acc));
	$set(this, okContext, acc);
}

void TCPTransport$ConnectionHandler::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Thread, t, $Thread::currentThread());
	$var($String, name, t->getName());
	{
		$var($Throwable, var$0, nullptr);
		try {
			$init($TCPTransport);
			t->setName($$str({"RMI TCP Connection("_s, $$str($nc($TCPTransport::connectionCount)->incrementAndGet()), ")-"_s, this->remoteHost}));
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPTransport$ConnectionHandler$$Lambda$lambda$run$0, this)), $TCPTransport::NOPERMS_ACC);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			t->setName(name);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void TCPTransport$ConnectionHandler::run0() {
	$useLocalCurrentObjectStackCache();
	$var($TCPEndpoint, endpoint, this->this$0->getEndpoint());
	int32_t port = $nc(endpoint)->getPort();
	$nc($TCPTransport::threadConnectionHandler)->set(this);
	try {
		$nc(this->socket)->setTcpNoDelay(true);
	} catch ($Exception& e) {
	}
	try {
		if ($TCPTransport::connectionReadTimeout > 0) {
			$nc(this->socket)->setSoTimeout($TCPTransport::connectionReadTimeout);
		}
	} catch ($Exception& e) {
	}
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				$var($InputStream, sockIn, $nc(this->socket)->getInputStream());
				$var($InputStream, bufIn, $nc(sockIn)->markSupported() ? sockIn : static_cast<$InputStream*>($new($BufferedInputStream, sockIn)));
				$var($DataInputStream, in, $new($DataInputStream, bufIn));
				int32_t magic = in->readInt();
				int16_t version = in->readShort();
				if (magic != $TransportConstants::Magic || version != $TransportConstants::Version) {
					$init($Log);
					if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
						$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"magic or version not match: "_s, $$str(magic), ", "_s, $$str(version)}));
					}
					$TCPTransport::closeSocket(this->socket);
					return$1 = true;
					goto $finally;
				}
				$var($OutputStream, sockOut, $nc(this->socket)->getOutputStream());
				$var($BufferedOutputStream, bufOut, $new($BufferedOutputStream, sockOut));
				$var($DataOutputStream, out, $new($DataOutputStream, bufOut));
				int32_t remotePort = $nc(this->socket)->getPort();
				$init($Log);
				if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
					$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"accepted socket from ["_s, this->remoteHost, ":"_s, $$str(remotePort), "]"_s}));
				}
				$var($TCPEndpoint, ep, nullptr);
				$var($TCPChannel, ch, nullptr);
				$var($TCPConnection, conn, nullptr);
				int8_t protocol = in->readByte();
				{
					$var($String, clientHost, nullptr)
					int32_t clientPort = 0;
					switch (protocol) {
					case $TransportConstants::SingleOpProtocol:
						{
							$var($String, var$2, this->remoteHost);
							int32_t var$3 = $nc(this->socket)->getLocalPort();
							$var($RMIClientSocketFactory, var$4, endpoint->getClientSocketFactory());
							$assign(ep, $new($TCPEndpoint, var$2, var$3, var$4, $(endpoint->getServerSocketFactory())));
							$assign(ch, $new($TCPChannel, this->this$0, ep));
							$assign(conn, $new($TCPConnection, ch, this->socket, bufIn, bufOut));
							this->this$0->handleMessages(conn, false);
							break;
						}
					case $TransportConstants::StreamProtocol:
						{
							out->writeByte($TransportConstants::ProtocolAck);
							if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
								$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"(port "_s, $$str(port), ") suggesting "_s, this->remoteHost, ":"_s, $$str(remotePort)}));
							}
							out->writeUTF(this->remoteHost);
							out->writeInt(remotePort);
							out->flush();
							$assign(clientHost, in->readUTF());
							clientPort = in->readInt();
							if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
								$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"(port "_s, $$str(port), ") client using "_s, clientHost, ":"_s, $$str(clientPort)}));
							}
							$var($String, var$5, this->remoteHost);
							int32_t var$6 = $nc(this->socket)->getLocalPort();
							$var($RMIClientSocketFactory, var$7, endpoint->getClientSocketFactory());
							$assign(ep, $new($TCPEndpoint, var$5, var$6, var$7, $(endpoint->getServerSocketFactory())));
							$assign(ch, $new($TCPChannel, this->this$0, ep));
							$assign(conn, $new($TCPConnection, ch, this->socket, bufIn, bufOut));
							this->this$0->handleMessages(conn, true);
							break;
						}
					case $TransportConstants::MultiplexProtocol:
						{
							if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
								$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"(port "_s, $$str(port), ") rejecting multiplex protocol"_s}));
							}
						}
					default:
						{
							out->writeByte($TransportConstants::ProtocolNack);
							out->flush();
							break;
						}
					}
				}
			} catch ($IOException& e) {
				$init($Log);
				$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "terminated with exception:"_s, e);
			}
		} catch ($Throwable& var$8) {
			$assign(var$0, var$8);
		} $finally: {
			$TCPTransport::closeSocket(this->socket);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

$Void* TCPTransport$ConnectionHandler::lambda$run$0() {
	run0();
	return nullptr;
}

TCPTransport$ConnectionHandler::TCPTransport$ConnectionHandler() {
}

$Class* TCPTransport$ConnectionHandler::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::classInfo$.name)) {
			return TCPTransport$ConnectionHandler$$Lambda$lambda$run$0::load$(name, initialize);
		}
	}
	$loadClass(TCPTransport$ConnectionHandler, name, initialize, &_TCPTransport$ConnectionHandler_ClassInfo_, allocate$TCPTransport$ConnectionHandler);
	return class$;
}

$Class* TCPTransport$ConnectionHandler::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun