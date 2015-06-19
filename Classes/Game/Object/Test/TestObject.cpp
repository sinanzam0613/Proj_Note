#include "TestObject.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Game/Object/Character/Player/DeadAnimation.h"
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
	mSprite = SpriteCreator::create("Texture/GamePlay/Character/Test.png");
	this->addChild(mSprite);

	
	return true;
}

void TestObject::update(float deltaTime)
{

}

void TestObject::setPosition(const Vec2& position)
{
	mSprite->setPosition(position);
}


void TestObject::dead()
{
	DeadAnimation anime;
	anime.action(mSprite);
}
