#ifndef _FERMATA_GIMMICK_H_
#define _FERMATA_GIMMICK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "GimmickData.h"

enum class ObjectType : int;

class FermataGimmick : public cocos2d::Sprite, public Collider
{

protected:

	FermataGimmick();

	~FermataGimmick();

public:

	static FermataGimmick* create(const std::string& nodeName, const GimmickData& data);

	bool init(const std::string& nodeName, const GimmickData& data);

	virtual void onContactBegin(cocos2d::Node* contactNode) override;

private:

	void initPhysics();

private:

	GimmickData	mGimmickData;
};

#endif