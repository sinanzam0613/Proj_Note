#ifndef _PAUSE_LAYER_H_
#define _PAUSE_LAYER_H_

#include "cocos2d.h"

class PauseLayer : public cocos2d::LayerColor
{

protected:
	
	PauseLayer();
	
	~PauseLayer();
	
	bool init( const cocos2d::Vec2& position );
	
public:
	
	static PauseLayer* create( const cocos2d::Vec2& position );
	
private:
	
	using ButtonCallback = std::function< void( cocos2d::Ref* ) >;
	
	void putButton( const std::string& normal, const std::string& selected, const cocos2d::Vec2& position, ButtonCallback callback );
};

#endif