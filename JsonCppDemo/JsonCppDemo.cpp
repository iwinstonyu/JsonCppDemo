// JsonCppDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <json\json.h>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("response.txt");

	typedef Json::Reader JReader;
	typedef Json::Value	JValue;

	JReader reader;
	JValue response;
	
	if (reader.parse(ifs, response))
	{
		JValue resultList = response["result_list"];

		for (Json::ArrayIndex i = 0; i < resultList.size(); ++i)
		{
			JValue tempResult = resultList[i];

			cout << "code: " << tempResult["code"].asInt() << endl;
			cout << "message: " << tempResult["message"].asString() << endl;
			cout << "url: " << tempResult["url"].asString() << endl;

			JValue data = tempResult["data"];
			cout << "result: " << data["result"].asString() << endl;
			cout << "forbid_status: " << data["forbid_status"].asString() << endl;
			cout << "confidence: " << data["confidence"].asString() << endl;
			cout << "hot_score: " << data["hot_score"].asString() << endl;
			cout << "normal_score: " << data["normal_score"].asString() << endl;
			cout << "porn_score: " << data["porn_score"].asString() << endl;
		}
	}

	ifs.close();

	system("pause");
    return 0;
}

