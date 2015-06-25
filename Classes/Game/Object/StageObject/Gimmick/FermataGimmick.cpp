#include "FermataGimmick.h"
#include "../ObjectType.h"

using namespace cocos2d;

FermataGimmick::FermataGimmick() : 
mGimmickData( GimmickData() ) {

}

FermataGimmick::~FermataGimmick() {
	this->disableCollision( this->getName() );
}

FermataGimmick* FermataGimmick::create(const std::string& nodeName, const GimmickData& data) {
	auto inst = new FermataGimmick();

	if (inst && inst->init(nodeName, data))
	{
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

bool FermataGimmick::init( const std::string& nodeName, const GimmickData& data ) {
	if ( !Sprite::initWithFile( data.gimmickTextureName + ".png" ) ) {
		return false;
	}


	mGimmickData = data;

	this->setName( nodeName );
	this->enableCollision( nodeName );
	this->setPosition(Vec2(mGimmickData.positionX, mGimmickData.positionY) );
	this->setRotation(270);

	ccBezierConfig move1;
	move1.controlPoint_1 = Vec2(0, 0);
	move1.controlPoint_2 = Vec2(0, 100);
	move1.endPosition = Vec2(100, 100);
	ActionInterval* move1action = BezierBy::create(2.0f, move1);

	ccBezierConfig move2;
	move2.controlPoint_1 = Vec2(0, 0);
	move2.controlPoint_2 = Vec2(100, 0);
	move2.endPosition = Vec2(100, -100);
	ActionInterval* move2action = BezierBy::create(2.0f, move2);

	ccBezierConfig move3;
	move3.controlPoint_1 = Vec2(0, 0);
	move3.controlPoint_2 = Vec2(0, -100);
	move3.endPosition = Vec2(-100, -100);
	ActionInterval* move3action = BezierBy::create(2.0f, move3);

	ccBezierConfig move4;
	move4.controlPoint_1 = Vec2(0, 0);
	move4.controlPoint_2 = Vec2(-100, 0);
	move4.endPosition = Vec2(-100, 100);
	ActionInterval* move4action = BezierBy::create(2.0f, move4);

	Sequence* seq = Sequence::create(move1action, move2action, move3action, move4action, NULL);

	auto rotate = RotateBy::create(8,360);

	Spawn* spawn = Spawn::create(seq, rotate, NULL);

	RepeatForever* reForever = RepeatForever::create(spawn);


	this->runAction(reForever);

	initPhysics();

	return true;
}


void FermataGimmick::onContactBegin(Node* contactNode)
{
}

void FermataGimmick::initPhysics()
{
	auto size = cocos2d::Size(this->getContentSize().width - 20, 30);

	mPhysicsBody = PhysicsBody::createBox(size, mPhysicsMaterial);
	mPhysicsBody->setDynamic(true);
	mPhysicsBody->setGravityEnable(false);
	mPhysicsBody->setCategoryBitmask(converter::toInt(ObjectType::OBJECT_GIMMICK_FERMATA));
	mPhysicsBody->setContactTestBitmask(converter::toInt(ObjectType::OBJECT_ALL));
	mPhysicsBody->setCollisionBitmask(converter::toInt(ObjectType::OBJECT_ALL));
	this->setPhysicsBody(mPhysicsBody);
}