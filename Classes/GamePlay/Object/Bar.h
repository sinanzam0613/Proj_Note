#ifndef BAR_H
#define BAR_H

#include "StageObj.h"

class Bar : public StageObj{

public:
	Bar* create(const std::string textureName);

	bool init(const std::string textureName);

	void update(float deltatime) override;

protected:
	Bar() = default;

	~Bar() = default;

};
#endif