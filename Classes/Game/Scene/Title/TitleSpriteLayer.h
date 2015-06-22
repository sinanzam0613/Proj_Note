#ifndef _TITLESPRITELAYER_H_
#define _TITLESPRITELAYER_H_

#include "cocos2d.h"

class TitleSpriteLayer : public cocos2d::Layer{
public:

    TitleSpriteLayer();
    ~TitleSpriteLayer() = default;
    
    virtual bool init();
    
    static TitleSpriteLayer* create();
    
    void nextDraw();
    
private:
    
    void fastDraw();
   
    void drawBackGraund();
    
    void drawTitleLogo();
    
    void drawTouchLogo();
    
    void drawStart();
    
    void drawStageSelect();
    
    void drawEnd();
    
    
};
#endif
