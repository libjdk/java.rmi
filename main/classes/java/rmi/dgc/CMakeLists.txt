#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.rmi.dgc_SRCS)
file(GLOB classes.java.rmi.dgc_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.rmi.dgc_HEADERS}) 
list(LENGTH classes.java.rmi.dgc_SRCS classes.java.rmi.dgc_SRCS_LENGTH)
if(classes.java.rmi.dgc_SRCS_LENGTH)
	add_library(classes.java.rmi.dgc OBJECT "${classes.java.rmi.dgc_SRCS}" "${classes.java.rmi.dgc_HEADERS}")
	jcpp_enable_bigobj(classes.java.rmi.dgc)
endif()