#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.rmi.runtime_SRCS)
file(GLOB classes.sun.rmi.runtime_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.rmi.runtime_HEADERS}) 
list(LENGTH classes.sun.rmi.runtime_SRCS classes.sun.rmi.runtime_SRCS_LENGTH)
if(classes.sun.rmi.runtime_SRCS_LENGTH)
	add_library(classes.sun.rmi.runtime OBJECT "${classes.sun.rmi.runtime_SRCS}" "${classes.sun.rmi.runtime_HEADERS}")
	jcpp_enable_bigobj(classes.sun.rmi.runtime)
endif()