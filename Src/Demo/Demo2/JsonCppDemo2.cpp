// JsonCppDemo2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <json/json.h>
#include <fstream>
#include <iostream>
#include <string>
//#include <boost/locale/encoding.hpp>
using namespace std;

typedef Json::Reader JReader;
typedef Json::Value	JValue;

void PrintJValue(JValue& value, string prefix)
{
	prefix += "--";
	auto& mbrNames = value.getMemberNames();
	for (auto it = mbrNames.begin(); it != mbrNames.end(); it++)
	{
		cout << *it << "\t: ";
		if (value[*it].type() == Json::objectValue)
		{
			cout << endl;
			PrintJValue(value[*it], prefix);
		}
		else if (value[*it].type() == Json::arrayValue)
		{
			cout << endl;
			auto cnt = value[*it].size();
			for (auto i = 0; i < cnt; i++)
			{
				PrintJValue(value[*it][i], prefix);
			}
		}
		else if (value[*it].type() == Json::stringValue)
		{
			cout << value[*it].asString() << endl;
		}
		else
		{
			cout << "unknown" << endl;
		}
	}
}

void TransJValue2GBK(JValue& value)
{

}

void AboutSwap()
{
	JValue value1;
	JValue value2;

	value1["foo"] = "foo";
	value2["bar"] = "bar";

	PrintJValue(value1, "");
	PrintJValue(value2, "");

	value1.swap(value2);

	printf("swap:\n");
	PrintJValue(value1, "");
	PrintJValue(value2, "");

	value1.clear();
	value2.clear();
	value1["foo"] = "foo";
	value2["bar"] = "bar";

	value1 = value2;

	printf("operator=:\n");
	PrintJValue(value1, "");
	PrintJValue(value2, "");
}

void WhatsThis() {
	//ifstream ifs;
	//ifs.open("response.txt");

	//string strData = "{\"_id\":\"597202d328b8d7436a22e4f2\",\"roomName\":\"血染全服发起的约战\",\"startTime\":1500715800,\"deadline\":1500718200,\"password\":\"51109\",\"startMember\":[{\"nickname\":\"红颜未曾醉\",\"openid\":\"E35629495DD0C4DF5F8E03708F910FDD\",\"accountid\":\"33585611\"},{\"nickname\":\"战争丶神。。。\",\"openid\":\"BD8198CE1351C6169955D10D5E4253DD\",\"accountid\":\"87438862\"},{\"nickname\":\"孤独~~血狼\",\"openid\":\"16C62C41CC11A1588913404448294C24\",\"accountid\":\"74435171\"},{\"nickname\":\"牛黄解毒丸\",\"openid\":\"325FF7F1160CBFF10FCB30C984418EB7\",\"accountid\":\"67783223\"},{\"nickname\":\"乜z尘颸\",\"openid\":\"7D8C7F672309A669AADE84D06DB0748E\",\"accountid\":\"17343844\"}],\"acceptMember\":[{\"nickname\":\"徐啦啦啦\",\"openid\":\"3BA40BE3CFCEB924BD86C17001E00EB3\",\"accountid\":\"27558341\"},{\"nickname\":\"愁心离去\",\"openid\":\"938944DC1A6228134C77EF415205A42D\",\"accountid\":\"27761356\"},{\"nickname\":\"怒帝\",\"openid\":\"E0480C9B8CA18FC746ADF267CAB4A40F\",\"accountid\":\"88274843\"},{\"nickname\":\"掌魂_14630516940\",\"openid\":\"228984B97BC36D4B653EED26D63E857E\",\"accountid\":\"73521256\"},{\"nickname\":\"独守卍空城\",\"openid\":\"C4DA3C9DEA5F6592EE2CCF9C6C992AE4\",\"accountid\":\"77863531\"}]}";
	////string strData = "{\"room\":\"乜z尘颸\"}";
	//string strUtf8 = boost::locale::conv::between(strData, "UTF-8", "GBK");

	//string strOne = "{\"num\":\"一\\\"}";
	//string strUtf8One = boost::locale::conv::between(strOne, "UTF-8", "GBK");

	//for (int i = 0; i < strOne.size(); ++i)
	//{
	//	printf("%x", (unsigned char)strOne[i]);
	//}
	//printf("\n");

	//for (int i = 0; i < strUtf8One.size(); ++i)
	//{
	//	printf("%x", (unsigned char)strUtf8One[i]);
	//}
	//printf("\n");


	//string str1 = "乜";
	//string str1Utf8 = boost::locale::conv::between(str1, "UTF-8", "GBK");

	//for (int i = 0; i < str1.size(); ++i)
	//{
	//	printf("%x", (unsigned char)str1[i]);
	//}
	//printf("\n");

	//for (int i = 0; i < str1Utf8.size(); ++i)
	//{
	//	printf("%x", (unsigned char)str1Utf8[i]);
	//}
	//printf("\n");

	//for (string::size_type pos(0); pos != string::npos; pos += 2)
	//{
	//	pos = strOne.find('\\', pos);
	//	if (pos != string::npos)
	//	{
	//		strOne.insert(pos, 1, '\\');
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}

	//for (string::size_type pos(0); pos != string::npos; pos += 2)
	//{
	//	pos = strUtf8One.find('\\', pos);
	//	if (pos != string::npos)
	//	{
	//		strUtf8One.insert(pos, 1, '\\');
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}

	////for (string::size_type pos(0); pos != string::npos; pos += 2)
	////{
	////	pos = strData.find('\\', pos);
	////	if (pos != string::npos)
	////	{
	////		strData.insert(pos, 1, '\\');
	////	}
	////	else
	////	{
	////		break;
	////	}
	////}


	//JReader reader;
	//JValue response;

	//if (reader.parse(strUtf8, response))
	//{
	//	PrintJValue(response, "");

	//	cout << endl;

	//	string str = response.toStyledString();

	//	// 		JValue resultList = response["result_list"];
	//	// 
	//	// 		for (Json::ArrayIndex i = 0; i < resultList.size(); ++i)
	//	// 		{
	//	// 			JValue tempResult = resultList[i];
	//	// 
	//	// 			cout << "code: " << tempResult["code"].asInt() << endl;
	//	// 			cout << "message: " << tempResult["message"].asString() << endl;
	//	// 			cout << "url: " << tempResult["url"].asString() << endl;
	//	// 
	//	// 			JValue data = tempResult["data"];
	//	// 			cout << "result: " << data["result"].asString() << endl;
	//	// 			cout << "forbid_status: " << data["forbid_status"].asString() << endl;
	//	// 			cout << "confidence: " << data["confidence"].asString() << endl;
	//	// 			cout << "hot_score: " << data["hot_score"].asString() << endl;
	//	// 			cout << "normal_score: " << data["normal_score"].asString() << endl;
	//	// 			cout << "porn_score: " << data["porn_score"].asString() << endl;
	//	// 		}
	//}
	//else
	//{
	//	cout << "read error: " << reader.getFormattedErrorMessages() << endl;
	//}



	//ifs.close();
}

int main()
{
	{
		Json::Value oldRoot;
		oldRoot["hello"] = "world";
		Json::FastWriter writer;
		string strBuff = writer.write(oldRoot);

		Json::Value root;
		Json::Reader reader;
		try {
			if (!reader.parse(strBuff, root)) {
				cout << "Fail parse json msg: " << strBuff << endl;
				return 1;
			}

			cout << root["hello"].asUInt() << endl;
		}
		catch (std::exception& e) {
			cout << "ProcessMsg exception: " << e.what() << " " << strBuff << endl;
		}

		system("pause");
	}


	{
		string strRoot = "{\"content\":\"***\"}";
		Json::Value rootVal;
		Json::Reader reader;
		reader.parse(strRoot, rootVal);
		cout << rootVal["content"].type() << endl;
	}

	{
		string strRoot = "{\"num\":5000000000}";
		Json::Value rootVal;
		Json::Reader reader;
		reader.parse(strRoot, rootVal);
		cout << rootVal["num"] << endl;
	}

	{
		Json::Value root;
		root["1"] = 123;
		root["2"] = -123;
		root["3"] = 1.5f;

		cout << root["1"].type() << endl;
		cout << root["2"].type() << endl;
		cout << root["3"].type() << endl;
	}

	{
		Json::Value root;
		root["room"] = "乜z尘颸";

		Json::FastWriter writer;
		string strRoot = writer.write(root);

		Json::Value root2;
		JReader reader;
		if (reader.parse(strRoot, root2)) {
			cout << root["room"] << endl;
		}
		else {
			cout << "parse Error" << endl;
		}
	}

	AboutSwap();

	system("pause");
    return 0;
}

