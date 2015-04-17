#ifndef _Story05__
#define _Story05__
#include "cocos2d.h"
#include "Global.h"
#include "Story.h"

USING_NS_CC;
class Story05:public Story
{
public:
	virtual bool init();
	virtual void nextEvt();

	void event01();
	void event02();
	void event03();
	void event04();
	void event05();

	CREATE_FUNC(Story05);
};
#endif