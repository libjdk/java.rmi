#include <sun/rmi/transport/tcp/TCPEndpoint$FQDN.h>

#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $NewThreadAction = ::sun::rmi::runtime::NewThreadAction;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$FieldInfo _TCPEndpoint$FQDN_FieldInfo_[] = {
	{"reverseLookup", "Ljava/lang/String;", nullptr, $PRIVATE, $field(TCPEndpoint$FQDN, reverseLookup)},
	{"hostAddress", "Ljava/lang/String;", nullptr, $PRIVATE, $field(TCPEndpoint$FQDN, hostAddress)},
	{}
};

$MethodInfo _TCPEndpoint$FQDN_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(TCPEndpoint$FQDN::*)($String*)>(&TCPEndpoint$FQDN::init$))},
	{"attemptFQDN", "(Ljava/net/InetAddress;)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($InetAddress*)>(&TCPEndpoint$FQDN::attemptFQDN)), "java.net.UnknownHostException"},
	{"getFQDN", "()V", nullptr, $PRIVATE, $method(static_cast<void(TCPEndpoint$FQDN::*)()>(&TCPEndpoint$FQDN::getFQDN))},
	{"getHost", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<$String*(TCPEndpoint$FQDN::*)()>(&TCPEndpoint$FQDN::getHost))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _TCPEndpoint$FQDN_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPEndpoint$FQDN", "sun.rmi.transport.tcp.TCPEndpoint", "FQDN", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _TCPEndpoint$FQDN_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.tcp.TCPEndpoint$FQDN",
	"java.lang.Object",
	"java.lang.Runnable",
	_TCPEndpoint$FQDN_FieldInfo_,
	_TCPEndpoint$FQDN_MethodInfo_,
	nullptr,
	nullptr,
	_TCPEndpoint$FQDN_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPEndpoint"
};

$Object* allocate$TCPEndpoint$FQDN($Class* clazz) {
	return $of($alloc(TCPEndpoint$FQDN));
}

void TCPEndpoint$FQDN::init$($String* hostAddress) {
	$set(this, hostAddress, hostAddress);
}

$String* TCPEndpoint$FQDN::attemptFQDN($InetAddress* localAddr) {
	$init(TCPEndpoint$FQDN);
	$useLocalCurrentObjectStackCache();
	$var($String, hostName, $nc(localAddr)->getHostName());
	if ($nc(hostName)->indexOf((int32_t)u'.') < 0) {
		$var($String, hostAddress, localAddr->getHostAddress());
		$var(TCPEndpoint$FQDN, f, $new(TCPEndpoint$FQDN, hostAddress));
		int32_t nameServiceTimeOut = $TCPEndpoint::getInt("sun.rmi.transport.tcp.localHostNameTimeOut"_s, 10000);
		try {
			$synchronized(f) {
				f->getFQDN();
				$of(f)->wait(nameServiceTimeOut);
			}
		} catch ($InterruptedException& e) {
			$($Thread::currentThread())->interrupt();
		}
		$assign(hostName, f->getHost());
		bool var$0 = (hostName == nullptr) || ($nc(hostName)->isEmpty());
		if (var$0 || ($nc(hostName)->indexOf((int32_t)u'.') < 0)) {
			$assign(hostName, hostAddress);
		}
	}
	return hostName;
}

void TCPEndpoint$FQDN::getFQDN() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Thread, t, $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($NewThreadAction, this, "FQDN Finder"_s, true)))));
	$nc(t)->start();
}

$String* TCPEndpoint$FQDN::getHost() {
	$synchronized(this) {
		return this->reverseLookup;
	}
}

void TCPEndpoint$FQDN::run() {
	$useLocalCurrentObjectStackCache();
	$var($String, name, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$assign(name, $nc($($InetAddress::getByName(this->hostAddress)))->getHostName());
			} catch ($UnknownHostException& e) {
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$synchronized(this) {
				$set(this, reverseLookup, name);
				$of(this)->notify();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

TCPEndpoint$FQDN::TCPEndpoint$FQDN() {
}

$Class* TCPEndpoint$FQDN::load$($String* name, bool initialize) {
	$loadClass(TCPEndpoint$FQDN, name, initialize, &_TCPEndpoint$FQDN_ClassInfo_, allocate$TCPEndpoint$FQDN);
	return class$;
}

$Class* TCPEndpoint$FQDN::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun