#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.rmi.registry_SRCS)
file(GLOB classes.java.rmi.registry_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.rmi.registry_HEADERS}) 
list(LENGTH classes.java.rmi.registry_SRCS classes.java.rmi.registry_SRCS_LENGTH)
if(classes.java.rmi.registry_SRCS_LENGTH)
	add_library(classes.java.rmi.registry OBJECT "${classes.java.rmi.registry_SRCS}" "${classes.java.rmi.registry_HEADERS}")
	jcpp_enable_bigobj(classes.java.rmi.registry)
endif()