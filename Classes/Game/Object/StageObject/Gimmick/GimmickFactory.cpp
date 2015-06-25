#include "GimmickFactory.h"
#include "GimmickDataReader.h"
#include "FermataGimmick.h"
#include "RestGimmick.h"

using namespace cocos2d;

void GimmickFactory::createGimmick( Node* parentNode, const std::string& fileName)
{
	auto reader = GimmickDataReader::create();
	auto readData = reader->read(fileName);

	int count = 0;
	for (auto& data : readData)
	{
		if (std::strstr(data.gimmickTextureName.c_str(), "Fermata"))
		{
			auto gimmick = FermataGimmick::create("FermataGimmick" + std::to_string(count), data);
			parentNode->addChild(gimmick);
			++count;
			continue;
		}
		if (std::strstr(data.gimmickTextureName.c_str(), "Rest"))
		{
			auto gimmick = RestGimmick::create("RestGimmick" + std::to_string(count), data);
			parentNode->addChild(gimmick);
			++count;
			continue;
		}
	}
}