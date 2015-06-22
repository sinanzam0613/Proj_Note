#ifndef _TITLEACTIONLAYER_H_
#define _TITLEACTIONLAYER_H_

#include "cocos2d.h"

class TitleActionLayer : public cocos2d::Layer{
public:
    /**　@brief  コンストラクタ*/
    TitleActionLayer();
    /**　@brief  デストラクタ*/
    ~TitleActionLayer() = default;
    
    /**　@brief  初期化*/
    virtual bool init();
    
    /**　@brief  レイヤー生成*/
    static TitleActionLayer* create();
    
    /** ボタン生成*/
    void CreateButton();
    
    /** 状態確認*/
    int getSelectCount();
    
private:
    /**　@brief  スタートボタン*/
    void ButtonStart();
    /**　@brief  ステージセレクトボタン*/
    void ButtonStageselect();
    /**　@brief  終了ボタン*/
    void ButtonEnd();
    
    //選ばれた状態
    int mselectCount;
};

#endif
