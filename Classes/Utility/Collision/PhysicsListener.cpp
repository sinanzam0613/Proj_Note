#include "PhysicsListener.h"
#include "PhysicsCollisionManager.h"

using namespace cocos2d;

PhysicsListener* PhysicsListener::create()
{
	auto inst = new PhysicsListener();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool PhysicsListener::init()
{
	auto contactListener = EventListenerPhysicsContact::create();
	
	// 衝突時に「1度だけ」呼ばれる関数です。
	contactListener->onContactBegin = [ & ]( PhysicsContact& contact )
	{
		return PhysicsCollisionManager::getInstance().onContactBegin( contact );
	};
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( contactListener, this );
	
	return true;
}