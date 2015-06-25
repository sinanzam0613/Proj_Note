#ifndef STARTSTAND_H
#define STARTSTAND_H

#include "Game/Object/StageObject/StageObj.h"
#include "Utility/Collision/Collider.h"

class StartStand : public StageObj, public Collider {

public:
	static StartStand* create(const std::string textureName);

	bool init(const std::string textureName);

	void update(float deltatime) override;

	virtual void onContactBegin(cocos2d::Node* contactNode) { };

protected:
	StartStand() = default;

	~StartStand() = default;
};

#endif