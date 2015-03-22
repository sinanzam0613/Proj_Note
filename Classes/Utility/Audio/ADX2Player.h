#ifndef _ADX2_PLAYER_H_
#define _ADX2_PLAYER_H_

#include "cocos2d.h"
#include "cri_adx2le.h"
#include "ADX2CueSheet.h"

/**
 *	@class	：	ADX2Player
 *	@brief	：	音の再生を行うプレーヤクラス
 *	@author	：	利川聖太
 */
class ADX2Player : public cocos2d::Node
{
	
public:
	
	// 型定義
	typedef CriAtomExPlayerConfig				PlayerConfig;
	typedef CriAtomExStandardVoicePoolConfig	VoicePoolConfig;
	typedef CriAtomExHcaMxVoicePoolConfig		HcaMxVoicePoolConfig;
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2Player();
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2Player();
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	acb				ACBファイルのファイルパス
	 *	@return	ADX2Player		インスタンス
	 */
	static ADX2Player* create( const std::string& acb );
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	acb				ACBファイルのファイルパス
	 *	@param	awb				AWBファイルのファイルパス
	 *	@return	ADX2Player		インスタンス
	 */
	static ADX2Player* create( const std::string& acb, const std::string& awb );
	
	/**
	 *	@brief	初期化
	 *	@param	acb		ACBファイルのファイルパス
	 *	@param	awb		AWBファイルのファイルパス
	 *	@return	bool	初期化が完了したか否か
	 */
	bool init( const std::string& acb, const std::string& awb );
	
	/**
	 *	@brief	音の再生
	 *			再生中の音に対して何らかの処理を行いたい場合
	 *			戻り値であるプレイバックIDを保持する必要があります。
	 *	@param	cueID				キューID
	 *	@return	CriAtomExPlaybackId	プレイバックID
	 */
	CriAtomExPlaybackId play( CriAtomExCueId cueID );
	
	/**
	 *	@brief	音の停止
	 *	@param	playbackID	プレイバックID
	 */
	void stop( CriAtomExPlaybackId playbackID );
	
	/**
	 *	@brief	プレーヤの停止
	 */
	void stopPlayer();
	
	/**
	 *	@brief	キューの数の取得
	 *	@return	CriSint32	キューシート内のキューの数
	 */
	CriSint32 getNumCues() const;
	
	/**
	 *	@brief	再生開始後の経過時間の取得
	 *	@param	playbackID	プレイバックID
	 *	@return	CriSint64	経過時間
	 */
	CriSint64 getTime( CriAtomExPlaybackId playbackID ) const;
	
	/**
	 *	@brief	キューの名前の取得
	 *	@param	cueID		キューID
	 *	@return	std::string	キューIDに紐づくキューの名前
	 */
	std::string getCueName( CriAtomExCueId cueID );
	
private:
	
	/**
	 *	@brief	ハンドルの解放
	 */
	void releaseHandle();
	
	/**
	 *	@brief	各コンフィグの設定
	 *			ある程度最適化されている各コンフィグを上書きします。
	 *			この関数を使用するユーザは、ある程度ADX2の内部を知っている必要があります。
	 *	@param	playerConfig			プレーヤ用コンフィグ構造体
	 *	@param	voicePoolConfig			標準ボイスプール用コンフィグ構造体
	 *	@param	hcaMxVoicePoolConfig	HCA-MXボイスプール用コンフィグ構造体
	 */
	void setConfig( PlayerConfig playerConfig, VoicePoolConfig voicePoolConfig, HcaMxVoicePoolConfig hcaMxVoicePoolConfig );
	
private:
	
	// メンバ変数の宣言
	ADX2CueSheet*			mCueSheet;
	CriAtomExPlayerHn		mPlayerHandle;
	CriAtomExVoicePoolHn	mVoicePoolHandle;
	CriAtomExVoicePoolHn	mHcaMxVoicePoolHandle;
};

#endif