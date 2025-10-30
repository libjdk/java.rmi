#include <sun/rmi/transport/tcp/TCPChannel$1.h>

#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/transport/tcp/TCPChannel.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <jcpp.h>

#undef VERBOSE

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $TCPChannel = ::sun::rmi::transport::tcp::TCPChannel;
using $TCPTransport = ::sun::rmi::transport::tcp::TCPTransport;

namespace sun {
	namespace rmi {
		namespace transport {
			namespace tcp {

$FieldInfo _TCPChannel$1_FieldInfo_[] = {
	{"this$0", "Lsun/rmi/transport/tcp/TCPChannel;", nullptr, $FINAL | $SYNTHETIC, $field(TCPChannel$1, this$0)},
	{}
};

$MethodInfo _TCPChannel$1_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/tcp/TCPChannel;)V", nullptr, 0, $method(static_cast<void(TCPChannel$1::*)($TCPChannel*)>(&TCPChannel$1::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _TCPChannel$1_EnclosingMethodInfo_ = {
	"sun.rmi.transport.tcp.TCPChannel",
	"free",
	"(Lsun/rmi/transport/Connection;Z)V"
};

$InnerClassInfo _TCPChannel$1_InnerClassesInfo_[] = {
	{"sun.rmi.transport.tcp.TCPChannel$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TCPChannel$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.tcp.TCPChannel$1",
	"java.lang.Object",
	"java.lang.Runnable",
	_TCPChannel$1_FieldInfo_,
	_TCPChannel$1_MethodInfo_,
	nullptr,
	&_TCPChannel$1_EnclosingMethodInfo_,
	_TCPChannel$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.tcp.TCPChannel"
};

$Object* allocate$TCPChannel$1($Class* clazz) {
	return $of($alloc(TCPChannel$1));
}

void TCPChannel$1::init$($TCPChannel* this$0) {
	$set(this, this$0, this$0);
}

void TCPChannel$1::run() {
	$init($TCPTransport);
	$init($Log);
	$nc($TCPTransport::tcpLog)->log($Log::VERBOSE, "wake up"_s);
	this->this$0->freeCachedConnections();
}

TCPChannel$1::TCPChannel$1() {
}

$Class* TCPChannel$1::load$($String* name, bool initialize) {
	$loadClass(TCPChannel$1, name, initialize, &_TCPChannel$1_ClassInfo_, allocate$TCPChannel$1);
	return class$;
}

$Class* TCPChannel$1::class$ = nullptr;

			} // tcp
		} // transport
	} // rmi
} // sun