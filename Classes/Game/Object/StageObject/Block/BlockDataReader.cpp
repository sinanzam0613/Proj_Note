#include "BlockDataReader.h"
#include "BlockData.h"
#include "Utility/FileIO/PlistReader.h"

BlockDataReader* BlockDataReader::create()
{
	auto inst = new BlockDataReader();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

BlockDataReader::ReadData BlockDataReader::read( const std::string& fileName )
{
	PlistReader	reader;
	ReadData	readData;
	
	auto valueMap = reader.read( fileName );
	
	for ( auto& map : valueMap )
	{
		BlockData data;
		data.pointTextureName	= map.at( "pointTextureName" ).asString();
		data.blockTextureName	= map.at( "blockTextureName" ).asString();
		data.cueID				= map.at( "cueID" ).asInt();
		data.positionX			= map.at( "positionX" ).asInt();
		data.positionY			= map.at( "positionY" ).asInt();
		data.objectType			= std::stoi( map.at( "objectType" ).asString().c_str(), nullptr, 16 );
		debugLog( data );
		readData.push_back( data );
	}
	
	return readData;
}

void BlockDataReader::debugLog( const BlockData& data )
{
	CCLOG( "pointTextureName : %s",	data.pointTextureName.c_str()	);
	CCLOG( "blockTextureName : %s",	data.blockTextureName.c_str()	);
	CCLOG( "cueID : %i",			data.cueID						);
	CCLOG( "positionX : %i",		data.positionX					);
	CCLOG( "positionY : %i",		data.positionY					);
	CCLOG( "objectType : %x",		data.objectType					);
}