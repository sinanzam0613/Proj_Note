#ifndef _GIMMICK_MANAGER_H_
#define _GIMMICK_MANAGER_H_

#include "cocos2d.h"
#include <vector>
#include <string>

class Gimmick;

class GimmickManager : public cocos2d::Node{
protected:
	GimmickManager() = default;
	~GimmickManager() = default;
public:
	static GimmickManager* create();
	virtual bool init() override;
private:
	cocos2d::Node* mGimmickNode;
	typedef std::vector<Gimmick*> GimmickList;

	GimmickList mGimmickList;

};

#endif