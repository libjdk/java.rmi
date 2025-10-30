#include <sun/rmi/server/UnicastServerRef2.h>

#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectOutput.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RemoteRef.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastRef2.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/transport/LiveRef.h>
#include <jcpp.h>

using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RMIClientSocketFactory = ::java::rmi::server::RMIClientSocketFactory;
using $RMIServerSocketFactory = ::java::rmi::server::RMIServerSocketFactory;
using $RemoteRef = ::java::rmi::server::RemoteRef;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $UnicastRef2 = ::sun::rmi::server::UnicastRef2;
using $UnicastServerRef = ::sun::rmi::server::UnicastServerRef;
using $LiveRef = ::sun::rmi::transport::LiveRef;

namespace sun {
	namespace rmi {
		namespace server {

$FieldInfo _UnicastServerRef2_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnicastServerRef2, serialVersionUID)},
	{}
};

$MethodInfo _UnicastServerRef2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef2::*)()>(&UnicastServerRef2::init$))},
	{"<init>", "(Lsun/rmi/transport/LiveRef;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef2::*)($LiveRef*)>(&UnicastServerRef2::init$))},
	{"<init>", "(Lsun/rmi/transport/LiveRef;Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef2::*)($LiveRef*,$ObjectInputFilter*)>(&UnicastServerRef2::init$))},
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef2::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*)>(&UnicastServerRef2::init$))},
	{"<init>", "(ILjava/rmi/server/RMIClientSocketFactory;Ljava/rmi/server/RMIServerSocketFactory;Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC, $method(static_cast<void(UnicastServerRef2::*)(int32_t,$RMIClientSocketFactory*,$RMIServerSocketFactory*,$ObjectInputFilter*)>(&UnicastServerRef2::init$))},
	{"getClientRef", "()Ljava/rmi/server/RemoteRef;", nullptr, $PROTECTED},
	{"getRefClass", "(Ljava/io/ObjectOutput;)Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _UnicastServerRef2_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.server.UnicastServerRef2",
	"sun.rmi.server.UnicastServerRef",
	nullptr,
	_UnicastServerRef2_FieldInfo_,
	_UnicastServerRef2_MethodInfo_
};

$Object* allocate$UnicastServerRef2($Class* clazz) {
	return $of($alloc(UnicastServerRef2));
}

void UnicastServerRef2::init$() {
	$UnicastServerRef::init$();
}

void UnicastServerRef2::init$($LiveRef* ref) {
	$UnicastServerRef::init$(ref);
}

void UnicastServerRef2::init$($LiveRef* ref, $ObjectInputFilter* filter) {
	$UnicastServerRef::init$(ref, filter);
}

void UnicastServerRef2::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf) {
	$UnicastServerRef::init$($$new($LiveRef, port, csf, ssf));
}

void UnicastServerRef2::init$(int32_t port, $RMIClientSocketFactory* csf, $RMIServerSocketFactory* ssf, $ObjectInputFilter* filter) {
	$UnicastServerRef::init$($$new($LiveRef, port, csf, ssf), filter);
}

$String* UnicastServerRef2::getRefClass($ObjectOutput* out) {
	return "UnicastServerRef2"_s;
}

$RemoteRef* UnicastServerRef2::getClientRef() {
	return $new($UnicastRef2, this->ref);
}

UnicastServerRef2::UnicastServerRef2() {
}

$Class* UnicastServerRef2::load$($String* name, bool initialize) {
	$loadClass(UnicastServerRef2, name, initialize, &_UnicastServerRef2_ClassInfo_, allocate$UnicastServerRef2);
	return class$;
}

$Class* UnicastServerRef2::class$ = nullptr;

		} // server
	} // rmi
} // sun