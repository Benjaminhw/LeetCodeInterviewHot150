////vcpkg cmake
//
//
//#include "function.h"
//
//int main()
//{
//	GetStockInfFac A;
//	A.mainFunction();
//	return 0;
//}
//
//std::map<std::string, std::string> GetStockInfFac::parseString(const std::string& str, char delimiter) {
//	std::map<std::string, std::string> result;
//	std::stringstream ss(str);
//	std::string item;
//	int index = 0;
//	while (getline(ss, item, delimiter)) {
//		switch (index) {
//		case 1:
//			result["name"] = item;
//			break;
//		case 2:
//			result["code"] = item;
//			break;
//		case 3:
//			result["current_price"] = item;
//			break;
//		case 4:
//			result["change"] = item;
//			break;
//		case 5:
//			result["change_percent"] = item;
//			break;
//		case 6:
//			result["volume"] = item;
//			break;
//		case 7:
//			result["turnover"] = item;
//			break;
//		case 8:
//			result["market_value"] = item;
//			break;
//		default:
//			break;
//		}
//		index++;
//	}
//	return result;
//}
//
//std::string GetStockInfFac::mapToJson(const std::map<std::string, std::string>& data) {
//	rapidjson::Document doc;
//	doc.SetObject();
//	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
//
//	for (const auto& pair : data) {
//		rapidjson::Value key(pair.first.c_str(), allocator);
//		rapidjson::Value value(pair.second.c_str(), allocator);
//		doc.AddMember(key, value, allocator);
//	}
//
//	rapidjson::StringBuffer buffer;
//	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
//	doc.Accept(writer);
//
//	return buffer.GetString();
//}
//
//int GetStockInfFac::mainFunction()
//{
//	//https: //stock.xueqiu.com/v5/stock/realtime/quotec.json?symbol=SZ002587&_=1541640828575 //
//	//https: //qt.gtimg.cn/q=s_sz002587 //可以用 tx
//	//// 设置stock代码和API密钥
//	//std::string symbol = "601001.sh"; // 代码
//
//	// 构建API请求URL
//	std::string apiUrl = "https://qt.gtimg.cn/q=s_sz002587";
//	// 初始化libcurl
//
//	CURL* curl = curl_easy_init();
//	if (curl) {
//		// 设置curl参数
//		curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
//		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36 Edg/122.0.0.0");
//
//		//// 设置用于保存cookie的文件
//		//curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookies.txt");
//		//// 设置用于读取cookie的文件
//		//curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");
//		// 设置Referer头部字段，模拟浏览器
//		//curl_easy_setopt(curl, CURLOPT_REFERER, "https: //xueqiu.com/");
//		// 设置Accept头部字段，模拟浏览器
//		//curl_easy_setopt(curl, CURLOPT_ACCEPT, "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
//
//		std::string responseBuffer;
//		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
//		//curl_easy_setopt(curl, CURLOPT_REFERER, "");
//
//
//		// 执行curl请求
//		CURLcode res = curl_easy_perform(curl);
//		if (res != CURLE_OK) {
//			std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
//			return 1;
//		}
//
//		//// 解析JSON响应
//		//rapidjson::Document jsonDocument;
//		//jsonDocument.Parse(responseBuffer.c_str());
//		//if (jsonDocument.HasParseError()) {
//		//    std::cerr << "Error parsing JSON response" << std::endl;
//		//    return 1;
//		//}
//		// Print
//		//if (jsonDocument.HasMember("Global Quote")) {
//		//    const rapidjson::Value& globalQuote = jsonDocument["Global Quote"];
//		//    if (globalQuote.HasMember("05. price")) {
//		//        std::string price = globalQuote["05. price"].GetString();
//		//        std::cout << "Current stock price for " << "test name" << ": " << price << std::endl;
//		//    }
//		//    else {
//		//        std::cerr << "Error: Unable to retrieve stock price from JSON response" << std::endl;
//		//    }
//		//}
//		//else {
//		//    std::cerr << "Error: JSON response does not contain expected data" << std::endl;
//		//}
//
//		auto x = parseString(responseBuffer, '~');
//		auto tempJson = mapToJson(x);
//
//		ofstream tempStream;
//		tempStream.open("testjson.json");
//		tempStream << tempJson;
//		tempStream.close();
//
//		// 清理curl资源
//		curl_easy_cleanup(curl);
//	}
//	else {
//		std::cerr << "Failed to initialize libcurl" << std::endl;
//		return 1;
//	}
//
//	return 0;
//}
