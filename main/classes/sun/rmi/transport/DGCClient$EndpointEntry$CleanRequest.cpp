#include <sun/rmi/transport/DGCClient$EndpointEntry$CleanRequest.h>

#include <java/rmi/server/ObjID.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <jcpp.h>

using $ObjIDArray = $Array<::java::rmi::server::ObjID>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ObjID = ::java::rmi::server::ObjID;
using $DGCClient$EndpointEntry = ::sun::rmi::transport::DGCClient$EndpointEntry;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _DGCClient$EndpointEntry$CleanRequest_FieldInfo_[] = {
	{"objIDs", "[Ljava/rmi/server/ObjID;", nullptr, $FINAL, $field(DGCClient$EndpointEntry$CleanRequest, objIDs)},
	{"sequenceNum", "J", nullptr, $FINAL, $field(DGCClient$EndpointEntry$CleanRequest, sequenceNum)},
	{"strong", "Z", nullptr, $FINAL, $field(DGCClient$EndpointEntry$CleanRequest, strong)},
	{"failures", "I", nullptr, 0, $field(DGCClient$EndpointEntry$CleanRequest, failures)},
	{}
};

$MethodInfo _DGCClient$EndpointEntry$CleanRequest_MethodInfo_[] = {
	{"<init>", "([Ljava/rmi/server/ObjID;JZ)V", nullptr, 0, $method(static_cast<void(DGCClient$EndpointEntry$CleanRequest::*)($ObjIDArray*,int64_t,bool)>(&DGCClient$EndpointEntry$CleanRequest::init$))},
	{}
};

$InnerClassInfo _DGCClient$EndpointEntry$CleanRequest_InnerClassesInfo_[] = {
	{"sun.rmi.transport.DGCClient$EndpointEntry", "sun.rmi.transport.DGCClient", "EndpointEntry", $PRIVATE | $STATIC},
	{"sun.rmi.transport.DGCClient$EndpointEntry$CleanRequest", "sun.rmi.transport.DGCClient$EndpointEntry", "CleanRequest", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DGCClient$EndpointEntry$CleanRequest_ClassInfo_ = {
	$ACC_SUPER,
	"sun.rmi.transport.DGCClient$EndpointEntry$CleanRequest",
	"java.lang.Object",
	nullptr,
	_DGCClient$EndpointEntry$CleanRequest_FieldInfo_,
	_DGCClient$EndpointEntry$CleanRequest_MethodInfo_,
	nullptr,
	nullptr,
	_DGCClient$EndpointEntry$CleanRequest_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.rmi.transport.DGCClient"
};

$Object* allocate$DGCClient$EndpointEntry$CleanRequest($Class* clazz) {
	return $of($alloc(DGCClient$EndpointEntry$CleanRequest));
}

void DGCClient$EndpointEntry$CleanRequest::init$($ObjIDArray* objIDs, int64_t sequenceNum, bool strong) {
	this->failures = 0;
	$set(this, objIDs, objIDs);
	this->sequenceNum = sequenceNum;
	this->strong = strong;
}

DGCClient$EndpointEntry$CleanRequest::DGCClient$EndpointEntry$CleanRequest() {
}

$Class* DGCClient$EndpointEntry$CleanRequest::load$($String* name, bool initialize) {
	$loadClass(DGCClient$EndpointEntry$CleanRequest, name, initialize, &_DGCClient$EndpointEntry$CleanRequest_ClassInfo_, allocate$DGCClient$EndpointEntry$CleanRequest);
	return class$;
}

$Class* DGCClient$EndpointEntry$CleanRequest::class$ = nullptr;

		} // transport
	} // rmi
} // sun