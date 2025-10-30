#include <sun/rmi/transport/tcp/TCPConnection.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/FilterInputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/net/Socket.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <sun/rmi/transport/tcp/TCPChannel.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef BRIEF
#undef MAX_VALUE
#undef MIN_VALUE
#undef VERBOSE

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Socket = ::java::net::Socket;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $TransportConstants = ::sun::rmi::transport::TransportConstants;
using $TCPChannel = ::sun::rmi::transport::tcp::TCPChannel;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$FieldInfo _TCPConnection_FieldInfo_[] = {
	{"socket", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(TCPConnection, socket)},
	{"channel", "Lsun/rmi/transport/Channel;", nullptr, $PRIVATE, $field(TCPConnection, channel)},
	{"in", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(TCPConnection, in)},
	{"out", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(TCPConnection, out)},
	{"expiration", "J", nullptr, $PRIVATE, $field(TCPConnection, expiration)},
	{"lastuse", "J", nullptr, $PRIVATE, $field(TCPConnection, lastuse)},
	{"roundtrip", "J", nullptr, $PRIVATE, $field(TCPConnection, roundtrip)},
	{}
};

$MethodInfo _TCPConnection_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPChannel;Ljava/net/Socket;Ljava/io/InputStream;Ljava/io/OutputStream;)V", nullptr, 0, $method(static_cast<void(TCPConnection::*)($TCPChannel*,$Socket*,$InputStream*,$OutputStream*)>(&TCPConnection::init$))},
	{"<init>", "(Lsun/rmi/transport/tcp/TCPChannel;Ljava/io/InputStream;Ljava/io/OutputStream;)V", nullptr, 0, $method(static_cast<void(TCPConnection::*)($TCPChannel*,$InputStream*,$OutputStream*)>(&TCPConnection::init$))},
	{"<init>", "(Lsun/rmi/transport/tcp/TCPChannel;Ljava/net/Socket;)V", nullptr, 0, $method(static_cast<void(TCPConnection::*)($TCPChannel*,$Socket*)>(&TCPConnection::init$))},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"expired", "(J)Z", nullptr, 0},
	{"getChannel", "()Lsun/rmi/transport/Channel;", nullptr, $PUBLIC},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"isDead", "()Z", nullptr, $PUBLIC},
	{"isReusable", "()Z", nullptr, $PUBLIC},
	{"releaseInputStream", "()V", nullptr, $PUBLIC},
	{"releaseOutputStream", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"setExpiration", "(J)V", nullptr, 0},
	{"setLastUseTime", "(J)V", nullptr, 0},
	{}
};

$ClassInfo _TCPConnection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.tcp.TCPConnection",
	"java.lang.Object",
	"sun.rmi.transport.Connection",
	_TCPConnection_FieldInfo_,
	_TCPConnection_MethodInfo_
};

$Object* allocate$TCPConnection($Class* clazz) {
	return $of($alloc(TCPConnection));
}

void TCPConnection::init$($TCPChannel* ch, $Socket* s, $InputStream* in, $OutputStream* out) {
	$set(this, in, nullptr);
	$set(this, out, nullptr);
	this->expiration = $Long::MAX_VALUE;
	this->lastuse = $Long::MIN_VALUE;
	this->roundtrip = 5;
	$set(this, socket, s);
	$set(this, channel, ch);
	$set(this, in, in);
	$set(this, out, out);
}

void TCPConnection::init$($TCPChannel* ch, $InputStream* in, $OutputStream* out) {
	TCPConnection::init$(ch, nullptr, in, out);
}

void TCPConnection::init$($TCPChannel* ch, $Socket* s) {
	TCPConnection::init$(ch, s, nullptr, nullptr);
}

$OutputStream* TCPConnection::getOutputStream() {
	if (this->out == nullptr) {
		$set(this, out, $new($BufferedOutputStream, $($nc(this->socket)->getOutputStream())));
	}
	return this->out;
}

void TCPConnection::releaseOutputStream() {
	if (this->out != nullptr) {
		$nc(this->out)->flush();
	}
}

$InputStream* TCPConnection::getInputStream() {
	if (this->in == nullptr) {
		$set(this, in, $new($BufferedInputStream, $($nc(this->socket)->getInputStream())));
	}
	return this->in;
}

void TCPConnection::releaseInputStream() {
}

bool TCPConnection::isReusable() {
	return true;
}

void TCPConnection::setExpiration(int64_t time) {
	this->expiration = time;
}

void TCPConnection::setLastUseTime(int64_t time) {
	this->lastuse = time;
}

bool TCPConnection::expired(int64_t time) {
	return this->expiration <= time;
}

bool TCPConnection::isDead() {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, i, nullptr);
	$var($OutputStream, o, nullptr);
	int64_t start = $System::currentTimeMillis();
	if ((this->roundtrip > 0) && (start < this->lastuse + this->roundtrip)) {
		return (false);
	}
	try {
		$assign(i, getInputStream());
		$assign(o, getOutputStream());
	} catch ($IOException& e) {
		return (true);
	}
	int32_t response = 0;
	try {
		$nc(o)->write((int32_t)$TransportConstants::Ping);
		o->flush();
		response = $nc(i)->read();
	} catch ($IOException& ex) {
		$init($TCPTransport);
		$init($Log);
		$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, "exception: "_s, ex);
		$nc($TCPTransport::tcpLog)->log($Log::BRIEF, "server ping failed"_s);
		return (true);
	}
	if (response == $TransportConstants::PingAck) {
		this->roundtrip = ($System::currentTimeMillis() - start) * 2;
		return (false);
	}
	$init($TCPTransport);
	$init($Log);
	if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
		$nc($TCPTransport::tcpLog)->log($Log::BRIEF, (response == -1 ? "server has been deactivated"_s : $$str({"server protocol error: ping response = "_s, $$str(response)})));
	}
	return (true);
}

void TCPConnection::close() {
	$init($TCPTransport);
	$init($Log);
	if ($nc($TCPTransport::tcpLog)->isLoggable($Log::BRIEF)) {
		$nc($TCPTransport::tcpLog)->log($Log::BRIEF, $$str({"close connection, socket: "_s, this->socket}));
	}
	if (this->socket != nullptr) {
		$nc(this->socket)->close();
	} else {
		$nc(this->in)->close();
		$nc(this->out)->close();
	}
}

$Channel* TCPConnection::getChannel() {
	return this->channel;
}

TCPConnection::TCPConnection() {
}

$Class* TCPConnection::load$($String* name, bool initialize) {
	$loadClass(TCPConnection, name, initialize, &_TCPConnection_ClassInfo_, allocate$TCPConnection);
	return class$;
}

$Class* TCPConnection::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun