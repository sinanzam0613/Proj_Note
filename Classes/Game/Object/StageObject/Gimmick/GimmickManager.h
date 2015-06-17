#ifndef GIMMICKMANAGER_H
#define GIMMICKMANAGER_H

#include "cocos2d.h"
#include <vector>
#include <string>

struct Gimmick;

class GimmickManager : public cocos2d::Node {
protected:
	GimmickManager() = default;
	~GimmickManager() = default;
public:
	static GimmickManager* create();

	virtual bool init() override;

	//cocos2d::Vec2 getGimmickpos(int value) const;
private:
	cocos2d::Node* mGimmickNode;
	typedef std::vector<Gimmick*> GimmickList;

	GimmickList mGimmickList;
};

#endif