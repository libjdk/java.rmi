#include <sun/rmi/transport/StreamRemoteCall.h>

#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutput.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/server/ObjID.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/logging/Level.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/server/MarshalInputStream.h>
#include <sun/rmi/server/MarshalOutputStream.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/ConnectionInputStream.h>
#include <sun/rmi/transport/ConnectionOutputStream.h>
#include <sun/rmi/transport/DGCAckHandler.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <jcpp.h>

#undef BRIEF
#undef VERBOSE

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $StackTraceElement = ::java::lang::StackTraceElement;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MarshalException = ::java::rmi::MarshalException;
using $UnmarshalException = ::java::rmi::UnmarshalException;
using $ObjID = ::java::rmi::server::ObjID;
using $RemoteCall = ::java::rmi::server::RemoteCall;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Level = ::java::util::logging::Level;
using $Log = ::sun::rmi::runtime::Log;
using $MarshalInputStream = ::sun::rmi::server::MarshalInputStream;
using $MarshalOutputStream = ::sun::rmi::server::MarshalOutputStream;
using $UnicastRef = ::sun::rmi::server::UnicastRef;
using $Channel = ::sun::rmi::transport::Channel;
using $Connection = ::sun::rmi::transport::Connection;
using $ConnectionInputStream = ::sun::rmi::transport::ConnectionInputStream;
using $ConnectionOutputStream = ::sun::rmi::transport::ConnectionOutputStream;
using $DGCAckHandler = ::sun::rmi::transport::DGCAckHandler;
using $Endpoint = ::sun::rmi::transport::Endpoint;
using $Transport = ::sun::rmi::transport::Transport;
using $TransportConstants = ::sun::rmi::transport::TransportConstants;
using $TCPEndpoint = ::sun::rmi::transport::tcp::TCPEndpoint;

namespace sun {
	namespace rmi {
		namespace transport {

class StreamRemoteCall$$Lambda$lambda$getInputStream$0 : public $PrivilegedAction {
	$class(StreamRemoteCall$$Lambda$lambda$getInputStream$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(StreamRemoteCall* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$getInputStream$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<StreamRemoteCall$$Lambda$lambda$getInputStream$0>());
	}
	StreamRemoteCall* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo StreamRemoteCall$$Lambda$lambda$getInputStream$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(StreamRemoteCall$$Lambda$lambda$getInputStream$0, inst$)},
	{}
};
$MethodInfo StreamRemoteCall$$Lambda$lambda$getInputStream$0::methodInfos[3] = {
	{"<init>", "(Lsun/rmi/transport/StreamRemoteCall;)V", nullptr, $PUBLIC, $method(static_cast<void(StreamRemoteCall$$Lambda$lambda$getInputStream$0::*)(StreamRemoteCall*)>(&StreamRemoteCall$$Lambda$lambda$getInputStream$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo StreamRemoteCall$$Lambda$lambda$getInputStream$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.rmi.transport.StreamRemoteCall$$Lambda$lambda$getInputStream$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* StreamRemoteCall$$Lambda$lambda$getInputStream$0::load$($String* name, bool initialize) {
	$loadClass(StreamRemoteCall$$Lambda$lambda$getInputStream$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* StreamRemoteCall$$Lambda$lambda$getInputStream$0::class$ = nullptr;

$FieldInfo _StreamRemoteCall_FieldInfo_[] = {
	{"in", "Lsun/rmi/transport/ConnectionInputStream;", nullptr, $PRIVATE, $field(StreamRemoteCall, in)},
	{"out", "Lsun/rmi/transport/ConnectionOutputStream;", nullptr, $PRIVATE, $field(StreamRemoteCall, out)},
	{"conn", "Lsun/rmi/transport/Connection;", nullptr, $PRIVATE, $field(StreamRemoteCall, conn)},
	{"filter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE, $field(StreamRemoteCall, filter)},
	{"resultStarted", "Z", nullptr, $PRIVATE, $field(StreamRemoteCall, resultStarted)},
	{"serverException", "Ljava/lang/Exception;", nullptr, $PRIVATE, $field(StreamRemoteCall, serverException)},
	{}
};

$MethodInfo _StreamRemoteCall_MethodInfo_[] = {
	{"<init>", "(Lsun/rmi/transport/Connection;)V", nullptr, $PUBLIC, $method(static_cast<void(StreamRemoteCall::*)($Connection*)>(&StreamRemoteCall::init$))},
	{"<init>", "(Lsun/rmi/transport/Connection;Ljava/rmi/server/ObjID;IJ)V", nullptr, $PUBLIC, $method(static_cast<void(StreamRemoteCall::*)($Connection*,$ObjID*,int32_t,int64_t)>(&StreamRemoteCall::init$)), "java.rmi.RemoteException"},
	{"discardPendingRefs", "()V", nullptr, $PUBLIC},
	{"done", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"exceptionReceivedFromServer", "(Ljava/lang/Exception;)V", nullptr, $PROTECTED, nullptr, "java.lang.Exception"},
	{"executeCall", "()V", nullptr, $PUBLIC, nullptr, "java.lang.Exception"},
	{"getConnection", "()Lsun/rmi/transport/Connection;", nullptr, $PUBLIC},
	{"getInputStream", "()Ljava/io/ObjectInput;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/ObjectOutput;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getOutputStream", "(Z)Ljava/io/ObjectOutput;", nullptr, $PRIVATE, $method(static_cast<$ObjectOutput*(StreamRemoteCall::*)(bool)>(&StreamRemoteCall::getOutputStream)), "java.io.IOException"},
	{"getResultStream", "(Z)Ljava/io/ObjectOutput;", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"getServerException", "()Ljava/lang/Exception;", nullptr, $PUBLIC},
	{"lambda$getInputStream$0", "()Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(StreamRemoteCall::*)()>(&StreamRemoteCall::lambda$getInputStream$0))},
	{"releaseInputStream", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"releaseOutputStream", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"setObjectInputFilter", "(Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _StreamRemoteCall_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.rmi.transport.StreamRemoteCall",
	"java.lang.Object",
	"java.rmi.server.RemoteCall",
	_StreamRemoteCall_FieldInfo_,
	_StreamRemoteCall_MethodInfo_
};

$Object* allocate$StreamRemoteCall($Class* clazz) {
	return $of($alloc(StreamRemoteCall));
}

void StreamRemoteCall::init$($Connection* c) {
	$set(this, in, nullptr);
	$set(this, out, nullptr);
	$set(this, filter, nullptr);
	this->resultStarted = false;
	$set(this, serverException, nullptr);
	$set(this, conn, c);
}

void StreamRemoteCall::init$($Connection* c, $ObjID* id, int32_t op, int64_t hash) {
	$set(this, in, nullptr);
	$set(this, out, nullptr);
	$set(this, filter, nullptr);
	this->resultStarted = false;
	$set(this, serverException, nullptr);
	try {
		$set(this, conn, c);
		$init($Transport);
		$init($Log);
		$nc($Transport::transportLog)->log($Log::VERBOSE, "write remote call header..."_s);
		$nc($($nc(this->conn)->getOutputStream()))->write((int32_t)$TransportConstants::Call);
		getOutputStream();
		$nc(id)->write(this->out);
		$nc(this->out)->writeInt(op);
		$nc(this->out)->writeLong(hash);
	} catch ($IOException& e) {
		$throwNew($MarshalException, "Error marshaling call header"_s, e);
	}
}

$Connection* StreamRemoteCall::getConnection() {
	return this->conn;
}

$ObjectOutput* StreamRemoteCall::getOutputStream() {
	return getOutputStream(false);
}

$ObjectOutput* StreamRemoteCall::getOutputStream(bool resultStream) {
	if (this->out == nullptr) {
		$init($Transport);
		$init($Log);
		$nc($Transport::transportLog)->log($Log::VERBOSE, "getting output stream"_s);
		$set(this, out, $new($ConnectionOutputStream, this->conn, resultStream));
	}
	return this->out;
}

void StreamRemoteCall::releaseOutputStream() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->out != nullptr) {
				{
					$var($Throwable, var$1, nullptr);
					try {
						$nc(this->out)->flush();
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						$nc(this->out)->done();
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
			}
			$nc(this->conn)->releaseOutputStream();
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} /*finally*/ {
			$set(this, out, nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void StreamRemoteCall::setObjectInputFilter($ObjectInputFilter* filter) {
	if (this->in != nullptr) {
		$throwNew($IllegalStateException, "set filter must occur before calling getInputStream"_s);
	}
	$set(this, filter, filter);
}

$ObjectInput* StreamRemoteCall::getInputStream() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->in == nullptr) {
		$init($Transport);
		$init($Log);
		$nc($Transport::transportLog)->log($Log::VERBOSE, "getting input stream"_s);
		$set(this, in, $new($ConnectionInputStream, $($nc(this->conn)->getInputStream())));
		if (this->filter != nullptr) {
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(StreamRemoteCall$$Lambda$lambda$getInputStream$0, this)));
		}
	}
	return this->in;
}

void StreamRemoteCall::releaseInputStream() {
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->in != nullptr) {
				try {
					$nc(this->in)->done();
				} catch ($RuntimeException& e) {
				}
				$nc(this->in)->registerRefs();
				$nc(this->in)->done(this->conn);
			}
			$nc(this->conn)->releaseInputStream();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, in, nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void StreamRemoteCall::discardPendingRefs() {
	$nc(this->in)->discardRefs();
}

$ObjectOutput* StreamRemoteCall::getResultStream(bool success) {
	$useLocalCurrentObjectStackCache();
	if (this->resultStarted) {
		$throwNew($StreamCorruptedException, "result already in progress"_s);
	} else {
		this->resultStarted = true;
	}
	$var($DataOutputStream, wr, $new($DataOutputStream, $($nc(this->conn)->getOutputStream())));
	wr->writeByte($TransportConstants::Return);
	getOutputStream(true);
	if (success) {
		$nc(this->out)->writeByte($TransportConstants::NormalReturn);
	} else {
		$nc(this->out)->writeByte($TransportConstants::ExceptionalReturn);
	}
	$nc(this->out)->writeID();
	return this->out;
}

void StreamRemoteCall::executeCall() {
	$useLocalCurrentObjectStackCache();
	int8_t returnType = 0;
	$var($DGCAckHandler, ackHandler, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				if (this->out != nullptr) {
					$assign(ackHandler, $nc(this->out)->getDGCAckHandler());
				}
				releaseOutputStream();
				$var($DataInputStream, rd, $new($DataInputStream, $($nc(this->conn)->getInputStream())));
				int8_t op = rd->readByte();
				if (op != $TransportConstants::Return) {
					$init($Transport);
					$init($Log);
					if ($nc($Transport::transportLog)->isLoggable($Log::BRIEF)) {
						$nc($Transport::transportLog)->log($Log::BRIEF, $$str({"transport return code invalid: "_s, $$str(op)}));
					}
					$throwNew($UnmarshalException, "Transport return code invalid"_s);
				}
				getInputStream();
				returnType = $nc(this->in)->readByte();
				$nc(this->in)->readID();
			} catch ($UnmarshalException& e) {
				$throw(e);
			} catch ($IOException& e) {
				$throwNew($UnmarshalException, "Error unmarshaling return header"_s, e);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (ackHandler != nullptr) {
				ackHandler->release();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	{
		$var($Object, ex, nullptr)
		switch (returnType) {
		case $TransportConstants::NormalReturn:
			{
				break;
			}
		case $TransportConstants::ExceptionalReturn:
			{
				try {
					$assign(ex, $nc(this->in)->readObject());
				} catch ($Exception& e) {
					discardPendingRefs();
					$throwNew($UnmarshalException, "Error unmarshaling return"_s, e);
				}
				if ($instanceOf($Exception, ex)) {
					exceptionReceivedFromServer($cast($Exception, ex));
				} else {
					discardPendingRefs();
					$throwNew($UnmarshalException, "Return type not Exception"_s);
				}
			}
		default:
			{
				$init($Transport);
				$init($Log);
				if ($nc($Transport::transportLog)->isLoggable($Log::BRIEF)) {
					$nc($Transport::transportLog)->log($Log::BRIEF, $$str({"return code invalid: "_s, $$str(returnType)}));
				}
				$throwNew($UnmarshalException, "Return code invalid"_s);
			}
		}
	}
}

void StreamRemoteCall::exceptionReceivedFromServer($Exception* ex) {
	$useLocalCurrentObjectStackCache();
	$set(this, serverException, ex);
	$var($StackTraceElementArray, serverTrace, $nc(ex)->getStackTrace());
	$var($StackTraceElementArray, clientTrace, ($$new($Throwable))->getStackTrace());
	$var($StackTraceElementArray, combinedTrace, $new($StackTraceElementArray, $nc(serverTrace)->length + $nc(clientTrace)->length));
	$System::arraycopy(serverTrace, 0, combinedTrace, 0, serverTrace->length);
	$System::arraycopy(clientTrace, 0, combinedTrace, serverTrace->length, clientTrace->length);
	ex->setStackTrace(combinedTrace);
	$init($UnicastRef);
	$init($Log);
	if ($nc($UnicastRef::clientCallLog)->isLoggable($Log::BRIEF)) {
		$var($TCPEndpoint, ep, $cast($TCPEndpoint, $nc($($nc(this->conn)->getChannel()))->getEndpoint()));
		$var($String, var$1, $$str({"outbound call received exception: ["_s, $($nc(ep)->getHost()), ":"_s}));
		$var($String, var$0, $$concat(var$1, $$str(ep->getPort())));
		$nc($UnicastRef::clientCallLog)->log($Log::BRIEF, $$concat(var$0, "] exception: "), ex);
	}
	$throw(ex);
}

$Exception* StreamRemoteCall::getServerException() {
	return this->serverException;
}

void StreamRemoteCall::done() {
	releaseInputStream();
}

$Void* StreamRemoteCall::lambda$getInputStream$0() {
	$nc(this->in)->setObjectInputFilter(this->filter);
	return nullptr;
}

StreamRemoteCall::StreamRemoteCall() {
}

$Class* StreamRemoteCall::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(StreamRemoteCall$$Lambda$lambda$getInputStream$0::classInfo$.name)) {
			return StreamRemoteCall$$Lambda$lambda$getInputStream$0::load$(name, initialize);
		}
	}
	$loadClass(StreamRemoteCall, name, initialize, &_StreamRemoteCall_ClassInfo_, allocate$StreamRemoteCall);
	return class$;
}

$Class* StreamRemoteCall::class$ = nullptr;

		} // transport
	} // rmi
} // sun