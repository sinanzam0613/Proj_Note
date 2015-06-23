#include "BackGround.h"
#include "Utility/Action/Follow/CustomFollow.h"
#include "Game/Scene/GameMain/Tags.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
/--------------------------*/
BackGround::BackGround(){
    
}

/*--------------------------/
 クリエイト
/--------------------------*/
BackGround* BackGround::create(cocos2d::Layer* layer){
    auto inst = new BackGround();
   
    if( inst &&  inst->init(layer)){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE(inst);
    return nullptr;
}

int BackGround::init(cocos2d::Layer* layer){

	auto size = Director::getInstance()->getWinSize();

	BackGraundCreate(layer, Vec2(0, 0), FLONTBG);
	BackGraundCreate(layer, Vec2(1800, 0), BACKBG);

	return true;
}

/*--------------------------/
 背景生成
/--------------------------*/
void BackGround::BackGraundCreate(Layer* layer,const cocos2d::Vec2& pos, const Tags tag){
    
    auto flontBG = Sprite::create("Texture/GamePlay/GameStage/BackGround.png");
	flontBG->setAnchorPoint(Vec2(0, 0));
	flontBG->setTag(tag);
	flontBG->setPosition(pos);
    
	layer->addChild(flontBG, -1);

	if (tag == BACKBG){
		flontBG->setFlipX(true);
	}

}

void BackGround::update(float dt, cocos2d::Layer* layer){
	resetPos(layer, FLONTBG);
	resetPos(layer, BACKBG);
}

void BackGround::resetPos(cocos2d::Layer* layer, const Tags tag){
	auto sprite = (Sprite*)layer->getChildByTag(tag);
	auto follow = (CustomAction::CustomFollow*)layer->getActionByTag(FOLLOW);

	/*if (sprite->getPosition().x + Director::getInstance()->getWinSize().width < layer->getPositionX() ){
		sprite->setPosition(Vec2(sprite->getPositionX() + Director::getInstance()->getWinSize().width * 2,
			sprite->getPositionY()));
	}*/

	int layerPos = layer->getPositionX() * -1;
	int WinsizeX = Director::getInstance()->getWinSize().width;

	if (layerPos == 0) return;

	if (layerPos > sprite->getPositionX() + 1800){
		sprite->setPosition(Vec2(sprite->getPositionX() + 1800 * 2,
			sprite->getPositionY()));
	}
}