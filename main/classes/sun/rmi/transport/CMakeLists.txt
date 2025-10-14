#machine generated

add_subdirectory("tcp")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.rmi.transport_SRCS)
file(GLOB classes.sun.rmi.transport_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.rmi.transport_HEADERS}) 
list(LENGTH classes.sun.rmi.transport_SRCS classes.sun.rmi.transport_SRCS_LENGTH)
if(classes.sun.rmi.transport_SRCS_LENGTH)
	add_library(classes.sun.rmi.transport OBJECT "${classes.sun.rmi.transport_SRCS}" "${classes.sun.rmi.transport_HEADERS}")
	jcpp_enable_bigobj(classes.sun.rmi.transport)
endif()