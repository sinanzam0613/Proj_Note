#ifndef _NOTE_H_
#define _NOTE_H_

#include "cocos2d.h"
#include "NoteValue.h"
#include "Game/Object/StageObject/StageObj.h"
#include "Utility/Collision/Collider.h"

//クラス前方宣言
class ADX2Player;

/**
 *	@class	：	Note
 *	@brief	：	音符
 *	@author	：	石川貴康
 */
class Note : public StageObj , public Collider {
protected:

	/**
	 *	@brief	コンストラクタ
	 */
	Note();

	/**
	 *	@brief	デストラクタ
	 */
	~Note();
public:

	/**
	 *	@brief	初期化
	 *	@return	bool	初期化の成否
	 */
	virtual bool init(const cocos2d::Vec2 &position);

	/**
	 *	@brief	更新
	 *	@pram	deltaTime	1fの更新にかかった時間
	 */
	virtual void update(float deltaTime) override;

	/**
	 *	@brief	インスタンスの生成
	 *	@return	Note	インスタンス
	 */
	static Note* createObject(const cocos2d::Vec2 &position);


	/*-----------------------------------------------------
	|	サウンドの再生
	|	int PosY 　音符の高さ（位置によって音を変える為）
	------------------------------------------------------*/
	void soundPlay(int PosY);

    void onContactBegin(cocos2d::Node* contactNode) override;

	void setName(const std::string& name) override;

private:

	ADX2Player* mADX2Player;
	int mSoundScale;
};

#endif