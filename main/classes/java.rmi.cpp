#include <java.rmi.h>

#include <java.base.h>
#include <java.logging.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <java/rmi/AccessException.h>
#include <java/rmi/AlreadyBoundException.h>
#include <java/rmi/ConnectException.h>
#include <java/rmi/ConnectIOException.h>
#include <java/rmi/MarshalException.h>
#include <java/rmi/MarshalledObject.h>
#include <java/rmi/MarshalledObject$MarshalledObjectInputStream.h>
#include <java/rmi/MarshalledObject$MarshalledObjectOutputStream.h>
#include <java/rmi/Naming.h>
#include <java/rmi/Naming$ParsedNamingURL.h>
#include <java/rmi/NoSuchObjectException.h>
#include <java/rmi/NotBoundException.h>
#include <java/rmi/RMISecurityException.h>
#include <java/rmi/RMISecurityManager.h>
#include <java/rmi/Remote.h>
#include <java/rmi/RemoteException.h>
#include <java/rmi/ServerError.h>
#include <java/rmi/ServerException.h>
#include <java/rmi/ServerRuntimeException.h>
#include <java/rmi/StubNotFoundException.h>
#include <java/rmi/UnexpectedException.h>
#include <java/rmi/UnknownHostException.h>
#include <java/rmi/UnmarshalException.h>
#include <java/rmi/dgc/DGC.h>
#include <java/rmi/dgc/Lease.h>
#include <java/rmi/dgc/VMID.h>
#include <java/rmi/registry/LocateRegistry.h>
#include <java/rmi/registry/Registry.h>
#include <java/rmi/registry/RegistryHandler.h>
#include <java/rmi/server/ExportException.h>
#include <java/rmi/server/LoaderHandler.h>
#include <java/rmi/server/LogStream.h>
#include <java/rmi/server/ObjID.h>
#include <java/rmi/server/Operation.h>
#include <java/rmi/server/RMIClassLoader.h>
#include <java/rmi/server/RMIClassLoader$1.h>
#include <java/rmi/server/RMIClassLoader$2.h>
#include <java/rmi/server/RMIClassLoaderSpi.h>
#include <java/rmi/server/RMIClientSocketFactory.h>
#include <java/rmi/server/RMIFailureHandler.h>
#include <java/rmi/server/RMIServerSocketFactory.h>
#include <java/rmi/server/RMISocketFactory.h>
#include <java/rmi/server/RemoteCall.h>
#include <java/rmi/server/RemoteObject.h>
#include <java/rmi/server/RemoteObjectInvocationHandler.h>
#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps.h>
#include <java/rmi/server/RemoteObjectInvocationHandler$MethodToHash_Maps$1.h>
#include <java/rmi/server/RemoteRef.h>
#include <java/rmi/server/RemoteServer.h>
#include <java/rmi/server/RemoteStub.h>
#include <java/rmi/server/ServerCloneException.h>
#include <java/rmi/server/ServerNotActiveException.h>
#include <java/rmi/server/ServerRef.h>
#include <java/rmi/server/Skeleton.h>
#include <java/rmi/server/SkeletonMismatchException.h>
#include <java/rmi/server/SkeletonNotFoundException.h>
#include <java/rmi/server/SocketSecurityException.h>
#include <java/rmi/server/UID.h>
#include <java/rmi/server/UnicastRemoteObject.h>
#include <java/rmi/server/Unreferenced.h>
#include <javax/rmi/ssl/SslRMIClientSocketFactory.h>
#include <javax/rmi/ssl/SslRMIServerSocketFactory.h>
#include <javax/rmi/ssl/SslRMIServerSocketFactory$1.h>
#include <sun/rmi/log/LogHandler.h>
#include <sun/rmi/log/LogInputStream.h>
#include <sun/rmi/log/LogOutputStream.h>
#include <sun/rmi/log/ReliableLog.h>
#include <sun/rmi/log/ReliableLog$1.h>
#include <sun/rmi/log/ReliableLog$LogFile.h>
#include <sun/rmi/registry/RegistryImpl.h>
#include <sun/rmi/registry/RegistryImpl$1.h>
#include <sun/rmi/registry/RegistryImpl$2.h>
#include <sun/rmi/registry/RegistryImpl$3.h>
#include <sun/rmi/registry/RegistryImpl$4.h>
#include <sun/rmi/registry/RegistryImpl$5.h>
#include <sun/rmi/registry/RegistryImpl$6.h>
#include <sun/rmi/registry/RegistryImpl_Skel.h>
#include <sun/rmi/registry/RegistryImpl_Stub.h>
#include <sun/rmi/runtime/Log.h>
#include <sun/rmi/runtime/Log$InternalStreamHandler.h>
#include <sun/rmi/runtime/Log$LogFactory.h>
#include <sun/rmi/runtime/Log$LogStreamLog.h>
#include <sun/rmi/runtime/Log$LogStreamLogFactory.h>
#include <sun/rmi/runtime/Log$LoggerLog.h>
#include <sun/rmi/runtime/Log$LoggerLog$1.h>
#include <sun/rmi/runtime/Log$LoggerLog$2.h>
#include <sun/rmi/runtime/Log$LoggerLogFactory.h>
#include <sun/rmi/runtime/Log$LoggerPrintStream.h>
#include <sun/rmi/runtime/NewThreadAction.h>
#include <sun/rmi/runtime/NewThreadAction$1.h>
#include <sun/rmi/runtime/NewThreadAction$2.h>
#include <sun/rmi/runtime/RuntimeUtil.h>
#include <sun/rmi/runtime/RuntimeUtil$1.h>
#include <sun/rmi/runtime/RuntimeUtil$GetInstanceAction.h>
#include <sun/rmi/server/DeserializationChecker.h>
#include <sun/rmi/server/Dispatcher.h>
#include <sun/rmi/server/LoaderHandler.h>
#include <sun/rmi/server/LoaderHandler$1.h>
#include <sun/rmi/server/LoaderHandler$2.h>
#include <sun/rmi/server/LoaderHandler$Loader.h>
#include <sun/rmi/server/LoaderHandler$LoaderEntry.h>
#include <sun/rmi/server/LoaderHandler$LoaderKey.h>
#include <sun/rmi/server/MarshalInputStream.h>
#include <sun/rmi/server/MarshalOutputStream.h>
#include <sun/rmi/server/MarshalOutputStream$1.h>
#include <sun/rmi/server/UnicastRef.h>
#include <sun/rmi/server/UnicastRef2.h>
#include <sun/rmi/server/UnicastServerRef.h>
#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps.h>
#include <sun/rmi/server/UnicastServerRef$HashToMethod_Maps$1.h>
#include <sun/rmi/server/UnicastServerRef2.h>
#include <sun/rmi/server/Util.h>
#include <sun/rmi/server/Util$1.h>
#include <sun/rmi/server/WeakClassHashMap.h>
#include <sun/rmi/server/WeakClassHashMap$ValueCell.h>
#include <sun/rmi/transport/Channel.h>
#include <sun/rmi/transport/Connection.h>
#include <sun/rmi/transport/ConnectionInputStream.h>
#include <sun/rmi/transport/ConnectionOutputStream.h>
#include <sun/rmi/transport/DGCAckHandler.h>
#include <sun/rmi/transport/DGCAckHandler$1.h>
#include <sun/rmi/transport/DGCClient.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$1.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$CleanRequest.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RefEntry$PhantomLiveRef.h>
#include <sun/rmi/transport/DGCClient$EndpointEntry$RenewCleanThread.h>
#include <sun/rmi/transport/DGCImpl.h>
#include <sun/rmi/transport/DGCImpl$1.h>
#include <sun/rmi/transport/DGCImpl$2.h>
#include <sun/rmi/transport/DGCImpl$2$1.h>
#include <sun/rmi/transport/DGCImpl$LeaseInfo.h>
#include <sun/rmi/transport/DGCImpl_Skel.h>
#include <sun/rmi/transport/DGCImpl_Stub.h>
#include <sun/rmi/transport/Endpoint.h>
#include <sun/rmi/transport/GC.h>
#include <sun/rmi/transport/GC$1.h>
#include <sun/rmi/transport/GC$Daemon.h>
#include <sun/rmi/transport/GC$Daemon$1.h>
#include <sun/rmi/transport/GC$LatencyLock.h>
#include <sun/rmi/transport/GC$LatencyRequest.h>
#include <sun/rmi/transport/LiveRef.h>
#include <sun/rmi/transport/ObjectEndpoint.h>
#include <sun/rmi/transport/ObjectTable.h>
#include <sun/rmi/transport/ObjectTable$1.h>
#include <sun/rmi/transport/ObjectTable$Reaper.h>
#include <sun/rmi/transport/SequenceEntry.h>
#include <sun/rmi/transport/StreamRemoteCall.h>
#include <sun/rmi/transport/Target.h>
#include <sun/rmi/transport/Transport.h>
#include <sun/rmi/transport/Transport$1.h>
#include <sun/rmi/transport/TransportConstants.h>
#include <sun/rmi/transport/WeakRef.h>
#include <sun/rmi/transport/tcp/ConnectionAcceptor.h>
#include <sun/rmi/transport/tcp/TCPChannel.h>
#include <sun/rmi/transport/tcp/TCPChannel$1.h>
#include <sun/rmi/transport/tcp/TCPConnection.h>
#include <sun/rmi/transport/tcp/TCPDirectSocketFactory.h>
#include <sun/rmi/transport/tcp/TCPEndpoint.h>
#include <sun/rmi/transport/tcp/TCPEndpoint$FQDN.h>
#include <sun/rmi/transport/tcp/TCPTransport.h>
#include <sun/rmi/transport/tcp/TCPTransport$1.h>
#include <sun/rmi/transport/tcp/TCPTransport$AcceptLoop.h>
#include <sun/rmi/transport/tcp/TCPTransport$ConnectionHandler.h>

#undef DGC
#undef GC
#undef UID
#undef VMID

#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$rmi_classes_[] = {
	$classEntry("java.rmi.AccessException", ::java::rmi::AccessException),
	$classEntry("java.rmi.AlreadyBoundException", ::java::rmi::AlreadyBoundException),
	$classEntry("java.rmi.ConnectException", ::java::rmi::ConnectException),
	$classEntry("java.rmi.ConnectIOException", ::java::rmi::ConnectIOException),
	$classEntry("java.rmi.MarshalException", ::java::rmi::MarshalException),
	$classEntry("java.rmi.MarshalledObject", ::java::rmi::MarshalledObject),
	$classEntry("java.rmi.MarshalledObject$MarshalledObjectInputStream", ::java::rmi::MarshalledObject$MarshalledObjectInputStream),
	$classEntry("java.rmi.MarshalledObject$MarshalledObjectOutputStream", ::java::rmi::MarshalledObject$MarshalledObjectOutputStream),
	$classEntry("java.rmi.Naming", ::java::rmi::Naming),
	$classEntry("java.rmi.Naming$ParsedNamingURL", ::java::rmi::Naming$ParsedNamingURL),
	$classEntry("java.rmi.NoSuchObjectException", ::java::rmi::NoSuchObjectException),
	$classEntry("java.rmi.NotBoundException", ::java::rmi::NotBoundException),
	$classEntry("java.rmi.RMISecurityException", ::java::rmi::RMISecurityException),
	$classEntry("java.rmi.RMISecurityManager", ::java::rmi::RMISecurityManager),
	$classEntry("java.rmi.Remote", ::java::rmi::Remote),
	$classEntry("java.rmi.RemoteException", ::java::rmi::RemoteException),
	$classEntry("java.rmi.ServerError", ::java::rmi::ServerError),
	$classEntry("java.rmi.ServerException", ::java::rmi::ServerException),
	$classEntry("java.rmi.ServerRuntimeException", ::java::rmi::ServerRuntimeException),
	$classEntry("java.rmi.StubNotFoundException", ::java::rmi::StubNotFoundException),
	$classEntry("java.rmi.UnexpectedException", ::java::rmi::UnexpectedException),
	$classEntry("java.rmi.UnknownHostException", ::java::rmi::UnknownHostException),
	$classEntry("java.rmi.UnmarshalException", ::java::rmi::UnmarshalException),
	$classEntry("java.rmi.dgc.DGC", ::java::rmi::dgc::DGC),
	$classEntry("java.rmi.dgc.Lease", ::java::rmi::dgc::Lease),
	$classEntry("java.rmi.dgc.VMID", ::java::rmi::dgc::VMID),
	$classEntry("java.rmi.registry.LocateRegistry", ::java::rmi::registry::LocateRegistry),
	$classEntry("java.rmi.registry.Registry", ::java::rmi::registry::Registry),
	$classEntry("java.rmi.registry.RegistryHandler", ::java::rmi::registry::RegistryHandler),
	$classEntry("java.rmi.server.ExportException", ::java::rmi::server::ExportException),
	$classEntry("java.rmi.server.LoaderHandler", ::java::rmi::server::LoaderHandler),
	$classEntry("java.rmi.server.LogStream", ::java::rmi::server::LogStream),
	$classEntry("java.rmi.server.ObjID", ::java::rmi::server::ObjID),
	$classEntry("java.rmi.server.Operation", ::java::rmi::server::Operation),
	$classEntry("java.rmi.server.RMIClassLoader", ::java::rmi::server::RMIClassLoader),
	$classEntry("java.rmi.server.RMIClassLoader$1", ::java::rmi::server::RMIClassLoader$1),
	$classEntry("java.rmi.server.RMIClassLoader$2", ::java::rmi::server::RMIClassLoader$2),
	$classEntry("java.rmi.server.RMIClassLoaderSpi", ::java::rmi::server::RMIClassLoaderSpi),
	$classEntry("java.rmi.server.RMIClientSocketFactory", ::java::rmi::server::RMIClientSocketFactory),
	$classEntry("java.rmi.server.RMIFailureHandler", ::java::rmi::server::RMIFailureHandler),
	$classEntry("java.rmi.server.RMIServerSocketFactory", ::java::rmi::server::RMIServerSocketFactory),
	$classEntry("java.rmi.server.RMISocketFactory", ::java::rmi::server::RMISocketFactory),
	$classEntry("java.rmi.server.RemoteCall", ::java::rmi::server::RemoteCall),
	$classEntry("java.rmi.server.RemoteObject", ::java::rmi::server::RemoteObject),
	$classEntry("java.rmi.server.RemoteObjectInvocationHandler", ::java::rmi::server::RemoteObjectInvocationHandler),
	$classEntry("java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps", ::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps),
	$classEntry("java.rmi.server.RemoteObjectInvocationHandler$MethodToHash_Maps$1", ::java::rmi::server::RemoteObjectInvocationHandler$MethodToHash_Maps$1),
	$classEntry("java.rmi.server.RemoteRef", ::java::rmi::server::RemoteRef),
	$classEntry("java.rmi.server.RemoteServer", ::java::rmi::server::RemoteServer),
	$classEntry("java.rmi.server.RemoteStub", ::java::rmi::server::RemoteStub),
	$classEntry("java.rmi.server.ServerCloneException", ::java::rmi::server::ServerCloneException),
	$classEntry("java.rmi.server.ServerNotActiveException", ::java::rmi::server::ServerNotActiveException),
	$classEntry("java.rmi.server.ServerRef", ::java::rmi::server::ServerRef),
	$classEntry("java.rmi.server.Skeleton", ::java::rmi::server::Skeleton),
	$classEntry("java.rmi.server.SkeletonMismatchException", ::java::rmi::server::SkeletonMismatchException),
	$classEntry("java.rmi.server.SkeletonNotFoundException", ::java::rmi::server::SkeletonNotFoundException),
	$classEntry("java.rmi.server.SocketSecurityException", ::java::rmi::server::SocketSecurityException),
	$classEntry("java.rmi.server.UID", ::java::rmi::server::UID),
	$classEntry("java.rmi.server.UnicastRemoteObject", ::java::rmi::server::UnicastRemoteObject),
	$classEntry("java.rmi.server.Unreferenced", ::java::rmi::server::Unreferenced),
	$classEntry("javax.rmi.ssl.SslRMIClientSocketFactory", ::javax::rmi::ssl::SslRMIClientSocketFactory),
	$classEntry("javax.rmi.ssl.SslRMIServerSocketFactory", ::javax::rmi::ssl::SslRMIServerSocketFactory),
	$classEntry("javax.rmi.ssl.SslRMIServerSocketFactory$1", ::javax::rmi::ssl::SslRMIServerSocketFactory$1),
	$classEntry("sun.rmi.log.LogHandler", ::sun::rmi::log::LogHandler),
	$classEntry("sun.rmi.log.LogInputStream", ::sun::rmi::log::LogInputStream),
	$classEntry("sun.rmi.log.LogOutputStream", ::sun::rmi::log::LogOutputStream),
	$classEntry("sun.rmi.log.ReliableLog", ::sun::rmi::log::ReliableLog),
	$classEntry("sun.rmi.log.ReliableLog$1", ::sun::rmi::log::ReliableLog$1),
	$classEntry("sun.rmi.log.ReliableLog$LogFile", ::sun::rmi::log::ReliableLog$LogFile),
	$classEntry("sun.rmi.registry.RegistryImpl", ::sun::rmi::registry::RegistryImpl),
	$classEntry("sun.rmi.registry.RegistryImpl$1", ::sun::rmi::registry::RegistryImpl$1),
	$classEntry("sun.rmi.registry.RegistryImpl$2", ::sun::rmi::registry::RegistryImpl$2),
	$classEntry("sun.rmi.registry.RegistryImpl$3", ::sun::rmi::registry::RegistryImpl$3),
	$classEntry("sun.rmi.registry.RegistryImpl$4", ::sun::rmi::registry::RegistryImpl$4),
	$classEntry("sun.rmi.registry.RegistryImpl$5", ::sun::rmi::registry::RegistryImpl$5),
	$classEntry("sun.rmi.registry.RegistryImpl$6", ::sun::rmi::registry::RegistryImpl$6),
	$classEntry("sun.rmi.registry.RegistryImpl_Skel", ::sun::rmi::registry::RegistryImpl_Skel),
	$classEntry("sun.rmi.registry.RegistryImpl_Stub", ::sun::rmi::registry::RegistryImpl_Stub),
	$classEntry("sun.rmi.runtime.Log", ::sun::rmi::runtime::Log),
	$classEntry("sun.rmi.runtime.Log$InternalStreamHandler", ::sun::rmi::runtime::Log$InternalStreamHandler),
	$classEntry("sun.rmi.runtime.Log$LogFactory", ::sun::rmi::runtime::Log$LogFactory),
	$classEntry("sun.rmi.runtime.Log$LogStreamLog", ::sun::rmi::runtime::Log$LogStreamLog),
	$classEntry("sun.rmi.runtime.Log$LogStreamLogFactory", ::sun::rmi::runtime::Log$LogStreamLogFactory),
	$classEntry("sun.rmi.runtime.Log$LoggerLog", ::sun::rmi::runtime::Log$LoggerLog),
	$classEntry("sun.rmi.runtime.Log$LoggerLog$1", ::sun::rmi::runtime::Log$LoggerLog$1),
	$classEntry("sun.rmi.runtime.Log$LoggerLog$2", ::sun::rmi::runtime::Log$LoggerLog$2),
	$classEntry("sun.rmi.runtime.Log$LoggerLogFactory", ::sun::rmi::runtime::Log$LoggerLogFactory),
	$classEntry("sun.rmi.runtime.Log$LoggerPrintStream", ::sun::rmi::runtime::Log$LoggerPrintStream),
	$classEntry("sun.rmi.runtime.NewThreadAction", ::sun::rmi::runtime::NewThreadAction),
	$classEntry("sun.rmi.runtime.NewThreadAction$1", ::sun::rmi::runtime::NewThreadAction$1),
	$classEntry("sun.rmi.runtime.NewThreadAction$2", ::sun::rmi::runtime::NewThreadAction$2),
	$classEntry("sun.rmi.runtime.RuntimeUtil", ::sun::rmi::runtime::RuntimeUtil),
	$classEntry("sun.rmi.runtime.RuntimeUtil$1", ::sun::rmi::runtime::RuntimeUtil$1),
	$classEntry("sun.rmi.runtime.RuntimeUtil$GetInstanceAction", ::sun::rmi::runtime::RuntimeUtil$GetInstanceAction),
	$classEntry("sun.rmi.server.DeserializationChecker", ::sun::rmi::server::DeserializationChecker),
	$classEntry("sun.rmi.server.Dispatcher", ::sun::rmi::server::Dispatcher),
	$classEntry("sun.rmi.server.LoaderHandler", ::sun::rmi::server::LoaderHandler),
	$classEntry("sun.rmi.server.LoaderHandler$1", ::sun::rmi::server::LoaderHandler$1),
	$classEntry("sun.rmi.server.LoaderHandler$2", ::sun::rmi::server::LoaderHandler$2),
	$classEntry("sun.rmi.server.LoaderHandler$Loader", ::sun::rmi::server::LoaderHandler$Loader),
	$classEntry("sun.rmi.server.LoaderHandler$LoaderEntry", ::sun::rmi::server::LoaderHandler$LoaderEntry),
	$classEntry("sun.rmi.server.LoaderHandler$LoaderKey", ::sun::rmi::server::LoaderHandler$LoaderKey),
	$classEntry("sun.rmi.server.MarshalInputStream", ::sun::rmi::server::MarshalInputStream),
	$classEntry("sun.rmi.server.MarshalOutputStream", ::sun::rmi::server::MarshalOutputStream),
	$classEntry("sun.rmi.server.MarshalOutputStream$1", ::sun::rmi::server::MarshalOutputStream$1),
	$classEntry("sun.rmi.server.UnicastRef", ::sun::rmi::server::UnicastRef),
	$classEntry("sun.rmi.server.UnicastRef2", ::sun::rmi::server::UnicastRef2),
	$classEntry("sun.rmi.server.UnicastServerRef", ::sun::rmi::server::UnicastServerRef),
	$classEntry("sun.rmi.server.UnicastServerRef$HashToMethod_Maps", ::sun::rmi::server::UnicastServerRef$HashToMethod_Maps),
	$classEntry("sun.rmi.server.UnicastServerRef$HashToMethod_Maps$1", ::sun::rmi::server::UnicastServerRef$HashToMethod_Maps$1),
	$classEntry("sun.rmi.server.UnicastServerRef2", ::sun::rmi::server::UnicastServerRef2),
	$classEntry("sun.rmi.server.Util", ::sun::rmi::server::Util),
	$classEntry("sun.rmi.server.Util$1", ::sun::rmi::server::Util$1),
	$classEntry("sun.rmi.server.WeakClassHashMap", ::sun::rmi::server::WeakClassHashMap),
	$classEntry("sun.rmi.server.WeakClassHashMap$ValueCell", ::sun::rmi::server::WeakClassHashMap$ValueCell),
	$classEntry("sun.rmi.transport.Channel", ::sun::rmi::transport::Channel),
	$classEntry("sun.rmi.transport.Connection", ::sun::rmi::transport::Connection),
	$classEntry("sun.rmi.transport.ConnectionInputStream", ::sun::rmi::transport::ConnectionInputStream),
	$classEntry("sun.rmi.transport.ConnectionOutputStream", ::sun::rmi::transport::ConnectionOutputStream),
	$classEntry("sun.rmi.transport.DGCAckHandler", ::sun::rmi::transport::DGCAckHandler),
	$classEntry("sun.rmi.transport.DGCAckHandler$1", ::sun::rmi::transport::DGCAckHandler$1),
	$classEntry("sun.rmi.transport.DGCClient", ::sun::rmi::transport::DGCClient),
	$classEntry("sun.rmi.transport.DGCClient$EndpointEntry", ::sun::rmi::transport::DGCClient$EndpointEntry),
	$classEntry("sun.rmi.transport.DGCClient$EndpointEntry$1", ::sun::rmi::transport::DGCClient$EndpointEntry$1),
	$classEntry("sun.rmi.transport.DGCClient$EndpointEntry$CleanRequest", ::sun::rmi::transport::DGCClient$EndpointEntry$CleanRequest),
	$classEntry("sun.rmi.transport.DGCClient$EndpointEntry$RefEntry", ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry),
	$classEntry("sun.rmi.transport.DGCClient$EndpointEntry$RefEntry$PhantomLiveRef", ::sun::rmi::transport::DGCClient$EndpointEntry$RefEntry$PhantomLiveRef),
	$classEntry("sun.rmi.transport.DGCClient$EndpointEntry$RenewCleanThread", ::sun::rmi::transport::DGCClient$EndpointEntry$RenewCleanThread),
	$classEntry("sun.rmi.transport.DGCImpl", ::sun::rmi::transport::DGCImpl),
	$classEntry("sun.rmi.transport.DGCImpl$1", ::sun::rmi::transport::DGCImpl$1),
	$classEntry("sun.rmi.transport.DGCImpl$2", ::sun::rmi::transport::DGCImpl$2),
	$classEntry("sun.rmi.transport.DGCImpl$2$1", ::sun::rmi::transport::DGCImpl$2$1),
	$classEntry("sun.rmi.transport.DGCImpl$LeaseInfo", ::sun::rmi::transport::DGCImpl$LeaseInfo),
	$classEntry("sun.rmi.transport.DGCImpl_Skel", ::sun::rmi::transport::DGCImpl_Skel),
	$classEntry("sun.rmi.transport.DGCImpl_Stub", ::sun::rmi::transport::DGCImpl_Stub),
	$classEntry("sun.rmi.transport.Endpoint", ::sun::rmi::transport::Endpoint),
	$classEntry("sun.rmi.transport.GC", ::sun::rmi::transport::GC),
	$classEntry("sun.rmi.transport.GC$1", ::sun::rmi::transport::GC$1),
	$classEntry("sun.rmi.transport.GC$Daemon", ::sun::rmi::transport::GC$Daemon),
	$classEntry("sun.rmi.transport.GC$Daemon$1", ::sun::rmi::transport::GC$Daemon$1),
	$classEntry("sun.rmi.transport.GC$LatencyLock", ::sun::rmi::transport::GC$LatencyLock),
	$classEntry("sun.rmi.transport.GC$LatencyRequest", ::sun::rmi::transport::GC$LatencyRequest),
	$classEntry("sun.rmi.transport.LiveRef", ::sun::rmi::transport::LiveRef),
	$classEntry("sun.rmi.transport.ObjectEndpoint", ::sun::rmi::transport::ObjectEndpoint),
	$classEntry("sun.rmi.transport.ObjectTable", ::sun::rmi::transport::ObjectTable),
	$classEntry("sun.rmi.transport.ObjectTable$1", ::sun::rmi::transport::ObjectTable$1),
	$classEntry("sun.rmi.transport.ObjectTable$Reaper", ::sun::rmi::transport::ObjectTable$Reaper),
	$classEntry("sun.rmi.transport.SequenceEntry", ::sun::rmi::transport::SequenceEntry),
	$classEntry("sun.rmi.transport.StreamRemoteCall", ::sun::rmi::transport::StreamRemoteCall),
	$classEntry("sun.rmi.transport.Target", ::sun::rmi::transport::Target),
	$classEntry("sun.rmi.transport.Transport", ::sun::rmi::transport::Transport),
	$classEntry("sun.rmi.transport.Transport$1", ::sun::rmi::transport::Transport$1),
	$classEntry("sun.rmi.transport.TransportConstants", ::sun::rmi::transport::TransportConstants),
	$classEntry("sun.rmi.transport.WeakRef", ::sun::rmi::transport::WeakRef),
	$classEntry("sun.rmi.transport.tcp.ConnectionAcceptor", ::sun::rmi::transport::tcp::ConnectionAcceptor),
	$classEntry("sun.rmi.transport.tcp.TCPChannel", ::sun::rmi::transport::tcp::TCPChannel),
	$classEntry("sun.rmi.transport.tcp.TCPChannel$1", ::sun::rmi::transport::tcp::TCPChannel$1),
	$classEntry("sun.rmi.transport.tcp.TCPConnection", ::sun::rmi::transport::tcp::TCPConnection),
	$classEntry("sun.rmi.transport.tcp.TCPDirectSocketFactory", ::sun::rmi::transport::tcp::TCPDirectSocketFactory),
	$classEntry("sun.rmi.transport.tcp.TCPEndpoint", ::sun::rmi::transport::tcp::TCPEndpoint),
	$classEntry("sun.rmi.transport.tcp.TCPEndpoint$FQDN", ::sun::rmi::transport::tcp::TCPEndpoint$FQDN),
	$classEntry("sun.rmi.transport.tcp.TCPTransport", ::sun::rmi::transport::tcp::TCPTransport),
	$classEntry("sun.rmi.transport.tcp.TCPTransport$1", ::sun::rmi::transport::tcp::TCPTransport$1),
	$classEntry("sun.rmi.transport.tcp.TCPTransport$AcceptLoop", ::sun::rmi::transport::tcp::TCPTransport$AcceptLoop),
	$classEntry("sun.rmi.transport.tcp.TCPTransport$ConnectionHandler", ::sun::rmi::transport::tcp::TCPTransport$ConnectionHandler)
};

const char* _java$rmi_packages_[] = {
	"java.rmi",
	"java.rmi.dgc",
	"java.rmi.registry",
	"java.rmi.server",
	"javax.rmi.ssl",
	"sun.rmi.log",
	"sun.rmi.registry",
	"sun.rmi.runtime",
	"sun.rmi.server",
	"sun.rmi.transport",
	"sun.rmi.transport.tcp"
};

void java$rmi$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$rmi_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$rmi_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$rmi$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$rmi$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$rmi$GetPackages() {
	int32_t length = $lengthOf(_java$rmi_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$rmi_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$rmi$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$rmi_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$rmi_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$rmi$GetResource($String* name) {
	return nullptr;
}

void java$rmi::init() {
	::java$base::init();
	::java$logging::init();
	::java::lang::Library lib = {
		"java.rmi", "17.35", "",
		&_java$rmi_ModuleInfo_,
		java$rmi$LibEventAction,
		java$rmi$GetPackages,
		java$rmi$GetClassEntry,
		java$rmi$GetResource
	};
	$System::addLibrary(&lib);
}