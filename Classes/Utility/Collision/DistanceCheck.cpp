#include "DistanceCheck.h"

using namespace cocos2d;

float DistanceCheck::Check(cocos2d::Node* myObject, cocos2d::Node* targetObject)
{
	Vec2 position = myObject->getPosition();
	Vec2 targetPosition = targetObject->getPosition();

	float distance;
	distance = position.distance(targetPosition);
	return distance;
}