cmake_minimum_required (VERSION 3.8)

project ("CodeToTests")

# 将源代码添加到此项目的可执行文件。
add_executable (CodeToTests
"function.h"
"main.cpp"
)

set(CMAKE_TOOLCHAIN_FILE "D:/learning/StockMonitor/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(CURL REQUIRED)
target_link_libraries(CodeToTests PRIVATE CURL::libcurl)

find_package(rapidjson CONFIG REQUIRED)
target_link_libraries(CodeToTests PRIVATE rapidjson)

# find_package(tinyxml config required)
# target_link_libraries(CodeToTests private unofficial-tinyxml::unofficial-tinyxml)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CodeToTests PROPERTY CXX_STANDARD 20)
endif()