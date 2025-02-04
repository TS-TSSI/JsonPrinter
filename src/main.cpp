#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <stdio.h>

static const char jsonData[] = 
"{"
"   \"encoding\" : \"UTF-8\","
"   \"plug-ins\" : ["
"        \"python\","
"        \"c++\","
"        \"ruby\""
"        ],"
"   \"indent\" : { \"length\" : 3, \"use_space\": true }"
"}";

static void PrintIndentations(size_t indentLevel)
{
	for (size_t i = 0; i < indentLevel; i++)
		printf("\t");
}

static void PrintJson(const Json::Value& jsonObj, const char* name, size_t indentLevel = 0)
{
	PrintIndentations(indentLevel);
	if(name)
		printf("%s = ", name);
	switch(jsonObj.type())
	{
		case Json::ValueType::stringValue  : printf("%s" , jsonObj.asCString()); break;
		case Json::ValueType::intValue     : printf("%li", jsonObj.asInt64()); break;
		case Json::ValueType::uintValue    : printf("%lu", jsonObj.asUInt64()); break;
		case Json::ValueType::realValue    : printf("%f" , jsonObj.asFloat()); break;
		case Json::ValueType::booleanValue : printf("%s" , jsonObj.asBool() ? "true" : "false"); break;
		case Json::ValueType::objectValue  : 
		{
			printf("{\n");
			const auto names = jsonObj.getMemberNames();
			for (const auto& name: names)
				PrintJson(jsonObj[name], name.c_str(), indentLevel + 1);
			PrintIndentations(indentLevel);
			printf("}");
		} break;
		case Json::ValueType::arrayValue   : 
		{
			printf("[\n");
			size_t idx = 0;
			for (const auto& v: jsonObj)
				PrintJson(v, nullptr, indentLevel + 1);
			PrintIndentations(indentLevel);
			printf("]");
		} break;
		default: printf("[Unknown JSON type]");
	}
	printf(", \n");
}

int main(int c, const char** args)
{
	printf("Testing Conda package!\n");

	Json::Value jsonRoot = {};
	Json::Reader reader = {};

	printf("Parsing JSON\n");
	if(!reader.parse(jsonData, jsonRoot))
		throw std::runtime_error("Error parsing json :-(");

	printf("Printing JSON data:\n");
	PrintJson(jsonRoot, "RootObject");

	printf("Finished!\n");

	return 0;
}