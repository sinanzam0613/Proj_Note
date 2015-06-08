#ifndef _RESTENEMY_H_
#define _RESTENEMY_H_

#include "cocos2d.h"
#include "Utility/Timer/Timer.h"

class RestEnemy : public cocos2d::Node
{
public:
	virtual bool init(const cocos2d::Vec2& position);
	void jump();
	virtual void update(float deltaTime)override;
	static RestEnemy* create(const cocos2d::Vec2& position);
	virtual const cocos2d::Vec2& getPosition()const override;
protected:
	RestEnemy();
	~RestEnemy();
private:
	cocos2d::Sprite* mSprite;
	MyUtil::Timer mTimer;
	
};



#endif