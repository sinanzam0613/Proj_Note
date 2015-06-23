#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "cocos2d.h"
enum Tags;

/**
 *	@class	： BackGround
 *	@brief	： 背景クラス
 *	@author	： 新井椋汰
 */

class BackGround : public cocos2d::Node {
protected:
    
    /**　@brief  コンストラクタ*/
    BackGround();
    
    /**　@brief  デストラクタ*/
    ~BackGround()=default;


public:
    /**
     *  @brief  インスタンスの生成
     * @return	SlideBar   インスタンス
     */
	static BackGround* create(cocos2d::Layer* layer);
    
    /**@brief  背景の生成　*/
	void BackGraundCreate(cocos2d::Layer* layer,const cocos2d::Vec2& pos, const Tags tag);
    

	void update(float dt, cocos2d::Layer* layer);

	void resetPos(cocos2d::Layer* layer, const Tags tag);

private:
	int init(cocos2d::Layer* layer);
    
};


#endif