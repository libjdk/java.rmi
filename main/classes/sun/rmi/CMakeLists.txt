#machine generated

add_subdirectory("log")
add_subdirectory("registry")
add_subdirectory("runtime")
add_subdirectory("server")
add_subdirectory("transport")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.rmi_SRCS)
file(GLOB classes.sun.rmi_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.rmi_HEADERS}) 
list(LENGTH classes.sun.rmi_SRCS classes.sun.rmi_SRCS_LENGTH)
if(classes.sun.rmi_SRCS_LENGTH)
	add_library(classes.sun.rmi OBJECT "${classes.sun.rmi_SRCS}" "${classes.sun.rmi_HEADERS}")
	jcpp_enable_bigobj(classes.sun.rmi)
endif()