#include "AttackRect.h"
USING_NS_CC;
AttackRect::AttackRect()
{
	setRect(0,0,0,0);
	m_force = 0;
	isCanFly = false;
	isFinished = false;
}
AttackRect::AttackRect(float x = 0,float y = 0,float width = 0,float height = 0,int force = 0,bool t_isCanFly = false):CCRect(x,y,width,height)
{
	m_force = force;
	isCanFly = t_isCanFly;
	isFinished = false;
}
AttackRect::AttackRect(CCRect a,int force = 0,bool t_isCanFly = false):CCRect(a)
{
	m_force = force;
	isCanFly = t_isCanFly;
	isFinished = false;
}
AttackRect::AttackRect(AttackRect &other)
{
	setRect(other.origin.x, other.origin.y, other.size.width, other.size.height);
	m_force = other.m_force;
	isFinished = other.isFinished;
	isCanFly = other.isCanFly;
}
AttackRect& AttackRect::operator=(const AttackRect& other)
{
	setRect(other.origin.x, other.origin.y, other.size.width, other.size.height);
	m_force = other.m_force;
	isFinished = other.isFinished;
	isCanFly = other.isCanFly;

	return *this;
}