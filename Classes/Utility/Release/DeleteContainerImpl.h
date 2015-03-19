#ifndef _DELETE_CONTAINER_IMPL_H_
#define _DELETE_CONTAINER_IMPL_H_

#include "DeleteInstance.h"

template < typename T >
void DeleteContainer::cleanList( std::list< T* >& list )
{
	list.remove_if( DeleteInstance() );
	list.clear();
}

template< typename KEY, typename VALUE >
void DeleteContainer::cleanMap( std::map< KEY, VALUE* >& map )
{
	auto itor	= map.begin();
	auto end	= map.end();
	
	for ( ; itor != end; ++itor )
	{
		CC_SAFE_DELETE( itor->second );
	}
	
	map.clear();
}

#endif