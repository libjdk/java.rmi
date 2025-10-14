#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.rmi.registry_SRCS)
file(GLOB classes.sun.rmi.registry_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.rmi.registry_HEADERS}) 
list(LENGTH classes.sun.rmi.registry_SRCS classes.sun.rmi.registry_SRCS_LENGTH)
if(classes.sun.rmi.registry_SRCS_LENGTH)
	add_library(classes.sun.rmi.registry OBJECT "${classes.sun.rmi.registry_SRCS}" "${classes.sun.rmi.registry_HEADERS}")
	jcpp_enable_bigobj(classes.sun.rmi.registry)
endif()