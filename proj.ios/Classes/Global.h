#ifndef _Global__
#define _Global__
#include "cocos2d.h"
#include "AttackRect.h"
USING_NS_CC;

#define LftBtnPsnX		60
#define LftBtnPsnY		64				//左行按钮坐标
#define RgtBtnPsnX		124
#define RgtBtnPsnY 		64				//右行按钮坐标
#define JmpBtnPsnX		485
#define JmpBtnPsnY		64				//跳跃按钮坐标
#define AtkBtnPsnX		550
#define AtkBtnPsnY		115				//攻击按钮坐标

#define BladeBtnPsnX	230				//光剑按钮坐标
#define BladeBtnPsnY	40

typedef enum{
	NORMAL = 0,			//正常状态
	WALKING,				//行走状态
	ATTACKING,				//攻击状态
	HURT,						//受伤状态
	FORCED					//强制状态
}HeroState;					//定义玩家状态

typedef enum{
	PATROLING = 0,		//巡逻中
	REACHING,				//接近主角中
	ATTACK,					//攻击中，跟HeroState是一回事（敌人在HeroState的ATTACKING属性弃用）
	FORCE,						//强制状态，跟HeroState是一回事（敌人在HeroState的FORCED属性弃用）
	STADINGBY,				//待机中，用于其他状态的结束和巡逻状态的开启
	DYING,						//濒死状态，用于显示死亡动画 怪物的HP为0时引导进来，并在播放完动画后标记为DIE
	DIE							//从怪物数组中将此对象删除的标志
}EnemyState;
typedef enum
{
	SHIELD = 0,				//护盾模式
	CLOCKUP,				//高速模式
	INVISIBLE,				//潜行模式
	FORCECONTROL,		//力场控制模式
	LIGHTBLADE,			//光剑状态
	PISTOL,					//手枪状态
	SHOTPUT,				//手榴弹状态
	RPG							//RPG火箭炮状态
}HeroMode;
#define GRAVITY			0.7f				//重力加速度
#define  VelocityX			5					//水平方向最大速度
#define  maxVelocityY	15				//竖直方向最大速度

static CCPoint TMXPoint2GLPoint(CCPoint p)					//图块坐标转换为游戏坐标
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	return ccp(p.x * 16,visibleSize.height - (p.y * 16));
}
static CCPoint GLPoint2TMXPoint(CCPoint p)					//游戏坐标转换为图块坐标
{
	;}
#endif
