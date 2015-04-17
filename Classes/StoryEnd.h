#ifndef _StoryEnd__
#define _StoryEnd__
#include "cocos2d.h"
#include "Global.h"
#include "Scene.h"
#include "Story.h"

USING_NS_CC;
class StoryEnd:public Story
{
public:
	virtual bool init();
	virtual void nextEvt();
	void animateFinished(CCNode *sender);
	void backtoTitle(CCNode* sender);
	CREATE_FUNC(StoryEnd);
};
#endif