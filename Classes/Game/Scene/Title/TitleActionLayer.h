#ifndef _TITLEACTIONLAYER_H_
#define _TITLEACTIONLAYER_H_

#include "cocos2d.h"

class TitleActionLayer : public cocos2d::Layer{
public:
    TitleActionLayer();
    ~TitleActionLayer() = default;
    
    virtual bool init();
    
    static TitleActionLayer* create();
    
    void CreateButton();
    
    void ButtonCreditSprite();
    
    int getSelectCount();
    void initSelectCount();
    
private:
    void ButtonStart();
    void ButtonStageselect();
    void ButtonCredit();
    
    
    int mselectCount;
};

#endif
