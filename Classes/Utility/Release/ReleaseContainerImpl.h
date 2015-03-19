#ifndef _RELEASE_CONTAINER_IMPL_H_
#define _RELEASE_CONTAINER_IMPL_H_

#include "ReleaseInstance.h"

template < typename T >
void ReleaseContainer::cleanList( std::list< T* >& list )
{
	list.remove_if( ReleaseInstance() );
	list.clear();
}

template< typename KEY, typename VALUE >
void ReleaseContainer::cleanMap( std::map< KEY, VALUE* >& map )
{
	auto itor	= map.begin();
	auto end	= map.end();
	
	for ( ; itor != end; ++itor )
	{
		CC_SAFE_RELEASE_NULL( itor->second );
	}
	
	map.clear();
}

#endif