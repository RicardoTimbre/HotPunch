#ifndef _GameOverLayer__
#define _GameOverLayer__
#include "cocos2d.h"
USING_NS_CC;
/************************************************************************/
/* GameOverLayer:游戏结束界面
/*包含一个背景图片和一个“回到标题”的按钮，切换到该页面的时候会播放音乐
/**/
/************************************************************************/
class GameOverLayer : public CCLayer
{
public:
	virtual bool init();									//初始化函数
	static CCScene* Scene();
	CREATE_FUNC(GameOverLayer);

	//Button Callback Functions:
	void retryBtnCallBack(CCObject* pSender);
private:
	CCMenuItemImage* retryBtn;
	CCSprite* sp_Background;
};

#endif