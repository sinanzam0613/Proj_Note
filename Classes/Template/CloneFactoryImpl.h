#ifndef _CLONE_FACTORY_IMPL_H_
#define _CLONE_FACTORY_IMPL_H_

#include "CloneFactory.h"

template< typename KEY, typename PRODUCT, typename RELEASE >
CloneFactory< KEY, PRODUCT, RELEASE >::~CloneFactory()
{
	RELEASE::cleanMap( mProductContainer );
}

template< typename KEY, typename PRODUCT, typename RELEASE >
void CloneFactory< KEY, PRODUCT, RELEASE >::add( KEY key, PRODUCT* product )
{
	mProductContainer[ key ] = product;
}

template< typename KEY, typename PRODUCT, typename RELEASE >
PRODUCT* CloneFactory< KEY, PRODUCT, RELEASE >::create( KEY key )
{
	// clone関数( プロトタイプパターン )を実装していることが前提です。
	return mProductContainer[ key ]->clone();
}

#endif