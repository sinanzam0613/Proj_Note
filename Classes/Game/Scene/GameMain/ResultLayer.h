#ifndef _RESULTLAYER_H_
#define _RESULTLAYER_H_

#include "cocos2d.h"

class ResultLayer: public cocos2d::LayerColor
{
    
protected:
    
    ResultLayer();
    
    ~ResultLayer();
    
    bool init(cocos2d::RenderTexture* sprite);
    
public:
    
    static ResultLayer* create( cocos2d::RenderTexture* sprite );
    
private:
    using ButtonCallback = std::function< void( cocos2d::Ref* ) >;
    
    void putButton( const std::string& normal, const std::string& selected, const cocos2d::Vec2& position, ButtonCallback callback );
    
    void selectScene();

    bool mIsAnimation;
};


#endif