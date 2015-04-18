#ifndef _Story__
#define _Story__
#include "cocos2d.h"
#include "Global.h"

USING_NS_CC;
class Story:public CCLayer
{
public:
	virtual bool init();

	CCSprite* dialogBox_bottom;
	CCSprite* dialogBox_top;
	CCSprite* crctorImage_bottom;
	CCSprite* crctorImage_top;

	CCSprite* text_bottom;
	CCSprite* text_top;

	void showAmysImage();
	void showNividasImage();
	void showNormansImage();
	bool state;											//标记当前是否可以触屏跳转到下一事件
	int count;												//事件ID标记

	virtual void nextEvt();							//跳转到下一个事件的函数
	void clear();											//清除所有内容
	//触摸监听函数三人行
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	CREATE_FUNC(Story);
};
#endif