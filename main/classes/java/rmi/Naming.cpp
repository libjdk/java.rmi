#include <java/rmi/Naming.h>

#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/rmi/Naming$ParsedNamingURL.h>
#include <java/rmi/Remote.h>
#include <java/rmi/registry/LocateRegistry.h>
#include <java/rmi/registry/Registry.h>
#include <jcpp.h>

#undef REGISTRY_PORT

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $Naming$ParsedNamingURL = ::java::rmi::Naming$ParsedNamingURL;
using $Remote = ::java::rmi::Remote;
using $LocateRegistry = ::java::rmi::registry::LocateRegistry;
using $Registry = ::java::rmi::registry::Registry;

namespace java {
	namespace rmi {

$MethodInfo _Naming_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Naming::*)()>(&Naming::init$))},
	{"bind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($String*,$Remote*)>(&Naming::bind)), "java.rmi.AlreadyBoundException,java.net.MalformedURLException,java.rmi.RemoteException"},
	{"getRegistry", "(Ljava/rmi/Naming$ParsedNamingURL;)Ljava/rmi/registry/Registry;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Registry*(*)($Naming$ParsedNamingURL*)>(&Naming::getRegistry)), "java.rmi.RemoteException"},
	{"intParseURL", "(Ljava/lang/String;)Ljava/rmi/Naming$ParsedNamingURL;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Naming$ParsedNamingURL*(*)($String*)>(&Naming::intParseURL)), "java.net.MalformedURLException,java.net.URISyntaxException"},
	{"list", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$StringArray*(*)($String*)>(&Naming::list)), "java.rmi.RemoteException,java.net.MalformedURLException"},
	{"lookup", "(Ljava/lang/String;)Ljava/rmi/Remote;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Remote*(*)($String*)>(&Naming::lookup)), "java.rmi.NotBoundException,java.net.MalformedURLException,java.rmi.RemoteException"},
	{"parseURL", "(Ljava/lang/String;)Ljava/rmi/Naming$ParsedNamingURL;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Naming$ParsedNamingURL*(*)($String*)>(&Naming::parseURL)), "java.net.MalformedURLException"},
	{"rebind", "(Ljava/lang/String;Ljava/rmi/Remote;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($String*,$Remote*)>(&Naming::rebind)), "java.rmi.RemoteException,java.net.MalformedURLException"},
	{"unbind", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($String*)>(&Naming::unbind)), "java.rmi.RemoteException,java.rmi.NotBoundException,java.net.MalformedURLException"},
	{}
};

$InnerClassInfo _Naming_InnerClassesInfo_[] = {
	{"java.rmi.Naming$ParsedNamingURL", "java.rmi.Naming", "ParsedNamingURL", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Naming_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.rmi.Naming",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Naming_MethodInfo_,
	nullptr,
	nullptr,
	_Naming_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.rmi.Naming$ParsedNamingURL"
};

$Object* allocate$Naming($Class* clazz) {
	return $of($alloc(Naming));
}

void Naming::init$() {
}

$Remote* Naming::lookup($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Naming$ParsedNamingURL, parsed, parseURL(name));
	$var($Registry, registry, getRegistry(parsed));
	if ($nc(parsed)->name == nullptr) {
		return registry;
	}
	return $nc(registry)->lookup($nc(parsed)->name);
}

void Naming::bind($String* name, $Remote* obj) {
	$useLocalCurrentObjectStackCache();
	$var($Naming$ParsedNamingURL, parsed, parseURL(name));
	$var($Registry, registry, getRegistry(parsed));
	if (obj == nullptr) {
		$throwNew($NullPointerException, "cannot bind to null"_s);
	}
	$nc(registry)->bind($nc(parsed)->name, obj);
}

void Naming::unbind($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Naming$ParsedNamingURL, parsed, parseURL(name));
	$var($Registry, registry, getRegistry(parsed));
	$nc(registry)->unbind($nc(parsed)->name);
}

void Naming::rebind($String* name, $Remote* obj) {
	$useLocalCurrentObjectStackCache();
	$var($Naming$ParsedNamingURL, parsed, parseURL(name));
	$var($Registry, registry, getRegistry(parsed));
	if (obj == nullptr) {
		$throwNew($NullPointerException, "cannot bind to null"_s);
	}
	$nc(registry)->rebind($nc(parsed)->name, obj);
}

$StringArray* Naming::list($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Naming$ParsedNamingURL, parsed, parseURL(name));
	$var($Registry, registry, getRegistry(parsed));
	$var($String, prefix, ""_s);
	if ($nc(parsed)->port > 0 || !$nc($nc(parsed)->host)->isEmpty()) {
		$plusAssign(prefix, $$str({"//"_s, parsed->host}));
	}
	if ($nc(parsed)->port > 0) {
		$plusAssign(prefix, $$str({":"_s, $$str(parsed->port)}));
	}
	$plusAssign(prefix, "/"_s);
	$var($StringArray, names, $nc(registry)->list());
	for (int32_t i = 0; i < $nc(names)->length; ++i) {
		names->set(i, $$str({prefix, names->get(i)}));
	}
	return names;
}

$Registry* Naming::getRegistry($Naming$ParsedNamingURL* parsed) {
	return $LocateRegistry::getRegistry($nc(parsed)->host, parsed->port);
}

$Naming$ParsedNamingURL* Naming::parseURL($String* str) {
	$useLocalCurrentObjectStackCache();
	try {
		return intParseURL(str);
	} catch ($URISyntaxException& ex) {
		$var($MalformedURLException, mue, $new($MalformedURLException, $$str({"invalid URL String: "_s, str})));
		mue->initCause(ex);
		int32_t indexSchemeEnd = $nc(str)->indexOf((int32_t)u':');
		int32_t indexAuthorityBegin = str->indexOf("//:"_s);
		if (indexAuthorityBegin < 0) {
			$throw(mue);
		}
		if ((indexAuthorityBegin == 0) || ((indexSchemeEnd > 0) && (indexAuthorityBegin == indexSchemeEnd + 1))) {
			int32_t indexHostBegin = indexAuthorityBegin + 2;
			$var($String, var$0, $$str({$(str->substring(0, indexHostBegin)), "localhost"_s}));
			$var($String, newStr, $concat(var$0, $(str->substring(indexHostBegin))));
			try {
				return intParseURL(newStr);
			} catch ($URISyntaxException& inte) {
				$throw(mue);
			} catch ($MalformedURLException& inte) {
				$throw(inte);
			}
		}
		$throw(mue);
	}
	$shouldNotReachHere();
}

$Naming$ParsedNamingURL* Naming::intParseURL($String* str) {
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $new($URI, str));
	if (uri->isOpaque()) {
		$throwNew($MalformedURLException, $$str({"not a hierarchical URL: "_s, str}));
	}
	if (uri->getFragment() != nullptr) {
		$throwNew($MalformedURLException, $$str({"invalid character, \'#\', in URL name: "_s, str}));
	} else if (uri->getQuery() != nullptr) {
		$throwNew($MalformedURLException, $$str({"invalid character, \'?\', in URL name: "_s, str}));
	} else if (uri->getUserInfo() != nullptr) {
		$throwNew($MalformedURLException, $$str({"invalid character, \'@\', in URL host: "_s, str}));
	}
	$var($String, scheme, uri->getScheme());
	if (scheme != nullptr && !scheme->equals("rmi"_s)) {
		$throwNew($MalformedURLException, $$str({"invalid URL scheme: "_s, str}));
	}
	$var($String, name, uri->getPath());
	if (name != nullptr) {
		if (name->startsWith("/"_s)) {
			$assign(name, name->substring(1));
		}
		if (name->length() == 0) {
			$assign(name, nullptr);
		}
	}
	$var($String, host, uri->getHost());
	if (host == nullptr) {
		$assign(host, ""_s);
		try {
			uri->parseServerAuthority();
		} catch ($URISyntaxException& use) {
			$var($String, authority, uri->getAuthority());
			if (authority != nullptr && authority->startsWith(":"_s)) {
				$assign(authority, $str({"localhost"_s, authority}));
				try {
					$assign(uri, $new($URI, nullptr, authority, nullptr, nullptr, nullptr));
					uri->parseServerAuthority();
				} catch ($URISyntaxException& use2) {
					$throwNew($MalformedURLException, $$str({"invalid authority: "_s, str}));
				}
			} else {
				$throwNew($MalformedURLException, $$str({"invalid authority: "_s, str}));
			}
		}
	}
	int32_t port = uri->getPort();
	if (port == -1) {
		port = $Registry::REGISTRY_PORT;
	}
	return $new($Naming$ParsedNamingURL, host, port, name);
}

Naming::Naming() {
}

$Class* Naming::load$($String* name, bool initialize) {
	$loadClass(Naming, name, initialize, &_Naming_ClassInfo_, allocate$Naming);
	return class$;
}

$Class* Naming::class$ = nullptr;

	} // rmi
} // java