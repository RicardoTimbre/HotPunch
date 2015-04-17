#ifndef _Scene__
#define _Scene__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "TitleLayer.h"
#include "GameOverLayer.h"
#include "GameLayer.h"
#include "GroupLayer.h"
#include "Story00.h"
#include "Story01.h"
#include "Story02.h"
#include "Story03.h"
#include "Story04.h"
#include "Story05.h"
#include "StoryEnd.h"
#include "TableViewTestScene.h"

#include "Level01.h"
#include "Level02.h"
#include "Level03.h"
#include "Level04.h"
#include "PauseLayer.h"
#include "ControlLayer.h"
USING_NS_CC;

class Scene
{
public:
	static CCScene* story00();
	static CCScene* story01();
	static CCScene* story02();
	static CCScene* story03();
	static CCScene* story04();
	static CCScene* story05();
	static CCScene* storyEnd();

	static CCScene* lv01GameScene();
	static CCScene* lv02GameScene();
	static CCScene* lv03GameScene();
	static CCScene* lv04GameScene();
	static CCScene* lv05GameScene();

	static CCScene* aboutScene();
	static CCScene* titleScene();
	static CCScene* gameOverScene();
	static CCScene* pauseLayer();
	static CCScene* ctnLayer();
};
#endif