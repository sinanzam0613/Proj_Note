#include "SlideBar.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
/--------------------------*/
SlideBar::SlideBar(){
}


/*--------------------------/
 インスタンス生成
/--------------------------*/
SlideBar* SlideBar::create(){
    auto inst = new SlideBar();
    
    if(inst && inst -> init()){
        inst -> autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE(inst);
    return nullptr;
}

/*--------------------------/
 スライドバー生成
/--------------------------*/
void SlideBar::SlideBarCreate(const std::string& name,
	cocos2d::Layer* layer,
	const std::string& bgFail,
	const std::string& progressFail,
	const std::string& thumbFail,
	const std::string& selectthumbFail,
	Vec2 pos
	)
{
	//画像の設定
	//auto  mSlider = extension::ControlSlider::create(bgFail.c_str(), progressFail.c_str() , thumbFail.c_str(),selectthumbFail.c_str());
	auto  mSlider = extension::ControlSlider::create("", "", "");

	//最小値、最大値の決定
	/*
	mSlider->setMinimumValue(1.5f);
	mSlider->setMaximumValue(3.0f);
	//移動範囲の最小値、最大値の決定
	//mSlider[tag]->setMinimumAllowedValue(0.1f);
	//mSlider[tag]->setMaximumAllowedValue(0.9f);
	//初期値の設定
	mSlider->setValue(2.0f);
	//name設定
	mSlider->setName(name);
	//位置の設定
	mSlider->setPosition(pos);
	mSlider->setScale(1.5f);
	//レイヤーへの追加
	layer->addChild(mSlider);
	*/
}

/*--------------------------/
 値の取得
/--------------------------*/
float SlideBar::getValue(const std::string& name,cocos2d::Layer* layer)
{
	auto slider = static_cast<extension::ControlSlider*>(layer->getChildByName(name));
    
    return slider->getValue();
}
