#ifndef _sun_rmi_runtime_Log_h_
#define _sun_rmi_runtime_Log_h_
//$ class sun.rmi.runtime.Log
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("BRIEF")
#undef BRIEF
#pragma push_macro("VERBOSE")
#undef VERBOSE
#pragma push_macro("WALKER")
#undef WALKER

namespace java {
	namespace io {
		class OutputStream;
		class PrintStream;
	}
}
namespace java {
	namespace lang {
		class Boolean;
		class StackWalker;
		class StackWalker$StackFrame;
		class Throwable;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Level;
		}
	}
}
namespace java {
	namespace util {
		namespace stream {
			class Stream;
		}
	}
}
namespace sun {
	namespace rmi {
		namespace runtime {
			class Log$LogFactory;
		}
	}
}

namespace sun {
	namespace rmi {
		namespace runtime {

class Log : public ::java::lang::Object {
	$class(Log, 0, ::java::lang::Object)
public:
	Log();
	void init$();
	static ::sun::rmi::runtime::Log* getLog($String* loggerName, $String* oldLogName, int32_t override$);
	static ::sun::rmi::runtime::Log* getLog($String* loggerName, $String* oldLogName, bool override$);
	virtual ::java::io::PrintStream* getPrintStream() {return nullptr;}
	static ::java::lang::StackWalker$StackFrame* getSource();
	virtual bool isLoggable(::java::util::logging::Level* level) {return false;}
	static ::java::lang::StackWalker$StackFrame* lambda$getSource$1(::java::util::stream::Stream* s);
	static ::java::lang::Boolean* lambda$static$0();
	virtual void log(::java::util::logging::Level* level, $String* message) {}
	virtual void log(::java::util::logging::Level* level, $String* message, $Throwable* thrown) {}
	virtual void setOutputStream(::java::io::OutputStream* stream) {}
	static ::java::util::logging::Level* BRIEF;
	static ::java::util::logging::Level* VERBOSE;
	static ::java::lang::StackWalker* WALKER;
	static ::sun::rmi::runtime::Log$LogFactory* logFactory;
};

		} // runtime
	} // rmi
} // sun

#pragma pop_macro("BRIEF")
#pragma pop_macro("VERBOSE")
#pragma pop_macro("WALKER")

#endif // _sun_rmi_runtime_Log_h_