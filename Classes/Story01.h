#ifndef _Story01__
#define _Story01__
#include "cocos2d.h"
#include "Global.h"
#include "Story.h"
USING_NS_CC;
class Story01:public Story
{
public:
	Story01(){}
	~Story01(){}

	virtual bool init();
	virtual void nextEvt();
	CCSprite* backgroundImage;

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

	CREATE_FUNC(Story01);
};
#endif