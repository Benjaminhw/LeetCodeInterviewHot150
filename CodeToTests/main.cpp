//vcpkg cmake


#include "function.h"

int main()
{
    // 设置stock代码和API密钥
    std::string symbol = "AAPL"; // 代码
    std::string apiKey = "YOUR_API_KEY"; // 替换为您的Alpha Vantage API密钥

    // 构建API请求URL
    std::string apiUrl = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + symbol + "&apikey=" + apiKey;

    // 初始化libcurl
    CURL* curl = curl_easy_init();
    if (curl) {
        // 设置curl参数
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
        std::string responseBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        // 执行curl请求
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }

        // 解析JSON响应
        rapidjson::Document jsonDocument;
        jsonDocument.Parse(responseBuffer.c_str());
        if (jsonDocument.HasParseError()) {
            std::cerr << "Error parsing JSON response" << std::endl;
            return 1;
        }

        // 提取stock价格并打印
        if (jsonDocument.HasMember("Global Quote")) {
            const rapidjson::Value& globalQuote = jsonDocument["Global Quote"];
            if (globalQuote.HasMember("05. price")) {
                std::string price = globalQuote["05. price"].GetString();
                std::cout << "Current stock price for " << symbol << ": " << price << std::endl;
            }
            else {
                std::cerr << "Error: Unable to retrieve stock price from JSON response" << std::endl;
            }
        }
        else {
            std::cerr << "Error: JSON response does not contain expected data" << std::endl;
        }

        // 清理curl资源
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Failed to initialize libcurl" << std::endl;
        return 1;
    }

    return 0;
}
