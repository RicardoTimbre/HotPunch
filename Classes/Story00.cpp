#include "Story00.h"
#include "Scene.h"
bool Story00::init()
{
	if (!Story::init())
	{
		return false;
	}	
	dialogBox_bottom->setVisible(false);	//设置对话框不可见
	dialogBox_top->setVisible(false);
	CCSpriteFrameCache* frameStart = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameStart->addSpriteFramesWithFile("Story00.plist","Story00.png");
	nextEvt();												//由此进入第一个事件
	return true;
}
void Story00::nextEvt()								//用了一个相当繁琐的方式，没办法
{
	state = false;											//设置触摸无法进入下一个事件
	static CCSprite* tempText0;
	
	if (count == 0)
	{
		tempText0 = CCSprite::create("StoryImg/00_00.png");
		backgroundImage = CCSprite::createWithSpriteFrameName("00_BG_00.png");

		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		tempText0->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));
		backgroundImage->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));
		this->addChild(tempText0,10);
		this->addChild(backgroundImage,0);
		state = true;
		count++;
	}
	else if (count == 1)
	{
		this->removeChild(tempText0);

		event00();
		state = true;
		count++;
	}
	else if (count == 2)
	{
		clear();
		event01();
		state = true;
		count++;
	}
	else if (count == 3)
	{
		clear();
		event02();
		state = true;
		count++;
	}
	else if (count == 4)
	{
		clear();
		event03();
		state = true;
		count++;
	}
	else if (count == 5)
	{
		clear();
		event04();
		state = true;
		count++;
	}
	else if (count == 6)
	{
		clear();
		event05();
		state = true;
		count++;
	}
	else if (count == 7)
	{
		clear();
		CCActionInterval* fadeinout = CCSequence::create(CCFadeOut::create(1.0f),CCFadeIn::create(1.0f),NULL);
		backgroundImage->runAction(fadeinout);
		scheduleOnce(schedule_selector(Story00::tempImageChange),1.0f);
		scheduleOnce(schedule_selector(Story00::event06),2.5f);
		count++;
	}
	else if (count == 8)
	{
		clear();
		event07();
		state = true;
		count++;
	}
	else if (count == 9)
	{
		clear();
		event08();
		state = true;
		count++;
	}
	else if (count == 10)
	{
		clear();
		event09();
		state = true;
		count++;
	}
	else if (count == 11)
	{
		clear();
		event10();
		state = true;
		count++;
	}
	else if (count == 12)
	{
		clear();
		tempText0 = CCSprite::create("StoryImg/01_00.png");
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		tempText0->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));
		this->addChild(tempText0);
		state = true;
		count++;
	}
	else
	{
		CCScene* scene = Scene::story01();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.0f,scene));
	}
}
void Story00::event00()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_01.png"));
 	dialogBox_top->setVisible(true);
}
void Story00::event01()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_02.png"));
	dialogBox_bottom->setVisible(true);
}
void Story00::event02()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_03.png"));
	dialogBox_top->setVisible(true);
}
void Story00::event03()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_04.png"));
	dialogBox_bottom->setVisible(true);
}
void Story00::event04()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_05.png"));
	dialogBox_top->setVisible(true);
}
void Story00::event05()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_06.png"));
	dialogBox_bottom->setVisible(true);
}
void Story00::event06(float dt)
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_07.png"));
	dialogBox_bottom->setVisible(true);
	state = true;
}
void Story00::event07()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_08.png"));
	dialogBox_top->setVisible(true);
}
void Story00::event08()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_09.png"));
	dialogBox_bottom->setVisible(true);
}
void Story00::event09()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_10.png"));
	dialogBox_top->setVisible(true);
}
void Story00::event10()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_11.png"));
	dialogBox_bottom->setVisible(true);
}