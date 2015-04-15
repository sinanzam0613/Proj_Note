#include "Rest.h"

USING_NS_CC;

Rest* Rest::create(const std::string textureName){

	auto obj = new Rest();

	if (obj && obj->init(textureName)){

		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;

}

bool Rest::init(const std::string textureName){
	mSprite = SpriteCreator::create(textureName);
	mSprite->retain();

	setPhysics(mSprite->getContentSize(), 1.0f, false, true, true);

	addChild(mSprite);

	return true;
}

void Rest::update(float deltatime){

}


void Rest::setPhysics(cocos2d::Size size, const float mass, bool isDynamic, bool setContact, bool setCollision){
	auto material = PHYSICSBODY_MATERIAL_DEFAULT;
	
	mPhysicsBody = PhysicsBody::createBox(size,material);
	mPhysicsBody->setMass(mass);
	mPhysicsBody->setDynamic(isDynamic);
	mPhysicsBody->setContactTestBitmask(setContact);
	mPhysicsBody->setCollisionBitmask(setCollision);
	mPhysicsBody->setGravityEnable(false);

	mSprite->setPhysicsBody(mPhysicsBody);

	mSprite->setName("Rest");
	Node::setName("Rest");
	enableCollision("Rest");
}

void Rest::onContactBegin(cocos2d::Node* contactNode){

}