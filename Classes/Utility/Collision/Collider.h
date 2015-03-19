#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include "cocos2d.h"

/**
 *	@class	：	Collider
 *	@brief	：	剛体を持つオブジェクトの基底クラス
 *	@author	：	利川聖太
 */
class Collider
{
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~Collider() = default;
	
	/**
	 *	@brief	衝突判定の有効化
	 *	@param	nodeName	ノードの名前
	 *						衝突した際、衝突したノードの名前で
	 *						コールバック関数を実行するので、ノードの名前を事前に登録する必要があります。
	 */
	void enableCollision( const std::string& nodeName );
	
	/**
	 *	@brief	衝突判定の無効化
	 *	@param	nodeName	ノードの名前
	 *						衝突判定を有効化した時のノードの名前が必要になります。
	 */
	void disableCollision( const std::string& nodeName );
	
	/**
	 *	@brief	衝突時に「1度だけ」呼ばれるコールバック関数
	 *	@param	contactNode	衝突したノード
	 */
	virtual void onContactBegin( cocos2d::Node* contactNode ) = 0;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	Collider();
	
protected:
	
	// メンバ変数の宣言
	cocos2d::PhysicsBody*		mPhysicsBody;
	cocos2d::PhysicsMaterial	mPhysicsMaterial;
};

#endif