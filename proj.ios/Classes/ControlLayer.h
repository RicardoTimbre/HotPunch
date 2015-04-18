#ifndef _ControlLayer__
#define _ControlLayer__
#include "cocos2d.h"
#include "Scene.h"
#include "Hero.h"
USING_NS_CC;
class ControlLayer:public CCLayer
{
public:
	virtual bool init();
	CREATE_FUNC(ControlLayer);
	virtual void update(float delta);

	void JmpBtnCallBack(CCObject* pSender);
	void AtkBtnCallBack(CCObject* pSender);
	void BladeBtnCallBack(CCObject* pSender);
	void ShieldBtnCallBack(CCObject* pSender);
	void CloakBtnCallBack(CCObject* pSender);
	void ClockUPBtnCallBack(CCObject* pSender);
	void pauseBtnCallBack(CCObject* pSender);
	//触摸监听函数三人行
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
public:
	//建立左右行走的按钮，建立攻击和跳跃两个真实的按钮
	CCSprite* LeftBtn;
	CCSprite* RightBtn;
	CCMenuItemImage* JmpBtn;
	CCMenuItemImage* AtkBtn;
	//CCMenuItemImage* 
	Hero* hero;		//取得对主角的操纵权，妥妥的！

	bool is_lftBtnPressed;
	bool is_rgtBtnPressed;
	bool is_ModeChangeItemPressed;			//已弃用
	//主角状态框显示用
	CCSprite* imageItemSide;
	CCSprite* imageItem;
	CCSprite* hp_Bar;
	CCSprite* sp_Bar;
	CCSprite* tp_Bar;
};
#endif