#ifndef _TitleLayer__
#define _TitleLayer__
#include "cocos2d.h"
/************************************************************************/
/* TitleLayer:标题界面的类，用于显示标题界面
游戏启动后进入的第一个画面，需要包含“新游戏”、“继续游戏”、“制作组”、“退出游戏四个选项
游戏的左上角需要有一个”齐鲁软件设计大赛“的标志*/
/************************************************************************/
USING_NS_CC;
class TitleLayer : public CCLayer
{
public:
	void menuActionForever(CCMenuItemImage* pImage);//函数实现菜单的动态效果
	virtual bool init();									//初始化函数
	CREATE_FUNC(TitleLayer);

	//Button Callback Functions:
	void newGmeBtnCallBack(CCObject* pSender);
	void ctnGmeBtnCallBack(CCObject* pSender);
	void tmStudBtnCallBack(CCObject* pSender);
	void quitGmeBtnCallBack(CCObject* pSender);
private:
	CCMenuItemImage* newGmeBtn;		//NweGameButton
	CCMenuItemImage* ctnGmeBtn;			//ContinueGameButton
	CCMenuItemImage* tmStudBtn;			//TeamStudioGameButton
	CCMenuItemImage* quitGmeBtn;			//QuitGameButton
};
#endif