//
//  Ninja.cpp
//  HelloCpp
//
//  Created by 田子桐 on 14-8-21.
//
//

#include "Ninja.h"
USING_NS_CC;
bool Ninja::init()
{
	if (!Enemy::init())
	{
		return false;
	}
	HP = 500;
	view = 5*32;
	enemyState = STADINGBY;
	initSprite();				//初始化精灵动画
	initViewRect();
	speedX = 1.5;
	return true;
}
void Ninja::initBlock()
{
	m_block = CCRectMake(
                         getPositionX(),
                         getPositionY(),
                         m_sprite->getContentSize().width - 5,
                         m_sprite->getContentSize().height);
    
	//m_attack = m_block;				//临时给怪物创建攻击矩形
}
void Ninja::initSprite()
{
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Ninja0.png", "Ninja0.plist", "Ninja.ExportJson");
	m_sprite = CCArmature::create("Ninja");							// 这里直接使用Nivida ，而此信息保存在 Nivida.ExportJson 中，与其创建的项目属性相对应
	m_sprite->getAnimation()->play("Stand");							// 设置当前运行动画的索引，一个“工程”可以建立多个动画
	m_sprite->setPosition(ccp(25,0));											// 设置位置信息
	this->addChild(m_sprite);														// 添加到容器，当前运行的场景之中
}
void Ninja::hurt()
{
	if (this->getState() != HURT)
	{
		this->setState(HURT);
		velocityX = 0;
		if (inTheAir_flag)
		{
			airHurt();
		}
		else
		{
			float tempRand = CCRANDOM_0_1();
			if (tempRand < 0.5f)						//在头部防御和腹部防御之间随机出一个
			{
				headHurt();
			}
			else
			{
				flankHurt();
			}
		}
	}
}
void Ninja::headHurt()
{
	m_sprite->getAnimation()->play("HeadHurt");
	this->scheduleOnce(schedule_selector(Ninja::doHurt),0.33f);
	m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Ninja::hurtCallBack));
}
void Ninja::flankHurt()
{
	m_sprite->getAnimation()->play("FlankHurt");
	this->scheduleOnce(schedule_selector(Ninja::doHurt),0.33f);
	m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Ninja::hurtCallBack));
}
void Ninja::airHurt()
{
	if (faceto)
	{
		velocityX = 2;
	}
	else
	{
		velocityX = -2;
	}
	velocityY = 5;
	m_sprite->getAnimation()->play("FlankHurt");
	this->scheduleOnce(schedule_selector(Ninja::doHurt),0.33f);
	m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Ninja::hurtCallBack));
}
void Ninja::doHurt(float dt)
{
	setState(NORMAL);
	m_sprite->getAnimation()->play("Stand");
}
void Ninja::hurtCallBack(CCArmature* armature, MovementEventType type, const char *name)
{
	if (strcmp(name,"FlankDefence") == 0 || strcmp(name,"HeadDefence") == 0)
	{
		switch (type)
		{
            case COMPLETE:
                setState(NORMAL);
                armature->getAnimation()->play("Stand");
                break;
            default:
                break;
		}
	}
}
void Ninja::attack()
{
	if (getState() ==  NORMAL||getState() == WALKING)
	{
		if (getState() != ATTACKING)
		{
			setState(ATTACKING);
			if (this->enemyState != ATTACK)
			{
				enemyState = ATTACK;
			}
			velocityX = 0;
			if (inTheAir_flag)
			{
				airAttack();
			}
			else
			{
				groundAttack();
			}
		}
	}
}
void Ninja::refresh(float dt)
{
	this->setState(NORMAL);
	enemyState = STADINGBY;
	m_sprite->getAnimation()->play("Stand");
}
void Ninja::setAttackRect(float dt)
{
	if (faceto)
	{
		m_attack = AttackRect(CCRectMake(
			getPositionX() - 40,
			getPositionY() + 16,
			m_sprite->getContentSize().width - 10,
			m_sprite->getContentSize().height - 10),
			force,false);
	}
	else
	{
		m_attack = AttackRect(CCRectMake(
			getPositionX() + 40,
			getPositionY() + 16,
			m_sprite->getContentSize().width - 10,
			m_sprite->getContentSize().height - 10),
			force,false);
	}
}
void Ninja::Dart()
{
	m_sprite->getAnimation()->play("Dart"); 
	this->scheduleOnce(schedule_selector(Ninja::setAttackRect),0.6f);
	scheduleOnce(schedule_selector(Ninja::refresh),0.4f);
}
void Ninja::Hurt_in_theAir()
{
	m_sprite->getAnimation()->play("Hurt_in_theAir");
	this->scheduleOnce(schedule_selector(Ninja::setAttackRect),0.6f);
	scheduleOnce(schedule_selector(Ninja::refresh),0.4f);
}
void Ninja::Boomerang()
{
	m_sprite->getAnimation()->play("Boomerang");
	this->scheduleOnce(schedule_selector(Ninja::setAttackRect),0.6f);
	scheduleOnce(schedule_selector(Ninja::refresh),0.4f);
}
void Ninja::airAttack()
{
	;
}
void Ninja::groundAttack()
{
	int attackIndex = CCRANDOM_0_1()*100;
	if (attackIndex <= 30)
	{
		Dart();
	}
	else if (attackIndex <= 65)
	{
		Hurt_in_theAir();
	}
	else
	{
		Boomerang();
	}
}