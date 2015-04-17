#include "PauseLayer.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
bool PauseLayer::init()
{
	if (!GameLayer::init())
	{
		return false;
	}
	CCSprite* image = CCSprite::create("PauseImage.png");
	CCMenuItemImage* btn = CCMenuItemImage::create("DirectBtn.png","DirectBtn_P.png",this,menu_selector(PauseLayer::btnResume));
	btn->setPosition(ccp(320,100));
	CCMenu* pMenu = CCMenu::create(btn,NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu,10);
	image->setPosition(ccp(320,160));
	this->addChild(image);
	return true;
}
void PauseLayer::btnResume(CCObject* pSender)
{
	CCDirector::sharedDirector()->popScene();
	CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}