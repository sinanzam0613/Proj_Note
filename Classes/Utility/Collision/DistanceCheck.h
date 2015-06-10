#ifndef _DISTANCECHECK_H_
#define _DISTANCECHECK_H_

#include "cocos2d.h"

class DistanceCheck
{
public:
	
	static float check(cocos2d::Node* myObject, cocos2d::Node* targetObject);
	static float checkX(cocos2d::Node* myObject, cocos2d::Node* targetObject);
	static float checkY(cocos2d::Node* myObject, cocos2d::Node* targetObject);

private:

};

#endif