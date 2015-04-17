#ifndef _Story00__
#define _Story00__
#include "cocos2d.h"
#include "Global.h"
#include "Story.h"

USING_NS_CC;
class Story00:public Story
{
public:
	Story00(){}
	~Story00(){}

	virtual bool init();
	virtual void nextEvt();

	CCSprite* backgroundImage;

	void event00();
	void event01();
	void event02();
	void event03();
	void event04();
	void event05();
	void event06(float dt);
	void event07();
	void event08();
	void event09();
	void event10();

	void tempImageChange(float dt)
	{
		backgroundImage->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("00_BG_01.png"));
	}
	CREATE_FUNC(Story00);
};
#endif