#include "cocos2d.h"
#include "ADX2Converter.h"

using namespace cocos2d;

std::string ADX2Converter::convertFilePath( const std::string& filePath )
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	return FileUtils::getInstance()->fullPathForFilename( filePath );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ) || ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	return std::string( filePath.c_str() );
#endif
}