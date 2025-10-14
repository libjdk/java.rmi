#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.rmi.log_SRCS)
file(GLOB classes.sun.rmi.log_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.rmi.log_HEADERS}) 
list(LENGTH classes.sun.rmi.log_SRCS classes.sun.rmi.log_SRCS_LENGTH)
if(classes.sun.rmi.log_SRCS_LENGTH)
	add_library(classes.sun.rmi.log OBJECT "${classes.sun.rmi.log_SRCS}" "${classes.sun.rmi.log_HEADERS}")
	jcpp_enable_bigobj(classes.sun.rmi.log)
endif()