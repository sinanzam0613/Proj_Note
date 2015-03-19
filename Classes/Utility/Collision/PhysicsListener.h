#ifndef _PHYSICS_LISTENER_H_
#define _PHYSICS_LISTENER_H_

#include "cocos2d.h"

/**
 *	@class	：	PhysicsListener
 *	@brief	：	剛体を持つオブジェクトの衝突を検知するリスナクラス
 *	@author	：	利川聖太
 */
class PhysicsListener : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PhysicsListener() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~PhysicsListener() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	PhysicsListener	インスタンス
	 */
	static PhysicsListener* create();
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
};

#endif