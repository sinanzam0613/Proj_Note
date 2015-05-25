#include "Jump.h"

USING_NS_CC;

namespace myAction{
	
	Jump* Jump::create(float duration, const Vec2& position, float height, int jumps)
	{
		Jump *jump = new Jump();
		jump->initWithDuration(duration, position, height, jumps);
		jump->autorelease();

		return jump;
	}

	bool Jump::initWithDuration(float duration, const Vec2& position, float height, int jumps)
	{
		CCASSERT(jumps >= 0, "Number of jumps must be >= 0");

		if (ActionInterval::initWithDuration(duration) && jumps >= 0)
		{
			_delta = position;
			_height = height;
			_jumps = jumps;

			return true;
		}

		return false;
	}
	
	Jump* Jump::clone() const
	{
		// no copy constructor
		auto a = new Jump();
		a->initWithDuration(_duration, _delta, _height, _jumps);
		a->autorelease();
		return a;
	}

	Jump* Jump::reverse() const
	{
		CCASSERT(false, "reverse() not supported in Jump");
		return nullptr;
	}

	void Jump::startWithTarget(Node *target)
	{
		ActionInterval::startWithTarget(target);
		_previousPos = _startPosition = target->getPosition();
		_delta = Vec2(_delta.x - _startPosition.x, _delta.y - _startPosition.y);
	}

	void Jump::update(float t)
	{
		// parabolic jump (since v0.8.2)
		if (_target)
		{
			float frac = fmodf(t * _jumps, 1.0f);
			float y = _height * 4 * frac * (1 - frac);
			y += _delta.y * t;

			float x = _delta.x * t;
#if CC_ENABLE_STACKABLE_ACTIONS
			Vec2 currentPos = _target->getPosition();

			Vec2 diff = currentPos - _previousPos;
			_startPosition = diff + _startPosition;

			Vec2 newPos = _startPosition + Vec2(x, y);
			_target->setPosition(newPos);

			_previousPos = newPos;
#else
			_target->setPosition(_startPosition + Vec2(x, y));
#endif // !CC_ENABLE_STACKABLE_ACTIONS
		}
	}

	void Jump::setSpeed(float speed){
		_duration = speed;
	}

}
