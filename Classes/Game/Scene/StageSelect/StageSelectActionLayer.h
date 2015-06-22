#ifndef _STAGESELECTACTIONLAYER_H_
#define _STAGESELECTACTIONLAYER_H_

#include "cocos2d.h"

class StageSelectActionLayer : public cocos2d::Layer{
public:
    /**　@brief  コンストラクタ*/
    StageSelectActionLayer();
    /**　@brief  デストラクタ*/
    ~StageSelectActionLayer();
    
    /**　@brief  初期化*/
    virtual bool init();
    
    /**　@brief  レイヤー生成*/
    static StageSelectActionLayer* create();
    
private:
    /**　@brief  戻るボタン生成*/
    void buttonBack();
    
    /**　@brief  ステージボタン生成*/
    void buttonStage();
    
    /**　@brief  ステージ選択時*/
    void stageSelected(int tag);
    
    /**　@brief  Mask描画*/
    void drawMask(cocos2d::Layer* layer);
    
    /**　@brief  ロゴ描画*/
    void drawExplain(cocos2d::Layer* layer);
    
    /**　@brief  Yesボタン生成*/
    void buttonYes(cocos2d::Layer* layer,cocos2d::Menu* menu);
    
    /**　@brief  Noボタン生成*/
    void buttonNo(cocos2d::Layer* layer,cocos2d::Menu* menu);
    
    /**　@brief  ボタン無効化有効化*/
    void isButton(bool flag);
    
    
    
};

#endif
