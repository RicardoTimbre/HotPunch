//
//  JapanArmyII.cpp
//  HelloCpp
//
//  Created by 田子桐 on 14-8-19.
//
//

#include "JapanArmyII.h"
USING_NS_CC;
bool JapanArmyII::init()
{
	if (!Enemy::init())
	{
		return false;
	}
	HP = 120;
	view = 5*32;
	enemyState = STADINGBY;
	initSprite();				//初始化精灵动画
	initViewRect();
	speedX = 1.5;
	return true;
}
void JapanArmyII::initBlock()
{
	m_block = CCRectMake(
                         getPositionX(),
                         getPositionY(),
                         m_sprite->getContentSize().width - 5,
                         m_sprite->getContentSize().height);
    
	//m_attack = m_block;				//临时给怪物创建攻击矩形
}
void JapanArmyII::initSprite()
{
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Xinfeng0.png", "Xinfeng0.plist", "Xinfeng.ExportJson");
	m_sprite = CCArmature::create("Xinfeng");							// 这里直接使用Nivida ，而此信息保存在 Nivida.ExportJson 中，与其创建的项目属性相对应
	m_sprite->getAnimation()->play("Stand");							// 设置当前运行动画的索引，一个“工程”可以建立多个动画
	m_sprite->setPosition(ccp(25,0));											// 设置位置信息
	m_sprite->setColor(ccc3(200,0,0));
	this->addChild(m_sprite);														// 添加到容器，当前运行的场景之中
}
void JapanArmyII::hurt()
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
void JapanArmyII::headHurt()
{
	m_sprite->getAnimation()->play("HeadHurt");
	this->scheduleOnce(schedule_selector(JapanArmyII::doHurt),0.33f);
	m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(JapanArmyII::hurtCallBack));
}
void JapanArmyII::flankHurt()
{
	m_sprite->getAnimation()->play("FlankHurt");
	this->scheduleOnce(schedule_selector(JapanArmyII::doHurt),0.33f);
	m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(JapanArmyII::hurtCallBack));
}
void JapanArmyII::airHurt()
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
	this->scheduleOnce(schedule_selector(JapanArmyII::doHurt),0.33f);
	m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(JapanArmyII::hurtCallBack));
}
void JapanArmyII::doHurt(float dt)
{
	setState(NORMAL);
	m_sprite->getAnimation()->play("Stand");

}
void JapanArmyII::hurtCallBack(CCArmature* armature, MovementEventType type, const char *name)
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
void JapanArmyII::attack()
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
void JapanArmyII::refresh(float dt)
{
	this->setState(NORMAL);
	enemyState = STADINGBY;
	m_attack.isFinished = true;
	m_sprite->getAnimation()->play("Stand");
}
void JapanArmyII::setAttackRect(float dt)
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
void JapanArmyII::HeavyPunch()
{
	m_sprite->getAnimation()->play("HeavyPunch");
	force = 10;
	this->scheduleOnce(schedule_selector(JapanArmyII::setAttackRect),0.3f);
	scheduleOnce(schedule_selector(JapanArmyII::refresh),0.4f);
}
void JapanArmyII::Pistol()
{
	m_sprite->getAnimation()->play("Pistol");
	force = 20;
	this->scheduleOnce(schedule_selector(JapanArmyII::setAttackRect),0.3f);
	scheduleOnce(schedule_selector(JapanArmyII::refresh),0.4f);
}
void JapanArmyII::UpAttack()
{
	m_sprite->getAnimation()->play("UpAttack");
	force = 10;
	this->scheduleOnce(schedule_selector(JapanArmyII::setAttackRect),0.3f);
	scheduleOnce(schedule_selector(JapanArmyII::refresh),0.4f);
}
void JapanArmyII::BoxingPunch()
{
	m_sprite->getAnimation()->play("BoxingPunch");
	force = 15;
	this->scheduleOnce(schedule_selector(JapanArmyII::setAttackRect),0.3f);
	scheduleOnce(schedule_selector(JapanArmyII::refresh),0.4f);
}
void JapanArmyII::SuperPistol()
{
	m_sprite->getAnimation()->play("SuperPistol");
	force = 30;
	this->scheduleOnce(schedule_selector(JapanArmyII::setAttackRect),0.3f);
	scheduleOnce(schedule_selector(JapanArmyII::refresh),0.4f);
}
void JapanArmyII::airAttack()
{
	;
}
void JapanArmyII::groundAttack()
{
	int attackIndex = CCRANDOM_0_1()*100;
	if (attackIndex <= 30)
	{
		HeavyPunch();
	}
	else if (attackIndex <= 55)
	{
		Pistol();
	}
	else if(attackIndex <= 65)	
	{
		UpAttack();
	}
	else if(attackIndex <= 75)
	{
		BoxingPunch();
	}
	else if(attackIndex <=90)
	{
		HeavyPunch();
	}
	else
	{
		SuperPistol();
	}
}