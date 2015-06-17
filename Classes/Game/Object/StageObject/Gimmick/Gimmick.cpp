#include "Gimmick.h"
#include "GimmickType.h"

using namespace cocos2d;

Gimmick::Gimmick() : mGimmickData( GimmickData() ) {

}

Gimmick::~Gimmick() {
	this->disableCollision( this->getName() );
}

Gimmick* Gimmick::create( const std::string& nodeName, const GimmickData& data ) {
	auto inst = new Gimmick();

	if ( inst && inst->init( nodeName, data ) ) {
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool Gimmick::init( const std::string& nodeName, const GimmickData& data ) {
	if ( !Sprite::initWithFile( data.textureName ) ) {
		return false;
	}

	mGimmickData = data;

	this->setName( nodeName );
	this->enableCollision( nodeName );
	this->setPosition( Vec2( mGimmickData.positionX, mGimmickData.positionY ) );

	initPhysics();

	return true;
}

void Gimmick::onContactBegin( Node* contactNode) {
}

void Gimmick::initPhysics() {
}