cmake_minimum_required(VERSION 3.5)
project(music)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH "../")

#查找Qt的库
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(PythonLibs 3.5 REQUIRED)

set(SOURCE_FILES main.cpp Interface.cpp Interface.h cpp/components/WButton.cpp cpp/components/WButton.h cpp/components/Awesome.h cpp/models/Song.cpp cpp/models/Song.h cpp/components/TitleBar.cpp cpp/components/TitleBar.h cpp/components/MainWindow.cpp cpp/components/MainWindow.h cpp/components/PlayBar.cpp cpp/components/PlayBar.h cpp/components/Awesome.cpp)
add_executable(music ${SOURCE_FILES})
target_link_libraries(music Qt5::Widgets)
target_link_libraries(music Qt5::Gui)
target_link_libraries(music Qt5::Core)
target_link_libraries(music python3.5m)