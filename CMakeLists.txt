cmake_minimum_required(VERSION 3.0.0)
project(costumeconverter VERSION 1.0.0)

SET (PROJECT_CREATOR "shepher")
configure_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/config.h"
)

add_executable(costumeconverter 
	src/pugixml/pugixml.cpp
	src/main.cpp 
	src/Bin2TextConverter.cpp
	src/Text2BinConverter.cpp
	src/Bin2XmlConverter.cpp
	src/Xml2BinConverter.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
