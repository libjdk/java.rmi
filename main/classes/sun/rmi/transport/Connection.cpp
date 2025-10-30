#include <sun/rmi/transport/Connection.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <sun/rmi/transport/Channel.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Channel = ::sun::rmi::transport::Channel;

namespace sun {
	namespace rmi {
		namespace transport {

$MethodInfo _Connection_MethodInfo_[] = {
	{"close", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getChannel", "()Lsun/rmi/transport/Channel;", nullptr, $PUBLIC | $ABSTRACT},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"isReusable", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"releaseInputStream", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{"releaseOutputStream", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.io.IOException"},
	{}
};

$ClassInfo _Connection_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.rmi.transport.Connection",
	nullptr,
	nullptr,
	nullptr,
	_Connection_MethodInfo_
};

$Object* allocate$Connection($Class* clazz) {
	return $of($alloc(Connection));
}

$Class* Connection::load$($String* name, bool initialize) {
	$loadClass(Connection, name, initialize, &_Connection_ClassInfo_, allocate$Connection);
	return class$;
}

$Class* Connection::class$ = nullptr;

		} // transport
	} // rmi
} // sun