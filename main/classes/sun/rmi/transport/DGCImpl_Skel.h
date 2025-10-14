#ifndef _sun_rmi_transport_DGCImpl_Skel_h_
#define _sun_rmi_transport_DGCImpl_Skel_h_
//$ class sun.rmi.transport.DGCImpl_Skel
//$ extends java.rmi.server.Skeleton

#include <java/lang/Array.h>
#include <java/rmi/server/Skeleton.h>

namespace java {
	namespace rmi {
		class Remote;
	}
}
namespace java {
	namespace rmi {
		namespace server {
			class Operation;
			class RemoteCall;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace transport {

class $export DGCImpl_Skel : public ::java::rmi::server::Skeleton {
	$class(DGCImpl_Skel, 0, ::java::rmi::server::Skeleton)
public:
	DGCImpl_Skel();
	void init$();
	virtual void dispatch(::java::rmi::Remote* obj, ::java::rmi::server::RemoteCall* remoteCall, int32_t opnum, int64_t hash) override;
	virtual $Array<::java::rmi::server::Operation>* getOperations() override;
	static $Array<::java::rmi::server::Operation>* operations;
	static const int64_t interfaceHash = (int64_t)0xF6B6898D8BF28643;
};

		} // transport
	} // rmi
} // sun

#endif // _sun_rmi_transport_DGCImpl_Skel_h_