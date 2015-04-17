#ifndef _Entity__
#define _Entity__
/************************************************************************/
/* Entity类，作为所有在地图上显示的物体的对象的父类存在
是Enemy和Hero类的父类*/
/************************************************************************/
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Global.h"
USING_NS_CC;
USING_NS_CC_EXT;
class Entity:public CCNode
{
public:
	virtual bool init();
	virtual void initBlock();										//初始化碰撞框
	CCRect getRect();												//获取主角碰撞矩形
	virtual void initSprite();										//初始化精灵动画（代替bindSprite用）
	HeroState getState();										//获取玩家的状态
	void setHP(int a);												//修改HP
	void setSP(int a);												//修改SP
	void setState(HeroState a);								//修改玩家的状态
public:
	CCArmature* m_sprite;				//新的主角精灵
	CCRect m_block;						//角色的碰撞框
	AttackRect m_attack;				//角色的攻击框
	float velocityY;							//竖直方向速度
	int force;									//攻击力
	bool inTheAir_flag;					//浮空标志
	bool faceto;								//角色的面向，左为true右为false
	bool finished;							//有没有成功按下跳跃键的标志
	bool jumpMainFlag;					//给修正待机姿势用的一个标志
	float velocityX;							//水平方向速度

	CREATE_FUNC(Entity);
	//给eclips用的两个函数
	float get_max(float a,float b)
	{
		return (a > b ? a : b);
	}
	float get_min(float a,float b)
	{
		return (a < b ? a : b);
	}
private:
		HeroState state;						//State of the hero
	//////////////////////
public:
    float HP,SP;
	//////////////各种动作////////////////
	virtual void refresh(float dt);			//主角修正
	virtual void run();											//行走（主角的仅仅是播放动画，不同敌人移动速度有区别）
	void setDirection(bool a);								//设置方向（通用）
	void changeDirection();									//改变方向
	virtual void jump();										//跳跃（不同的高度不同）
	void doJump(float dt);									//跳跃的回调

	virtual void hurt();											//受伤
	virtual void headHurt();									//头部受伤
	virtual void flankHurt();									//腹部受伤
	virtual void airHurt();										//浮空受伤
	virtual void standUpCallBack(CCArmature* armature, MovementEventType type, const char * name);						//由下蹲站起执行完毕后的回调函数
	virtual void jumpCallBack(CCArmature* armature,MovementEventType type,const char *name);								//跳跃动画播放完毕后的回调函数
};
#endif