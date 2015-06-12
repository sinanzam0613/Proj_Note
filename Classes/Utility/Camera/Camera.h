#ifndef MYCAMERA_H
#define MYCAMERA_H

#include "cocos2d.h"
#include "Utility/Template/Singleton.h"

namespace MyUtill{
	class MyCamera :public Singleton<MyCamera>
	{
	public:
		~MyCamera();

		void create(cocos2d::Layer* layer);

		void moveX(float x);

	private:
		MyCamera();

		friend class Singleton< MyCamera >;

		cocos2d::ActionCamera* mCamera;
	};
}
#endif