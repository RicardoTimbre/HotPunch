#ifndef  _STARTSCENE__
#define  _STARTSCENE__
#include "cocos2d.h"
#include "Global.h"

USING_NS_CC;
class StartScene:public CCLayer
{
public:
	StartScene()
	{

	}
	~StartScene()
	{

	}
	//¶¯Ì¬ÎÄ×Öº¯Êý
	void labelAction(CCSprite *pLabel,CCPoint pLabelPoint);
	void labelActionMoveTo(CCSprite* pLabelMove,CCPoint pLabelPointMove);
	virtual bool init();
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	static CCScene* scene();

	CCSprite* text;
	void labelonStage(float dt);
	CREATE_FUNC(StartScene);
};
#endif