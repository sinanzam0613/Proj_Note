#include "DeadAnimation.h"

using namespace cocos2d;

DeadAnimation::DeadAnimation()
{
}

DeadAnimation::~DeadAnimation()
{
}

void DeadAnimation::action(Sprite* sprite)
{
	if (sprite->getActionByTag(21))return;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto dead = JumpTo::create(2, Vec2(sprite->getPosition().x, -100), origin.y + visibleSize.height / 2 + 200, 1);
	auto rotate = RotateBy::create(2, Vec3(0, 0, 720));
	//auto repeat = RepeatForever::create(rotate);
	auto spawn = Spawn::create(dead, rotate,NULL);
	spawn->setTag(21);

	sprite->runAction(spawn);
}