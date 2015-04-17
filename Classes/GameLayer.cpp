#include"GameLayer.h"
USING_NS_CC;
GameLayer::GameLayer()
{
	//Array的创建
	enemyArr = CCArray::create();
	enemyArr->retain();					//防止被引擎坑掉
}
GameLayer::~GameLayer()
{
	CC_SAFE_RELEASE(enemyArr);
}
bool GameLayer::init()
{
	return true;
}
void GameLayer::initGroundRect()
{
	blockCount = 4;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCTMXObjectGroup* objGroup = map->objectGroupNamed("groundRect");
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground1");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[0] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground2");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[1] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground3");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[2] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground4");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[3] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
}
void GameLayer::update(float dt)
{
	updateMap();
	CCRect b_hero = hero->getRect();
	if (hero->getState() == NORMAL || hero->getState() == WALKING)		//state=0对应普通状态
	{
		updateNORMAL();
	}
	else if (hero->getState() == HURT)
	{
		updateNORMAL();
	}
	//怪物的检测
	updateEnemy();
	AIMonster();
	//主角的状态设置
	if (hero->SP > 0)
	{
		if (hero->getMode() == INVISIBLE)
		{
			hero->SP-=0.2f;
		}
		else if (hero->getMode() == CLOCKUP)
		{
			hero->SP-=0.1f;
		}
		else if (hero->getMode() == LIGHTBLADE)
		{
			hero->SP-=0.1f;
		}
		else
		{
			hero->SP+=0.1f;
		}
	}
	else
	{
		hero->modeShield();
		hero->SP+=1;
	}
	if (hero->TP < 100)
	{
		hero->TP += 0.07f;
	}
	else
	{
		hero->HP = 100;
		hero->SP = 100;
		hero->TP = 0;
	}
	if (hero->HP < 0)
	{
		hero->HP = 0;
	}
	if (hero->HP > 100)
	{
		hero->HP = 100;
	}
	if (hero->SP < 0)
	{
		hero->SP = 0;
	}
	if (hero->SP > 100)
	{
		hero->SP = 100;
	}
	if (hero->TP < 0)
	{
		hero->TP = 0;
	}
	if (hero->TP > 100)
	{
		hero->TP = 100;
	}
}
void GameLayer::AIMonster()
{
	CCObject* pObj;
	CCARRAY_FOREACH(enemyArr,pObj)
	{
		Enemy* pTemp = (Enemy*)pObj;
		float heroX = hero->getPositionX();
		float thisX = pTemp->getPositionX();			//thisX 是当前怪物的X坐标
		float thisY = pTemp->getPositionY();

		if (pTemp->enemyState == STADINGBY)			//如果当前为待机状态，那么让它变为巡逻状态
		{//////////////////////////////////////////////////////////////////////////////////////////////////////////////
			pTemp->enemyState = PATROLING;
			pTemp->patrol();
		}///////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (pTemp->enemyState == PATROLING)//如果在巡逻状态，那么开始判断是业内有木有主角，如果有，变为reaching
		{//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
			if (pTemp->m_ViewRect.intersectsRect(hero->m_block) && hero->getMode() != INVISIBLE)	//视野矩形和主角碰撞矩形发生碰撞，也就是敌人“看到了”主角
			{
				pTemp->enemyState = REACHING;
			}
			else
				pTemp->patrol();
		}//}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
		else if (pTemp->enemyState == REACHING)
		{//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{
			if (pTemp->m_ViewRect.intersectsRect(hero->m_block))
			{
				if ( heroX - thisX >= 40)
				{
					if (hero->getPositionY() - thisY > 12 && heroX - thisX < 80)
					{
						pTemp->jump();
					}
					pTemp->setDirection(false);
					pTemp->run();
				}
				else if (heroX  -  thisX <= -40)
				{
					if (hero->getPositionY() - thisY > 12 && heroX - thisX > -80)
					{
						pTemp->jump();
					}
					pTemp->setDirection(true);
					pTemp->run();
				}
				else
				{
					int tempRand = CCRANDOM_0_1() * 100;
					if (tempRand > 90)
					{
						pTemp->attack();
					}
					else
					{
						pTemp->enemyState = STADINGBY;
					}
				}
			}
			else						//从碰撞框中消失，也就是看不到主角了
			{
				pTemp->enemyState = PATROLING;
			}

			if (hero->getMode() == INVISIBLE)
			{
				pTemp->enemyState = PATROLING;
			}
		}//}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
		/*********************************中间有待完善************************************/
		pTemp->initViewRect();
	}
}
void GameLayer::updateNORMAL()
{
	hero->inTheAir_flag = true;
	for (int i = 0;i < blockCount;i++)
	{
		CCRect tempBlock = grdBlkArry[i];
		if (hero->getRect().intersectsRect(tempBlock))		//一旦发生碰撞，就将flag标记记为true，同时退出循环，
		{
			if (hero->getRect().getMinY() - tempBlock.getMaxY() > -16 && hero->getRect().getMinY() - tempBlock.getMaxY() <= 0)				//对是否站在当前矩形的判断
			{
				hero->inTheAir_flag = false;
				hero->setPositionY(tempBlock.getMaxY());
				hero->velocityY = 0;
				hero->initBlock();
				if (hero->jumpMainFlag == false)
				{
					if (hero->getMode() == LIGHTBLADE)
						hero->m_sprite->getAnimation()->play("SB_Stand");
					else
						hero->m_sprite->getAnimation()->play("Stand");
					hero->velocityX = 0;
					hero->jumpMainFlag = true;
				}
			}
			else if (hero->getRect().getMaxY() - tempBlock.getMinY() < 16 && hero->getRect().getMaxY() - tempBlock.getMinY() >= 0)
			{
				hero->velocityY = -3;
			}
			else																//如果是X方向的碰撞，那么就阻挡玩家移动（将坐标回移两个像素）
			{
				float tempX = hero->getPositionX();
// 				if(hero->velocityX > 0)
// 				{
// 					hero->setPositionX(tempBlock.getMinX());
// 				}
// 				else
// 				{
// 					hero->setPositionX(tempBlock.getMaxX());
// 				}
				if (hero->getMode() != CLOCKUP)
				{
					if (hero->faceto)							//如果角色朝左
						hero->setPositionX(tempX - hero->velocityX + 1);
					else
					{
						hero->setPositionX(tempX - hero->velocityX - 1);
					}
				}
				else
				{
					if (hero->faceto)							//如果角色朝左
						hero->setPositionX(tempX - hero->velocityX + 1);
					else
					{
						hero->setPositionX(tempX - hero->velocityX - 1);
					}
				}
				break;
			}
		}										//判断是否碰撞的if结束
	}											//循环判断结束
	if (hero->inTheAir_flag == true)
	{
		int temp = hero->getPositionY();
		if(hero->velocityY > -maxVelocityY)
		hero->velocityY -= GRAVITY;
		hero->setPositionY(temp + hero->velocityY);
	} 
	int temp = hero->getPositionX();
	hero->setPositionX(temp + hero->velocityX);
	hero->initBlock();
}
void GameLayer::updateEnemy()
{
	bool isAttackFinished = false;
	CCObject* pObj;
	CCARRAY_FOREACH(enemyArr,pObj)
	{
		Enemy* pTemp = (Enemy*)pObj;
		CCRect b_enemy = pTemp->getRect();

		pTemp->inTheAir_flag = true;
		for (int i = 0;i < blockCount;i++)
		{
			CCRect tempBlock = grdBlkArry[i];
			if (pTemp->getPositionX() >= maxWidth)
			{
				pTemp->setDirection(true);
				pTemp->setPositionX(pTemp->getPositionX() - 5);
			}
			if (pTemp->getRect().intersectsRect(tempBlock))		//一旦发生碰撞，就将flag标记，同时退出循环，
			{
				if (pTemp->getRect().getMinY() - tempBlock.getMaxY() > -16 && pTemp->getRect().getMinY() - tempBlock.getMaxY() <= 0)				//对是否站在当前矩形的判断
				{
					pTemp->inTheAir_flag = false;
					pTemp->setPositionY(tempBlock.getMaxY());
					pTemp->velocityY = 0;
					pTemp->initBlock();
					if (pTemp->jumpMainFlag == false)
					{
						pTemp->m_sprite->getAnimation()->play("Stand");
						pTemp->jumpMainFlag = true;
					}
				}
				else if (pTemp->getRect().getMaxY() - tempBlock.getMinY() < 16 && pTemp->getRect().getMaxY() - tempBlock.getMinY() >= 0)
				{
					pTemp->velocityY = -3;
				}
				else																	//如果是X方向的碰撞，那么就阻挡玩家移动（将坐标回移两个像素），之后转向
				{
					float tempX = pTemp->getPositionX();
					if (pTemp->velocityX < 0)							//如果角色朝左
					{
						pTemp->velocityX = -pTemp->velocityX;
						float temp = CCRANDOM_0_1() * 100;
						if (temp > 70)
						{
							pTemp->jump();
						}
						else
						{
							if (pTemp->enemyState != DYING)
							{
								pTemp->changeDirection();
							}
						}
						pTemp->initViewRect();
					}
					else if (pTemp->velocityX > 0)
					{
						pTemp->velocityX = -pTemp->velocityX;
						float temp = CCRANDOM_0_1() * 100;
						if (temp > 70)
						{
							pTemp->jump();
						}
						else
						{
							pTemp->changeDirection();
						}
						pTemp->initViewRect();
					}
					break;

				}
			}																			//判断是否碰撞的if结束
		}											//循环判断结束
		if (pTemp->inTheAir_flag == true)
		{
			int temp = pTemp->getPositionY();
			if(pTemp->velocityY > -maxVelocityY)
				pTemp->velocityY -= GRAVITY;
			pTemp->setPositionY(temp + pTemp->velocityY);
		}
		int temp = pTemp->getPositionX();
		pTemp->setPositionX(temp + pTemp->velocityX);
		pTemp->initBlock();
		//攻击与受伤的判断
		if (hero->m_block.intersectsRect(pTemp->m_attack) && pTemp->m_attack.isFinished == false)
		{
			hero->hurt();
			if (hero->getMode() == SHIELD)
			{
				hero->HP -= (pTemp->m_attack.m_force * 0.6f);
			}
			else
				hero->HP -= pTemp->m_attack.m_force;
			pTemp->m_attack.isFinished = true;
		}
		if (pTemp->m_block.intersectsRect(hero->m_attack) && hero->m_attack.isFinished == false)
		{
			pTemp->hurt();
			pTemp->HP -= hero->m_attack.m_force;
			isAttackFinished = true;
		}
		if (pTemp->HP<=0)
		{
			pTemp->setState(FORCED);
			pTemp->enemyState = DYING;
			pTemp->m_block = CCRectMake(-1,-1,1,1);
			pTemp->m_sprite->getAnimation()->play("Fly");
			if (pTemp->faceto)
			{
				pTemp->velocityX = 5;
			}
			else
			{
				pTemp->velocityX = -5;
			}
		}
		if (pTemp->getPositionX() < 0 || pTemp->getPositionX() > maxWidth)
		{
			enemyArr->removeObject(pTemp);
			this->removeChild(pTemp);
		}
	}
	if (isAttackFinished == true)
	{
		hero->m_attack.isFinished = true;
	}
}
//已弃用////////////////////////////////
void GameLayer::updateHURT()
{
	hero->inTheAir_flag = true;
	for (int i = 0;i < blockCount;i++)
	{
		CCRect tempBlock = grdBlkArry[i];
		if (hero->getRect().intersectsRect(tempBlock))		//一旦发生碰撞，就将flag标记记为true，同时退出循环，
		{
			if (hero->getRect().getMinY() - tempBlock.getMaxY() > -16 && hero->getRect().getMinY() - tempBlock.getMaxY() <= 0)				//对是否站在当前矩形的判断
			{
				hero->inTheAir_flag = false;
				hero->setPositionY(tempBlock.getMaxY());
				hero->velocityY = 0;
				hero->initBlock();
				if (hero->jumpMainFlag == false)
				{
					if (hero->getMode() == LIGHTBLADE)
					{
						hero->m_sprite->getAnimation()->play("SB_Stand");
					}
					else
						hero->m_sprite->getAnimation()->play("Stand");
					hero->jumpMainFlag = true;
				}
			}
			else																//如果是X方向的碰撞，那么就阻挡玩家移动（将坐标回移两个像素）
			{
				float tempX = hero->getPositionX();
				if (hero->faceto == true)							//如果角色朝左
					hero->setPositionX(tempX - 10);
				else if (hero->faceto == false)
					hero->setPositionX(tempX + 10);
				break;
			}
		}										//判断是否碰撞的if结束
	}											//循环判断结束
	if (hero->inTheAir_flag == true)
	{
		int temp = hero->getPositionY();
		if(hero->velocityY > -maxVelocityY)
			hero->velocityY -= GRAVITY;
		hero->setPositionY(temp + hero->velocityY);
		hero->initBlock();
	}
}
////////////////////////////////////////
void GameLayer::initEnemyArr()
{
	//怪物的依次创建/////////////////////////////////////
	JapanArmyI* Monster1 = JapanArmyI::create();
	JapanArmyI* Monster2 = JapanArmyI::create();
	JapanArmyI* Monster3 = JapanArmyI::create();
	Monster1->setPosition(TMXPoint2GLPoint(ccp(23,13)));
	Monster2->setPosition(TMXPoint2GLPoint(ccp(43,6)));
	Monster3->setPosition(TMXPoint2GLPoint(ccp(55,9)));
	this->addChild(Monster1,5);
	this->addChild(Monster2,5);
	this->addChild(Monster3,5);
	enemyArr->addObject(Monster1);
	enemyArr->addObject(Monster2);
	enemyArr->addObject(Monster3);
}
void GameLayer::updateMap()
{
	CCPoint viewPoint = hero->getViewPointByPlayer();
	this->setPosition(viewPoint);
}