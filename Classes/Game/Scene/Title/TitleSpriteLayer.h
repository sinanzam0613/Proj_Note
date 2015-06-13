#ifndef _TITLESPRITELAYER_H_
#define _TITLESPRITELAYER_H_

#include "cocos2d.h"

class TitleSpriteLayer : public cocos2d::Layer{
public:
    /**　@brief  コンストラクタ*/
    TitleSpriteLayer();
    /**　@brief  デストラクタ*/
    ~TitleSpriteLayer() = default;
    
    /**　@brief  初期化*/
    virtual bool init();
    
    /**　@brief  レイヤー生成*/
    CREATE_FUNC(TitleSpriteLayer);
    
    /**　@brief  時点描画*/
    void nextDraw();
    
private:
    
    /**　@brief  初期描画*/
    void fastDraw();
   
    
    
    /**　@brief  背景描画*/
    void drawBackGraund();
    
    /**　@brief  タイトルロゴ描画*/
    void drawTitleLogo();
    
    /**　@brief  タッチロゴ描画*/
    void drawTouchLogo();
    
    /**　@brief  初めから描画*/
    void drawStart();
    
    /**　@brief  ステージセレクト描画*/
    void drawStageSelect();
    
    /**　@brief  終了描画*/
    void drawEnd();
    
    
};
#endif
