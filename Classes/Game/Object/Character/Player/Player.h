#ifndef _PLAYER_H_
#define _PLAYER_H_


//インクルード
#include "cocos2d.h"
#include "Utility/Collision/Collider.h"

class Note;

/**********************************************

ファイル名: Player.h
作成者: 小林 勇輝

***********************************************/
class Player :public cocos2d::Node , public Collider
{
protected:

	/******************************************
	コンストラクタ
	*******************************************/
	Player();

	/*******************************************
	デストラクタ
	********************************************/
	~Player();

public:
	/*******************************************
	初期化
	********************************************/
	virtual bool init(const std::string& fileName);

	/********************************************
	更新
	deltaTime: デルタタイム
	*********************************************/
	virtual void update(float deltaTime) override;

	/*********************************************
	プレイヤーの生成
	**********************************************/
	static Player* create(const std::string& fileName);

	/********************************************
	ジャンプ
	後に別クラスに以降させると思います
	********************************************/
	void jump(cocos2d::Vec2 targetPosition);

	void changeSpeed(float speed);

	void onContactBegin(cocos2d::Node* contactNode) override;

	virtual void setPosition(const cocos2d::Vec2& pos)override;

	virtual const cocos2d::Vec2& getPosition()const override;

	void stop(){ mSprite->stopAllActions(); };

	//テストでタッチしている間ジャンプさせてみます
	bool mTestIsJump;
	int mTestCount;
private:
	cocos2d::Sprite* mSprite;
	float mAngle;
	unsigned int  mJumpTime;
   	float mTestJumpTimer;
	cocos2d::Vec2 mTargetPos;

};

#endif