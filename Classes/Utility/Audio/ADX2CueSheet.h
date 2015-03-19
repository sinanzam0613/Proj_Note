#ifndef _ADX2_CUESHEET_H_
#define _ADX2_CUESHEET_H_

#include "cocos2d.h"
#include "cri_adx2le.h"

/**
 *	@class	：	ADX2CueSheet
 *	@brief	：	キューを管理するキューシートクラス
 *	@author	：	利川聖太
 */
class ADX2CueSheet : public cocos2d::Ref
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2CueSheet();
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2CueSheet();
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@param	acb				ACBファイルのファイルパス
	 *	@param	awb				AWBファイルのファイルパス
	 *	@return	ADX2CueSheet	インスタンス
	 */
	static ADX2CueSheet* create( const std::string& acb, const std::string& awb );
	
	/**
	 *	@brief	キューシート情報を管理するハンドルの取得
	 *	@return	CriAtomExAcbHn	ACBハンドル
	 */
	CriAtomExAcbHn getAcbHandle();
	
private:
	
	/**
	 *	@brief	ACBファイルの読み込み
	 *	@param	acb				ACBファイルのファイルパス
	 *	@param	awb				AWBファイルのファイルパス
	 *	@return	bool			ACBファイルの読み込みに成功したか否か
	 */
	bool loadAcb( const std::string& acb, const std::string& awb );
	
private:
	
	// メンバ変数の宣言
	CriAtomExAcbHn	mAcbHandle;
};

#endif