// JsonCppDemo.cpp : 定义控制台应用程序的入口点。
//

#include <json/json.h>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

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
		catch (std::exception e) {
			cout << "ProcessMsg exception: " << e.what() << " " << strBuff << endl;
		}

		system("pause");
	}
	

	{
		clock_t cur = clock();

		for (int i = 0; i < 10000; ++i) {
			Json::Value root;
			root["territoryOP"]["wood"] = 1;
			root["territoryOP"]["iron"] = 1;
			root["territoryOP"]["stone"] = 1;
			root["territoryOP"]["food"] = 1;

			root["buildingOP"]["wood"] = 1;
			root["buildingOP"]["iron"] = 1;
			root["buildingOP"]["stone"] = 1;
			root["buildingOP"]["food"] = 1;

			root["allianceCityOP"]["wood"] = 1;
			root["allianceCityOP"]["iron"] = 1;
			root["allianceCityOP"]["stone"] = 1;
			root["allianceCityOP"]["food"] = 1;

			root["troopCostOP"]["wood"] = 1;
			root["troopCostOP"]["iron"] = 1;
			root["troopCostOP"]["stone"] = 1;
			root["troopCostOP"]["food"] = 1;

			Json::FastWriter writer;
			string str = writer.write(root);
		}

		cout << "time cost: " << clock() - cur << endl;
		system("pause");
	}




	{
		Json::Value root;
		Json::FastWriter writer;
		root["test"] = "test\"";
		string str = writer.write(root);

		Json::Reader reader;
		Json::Value root2;
		reader.parse(str, root2);
		string strTest = root2["test"].asString();
	}

	ifstream ifs;
	ifs.open("response.txt");

	typedef Json::Reader JReader;
	typedef Json::Value	JValue;

	//string strData = "{\"_id\":\"597202d328b8d7436a22e4f2\",\"roomName\":\"血染全服发起的约战\",\"startTime\":1500715800,\"deadline\":1500718200,\"password\":\"51109\",\"startMember\":[{\"nickname\":\"红颜未曾醉\",\"openid\":\"E35629495DD0C4DF5F8E03708F910FDD\",\"accountid\":\"33585611\"},{\"nickname\":\"战争丶神。。。\",\"openid\":\"BD8198CE1351C6169955D10D5E4253DD\",\"accountid\":\"87438862\"},{\"nickname\":\"孤独~~血狼\",\"openid\":\"16C62C41CC11A1588913404448294C24\",\"accountid\":\"74435171\"},{\"nickname\":\"牛黄解毒丸\",\"openid\":\"325FF7F1160CBFF10FCB30C984418EB7\",\"accountid\":\"67783223\"},{\"nickname\":\"乜z尘颸\",\"openid\":\"7D8C7F672309A669AADE84D06DB0748E\",\"accountid\":\"17343844\"}],\"acceptMember\":[{\"nickname\":\"徐啦啦啦\",\"openid\":\"3BA40BE3CFCEB924BD86C17001E00EB3\",\"accountid\":\"27558341\"},{\"nickname\":\"愁心离去\",\"openid\":\"938944DC1A6228134C77EF415205A42D\",\"accountid\":\"27761356\"},{\"nickname\":\"怒帝\",\"openid\":\"E0480C9B8CA18FC746ADF267CAB4A40F\",\"accountid\":\"88274843\"},{\"nickname\":\"掌魂_14630516940\",\"openid\":\"228984B97BC36D4B653EED26D63E857E\",\"accountid\":\"73521256\"},{\"nickname\":\"独守卍空城\",\"openid\":\"C4DA3C9DEA5F6592EE2CCF9C6C992AE4\",\"accountid\":\"77863531\"}]}";
	string strData = "\"{\"_id\":\"59c7466d50ab85f055569b1b\",\"roomName\":\"音速联盟发起的约战\",\"startTime\":1506295800,\"deadline\":1506298200,\"password\":\"17572\"}"; //, \"startMember\":[{\"nickname\":\"此生只为一醉\",\"openid\":\"BF7BDEFF5D97C5FF179E740EC0BEA77E\",\"accountid\":\"14551543\"},{\"nickname\":\"TK丶君莫笑\",\"openid\":\"F07C6647E8658C9E387BAEA1FF7DFC12\",\"accountid\":\"28162771\"},{\"nickname\":\"情迷欧巴\",\"openid\":\"83BC64DE7D8AD6019E3672956FC88D88\",\"accountid\":\"34717668\"},{\"nickname\":\"以戰止戰 \\笙\",\"openid\":\"918C6933EBDC5F1809573B3A9B3999EA\",\"accountid\":\"64744824\"},{\"nickname\":\"世界有你\",\"openid\":\"43F45DB08070D23E1C31364F2F420D00\",\"accountid\":\"31787234\"}],\"acceptMember\":[{\"nickname\":\"我是大号人\",\"openid\":\"76CDC2B1E45E040713C06F83F038FBC4\",\"accountid\":\"18421844\"},{\"nickname\":\"我恨我真心.\",\"openid\":\"90CAB63E8B8F50F24CCCA5118B810916\",\"accountid\":\"44473126\"},{\"nickname\":\"永久鹿晗最帅\",\"openid\":\"3FFDECFCF759FD36FBAD8B9B7EEB7BB0\",\"accountid\":\"75742462\"},{\"nickname\":\"大帅比hhd\",\"openid\":\"7AD794510433E12DB0B7005E067BB497\",\"accountid\":\"38868743\"},{\"nickname\":\"ⅱ：帅，尛韓\",\"openid\":\"4CAE9D9EF4A9966614E29EBE17C9BBE3\",\"accountid\":\"15345786\"}]}\"";

	JReader reader;
	JValue response;
	
	if (reader.parse(strData, response))
	{
		string id = response["_id"].asString();

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
	else
	{
		cout << "read error: " << reader.getFormattedErrorMessages() << endl;
	}

	ifs.close();

	system("pause");
    return 0;
}

