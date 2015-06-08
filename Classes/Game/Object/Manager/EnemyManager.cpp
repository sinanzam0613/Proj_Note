#include "EnemyManager.h"
#include "../Character/Enemy/RestEnemy.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
	for (auto enemy : mContainer)
	{
		CC_SAFE_RELEASE(enemy);
	}
}

bool EnemyManager::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}

void EnemyManager::update(float deltaTime)
{
	for (auto enemy : mContainer)
	{
		enemy->update(deltaTime);
	}
}

void EnemyManager::add(const cocos2d::Vec2& position)
{
	RestEnemy* enemy = RestEnemy::create(position);
	mContainer.push_back(enemy);
	addChild(enemy);
}

EnemyManager* EnemyManager::create()
{
	auto instance = new EnemyManager();
	if (instance&&instance->init())
	{
		return instance;
	}
	CC_SAFE_DELETE(instance);
	return nullptr;
}