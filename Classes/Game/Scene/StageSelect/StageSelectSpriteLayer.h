#ifndef _STAGESELECTSPRITELAYER_H_
#define _STAGESELECTSPRITELAYER_H_

#include "cocos2d.h"

class StageSelectSpriteLayer : public cocos2d::Layer{
public:

	StageSelectSpriteLayer();
    ~StageSelectSpriteLayer()= default;
    
    virtual bool init();
    
    static StageSelectSpriteLayer* create();
    
private:
    void drawBackGround();
    
    void drawLogo();
    
};

#endif