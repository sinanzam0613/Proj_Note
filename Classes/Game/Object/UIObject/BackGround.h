#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "cocos2d.h"

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
    static BackGround* create();
    
    /**@brief  背景の生成　*/
    void BackGraundCreate(cocos2d::Layer* layer);
    
private:

    
};


#endif