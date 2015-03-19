#include "ListenerAssistant.h"

using namespace cocos2d;

void ListenerAssistant::setupSingleTouchListener
(
	Node*					target,
	bool					isSwallowTouches,
	SingleTouchBeganFunc	began,
	SingleTouchFunc			moved,
	SingleTouchFunc			ended,
	SingleTouchFunc			cancelled
)
{
	auto singleTouchListener = EventListenerTouchOneByOne::create();
	
	singleTouchListener->setSwallowTouches( isSwallowTouches );
	singleTouchListener->onTouchBegan		= began;
	singleTouchListener->onTouchMoved		= moved;
	singleTouchListener->onTouchEnded		= ended;
	singleTouchListener->onTouchCancelled	= cancelled;
	
	target->getEventDispatcher()->addEventListenerWithSceneGraphPriority( singleTouchListener, target );
}

void ListenerAssistant::setupKeyboardListener( Node* target, KeyboardFunc pressed, KeyboardFunc released )
{
	auto keyboardListener = EventListenerKeyboard::create();
	
	keyboardListener->onKeyPressed	= pressed;
	keyboardListener->onKeyReleased	= released;
	
	target->getEventDispatcher()->addEventListenerWithSceneGraphPriority( keyboardListener, target );
}