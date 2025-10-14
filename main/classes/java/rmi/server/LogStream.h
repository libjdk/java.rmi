#ifndef _java_rmi_server_LogStream_h_
#define _java_rmi_server_LogStream_h_
//$ class java.rmi.server.LogStream
//$ extends java.io.PrintStream

#include <java/io/PrintStream.h>
#include <java/lang/Array.h>

#pragma push_macro("BRIEF")
#undef BRIEF
#pragma push_macro("SILENT")
#undef SILENT
#pragma push_macro("VERBOSE")
#undef VERBOSE

namespace java {
	namespace io {
		class ByteArrayOutputStream;
		class OutputStream;
		class OutputStreamWriter;
	}
}
namespace java {
	namespace lang {
		class StringBuffer;
	}
}
namespace java {
	namespace util {
		class Map;
	}
}

namespace java {
	namespace rmi {
		namespace server {

class $export LogStream : public ::java::io::PrintStream {
	$class(LogStream, 0, ::java::io::PrintStream)
public:
	LogStream();
	void init$($String* name, ::java::io::OutputStream* out);
	static ::java::io::PrintStream* getDefaultStream();
	virtual ::java::io::OutputStream* getOutputStream();
	static ::java::rmi::server::LogStream* log($String* name);
	static int32_t parseLevel($String* s);
	static void setDefaultStream(::java::io::PrintStream* newDefault);
	virtual void setOutputStream(::java::io::OutputStream* out);
	virtual $String* toString() override;
	using ::java::io::PrintStream::write;
	virtual void write(int32_t b) override;
	virtual void write($bytes* b, int32_t off, int32_t len) override;
	static ::java::util::Map* known;
	static ::java::io::PrintStream* defaultStream;
	$String* name = nullptr;
	::java::io::OutputStream* logOut = nullptr;
	::java::io::OutputStreamWriter* logWriter = nullptr;
	::java::lang::StringBuffer* buffer = nullptr;
	::java::io::ByteArrayOutputStream* bufOut = nullptr;
	static const int32_t SILENT = 0;
	static const int32_t BRIEF = 10;
	static const int32_t VERBOSE = 20;
};

		} // server
	} // rmi
} // java

#pragma pop_macro("BRIEF")
#pragma pop_macro("SILENT")
#pragma pop_macro("VERBOSE")

#endif // _java_rmi_server_LogStream_h_