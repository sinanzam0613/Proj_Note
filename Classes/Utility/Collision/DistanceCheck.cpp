#include "DistanceCheck.h"


using namespace cocos2d;

float DistanceCheck::check(cocos2d::Node* myObject, cocos2d::Node* targetObject)
{
	Vec2 position = myObject->getPosition();
	Vec2 targetPosition = targetObject->getPosition();

	float distance;
	distance = position.distance(targetPosition);
	return distance;
}

float DistanceCheck::checkX(cocos2d::Node* myObject, cocos2d::Node* targetObject)
{
	Vec2 position = myObject->getPosition();
	Vec2 targetPosition = targetObject->getPosition();

	float distanceX = position.x - targetPosition.x;
	float distance;
	distance = abs(distanceX);
	return distance;
}

float DistanceCheck::checkY(cocos2d::Node* myObject, cocos2d::Node* targetObject)
{
	Vec2 position = myObject->getPosition();
	Vec2 targetPosition = targetObject->getPosition();

	float distanceY = position.y - targetPosition.y;
	float distance;
	distance = abs(distanceY);
	return distance;
}