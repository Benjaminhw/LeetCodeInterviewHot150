#pragma once

//git clone https://github.com/microsoft/vcpkg //����ʹ��powershell
//bootstrap-vcpkg.bat
//.\vcpkg install *
//.\vcpkg integrate install / remove
//.\vcpkg integrate project
//nuget�� ����Դ�����µ�ַ
//�һ����� nuget ��װ��sln��
//����cmake: -DCMAKE_TOOLCHAIN_FILE=<vcpkg_dir>/scripts/buildsystems/vcpkg.cmake

#include <iostream>
#include <vector>
#include "curl/curl.h"
#include "rapidjson/document.h"
#include "stddef.h"

using namespace std;


class Solution {
public:

};

class GetStockInfFac {
public:
    size_t writeMemoryCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
        size_t totalSize = size * nmemb;
        buffer->append((char*)contents, totalSize);
        return totalSize;
    }
};