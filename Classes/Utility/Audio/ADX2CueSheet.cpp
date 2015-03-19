#include "ADX2CueSheet.h"
#include "ADX2Converter.h"

using namespace cocos2d;

ADX2CueSheet::ADX2CueSheet()
	: mAcbHandle( nullptr )
{
	
}

ADX2CueSheet::~ADX2CueSheet()
{
	criAtomExAcb_Release( mAcbHandle );
}

ADX2CueSheet* ADX2CueSheet::create( const std::string& acb, const std::string& awb )
{
	auto inst = new ADX2CueSheet();
	
	if ( inst && inst->loadAcb( acb, awb ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

CriAtomExAcbHn ADX2CueSheet::getAcbHandle()
{
	return mAcbHandle;
}

bool ADX2CueSheet::loadAcb( const std::string& acb, const std::string& awb )
{
	auto acbPath	= ADX2Converter::convertFilePath( acb );
	auto awbPath	= ADX2Converter::convertFilePath( awb );
	
	if ( awb == "" )
	{
		// AWBファイルを使用しない場合の読み込みです。
		mAcbHandle = criAtomExAcb_LoadAcbFile( NULL, acbPath.c_str(), NULL, NULL, NULL, 0 );
	}
	
	else
	{
		mAcbHandle = criAtomExAcb_LoadAcbFile( NULL, acbPath.c_str(), NULL, awbPath.c_str(), NULL, 0 );
	}
	
	if ( mAcbHandle == nullptr )
	{
		return false;
	}
	
	return true;
}