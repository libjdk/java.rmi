#machine generated

add_subdirectory("ssl")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.rmi_SRCS)
file(GLOB classes.javax.rmi_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.rmi_HEADERS}) 
list(LENGTH classes.javax.rmi_SRCS classes.javax.rmi_SRCS_LENGTH)
if(classes.javax.rmi_SRCS_LENGTH)
	add_library(classes.javax.rmi OBJECT "${classes.javax.rmi_SRCS}" "${classes.javax.rmi_HEADERS}")
	jcpp_enable_bigobj(classes.javax.rmi)
endif()