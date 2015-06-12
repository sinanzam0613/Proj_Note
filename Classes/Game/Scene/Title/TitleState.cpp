#include "TitleState.h"
#include "cocos-ext.h"
#include "Utility/Audio/ADX2Player.h"

USING_NS_CC;
using namespace cocos2d::extension;

TitleState* TitleState::create(Layer* layer){

	auto obj = new TitleState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

/*-----------------------------------------------------
 -------初期化
 -----------------------------------------------------*/
bool TitleState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;
	mTestTouch = false;
    
    
    //背景生成------------------------------------------------------------------------
    auto mBG = Sprite::create("Texture/GamePlay/GameScene/Title/Title_BG.png");
    mBG->setPosition(Vec2(0,0));
    mBG->setAnchorPoint(Vec2(0,0));
    layer->addChild(mBG);
    
    //タッチ-----------------------------------------------------------------------
    auto mLogo = Sprite::create("Texture/GamePlay/GameScene/Title/Title_Touch.png");
    mLogo->setScale(0.8f, 0.9f);
    mLogo->setPosition(Vec2(300,100));
    mLogo->setAnchorPoint(Vec2(0,0));
    mLogo->setOpacity(0);
    layer->addChild(mLogo);
    
    auto mFadeIn = FadeIn::create(3);
    auto mFadeOut = FadeOut::create(3);
    auto sequence = Sequence::create(mFadeIn,mFadeOut,NULL);
    auto repeatForever = RepeatForever::create(sequence);
    repeatForever -> setTag(0);
    mLogo->runAction(repeatForever);
    
    
    //ロゴ----------------------------------------------------------------------------
    auto mTouch = Sprite::create("Texture/GamePlay/GameScene/Title/Title_Logo.png");
    mTouch->setScale(0.8f, 0.9f);
    mTouch->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,
                             Director::getInstance()->getVisibleSize().height/2 + 100));
    mTouch->setAnchorPoint(Vec2(0.5f,0.5f));
    layer->addChild(mTouch);
    
    
    auto mScaleUp = ScaleTo::create(1, 1.1f);
    auto mScaleDown = ScaleTo::create(1, 0.9f);
    auto sequence2 = Sequence::create(mScaleUp,mScaleDown,NULL);
    auto repeatForever2 = RepeatForever::create(sequence2);
    repeatForever2->setTag(1);
    mTouch->runAction(repeatForever2);
    
	return true;
}

/*-----------------------------------------------------
  -------更新
 -----------------------------------------------------*/
void TitleState::update(float at){(this->*updateFunc[mSceneState])(at);}


/*-----------------------------------------------------
 -------フェードイン
 -----------------------------------------------------*/
void TitleState::fadeIn(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = MAIN;
	}
}

/*-----------------------------------------------------
 -------シーンメイン
 -----------------------------------------------------*/
void TitleState::sceneMain(float at){(this->*mainFunc[mUpdateState])(at);}

/*-----------------------------------------------------
 -------フェードアウト
 -----------------------------------------------------*/
void TitleState::fadeOut(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = FADEIN;
	}
    
    
}

/*-----------------------------------------------------
 -------シーンメイン（スタート）
 -----------------------------------------------------*/
void TitleState::mainStart(float at){mUpdateState = UPDATELOOP;}

/*-----------------------------------------------------
 -------シーンメイン（ループ）
 -----------------------------------------------------*/
void TitleState::mainLoop(float at){
	if (mTestTouch){
		mTestTouch = false;
		mUpdateState = UPDATEEND;
	}
    
    
}
/*-----------------------------------------------------
 -------シーンメイン（エンド）
 -----------------------------------------------------*/
void TitleState::mainEnd(float at){
	mUpdateState =UPDATESTART;
	mSceneState = FADEOUT;
}

bool TitleState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mTestTouch = true;
    
	return true;
}


void TitleState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
