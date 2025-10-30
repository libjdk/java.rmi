#include <sun/rmi/transport/LiveRef.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectOutput.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/Cloneable.h>
#include <java/lang/InternalError.h>
#include <java/rmi/Remote.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/ConnectionInputStream.h>
#include <sun/rmi/transport/ConnectionOutputStream.h>
#include <sun/rmi/transport/DGCClient.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/ObjectEndpoint.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <jcpp.h>

using $LiveRefArray = $Array<::sun::rmi::transport::LiveRef>;
using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Remote = ::java::rmi::Remote;
using $ObjID = ::java::rmi::server::ObjID;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Channel = ::sun::rmi::transport::Channel;
using $ConnectionInputStream = ::sun::rmi::transport::ConnectionInputStream;
using $ConnectionOutputStream = ::sun::rmi::transport::ConnectionOutputStream;
using $DGCClient = ::sun::rmi::transport::DGCClient;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $ObjectEndpoint = ::sun::rmi::transport::ObjectEndpoint;
using $ObjectTable = ::sun::rmi::transport::ObjectTable;
using $Target = ::sun::rmi::transport::Target;
using $Transport = ::sun::rmi::transport::Transport;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _LiveRef_FieldInfo_[] = {
	{"ep", "Lsun/rmi/transport/Endpoint;", nullptr, $PRIVATE | $FINAL, $field(LiveRef, ep)},
	{"id", "Ljava/rmi/server/ObjID;", nullptr, $PRIVATE | $FINAL, $field(LiveRef, id)},
	{"ch", "Lsun/rmi/transport/Channel;", nullptr, $PRIVATE | $TRANSIENT, $field(LiveRef, ch)},
	{"isLocal", "Z", nullptr, $PRIVATE | $FINAL, $field(LiveRef, isLocal)},
	{}
};

$MethodInfo _LiveRef_MethodInfo_[] = {
	{"<init>", "(Ljava/rmi/server/ObjID;Lsun/rmi/transport/Endpoint;Z)V", nullptr, $PUBLIC, $method(static_cast<void(LiveRef::*)($ObjID*,$Endpoint*,bool)>(&LiveRef::init$))},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(LiveRef::*)(int32_t)>(&LiveRef::init$))},
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $PUBLIC, $method(static_cast<void(LiveRef::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&LiveRef::init$))},
	{"<init>", "(Ljava/rmi/server/ObjID;I)V", nullptr, $PUBLIC, $method(static_cast<void(LiveRef::*)($ObjID*,int32_t)>(&LiveRef::init$))},
	{"<init>", "(Ljava/rmi/server/ObjID;ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $PUBLIC, $method(static_cast<void(LiveRef::*)($ObjID*,int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&LiveRef::init$))},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"exportObject", "(Lsun/rmi/transport/Target;)V", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"getChannel", "()Lsun/rmi/transport/Channel;", nullptr, $PUBLIC, nullptr, "java.rmi.RemoteException"},
	{"getClientSocketFactory", "()Ljava/rmi/server/RMIClientSocketFactory;", nullptr, $PUBLIC},
	{"getEndpoint", "()Lsun/rmi/transport/Endpoint;", nullptr, 0},
	{"getObjID", "()Ljava/rmi/server/ObjID;", nullptr, $PUBLIC},
	{"getPort", "()I", nullptr, $PUBLIC},
	{"getServerSocketFactory", "()Ljava/rmi/server/RMIServerSocketFactory;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"read", "(Ljava/io/ObjectInput;Z)Lsun/rmi/transport/LiveRef;", nullptr, $PUBLIC | $STATIC, $method(static_cast<LiveRef*(*)($ObjectInput*,bool)>(&LiveRef::read)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"remoteEquals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"write", "(Ljava/io/ObjectOutput;Z)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _LiveRef_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.LiveRef",
	"java.lang.Object",
	"java.lang.Cloneable",
	_LiveRef_FieldInfo_,
	_LiveRef_MethodInfo_
};

$Object* allocate$LiveRef($Class* clazz) {
	return $of($alloc(LiveRef));
}

void LiveRef::init$($ObjID* objID, $Endpoint* endpoint, bool isLocal) {
	$set(this, ep, endpoint);
	$set(this, id, objID);
	this->isLocal = isLocal;
}

void LiveRef::init$(int32_t port) {
	LiveRef::init$(($$new($ObjID)), port);
}

void LiveRef::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	LiveRef::init$(($$new($ObjID)), port, csf, ssf);
}

void LiveRef::init$($ObjID* objID, int32_t port) {
	LiveRef::init$(objID, $(static_cast<$Endpoint*>($TCPEndpoint::getLocalEndpoint(port))), true);
}

void LiveRef::init$($ObjID* objID, int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	LiveRef::init$(objID, $(static_cast<$Endpoint*>($TCPEndpoint::getLocalEndpoint(port, csf, ssf))), true);
}

$Object* LiveRef::clone() {
	$useLocalCurrentObjectStackCache();
	try {
		$var(LiveRef, newRef, $cast(LiveRef, $Cloneable::clone()));
		return $of(newRef);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, $(e->toString()), e);
	}
	$shouldNotReachHere();
}

int32_t LiveRef::getPort() {
	return $nc(($cast($TCPEndpoint, this->ep)))->getPort();
}

$RMIClientSocketFactory* LiveRef::getClientSocketFactory() {
	return $nc(($cast($TCPEndpoint, this->ep)))->getClientSocketFactory();
}

$RMIServerSocketFactory* LiveRef::getServerSocketFactory() {
	return $nc(($cast($TCPEndpoint, this->ep)))->getServerSocketFactory();
}

void LiveRef::exportObject($Target* target) {
	$nc(this->ep)->exportObject(target);
}

$Channel* LiveRef::getChannel() {
	if (this->ch == nullptr) {
		$set(this, ch, $nc(this->ep)->getChannel());
	}
	return this->ch;
}

$ObjID* LiveRef::getObjID() {
	return this->id;
}

$Endpoint* LiveRef::getEndpoint() {
	return this->ep;
}

$String* LiveRef::toString() {
	$var($String, type, nullptr);
	if (this->isLocal) {
		$assign(type, "local"_s);
	} else {
		$assign(type, "remote"_s);
	}
	return $str({"[endpoint:"_s, this->ep, "("_s, type, "),objID:"_s, this->id, "]"_s});
}

int32_t LiveRef::hashCode() {
	return $nc(this->id)->hashCode();
}

bool LiveRef::equals(Object$* obj) {
	if (obj != nullptr && $instanceOf(LiveRef, obj)) {
		$var(LiveRef, ref, $cast(LiveRef, obj));
		bool var$0 = $nc($of(this->ep))->equals(ref->ep);
		return (var$0 && $nc(this->id)->equals(ref->id) && this->isLocal == ref->isLocal);
	} else {
		return false;
	}
}

bool LiveRef::remoteEquals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (obj != nullptr && $instanceOf(LiveRef, obj)) {
		$var(LiveRef, ref, $cast(LiveRef, obj));
		$var($TCPEndpoint, thisEp, $cast($TCPEndpoint, this->ep));
		$var($TCPEndpoint, refEp, $cast($TCPEndpoint, ref->ep));
		$var($RMIClientSocketFactory, thisClientFactory, $nc(thisEp)->getClientSocketFactory());
		$var($RMIClientSocketFactory, refClientFactory, $nc(refEp)->getClientSocketFactory());
		int32_t var$1 = thisEp->getPort();
		bool var$0 = var$1 != refEp->getPort();
		if (var$0 || !$nc($(thisEp->getHost()))->equals($(refEp->getHost()))) {
			return false;
		}
		if ((thisClientFactory == nullptr) ^ (refClientFactory == nullptr)) {
			return false;
		}
		bool var$2 = (thisClientFactory != nullptr);
		if (var$2) {
			bool var$3 = ($of(thisClientFactory)->getClass() == $nc($of(refClientFactory))->getClass());
			var$2 = !(var$3 && ($of(thisClientFactory)->equals(refClientFactory)));
		}
		if (var$2) {
			return false;
		}
		return ($nc(this->id)->equals(ref->id));
	} else {
		return false;
	}
}

void LiveRef::write($ObjectOutput* out, bool useNewFormat) {
	$useLocalCurrentObjectStackCache();
	bool isResultStream = false;
	if ($instanceOf($ConnectionOutputStream, out)) {
		$var($ConnectionOutputStream, stream, $cast($ConnectionOutputStream, out));
		isResultStream = $nc(stream)->isResultStream();
		if (this->isLocal) {
			$var($ObjectEndpoint, oe, $new($ObjectEndpoint, this->id, $($nc(this->ep)->getInboundTransport())));
			$var($Target, target, $ObjectTable::getTarget(oe));
			if (target != nullptr) {
				$var($Remote, impl, target->getImpl());
				if (impl != nullptr) {
					stream->saveObject(impl);
				}
			}
		} else {
			stream->saveObject(this);
		}
	}
	if (useNewFormat) {
		$nc(($cast($TCPEndpoint, this->ep)))->write(out);
	} else {
		$nc(($cast($TCPEndpoint, this->ep)))->writeHostPortFormat(out);
	}
	$nc(this->id)->write(out);
	$nc(out)->writeBoolean(isResultStream);
}

LiveRef* LiveRef::read($ObjectInput* in, bool useNewFormat) {
	$init(LiveRef);
	$useLocalCurrentObjectStackCache();
	$var($Endpoint, ep, nullptr);
	$var($ObjID, id, nullptr);
	if (useNewFormat) {
		$assign(ep, $TCPEndpoint::read(in));
	} else {
		$assign(ep, $TCPEndpoint::readHostPortFormat(in));
	}
	$assign(id, $ObjID::read(in));
	bool isResultStream = $nc(in)->readBoolean();
	$var(LiveRef, ref, $new(LiveRef, id, ep, false));
	if ($instanceOf($ConnectionInputStream, in)) {
		$var($ConnectionInputStream, stream, $cast($ConnectionInputStream, in));
		stream->saveRef(ref);
		if (isResultStream) {
			stream->setAckNeeded();
		}
	} else {
		$DGCClient::registerRefs(ep, $($Arrays::asList($$new($LiveRefArray, {ref}))));
	}
	return ref;
}

LiveRef::LiveRef() {
}

$Class* LiveRef::load$($String* name, bool initialize) {
	$loadClass(LiveRef, name, initialize, &_LiveRef_ClassInfo_, allocate$LiveRef);
	return class$;
}

$Class* LiveRef::class$ = nullptr;

		} // transport
	} // rmi
} // sun