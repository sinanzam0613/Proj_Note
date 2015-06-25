#ifndef _CREDITSCENE_H_
#define _CREDITSCENE_H_

#include "cocos2d.h"

class CreditScene :public cocos2d::Layer
{
public:
    CreditScene();
    ~CreditScene();
    
    static CreditScene* create();
    
    bool init();
    
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
