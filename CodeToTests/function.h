//#pragma once
//
////git clone https://github.com/microsoft/vcpkg //建议使用powershell
////bootstrap-vcpkg.bat
////.\vcpkg install *
////.\vcpkg integrate install / remove
////.\vcpkg integrate project
////nuget包 程序源包更新地址
////右击工程 nuget 安装（sln）
////集成cmake: -DCMAKE_TOOLCHAIN_FILE=<vcpkg_dir>/scripts/buildsystems/vcpkg.cmake
//
//#include <iostream>
//#include <vector>
//#include <curl/curl.h>
//#include <rapidjson/document.h>
//#include "stddef.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
//#include <fstream>
//#include <map>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//
//class Solution {
//public:
//
//};
//
//class GetStockInfFac {
//public:
//    int mainFunction();
//    std::map<std::string, std::string> parseString(const std::string& str, char delimiter);
//    std::string mapToJson(const std::map<std::string, std::string>& data);
//    static size_t writeMemoryCallback(char* contents, size_t size, size_t nmemb, void* buffer) {
//        size_t totalSize = size * nmemb;
//        ((string *)buffer)->append(contents, totalSize);
//        return totalSize;
//    }
//};