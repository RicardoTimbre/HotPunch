#ifndef _PauseLayer__
#define _PauseLayer__
#include "cocos2d.h"
#include "Scene.h"
USING_NS_CC;
class PauseLayer : public GameLayer
{
public:
	virtual bool init();
	CCScene* gameScene;
	void btnResume(CCObject* pSender);
	CREATE_FUNC(PauseLayer);
};
#endif