#ifndef _DELEGATE_H_
#define _DELEGATE_H_

#include <functional>

using namespace std::placeholders;

/**
 *	@class	：	Delegate
 *	@brief	：	デリゲートクラス
 *				引数3個, 2個, 1個, 0個に対応しています。
 *	@author	：	利川聖太
 */
template< typename T, typename ARGS_1 = void*, typename ARGS_2 = void*, typename ARGS_3 = void* >
class Delegate
{
	
public:
	
	// 型定義
	typedef void( T::*Func )( ARGS_1, ARGS_2, ARGS_3 );
	typedef void( *StaticFunc )( ARGS_1, ARGS_2, ARGS_3 );
	
	/**
	 *	@brief	関数の登録
	 *	@param	instance	インスタンス
	 *	@param	func		登録する関数
	 */
	void setFunc( T* instance, Func func )
	{
		mFunction = std::bind( func, instance, _1, _2, _3 );
	}
	
	/**
	 *	@brief	静的関数の登録
	 *	@param	func	登録する関数
	 */
	void setFunc( StaticFunc func )
	{
		mFunction = std::bind( func, _1, _2, _3 );
	}
	
	/**
	 *	@brief	関数を実行する関数オブジェクト
	 *	@param	args_1	引数 1
	 *	@param	args_2	引数 2
	 *	@param	args_3	引数 3
	 */
	void operator () ( ARGS_1 args_1, ARGS_2 args_2, ARGS_3 args_3 )
	{
		mFunction( args_1, args_2, args_3 );
	}
	
private:
	
	// メンバ変数の宣言
	std::function< void( ARGS_1, ARGS_2, ARGS_3 ) >	mFunction;
};

template< typename T, typename ARGS_1, typename ARGS_2 >
class Delegate< T, ARGS_1, ARGS_2 >
{
	
public:
	
	// 型定義
	typedef void( T::*Func )( ARGS_1, ARGS_2 );
	typedef void( *StaticFunc )( ARGS_1, ARGS_2 );
	
	/**
	 *	@brief	関数の登録
	 *	@param	instance	インスタンス
	 *	@param	func		登録する関数
	 */
	void setFunc( T* instance, Func func )
	{
		mFunction = std::bind( func, instance, _1, _2 );
	}
	
	/**
	 *	@brief	静的関数の登録
	 *	@param	func	登録する関数
	 */
	void setFunc( StaticFunc func )
	{
		mFunction = std::bind( func, _1, _2 );
	}
	
	/**
	 *	@brief	関数を実行する関数オブジェクト
	 *	@param	args_1	引数 1
	 *	@param	args_2	引数 2
	 */
	void operator () ( ARGS_1 args_1, ARGS_2 args_2 )
	{
		mFunction( args_1, args_2 );
	}
	
private:
	
	// メンバ変数の宣言
	std::function< void( ARGS_1, ARGS_2 ) >	mFunction;
};

template< typename T, typename ARGS_1 >
class Delegate< T, ARGS_1 >
{
	
public:
	
	// 型定義
	typedef void( T::*Func )( ARGS_1 );
	typedef void( *StaticFunc )( ARGS_1 );
	
	/**
	 *	@brief	関数の登録
	 *	@param	instance	インスタンス
	 *	@param	func		登録する関数
	 */
	void setFunc( T* instance, Func func )
	{
		mFunction = std::bind( func, instance, _1 );
	}
	
	/**
	 *	@brief	静的関数の登録
	 *	@param	func	登録する関数
	 */
	void setFunc( StaticFunc func )
	{
		mFunction = std::bind( func, _1 );
	}
	
	/**
	 *	@brief	関数を実行する関数オブジェクト
	 *	@param	args_1	引数 1
	 */
	void operator () ( ARGS_1 args_1 )
	{
		mFunction( args_1 );
	}
	
private:
	
	// メンバ変数の宣言
	std::function< void( ARGS_1 ) >	mFunction;
};

template< typename T >
class Delegate< T >
{
	
public:
	
	// 型定義
	typedef void( T::*Func )();
	typedef void( *StaticFunc )();
	
	/**
	 *	@brief	関数の登録
	 *	@param	instance	インスタンス
	 *	@param	func		登録する関数
	 */
	void setFunc( T* instance, Func func )
	{
		mFunction = std::bind( func, instance );
	}
	
	/**
	 *	@brief	静的関数の登録
	 *	@param	func	登録する関数
	 */
	void setFunc( StaticFunc func )
	{
		mFunction = std::bind( func );
	}
	
	/**
	 *	@brief	関数を実行する関数オブジェクト
	 */
	void operator () ()
	{
		mFunction();
	}
	
private:
	
	// メンバ変数の宣言
	std::function< void() >	mFunction;
};

#endif