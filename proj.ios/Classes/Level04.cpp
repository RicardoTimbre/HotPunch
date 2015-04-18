#include "Level04.h"
USING_NS_CC;
void Level04::initEnemyArr()
{
	//怪物的依次创建/////////////////////////////////////
	JapanArmyI* Monster1 = JapanArmyI::create();
	JapanArmyII* Monster2 = JapanArmyII::create();
	Ninja* Monster3 = Ninja::create();
	Monster1->setPosition(TMXPoint2GLPoint(ccp(23,6)));
	Monster2->setPosition(TMXPoint2GLPoint(ccp(43,6)));
	Monster3->setPosition(TMXPoint2GLPoint(ccp(55,9)));
	this->addChild(Monster1,5);
	this->addChild(Monster2,5);
	this->addChild(Monster3,5);
	enemyArr->addObject(Monster1);
	enemyArr->addObject(Monster2);
	enemyArr->addObject(Monster3);

	JapanArmyII* Monster4 = JapanArmyII::create();
	Monster4->setPosition(TMXPoint2GLPoint(ccp(194,6)));
	this->addChild(Monster4,5);
	enemyArr->addObject(Monster4);

	Ninja* Monster5 = Ninja::create();
	Monster5->setPosition(TMXPoint2GLPoint(ccp(178,6)));
	this->addChild(Monster5,5);
	enemyArr->addObject(Monster5);

	JapanArmyI* Monster6 = JapanArmyI::create();
	Monster6->setPosition(TMXPoint2GLPoint(ccp(167,6)));
	this->addChild(Monster6,5);
	enemyArr->addObject(Monster6);

	Ninja* Monster7 = Ninja::create();
	Monster7->setPosition(TMXPoint2GLPoint(ccp(120,6)));
	this->addChild(Monster7,5);
	enemyArr->addObject(Monster7);

	Liuhai* Monster8 = Liuhai::create();
	Monster8->setPosition(TMXPoint2GLPoint(ccp(93,6)));
	this->addChild(Monster8,5);
	enemyArr->addObject(Monster8);

	Liuhai* Monster9 = Liuhai::create();
	Monster9->setPosition(TMXPoint2GLPoint(ccp(53,6)));
	this->addChild(Monster9,5);
	enemyArr->addObject(Monster9);

	Liuhai* Monster10 = Liuhai::create();
	Monster10->setPosition(TMXPoint2GLPoint(ccp(12,6)));
	this->addChild(Monster10,5);
	enemyArr->addObject(Monster10);
}
bool Level04::init()
{
	if (!GameLayer::init())
	{
		return false;
	}
	maxWidth = 3744;
	map = CCTMXTiledMap::create("Maps/Level04.tmx");
	map->setPosition(CCPointZero);
	this->addChild(map,0);
	thisPosition = getPosition();
	hero = Hero::create();
	hero->setPosition(ccp(150,1100));
/*	hero->setPosition(TMXPoint2GLPoint(ccp(12,6)));*/
	hero->setTiledMap(map);
	this->addChild(hero,10);
	initEnemyArr();
	initGroundRect();
	this->scheduleUpdate();
	return true;
}
void Level04::initGroundRect()
{
	blockCount = 27;
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
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground10");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[9] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground11");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[10] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground12");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[11] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground13");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[12] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground14");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[13] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground15");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[14] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground16");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[15] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground17");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[16] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground18");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[17] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground19");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[18] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground20");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[19] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground21");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[20] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground22");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[21] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground23");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[22] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground24");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[23] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground25");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[24] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground26");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[25] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
	{
		CCDictionary* objRect = objGroup->objectNamed("Ground27");
		float tempX = objRect->valueForKey("x")->floatValue();
		float tempY = objRect->valueForKey("y")->floatValue();
		float tempWidth = objRect->valueForKey("width")->floatValue();
		float tempHeight = objRect->valueForKey("height")->floatValue();
		grdBlkArry[26] = CCRectMake(tempX,tempY,tempWidth,tempHeight);
	}
}
void Level04::update(float delta)
{
	GameLayer::update(delta);
	if (hero->getPositionY() < 100 && hero->getPositionX() < 20)
	{
		CCScene* scene = Scene::story05();
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