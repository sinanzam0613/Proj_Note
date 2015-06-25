#include "GimmickDataReader.h"
#include "GimmickData.h"
#include "Utility/FileIO/PlistReader.h"

GimmickDataReader* GimmickDataReader::create()
{
	auto inst = new GimmickDataReader();

	if (inst && inst->init())
	{
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

GimmickDataReader::GimmickReadData GimmickDataReader::read(const std::string& fileName)
{
	PlistReader	reader;
	GimmickReadData	readData;

	auto valueMap = reader.read(fileName);

	for (auto& map : valueMap)
	{
		GimmickData data;
		data.gimmickTextureName = map.at("gimmickTextureName").asString();
		data.positionX = map.at("positionX").asInt();
		data.positionY = map.at("positionY").asInt();
		readData.push_back(data);
	}

	return readData;
}