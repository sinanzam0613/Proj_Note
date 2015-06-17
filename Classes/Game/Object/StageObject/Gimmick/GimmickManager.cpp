#include "GimmickManager.h"
#include "Gimmick.h"
#include "GimmickDataReader.h"

using namespace cocos2d;

GimmickManager* GimmickManager::create() {
	auto inst = new GimmickManager();

	if ( inst && inst->init() ) {
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool GimmickManager::init() {
	if (!Node::init() ) {
		return false;
	}

	mGimmickNode = Node::create();
	this->addChild( mGimmickNode );

	auto reader = GimmickDataReader::create();
	auto readData = reader->read( "Plist/GimmickData.plist" );

	int count = 0;
	for ( auto& data : readData ) {
		auto gimmick = Gimmick::create( "Gimmick" + std::to_string( count ), data );
		mGimmickNode->addChild( gimmick );
		++count;
	}

	return true;
}