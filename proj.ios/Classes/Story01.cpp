#include "Story01.h"
#include "Scene.h"
bool Story01::init()
{
	if (!Story::init())
	{
		return false;
	}	
	dialogBox_bottom->setVisible(false);	//设置对话框不可见
	dialogBox_top->setVisible(false);
	CCSpriteFrameCache* frameStart = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameStart->addSpriteFramesWithFile("Story00.plist","Story00.png");
	frameStart->addSpriteFramesWithFile("Story01.plist","Story01.png");
	nextEvt();												//由此进入第一个事件
	return true;
}
void Story01::nextEvt()								//用了一个相当繁琐的方式，没办法
{
	state = false;											//设置触摸无法进入下一个事件
	if (count == 0)
	{
		backgroundImage = CCSprite::createWithSpriteFrameName("01_BG.png");
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		backgroundImage->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));
		this->addChild(backgroundImage,0);
		state = true;
		event01();
		count++;
		count++;
	}
// 	else if (count == 1)
// 	{
// 		event01();
// 		state = true;
// 		count++;
// 	}
	else if (count == 2)
	{
		clear();
		event02();
		state = true;
		count++;
	}
	else if (count == 3)
	{
		clear();
		event03();
		state = true;
		count++;
	}
	else if (count == 4)
	{
		clear();
		event04();
		state = true;
		count++;
	}
	else
	{
		CCScene* scene = Scene::lv01GameScene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFadeDown::create(1.0f,scene));
	}
}

void Story01::event01()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("01_01.png"));
	dialogBox_top->setVisible(true);
}
void Story01::event02()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("01_02.png"));
	dialogBox_bottom->setVisible(true);
}
void Story01::event03()
{
	showAmysImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("01_03.png"));
	dialogBox_top->setVisible(true);
}
void Story01::event04()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("01_04.png"));
	dialogBox_bottom->setVisible(true);
}