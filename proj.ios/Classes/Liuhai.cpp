//
//  Liuhai.cpp
//  HelloCpp
//
//  Created by Ricardo on 14/9/22.
//
//


/*重写了攻击动作函数attack
 敌人的攻击动作随机产生
 */
#include "Liuhai.h"
USING_NS_CC;
bool Liuhai::init()
{
    if (!Enemy::init())
    {
        return false;
    }
    setHP(1000);
    view = 5*32;
    enemyState = STADINGBY;
    initSprite();				//初始化精灵动画
    initViewRect();
    speedX = 1.5;
    return true;
}
void Liuhai::initBlock()
{
    m_block = CCRectMake(
                         getPositionX(),
                         getPositionY(),
                         m_sprite->getContentSize().width - 5,
                         m_sprite->getContentSize().height);
    
    //m_attack = m_block;				//临时给怪物创建攻击矩形
}
void Liuhai::initSprite()
{
    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("Liuhai0.png", "Liuhai0.plist", "Liuhai.ExportJson");
    m_sprite = CCArmature::create("Liuhai");
    m_sprite->getAnimation()->play("Stand");							// 设置当前运行动画的索引，一个“工程”可以建立多个动画
    m_sprite->setPosition(ccp(25,0));											// 设置位置信息
    this->addChild(m_sprite);														// 添加到容器，当前运行的场景之中
}
void Liuhai::hurt()
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
    HP = HP - FORCED;
}
void Liuhai::headHurt()
{
    m_sprite->getAnimation()->play("HeadHurt");
    this->scheduleOnce(schedule_selector(Liuhai::doHurt),0.33f);
    m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Liuhai::hurtCallBack));
}
void Liuhai::flankHurt()
{
    m_sprite->getAnimation()->play("FlankHurt");
    this->scheduleOnce(schedule_selector(Liuhai::doHurt),0.33f);
    m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Liuhai::hurtCallBack));
}
void Liuhai::airHurt()
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
    this->scheduleOnce(schedule_selector(Liuhai::doHurt),0.33f);
    m_sprite->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(Liuhai::hurtCallBack));
}
void Liuhai::doHurt(float dt)
{
    setState(NORMAL);
    m_sprite->getAnimation()->play("Stand");
}
void Liuhai::hurtCallBack(CCArmature* armature, MovementEventType type, const char *name)
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
void Liuhai::attack()
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
void Liuhai::refresh(float dt)
{
    this->setState(NORMAL);
    enemyState = STADINGBY;
	m_attack.isFinished = true;
	velocityX = 0;
    m_sprite->getAnimation()->play("Stand");
}
void Liuhai::setAttackRect(float dt)
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
void Liuhai::HeavyPunch()
{
    m_sprite->getAnimation()->play("RiderKick");
    force = 30;
	if (faceto)
	{
		velocityX = -2;
	}
	else
		velocityX = 2;
    this->scheduleOnce(schedule_selector(Liuhai::setAttackRect),0.4f);
    this->scheduleOnce(schedule_selector(Liuhai::refresh),0.6f);
}
void Liuhai::Pistol()
{
    m_sprite->getAnimation()->play("RiderSting2");
    force = 30;
	if (faceto)
	{
		velocityX = -3;
	}
	else
		velocityX = 3;
    this->scheduleOnce(schedule_selector(Liuhai::setAttackRect),0.4f);
    scheduleOnce(schedule_selector(Liuhai::refresh),0.6f);
}
void Liuhai::UpAttack()
{
    m_sprite->getAnimation()->play("WAttack");
    force = 45;
	if (faceto)
	{
		velocityX = -3;
	}
	else
		velocityX = 3;
	velocityY = 1;
    this->scheduleOnce(schedule_selector(Liuhai::setAttackRect),0.4f);
    scheduleOnce(schedule_selector(Liuhai::refresh),0.6f);
}
void Liuhai::BoxingPunch()
{
    m_sprite->getAnimation()->play("Saber");
    force = 50;
    this->scheduleOnce(schedule_selector(Liuhai::setAttackRect),0.5f);
    scheduleOnce(schedule_selector(Liuhai::refresh),0.6f);
}
void Liuhai::SuperPistol()
{
    m_sprite->getAnimation()->play("RiderSting1");
    force = 30;
	if (faceto)
	{
		velocityX = -2;
	}
	else
		velocityX = 2;
	velocityY = 1.5;
    this->scheduleOnce(schedule_selector(Liuhai::setAttackRect),0.4f);
    scheduleOnce(schedule_selector(Liuhai::refresh),0.6f);
}
void Liuhai::airAttack()
{
    ;
}

void Liuhai::groundAttack()
{
    CCLOG("IN Liuhai I attacked You");
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
    //enemyState = STADINGBY;
}