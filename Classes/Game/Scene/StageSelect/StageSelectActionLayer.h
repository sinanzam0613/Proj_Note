#ifndef _STAGESELECTACTIONLAYER_H_
#define _STAGESELECTACTIONLAYER_H_

#include "cocos2d.h"

class StageSelectActionLayer : public cocos2d::Layer{
public:
    StageSelectActionLayer();
    ~StageSelectActionLayer() = default;
    
    virtual bool init();
    
    static StageSelectActionLayer* create();
    
private:
    void buttonBack();
    
    void buttonStage();
    
    void stageSelected(int tag);
    
    void drawMask(cocos2d::Layer* layer);
    
    void drawExplain(cocos2d::Layer* layer);
    
    void buttonYes(cocos2d::Layer* layer,cocos2d::Menu* menu,int tag);
    
    void buttonNo(cocos2d::Layer* layer,cocos2d::Menu* menu);
    
    void isButton(bool flag);
};
#endif