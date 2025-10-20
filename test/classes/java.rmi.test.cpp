#include <java.rmi.test.h>

#include <java.rmi.h>
#include <java.base.h>
#include <java.logging.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$rmi$test$PreloadClass(void* eventData) {
}

void java$rmi$test$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$rmi$test$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$rmi$test$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$rmi$test$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$rmi$test$GetResource($String* name) {
	return nullptr;
}

void java$rmi$test::init() {
	::java$rmi::init();
	::java$base::init();
	::java$logging::init();
	::java::lang::Library lib = {
		"java.rmi.test", "17.35", "",
		nullptr,
		java$rmi$test$LibEventAction,
		java$rmi$test$GetPackages,
		java$rmi$test$GetClassEntry,
		java$rmi$test$GetResource
	};
	$System::addLibrary(&lib);
	$System::init();
}