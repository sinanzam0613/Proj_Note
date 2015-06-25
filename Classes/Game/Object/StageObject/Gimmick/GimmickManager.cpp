#include "GimmickManager.h"
#include "GimmickDataReader.h"
#include "GimmickFactory.h"

using namespace cocos2d;

GimmickManager* GimmickManager::create()
{
	auto inst = new GimmickManager();

	if (inst && inst->init())
	{
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

bool GimmickManager::init()
{
	if (!Node::init())
	{
		return false;
	}

	mGimmickNode = Node::create();
	this->addChild(mGimmickNode);

	auto fac = std::make_shared< GimmickFactory >();
	fac->createGimmick(mGimmickNode, "Plist/GimmickData.plist");

	return true;
}