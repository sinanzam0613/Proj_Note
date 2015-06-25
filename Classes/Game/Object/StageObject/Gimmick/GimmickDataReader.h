#ifndef _GIMMICK_DATA_READER_H_
#define _GIMMICK_DATA_READER_H_

#include "cocos2d.h"

struct GimmickData;

class GimmickDataReader : public cocos2d::Node
{

protected:

	GimmickDataReader() = default;

	~GimmickDataReader() = default;

public:

	typedef std::vector< GimmickData > GimmickReadData;

public:

	static GimmickDataReader* create();

	GimmickReadData read(const std::string& fileName);
};

#endif