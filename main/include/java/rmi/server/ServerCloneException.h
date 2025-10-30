#ifndef _java_rmi_server_ServerCloneException_h_
#define _java_rmi_server_ServerCloneException_h_
//$ class java.rmi.server.ServerCloneException
//$ extends java.lang.CloneNotSupportedException

#include <java/lang/CloneNotSupportedException.h>

namespace java {
	namespace lang {
		class Exception;
		class Throwable;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $import ServerCloneException : public ::java::lang::CloneNotSupportedException {
	$class(ServerCloneException, $NO_CLASS_INIT, ::java::lang::CloneNotSupportedException)
public:
	ServerCloneException();
	void init$($String* s);
	void init$($String* s, ::java::lang::Exception* cause);
	virtual $Throwable* getCause() override;
	virtual $String* getMessage() override;
	::java::lang::Exception* detail = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x5BD5ED7F1B42FB49;
	ServerCloneException(const ServerCloneException& e);
	virtual void throw$() override;
	inline ServerCloneException* operator ->() {
		return (ServerCloneException*)throwing$;
	}
};

		} // server
	} // rmi
} // java

#endif // _java_rmi_server_ServerCloneException_h_