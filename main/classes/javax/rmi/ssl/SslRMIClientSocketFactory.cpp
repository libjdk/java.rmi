#include <javax/rmi/ssl/SslRMIClientSocketFactory.h>

#include <java/io/IOException.h>
#include <java/net/Socket.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/util/StringTokenizer.h>
#include <javax/net/SocketFactory.h>
#include <javax/net/ssl/SSLSocket.h>
#include <javax/net/ssl/SSLSocketFactory.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Socket = ::java::net::Socket;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $StringTokenizer = ::java::util::StringTokenizer;
using $SocketFactory = ::javax::net::SocketFactory;
using $SSLSocket = ::javax::net::ssl::SSLSocket;
using $SSLSocketFactory = ::javax::net::ssl::SSLSocketFactory;

namespace javax {
	namespace rmi {
		namespace ssl {

$FieldInfo _SslRMIClientSocketFactory_FieldInfo_[] = {
	{"defaultSocketFactory", "Ljavax/net/SocketFactory;", nullptr, $PRIVATE | $STATIC, $staticField(SslRMIClientSocketFactory, defaultSocketFactory)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SslRMIClientSocketFactory, serialVersionUID)},
	{}
};

$MethodInfo _SslRMIClientSocketFactory_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SslRMIClientSocketFactory::*)()>(&SslRMIClientSocketFactory::init$))},
	{"createSocket", "(Ljava/lang/String;I)Ljava/net/Socket;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getDefaultClientSocketFactory", "()Ljavax/net/SocketFactory;", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<$SocketFactory*(*)()>(&SslRMIClientSocketFactory::getDefaultClientSocketFactory))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _SslRMIClientSocketFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.rmi.ssl.SslRMIClientSocketFactory",
	"java.lang.Object",
	"java.rmi.server.RMIClientSocketFactory,java.io.Serializable",
	_SslRMIClientSocketFactory_FieldInfo_,
	_SslRMIClientSocketFactory_MethodInfo_
};

$Object* allocate$SslRMIClientSocketFactory($Class* clazz) {
	return $of($alloc(SslRMIClientSocketFactory));
}

$Object* SslRMIClientSocketFactory::clone() {
	 return this->$RMIClientSocketFactory::clone();
}

$String* SslRMIClientSocketFactory::toString() {
	 return this->$RMIClientSocketFactory::toString();
}

void SslRMIClientSocketFactory::finalize() {
	this->$RMIClientSocketFactory::finalize();
}

$SocketFactory* SslRMIClientSocketFactory::defaultSocketFactory = nullptr;

void SslRMIClientSocketFactory::init$() {
}

$Socket* SslRMIClientSocketFactory::createSocket($String* host, int32_t port) {
	$useLocalCurrentObjectStackCache();
	$var($SocketFactory, sslSocketFactory, getDefaultClientSocketFactory());
	$var($SSLSocket, sslSocket, $cast($SSLSocket, $nc(sslSocketFactory)->createSocket(host, port)));
	$var($String, enabledCipherSuites, $System::getProperty("javax.rmi.ssl.client.enabledCipherSuites"_s));
	if (enabledCipherSuites != nullptr) {
		$var($StringTokenizer, st, $new($StringTokenizer, enabledCipherSuites, ","_s));
		int32_t tokens = st->countTokens();
		$var($StringArray, enabledCipherSuitesList, $new($StringArray, tokens));
		for (int32_t i = 0; i < tokens; ++i) {
			enabledCipherSuitesList->set(i, $(st->nextToken()));
		}
		try {
			$nc(sslSocket)->setEnabledCipherSuites(enabledCipherSuitesList);
		} catch ($IllegalArgumentException& e) {
			$throw($cast($IOException, $($$new($IOException, $(e->getMessage()))->initCause(e))));
		}
	}
	$var($String, enabledProtocols, $System::getProperty("javax.rmi.ssl.client.enabledProtocols"_s));
	if (enabledProtocols != nullptr) {
		$var($StringTokenizer, st, $new($StringTokenizer, enabledProtocols, ","_s));
		int32_t tokens = st->countTokens();
		$var($StringArray, enabledProtocolsList, $new($StringArray, tokens));
		for (int32_t i = 0; i < tokens; ++i) {
			enabledProtocolsList->set(i, $(st->nextToken()));
		}
		try {
			$nc(sslSocket)->setEnabledProtocols(enabledProtocolsList);
		} catch ($IllegalArgumentException& e) {
			$throw($cast($IOException, $($$new($IOException, $(e->getMessage()))->initCause(e))));
		}
	}
	return sslSocket;
}

bool SslRMIClientSocketFactory::equals(Object$* obj) {
	if (obj == nullptr) {
		return false;
	}
	if ($equals(obj, this)) {
		return true;
	}
	return $of($of(this)->getClass())->equals($nc($of(obj))->getClass());
}

int32_t SslRMIClientSocketFactory::hashCode() {
	return $of($of(this)->getClass())->hashCode();
}

$SocketFactory* SslRMIClientSocketFactory::getDefaultClientSocketFactory() {
	$load(SslRMIClientSocketFactory);
	$synchronized(class$) {
		$init(SslRMIClientSocketFactory);
		if (SslRMIClientSocketFactory::defaultSocketFactory == nullptr) {
			$assignStatic(SslRMIClientSocketFactory::defaultSocketFactory, $SSLSocketFactory::getDefault());
		}
		return SslRMIClientSocketFactory::defaultSocketFactory;
	}
}

void clinit$SslRMIClientSocketFactory($Class* class$) {
	$assignStatic(SslRMIClientSocketFactory::defaultSocketFactory, nullptr);
}

SslRMIClientSocketFactory::SslRMIClientSocketFactory() {
}

$Class* SslRMIClientSocketFactory::load$($String* name, bool initialize) {
	$loadClass(SslRMIClientSocketFactory, name, initialize, &_SslRMIClientSocketFactory_ClassInfo_, clinit$SslRMIClientSocketFactory, allocate$SslRMIClientSocketFactory);
	return class$;
}

$Class* SslRMIClientSocketFactory::class$ = nullptr;

		} // ssl
	} // rmi
} // javax