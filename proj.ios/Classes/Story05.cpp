#include "Story05.h"
#include "Scene.h"
bool Story05::init()
{
	if (!Story::init())
	{
		return false;
	}	
	dialogBox_bottom->setVisible(false);	//设置对话框不可见
	dialogBox_top->setVisible(false);
	CCSpriteFrameCache* frameStart = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameStart->addSpriteFramesWithFile("Story00.plist","Story00.png");
	frameStart->addSpriteFramesWithFile("Story05.plist","Story05.png");
	count = 1;
	nextEvt();												//由此进入第一个事件
	return true;
}
void Story05::nextEvt()								//用了一个相当繁琐的方式，没办法
{
	state = false;											//设置触摸无法进入下一个事件
	if (count == 1)
	{
		event01();
		state = true;
		count++;
	}
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
	else if (count == 5)
	{
		clear();
		event05();
		state = true;
		count++;
	}
	else
	{
		CCScene* scene = Scene::storyEnd();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,scene));
	}
}
void Story05::event01()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("05_01.png"));
	dialogBox_bottom->setVisible(true);
}
void Story05::event02()
{
	
}
void Story05::event03()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("05_02.png"));
	dialogBox_bottom->setVisible(true);
}
void Story05::event04()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("05_03.png"));
	dialogBox_bottom->setVisible(true);
}
void Story05::event05()
{
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("05_04.png"));
}