#include "Level03.h"
USING_NS_CC;
void Level03::initEnemyArr()
{
	//怪物的依次创建/////////////////////////////////////
	JapanArmyII* Monster2 = JapanArmyII::create();
	Ninja* Monster3 = Ninja::create();

	JapanArmyI* Monster1 = JapanArmyI::create();
	Monster1->setPosition(TMXPoint2GLPoint(ccp(42,13)));
	this->addChild(Monster1,5);
	enemyArr->addObject(Monster1);

	Monster2->setPosition(TMXPoint2GLPoint(ccp(48,15)));
	Monster3->setPosition(TMXPoint2GLPoint(ccp(63,15)));
	this->addChild(Monster2,5);
	this->addChild(Monster3,5);
	enemyArr->addObject(Monster2);
	enemyArr->addObject(Monster3);

	JapanArmyI* Monster4 = JapanArmyI::create();
	Monster4->setPosition(TMXPoint2GLPoint(ccp(83,16)));
	this->addChild(Monster4,5);
	enemyArr->addObject(Monster4);

	JapanArmyI* Monster5 = JapanArmyI::create();
	Monster5->setPosition(TMXPoint2GLPoint(ccp(99,13)));
	this->addChild(Monster5,5);
	enemyArr->addObject(Monster5);

	Liuhai* Monster6 = Liuhai::create();
	Monster6->setPosition(TMXPoint2GLPoint(ccp(127,9)));
	this->addChild(Monster6,5);
	enemyArr->addObject(Monster6);

	Liuhai* Monster7 = Liuhai::create();
	Monster7->setPosition(TMXPoint2GLPoint(ccp(139,13)));
	this->addChild(Monster7,5);
	enemyArr->addObject(Monster7);
}
bool Level03::init()
{
	if (!GameLayer::init())
	{
		return false;
	}
	maxWidth = 2410;
	map = CCTMXTiledMap::create("Maps/Level03.tmx");
	map->setPosition(CCPointZero);
	this->addChild(map,0);
	thisPosition = getPosition();
	hero = Hero::create();
	hero->setPosition(ccp(30,100));
	hero->setTiledMap(map);
	this->addChild(hero,10);
	initEnemyArr();
	initGroundRect();
	this->scheduleUpdate();
	return true;
}
void Level03::initGroundRect()
{
	blockCount = 9;
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
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground5");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[4] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground6");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[5] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground7");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[6] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground8");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[7] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground9");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[8] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
}
void Level03::update(float delta)
{
	GameLayer::update(delta);
	if (hero->getPositionX()>=maxWidth)
	{
		CCScene* scene = Scene::story04();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2.0f,scene));
	}
	if (hero->HP <= 0)
	{
		hero->setState(FORCED);
		hero->m_sprite->getAnimation()->play("Fly");
		if (hero->faceto)
		{
			hero->velocityX = 5;
		}
		else
		{
			hero->velocityX = -5;
		}
		CCScene* scene = Scene::gameOverScene();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2.0f,scene));
	}
}