#include <javax/rmi/ssl/SslRMIServerSocketFactory$1.h>

#include <java/net/InetAddress.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <javax/rmi/ssl/SslRMIServerSocketFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;
using $SslRMIServerSocketFactory = ::javax::rmi::ssl::SslRMIServerSocketFactory;

namespace javax {
	namespace rmi {
		namespace ssl {

$FieldInfo _SslRMIServerSocketFactory$1_FieldInfo_[] = {
	{"this$0", "Ljavax/rmi/ssl/SslRMIServerSocketFactory;", nullptr, $FINAL | $SYNTHETIC, $field(SslRMIServerSocketFactory$1, this$0)},
	{"val$sslSocketFactory", "Ljavax/net/ssl/SSLSocketFactory;", nullptr, $FINAL | $SYNTHETIC, $field(SslRMIServerSocketFactory$1, val$sslSocketFactory)},
	{}
};

$MethodInfo _SslRMIServerSocketFactory$1_MethodInfo_[] = {
	{"<init>", "(Ljavax/rmi/ssl/SslRMIServerSocketFactory;ILjavax/net/ssl/SSLSocketFactory;)V", nullptr, 0, $method(static_cast<void(SslRMIServerSocketFactory$1::*)($SslRMIServerSocketFactory*,int32_t,$SSLSocketFactory*)>(&SslRMIServerSocketFactory$1::init$)), "java.io.IOException"},
	{"accept", "()Ljava/net/Socket;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$EnclosingMethodInfo _SslRMIServerSocketFactory$1_EnclosingMethodInfo_ = {
	"javax.rmi.ssl.SslRMIServerSocketFactory",
	"createServerSocket",
	"(I)Ljava/net/ServerSocket;"
};

$InnerClassInfo _SslRMIServerSocketFactory$1_InnerClassesInfo_[] = {
	{"javax.rmi.ssl.SslRMIServerSocketFactory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SslRMIServerSocketFactory$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.rmi.ssl.SslRMIServerSocketFactory$1",
	"java.net.ServerSocket",
	nullptr,
	_SslRMIServerSocketFactory$1_FieldInfo_,
	_SslRMIServerSocketFactory$1_MethodInfo_,
	nullptr,
	&_SslRMIServerSocketFactory$1_EnclosingMethodInfo_,
	_SslRMIServerSocketFactory$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.rmi.ssl.SslRMIServerSocketFactory"
};

$Object* allocate$SslRMIServerSocketFactory$1($Class* clazz) {
	return $of($alloc(SslRMIServerSocketFactory$1));
}

void SslRMIServerSocketFactory$1::init$($SslRMIServerSocketFactory* this$0, int32_t arg0, $SSLSocketFactory* val$sslSocketFactory) {
	$set(this, this$0, this$0);
	$set(this, val$sslSocketFactory, val$sslSocketFactory);
	$ServerSocket::init$(arg0);
}

$Socket* SslRMIServerSocketFactory$1::accept() {
	$useLocalCurrentObjectStackCache();
	$var($Socket, socket, $ServerSocket::accept());
	$var($Socket, var$0, socket);
	$var($String, var$1, $nc($($nc(socket)->getInetAddress()))->getHostName());
	$var($SSLSocket, sslSocket, $cast($SSLSocket, $nc(this->val$sslSocketFactory)->createSocket(var$0, var$1, socket->getPort(), true)));
	$nc(sslSocket)->setUseClientMode(false);
	if (this->this$0->enabledCipherSuites != nullptr) {
		sslSocket->setEnabledCipherSuites(this->this$0->enabledCipherSuites);
	}
	if (this->this$0->enabledProtocols != nullptr) {
		sslSocket->setEnabledProtocols(this->this$0->enabledProtocols);
	}
	sslSocket->setNeedClientAuth(this->this$0->needClientAuth);
	return sslSocket;
}

SslRMIServerSocketFactory$1::SslRMIServerSocketFactory$1() {
}

$Class* SslRMIServerSocketFactory$1::load$($String* name, bool initialize) {
	$loadClass(SslRMIServerSocketFactory$1, name, initialize, &_SslRMIServerSocketFactory$1_ClassInfo_, allocate$SslRMIServerSocketFactory$1);
	return class$;
}

$Class* SslRMIServerSocketFactory$1::class$ = nullptr;

		} // ssl
	} // rmi
} // javax