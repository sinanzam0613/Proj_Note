#include "HigeLayer.h"
#include "Game/Object/StageObject/Rest/Rest.h"
#include "Game/Object/UIObject/UiObjectLayer.h"
#include "Utility/Collision/PhysicsListener.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameDataMediator.h"


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

	auto mediator = GameDataMediator::create();
	mediator->setTag(12345);
	addChild(mediator);

	mediator->setFollow(this);

	auto lis = PhysicsListener::create();
	addChild(lis);

   	uiLayer = UiObjectLayer::create();
    
    addChild(uiLayer);
        
	return true;
}

void HigeLayer::update(float deltaTime) {
    

    mSlideBar->setPosition(Vec2(getPosition().x,getPosition().y),uiLayer);
	
	auto media = (GameDataMediator*)getChildByTag(12345);

	media->update(deltaTime, uiLayer);
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