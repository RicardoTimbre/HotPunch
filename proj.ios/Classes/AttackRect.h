#ifndef _AttackRect__
#define _AttackRect__
#include "cocos2d.h"
USING_NS_CC;
class AttackRect : public CCRect
{
public:
	bool isFinished;			//是否已经攻击标志
	bool isCanFly;			//是否造成击飞
	int m_force;				//攻击的威力

	AttackRect& operator=(const AttackRect& other);

	AttackRect();

	AttackRect(float x,float y,float width,float height,int force,bool t_isCanFly);
	AttackRect(CCRect a,int force,bool t_isCanFly);
	AttackRect(AttackRect &temp);
};
#endif
