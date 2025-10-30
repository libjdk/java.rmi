#include <sun/rmi/transport/TransportConstants.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace sun {
	namespace rmi {
		namespace transport {

$FieldInfo _TransportConstants_FieldInfo_[] = {
	{"Magic", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, Magic)},
	{"Version", "S", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, Version)},
	{"StreamProtocol", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, StreamProtocol)},
	{"SingleOpProtocol", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, SingleOpProtocol)},
	{"MultiplexProtocol", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, MultiplexProtocol)},
	{"ProtocolAck", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, ProtocolAck)},
	{"ProtocolNack", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, ProtocolNack)},
	{"Call", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, Call)},
	{"Return", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, Return)},
	{"Ping", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, Ping)},
	{"PingAck", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, PingAck)},
	{"DGCAck", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, DGCAck)},
	{"NormalReturn", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, NormalReturn)},
	{"ExceptionalReturn", "B", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(TransportConstants, ExceptionalReturn)},
	{}
};

$MethodInfo _TransportConstants_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(TransportConstants::*)()>(&TransportConstants::init$))},
	{}
};

$ClassInfo _TransportConstants_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.TransportConstants",
	"java.lang.Object",
	nullptr,
	_TransportConstants_FieldInfo_,
	_TransportConstants_MethodInfo_
};

$Object* allocate$TransportConstants($Class* clazz) {
	return $of($alloc(TransportConstants));
}

void TransportConstants::init$() {
}

TransportConstants::TransportConstants() {
}

$Class* TransportConstants::load$($String* name, bool initialize) {
	$loadClass(TransportConstants, name, initialize, &_TransportConstants_ClassInfo_, allocate$TransportConstants);
	return class$;
}

$Class* TransportConstants::class$ = nullptr;

		} // transport
	} // rmi
} // sun