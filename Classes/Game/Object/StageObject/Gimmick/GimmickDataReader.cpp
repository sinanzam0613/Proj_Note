#include "GimmickDataReader.h"
#include "GimmickData.h"
#include "Utility/FileIO/PlistReader.h"

GimmickDataReader* GimmickDataReader::create() {
	auto inst = new GimmickDataReader();

	if ( inst && inst->init() ) {
		inst->autorelease();
		return inst;
	}

	CC_SAFE_DELETE(inst);
	return nullptr;
}

GimmickDataReader::ReadData GimmickDataReader::read( const std::string& fileName ) {
	PlistReader reader;
	ReadData	readData;

	auto valueMap = reader.read( fileName );

	for ( auto& map : valueMap ) {
		GimmickData data;
		data.textureName	= map.at( "textureName" ).asString();
		data.positionX = map.at( "positionX" ).asInt();
		data.positionY = map.at( "positionY" ).asInt();
		data.objectType = std::stoi( map.at( "objectType" ).asString().c_str(), nullptr, 2 );
		readData.push_back( data );
	}
	return readData;
}