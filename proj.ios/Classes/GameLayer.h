#ifndef _GameLayer__
#define _GameLayer__

#include "cocos2d.h"

#include "Hero.h"
#include "JapanArmyI.h"
#include "JapanArmyII.h"
#include "Ninja.h"
#include "Liuhai.h"

#include "Global.h"
USING_NS_CC;
class GameLayer: public cocos2d::CCLayer
{
public:
	GameLayer();
	~GameLayer();
	virtual bool init();  
	virtual void initGroundRect();				//初始化当前地图的所有碰撞矩形
	virtual void initEnemyArr();					//初始化怪物容器
	void updateNORMAL();				//调用平常情况下的主角的刷新
	void updateHURT();					//调用受伤情况下的主角的刷新
	void updateMap();					//地图的刷新

	void updateEnemy();					//敌人的更新
	void AIMonster();						//敌人的行为

	int blockCount;
	int maxWidth;							//地图最大宽度
	CREATE_FUNC(GameLayer);
	virtual void update(float delta);
public:
	CCTMXTiledMap* map;
	int tileCountX,tileCountY;
	Hero* hero;
	CCRect grdBlkArry[100];
	CCPoint thisPosition;

	CCArray* enemyArr;					//敌人容器

private:
};
#endif