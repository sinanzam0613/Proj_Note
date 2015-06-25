#include "BlockManager.h"
#include "BlockDataReader.h"
#include "BlockFactory.h"
#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

BlockManager* BlockManager::create()
{
	auto inst = new BlockManager();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool BlockManager::init()
{
	if ( !Node::init() )
	{
		return false;
	}

	mBlockNode = Node::create();
	this->addChild( mBlockNode );
    
    auto userDef = UserDefault::getInstance();
    
    int  selectStage  = userDef -> getIntegerForKey("selectStage");
    std::string stage = "Plist/Stage" + std::to_string(selectStage) + ".plist";

    
	auto player = ADX2Player::create("Sound/ADX2/WorkUnit_Effect/CueSheet_1.acb");
	player->setName("Player");
	addChild(player);

	auto fac = std::make_shared< BlockFactory >();
	fac->createBlock( mBlockNode, stage);

	return true;
}

void BlockManager::onTouchBegan(cocos2d::Point pos) {
}

void BlockManager::onTouchMove(cocos2d::Point pos) {

}

void BlockManager::onTouchEnd(cocos2d::Point pos) {

}

Vec2 BlockManager::getGoalPos(){
    return mBlockNode->getChildren().back()->getPosition();
}

Vec2 BlockManager::getBlockPos(int value) const {
	if (value >= mBlockNode->getChildrenCount()) {
		return mBlockNode->getChildren().back()->getPosition();
	}

	return mBlockNode->getChildren().at(value)->getPosition();
}