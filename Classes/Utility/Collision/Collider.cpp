#include "Collider.h"
#include "../Delegate/Delegate.h"
#include "PhysicsCollisionManager.h"

using namespace cocos2d;

Collider::Collider()
	: mPhysicsBody( nullptr )
	, mPhysicsMaterial( PhysicsMaterial() )
{
	
}

void Collider::enableCollision( const std::string& nodeName )
{
	auto delegate = new Delegate< Collider, Node* >();
	delegate->setFunc( this, &Collider::onContactBegin );
	PhysicsCollisionManager::getInstance().addCallback( nodeName, delegate );
}

void Collider::disableCollision( const std::string& nodeName )
{
	PhysicsCollisionManager::getInstance().deleteCallback( nodeName );
}