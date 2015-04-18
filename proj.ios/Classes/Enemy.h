#ifndef _Enemy__
#define _Enemy__
#include "Entity.h"
USING_NS_CC;
class Enemy : public Entity
{
public:
	int view;

	CCRect m_ViewRect;											//视野矩形
	virtual void initViewRect();									//初始化并更新视野矩形
	virtual void initBlock();
	EnemyState enemyState;									//怪物状态机枚举
	virtual void attack();											//攻击
	virtual void useSkill();										//施用法术（不同敌人施用法术的场合均不同）
	virtual void changeDirection();							//重写父类函数
	void patrol();														//巡逻
	virtual void run();												//重写父类函数
	virtual void jump();											//重写他爹的函数

	int count;															//巡逻步数
	int speedX;														//敌人的水平移动速度
	virtual bool init();
	CREATE_FUNC(Enemy);
};
#endif