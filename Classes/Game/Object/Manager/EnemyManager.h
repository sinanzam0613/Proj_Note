#ifndef _ENEMYMANAGER_H_
#define _ENEMYMANAGER_H_

#include "cocos2d.h"

class RestEnemy;

class EnemyManager : public cocos2d::Node
{
public:
	virtual bool init()override;
	virtual void update(float deltaTime)override;
	void add(const cocos2d::Vec2& position);
	static EnemyManager* create();

protected:
	EnemyManager();
	~EnemyManager();
private:
	using EnemyContainer = std::vector < RestEnemy* > ;
	EnemyContainer mContainer;
};



#endif