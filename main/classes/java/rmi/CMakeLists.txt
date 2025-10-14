#machine generated

add_subdirectory("dgc")
add_subdirectory("registry")
add_subdirectory("server")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.rmi_SRCS)
file(GLOB classes.java.rmi_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.rmi_HEADERS}) 
list(LENGTH classes.java.rmi_SRCS classes.java.rmi_SRCS_LENGTH)
if(classes.java.rmi_SRCS_LENGTH)
	add_library(classes.java.rmi OBJECT "${classes.java.rmi_SRCS}" "${classes.java.rmi_HEADERS}")
	jcpp_enable_bigobj(classes.java.rmi)
endif()