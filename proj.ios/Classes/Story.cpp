#include "Story.h"
bool Story::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	count = 0;
	state = false;			//设置一开始事件不能通过触摸跳转
	const int b_x = 415;
	const int b_y = 50;
	const int t_x =225;
	const int t_y = 310;
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UIS.plist","UIS.png");
	dialogBox_bottom = CCSprite::createWithSpriteFrameName("UI_dialogBox.png");
	dialogBox_top		 = CCSprite::createWithSpriteFrameName("UI_dialogBox.png");

	dialogBox_bottom->setFlipX(true);
	dialogBox_bottom->setPosition(ccp(b_x,b_y));
	dialogBox_top->setPosition(ccp(t_x,t_y));
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	crctorImage_bottom = CCSprite::create();
	crctorImage_top = CCSprite::create();
	text_bottom = CCSprite::create();
	text_top = CCSprite::create();
	text_bottom->setAnchorPoint(ccp(0,0));
	text_top->setAnchorPoint(ccp(0,0));
	
	crctorImage_top->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));
	crctorImage_bottom->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));

	this->addChild(dialogBox_top,5);
	this->addChild(dialogBox_bottom,5);
	this->addChild(crctorImage_bottom,10);
	this->addChild(crctorImage_top,10);
	this->addChild(text_bottom,15);
	this->addChild(text_top,15);

	setTouchEnabled(true);			//开启触摸监听
	return true;
}
void Story::nextEvt()
{

}
void Story::clear()
{
	dialogBox_bottom->setVisible(false);
	dialogBox_top->setVisible(false);
	text_bottom->setVisible(false);
	text_top->setVisible(false);
	crctorImage_bottom->setVisible(false);
	crctorImage_top->setVisible(false);
}

void Story::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	if (state == true)
	{
		nextEvt();
	}
}
void Story::showAmysImage()
{
	crctorImage_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Amy_Image.png"));
	crctorImage_top->setVisible(true);
}
void Story::showNividasImage()
{
	crctorImage_bottom->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Nivida_Image.png"));
	crctorImage_bottom->setVisible(true);
}
void Story::showNormansImage()
{
	crctorImage_top->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Norman_Image.png"));
	crctorImage_top->setVisible(true);
}