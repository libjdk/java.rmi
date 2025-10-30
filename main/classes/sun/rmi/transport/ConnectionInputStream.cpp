#include <sun/rmi/transport/ConnectionInputStream.h>

#include <java/io/DataInput.h>
#include <java/io/DataOutput.h>
#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/OutputStream.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/server/UID.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/MarshalInputStream.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/DGCClient.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <jcpp.h>

#undef VERBOSE

using $DataInput = ::java::io::DataInput;
using $DataOutput = ::java::io::DataOutput;
using $DataOutputStream = ::java::io::DataOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RemoteException = ::java::rmi::RemoteException;
using $UID = ::java::rmi::server::UID;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $MarshalInputStream = ::sun::rmi::server::MarshalInputStream;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $DGCClient = ::sun::rmi::transport::DGCClient;
using $DGCImpl = ::sun::rmi::transport::DGCImpl;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $LiveRef = ::sun::rmi::transport::LiveRef;
using $TransportConstants = ::sun::rmi::transport::TransportConstants;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _ConnectionInputStream_FieldInfo_[] = {
	{"dgcAckNeeded", "Z", nullptr, $PRIVATE, $field(ConnectionInputStream, dgcAckNeeded)},
	{"incomingRefTable", "Ljava/util/Map;", "Ljava/util/Map<Lsun/rmi/transport/Endpoint;Ljava/util/List<Lsun/rmi/transport/LiveRef;>;>;", $PRIVATE, $field(ConnectionInputStream, incomingRefTable)},
	{"ackID", "Ljava/rmi/server/UID;", nullptr, $PRIVATE, $field(ConnectionInputStream, ackID)},
	{}
};

$MethodInfo _ConnectionInputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, 0, $method(static_cast<void(ConnectionInputStream::*)($InputStream*)>(&ConnectionInputStream::init$)), "java.io.IOException"},
	{"discardRefs", "()V", nullptr, 0},
	{"done", "(Lsun/rmi/transport/Connection;)V", nullptr, 0},
	{"readID", "()V", nullptr, 0, nullptr, "java.io.IOException"},
	{"registerRefs", "()V", nullptr, 0, nullptr, "java.io.IOException"},
	{"saveRef", "(Lsun/rmi/transport/LiveRef;)V", nullptr, 0},
	{"setAckNeeded", "()V", nullptr, 0},
	{}
};

$ClassInfo _ConnectionInputStream_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.ConnectionInputStream",
	"sun.rmi.server.MarshalInputStream",
	nullptr,
	_ConnectionInputStream_FieldInfo_,
	_ConnectionInputStream_MethodInfo_
};

$Object* allocate$ConnectionInputStream($Class* clazz) {
	return $of($alloc(ConnectionInputStream));
}

void ConnectionInputStream::init$($InputStream* in) {
	$MarshalInputStream::init$(in);
	this->dgcAckNeeded = false;
	$set(this, incomingRefTable, $new($HashMap, 5));
}

void ConnectionInputStream::readID() {
	$set(this, ackID, $UID::read(static_cast<$DataInput*>(this)));
}

void ConnectionInputStream::saveRef($LiveRef* ref) {
	$useLocalCurrentObjectStackCache();
	$var($Endpoint, ep, $nc(ref)->getEndpoint());
	$var($List, refList, $cast($List, $nc(this->incomingRefTable)->get(ep)));
	if (refList == nullptr) {
		$assign(refList, $new($ArrayList));
		$nc(this->incomingRefTable)->put(ep, refList);
	}
	$nc(refList)->add(ref);
}

void ConnectionInputStream::discardRefs() {
	$nc(this->incomingRefTable)->clear();
}

void ConnectionInputStream::registerRefs() {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->incomingRefTable)->isEmpty()) {
		{
			$var($Iterator, i$, $nc($($nc(this->incomingRefTable)->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($Endpoint, var$0, $cast($Endpoint, $nc(entry)->getKey()));
					$DGCClient::registerRefs(var$0, $cast($List, $(entry->getValue())));
				}
			}
		}
	}
}

void ConnectionInputStream::setAckNeeded() {
	this->dgcAckNeeded = true;
}

void ConnectionInputStream::done($Connection* c) {
	$useLocalCurrentObjectStackCache();
	if (this->dgcAckNeeded) {
		$var($Connection, conn, nullptr);
		$var($Channel, ch, nullptr);
		bool reuse = true;
		$init($DGCImpl);
		$init($Log);
		$nc($DGCImpl::dgcLog)->log($Log::VERBOSE, "send ack"_s);
		try {
			$assign(ch, $nc(c)->getChannel());
			$assign(conn, $nc(ch)->newConnection());
			$var($DataOutputStream, out, $new($DataOutputStream, $($nc(conn)->getOutputStream())));
			out->writeByte($TransportConstants::DGCAck);
			if (this->ackID == nullptr) {
				$set(this, ackID, $new($UID));
			}
			$nc(this->ackID)->write(static_cast<$DataOutput*>(out));
			$nc(conn)->releaseOutputStream();
			$nc($(conn->getInputStream()))->available();
			conn->releaseInputStream();
		} catch ($RemoteException& e) {
			reuse = false;
		} catch ($IOException& e) {
			reuse = false;
		}
		try {
			if (conn != nullptr) {
				$nc(ch)->free(conn, reuse);
			}
		} catch ($RemoteException& e) {
		}
	}
}

ConnectionInputStream::ConnectionInputStream() {
}

$Class* ConnectionInputStream::load$($String* name, bool initialize) {
	$loadClass(ConnectionInputStream, name, initialize, &_ConnectionInputStream_ClassInfo_, allocate$ConnectionInputStream);
	return class$;
}

$Class* ConnectionInputStream::class$ = nullptr;

		} // transport
	} // rmi
} // sun