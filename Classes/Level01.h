#ifndef _Level01__
#define _Level01__
#include "cocos2d.h"
#include "Scene.h"
#include "GameLayer.h"

USING_NS_CC;
class Level01 : public GameLayer
{
public:
	virtual bool init();
	virtual void initGroundRect();				//初始化当前地图的所有碰撞矩形
	virtual void initEnemyArr();					//初始化怪物容器

	virtual void update(float delta);
	CREATE_FUNC(Level01);
};
#endif