#ifndef _sun_rmi_runtime_NewThreadAction_h_
#define _sun_rmi_runtime_NewThreadAction_h_
//$ class sun.rmi.runtime.NewThreadAction
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		class Runnable;
		class ThreadGroup;
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class NewThreadAction : public ::java::security::PrivilegedAction {
	$class(NewThreadAction, 0, ::java::security::PrivilegedAction)
public:
	NewThreadAction();
	void init$(::java::lang::ThreadGroup* group, ::java::lang::Runnable* runnable, $String* name, bool daemon);
	void init$(::java::lang::Runnable* runnable, $String* name, bool daemon);
	void init$(::java::lang::Runnable* runnable, $String* name, bool daemon, bool user);
	virtual $Object* run() override;
	static ::java::lang::ThreadGroup* systemThreadGroup;
	static ::java::lang::ThreadGroup* userThreadGroup;
	::java::lang::ThreadGroup* group = nullptr;
	::java::lang::Runnable* runnable = nullptr;
	$String* name = nullptr;
	bool daemon = false;
};

		} // runtime
	} // rmi
} // sun

#endif // _sun_rmi_runtime_NewThreadAction_h_