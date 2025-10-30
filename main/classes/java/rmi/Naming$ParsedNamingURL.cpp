#include <java/rmi/Naming$ParsedNamingURL.h>

#include <java/rmi/Naming.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Naming = ::java::rmi::Naming;

namespace java {
	namespace rmi {

$FieldInfo _Naming$ParsedNamingURL_FieldInfo_[] = {
	{"host", "Ljava/lang/String;", nullptr, 0, $field(Naming$ParsedNamingURL, host)},
	{"port", "I", nullptr, 0, $field(Naming$ParsedNamingURL, port)},
	{"name", "Ljava/lang/String;", nullptr, 0, $field(Naming$ParsedNamingURL, name)},
	{}
};

$MethodInfo _Naming$ParsedNamingURL_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, 0, $method(static_cast<void(Naming$ParsedNamingURL::*)($String*,int32_t,$String*)>(&Naming$ParsedNamingURL::init$))},
	{}
};

$InnerClassInfo _Naming$ParsedNamingURL_InnerClassesInfo_[] = {
	{"java.rmi.Naming$ParsedNamingURL", "java.rmi.Naming", "ParsedNamingURL", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Naming$ParsedNamingURL_ClassInfo_ = {
	$ACC_SUPER,
	"java.rmi.Naming$ParsedNamingURL",
	"java.lang.Object",
	nullptr,
	_Naming$ParsedNamingURL_FieldInfo_,
	_Naming$ParsedNamingURL_MethodInfo_,
	nullptr,
	nullptr,
	_Naming$ParsedNamingURL_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.rmi.Naming"
};

$Object* allocate$Naming$ParsedNamingURL($Class* clazz) {
	return $of($alloc(Naming$ParsedNamingURL));
}

void Naming$ParsedNamingURL::init$($String* host, int32_t port, $String* name) {
	$set(this, host, host);
	this->port = port;
	$set(this, name, name);
}

Naming$ParsedNamingURL::Naming$ParsedNamingURL() {
}

$Class* Naming$ParsedNamingURL::load$($String* name, bool initialize) {
	$loadClass(Naming$ParsedNamingURL, name, initialize, &_Naming$ParsedNamingURL_ClassInfo_, allocate$Naming$ParsedNamingURL);
	return class$;
}

$Class* Naming$ParsedNamingURL::class$ = nullptr;

	} // rmi
} // java