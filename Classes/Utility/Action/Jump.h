#ifndef JUMP_H_
#define JUMP_H_

#include "cocos2d.h"

namespace myAction{
	class Jump : public cocos2d::ActionInterval
	{
	public:
		static Jump* create(float duration, const cocos2d::Vec2& position, float height, int jumps);

		virtual Jump* clone() const override;
		virtual Jump* reverse(void) const override;
		virtual void startWithTarget(cocos2d::Node *target) override;
		virtual void update(float time) override;

		void setSpeed(float speed);

		bool initWithDuration(float duration, const cocos2d::Vec2& position, float height, int jumps);

	CC_CONSTRUCTOR_ACCESS:
		Jump(){}
		virtual ~Jump(){}

	protected:
		cocos2d::Vec2           _startPosition;
		cocos2d::Vec2           _delta;
		float					 _height;
		int						_jumps;
		cocos2d::Vec2           _previousPos;

		CC_DISALLOW_COPY_AND_ASSIGN(Jump);
	};
}
#endif