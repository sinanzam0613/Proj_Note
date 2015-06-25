#include "HigeLayer.h"
#include "Game/Object/StageObject/Rest/Rest.h"
#include "Game/Object/UIObject/UiObjectLayer.h"
#include "Utility/Collision/PhysicsListener.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameDataMediator.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Object/StageObject/ObjectType.h"


using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

HigeLayer::HigeLayer() : mNumber(0){
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
	
	UserDefault* useDef = UserDefault::getInstance();
	useDef->setIntegerForKey("selectStage", mNumber);
	useDef->flush();

	player = Player::create("Helper1_1.png", ObjectType::OBJECT_PLAYER_RED, 2);
	player->setName("Player");
	player->setPosition(Vec2(0,0));
	this->addChild(player);


	auto lis = PhysicsListener::create();
	addChild(lis);

	mBlockManager = BlockManager::create();
	mBlockManager->setName("Blocks");

	this->addChild(mBlockManager);


	return true;
}

void HigeLayer::update(float deltaTime) {

	if (!getChildByName("Player")) return;

	player->update(deltaTime);

	if (player->jumpCount() >= 5 || player->getState() == DEAD){
		remove();
		mNumber  = (mNumber - 1) % -3;
		reset();
		return;
	}

	if (player->getState() == JUMP) return;
	
	player->jump(mBlockManager->getBlockPos(player->jumpCount()));
}

void HigeLayer::remove(){
	removeChildByName("Blocks");
	removeChildByName("Player");
}

void HigeLayer::reset(){

	if (mNumber == -1){
		player = Player::create("Helper2_1.png", ObjectType::OBJECT_PLAYER_BLUE, 2);
		player->setName("Player");
		player->setPosition(Vec2(0, 0));
		this->addChild(player);
	}
	else{
		player = Player::create("Helper1_1.png", ObjectType::OBJECT_PLAYER_RED, 2);
		player->setName("Player");
		player->setPosition(Vec2(0, 0));
		this->addChild(player);
	}

	UserDefault* useDef = UserDefault::getInstance();
	useDef->setIntegerForKey("selectStage", mNumber);
	useDef->flush();

	mBlockManager = BlockManager::create();
	mBlockManager->setName("Blocks");

	this->addChild(mBlockManager);
}


bool HigeLayer::onTouchBegan(Touch* touch, Event* event) {


	return true;
}

void HigeLayer::onTouchMoved(Touch* touch, Event* event) {

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