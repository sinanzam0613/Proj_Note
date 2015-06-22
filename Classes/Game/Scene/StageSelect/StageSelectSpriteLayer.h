#ifndef _STAGESELECTSPRITELAYER_H_
#define _STAGESELECTSPRITELAYER_H_

#include "cocos2d.h"

class StageSelectSpriteLayer : public cocos2d::Layer{
public:
    /**　@brief  コンストラクタ*/
    StageSelectSpriteLayer();
    /**　@brief  デストラクタ*/
    ~StageSelectSpriteLayer();
    
    /**　@brief  初期化*/
    virtual bool init();
    
    /**　@brief  レイヤー生成*/
    static StageSelectSpriteLayer* create();
    
private:
    /**　@brief  背景描画*/
    void drawBackGround();
    
    /**　@brief  ステージセレクト描画*/
    void drawLogo();
    
private:
};

#endif