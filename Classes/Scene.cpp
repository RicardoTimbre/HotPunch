#include "Scene.h"
/************************************************************************/
/* ³¡¾°¹ÜÀíÆ÷                                                                     */
/************************************************************************/
CCScene* Scene::story00()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/01-Story00.mp3",true);
	CCScene* scene = CCScene::create();
	Story00* storyLayer = Story00::create();
	scene->addChild(storyLayer,0);
	return scene;
}
CCScene* Scene::story01()
{
	CCScene* scene = CCScene::create();
	Story01* storyLayer = Story01::create();
	scene->addChild(storyLayer,0);
	return scene;
}
CCScene* Scene::story02()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/02-Story02.mp3",true);
	CCScene* scene = CCScene::create();
	Story02* storyLayer = Story02::create();
	scene->addChild(storyLayer,0);
	return scene;
}
CCScene* Scene::story03()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/02-Story02.mp3",true);
	CCScene* scene = CCScene::create();
	Story03* stroyLayer = Story03::create();
	scene->addChild(stroyLayer,0);
	return scene;
}
CCScene* Scene::story04()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/02-Story02.mp3",true);
	CCScene* scene = CCScene::create();
	Story04* stroyLayer = Story04::create();
	scene->addChild(stroyLayer,0);
	return scene;
}
CCScene* Scene::story05()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/02-Story02.mp3",true);
	CCScene* scene = CCScene::create();
	Story05* stroyLayer = Story05::create();
	scene->addChild(stroyLayer,0);
	return scene;
}
CCScene* Scene::storyEnd()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/04-Peace.mp3",true);
	CCScene* scene = CCScene::create();
	StoryEnd* stroyLayer = StoryEnd::create();
	scene->addChild(stroyLayer,0);
	return scene;
}
CCScene* Scene::lv01GameScene()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/00-Title.mp3",true);
	CCScene* scene = CCScene::create();
	Level01* gamelayer = Level01::create();
	ControlLayer* controllayer = ControlLayer::create();
	controllayer->hero = gamelayer->hero;
	scene->addChild(gamelayer,0);
	scene->addChild(controllayer,1);
	return scene;
}
CCScene* Scene::lv02GameScene()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/00-Title.mp3",true);
	CCScene* scene = CCScene::create();
	Level02* gamelayer = Level02::create();
	ControlLayer* controllayer = ControlLayer::create();
	controllayer->hero = gamelayer->hero;
	scene->addChild(gamelayer,0);
	scene->addChild(controllayer,1);
	return scene;
}
CCScene* Scene::lv03GameScene()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/03-Main.mp3",true);
	CCScene* scene = CCScene::create();
	Level03* gamelayer = Level03::create();
	ControlLayer* controllayer = ControlLayer::create();
	controllayer->hero = gamelayer->hero;
	scene->addChild(gamelayer,0);
	scene->addChild(controllayer,1);
	return scene;
}
CCScene* Scene::lv04GameScene()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/03-Main.mp3",true);
	CCScene* scene = CCScene::create();
	Level04* gamelayer = Level04::create();
	ControlLayer* controllayer = ControlLayer::create();
	controllayer->hero = gamelayer->hero;
	scene->addChild(gamelayer,0);
	scene->addChild(controllayer,1);
	return scene;
}
CCScene* Scene::lv05GameScene()
{
	CCScene* scene = CCScene::create();
	Level02* gamelayer = Level02::create();
	ControlLayer* controllayer = ControlLayer::create();
	controllayer->hero = gamelayer->hero;
	scene->addChild(gamelayer,0);
	scene->addChild(controllayer,1);
	return scene;
}
CCScene* Scene::titleScene()
{
	CCScene* pMenuScene = CCScene::create();
	TitleLayer* pMenuLayer = TitleLayer::create();
	pMenuScene->addChild(pMenuLayer);
	return pMenuScene;
}
CCScene* Scene::aboutScene()
{
	CCScene* pscene = CCScene::create();
	GroupLayer* pLaer = GroupLayer::create();
	pscene->addChild(pLaer);
	return pscene;
}
CCScene* Scene::gameOverScene()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/09-GameOver.mp3",true);
	CCScene* pMenuScene = CCScene::create();
	GameOverLayer* pMenuLayer = GameOverLayer::create();
	pMenuScene->addChild(pMenuLayer);
	return pMenuScene;
}
CCScene* Scene::pauseLayer()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	CCScene* pMenuScene = CCScene::create();
	PauseLayer* pMenuLayer = PauseLayer::create();
	pMenuScene->addChild(pMenuLayer);
	return pMenuScene;
//	CCDirector::sharedDirector()->pause();
}
CCScene* Scene::ctnLayer()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	CCScene* pMenuScene = CCScene::create();
	TableViewTestLayer* pMenuLayer = TableViewTestLayer::create();
	pMenuScene->addChild(pMenuLayer);
	return pMenuScene;
}