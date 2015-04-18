#include "Entity.h"
USING_NS_CC;
bool Entity::init()
{
	if (!CCNode::init())
	{
		return false;
	}
	m_attack = AttackRect(-1000,-1000,1,1,0,false);			/////将攻击框设置到很远的地方
	m_attack.isFinished = true;
	state = NORMAL;			//初始化状态
	HP = SP  = 0;				//初始化数据
	velocityX = 0;
	velocityY = 0;				//初始化水平和竖直方向的速度
	force = 0;
	finished = false;
	faceto = false;
	inTheAir_flag = true;
	jumpMainFlag = true;
	return true;
}
void Entity::initSprite()//临时以主角为例
{
	
}
CCRect Entity::getRect()
{
	return m_block;
}
HeroState Entity::getState()
{
	return state;
}
void Entity::setState(HeroState a)
{
	state = a;
}
void Entity::initBlock()
{
	m_block = CCRectMake(getPositionX() + 20,getPositionY(),28 , 91);
}
void Entity::setHP(int a)
{
	HP = a;
}
void Entity::setSP(int a)
{
	SP = a;
}
void Entity::run()
{
	setState(WALKING);
	if (faceto == false)
		this->velocityX = 1.5;
	else
		this->velocityX = -1.5;
}
void Entity::setDirection(bool a)
{
	faceto = a;
	if (a == true)		//面向左
		m_sprite->setScaleX(-1.0f);
	else
		m_sprite->setScaleX(1.0f);
}
void Entity::changeDirection()
{
	if (faceto)
	{
		faceto = false;
		m_sprite->setScaleX(1.0f);
	}
	else
	{
		faceto = true;
		m_sprite->setScaleX(-1.0f);
	}
}
void Entity::jump()
{
	if (inTheAir_flag == false && finished == false)
	{
		finished = true;
		m_sprite->getAnimation()->play("Jump");
		this->scheduleOnce(schedule_selector(Entity::doJump),0.33f);
	}
}
void Entity::doJump(float dt)
{
	int temp = getPositionY();
	m_sprite->getAnimation()->play("Up");
	setPositionY(temp + 10);
	initBlock();
	inTheAir_flag = true;
	finished = false;
	jumpMainFlag = false;		//在此处确定修正待机动画
	velocityY = 14;
	setState(NORMAL);
}
//
void Entity::standUpCallBack(CCArmature* armature, MovementEventType type, const char * name)
{
	CCLOG("movement callback name:%s \n",name);
	if (strcmp(name,"Down") == 0)
	{
		switch (type)
		{
		case COMPLETE:
			//setState(NORMAL);
			armature->getAnimation()->play("Stand");
			break;
		default:
			break;
		}
	}
}
//
void Entity::jumpCallBack(CCArmature* armature,MovementEventType type,const char *name)
{
	CCLOG("movement callback name:%s \n",name);
	if (strcmp(name,"Jump") == 0)
	{
		switch (type)
		{
		case COMPLETE:
			setState(NORMAL);
			armature->getAnimation()->play("Up");
			break;
		default:
			break;
		}
	}
}
void Entity::hurt()
{
	setState(HURT);
	if (inTheAir_flag)								//浮空的话就出浮空受伤
	{
		airHurt();
	}
	else
	{
		float tempRand = CCRANDOM_0_1();
		if (tempRand < 0.5f)						//在头部受伤和腹部受伤之间随机出一个
		{
			headHurt();
		}
		else
		{
			flankHurt();
		}
	}
}
//下面三个函数在不同的子类里有不同的实现，这里的三个只是卖萌
void Entity::headHurt()
{
	CCLOG("Oh,my head!\n");
	setState(NORMAL);
}
void Entity::flankHurt()
{
	CCLOG("Oh,my baby!\n");
	setState(NORMAL);
}
void Entity::airHurt()
{
	CCLOG("I want to fly so high\n");
	setState(NORMAL);
}
void Entity::refresh(float dt)
{
	this->setState(NORMAL);
	m_attack.isFinished = true;
	m_sprite->getAnimation()->play("Stand");
}