#ifndef _STAGESELECTSCENE_H_
#define _STAGESELECTSCENE_H_

#include "cocos2d.h"
#include "Game/Scene/StageSelect/StageSelectState.h"

class StageSelectScene :public cocos2d::Layer{
public:
    StageSelectScene();
    ~StageSelectScene();
    
    static StageSelectScene* create();
    
    bool init();
    
    StageSelectState* mState;
    
    void update(float at);
    
    /*----------------------------------------------------------------------
     |	・タッチ始め
     ----------------------------------------------------------------------*/
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    /*----------------------------------------------------------------------
     |	・タッチ終わり
     ----------------------------------------------------------------------*/
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif
