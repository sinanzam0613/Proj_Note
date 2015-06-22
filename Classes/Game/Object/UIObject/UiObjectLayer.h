#ifndef _UIOBJECTLAYER_H_
#define _UIOBJECTLAYER_H_

#include "cocos2d.h"
#include "Game/Object/UIObject/SlideBar.h"
#include "Game/Object/UIObject/BackGround.h"

class UiObjectLayer : public cocos2d::Layer{
  
public:
    /**　@brief  コンストラクタ*/
    UiObjectLayer();
    /**　@brief  デストラクタ*/
    ~UiObjectLayer() = default;

    /**　@brief  初期化*/
    virtual bool init();
    
    /**　@brief  レイヤー生成*/
    CREATE_FUNC(UiObjectLayer);
    
    SlideBar* getSlideBer();
    
protected:
    /**　@brief  スライドバー用ポインタ*/
    SlideBar* mSlideBar;
    BackGround* mBG;
    
};


#endif

