#ifndef REST_H
#define REST_H

#include "../StageObj.h"
#include "Utility/Collision/Collider.h"

class Rest : public StageObj,public Collider
{
public:

	static Rest* create(const std::string textureName);

	bool init(const std::string textureName);

	void update(float deltatime) override;

	void onContactBegin(cocos2d::Node* contactNode) override;

	void setPhysics(cocos2d::Size size, const float mass, bool isDynamic, bool setContact, bool setCollision);

protected:
	Rest() = default;
	~Rest() = default;
};

#endif

