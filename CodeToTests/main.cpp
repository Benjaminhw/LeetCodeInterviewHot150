//vcpkg cmake


#include "function.h"

int main()
{
    // ����stock�����API��Կ
    std::string symbol = "AAPL"; // ����
    std::string apiKey = "YOUR_API_KEY"; // �滻Ϊ����Alpha Vantage API��Կ

    // ����API����URL
    std::string apiUrl = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + symbol + "&apikey=" + apiKey;

    // ��ʼ��libcurl
    CURL* curl = curl_easy_init();
    if (curl) {
        // ����curl����
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
        std::string responseBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

        // ִ��curl����
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }

        // ����JSON��Ӧ
        rapidjson::Document jsonDocument;
        jsonDocument.Parse(responseBuffer.c_str());
        if (jsonDocument.HasParseError()) {
            std::cerr << "Error parsing JSON response" << std::endl;
            return 1;
        }

        // ��ȡstock�۸񲢴�ӡ
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

        // ����curl��Դ
        curl_easy_cleanup(curl);
    }
    else {
        std::cerr << "Failed to initialize libcurl" << std::endl;
        return 1;
    }

    return 0;
}
