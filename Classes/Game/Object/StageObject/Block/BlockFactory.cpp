#include "BlockFactory.h"
#include "BlockDataReader.h"
#include "RedBlock.h"
#include "BlueBlock.h"
#include "GoalBlock.h"
#include "NormalBlock.h"

using namespace cocos2d;

void BlockFactory::createBlock( Node* parentNode, const std::string& fileName )
{
	auto reader		= BlockDataReader::create();
	auto readData	= reader->read( fileName );
	
	int count = 0;
	for ( auto& data : readData )
	{
		if ( std::strstr( data.blockTextureName.c_str(), "Red" ) )
		{
			auto block = RedBlock::create( "RedBlock" + std::to_string( count ), data );
			parentNode->addChild( block );
			++count;
			continue;
		}
		if ( std::strstr( data.blockTextureName.c_str(), "Blue" ) )
		{
			auto block = BlueBlock::create( "BlueBlock" + std::to_string( count ), data );
			parentNode->addChild( block );
			++count;
			continue;
		}
		if ( std::strstr( data.blockTextureName.c_str(), "Goal" ) )
		{
			auto block = GoalBlock::create( "GoalBlock" + std::to_string( count ), data );
			parentNode->addChild( block );
			++count;
			continue;
		}
		if ( std::strstr( data.blockTextureName.c_str(), "Normal" ) )
		{
			auto block = NormalBlock::create( "NormalBlock" + std::to_string( count ), data );
			parentNode->addChild( block );
			++count;
			continue;
		}
	}
}