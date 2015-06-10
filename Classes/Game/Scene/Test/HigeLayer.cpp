#include "HigeLayer.h"
#include "Game/Object/Manager/NoteManager.h"
#include "Utility/Audio/ADX2Player.h"
#include "Game/Object/StageObject/Note/Note.h"
#include "Utility/Audio/Define/PianoSample.h"
#include "Game/Object/StageObject/Rest/Rest.h"
#include "Game/Object/StageObject/Goal/Goal.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Object/StageObject/Block/Block.h"
#include "Game/Object/StageObject/Block/BlockManager.h"
#include "Utility/Collision/PhysicsListener.h"
#include <math.h>
#include <random>

using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

HigeLayer::HigeLayer(){
	srand((unsigned)time(NULL));
}

HigeLayer::~HigeLayer() {
}

bool HigeLayer::init() {
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255), 1280, 720)) return false;

	this->schedule(schedule_selector(HigeLayer::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HigeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HigeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HigeLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	auto back = Sprite::create("Texture/GamePlay/GameStage/BackGround1.png");
	back->setAnchorPoint(Vec2(0,0));
	back->setPosition(Vec2(0, 5));
	addChild(back);

	auto rest = Rest::create("Texture/GamePlay/Character/RestEnemy.png");
	rest->setPosition(Vec2(100, 50));
	addChild(rest);

	auto goal = Goal::create("Texture/GamePlay/GameStage/GoalBlockAfter.png");
	goal->setPosition(Vec2(1250, 500));
	addChild(goal);

	auto sprite = Player::create("Helper1.png",ObjectType::OBJECT_PLAYER_BLUE);
	sprite->setPosition(Vec2(100, 230));
	sprite->setTag(555);
	addChild(sprite);

	auto sprite2 = Player::create("Helper1.png", ObjectType::OBJECT_PLAYER_RED);
	sprite2->setPosition(Vec2(100, 230));
	sprite2->setTag(55);
	addChild(sprite2);

	auto lis = PhysicsListener::create();
	addChild(lis);

	auto b = BlockManager::create();
	b->setTag(123);
	this->addChild(b);

	mSlideBar->slideBarCreate("p1",
		this,
		"Texture/GamePlay/Controller/sliderTrack.png",
		"Texture/GamePlay/Controller/sliderTrack.png",
		"Texture/GamePlay/Controller/sliderThumb_Red.png",
		"Texture/GamePlay/Controller/switch-thumb_Red.png",
		Vec2(300, 100));

	mSlideBar2->slideBarCreate("p2",
		this,
		"Texture/GamePlay/Controller/sliderTrack.png",
		"Texture/GamePlay/Controller/sliderTrack.png",
		"Texture/GamePlay/Controller/sliderThumb_Red.png",
		"Texture/GamePlay/Controller/switch-thumb_Red.png",
		Vec2(900, 100));

    
    /*
    mSlideBar->slideBarCreate("p2",
                              this,
                              "Texture/GamePlay/Controller/sliderTrack.png",
                              "Texture/GamePlay/Controller/sliderTrack.png",
                              "Texture/GamePlay/Controller/sliderThumb_Blue.png",
                              "Texture/GamePlay/Controller/switch-thumb_Blue.png",
                              Vec2(300, 100));
     */

	//runAction(Follow::create(sprite));


	return true;
}

void HigeLayer::update(float deltaTime) {
	
	//プレイヤー２
	{
		auto sprite2 = (Player*)getChildByTag(55);

		sprite2->update(deltaTime);

		if (mSlideBar2->isTouch("p2", this)){
			sprite2->changeJumpTime(mSlideBar2->getValue("p1", this));
		}

		if (!sprite2->isJump()){

			auto blockManager = (BlockManager*)getChildByTag(123);

			sprite2->jump(blockManager->getBlockPos(sprite2->jumpCount()));
		}
	}


	//プレイヤー1
	{
		auto sprite = (Player*)getChildByTag(555);

		sprite->update(deltaTime);

		if (mSlideBar->isTouch("p1", this)){
			sprite->changeJumpTime(mSlideBar->getValue("p1", this));
		}

		if (sprite->isJump()) return;

		auto blockManager = (BlockManager*)getChildByTag(123);

		sprite->jump(blockManager->getBlockPos(sprite->jumpCount()));

		CCLOG("%f", mSlideBar->getValue("p1", this));
		CCLOG("1");
	}
}


bool HigeLayer::onTouchBegan(Touch* touch, Event* event) {
	auto pos = this->convertTouchToNodeSpace(touch);

	auto blockManager = (BlockManager*)getChildByTag(123);
	blockManager->onTouchBegan(pos);

	return true;
}

void HigeLayer::onTouchMoved(Touch* touch, Event* event) {
	auto sprite = (Player*)getChildByTag(555);
}

void HigeLayer::onTouchEnded(Touch* touch, Event* event) {

}

HigeLayer* HigeLayer::create() {
	auto instance = new HigeLayer();

	if (instance && instance->init()) {
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}