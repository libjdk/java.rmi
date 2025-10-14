#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.rmi.server_SRCS)
file(GLOB classes.java.rmi.server_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.rmi.server_HEADERS}) 
list(LENGTH classes.java.rmi.server_SRCS classes.java.rmi.server_SRCS_LENGTH)
if(classes.java.rmi.server_SRCS_LENGTH)
	add_library(classes.java.rmi.server OBJECT "${classes.java.rmi.server_SRCS}" "${classes.java.rmi.server_HEADERS}")
	jcpp_enable_bigobj(classes.java.rmi.server)
endif()