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
    
    int getSelectCount();
    
private:
    void ButtonStart();
    void ButtonStageselect();
    void ButtonEnd();
    
    int mselectCount;
};

#endif
