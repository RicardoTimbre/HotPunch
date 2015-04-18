#include "Story03.h"
#include "Scene.h"
bool Story03::init()
{
	if (!Story::init())
	{
		return false;
	}	
	dialogBox_bottom->setVisible(false);	//设置对话框不可见
	dialogBox_top->setVisible(false);
	CCSpriteFrameCache* frameStart = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameStart->addSpriteFramesWithFile("Story00.plist","Story00.png");
	frameStart->addSpriteFramesWithFile("Story03.plist","Story03.png");
	count = 1;
	nextEvt();												//由此进入第一个事件
	return true;
}
void Story03::nextEvt()								//用了一个相当繁琐的方式，没办法
{
	state = false;											//设置触摸无法进入下一个事件
	if (count == 0)
	{
		state = true;
		count++;
	}
	else if (count == 1)
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
	else if (count == 6)
	{
		clear();
		event06();
		state = true;
		count++;
	}
	else if (count == 7)
	{
		clear();
		event07();
		state = true;
		count++;
	}
	else
	{
		CCScene* scene = Scene::lv03GameScene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f,scene));
	}
}
void Story03::event01()
{
	showNormansImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_01.png"));
	dialogBox_top->setVisible(true);
}
void Story03::event02()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_02.png"));
	dialogBox_bottom->setVisible(true);
}
void Story03::event03()
{
	showNormansImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_03.png"));
	dialogBox_top->setVisible(true);
}
void Story03::event04()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_04.png"));
	dialogBox_bottom->setVisible(true);
}
void Story03::event05()
{
	showNormansImage();
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_05.png"));
	dialogBox_top->setVisible(true);
}
void Story03::event06()
{
	showNividasImage();
	text_bottom->setVisible(true);
	text_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_06.png"));
	dialogBox_bottom->setVisible(true);
}
void Story03::event07()
{
	text_top->setVisible(true);
	text_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("03_07.png"));
}