#include "GoalAnimation.h"
#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Animation/SimpleParticle.h"

using namespace cocos2d;

GoalAnimation::GoalAnimation()
{
	mTimer.reset();
}

GoalAnimation::~GoalAnimation()
{
}

void GoalAnimation::action(const cocos2d::Vec2& goalPosition,Node* parentNode, Node* playerRed, Node* playerBlue)
{
	if (parentNode->getChildByName("Bell"))return;
	bellAnimation(goalPosition,parentNode);
	jumpAnimation(playerRed,playerBlue);
}

void GoalAnimation::bellAnimation(const cocos2d::Vec2& goalPosition,Node* parentNode)
{
	auto bellSprite = SpriteCreator::create("Texture/GamePlay/GameStage/Bell.png");
	Vec2 bellPosition = Vec2(goalPosition.x,goalPosition.y+200);
	bellSprite->setPosition(bellPosition);
	bellSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	bellSprite->setRotation(-45);
	auto rotate = RotateTo::create(1.5f/2, 45);
	auto rotate2 = RotateTo::create(1.5f/2, -45);
	
	auto seq = Sequence::create(rotate, CallFunc::create([this, bellSprite,parentNode](){createEffect(parentNode,bellSprite->getPosition()); }), rotate2, CallFunc::create([this, bellSprite,parentNode](){createEffect(parentNode,bellSprite->getPosition()); }), nullptr);
	auto repeat = RepeatForever::create(seq);
	bellSprite->setName("Bell");
	parentNode->addChild(bellSprite);
	repeat->setTag(1);
	bellSprite->runAction(repeat);
}

void GoalAnimation::jumpAnimation(Node* playerRed, Node* playerBlue)
{
	auto jump1P = JumpBy::create(0.5f, Vec2(), 100, 1);
	auto jump2P = JumpBy::create(0.5f, Vec2(), 100, 1);
	auto delayTime = DelayTime::create(0.5f);
	auto seq1P = Sequence::create(jump1P, delayTime, nullptr);
	auto seq2P = Sequence::create(delayTime, jump2P,nullptr);
	auto repeat1P = RepeatForever::create(seq1P);
	auto repeat2P = RepeatForever::create(seq2P);

	playerRed->runAction(repeat1P);
	playerBlue->runAction(repeat2P);
}

void GoalAnimation::createEffect(Node* parent, cocos2d::Vec2 position)
{
	auto p = SimpleParticle::create("Particle/GoalEffect.plist", position);
	parent->addChild(p);
}