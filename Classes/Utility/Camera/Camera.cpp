#include "Camera.h"

USING_NS_CC;

namespace MyUtill{
	MyCamera::MyCamera():mCamera(nullptr){

	}

	MyCamera::~MyCamera(){

	}

	void MyCamera::create(Layer* _layer){
		
		if (mCamera) return;

		mCamera = new ActionCamera();
		//mCamera->autorelease();
		
		mCamera->startWithTarget(_layer);
	}

	void MyCamera::moveX(float x){
		auto eye = mCamera->getEye();

		eye.x += x;

		mCamera->setEye(eye.x, eye.y, 10);

		mCamera->setCenter(Vec3(eye.x,0,0));
	}
}