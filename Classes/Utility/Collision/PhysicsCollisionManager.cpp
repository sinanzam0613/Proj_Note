#include "PhysicsCollisionManager.h"
#include "../Release/DeleteContainer.h"
#include "Collider.h"

using namespace cocos2d;

PhysicsCollisionManager::~PhysicsCollisionManager()
{
	DeleteContainer::cleanMap( mDelegateContainer );
}

void PhysicsCollisionManager::addCallback( const std::string& nodeName, CollisionDelegate* delegate )
{
	mDelegateContainer[ nodeName ] = delegate;
}

void PhysicsCollisionManager::deleteCallback( const std::string& nodeName )
{
	mDelegateContainer.erase( nodeName );
}

bool PhysicsCollisionManager::onContactBegin( PhysicsContact& contact )
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	
	if ( !nodeA || !nodeB )
	{
		// 不正なポインタを取得した場合、衝突判定は発生しません。
		return false;
	}
	
	runCallback( nodeA->getName(), nodeB );
	runCallback( nodeB->getName(), nodeA );
	return true;
}

void PhysicsCollisionManager::runCallback( const std::string& nodeName, Node* contactNode )
{
	auto findItor = mDelegateContainer.find( nodeName );
	
	if ( findItor != mDelegateContainer.end() )
	{
		mDelegateContainer[ nodeName ]->operator()( contactNode );
	}
}