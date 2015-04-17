#include "StoryEnd.h"
#include "Scene.h"
bool StoryEnd::init()
{
	if (!Story::init())
	{
		return false;
	}	
	dialogBox_bottom->setVisible(false);	//设置对话框不可见
	dialogBox_top->setVisible(false);
	CCSpriteFrameCache* frameStart = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameStart->addSpriteFramesWithFile("Story00.plist","Story00.png");
	frameStart->addSpriteFramesWithFile("StoryEnd.plist","StoryEnd.png");
	count = 1;
	nextEvt();												//由此进入第一个事件
	return true;
}
void StoryEnd::nextEvt()								//用了一个相当繁琐的方式，没办法
{
	CCSprite *sprite1=CCSprite::create();
	sprite1->setAnchorPoint(ccp(0,0));
	sprite1->setPosition(ccp(0,0));
	this->addChild(sprite1);
	CCFadeIn* fadein=CCFadeIn::create(1.0f);
	CCFadeIn* fadein2=CCFadeIn::create(0.1f);
	//sprite1->runAction(fadein);
	CCSpriteFrame * frame1=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_01.png");
	CCSpriteFrame * frame2=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_02.png");
	CCSpriteFrame * frame3=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_03.png");
	CCSpriteFrame * frame4=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_04.png");
	CCSpriteFrame * frame5=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_05.png");
	CCSpriteFrame * frame6=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_06.png");
	CCSpriteFrame * frame7=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_07.png");
	CCSpriteFrame * frame8=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_08.png");
	CCSpriteFrame * frame9=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_09.png");
	CCSpriteFrame * frame10=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_10.png");
	CCSpriteFrame * frame11=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_11.png");
	CCSpriteFrame * frame12=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("end_12.png");
	CCArray* array=CCArray::createWithCapacity(12);
	array->addObject(frame1);
	array->addObject(frame2);
	array->addObject(frame3);
	array->addObject(frame4);
	array->addObject(frame5);
	array->addObject(frame6);
	array->addObject(frame7);
	array->addObject(frame8);
	array->addObject(frame9);
	array->addObject(frame10);
	array->addObject(frame11);
	array->addObject(frame12);

	CCAnimation* animation=CCAnimation::createWithSpriteFrames(array,4.0f);
	CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(StoryEnd::animateFinished));
	sprite1->runAction(CCSequence::create(CCSpawn::createWithTwoActions(fadein,CCAnimate::create(animation)),actionMoveDone,CCFadeOut::create(2.0f),NULL));
}
void StoryEnd::animateFinished(CCNode *sender)
{
	CCSprite* text = CCSprite::create("StoryImg/end_end.png");
/*	text->setAnchorPoint(ccp(0,1344/2));*/
	text->setPosition(ccp(320,-1344/2));
	this->addChild(text);
	CCFiniteTimeAction* actionMoveDone=CCCallFuncN::create(this,callfuncN_selector(StoryEnd::backtoTitle));
	CCActionInterval* move = CCSequence::create(CCMoveBy::create(40.0f,ccp(0,1344)),CCDelayTime::create(5.0f),actionMoveDone,NULL);
	text->runAction(move);
}
void StoryEnd::backtoTitle(CCNode *sender)
{
	CCScene *gameMenu=Scene::titleScene();
	CCDirector::sharedDirector()->replaceScene( CCTransitionFade::create(1.0f,gameMenu));
}