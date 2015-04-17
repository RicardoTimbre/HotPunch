#ifndef _Story04__
#define _Story04__
#include "cocos2d.h"
#include "Global.h"
#include "Story.h"

USING_NS_CC;
class Story04:public Story
{
public:
	virtual bool init();
	virtual void nextEvt();

	void event01();
	void event02();
	void event03();
	void event04();
	void event05();
	void event06();
	void event07();
	CREATE_FUNC(Story04);
};
#endif