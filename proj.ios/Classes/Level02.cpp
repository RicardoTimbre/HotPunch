#include "Level02.h"
USING_NS_CC;
void Level02::initEnemyArr()
{
	//怪物的依次创建/////////////////////////////////////
	JapanArmyI* Monster1 = JapanArmyI::create();
	JapanArmyII* Monster2 = JapanArmyII::create();
	Ninja* Monster3 = Ninja::create();
	Ninja* Monster4 = Ninja::create();
	Ninja* Monster5 = Ninja::create();
	Monster1->setPosition(TMXPoint2GLPoint(ccp(23,13)));
	Monster2->setPosition(TMXPoint2GLPoint(ccp(43,6)));
	Monster3->setPosition(TMXPoint2GLPoint(ccp(55,9)));
	Monster4->setPosition(TMXPoint2GLPoint(ccp(40,8)));
	Monster5->setPosition(TMXPoint2GLPoint(ccp(35,8)));
	this->addChild(Monster1,5);
	this->addChild(Monster2,5);
	this->addChild(Monster3,5);
	this->addChild(Monster4,5);
	this->addChild(Monster5,5);
	enemyArr->addObject(Monster1);
	enemyArr->addObject(Monster2);
	enemyArr->addObject(Monster3);
	enemyArr->addObject(Monster4);
	enemyArr->addObject(Monster5);
}
bool Level02::init()
{
	if (!GameLayer::init())
	{
		return false;
	}
	maxWidth = 1856;
	map = CCTMXTiledMap::create("Maps/Level02.tmx");
	map->setPosition(CCPointZero);
	this->addChild(map,0);
	thisPosition = getPosition();
	hero = Hero::create();
	hero->setPosition(ccp(50,300));
	hero->setTiledMap(map);
	this->addChild(hero,10);
	initEnemyArr();
	initGroundRect();
	this->scheduleUpdate();
	return true;
}
void Level02::initGroundRect()
{
	blockCount = 7;
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
}
void Level02::update(float delta)
{
	GameLayer::update(delta);
	if (hero->getPositionX()>=maxWidth)
	{
		CCScene* scene = Scene::story03();
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
		CCDirector::sharedDirector()->replaceScene(scene);
	}
}