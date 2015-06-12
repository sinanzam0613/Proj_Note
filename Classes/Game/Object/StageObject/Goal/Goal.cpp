﻿#include "Goal.h"

USING_NS_CC;

Goal* Goal::create(const std::string textureName){

	auto obj = new Goal();

	if (obj && obj->init(textureName)){

		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;

}

bool Goal::init(const std::string textureName){
	
	mSprite = Sprite::create( textureName );
	mSprite->setName( "Goal" );
	addChild(mSprite);
	
	auto size = cocos2d::Size( mSprite->getContentSize().width, mSprite->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( true );
	mPhysicsBody->setGravityEnable( false );
	mPhysicsBody->setCategoryBitmask( 0xFFFFFFFF );
	mPhysicsBody->setContactTestBitmask( 0xFFFFFFFF );
	mPhysicsBody->setCollisionBitmask( 0xFFFFFFFF );
	
	mSprite->setPhysicsBody( mPhysicsBody );
	this->enableCollision( mSprite->getName() );

	return true;
}

void Goal::update(float deltatime){

}

void Goal::onContactBegin( Node* contactNode )
{
	Director::getInstance()->stopAnimation();
}