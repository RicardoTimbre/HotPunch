#include "GameOverLayer.h"
#include "Scene.h"
USING_NS_CC;
bool GameOverLayer::init()
{
	if (!CCLayer::init())
		return false;
	//´´½¨±³¾°Í¼Æ¬¾«Áé
	int randNum = rand()%4;
	if (randNum == 0)
	{
		sp_Background = CCSprite::create("endSprite0.png");
		sp_Background->setScale(0.7f);
	}
	else if(randNum == 1)
	{
		sp_Background = CCSprite::create("endSprite1.png");
		sp_Background->setScale(0.5f);
	}
	else if (randNum == 2)
	{
		sp_Background = CCSprite::create("endSprite2.png");
		sp_Background->setScale(0.5f);
	}
	else
	{
		sp_Background = CCSprite::create("endSprite3.png");
		sp_Background->setScale(0.5f);
	}
	sp_Background->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
		CCDirector::sharedDirector()->getVisibleSize().height/2));
	this->addChild(sp_Background);
	CCMenuItemImage* pMenuBack = CCMenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",this,menu_selector(GameOverLayer::retryBtnCallBack));
	pMenuBack->setPosition(CCPointMake(CCDirector::sharedDirector()->getVisibleSize().width/2-pMenuBack->getContentSize().width*2,
		-CCDirector::sharedDirector()->getVisibleSize().height/2+pMenuBack->getContentSize().height*2));
	CCMenu* overMenu = CCMenu::create(pMenuBack,NULL);
	this->addChild(overMenu);
	return true;
}

CCScene*  GameOverLayer::Scene()
{
	CCScene* pScene = CCScene::create();
	GameOverLayer* pLayer = GameOverLayer::create();
	pScene->addChild(pLayer);
	return pScene;
}
void GameOverLayer::retryBtnCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(Scene::titleScene());
}