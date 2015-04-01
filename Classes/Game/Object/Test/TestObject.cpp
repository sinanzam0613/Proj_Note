#include "TestObject.h"
#include "Utility/CocosAssistant/SpriteCreator.h"

using namespace cocos2d;

TestObject::TestObject()
{
}

TestObject::~TestObject()
{
}

bool TestObject::init()
{
	if (!Node::init())
	{
		return false;
	}
	mSprite = SpriteCreator::create("GamePlay/Character/Test.png");
	this->addChild(mSprite);
	return true;
}

void TestObject::update(float deltaTime)
{

}

