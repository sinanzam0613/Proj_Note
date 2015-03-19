#ifndef _ADX2_CONVERTER_H_
#define _ADX2_CONVERTER_H_

#include <string>

/**
 *	@class	：	ADX2Converter
 *	@brief	：	機種依存の変換を行うクラス
 *	@author	：	利川聖太
 */
class ADX2Converter
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2Converter() = delete;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2Converter() = delete;
	
	/**
	 *	@brief	ファイルパスの変換
	 *	@param	filePath	ファイルパス
	 *	@return	std::string	変換済みのファイルパス
	 */
	static std::string convertFilePath( const std::string& filePath );
};

#endif