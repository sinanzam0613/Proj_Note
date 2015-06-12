#ifndef GOAL_H
#define GOAL_H

#include "Game/Object/StageObject/StageObj.h"
#include "Utility/Collision/Collider.h"

class Goal : public StageObj, public Collider {

public:
	static Goal* create(const std::string textureName);

	bool init(const std::string textureName);

	void update(float deltatime) override;
	
	virtual void onContactBegin( cocos2d::Node* contactNode );

protected:
	Goal() = default;

	~Goal() = default;
};

#endif