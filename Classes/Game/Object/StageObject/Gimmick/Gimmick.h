#ifndef GIMMICK_H
#define GIMMICK_H

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "GimmickData.h"

class Gimmick : public cocos2d::Sprite, public Collider {
protected:
	Gimmick();
	~Gimmick();
public:
	static Gimmick* create( const std::string& nodeName, const GimmickData& data );
	bool init(const std::string& nadeName, const GimmickData& data );
	virtual void onContactBegin( cocos2d::Node* contactNode ) override;
private:
	void initPhysics();
private:
	GimmickData mGimmickData;
};

#endif