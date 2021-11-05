cmake_minimum_required(VERSION 3.20)
project(ImageRecoveryTEC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}"${${PROJECT_NAME}_SOURCE_DIR}/cmake")

find_package( Qt5Core REQUIRED)
find_package( Qt5Widgets REQUIRED)
find_package( Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(ImageRecoveryTEC main.cpp GUI_ImageRecovery/ImageRecoveryGUI.cpp GUI_ImageRecovery/ImageRecoveryGUI.h dataStructures/CircularLinkedList.h)
target_link_libraries(ImageRecoveryTEC Qt5::Widgets)