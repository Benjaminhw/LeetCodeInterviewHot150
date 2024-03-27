cmake_minimum_required (VERSION 3.8)

project ("CodeToTests")

# 将源代码添加到此项目的可执行文件。
add_executable (CodeToTests
"function.h"
"main.cpp"
)

set(CMAKE_TOOLCHAIN_FILE "${sourceDir}/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(curl CONFIG REQUIRED)
find_package(rapidjson CONFIG REQUIRED)
# target_link_directories("D:/earning/LeetCode/LeetCodeInterviewClassic150/vcpkg/packages/curl_x64-windows/lib")
target_link_libraries(CodeToTests PRIVATE curl)
target_link_libraries(CodeToTests PRIVATE rapidjson)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CodeToTests PROPERTY CXX_STANDARD 20)
endif()