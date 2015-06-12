//#include "UiObjectLayer.h"
//
//USING_NS_CC;
//
//
///*--------------------------/
// コンストラクタ
///--------------------------*/
//UiObjectLayer::UiObjectLayer(){}
//
///*--------------------------/
// 初期化
///--------------------------*/
//bool UiObjectLayer::init(){
//    if(!Layer::init()){
//        return false;
//    }
//    
//    //スライドバー生成
//    mSlideBar = SlideBar::create();
//    
//    //プレイヤー１用スライドバー生成
//    mSlideBar->slideBarCreate("p1",
//                              this,
//                              "Texture/GamePlay/Controller/sliderTrack.png",
//                              "Texture/GamePlay/Controller/sliderTrack.png",
//                              "Texture/GamePlay/Controller/sliderThumb_Red.png",
//                              "Texture/GamePlay/Controller/switch-thumb_Red.png",
//                              Vec2(300, 100));
//    
//    
//    //プレイヤー２用スライドバー生成
//    mSlideBar->slideBarCreate("p2",
//                              this,
//                              "Texture/GamePlay/Controller/sliderTrack.png",
//                              "Texture/GamePlay/Controller/sliderTrack.png",
//                              "Texture/GamePlay/Controller/sliderThumb_Blue.png",
//                              "Texture/GamePlay/Controller/switch-thumb_Blue.png",
//                              Vec2(1000, 100));
//    return true;
//}