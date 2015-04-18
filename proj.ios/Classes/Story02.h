#ifndef _Story02__
#define _Story02__
#include "cocos2d.h"
#include "Global.h"
#include "Story.h"

USING_NS_CC;
class Story02:public Story
{
public:
	Story02(){}
	~Story02(){}

	virtual bool init();
	virtual void nextEvt();

	void event01();
	void event02();
	void event03();
	void event04();
	void event05();
	void event06();
// 	void event07();
// 	void event08();
// 	void event09();
// 	void event10();

	CREATE_FUNC(Story02);
};
#endif