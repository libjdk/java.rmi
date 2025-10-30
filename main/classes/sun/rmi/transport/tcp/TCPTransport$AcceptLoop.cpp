#include <sun/rmi/transport/tcp/TCPTransport$AcceptLoop.h>

#include <java/io/IOException.h>
#include <java/lang/Error.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/NoClassDefFoundError.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/Runnable.h>
#include <java/lang/SecurityException.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/UndeclaredThrowableException.h>
#include <java/net/InetAddress.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/rmi/server/RMIFailureHandler.h>
#include <java/rmi/server/RMISocketFactory.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/ExecutorService.h>
#include <java/util/concurrent/RejectedExecutionException.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <sun/rmi/transport/tcp/TCPTransport$ConnectionHandler.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef BRIEF
#undef WARNING

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoClassDefFoundError = ::java::lang::NoClassDefFoundError;
using $NullPointerException = ::java::lang::NullPointerException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Runnable = ::java::lang::Runnable;
using $SecurityException = ::java::lang::SecurityException;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $UndeclaredThrowableException = ::java::lang::reflect::UndeclaredThrowableException;
using $InetAddress = ::java::net::InetAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $RMIFailureHandler = ::java::rmi::server::RMIFailureHandler;
using $RMISocketFactory = ::java::rmi::server::RMISocketFactory;
using $Executor = ::java::util::concurrent::Executor;
using $ExecutorService = ::java::util::concurrent::ExecutorService;
using $RejectedExecutionException = ::java::util::concurrent::RejectedExecutionException;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;
using $TCPTransport$ConnectionHandler = ::sun::rmi::transport::tcp::TCPTransport$ConnectionHandler;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$FieldInfo _TCPTransport$AcceptLoop_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/tcp/TCPTransport;", nullptr, $FINAL | $SYNTHETIC, $field(TCPTransport$AcceptLoop, this$0)},
	{"serverSocket", "Ljava/net/ServerSocket;", nullptr, $PRIVATE | $FINAL, $field(TCPTransport$AcceptLoop, serverSocket)},
	{"lastExceptionTime", "J", nullptr, $PRIVATE, $field(TCPTransport$AcceptLoop, lastExceptionTime)},
	{"recentExceptionCount", "I", nullptr, $PRIVATE, $field(TCPTransport$AcceptLoop, recentExceptionCount)},
	{}
};

$MethodInfo _TCPTransport$AcceptLoop_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPTransport;Ljava/net/ServerSocket;)V", nullptr, 0, $method(static_cast<void(TCPTransport$AcceptLoop::*)($TCPTransport*,$ServerSocket*)>(&TCPTransport$AcceptLoop::init$))},
	{"continueAfterAcceptFailure", "(Ljava/lang/Throwable;)Z", nullptr, $PRIVATE, $method(static_cast<bool(TCPTransport$AcceptLoop::*)($Throwable*)>(&TCPTransport$AcceptLoop::continueAfterAcceptFailure))},
	{"executeAcceptLoop", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPTransport$AcceptLoop::*)()>(&TCPTransport$AcceptLoop::executeAcceptLoop))},
	{"run", "()V", nullptr, $PUBLIC},
	{"throttleLoopOnException", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPTransport$AcceptLoop::*)()>(&TCPTransport$AcceptLoop::throttleLoopOnException))},
	{}
};

$InnerClassInfo _TCPTransport$AcceptLoop_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPTransport$AcceptLoop", "sun.rmi.transport.tcp.TCPTransport", "AcceptLoop", $PRIVATE},
	{}
};

$ClassInfo _TCPTransport$AcceptLoop_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.tcp.TCPTransport$AcceptLoop",
	"java.lang.Object",
	"java.lang.Runnable",
	_TCPTransport$AcceptLoop_FieldInfo_,
	_TCPTransport$AcceptLoop_MethodInfo_,
	nullptr,
	nullptr,
	_TCPTransport$AcceptLoop_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPTransport"
};

$Object* allocate$TCPTransport$AcceptLoop($Class* clazz) {
	return $of($alloc(TCPTransport$AcceptLoop));
}

void TCPTransport$AcceptLoop::init$($TCPTransport* this$0, $ServerSocket* serverSocket) {
	$set(this, this$0, this$0);
	this->lastExceptionTime = 0;
	$set(this, serverSocket, serverSocket);
}

void TCPTransport$AcceptLoop::run() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			executeAcceptLoop();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			try {
				$init($TCPTransport);
				$init($Log);
				if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
					$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"server socket close: "_s, this->serverSocket}));
				}
				$nc(this->serverSocket)->close();
			} catch ($IOException& e) {
				$init($TCPTransport);
				$init($Log);
				if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
					$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"server socket close throws: "_s, e}));
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void TCPTransport$AcceptLoop::executeAcceptLoop() {
	$useLocalCurrentObjectStackCache();
	$init($TCPTransport);
	$init($Log);
	if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
		$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"listening on port "_s, $$str($nc($(this->this$0->getEndpoint()))->getPort())}));
	}
	while (true) {
		$var($Socket, socket, nullptr);
		try {
			$assign(socket, $nc(this->serverSocket)->accept());
			$var($InetAddress, clientAddr, $nc(socket)->getInetAddress());
			$var($String, clientHost, clientAddr != nullptr ? $nc(clientAddr)->getHostAddress() : "0.0.0.0"_s);
			try {
				$nc($TCPTransport::connectionThreadPool)->execute($$new($TCPTransport$ConnectionHandler, this->this$0, socket, clientHost));
			} catch ($RejectedExecutionException& e) {
				$TCPTransport::closeSocket(socket);
				$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"rejected connection from "_s, clientHost}));
			}
		} catch ($Throwable& t) {
			{
				$var($Throwable, var$0, nullptr);
				bool break$1 = false;
				try {
					if ($nc(this->serverSocket)->isClosed()) {
						// break;
						break$1 = true;
						goto $finally;
					}
					try {
						$init($Level);
						if ($nc($TCPTransport::tcpLog)->isLoggable($Level::WARNING)) {
							$nc($TCPTransport::tcpLog)->log($Level::WARNING, $$str({"accept loop for "_s, this->serverSocket, " throws"_s}), t);
						}
					} catch ($Throwable& tt) {
					}
				} catch ($Throwable& var$2) {
					$assign(var$0, var$2);
				} $finally: {
					if (socket != nullptr) {
						$TCPTransport::closeSocket(socket);
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
				if (break$1) {
					break;
				}
			}
			if (!($instanceOf($SecurityException, t))) {
				try {
					$TCPEndpoint::shedConnectionCaches();
				} catch ($Throwable& tt) {
				}
			}
			if ($instanceOf($Exception, t) || $instanceOf($OutOfMemoryError, t) || $instanceOf($NoClassDefFoundError, t)) {
				if (!continueAfterAcceptFailure(t)) {
					return;
				}
			} else if ($instanceOf($Error, t)) {
				$throw($cast($Error, t));
			} else {
				$throwNew($UndeclaredThrowableException, t);
			}
		}
	}
}

bool TCPTransport$AcceptLoop::continueAfterAcceptFailure($Throwable* t) {
	$useLocalCurrentObjectStackCache();
	$var($RMIFailureHandler, fh, $RMISocketFactory::getFailureHandler());
	if (fh != nullptr) {
		return fh->failure($instanceOf($Exception, t) ? $cast($Exception, t) : static_cast<$Exception*>($$new($InvocationTargetException, t)));
	} else {
		throttleLoopOnException();
		return true;
	}
}

void TCPTransport$AcceptLoop::throttleLoopOnException() {
	int64_t now = $System::currentTimeMillis();
	if (this->lastExceptionTime == (int64_t)0 || (now - this->lastExceptionTime) > 5000) {
		this->lastExceptionTime = now;
		this->recentExceptionCount = 0;
	} else if (++this->recentExceptionCount >= 10) {
		try {
			$Thread::sleep(10000);
		} catch ($InterruptedException& ignore) {
		}
	}
}

TCPTransport$AcceptLoop::TCPTransport$AcceptLoop() {
}

$Class* TCPTransport$AcceptLoop::load$($String* name, bool initialize) {
	$loadClass(TCPTransport$AcceptLoop, name, initialize, &_TCPTransport$AcceptLoop_ClassInfo_, allocate$TCPTransport$AcceptLoop);
	return class$;
}

$Class* TCPTransport$AcceptLoop::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun