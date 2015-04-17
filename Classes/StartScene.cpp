#ifndef _Story00__
#define _Story00__

#include "StartScene.h"
#include "Scene.h"

bool  StartScene::init()
{
/*齐鲁软件设计大赛
        参赛作品*/	
	setTouchEnabled(true);
	//CCArray* stAction = CCArray::createWithCapacity(12);
	CCSpriteFrameCache* frameStart = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameStart->addSpriteFramesWithFile("startpages.plist","startpages.png");
	CCSprite* pLabel0= CCSprite::createWithSpriteFrameName("qi.png");
	CCSprite* pLabel1= CCSprite::createWithSpriteFrameName("lu.png");
	CCSprite* pLabel2 = CCSprite::createWithSpriteFrameName("ruan.png");
    CCSprite* pLabel3 = CCSprite::createWithSpriteFrameName("jian.png");
    CCSprite* pLabel4 = CCSprite::createWithSpriteFrameName("she.png");
    CCSprite*	pLabel5 = CCSprite::createWithSpriteFrameName("ji.png");
	CCSprite* pLabel6 = CCSprite::createWithSpriteFrameName("da.png");
	CCSprite* pLabel7 = CCSprite::createWithSpriteFrameName("sai.png");
	CCSprite* pLabelc = CCSprite::createWithSpriteFrameName("scan.png");
	pLabelc->setPosition(ccp(-4*pLabelc->getContentSize().width,CCDirector::sharedDirector()->getVisibleSize().height/4));
	CCSprite* pLabels = CCSprite::createWithSpriteFrameName("ssai.png");
	pLabels->setPosition(ccp(-3*pLabels->getContentSize().width,CCDirector::sharedDirector()->getVisibleSize().height/4));
	CCSprite* pLabelz = CCSprite::createWithSpriteFrameName("szuo.png");
	pLabelz->setPosition(ccp(-2*pLabelz->getContentSize().width,CCDirector::sharedDirector()->getVisibleSize().height/4));
	CCSprite* pLabelp = CCSprite::createWithSpriteFrameName("spin.png");
	pLabelp->setPosition(ccp(-pLabelp->getContentSize().width,CCDirector::sharedDirector()->getVisibleSize().height/4));
    CCSprite* pStartBg = CCSprite::createWithSpriteFrameName("start_back.png");
	pStartBg->setScale(1.5);
	pStartBg->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
	CCDirector::sharedDirector()->getVisibleSize().height/2));
	this->addChild(pStartBg,0);
	/**************************文字效果***********************************/
	pLabel0->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width,
		CCDirector::sharedDirector()->getVisibleSize().height/2));
	this->addChild(pLabel0);
	CCPoint pLabel0Point = ccp(11*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	labelAction(pLabel0,pLabel0Point);
	
	////////
	pLabel1->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width+pLabel1->getContentSize().width,
		CCDirector::sharedDirector()->getVisibleSize().height));
	this->addChild(pLabel1);
	CCPoint pLabel1Point = ccp(17*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	labelAction(pLabel1,pLabel1Point);

	///////
	pLabel2->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width+pLabel2->getContentSize().width,0));
	this->addChild(pLabel2);
	CCPoint pLabel2Point = ccp(23*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	labelAction(pLabel2,pLabel2Point);
	///////
	pLabel3->setPosition(ccp(0,	CCDirector::sharedDirector()->getVisibleSize().height));
	this->addChild(pLabel3);
	CCPoint pLabel3Point = ccp(29*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	labelAction(pLabel3,pLabel3Point);
	/////////
	pLabel4->setPosition(ccp(0,0));
	this->addChild(pLabel4);
	CCPoint pLabel4Point = ccp(35*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	labelAction(pLabel4,pLabel4Point);
	/////////
	pLabel5->setPosition(ccp(0,	CCDirector::sharedDirector()->getVisibleSize().height/2));
	this->addChild(pLabel5);
	CCPoint pLabel5Point = ccp(41*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
		labelAction(pLabel5,pLabel5Point);
	//CCSequence* startAction = CCSequence::create(pLabel0,pLabel1,pLabel2,pLabel3,pLabel4,pLabel5,NULL);
	pLabel6->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,CCDirector::sharedDirector()->getVisibleSize().height));
	this->addChild(pLabel6);
	CCPoint pLabel6Point = ccp(47*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	labelAction(pLabel6,pLabel6Point);
	pLabel7->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,0));
	CCPoint pLabel7Point = ccp(53*pLabel0->getContentSize().width/6,2*CCDirector::sharedDirector()->getVisibleSize().height/3);
	this->addChild(pLabel7);
	labelAction(pLabel7,pLabel7Point);
	CCPoint pLabelcPoint = ccp(CCDirector::sharedDirector()->getVisibleSize().width-5*pLabelc->getContentSize().width,
		CCDirector::sharedDirector()->getVisibleSize().height/4);
	CCPoint pLabelsPoint = ccp(CCDirector::sharedDirector()->getVisibleSize().width-4*pLabels->getContentSize().width,
		CCDirector::sharedDirector()->getVisibleSize().height/4);
	CCPoint pLabelzPoint = ccp(CCDirector::sharedDirector()->getVisibleSize().width-3*pLabelz->getContentSize().width,
		CCDirector::sharedDirector()->getVisibleSize().height/4);
	CCPoint pLabelpPoint = ccp(CCDirector::sharedDirector()->getVisibleSize().width-2*pLabelp->getContentSize().width,
		CCDirector::sharedDirector()->getVisibleSize().height/4);
	labelActionMoveTo(pLabelc,pLabelcPoint);
	labelActionMoveTo(pLabels,pLabelsPoint);
	labelActionMoveTo(pLabelz,pLabelzPoint);
	labelActionMoveTo(pLabelp,pLabelpPoint);
	this->addChild(pLabelc);
	this->addChild(pLabels);
	this->addChild(pLabelz);
	this->addChild(pLabelp);

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	text = CCSprite::create("UI_prstoctn.png");
	text->setColor(ccc3(120,120,120));
	text->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2.5));
	text->setVisible(false);
	this->addChild(text);

	scheduleOnce(schedule_selector(StartScene::labelonStage),1.5f);
	return true;
}
void StartScene::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
           CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(1,Scene::titleScene()));
		 //  CCLOG("%f,%f",CCDirector::sharedDirector()->getVisibleSize().width,CCDirector::sharedDirector()->getVisibleSize().height);
}
CCScene* StartScene::scene()
{
	CCScene* SScene = CCScene::create();
	StartScene* startScene = StartScene::create();
	SScene->addChild(startScene);

	return SScene;
}
//动态文字函数实现
void StartScene::labelAction(CCSprite* pLabel,CCPoint pLabelPoint)
{
	CCActionInterval* pLabelMove = CCMoveTo::create(1.2f,CCPointMake(
		pLabelPoint.x,pLabelPoint.y));
	CCActionInterval* pLabelRote = CCRotateBy::create(1.0f,360);
	CCSequence* pLabelsqc1 = CCSequence::create(pLabelMove,pLabelRote,NULL);
	pLabel->runAction(pLabelsqc1);
}
void StartScene::labelActionMoveTo(CCSprite* pLabelMove,CCPoint pLabelPointMove)
{
	CCActionInterval* pLabelMoveTo = CCMoveTo::create(1.2f,CCPointMake(pLabelPointMove.x,pLabelPointMove.y));
	pLabelMove->runAction(pLabelMoveTo);
}
void StartScene::labelonStage(float dt)
{
	text->setVisible(true);
}

#endif