#ifndef _Hero__
#define _Hero__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Entity.h"
USING_NS_CC;
USING_NS_CC_EXT;
class Hero:public Entity
{
public:
	Hero();
	~Hero();
	float TP;//怒气值
	void setTiledMap(CCTMXTiledMap* map);				//set the tiled map
	virtual bool init();
	virtual void initBlock();											//初始化碰撞框
	virtual void initSprite();
//	virtual void initSprite();  										//日后需要重写此函数	
	CCPoint getViewPointByPlayer();
	virtual void run();
	HeroMode getMode();											//获取玩家模式状态
	void setMode(HeroMode a);									//修改玩家模式状态
	//重写父类的这三个受伤函数
	virtual void hurt();
	virtual void headHurt();
	virtual void flankHurt();
	virtual void airHurt();
	void headDefence();												//头部防御
	void flankDefence();												//腹部防御
	void SB_HeadHurt();
	void SB_FlankHurt();
	void hurtCallBack(CCArmature* armature,
		MovementEventType type,
		const char *name);											//受伤动画播放完成后的回调
	void doHurt(float dt);											//受伤后处理移动的回调

	////////////////各种动作//////////////////
	void attack();							//总攻击动作
	void normalAttack();				//不拿剑的攻击动作
	void bladeAttack();				//拿剑的攻击动作
	void airAttack();					//空中攻击动作的分支
	void groundAttack();				//地面攻击的分支
	void groundBladeAttack();		//地面光剑攻击的分支
	void terminateAttack();
	//被调用分配的动作
	void heavyPunch();
	void upAttack();
	void heavyKick();

	void SB_Attack1();
	void SB_Attack2();
	void SB_Attack3();
	void SB_Attack4();
	//两个终结技
	void drangonPunch();
	void cycloneKick();
	/////////////////////////////////////////
	virtual void refresh(float dt);			//主角修正
	void setAttackRect(float dt);
	///////////////////////////////////////
	void handBlade();
	void afterHandBlade(float dt);
	void modeShield();
	void modeIvisible();
	void afterModeIvisible(float dt);
	void modeClockUp();
	void afterModeClockUp(float dt);
	///////////////////////////////////////
	virtual void jump();
	virtual void doJump(float dt);
	//待添加
public:
	CREATE_FUNC(Hero);
private:
	CCTMXTiledMap* m_map;		//to opreate the TiledMap
	HeroMode m_mode;					//模式状态
	//////////////////////
};
#endif
