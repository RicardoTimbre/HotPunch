#include "TitleLayer.h"
#include "Scene.h"
#include "SimpleAudioEngine.h"
#include "GameOverLayer.h"
USING_NS_CC;

bool TitleLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Audio/00-Title.mp3",true);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//背景图层有两层，均为静态，如下代码创建之
	CCSprite* sp_Background1 = CCSprite::create("menu_back.png");
	//sp_Background1->setScale(0.8);
	CCSprite* sp_Background2 = CCSprite::create("menu_back.png");
	//sp_Background2->setScale(0.8);
	sp_Background1->setPosition(ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	sp_Background2->setPosition(ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));

	this->addChild(sp_Background1,0);			//设置层次关系，1在下2在其上
	this->addChild(sp_Background2,1);
	//创建齐鲁软件设计大赛的Logo精灵：
	CCSprite* sp_QiluLogo = CCSprite::create("sp_logo.png");
	sp_QiluLogo->setPosition(ccp(origin.x+visibleSize.width-sp_QiluLogo->getContentSize().width/2+2,visibleSize.height-sp_QiluLogo->getContentSize().height/2-2));
	/*
	/在此期间创建一个动作，让这个图标一直反复变大变小地蠕动
	*/
	CCScaleTo* logoScale = CCScaleTo::create(0.4f,1.12f,1.12f);  
	CCScaleTo* logoScaler = CCScaleTo::create(0.4f,1,1);
	CCSequence* logosqce = CCSequence::create(logoScale,logoScaler,NULL);
	CCRepeatForever* logoRepeat = CCRepeatForever::create(logosqce);
	this->addChild(sp_QiluLogo,5);
	sp_QiluLogo->runAction(logoRepeat);
	/*
	/在此处将内四个按钮依次添加了，然后创建一个CCMenu对象把它们括起来
	/显示到图层里面去
	*/
	//////newgame
	CCMenuItemImage* pNewGame =  CCMenuItemImage::create("new_game.png",
		"new_gameP.png",
		this,menu_selector(TitleLayer::newGmeBtnCallBack));
	pNewGame->setPosition(ccp(-visibleSize.width/2+pNewGame->getContentSize().width,
		-visibleSize.height/2+2.75*pNewGame->getContentSize().height));//menuIamge的默认坐标原点在屏幕中点
//////////	continue game
	CCMenuItemImage* pContGame =  CCMenuItemImage::create("con_game.png",
		"con_gameP.png",
		this,menu_selector(TitleLayer::ctnGmeBtnCallBack));
	pContGame->setPosition(ccp(-visibleSize.width/2+4.8*pContGame->getContentSize().width/2,
		-visibleSize.height/2+2.75*pContGame->getContentSize().height));
	/////////////team
	CCMenuItemImage* pTeamGame =  CCMenuItemImage::create("team_game.png",
		"team_gameP.png",
		this,menu_selector(TitleLayer::tmStudBtnCallBack));
	pTeamGame->setPosition(ccp(-visibleSize.width/2+pTeamGame->getContentSize().width,
		-visibleSize.height/2+1.2*pTeamGame->getContentSize().height));
	///////////////quit game
	CCMenuItemImage* pQuitGame =  CCMenuItemImage::create("quit_game.png",
		"quit_gameP.png",
		this,menu_selector(TitleLayer::quitGmeBtnCallBack));
	pQuitGame->setPosition(ccp(-visibleSize.width/2+4.8*pNewGame->getContentSize().width/2,
		-visibleSize.height/2+1.2*pQuitGame->getContentSize().height));
	//菜单newgame的动态效果实现
	/*
    menuActionForever(pNewGame);
	menuActionForever(pContGame);
	menuActionForever(pTeamGame);
	menuActionForever(pQuitGame);
	*/
	CCMenu* pMenuGame = CCMenu::create(pNewGame,pContGame,pTeamGame,pQuitGame,NULL);
	pMenuGame->setPosition(ccp(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	this->addChild(pMenuGame,5);
	return true;
};
void TitleLayer::menuActionForever(CCMenuItemImage* pImage)
{
	CCScaleTo* pImageGameScale = CCScaleTo::create(0.4f,1.05f,1.05f);  
	CCScaleTo* pImageGameScaler = CCScaleTo::create(0.4f,1,1);
	CCSequence* pImageGamesqce = CCSequence::create(pImageGameScale,pImageGameScaler,NULL);
	CCRepeatForever* pImageGameRepeat = CCRepeatForever::create(pImageGamesqce);
	pImage->runAction(pImageGameRepeat);
}
//////////////////按钮的回调函数/////////////////////////////////////
void TitleLayer::newGmeBtnCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,Scene::story00()));
}
void TitleLayer::ctnGmeBtnCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,Scene::ctnLayer()));
}
void TitleLayer::tmStudBtnCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f,Scene::aboutScene()));
}
void TitleLayer::quitGmeBtnCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}