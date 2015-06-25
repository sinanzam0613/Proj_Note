#ifndef PAUSEBOTTON_H
#define PAUSEBOTTON_H

#include "cocos2d.h"

namespace UI{

	class PauseBotton : public cocos2d::MenuItemSprite
	{

	protected:
		PauseBotton(){};
		~PauseBotton() = default;

	public:

		static PauseBotton* create(Node* normalSprite, Node* selectedSprite);

	private:
	};
}

#endif