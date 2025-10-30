#include <sun/rmi/transport/tcp/TCPEndpoint.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/io/Serializable.h>
#include <java/lang/InternalError.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Proxy.h>
#include <java/net/ConnectException.h>
#include <java/net/InetAddress.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/net/SocketException.h>
#include <java/net/UnknownHostException.h>
#include <java/rmi/ConnectException.h>
#include <java/rmi/ConnectIOException.h>
#include <java/rmi/UnknownHostException.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RMISocketFactory.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/tcp/TCPEndpoint$FQDN.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef BRIEF
#undef FORMAT_HOST_PORT
#undef FORMAT_HOST_PORT_FACTORY
#undef VERBOSE

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $IOException = ::java::io::IOException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Proxy = ::java::lang::reflect::Proxy;
using $ConnectException = ::java::net::ConnectException;
using $InetAddress = ::java::net::InetAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $SocketException = ::java::net::SocketException;
using $1UnknownHostException = ::java::net::UnknownHostException;
using $1ConnectException = ::java::rmi::ConnectException;
using $ConnectIOException = ::java::rmi::ConnectIOException;
using $UnknownHostException = ::java::rmi::UnknownHostException;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $RMISocketFactory = ::java::rmi::server::RMISocketFactory;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $Channel = ::sun::rmi::transport::Channel;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $Target = ::sun::rmi::transport::Target;
using $Transport = ::sun::rmi::transport::Transport;
using $TCPEndpoint$FQDN = ::sun::rmi::transport::tcp::TCPEndpoint$FQDN;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

class TCPEndpoint$$Lambda$lambda$getInt$0 : public $PrivilegedAction {
	$class(TCPEndpoint$$Lambda$lambda$getInt$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name, int32_t def) {
		$set(this, name, name);
		this->def = def;
	}
	virtual $Object* run() override {
		 return $of(TCPEndpoint::lambda$getInt$0(name, def));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPEndpoint$$Lambda$lambda$getInt$0>());
	}
	$String* name = nullptr;
	int32_t def = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TCPEndpoint$$Lambda$lambda$getInt$0::fieldInfos[3] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(TCPEndpoint$$Lambda$lambda$getInt$0, name)},
	{"def", "I", nullptr, $PUBLIC, $field(TCPEndpoint$$Lambda$lambda$getInt$0, def)},
	{}
};
$MethodInfo TCPEndpoint$$Lambda$lambda$getInt$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(TCPEndpoint$$Lambda$lambda$getInt$0::*)($String*,int32_t)>(&TCPEndpoint$$Lambda$lambda$getInt$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPEndpoint$$Lambda$lambda$getInt$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPEndpoint$$Lambda$lambda$getInt$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* TCPEndpoint$$Lambda$lambda$getInt$0::load$($String* name, bool initialize) {
	$loadClass(TCPEndpoint$$Lambda$lambda$getInt$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPEndpoint$$Lambda$lambda$getInt$0::class$ = nullptr;

class TCPEndpoint$$Lambda$lambda$getBoolean$1$1 : public $PrivilegedAction {
	$class(TCPEndpoint$$Lambda$lambda$getBoolean$1$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* run() override {
		 return $of(TCPEndpoint::lambda$getBoolean$1(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPEndpoint$$Lambda$lambda$getBoolean$1$1>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TCPEndpoint$$Lambda$lambda$getBoolean$1$1::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(TCPEndpoint$$Lambda$lambda$getBoolean$1$1, name)},
	{}
};
$MethodInfo TCPEndpoint$$Lambda$lambda$getBoolean$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(TCPEndpoint$$Lambda$lambda$getBoolean$1$1::*)($String*)>(&TCPEndpoint$$Lambda$lambda$getBoolean$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPEndpoint$$Lambda$lambda$getBoolean$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPEndpoint$$Lambda$lambda$getBoolean$1$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* TCPEndpoint$$Lambda$lambda$getBoolean$1$1::load$($String* name, bool initialize) {
	$loadClass(TCPEndpoint$$Lambda$lambda$getBoolean$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPEndpoint$$Lambda$lambda$getBoolean$1$1::class$ = nullptr;

class TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2 : public $PrivilegedAction {
	$class(TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(TCPEndpoint::lambda$getHostnameProperty$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::*)()>(&TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.tcp.TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::load$($String* name, bool initialize) {
	$loadClass(TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::class$ = nullptr;

$FieldInfo _TCPEndpoint_FieldInfo_[] = {
	{"host", "Ljava/lang/String;", nullptr, $PRIVATE, $field(TCPEndpoint, host)},
	{"port", "I", nullptr, $PRIVATE, $field(TCPEndpoint, port)},
	{"csf", "Ljava/rmi/server/RMIClientSocketFactory;", nullptr, $PRIVATE | $FINAL, $field(TCPEndpoint, csf)},
	{"ssf", "Ljava/rmi/server/RMIServerSocketFactory;", nullptr, $PRIVATE | $FINAL, $field(TCPEndpoint, ssf)},
	{"listenPort", "I", nullptr, $PRIVATE, $field(TCPEndpoint, listenPort)},
	{"transport", "Lsun/rmi/transport/tcp/TCPTransport;", nullptr, $PRIVATE, $field(TCPEndpoint, transport)},
	{"localHost", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(TCPEndpoint, localHost)},
	{"localHostKnown", "Z", nullptr, $PRIVATE | $STATIC, $staticField(TCPEndpoint, localHostKnown)},
	{"localEndpoints", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/tcp/TCPEndpoint;Ljava/util/LinkedList<Lsun/rmi/transport/tcp/TCPEndpoint;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(TCPEndpoint, localEndpoints)},
	{"FORMAT_HOST_PORT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TCPEndpoint, FORMAT_HOST_PORT)},
	{"FORMAT_HOST_PORT_FACTORY", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TCPEndpoint, FORMAT_HOST_PORT_FACTORY)},
	{}
};

$MethodInfo _TCPEndpoint_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(TCPEndpoint::*)($String*,int32_t)>(&TCPEndpoint::init$))},
	{"<init>", "(Ljava/lang/String;ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $PUBLIC, $method(static_cast<void(TCPEndpoint::*)($String*,int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&TCPEndpoint::init$))},
	{"allKnownTransports", "()Ljava/util/Collection;", "()Ljava/util/Collection<Lsun/rmi/transport/tcp/TCPTransport;>;", $PRIVATE | $STATIC, $method(static_cast<$Collection*(*)()>(&TCPEndpoint::allKnownTransports))},
	{"chooseFactory", "()Ljava/rmi/server/RMISocketFactory;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$RMISocketFactory*(*)()>(&TCPEndpoint::chooseFactory))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"exportObject", "(Lsun/rmi/transport/Target;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"getBoolean", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($String*)>(&TCPEndpoint::getBoolean))},
	{"getChannel", "()Lsun/rmi/transport/Channel;", nullptr, $PUBLIC},
	{"getClientSocketFactory", "()Ljava/rmi/server/RMIClientSocketFactory;", nullptr, $PUBLIC},
	{"getHost", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getHostnameProperty", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)()>(&TCPEndpoint::getHostnameProperty))},
	{"getInboundTransport", "()Lsun/rmi/transport/Transport;", nullptr, $PUBLIC},
	{"getInt", "(Ljava/lang/String;I)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($String*,int32_t)>(&TCPEndpoint::getInt))},
	{"getListenPort", "()I", nullptr, $PUBLIC},
	{"getLocalEndpoint", "(I)Lsun/rmi/transport/tcp/TCPEndpoint;", nullptr, $PUBLIC | $STATIC, $method(static_cast<TCPEndpoint*(*)(int32_t)>(&TCPEndpoint::getLocalEndpoint))},
	{"getLocalEndpoint", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)Lsun/rmi/transport/tcp/TCPEndpoint;", nullptr, $PUBLIC | $STATIC, $method(static_cast<TCPEndpoint*(*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&TCPEndpoint::getLocalEndpoint))},
	{"getOutboundTransport", "()Lsun/rmi/transport/Transport;", nullptr, $PUBLIC},
	{"getPort", "()I", nullptr, $PUBLIC},
	{"getServerSocketFactory", "()Ljava/rmi/server/RMIServerSocketFactory;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"lambda$getBoolean$1", "(Ljava/lang/String;)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)($String*)>(&TCPEndpoint::lambda$getBoolean$1))},
	{"lambda$getHostnameProperty$2", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)()>(&TCPEndpoint::lambda$getHostnameProperty$2))},
	{"lambda$getInt$0", "(Ljava/lang/String;I)Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)($String*,int32_t)>(&TCPEndpoint::lambda$getInt$0))},
	{"newServerSocket", "()Ljava/net/ServerSocket;", nullptr, 0, nullptr, "java.io.IOException"},
	{"newSocket", "()Ljava/net/Socket;", nullptr, 0, nullptr, "java.rmi.RemoteException"},
	{"read", "(Ljava/io/ObjectInput;)Lsun/rmi/transport/tcp/TCPEndpoint;", nullptr, $PUBLIC | $STATIC, $method(static_cast<TCPEndpoint*(*)($ObjectInput*)>(&TCPEndpoint::read)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readHostPortFormat", "(Ljava/io/DataInput;)Lsun/rmi/transport/tcp/TCPEndpoint;", nullptr, $PUBLIC | $STATIC, $method(static_cast<TCPEndpoint*(*)($DataInput*)>(&TCPEndpoint::readHostPortFormat)), "java.io.IOException"},
	{"resampleLocalHost", "()Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)()>(&TCPEndpoint::resampleLocalHost))},
	{"setDefaultPort", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $STATIC, $method(static_cast<void(*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&TCPEndpoint::setDefaultPort))},
	{"setLocalHost", "(Ljava/lang/String;)V", nullptr, $STATIC, $method(static_cast<void(*)($String*)>(&TCPEndpoint::setLocalHost))},
	{"shedConnectionCaches", "()V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)()>(&TCPEndpoint::shedConnectionCaches))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"write", "(Ljava/io/ObjectOutput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"writeHostPortFormat", "(Ljava/io/DataOutput;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _TCPEndpoint_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPEndpoint$FQDN", "sun.rmi.transport.tcp.TCPEndpoint", "FQDN", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _TCPEndpoint_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.tcp.TCPEndpoint",
	"java.lang.Object",
	"sun.rmi.transport.Endpoint",
	_TCPEndpoint_FieldInfo_,
	_TCPEndpoint_MethodInfo_,
	nullptr,
	nullptr,
	_TCPEndpoint_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPEndpoint$FQDN"
};

$Object* allocate$TCPEndpoint($Class* clazz) {
	return $of($alloc(TCPEndpoint));
}

$String* TCPEndpoint::localHost = nullptr;
bool TCPEndpoint::localHostKnown = false;
$Map* TCPEndpoint::localEndpoints = nullptr;

int32_t TCPEndpoint::getInt($String* name, int32_t def) {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPEndpoint$$Lambda$lambda$getInt$0, name, def)))))))->intValue();
}

bool TCPEndpoint::getBoolean($String* name) {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPEndpoint$$Lambda$lambda$getBoolean$1$1, name)))))))->booleanValue();
}

$String* TCPEndpoint::getHostnameProperty() {
	$init(TCPEndpoint);
	$beforeCallerSensitive();
	return $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2))));
}

void TCPEndpoint::init$($String* host, int32_t port) {
	TCPEndpoint::init$(host, port, nullptr, nullptr);
}

void TCPEndpoint::init$($String* host$renamed, int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	$var($String, host, host$renamed);
	this->listenPort = -1;
	$set(this, transport, nullptr);
	if (host == nullptr) {
		$assign(host, ""_s);
	}
	$set(this, host, host);
	this->port = port;
	$set(this, csf, csf);
	$set(this, ssf, ssf);
}

TCPEndpoint* TCPEndpoint::getLocalEndpoint(int32_t port) {
	$init(TCPEndpoint);
	return getLocalEndpoint(port, nullptr, nullptr);
}

TCPEndpoint* TCPEndpoint::getLocalEndpoint(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$var(TCPEndpoint, ep, nullptr);
	$synchronized(TCPEndpoint::localEndpoints) {
		$var(TCPEndpoint, endpointKey, $new(TCPEndpoint, nullptr, port, csf, ssf));
		$var($LinkedList, epList, $cast($LinkedList, $nc(TCPEndpoint::localEndpoints)->get(endpointKey)));
		$var($String, localHost, resampleLocalHost());
		if (epList == nullptr) {
			$assign(ep, $new(TCPEndpoint, localHost, port, csf, ssf));
			$assign(epList, $new($LinkedList));
			epList->add(ep);
			ep->listenPort = port;
			$set(ep, transport, $new($TCPTransport, epList));
			$nc(TCPEndpoint::localEndpoints)->put(endpointKey, epList);
			$init($TCPTransport);
			$init($Log);
			if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
				$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"created local endpoint for socket factory "_s, ssf, " on port "_s, $$str(port)}));
			}
		} else {
			$synchronized(epList) {
				$assign(ep, $cast(TCPEndpoint, $nc(epList)->getLast()));
				$var($String, lastHost, $nc(ep)->host);
				int32_t lastPort = ep->port;
				$var($TCPTransport, lastTransport, ep->transport);
				if (localHost != nullptr && !localHost->equals(lastHost)) {
					if (lastPort != 0) {
						epList->clear();
					}
					$assign(ep, $new(TCPEndpoint, localHost, lastPort, csf, ssf));
					ep->listenPort = port;
					$set(ep, transport, lastTransport);
					epList->add(ep);
				}
			}
		}
	}
	return ep;
}

$String* TCPEndpoint::resampleLocalHost() {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$var($String, hostnameProperty, getHostnameProperty());
	$synchronized(TCPEndpoint::localEndpoints) {
		if (hostnameProperty != nullptr) {
			if (!TCPEndpoint::localHostKnown) {
				setLocalHost(hostnameProperty);
			} else {
				if (!hostnameProperty->equals(TCPEndpoint::localHost)) {
					$assignStatic(TCPEndpoint::localHost, hostnameProperty);
					$init($TCPTransport);
					$init($Log);
					if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
						$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"updated local hostname to: "_s, TCPEndpoint::localHost}));
					}
				}
			}
		}
		return TCPEndpoint::localHost;
	}
}

void TCPEndpoint::setLocalHost($String* host) {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$synchronized(TCPEndpoint::localEndpoints) {
		if (!TCPEndpoint::localHostKnown) {
			$assignStatic(TCPEndpoint::localHost, host);
			TCPEndpoint::localHostKnown = true;
			$init($TCPTransport);
			$init($Log);
			if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
				$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"local host set to "_s, host}));
			}
			{
				$var($Iterator, i$, $nc($($nc(TCPEndpoint::localEndpoints)->values()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($LinkedList, epList, $cast($LinkedList, i$->next()));
					{
						$synchronized(epList) {
							{
								$var($Iterator, i$, $nc(epList)->iterator());
								for (; $nc(i$)->hasNext();) {
									$var(TCPEndpoint, ep, $cast(TCPEndpoint, i$->next()));
									{
										$set($nc(ep), host, host);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void TCPEndpoint::setDefaultPort(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$var(TCPEndpoint, endpointKey, $new(TCPEndpoint, nullptr, 0, csf, ssf));
	$synchronized(TCPEndpoint::localEndpoints) {
		$var($LinkedList, epList, $cast($LinkedList, $nc(TCPEndpoint::localEndpoints)->get(endpointKey)));
		$synchronized(epList) {
			int32_t size = $nc(epList)->size();
			$var(TCPEndpoint, lastEp, $cast(TCPEndpoint, epList->getLast()));
			{
				$var($Iterator, i$, epList->iterator());
				for (; $nc(i$)->hasNext();) {
					$var(TCPEndpoint, ep, $cast(TCPEndpoint, i$->next()));
					{
						$nc(ep)->port = port;
					}
				}
			}
			if (size > 1) {
				epList->clear();
				epList->add(lastEp);
			}
		}
		$var(TCPEndpoint, newEndpointKey, $new(TCPEndpoint, nullptr, port, csf, ssf));
		$nc(TCPEndpoint::localEndpoints)->put(newEndpointKey, epList);
		$init($TCPTransport);
		$init($Log);
		if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
			$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"default port for server socket factory "_s, ssf, " and client socket factory "_s, csf, " set to "_s, $$str(port)}));
		}
	}
}

$Transport* TCPEndpoint::getOutboundTransport() {
	$var(TCPEndpoint, localEndpoint, getLocalEndpoint(0, nullptr, nullptr));
	return $nc(localEndpoint)->transport;
}

$Collection* TCPEndpoint::allKnownTransports() {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$var($Set, s, nullptr);
	$synchronized(TCPEndpoint::localEndpoints) {
		$assign(s, $new($HashSet, $nc(TCPEndpoint::localEndpoints)->size()));
		{
			$var($Iterator, i$, $nc($($nc(TCPEndpoint::localEndpoints)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($LinkedList, epList, $cast($LinkedList, i$->next()));
				{
					$var(TCPEndpoint, ep, $cast(TCPEndpoint, $nc(epList)->getFirst()));
					s->add($nc(ep)->transport);
				}
			}
		}
	}
	return s;
}

void TCPEndpoint::shedConnectionCaches() {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($(allKnownTransports()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($TCPTransport, transport, $cast($TCPTransport, i$->next()));
			{
				$nc(transport)->shedConnectionCaches();
			}
		}
	}
}

void TCPEndpoint::exportObject($Target* target) {
	$nc(this->transport)->exportObject(target);
}

$Channel* TCPEndpoint::getChannel() {
	return $nc($(getOutboundTransport()))->getChannel(this);
}

$String* TCPEndpoint::getHost() {
	return this->host;
}

int32_t TCPEndpoint::getPort() {
	return this->port;
}

int32_t TCPEndpoint::getListenPort() {
	return this->listenPort;
}

$Transport* TCPEndpoint::getInboundTransport() {
	return this->transport;
}

$RMIClientSocketFactory* TCPEndpoint::getClientSocketFactory() {
	return this->csf;
}

$RMIServerSocketFactory* TCPEndpoint::getServerSocketFactory() {
	return this->ssf;
}

$String* TCPEndpoint::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$1, $$str({"["_s, this->host, ":"_s, $$str(this->port), (this->ssf != nullptr ? $$str({","_s, this->ssf}) : ""_s)}));
	$var($String, var$0, $$concat(var$1, (this->csf != nullptr ? $$str({","_s, this->csf}) : ""_s)));
	return $concat(var$0, "]");
}

int32_t TCPEndpoint::hashCode() {
	return this->port;
}

bool TCPEndpoint::equals(Object$* obj) {
	if ((obj != nullptr) && ($instanceOf(TCPEndpoint, obj))) {
		$var(TCPEndpoint, ep, $cast(TCPEndpoint, obj));
		if (this->port != ep->port || !$nc(this->host)->equals(ep->host)) {
			return false;
		}
		if (((this->csf == nullptr) ^ (ep->csf == nullptr)) || ((this->ssf == nullptr) ^ (ep->ssf == nullptr))) {
			return false;
		}
		bool var$0 = (this->csf != nullptr);
		if (var$0) {
			bool var$1 = $nc($of(this->csf))->getClass() == $nc($of(ep->csf))->getClass();
			var$0 = !(var$1 && $nc($of(this->csf))->equals(ep->csf));
		}
		if (var$0) {
			return false;
		}
		bool var$2 = (this->ssf != nullptr);
		if (var$2) {
			bool var$3 = $nc($of(this->ssf))->getClass() == $nc($of(ep->ssf))->getClass();
			var$2 = !(var$3 && $nc($of(this->ssf))->equals(ep->ssf));
		}
		if (var$2) {
			return false;
		}
		return true;
	} else {
		return false;
	}
}

void TCPEndpoint::write($ObjectOutput* out) {
	if (this->csf == nullptr) {
		$nc(out)->writeByte(TCPEndpoint::FORMAT_HOST_PORT);
		out->writeUTF(this->host);
		out->writeInt(this->port);
	} else {
		$nc(out)->writeByte(TCPEndpoint::FORMAT_HOST_PORT_FACTORY);
		out->writeUTF(this->host);
		out->writeInt(this->port);
		out->writeObject(this->csf);
	}
}

TCPEndpoint* TCPEndpoint::read($ObjectInput* in) {
	$init(TCPEndpoint);
	$useLocalCurrentObjectStackCache();
	$var($String, host, nullptr);
	int32_t port = 0;
	$var($RMIClientSocketFactory, csf, nullptr);
	int8_t format = $nc(in)->readByte();
	switch (format) {
	case TCPEndpoint::FORMAT_HOST_PORT:
		{
			$assign(host, in->readUTF());
			port = in->readInt();
			break;
		}
	case TCPEndpoint::FORMAT_HOST_PORT_FACTORY:
		{
			$assign(host, in->readUTF());
			port = in->readInt();
			$assign(csf, $cast($RMIClientSocketFactory, in->readObject()));
			if (csf != nullptr && $Proxy::isProxyClass($of(csf)->getClass())) {
				$throwNew($IOException, "Invalid SocketFactory"_s);
			}
			break;
		}
	default:
		{
			$throwNew($IOException, "invalid endpoint format"_s);
		}
	}
	return $new(TCPEndpoint, host, port, csf, nullptr);
}

void TCPEndpoint::writeHostPortFormat($DataOutput* out) {
	if (this->csf != nullptr) {
		$throwNew($InternalError, "TCPEndpoint.writeHostPortFormat: called for endpoint with non-null socket factory"_s);
	}
	$nc(out)->writeUTF(this->host);
	out->writeInt(this->port);
}

TCPEndpoint* TCPEndpoint::readHostPortFormat($DataInput* in) {
	$init(TCPEndpoint);
	$var($String, host, $nc(in)->readUTF());
	int32_t port = in->readInt();
	return $new(TCPEndpoint, host, port);
}

$RMISocketFactory* TCPEndpoint::chooseFactory() {
	$init(TCPEndpoint);
	$var($RMISocketFactory, sf, $RMISocketFactory::getSocketFactory());
	if (sf == nullptr) {
		$init($TCPTransport);
		$assign(sf, $TCPTransport::defaultSocketFactory);
	}
	return sf;
}

$Socket* TCPEndpoint::newSocket() {
	$useLocalCurrentObjectStackCache();
	$init($TCPTransport);
	$init($Log);
	if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
		$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"opening socket to "_s, this}));
	}
	$var($Socket, socket, nullptr);
	try {
		$var($RMIClientSocketFactory, clientFactory, this->csf);
		if (clientFactory == nullptr) {
			$assign(clientFactory, chooseFactory());
		}
		$assign(socket, $nc(clientFactory)->createSocket(this->host, this->port));
	} catch ($1UnknownHostException& e) {
		$throwNew($UnknownHostException, $$str({"Unknown host: "_s, this->host}), e);
	} catch ($ConnectException& e) {
		$throwNew($1ConnectException, $$str({"Connection refused to host: "_s, this->host}), e);
	} catch ($IOException& e) {
		try {
			TCPEndpoint::shedConnectionCaches();
		} catch ($OutOfMemoryError& mem) {
		} catch ($Exception& mem) {
		}
		$throwNew($ConnectIOException, $$str({"Exception creating connection to: "_s, this->host}), e);
	}
	try {
		$nc(socket)->setTcpNoDelay(true);
	} catch ($Exception& e) {
	}
	try {
		$nc(socket)->setKeepAlive(true);
	} catch ($Exception& e) {
	}
	return socket;
}

$ServerSocket* TCPEndpoint::newServerSocket() {
	$useLocalCurrentObjectStackCache();
	$init($TCPTransport);
	$init($Log);
	if ($nc($TCPTransport::tcpLog)->isLoggable($Log::VERBOSE)) {
		$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, $$str({"creating server socket on "_s, this}));
	}
	$var($RMIServerSocketFactory, serverFactory, this->ssf);
	if (serverFactory == nullptr) {
		$assign(serverFactory, chooseFactory());
	}
	$var($ServerSocket, server, $nc(serverFactory)->createServerSocket(this->listenPort));
	if (this->listenPort == 0) {
		setDefaultPort($nc(server)->getLocalPort(), this->csf, this->ssf);
	}
	return server;
}

$String* TCPEndpoint::lambda$getHostnameProperty$2() {
	$init(TCPEndpoint);
	return $System::getProperty("java.rmi.server.hostname"_s);
}

$Boolean* TCPEndpoint::lambda$getBoolean$1($String* name) {
	$init(TCPEndpoint);
	return $Boolean::valueOf($Boolean::getBoolean(name));
}

$Integer* TCPEndpoint::lambda$getInt$0($String* name, int32_t def) {
	$init(TCPEndpoint);
	return $Integer::getInteger(name, def);
}

void clinit$TCPEndpoint($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		TCPEndpoint::localHostKnown = true;
		$assignStatic(TCPEndpoint::localHost, TCPEndpoint::getHostnameProperty());
		if (TCPEndpoint::localHost == nullptr) {
			try {
				$var($InetAddress, localAddr, $InetAddress::getLocalHost());
				$var($bytes, raw, $nc(localAddr)->getAddress());
				if (($nc(raw)->get(0) == 127) && (raw->get(1) == 0) && (raw->get(2) == 0) && (raw->get(3) == 1)) {
					TCPEndpoint::localHostKnown = false;
				}
				if (TCPEndpoint::getBoolean("java.rmi.server.useLocalHostName"_s)) {
					$assignStatic(TCPEndpoint::localHost, $TCPEndpoint$FQDN::attemptFQDN(localAddr));
				} else {
					$assignStatic(TCPEndpoint::localHost, localAddr->getHostAddress());
				}
			} catch ($Exception& e) {
				TCPEndpoint::localHostKnown = false;
				$assignStatic(TCPEndpoint::localHost, nullptr);
			}
		}
		$init($TCPTransport);
		$init($Log);
		if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
			$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"localHostKnown = "_s, $$str(TCPEndpoint::localHostKnown), ", localHost = "_s, TCPEndpoint::localHost}));
		}
	}
	$assignStatic(TCPEndpoint::localEndpoints, $new($HashMap));
}

TCPEndpoint::TCPEndpoint() {
}

$Class* TCPEndpoint::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(TCPEndpoint$$Lambda$lambda$getInt$0::classInfo$.name)) {
			return TCPEndpoint$$Lambda$lambda$getInt$0::load$(name, initialize);
		}
		if (name->equals(TCPEndpoint$$Lambda$lambda$getBoolean$1$1::classInfo$.name)) {
			return TCPEndpoint$$Lambda$lambda$getBoolean$1$1::load$(name, initialize);
		}
		if (name->equals(TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::classInfo$.name)) {
			return TCPEndpoint$$Lambda$lambda$getHostnameProperty$2$2::load$(name, initialize);
		}
	}
	$loadClass(TCPEndpoint, name, initialize, &_TCPEndpoint_ClassInfo_, clinit$TCPEndpoint, allocate$TCPEndpoint);
	return class$;
}

$Class* TCPEndpoint::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun