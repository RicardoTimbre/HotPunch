#include "Level01.h"
USING_NS_CC;
bool Level01::init()
{
	if (!GameLayer::init())
	{
		return false;
	}
	maxWidth = 1140;

	map = CCTMXTiledMap::create("Maps/Level01.tmx");
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
void Level01::initGroundRect()
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
void Level01::initEnemyArr()
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
void Level01::update(float delta)
{
	GameLayer::update(delta);
	if (hero->getPositionX()>=maxWidth)
	{
		CCScene* scene = Scene::story02();
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