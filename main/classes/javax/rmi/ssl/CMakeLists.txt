#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.rmi.ssl_SRCS)
file(GLOB classes.javax.rmi.ssl_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.rmi.ssl_HEADERS}) 
list(LENGTH classes.javax.rmi.ssl_SRCS classes.javax.rmi.ssl_SRCS_LENGTH)
if(classes.javax.rmi.ssl_SRCS_LENGTH)
	add_library(classes.javax.rmi.ssl OBJECT "${classes.javax.rmi.ssl_SRCS}" "${classes.javax.rmi.ssl_HEADERS}")
	jcpp_enable_bigobj(classes.javax.rmi.ssl)
endif()