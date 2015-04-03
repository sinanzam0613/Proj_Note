#include "AppDelegate.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Utility/Audio/ADX2Manager.h"
#include "Utility/Audio/ADX2LogoLayer.h"

using namespace cocos2d;

AppDelegate::AppDelegate()
	: mADX2Manager( ADX2Manager::create() )
{
	mADX2Manager->retain();
}

AppDelegate::~AppDelegate()
{
	mADX2Manager->release();
}

bool AppDelegate::applicationDidFinishLaunching()
{
	auto director	= Director::getInstance();
	auto glView		= director->getOpenGLView();

	if ( !glView )
	{
		glView = GLView::create( "おんぷ" );
		director->setOpenGLView( glView );
	}
	
	director->setDisplayStats( true );
	director->setAnimationInterval( 1.f / 60.f );
	
	glView->setDesignResolutionSize( 1280, 720, ResolutionPolicy::SHOW_ALL );
	
	FileUtils::getInstance()->addSearchPath( "Font"		);
	FileUtils::getInstance()->addSearchPath( "Texture"	);
	FileUtils::getInstance()->addSearchPath( "Sound"	);
	
	mADX2Manager->init( "Note.acf" );
	
	auto firstScene = SceneCreator::createScene( ADX2LogoLayer::create() );
	auto scene		= TransitionFade::create( 1.5f, firstScene, Color3B::BLACK );
	director->runWithScene( scene );
	
	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
	
	mADX2Manager->pauseApp();
}

void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
	
	mADX2Manager->resumeApp();
}