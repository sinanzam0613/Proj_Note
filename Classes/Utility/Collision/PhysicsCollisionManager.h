#ifndef _PHYSICS_COLLISION_MANAGER_H_
#define _PHYSICS_COLLISION_MANAGER_H_

#include "cocos2d.h"
#include "Utility/Template/Singleton.h"
#include "../Delegate/Delegate.h"

class Collider;

/**
 *	@class	：	PhysicsCollisionManager
 *	@brief	：	剛体同士の衝突判定管理者クラス
 *	@author	：	利川聖太
 */
class PhysicsCollisionManager : public Singleton< PhysicsCollisionManager >
{
	
private:
	
	// 型定義
	typedef Delegate< Collider, cocos2d::Node* >		CollisionDelegate;
	typedef std::map< std::string, CollisionDelegate* >	DelegateContainer;
	
public:
	
	/**
	 *	@brief	デストラクタ
	 */
	~PhysicsCollisionManager();
	
	/**
	 *	@brief	コールバック関数の追加
	 *	@param	nodeName	ノードの名前
	 *	@param	delegate	デリゲート
	 */
	void addCallback( const std::string& nodeName, CollisionDelegate* delegate );
	
	/**
	 *	@brief	コールバック関数の削除
	 *	@param	nodeName	ノードの名前
	 */
	void deleteCallback( const std::string& nodeName );
	
	/**
	 *	@brief	衝突時に「1度だけ」呼ばれるコールバック関数
	 *	@param	contact		衝突したノードの情報
	 *	@return	bool		衝突したか否か
	 */
	bool onContactBegin( cocos2d::PhysicsContact& contact );
	
private:
	
	/**
	 *	@brief	コンストラクタ
	 */
	PhysicsCollisionManager() = default;
	
	/**
	 *	@brief	コールバック関数の実行
	 *	@param	nodeName	ノードの名前
	 *	@param	contactNode	衝突したノード
	 */
	void runCallback( const std::string& nodeName, cocos2d::Node* contactNode );
	
private:
	
	// シングルトンクラスのみ、インスタンスの生成を許可します。
	friend class Singleton< PhysicsCollisionManager >;
	
	// メンバ変数の宣言
	DelegateContainer	mDelegateContainer;
};

#endif