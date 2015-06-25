#include "TitleState.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/StageSelect/StageSelectScene.h"
#include "Game/Scene/GameMain/GameMainScene.h"
#include "Game/Scene/Credit/CreditScene.h"

USING_NS_CC;

TitleState::TitleState():
mTitleState(true),
mTitleActionLayer(nullptr),
mTitleSpriteLayer(nullptr)
{
    auto userDef = UserDefault::getInstance();
    if(userDef->getIntegerForKey("clearStage") <= 2){
        userDef->setIntegerForKey("clearStage", 2);
    }
}


/*-----------------------------------------------------
 -------デストラクタ
 -----------------------------------------------------*/
TitleState::~TitleState()
{}

/*-----------------------------------------------------
 -------シーン作成
 -----------------------------------------------------*/
TitleState* TitleState::create(Layer* layer)
{

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
    
    mTitleSpriteLayer = TitleSpriteLayer::create();
    layer->addChild(mTitleSpriteLayer);
    mTitleActionLayer = TitleActionLayer::create();
    layer->addChild(mTitleActionLayer);
    
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
    //シーン遷移
    sceneChange();
}

/*-----------------------------------------------------
 -------シーン遷移
 -----------------------------------------------------*/
void TitleState::sceneChange(){
    
    int mState = mTitleActionLayer->getSelectCount();
    
    switch (mState)
    {
        case 0:
            break;
         
        //初めから//////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1:
        {
            //初期化
            mTitleActionLayer->initSelectCount();
            
            UserDefault* useDef  = UserDefault::getInstance();
            useDef->setIntegerForKey("selectStage",1);
            useDef->flush();
            
            //ゲーム生成
            auto nextScene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0,-9.8f));
            auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
            auto dir = Director::getInstance();
            dir->replaceScene(scene);
            break;
        }
        
        //ステージセレクト////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
        {
            //初期化
            mTitleActionLayer->initSelectCount();
            //ステージセレクト
            auto nextScene = SceneCreator::createScene(StageSelectScene::create());
            auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
            auto dir = Director::getInstance();
            dir->replaceScene(scene);
            break;
        }
            
        //クレジット////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 3:
        {
            mTitleActionLayer->initSelectCount();
            
            //クレジット
            auto nextScene = SceneCreator::createScene(CreditScene::create());
            auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
            auto dir = Director::getInstance();
            dir->replaceScene(scene);
            break;
        }
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
    
    //状態管理
    if(!mTitleState) return false;
    
    //アクションの停止
    auto touchLogo = mTitleSpriteLayer->getChildByName("TouchLogo");
    touchLogo->stopAllActions();
    touchLogo->setOpacity(0);
    
    mTitleActionLayer->CreateButton();
    
    mTitleState = false;

	return true;
}


void TitleState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
