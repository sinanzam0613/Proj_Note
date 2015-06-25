#include "PauseBotton.h"
#include "PauseLayer.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "base/ccUtils.h"

using namespace UI;

PauseBotton* PauseBotton::create(Node* normalSprite, Node* selectedSprite ){
	auto obj = new PauseBotton();
	
	auto callback = [&](Ref*){

		//cocos2d::utils::captureScreen([&](bool succeed, const std::string &filePath){
		//	if (succeed){
		//		cocos2d::Director::getInstance()->getTextureCache()->removeTextureForKey(filePath);
		//		auto sprite = cocos2d::Sprite::create(filePath);

		//		auto scene = SceneCreator::createScene(PauseLayer::create(sprite));
		//		cocos2d::Director::getInstance()->pushScene(scene);
		//	}
		//	else{
		//		cocos2d::log("キャプチャー失敗");
		//	}
		//}, "screenshot.png");

		auto size = cocos2d::Director::getInstance()->getWinSize();

		cocos2d::RenderTexture* texture = cocos2d::RenderTexture::create(size.width,size.height);
		texture->setPosition(cocos2d::Vec2(size.width * 0.5f, size.height * 0.5f));

		texture->begin();
		cocos2d::Director::getInstance()->getRunningScene()->visit();
		texture->end();

		auto scene = SceneCreator::createScene(PauseLayer::create(texture));

		cocos2d::Director::getInstance()->pushScene(scene);
		

	};

	if (obj && obj->initWithNormalSprite(normalSprite, selectedSprite, nullptr, callback)){
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}