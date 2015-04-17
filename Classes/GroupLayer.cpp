#include "GroupLayer.h"
#include "Scene.h"
bool GroupLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	CCSprite* sptMaker = CCSprite::create("makeGroup.png");
	sptMaker->setPosition(ccp(sptMaker->getContentSize().width/2 - 20,sptMaker->getContentSize().height/2));
	this->addChild(sptMaker);

	CCMenuItemImage* pReturn = CCMenuItemImage::create("returnMenu.png",
      "returnMenuSlected.png",
		this,
		menu_selector(GroupLayer::menuReturnCall));
	pReturn->setOpacity(180);

	 CCMenu* makeMenu = CCMenu::create(pReturn,NULL);
	 makeMenu->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width - pReturn->getContentSize().width , pReturn->getContentSize().height/2));

	 this->addChild(makeMenu,5);	

	 return true;
}
void GroupLayer::menuReturnCall(CCObject* pSneder)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,Scene::titleScene()));
}