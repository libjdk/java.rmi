#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.rmi.server_SRCS)
file(GLOB classes.sun.rmi.server_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.rmi.server_HEADERS}) 
list(LENGTH classes.sun.rmi.server_SRCS classes.sun.rmi.server_SRCS_LENGTH)
if(classes.sun.rmi.server_SRCS_LENGTH)
	add_library(classes.sun.rmi.server OBJECT "${classes.sun.rmi.server_SRCS}" "${classes.sun.rmi.server_HEADERS}")
	jcpp_enable_bigobj(classes.sun.rmi.server)
endif()