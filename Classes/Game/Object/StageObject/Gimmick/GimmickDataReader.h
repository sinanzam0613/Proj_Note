#ifndef GIMMICKDATAREADER_H
#define GIMMICKDATAREADER_H

#include "cocos2d.h"

struct GimmickData;

class GimmickDataReader : public cocos2d::Node {
protected:
	GimmickDataReader() = default;
	~GimmickDataReader() = default;
public:
	typedef std::vector< GimmickData > ReadData;
public:
	static GimmickDataReader* create();
	ReadData read( const std::string& fileName);
};

#endif